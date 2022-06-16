#include "stdafx.h"

void CBattlePlayer::_PumpCallback(void)
{
}
void CBattlePlayer::_PumpDoneCallback(void)
{
	pCharacter->BalloonCount = c_BalloonCountForPump;
	_PlayerCollider.pBalloon->SetSizeX(CEngineGlobal::BalloonWidth(pCharacter->BalloonCount));
	_PlayerCollider.pBalloon->LocalEnabled = true;
	pCharacter->Acc.Y = c_Gravity;
	_ParachuteControl.Clear();
	++pPlayer->GetUserDB().BlowBalloonTotal;
	QuestDone(EQuestType::BlowBalloon, 1);
}
void CBattlePlayer::_ParachuteOnCallback(bool On_)
{
	_PlayerCollider.pParachute->LocalEnabled = On_;
}
void CBattlePlayer::_AttachGround(const shared_ptr<CCollider2D>& pOtherCollider_)
{
	if (!_AttachedGrounds.emplace(pOtherCollider_).second || _AttachedGrounds.size() != 1) // 최초 지형이 붙었을 때 한번만 코드 실행 위해 1과 비교
		return;

	pCharacter->IsGround = true;
	pCharacter->Acc.X = pMeta->RunAcc * pCharacter->Dir;

	if (pCharacter->BalloonCount == 0)
		_ParachuteControl.Off();
}
void CBattlePlayer::_DetachGround(const shared_ptr<CCollider2D>& pOtherCollider_)
{
	if (_AttachedGrounds.erase(pOtherCollider_) == 0 || _AttachedGrounds.size() != 0) // 마지막 지형이 떨어졌을때 한번만 코드 실행 위해 0과 비교
		return;

	pCharacter->IsGround = false;

	if (pCharacter->BalloonCount == 0)
		pCharacter->Acc.X = c_ParachuteAccX * pCharacter->Dir;

	_PumpControl.Clear();

	if (pCharacter->BalloonCount == 0)
		_ParachuteControl.On();
}
void CBattlePlayer::Bounce(const SPoint& Normal_)
{
	if (Normal_.X != 0.0f)
	{
		if (pPlayerObject->Velocity.X > 0.0f && Normal_.X < 0.0f ||
			pPlayerObject->Velocity.X < 0.0f && Normal_.X > 0.0f)
		{
			pPlayerObject->Velocity.X = -pPlayerObject->Velocity.X;
		}
	}
	else if (Normal_.Y != 0.0f)
	{
		if (pPlayerObject->Velocity.Y > 0.0f && Normal_.Y < 0.0f ||
			pPlayerObject->Velocity.Y < 0.0f && Normal_.Y > 0.0f)
		{
			pPlayerObject->Velocity.Y = -pPlayerObject->Velocity.Y;
		}
	}
}
void CBattlePlayer::_Dead(int64 Tick_)
{
	pPlayerObject->Velocity.X = 0.0f;
	pPlayerObject->Velocity.Y = c_DieUpVel;
	pCharacter->Dir = 0;
	pCharacter->Acc.X = 0.0f;
	pCharacter->Acc.Y = (c_Gravity * c_GravityDeadRatio);
	pCharacter->RegenTick = Tick_ + c_RegenDelayTickCount;

	_PumpControl.Clear();
	_ParachuteControl.Clear();
	_PlayerCollider.pBalloon->LocalEnabled = false;
	_PlayerCollider.pBody->LocalEnabled = false;
	_PlayerCollider.pParachute->LocalEnabled = false;
}
bool CBattlePlayer::_HitBalloon(int64 Tick_, const SPoint& Normal_) // return true : dead
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
			{
				pCharacter->Acc.X = c_ParachuteAccX * pCharacter->Dir;
				_ParachuteControl.On();
			}

			pCharacter->Acc.Y = (c_Gravity * c_GravityParachuteRatio);
			_PlayerCollider.pBalloon->LocalEnabled = false;
		}

		Bounce(Normal_);

		return false;
	}

	return true;
}
void CBattlePlayer::_SetLandingVelocity(const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	auto ObjectVelocity = pOtherMovingObject_ == nullptr ? SPoint() : pOtherMovingObject_->Velocity;
	if (ObjectVelocity.Y > pPlayerObject->Velocity.Y)
		pPlayerObject->Velocity.Y = ObjectVelocity.Y;

	if (pCharacter->Dir == 0)
	{
		auto DiffX = ObjectVelocity.X - pPlayerObject->Velocity.X;
		if (DiffX > 0.0f)
		{
			if (DiffX > c_LandXDragPerFrame)
				pPlayerObject->Velocity.X += c_LandXDragPerFrame;
			else
				pPlayerObject->Velocity.X = ObjectVelocity.X;
		}
		else
		{
			if (DiffX < -c_LandXDragPerFrame)
				pPlayerObject->Velocity.X -= c_LandXDragPerFrame;
			else
				pPlayerObject->Velocity.X = ObjectVelocity.X;

		}
	}
}
bool CBattlePlayer::_CheckCollisionEnterStructure(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (pOtherCollider_->Number == CEngineGlobal::c_StructureNumber &&
		pCollider_->Number == CEngineGlobal::c_BodyNumber && Normal_.Y > 0.0f)
	{
		_SetLandingVelocity(pOtherMovingObject_);
		_AttachGround(pOtherCollider_);
		return true;
	}
	else
	{
		return false;
	}
}
void CBattlePlayer::_CollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (_CheckCollisionEnterStructure(Tick_, Normal_, pCollider_, pOtherCollider_, pOtherMovingObject_))
		return;

	if (_CheckCollisionEnter(Tick_, Normal_, pCollider_, pOtherCollider_, pOtherMovingObject_))
		return;

	Bounce(Normal_);
}
void CBattlePlayer::_CollisionStay(int64 Tick_, const CPlayerObject2D::TContactPoint2Ds& ContactPoint2Ds_)
{
	for (auto& i : ContactPoint2Ds_)
	{
		if (i.first.pCollider->Number == CEngineGlobal::c_BodyNumber && i.first.pOtherCollider->Number == CEngineGlobal::c_StructureNumber) // 몸이 지형에 닿았으면
		{
			if (i.second.Normal.Y > 0.0f)
			{
				_SetLandingVelocity(i.second.pOtherMovingObject);
				_AttachGround(i.first.pOtherCollider);
			}
			else
			{
				_DetachGround(i.first.pOtherCollider);
			}
		}
	}
}
void CBattlePlayer::_CollisionExit(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (pCollider_->Number != CEngineGlobal::c_BodyNumber || pOtherCollider_->Number != CEngineGlobal::c_StructureNumber)
		return;

	_DetachGround(pOtherCollider_);
}
void CBattlePlayer::_FixedUpdate(int64 Tick_)
{
	if (Tick_ > pCharacter->StaminaInfo.LastUsedTick + pMeta->StaminaRegenDelay)
	{
		pCharacter->StaminaInfo.Stamina += ((Tick_ - (pCharacter->StaminaInfo.LastUsedTick + pMeta->StaminaRegenDelay)) * pMeta->StaminaPerTick);
		if (pCharacter->StaminaInfo.Stamina > pMeta->StaminaMax)
			pCharacter->StaminaInfo.Stamina = pMeta->StaminaMax;
	}

	// 변위 = 0.5 * g * t*t + 현재v * t
	//      = t * (0.5 * g * t + 현재v)
	pPlayerObject->LocalPosition.X += (CEngine::GetDeltaTime() * (0.5f * pCharacter->Acc.X * CEngine::GetDeltaTime() + pPlayerObject->Velocity.X));
	pPlayerObject->LocalPosition.Y += (CEngine::GetDeltaTime() * (0.5f * pCharacter->Acc.Y * CEngine::GetDeltaTime() + pPlayerObject->Velocity.Y));

	// X 속도 처리
	if (pCharacter->IsGround)
	{
		// X 축 속도 처리
		if (pCharacter->Dir > 0)
		{
			if (pPlayerObject->Velocity.X < pMeta->MaxVelXGround) // 최고 속도가 아니면
			{
				pPlayerObject->Velocity.X += pCharacter->Acc.X * CEngine::GetDeltaTime();
				if (pPlayerObject->Velocity.X > pMeta->MaxVelXGround)
					pPlayerObject->Velocity.X = pMeta->MaxVelXGround;
			}
			else if (pPlayerObject->Velocity.X > pMeta->MaxVelXGround) // 점진적 감속
			{
				auto ReducedVel = (c_GroundResistance * CEngine::GetDeltaTime());
				if (pPlayerObject->Velocity.X - ReducedVel > pMeta->MaxVelXGround)
					pPlayerObject->Velocity.X -= ReducedVel;
				else
					pPlayerObject->Velocity.X = pMeta->MaxVelXGround;
			}
		}
		else if (pCharacter->Dir < 0)
		{
			if (pPlayerObject->Velocity.X > -pMeta->MaxVelXGround) // 최고 속도가 아니면
			{
				pPlayerObject->Velocity.X += pCharacter->Acc.X * CEngine::GetDeltaTime();
				if (pPlayerObject->Velocity.X < -pMeta->MaxVelXGround)
					pPlayerObject->Velocity.X = -pMeta->MaxVelXGround;
			}
			else if (pPlayerObject->Velocity.X < -pMeta->MaxVelXGround) // 점진적 감속
			{
				auto ReducedVel = (c_GroundResistance * CEngine::GetDeltaTime());
				if (pPlayerObject->Velocity.X + ReducedVel < -pMeta->MaxVelXGround)
					pPlayerObject->Velocity.X += ReducedVel;
				else
					pPlayerObject->Velocity.X = -pMeta->MaxVelXGround;
			}
		}
		else // 정지할 때 까지 감속
		{
			_PumpControl.FixedUpdate();
		}
	}
	else
	{
		// X 축 속도 처리
		if (pCharacter->BalloonCount == 0 && pCharacter->Dir != 0) // 최대 속도까지 가속
		{
			if (!(pCharacter->Dir == 1 && pPlayerObject->Velocity.X >= c_MaxVelParachuteX ||
				pCharacter->Dir == -1 && pPlayerObject->Velocity.X <= -c_MaxVelParachuteX)) // 현재 최고가 아니면
			{
				pPlayerObject->Velocity.X += pCharacter->Acc.X * CEngine::GetDeltaTime();
				if (pPlayerObject->Velocity.X > c_MaxVelParachuteX)
					pPlayerObject->Velocity.X = c_MaxVelParachuteX;
				else if (pPlayerObject->Velocity.X < -c_MaxVelParachuteX)
					pPlayerObject->Velocity.X = -c_MaxVelParachuteX;
			}
		}
	}

	if (_ParachuteControl.FixedUpdate())
		_PlayerCollider.pParachute->LocalScale.X = _PlayerCollider.pParachute->LocalScale.Y = pCharacter->ParachuteInfo.Scale;

	// Y 축 속도 처리
	pPlayerObject->Velocity.Y += pCharacter->Acc.Y * CEngine::GetDeltaTime();

	auto MaxVelY = 0.0f;
	if (pCharacter->BalloonCount > 0)
		MaxVelY = -pMeta->MaxVelDown;
	else if (pCharacter->BalloonCount == 0)
		MaxVelY = -c_MaxVelParachuteY;
	else
		MaxVelY = -c_MaxVelDeadY;

	if (pPlayerObject->Velocity.Y < MaxVelY)
		pPlayerObject->Velocity.Y = MaxVelY;
}
bool CBattlePlayer::IsInvulerable(int64 Tick_)
{
	return (Tick_ < pCharacter->InvulnerableEndTick);
}
bool CBattlePlayer::IsAlive(void) const
{
	return pCharacter->BalloonCount >= 0;
}
bool CBattlePlayer::Touch(int8 Dir_)
{
	if (!IsAlive())
		return false;

	if (Dir_ == pCharacter->Dir || Dir_ < -1 || Dir_ > 1)
		return false;

	if (Dir_ == 0)
	{
		pCharacter->Acc.X = 0.0f;
	}
	else
	{
		if (pCharacter->Face != Dir_)
			pCharacter->Face = Dir_;

		if (pCharacter->IsGround)
		{
			pCharacter->Acc.X = pMeta->RunAcc * Dir_;
			_PumpControl.Clear();
		}
		else if (pCharacter->BalloonCount == 0)
		{
			pCharacter->Acc.X = c_ParachuteAccX * Dir_;
		}
	}

	pCharacter->Dir = Dir_;

	return true;
}
bool CBattlePlayer::Push(int64 Tick_)
{
	if (!IsAlive())
		return false;

	if (pCharacter->BalloonCount > 0) // Flap
	{
		if (!IsStaminaFree())
		{
			if (pCharacter->StaminaInfo.Stamina < 1.0f)
				return false;

			pCharacter->StaminaInfo.Stamina -= 1.0f;
			pCharacter->StaminaInfo.LastUsedTick = Tick_;
		}

		pPlayerObject->Velocity.Y += pMeta->FlapDeltaVelUp;
		if (pPlayerObject->Velocity.Y > pMeta->MaxVelUp)
			pPlayerObject->Velocity.Y = pMeta->MaxVelUp;

		if (pCharacter->Dir > 0)
		{
			if (pPlayerObject->Velocity.X + pMeta->FlapDeltaVelX > pMeta->MaxVelXAir)
			{
				if (pMeta->MaxVelXAir > pPlayerObject->Velocity.X)
					pPlayerObject->Velocity.X = pMeta->MaxVelXAir;
			}
			else
			{
				pPlayerObject->Velocity.X += pMeta->FlapDeltaVelX;
			}
		}
		else if (pCharacter->Dir < 0)
		{
			if (pPlayerObject->Velocity.X - pMeta->FlapDeltaVelX < -pMeta->MaxVelXAir)
			{
				if (-pMeta->MaxVelXAir < pPlayerObject->Velocity.X)
					pPlayerObject->Velocity.X = -pMeta->MaxVelXAir;
			}
			else
			{
				pPlayerObject->Velocity.X -= pMeta->FlapDeltaVelX;
			}
		}

		return true;
	}
	else if (pCharacter->BalloonCount == 0 && pCharacter->IsGround && pCharacter->Dir == 0)
	{
		return _PumpControl.Pump();
	}

	return false;
}
void CBattlePlayer::Link(int64 Tick_)
{
}
void CBattlePlayer::UnLink(int64 Tick_)
{
	Touch(0);
}
void CBattlePlayer::CheckRegen(int64 Tick_)
{
	if (IsAlive() || Tick_ < pCharacter->RegenTick)
		return;

	pCharacter->IsGround = false;
	pCharacter->Dir = 0;
	pCharacter->BalloonCount = c_BalloonCountForRegen;
	pCharacter->StaminaInfo.LastUsedTick = Tick_;
	pCharacter->StaminaInfo.Stamina = pMeta->StaminaMax;
	pCharacter->Face = CEngineGlobal::GetFaceWithPosition(InitialPos);
	pPlayerObject->LocalPosition = InitialPos;
	pPlayerObject->Velocity = SPoint();
	pCharacter->Acc = SPoint(0.0f, c_Gravity);
	pCharacter->InvulnerableEndTick = CEngineGlobal::GetInvulnerableEndTick(Tick_);
	pCharacter->ChainKillCount = 0;
	pCharacter->LastKillTick = 0;
	pCharacter->RegenTick = 0;

	_PlayerCollider.pBody->LocalEnabled = true;
	_PlayerCollider.pBalloon->SetSizeX(CEngineGlobal::BalloonWidth(pCharacter->BalloonCount));
	_PlayerCollider.pBalloon->LocalEnabled = true;
	_fRegen(PlayerIndex);
}
CBattlePlayer::CBattlePlayer(
	const SBattlePlayer Super_,
	FRegen fRegen_,
	const int32 PlayerIndex_,
	const SPoint& InitialPos_,
	const SCharacterMeta* const pMeta_,
	const int8 TeamIndex_,
	const shared_ptr<SCharacter>& pCharacter_,
	TBattlesIt itBattle_,
	CUser* Player_,
	CBattlePlayer* pVirtualBattlePlayer_) :
	SBattlePlayer(Super_),
	_fRegen(fRegen_),
	PlayerIndex(PlayerIndex_),
	InitialPos(InitialPos_),
	pMeta(pMeta_),
	TeamIndex(TeamIndex_),
	pCharacter(pCharacter_),
	itBattle(itBattle_),
	pPlayer(Player_),
	_BalloonHitControl(PlayerIndex_),
	_PlayerCollider(pCharacter.get()),
	pPlayerObject(make_shared<CBattlePlayerObject>(GetDefaultTransform(InitialPos_), SPoint(), pVirtualBattlePlayer_)),
	_PumpControl(
		std::bind(&CBattlePlayer::_PumpCallback, this),
		std::bind(&CBattlePlayer::_PumpDoneCallback, this),
		pMeta->PumpSpeed,
		pCharacter->PumpInfo),
	_ParachuteControl(
		std::bind(&CBattlePlayer::_ParachuteOnCallback, this, _1),
		pCharacter->ParachuteInfo)
{
	_PlayerCollider.pBody->LocalEnabled = IsAlive();
	_PlayerCollider.pBalloon->LocalEnabled = (pCharacter->BalloonCount > 0);
	_PlayerCollider.pParachute->LocalEnabled = CEngineGlobal::IsScaling(pCharacter->ParachuteInfo);

	SetColliderToMovingObject2D(_PlayerCollider.pPlayer, pPlayerObject);
	pPlayerObject->fCollisionEnter = std::bind(&CBattlePlayer::_CollisionEnter, this, _1, _2, _3, _4, _5);
	pPlayerObject->fCollisionStay = std::bind(&CBattlePlayer::_CollisionStay, this, _1, _2);
	pPlayerObject->fCollisionExit = std::bind(&CBattlePlayer::_CollisionExit, this, _1, _2, _3, _4, _5);
	pPlayerObject->fFixedUpdate = std::bind(&CBattlePlayer::_FixedUpdate, this, _1);

	pPlayer->BattleBegin(this);
	g_Net->SessionHold(pPlayer->GetSession());
}
void CBattlePlayer::OnLine(void)
{
	itBattle->get()->OnLine(PlayerIndex);
}
void CBattlePlayer::OffLine(void)
{
	itBattle->get()->OffLine(PlayerIndex);
}
ERet CBattlePlayer::Touch(const SBattleTouchNetCs& Proto_)
{
	return itBattle->get()->Touch(PlayerIndex, Proto_);
}
ERet CBattlePlayer::Push(const SBattlePushNetCs& Proto_)
{
	return itBattle->get()->Push(PlayerIndex, Proto_);
}
void CBattlePlayer::BattleEnd(void)
{
	auto itSession = pPlayer->GetSession();
	g_Users.battle_end(itSession->first);
	g_Net->SessionUnHold(itSession); // SessionUnHold 하면 itSession 이 삭제되므로 마지막에 호출
}
void CBattlePlayer::QuestDone(EQuestType QuestType_, int32 Count_)
{
	auto ib = _DoneQuests.emplace(QuestType_, Count_);
	if (!ib.second)
		ib.first->second += Count_;
}
