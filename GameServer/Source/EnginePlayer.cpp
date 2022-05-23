#include "stdafx.h"

void CEnginePlayer::_PumpCallback(void)
{
}
void CEnginePlayer::_PumpDoneCallback(void)
{
	_pCharacter->BalloonCount = c_BalloonCountForPump;
	_pBalloon->SetSizeX(CEngineGlobal::BalloonWidth(_pCharacter->BalloonCount));
	_pBalloon->Enabled = true;
	_pCharacter->Acc.Y = c_Gravity;
	_ParachuteControl.Clear();
	_pBattlePlayer->PumpDone();
}
void CEnginePlayer::_ParachuteOnCallback(bool On_)
{
	_pParachute->Enabled = On_;
}
void CEnginePlayer::_AttachGround(CCollider2D* pOtherCollider_)
{
	if (!_AttachedGrounds.emplace(pOtherCollider_).second || _AttachedGrounds.size() != 1) // 최초 지형이 붙었을 때 한번만 코드 실행 위해 1과 비교
		return;

	_pCharacter->IsGround = true;
	_pCharacter->Acc.X = GetMeta()->RunAcc * _pCharacter->Dir;

	if (_pCharacter->BalloonCount == 0)
		_ParachuteControl.Off();
}
void CEnginePlayer::_DetachGround(CCollider2D* pOtherCollider_)
{
	if (_AttachedGrounds.erase(pOtherCollider_) == 0 || _AttachedGrounds.size() != 0) // 마지막 지형이 떨어졌을때 한번만 코드 실행 위해 0과 비교
		return;

	_pCharacter->IsGround = false;

	if (_pCharacter->BalloonCount == 0)
		_pCharacter->Acc.X = c_ParachuteAccX * _pCharacter->Dir;

	_PumpControl.Clear();

	if (_pCharacter->BalloonCount == 0)
		_ParachuteControl.On();
}
void CEnginePlayer::_Bounce(const SPoint& Normal_)
{
	if (Normal_.X != 0.0f)
	{
		if (Velocity.X > 0.0f && Normal_.X < 0.0f ||
			Velocity.X < 0.0f && Normal_.X > 0.0f)
		{
			Velocity.X = -Velocity.X;
		}
	}
	else if (Normal_.Y != 0.0f)
	{
		if (Velocity.Y > 0.0f && Normal_.Y < 0.0f ||
			Velocity.Y < 0.0f && Normal_.Y > 0.0f)
		{
			Velocity.Y = -Velocity.Y;
		}
	}
}
CEnginePlayer::CEnginePlayer(
	FHit fHit_,
	FRegen fRegen_,
	FGetItem fGetItem_,
	int32 PlayerIndex_,
	const SPoint& InitialPos_,
	const SCharacterMeta* pMeta_,
	int8 TeamIndex_,
	unique_ptr<SCharacter> pCharacter_,
	unique_ptr<CCollider2D> pPlayerCollider_,
	CRectCollider2D* pBody_,
	CRectCollider2D* pBalloon_,
	CRectCollider2D* pParachute_,
	CBattlePlayer* pBattlePlayer_) :
	CPlayerObject2D(InitialPos_, std::move(pPlayerCollider_), SPoint()),
	_fHit(fHit_),
	_fRegen(fRegen_),
	_fGetItem(fGetItem_),
	_PlayerIndex(PlayerIndex_),
	_InitialPos(InitialPos_),
	_pMeta(pMeta_),
	_TeamIndex(TeamIndex_),
	_pCharacter(std::move(pCharacter_)),
	_PumpControl(
		std::bind(&CEnginePlayer::_PumpCallback, this),
		std::bind(&CEnginePlayer::_PumpDoneCallback, this),
		pMeta_->PumpSpeed,
		_pCharacter->PumpInfo),
	_ParachuteControl(
		std::bind(&CEnginePlayer::_ParachuteOnCallback, this, _1),
		_pCharacter->ParachuteInfo),
	_pBody(pBody_),
	_pBalloon(pBalloon_),
	_pParachute(pParachute_),
	_pBattlePlayer(pBattlePlayer_)
{
	_pBody->Enabled = IsAlive();
	_pBalloon->Enabled = (_pCharacter->BalloonCount > 0);
	_pParachute->Enabled = CEngineGlobal::IsScaling(_pCharacter->ParachuteInfo);
}
void CEnginePlayer::_Hit(int64 Tick_, const SPoint& Normal_, CEnginePlayer* pAttacker_)
{
	--_pCharacter->BalloonCount;

	if (_pCharacter->BalloonCount >= 0)
	{
		if (_pCharacter->BalloonCount > 0)
		{
			_pBalloon->SetSizeX(CEngineGlobal::BalloonWidth(_pCharacter->BalloonCount));
		}
		else
		{
			if (!_pCharacter->IsGround)
			{
				_pCharacter->Acc.X = c_ParachuteAccX * _pCharacter->Dir;
				_ParachuteControl.On();
			}

			_pCharacter->Acc.Y = (c_Gravity * c_GravityParachuteRatio);
			_pBalloon->Enabled = false;
		}

		_Bounce(Normal_);
	}
	else // Die
	{
		if ((Tick_ - pAttacker_->_pCharacter->LastKillTick) < c_ChainKillDelayTickCount)
			++pAttacker_->_pCharacter->ChainKillCount;
		else
			pAttacker_->_pCharacter->ChainKillCount = 1;

		pAttacker_->_pCharacter->LastKillTick = Tick_;

		Velocity.X = 0.0f;
		Velocity.Y = c_DieUpVel;
		_pCharacter->Dir = 0;
		_pCharacter->Acc.X = 0.0f;
		_pCharacter->Acc.Y = (c_Gravity * c_GravityDeadRatio);
		_pCharacter->RegenTick = Tick_ + c_RegenDelayTickCount;

		_PumpControl.Clear();
		_ParachuteControl.Clear();
		_pBody->Enabled = false;
		_pParachute->Enabled = false;
	}

	_fHit(*pAttacker_, *this);
}
void CEnginePlayer::_SetLandingVelocity(CMovingObject2D* pOtherMovingObject_)
{
	auto ObjectVelocity = pOtherMovingObject_ == nullptr ? SPoint() : pOtherMovingObject_->Velocity;
	if (ObjectVelocity.Y > Velocity.Y)
		Velocity.Y = ObjectVelocity.Y;

	if (_pCharacter->Dir == 0)
	{
		auto DiffX = ObjectVelocity.X - Velocity.X;
		if (DiffX > 0.0f)
		{
			if (DiffX > c_LandXDragPerFrame)
				Velocity.X += c_LandXDragPerFrame;
			else
				Velocity.X = ObjectVelocity.X;
		}
		else
		{
			if (DiffX < -c_LandXDragPerFrame)
				Velocity.X -= c_LandXDragPerFrame;
			else
				Velocity.X = ObjectVelocity.X;

		}
	}
}
void CEnginePlayer::OnCollisionEnter(int64 Tick_, const SPoint& Normal_, CCollider2D* pCollider_, CCollider2D* pOtherCollider_, CMovingObject2D* pOtherMovingObject_)
{
	if (pOtherCollider_->Number == CEngineGlobal::c_StructureNumber)
	{
		if (pCollider_->Number == CEngineGlobal::c_BodyNumber && Normal_.Y > 0.0f)
		{
			_SetLandingVelocity(pOtherMovingObject_);
			_AttachGround(pOtherCollider_);
		}
		else
		{
			_Bounce(Normal_);
		}
	}
	else
	{
		auto* pOtherPlayer = dynamic_cast<CEnginePlayer*>(pOtherMovingObject_);
		if (pOtherPlayer == nullptr)
			return;

		if (GetTeamIndex() != pOtherPlayer->GetTeamIndex() && // 다른편이고
			pOtherCollider_->Number == CEngineGlobal::c_BodyNumber && // 적의 몸과 부딪혔고
			!CEngineGlobal::IsInvulerable(*_pCharacter, Tick_) && // 내가 무적이 아니고
			!CEngineGlobal::IsInvulerable(*pOtherPlayer->_pCharacter, Tick_) && // 적이 무적이 아니고
			pOtherPlayer->_pCharacter->BalloonCount > 0 && // 적이 풍선이 있고
			(pCollider_->Number == CEngineGlobal::c_BalloonNumber || _pCharacter->BalloonCount == 0)) // 내 풍선과 부딪혔거나, 내 풍선이 없으면
		{
			_Hit(Tick_, Normal_, pOtherPlayer);
			pOtherPlayer->_Bounce(Normal_ * -1.0f);
		}
		else
		{
			_Bounce(Normal_);
		}
	}
}
void CEnginePlayer::OnCollisionStay(int64 Tick_, const CPlayerObject2D::TContactPoint2Ds& ContactPoint2Ds_)
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
void CEnginePlayer::OnCollisionExit(int64 Tick_, const SPoint& Normal_, CCollider2D* pCollider_, CCollider2D* pOtherCollider_, CMovingObject2D* pOtherMovingObject_)
{
	if (pCollider_->Number != CEngineGlobal::c_BodyNumber || pOtherCollider_->Number != CEngineGlobal::c_StructureNumber)
		return;

	_DetachGround(pOtherCollider_);
}
bool CEnginePlayer::IsAlive(void) const
{
	return CEngineGlobal::IsAlive(*_pCharacter);
}
bool CEnginePlayer::Touch(int8 Dir_)
{
	if (!CEngineGlobal::IsAlive(*_pCharacter))
		return false;

	if (Dir_ == _pCharacter->Dir || Dir_ < -1 || Dir_ > 1)
		return false;

	if (Dir_ == 0)
	{
		_pCharacter->Acc.X = 0.0f;
	}
	else
	{
		if (_pCharacter->Face != Dir_)
			_pCharacter->Face = Dir_;

		if (_pCharacter->IsGround)
		{
			_pCharacter->Acc.X = GetMeta()->RunAcc * Dir_;
			_PumpControl.Clear();
		}
		else if (_pCharacter->BalloonCount == 0)
		{
			_pCharacter->Acc.X = c_ParachuteAccX * Dir_;
		}
	}

	_pCharacter->Dir = Dir_;

	return true;
}
bool CEnginePlayer::Push(int64 Tick_)
{
	if (!CEngineGlobal::IsAlive(*_pCharacter))
		return false;

	if (_pCharacter->BalloonCount > 0) // Flap
	{
		// Stamina /////////////////////////
		if (_pCharacter->StaminaInfo.Stamina < 1.0f)
			return false;

		_pCharacter->StaminaInfo.Stamina -= 1.0f;
		_pCharacter->StaminaInfo.LastUsedTick = Tick_;
		/////////////////////////////////////////

		Velocity.Y += GetMeta()->FlapDeltaVelUp;
		if (Velocity.Y > GetMeta()->MaxVelUp)
			Velocity.Y = GetMeta()->MaxVelUp;

		if (_pCharacter->Dir > 0)
		{
			if (Velocity.X + GetMeta()->FlapDeltaVelX > GetMeta()->MaxVelXAir)
			{
				if (GetMeta()->MaxVelXAir > Velocity.X)
					Velocity.X = GetMeta()->MaxVelXAir;
			}
			else
			{
				Velocity.X += GetMeta()->FlapDeltaVelX;
			}
		}
		else if (_pCharacter->Dir < 0)
		{
			if (Velocity.X - GetMeta()->FlapDeltaVelX < -GetMeta()->MaxVelXAir)
			{
				if (-GetMeta()->MaxVelXAir < Velocity.X)
					Velocity.X = -GetMeta()->MaxVelXAir;
			}
			else
			{
				Velocity.X -= GetMeta()->FlapDeltaVelX;
			}
		}

		return true;
	}
	else if (_pCharacter->BalloonCount == 0 && _pCharacter->IsGround && _pCharacter->Dir == 0)
	{
		return _PumpControl.Pump();
	}

	return false;
}
void CEnginePlayer::Link(int64 Tick_)
{
}
void CEnginePlayer::UnLink(int64 Tick_)
{
	Touch(0);
}
void CEnginePlayer::CheckRegen(int64 Tick_)
{
	if (IsAlive() || Tick_ < _pCharacter->RegenTick)
		return;

	_pCharacter->IsGround = false;
	_pCharacter->Dir = 0;
	_pCharacter->BalloonCount = c_BalloonCountForRegen;
	_pCharacter->StaminaInfo.LastUsedTick = Tick_;
	_pCharacter->StaminaInfo.Stamina = GetMeta()->StaminaMax;
	_pCharacter->Face = CEngineGlobal::GetFace(_InitialPos);
	LocalPosition = _InitialPos;
	Velocity = SPoint();
	_pCharacter->Acc = SPoint(0.0f, c_Gravity);
	_pCharacter->InvulnerableEndTick = CEngineGlobal::GetInvulnerableEndTick(Tick_);
	_pCharacter->ChainKillCount = 0;
	_pCharacter->LastKillTick = 0;
	_pCharacter->RegenTick = 0;

	_pBody->Enabled = true;
	_pBalloon->SetSizeX(CEngineGlobal::BalloonWidth(_pCharacter->BalloonCount));
	_pBalloon->Enabled = true;
	_fRegen(*this);
}
void CEnginePlayer::FixedUpdate(int64 Tick_)
{
	if (Tick_ > _pCharacter->StaminaInfo.LastUsedTick + GetMeta()->StaminaRegenDelay)
	{
		_pCharacter->StaminaInfo.Stamina += ((Tick_ - (_pCharacter->StaminaInfo.LastUsedTick + GetMeta()->StaminaRegenDelay)) * GetMeta()->StaminaPerTick);
		if (_pCharacter->StaminaInfo.Stamina > GetMeta()->StaminaMax)
			_pCharacter->StaminaInfo.Stamina = GetMeta()->StaminaMax;
	}

	// 변위 = 0.5 * g * t*t + 현재v * t
	//      = t * (0.5 * g * t + 현재v)

	LocalPosition.X += (CEngine::GetDeltaTime() * (0.5f * _pCharacter->Acc.X * CEngine::GetDeltaTime() + Velocity.X));
	LocalPosition.Y += (CEngine::GetDeltaTime() * (0.5f * _pCharacter->Acc.Y * CEngine::GetDeltaTime() + Velocity.Y));

	// X 속도 처리
	if (_pCharacter->IsGround)
	{
		// X 축 속도 처리
		if (_pCharacter->Dir > 0)
		{
			if (Velocity.X < GetMeta()->MaxVelXGround) // 최고 속도가 아니면
			{
				Velocity.X += _pCharacter->Acc.X * CEngine::GetDeltaTime();
				if (Velocity.X > GetMeta()->MaxVelXGround)
					Velocity.X = GetMeta()->MaxVelXGround;
			}
			else if (Velocity.X > GetMeta()->MaxVelXGround) // 점진적 감속
			{
				auto ReducedVel = (c_GroundResistance * CEngine::GetDeltaTime());
				if (Velocity.X - ReducedVel > GetMeta()->MaxVelXGround)
					Velocity.X -= ReducedVel;
				else
					Velocity.X = GetMeta()->MaxVelXGround;
			}
		}
		else if (_pCharacter->Dir < 0)
		{
			if (Velocity.X > -GetMeta()->MaxVelXGround) // 최고 속도가 아니면
			{
				Velocity.X += _pCharacter->Acc.X * CEngine::GetDeltaTime();
				if (Velocity.X < -GetMeta()->MaxVelXGround)
					Velocity.X = -GetMeta()->MaxVelXGround;
			}
			else if (Velocity.X < -GetMeta()->MaxVelXGround) // 점진적 감속
			{
				auto ReducedVel = (c_GroundResistance * CEngine::GetDeltaTime());
				if (Velocity.X + ReducedVel < -GetMeta()->MaxVelXGround)
					Velocity.X += ReducedVel;
				else
					Velocity.X = -GetMeta()->MaxVelXGround;
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
		if (_pCharacter->BalloonCount == 0 && _pCharacter->Dir != 0) // 최대 속도까지 가속
		{
			if (!(_pCharacter->Dir == 1 && Velocity.X >= c_MaxVelParachuteX ||
				_pCharacter->Dir == -1 && Velocity.X <= -c_MaxVelParachuteX)) // 현재 최고가 아니면
			{
				Velocity.X += _pCharacter->Acc.X * CEngine::GetDeltaTime();
				if (Velocity.X > c_MaxVelParachuteX)
					Velocity.X = c_MaxVelParachuteX;
				else if (Velocity.X < -c_MaxVelParachuteX)
					Velocity.X = -c_MaxVelParachuteX;
			}
		}
	}

	if (_ParachuteControl.FixedUpdate())
		_pParachute->SetScale(_pCharacter->ParachuteInfo.Scale);

	// Y 축 속도 처리
	Velocity.Y += _pCharacter->Acc.Y * CEngine::GetDeltaTime();

	auto MaxVelY = 0.0f;
	if (_pCharacter->BalloonCount > 0)
		MaxVelY = -GetMeta()->MaxVelDown;
	else if (_pCharacter->BalloonCount == 0)
		MaxVelY = -c_MaxVelParachuteY;
	else
		MaxVelY = -c_MaxVelDeadY;

	if (Velocity.Y < MaxVelY)
		Velocity.Y = MaxVelY;
}
