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
void CArrowDodgeBattlePlayer::BattleEnd(int64 Tick_)
{
	QuestDone(EQuestType::PlaySingle, 1);

	int32 PlaySeconds = (int32)(BattleInfo.Tick / 10000000);
	if (PlaySeconds > 0)
		QuestDone(EQuestType::SingleTime, PlaySeconds);

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

	pPlayer->ArrowDodgeBattleEnd(Tick_, BattleInfo, _DoneQuests);
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
bool CArrowDodgeBattlePlayer::_CheckCollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (__super::_CheckCollisionEnter(Tick_, Normal_, pCollider_, pOtherCollider_, pOtherMovingObject_))
		return true;

	if (pOtherCollider_->Number == CEngineGlobal::c_ArrowNumber)
	{
		if (pOtherMovingObject_)
		{
			auto pArrow = dynamic_pointer_cast<CArrow>(pOtherMovingObject_);

			if (Bufs.Shield.Enabled)
			{
				_fHitArrow(pArrow, true);
				return true;
			}

			if (pArrow->Velocity.X > 0.0f && Normal_.X > 0.0f ||
				pArrow->Velocity.X < 0.0f && Normal_.X < 0.0f ||
				pArrow->Velocity.Y > 0.0f && Normal_.Y > 0.0f ||
				pArrow->Velocity.Y < 0.0f && Normal_.Y < 0.0f)
			{
				if (pCollider_->Number == CEngineGlobal::c_BalloonNumber)
				{
					if (_HitBalloon(Tick_, Normal_))
						_Die(Tick_);
				}
				else if (pCollider_->Number == CEngineGlobal::c_BodyNumber || pCollider_->Number == CEngineGlobal::c_ParachuteNumber)
				{
					Die(Tick_);
				}

				_fHitArrow(pArrow, false);

				return true;
			}
		}
	}
	else if (pOtherCollider_->Number == CEngineGlobal::c_ItemNumber)
	{
		_fGetItem(Tick_, dynamic_pointer_cast<CArrowDodgeItem>(pOtherCollider_));
		return true;
	}

	return false;
}
void CArrowDodgeBattlePlayer::SetItem(const SArrowDodgeItemMeta& Meta_)
{
	BattleInfo.Point += Meta_.AddedPoint;
	BattleInfo.Gold += Meta_.AddedGold;
}
void CArrowDodgeBattlePlayer::SetShieldItem(int64 Tick_, const CArrowDodgeShield* pShield_)
{
	int64 Duration = g_MetaData->ArrowDodgeMeta.ItemDurationTick;
	Bufs.Shield.Enabled = true;
	Bufs.Shield.EndTick = Tick_ + Duration;
}
void CArrowDodgeBattlePlayer::SetStaminaItem(int64 Tick_, const CArrowDodgeStamina* pStamina_)
{
	int64 Duration = g_MetaData->ArrowDodgeMeta.ItemDurationTick;
	pCharacter->StaminaInfo.Stamina = pMeta->StaminaMax;
	Bufs.Stamina.Enabled = true;
	Bufs.Stamina.EndTick = Tick_ + Duration;
}
