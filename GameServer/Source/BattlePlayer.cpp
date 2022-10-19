#include "stdafx.h"

void CBattlePlayer::_PumpCallback(void)
{
}
void CBattlePlayer::_PumpDoneCallback(void)
{
	pCharacter->BalloonCount = c_BalloonCountForPump;
	_PlayerCollider.pBalloon->SetSizeX(CEngineGlobal::BalloonWidth(pCharacter->BalloonCount));
	_PlayerCollider.pBalloon->SetEnabled(true);
	_ParachuteControl.Clear();
	++pPlayer->GetUserDB().BlowBalloonTotal;
	QuestDone(EQuestType::BlowBalloon, 1);
}
void CBattlePlayer::_ParachuteOnCallback(bool On_)
{
	_PlayerCollider.pParachute->SetEnabled(On_);
}
void CBattlePlayer::_AttachGround(const CCollider2D* pOtherCollider_)
{
	if (!_AttachedGrounds.emplace(pOtherCollider_).second || _AttachedGrounds.size() != 1) // 최초 지형이 붙었을 때 한번만 코드 실행 위해 1과 비교
		return;

	pCharacter->IsGround = true;

	if (pCharacter->BalloonCount == 0)
		_ParachuteControl.Off();
}
void CBattlePlayer::_DetachGround(const CCollider2D* pOtherCollider_)
{
	if (_AttachedGrounds.erase(pOtherCollider_) == 0 || _AttachedGrounds.size() != 0) // 마지막 지형이 떨어졌을때 한번만 코드 실행 위해 0과 비교
		return;

	pCharacter->IsGround = false;
	_PumpControl.Clear();

	if (pCharacter->BalloonCount == 0)
		_ParachuteControl.On();
}
void CBattlePlayer::bounce(const SCollision2D& collision)
{
	if (collision.Normal.X != 0.0f)
	{
		if (pPlayerObject->Velocity.X > 0.0f && collision.Normal.X < 0.0f ||
			pPlayerObject->Velocity.X < 0.0f && collision.Normal.X > 0.0f)
		{
			pPlayerObject->Velocity.X = -pPlayerObject->Velocity.X;
		}
	}
	else if (collision.Normal.Y != 0.0f)
	{
		if (pPlayerObject->Velocity.Y > 0.0f && collision.Normal.Y < 0.0f ||
			pPlayerObject->Velocity.Y < 0.0f && collision.Normal.Y > 0.0f)
		{
			pPlayerObject->Velocity.Y = -pPlayerObject->Velocity.Y;
		}
	}

	return;

	if (collision.pOtherMovingObject != nullptr)
	{
		auto multiplier = collision.pOtherMovingObject->GetPlayerObject2D() != nullptr ? 2.0f * collision.pOtherMovingObject->Mass / (pPlayerObject->Mass + collision.pOtherMovingObject->Mass) : 2.0f;

		if (collision.Normal.X != 0.0f)
			pPlayerObject->Velocity.X += collision.RelativeVelocity.X * multiplier;
		else
			pPlayerObject->Velocity.Y += collision.RelativeVelocity.Y * multiplier;
	}
	else
	{
		if (collision.Normal.X != 0.0f)
			pPlayerObject->Velocity.X = -pPlayerObject->Velocity.X;
		else
			pPlayerObject->Velocity.Y = -pPlayerObject->Velocity.Y;
	}
}
void CBattlePlayer::Die(int64 tick)
{
	pCharacter->BalloonCount = -1;
	_Die(tick);
}
void CBattlePlayer::_Die(int64 tick)
{
	pPlayerObject->SetEnabled(false);
	pPlayerObject->Velocity.X = 0.0f;
	pPlayerObject->Velocity.Y = c_DieUpVel;
	pCharacter->IsGround = false;
	pCharacter->Dir = 0;
	pCharacter->RegenTick = tick + c_RegenDelayTickCount;

	_PumpControl.Clear();
	_ParachuteControl.Clear();
	_AttachedGrounds.clear();
}
bool CBattlePlayer::_beHitBalloon(const SPoint& Normal_) // return true : dead
{
	--pCharacter->BalloonCount;

	if (pCharacter->BalloonCount >= 0)
	{
		if (pCharacter->BalloonCount > 0)
		{
			_PlayerCollider.pBalloon->SetSizeX(CEngineGlobal::BalloonWidth(pCharacter->BalloonCount));
		}
		else
		{
			if (!pCharacter->IsGround)
				_ParachuteControl.On();

			_PlayerCollider.pBalloon->SetEnabled(false);
		}

		return false;
	}

	return true;
}
bool CBattlePlayer::_LandEnter(const SCollision2D& Collision_)
{
	if (Collision_.pOtherCollider->Number != CEngineGlobal::c_StructureNumber ||
		Collision_.pCollider->Number != CEngineGlobal::c_BodyNumber ||
		Collision_.Normal.Y <= 0.0f)
		return false;

	_UpdateGroundPhysics(Collision_.pOtherMovingObject);
	_AttachGround(Collision_.pOtherCollider);
	return true;
}
bool CBattlePlayer::_CollisionEnter(int64 tick, const SCollision2D& Collision_)
{
	if (_LandEnter(Collision_))
		return false;

	bounce(Collision_);

	return false;
}
void CBattlePlayer::_LandStay(const SCollision2D& Collision_)
{
	if (Collision_.Normal.Y > 0.0f)
	{
		_UpdateGroundPhysics(Collision_.pOtherMovingObject);
		_AttachGround(Collision_.pOtherCollider);
	}
	else
	{
		_DetachGround(Collision_.pOtherCollider);
	}
}
bool CBattlePlayer::_CollisionStay(int64 tick, const SCollision2D& Collision_)
{
	if (Collision_.pCollider->Number != CEngineGlobal::c_BodyNumber || Collision_.pOtherCollider->Number != CEngineGlobal::c_StructureNumber) // 몸이 지형에 안 닿았으면
		return false;

	_LandStay(Collision_);

	return false;
}
bool CBattlePlayer::_CollisionExit(int64 tick, const SCollision2D& Collision_)
{
	if (Collision_.pCollider->Number != CEngineGlobal::c_BodyNumber || Collision_.pOtherCollider->Number != CEngineGlobal::c_StructureNumber)
		return false;

	_DetachGround(Collision_.pOtherCollider);

	return false;
}
bool CBattlePlayer::_TriggerEnter(const CCollider2D* pCollider_)
{
	return false;
}
void CBattlePlayer::_FixedUpdate(int64 tick)
{
	_UpdateStamina(tick);
	_UpdatePhysics();
}
void CBattlePlayer::_UpdateStamina(int64 tick)
{
	if (tick > pCharacter->StaminaInfo.LastUsedTick + c_StaminaRegenDelayTick)
	{
		pCharacter->StaminaInfo.Stamina += ((pCharacter->IsGround ? c_StaminaRegenSpeedOnGround : c_StaminaRegenSpeedInAir) * CEngine::GetDeltaTime());
		if (pCharacter->StaminaInfo.Stamina > pMeta->pCharacterTypeMeta->StaminaMax)
			pCharacter->StaminaInfo.Stamina = pMeta->pCharacterTypeMeta->StaminaMax;
	}
}
void CBattlePlayer::_UpdateGroundPhysics(const CMovingObject2D* pOtherMovingObject_)
{
	auto OtherObjectXVelocity = pOtherMovingObject_ == nullptr ? 0.0f : pOtherMovingObject_->Velocity.X;
	auto DestXVelocity = pCharacter->Dir > 0 ? pMeta->pCharacterTypeMeta->MaxVelXGround : pCharacter->Dir < 0 ? -pMeta->pCharacterTypeMeta->MaxVelXGround : 0.0f;
	auto XVelocityOnGround = pPlayerObject->Velocity.X - OtherObjectXVelocity;


	auto DeltaX = (DestXVelocity - XVelocityOnGround) * c_GroundAccRatio * CEngine::GetDeltaTime();
	if (abs(DeltaX) > c_IgnoredGroundMaxDeltaVelocity)
		pPlayerObject->Velocity.X += DeltaX;
	else
		pPlayerObject->Velocity.X = OtherObjectXVelocity + DestXVelocity;
}
void CBattlePlayer::_UpdatePhysics()
{
	if (pCharacter->IsGround)
	{
		if (pCharacter->Dir == 0)
			_PumpControl.FixedUpdate();
	}
	else
	{
		_updateXVelocityInAir();
		_updateYVelocityInAir();
	}

	pPlayerObject->LocalPosition.X += (CEngine::GetDeltaTime() * pPlayerObject->Velocity.X);
	pPlayerObject->LocalPosition.Y += (CEngine::GetDeltaTime() * pPlayerObject->Velocity.Y);

	if (_ParachuteControl.FixedUpdate())
		_PlayerCollider.pParachute->LocalScale.X = _PlayerCollider.pParachute->LocalScale.Y = pCharacter->ParachuteInfo.Scale;
}
void CBattlePlayer::_updateXVelocityInAir()
{
	if (pCharacter->BalloonCount > 0)
	{
		if (pPlayerObject->Velocity.X > pMeta->pCharacterTypeMeta->MaxVelAir)
			_approximateAirXVelocity(pMeta->pCharacterTypeMeta->MaxVelAir);
		else if (pPlayerObject->Velocity.X < -pMeta->pCharacterTypeMeta->MaxVelAir)
			_approximateAirXVelocity(-pMeta->pCharacterTypeMeta->MaxVelAir);
	}
	else if (pCharacter->BalloonCount == 0)
	{
		if (pCharacter->Dir > 0)
			_approximateAirXVelocity(c_MaxVelParachuteX);
		else if (pCharacter->Dir < 0)
			_approximateAirXVelocity(-c_MaxVelParachuteX);
		else
			if (pPlayerObject->Velocity.X > c_MaxVelParachuteX)
				_approximateAirXVelocity(c_MaxVelParachuteX);
			else if (pPlayerObject->Velocity.X < -c_MaxVelParachuteX)
				_approximateAirXVelocity(-c_MaxVelParachuteX);
	}
}
void CBattlePlayer::_updateYVelocityInAir()
{
	auto YAcc = pCharacter->BalloonCount > 0 ? c_Gravity : pCharacter->BalloonCount == 0 ? (c_Gravity * c_GravityParachuteRatio) : (c_Gravity * c_GravityDeadRatio);

	float MaxYVel;
	if (pCharacter->BalloonCount > 0)
		MaxYVel = -c_MaxVelDown;
	else if (pCharacter->BalloonCount == 0)
		MaxYVel = -c_MaxVelParachuteY;
	else
		MaxYVel = -c_MaxVelDeadY;

	auto Diff = MaxYVel - pPlayerObject->Velocity.Y;
	if (Diff > 0.0f) // 하강속도 초과
	{
		pPlayerObject->Velocity.Y += (Diff * c_AirAccRatio * CEngine::GetDeltaTime());
		if (pPlayerObject->Velocity.Y > MaxYVel)
			pPlayerObject->Velocity.Y = MaxYVel;
	}
	else
	{
		pPlayerObject->Velocity.Y += (YAcc * CEngine::GetDeltaTime());
		if (pPlayerObject->Velocity.Y < MaxYVel)
			pPlayerObject->Velocity.Y = MaxYVel;
	}
}
void CBattlePlayer::_approximateAirXVelocity(float value)
{
	pPlayerObject->Velocity.X += ((value - pPlayerObject->Velocity.X) * c_AirAccRatio * CEngine::GetDeltaTime());
}
bool CBattlePlayer::IsInvulerable(int64 tick)
{
	return (tick < pCharacter->InvulnerableEndTick);
}
bool CBattlePlayer::IsAlive(void) const
{
	return pCharacter->BalloonCount >= 0;
}
bool CBattlePlayer::touch(int8 dir)
{
	if (!IsAlive())
		return false;

	if (dir == pCharacter->Dir || dir < -1 || dir > 1)
		return false;

	direct(dir);

	return true;
}
void CBattlePlayer::direct(int8 dir)
{
	if (dir != 0)
	{
		if (pCharacter->Face != dir)
			pCharacter->Face = dir;

		if (pCharacter->IsGround)
			_PumpControl.Clear();
	}

	pCharacter->Dir = dir;
}
CBattlePlayer::PushType CBattlePlayer::push(int64 tick)
{
	if (!IsAlive())
		return PushType::null;

	if (canFlap(*pCharacter)) // Flap
	{
		flap(tick);
		return PushType::flap;
	}
	else if (canPump(*pCharacter) && _PumpControl.canPump())
	{
		pump();
		return PushType::pump;
	}
	else
	{
		return PushType::null;
	}
}
void CBattlePlayer::flap(int64 tick)
{
	if (!IsStaminaFree() && pCharacter->StaminaInfo.Stamina >= 1.0f)
	{
		pCharacter->StaminaInfo.Stamina -= 1.0f;
		pCharacter->StaminaInfo.LastUsedTick = tick;
	}

	auto YDiff = pMeta->pCharacterTypeMeta->MaxVelAir - pPlayerObject->Velocity.Y;
	if (YDiff > 0.0f)
	{
		if (YDiff > c_FlapDeltaVelUp)
			pPlayerObject->Velocity.Y += c_FlapDeltaVelUp;
		else
			pPlayerObject->Velocity.Y = pMeta->pCharacterTypeMeta->MaxVelAir;
	}

	if (pCharacter->Dir > 0)
	{
		auto XDiff = pMeta->pCharacterTypeMeta->MaxVelAir - pPlayerObject->Velocity.X;
		if (XDiff > 0.0f)
		{
			if (XDiff > c_FlapDeltaVelX)
				pPlayerObject->Velocity.X += c_FlapDeltaVelX;
			else
				pPlayerObject->Velocity.X = pMeta->pCharacterTypeMeta->MaxVelAir;
		}
	}
	else if (pCharacter->Dir < 0)
	{
		auto XDiff = pMeta->pCharacterTypeMeta->MaxVelAir + pPlayerObject->Velocity.X;
		if (XDiff > 0.0f)
		{
			if (XDiff > c_FlapDeltaVelX)
				pPlayerObject->Velocity.X -= c_FlapDeltaVelX;
			else
				pPlayerObject->Velocity.X = -pMeta->pCharacterTypeMeta->MaxVelAir;
		}
	}
}
void CBattlePlayer::pump()
{
	_PumpControl.pump();
}
void CBattlePlayer::CheckRegen(int64 tick)
{
	if (IsAlive() || tick < pCharacter->RegenTick)
		return;

	pCharacter->IsGround = false;
	pCharacter->Dir = 0;
	pCharacter->BalloonCount = c_BalloonCountForRegen;
	pCharacter->StaminaInfo.LastUsedTick = tick;
	pCharacter->StaminaInfo.Stamina = pMeta->pCharacterTypeMeta->StaminaMax;
	pCharacter->Face = CEngineGlobal::GetFaceWithX(InitialPos.X);
	pPlayerObject->LocalPosition = InitialPos;
	pPlayerObject->Velocity = SPoint();
	pCharacter->InvulnerableEndTick = CEngineGlobal::GetInvulnerableEndTick(tick);
	pCharacter->ChainKillCount = 0;
	pCharacter->LastKillTick = 0;
	pCharacter->RegenTick = 0;

	_PlayerCollider.pBody->SetEnabled(true);
	_PlayerCollider.pBalloon->SetSizeX(CEngineGlobal::BalloonWidth(pCharacter->BalloonCount));
	_PlayerCollider.pBalloon->SetEnabled(true);
	pPlayerObject->SetEnabled(true);
}
CBattlePlayer::CBattlePlayer(
	const SBattlePlayer Super_,
	const int32 PlayerIndex_,
	const SPoint& InitialPos_,
	const SCharacterMeta* const pMeta_,
	const int8 TeamIndex_,
	const shared_ptr<SCharacter>& pCharacter_,
	TBattlesIt itBattle_,
	CUser* Player_,
	CBattlePlayer* pVirtualBattlePlayer_) :
	SBattlePlayer(Super_),
	PlayerIndex(PlayerIndex_),
	InitialPos(InitialPos_),
	pMeta(pMeta_),
	TeamIndex(TeamIndex_),
	pCharacter(pCharacter_),
	itBattle(itBattle_),
	pPlayer(Player_),
	_PlayerCollider(pCharacter.get()),
	pPlayerObject(make_shared<CBattlePlayerObject>(GetDefaultTransform(InitialPos_), _PlayerCollider.Colliders, SPoint(), pVirtualBattlePlayer_)),
	_PumpControl(
		std::bind(&CBattlePlayer::_PumpCallback, this),
		std::bind(&CBattlePlayer::_PumpDoneCallback, this),
		pMeta->pCharacterTypeMeta->PumpSpeed,
		pCharacter->PumpInfo),
	_ParachuteControl(
		std::bind(&CBattlePlayer::_ParachuteOnCallback, this, _1),
		pCharacter->ParachuteInfo)
{
	_PlayerCollider.pBody->SetEnabled(IsAlive());
	_PlayerCollider.pBalloon->SetEnabled(pCharacter->BalloonCount > 0);
	_PlayerCollider.pParachute->SetEnabled(CEngineGlobal::IsScaling(pCharacter->ParachuteInfo));

	pPlayerObject->fCollisionEnter = std::bind(&CBattlePlayer::_CollisionEnter, this, _1, _2);
	pPlayerObject->fCollisionStay = std::bind(&CBattlePlayer::_CollisionStay, this, _1, _2);
	pPlayerObject->fCollisionExit = std::bind(&CBattlePlayer::_CollisionExit, this, _1, _2);
	pPlayerObject->fFixedUpdate = std::bind(&CBattlePlayer::_FixedUpdate, this, _1);

	pPlayer->BattleBegin(this);
	g_Net->SessionHold(pPlayer->GetSession());
}
CBattlePlayer::~CBattlePlayer()
{
	auto itSession = pPlayer->GetSession();
	g_Users.battle_end(itSession->first);
	g_Net->SessionUnHold(itSession); // SessionUnHold 하면 itSession 이 삭제되므로 마지막에 호출
}
void CBattlePlayer::Link(void)
{
}
void CBattlePlayer::UnLink(void)
{
}
ERet CBattlePlayer::Touch(const SBattleTouchNetCs& Proto_)
{
	return itBattle->get()->Touch(PlayerIndex, Proto_);
}
ERet CBattlePlayer::Push(const SBattlePushNetCs& Proto_)
{
	return itBattle->get()->Push(PlayerIndex, Proto_);
}
void CBattlePlayer::QuestDone(EQuestType QuestType_, int32 Count_)
{
	auto ib = _DoneQuests.emplace(QuestType_, Count_);
	if (!ib.second)
		ib.first->second += Count_;
}
