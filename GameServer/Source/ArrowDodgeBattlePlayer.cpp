#include "stdafx.h"

CArrowDodgeBattlePlayer::CArrowDodgeBattlePlayer(
	const SBattlePlayer Super_,
	FRegen fRegen_,
	const SPoint& InitialPos_,
	const SCharacterMeta* const pMeta_,
	const shared_ptr<SCharacter>& pCharacter_,
	TBattlesIt itBattle_,
	CUser* Player_,
	FHitArrow fHitArrow_,
	FGetItem fGetItem_,
	CArrowDodgeBattle* pArrowDodgeBattle_) :
	CBattlePlayer(
		Super_,
		fRegen_,
		0,
		InitialPos_,
		pMeta_,
		0,
		pCharacter_,
		itBattle_,
		Player_,
		this),
	_fHitArrow(fHitArrow_),
	_fGetItem(fGetItem_),
	pArrowDodgeBattle(pArrowDodgeBattle_)
{
}
void CArrowDodgeBattlePlayer::BattleEnd(bool Force_)
{
	QuestDone(EQuestType::PlaySingle, 1);

	if (BattleInfo.Second > 0)
		QuestDone(EQuestType::SingleTime, BattleInfo.Second);

	if (BattleInfo.Gold > 0)
		QuestDone(EQuestType::SinglePlayGoldGet, BattleInfo.Gold);

	if (BattleInfo.Point > 0)
		QuestDone(EQuestType::SinglePlayScoreGet, BattleInfo.Point);

	switch (pPlayer->GetSelectedChar()->Grade)
	{
	case EGrade::Normal:
		QuestDone(EQuestType::PlayNormal, 1);
		break;

	case EGrade::Rare:
		QuestDone(EQuestType::PlayRare, 1);
		break;

	case EGrade::Epic:
		QuestDone(EQuestType::PlayEpic, 1);
		break;
	}

	if (Force_)
		pPlayer->ArrowDodgeBattleEnd();
	else
		pPlayer->ArrowDodgeBattleEnd(BattleInfo, _DoneQuests);

	CBattlePlayer::BattleEnd();
}
bool CArrowDodgeBattlePlayer::_CheckCollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (pOtherCollider_->Number == CEngineGlobal::c_ArrowNumber)
	{
		if (pOtherMovingObject_)
		{
			auto pArrow = dynamic_pointer_cast<CArrow>(pOtherMovingObject_);

			if (pArrow->Velocity.X > 0.0f && Normal_.X > 0.0f ||
				pArrow->Velocity.X < 0.0f && Normal_.X < 0.0f ||
				pArrow->Velocity.Y > 0.0f && Normal_.Y > 0.0f ||
				pArrow->Velocity.Y < 0.0f && Normal_.Y < 0.0f)
			{
				if (pCollider_->Number == CEngineGlobal::c_BalloonNumber)
				{
					if (_HitBalloon(Tick_, Normal_))
						_Dead(Tick_);
				}
				else if (pCollider_->Number == CEngineGlobal::c_BodyNumber)
				{
					pCharacter->BalloonCount = -1;
					_Dead(Tick_);
				}

				_fHitArrow(pArrow);

				return true;
			}
		}
	}
	else if (
		pOtherCollider_->Number == CEngineGlobal::c_CoinNumber ||
		pOtherCollider_->Number == CEngineGlobal::c_GoldBarNumber ||
		pOtherCollider_->Number == CEngineGlobal::c_ShieldNumber ||
		pOtherCollider_->Number == CEngineGlobal::c_StaminaNumber)
	{
		auto pItem = dynamic_pointer_cast<CArrowDodgeItem>(pOtherCollider_);
		pItem->Proc(Tick_, this);

		_fGetItem(pItem);

		return true;
	}
	return false;
}
bool CArrowDodgeBattlePlayer::IsStaminaFree(void) const
{
	return Bufs.Stamina.Enabled;
}
void CArrowDodgeBattlePlayer::_FixedUpdate(int64 Tick_)
{
	CBattlePlayer::_FixedUpdate(Tick_);

	if (Bufs.Shield.Enabled && Bufs.Shield.EndTick < Tick_)
		Bufs.Shield.Enabled = false;

	if (Bufs.Stamina.Enabled && Bufs.Stamina.EndTick < Tick_)
		Bufs.Stamina.Enabled = false;
}
void CArrowDodgeBattlePlayer::SetCoinItem(int64 Tick_, const CArrowDodgeCoin* pCoin_)
{
	++BattleInfo.Gold;
}
void CArrowDodgeBattlePlayer::SetGoldBarItem(int64 Tick_, const CArrowDodgeGoldBar* pGoldBar_)
{
	BattleInfo.Gold += 5;
}
void CArrowDodgeBattlePlayer::SetShieldItem(int64 Tick_, const CArrowDodgeShield* pShield_)
{
	Bufs.Shield.Enabled = true;
	Bufs.Shield.EndTick = Tick_ + 70000000;
}
void CArrowDodgeBattlePlayer::SetStaminaItem(int64 Tick_, const CArrowDodgeStamina* pStamina_)
{
	pCharacter->StaminaInfo.Stamina = pMeta->StaminaMax;
	Bufs.Stamina.Enabled = true;
	Bufs.Stamina.EndTick = Tick_ + 70000000;
}
