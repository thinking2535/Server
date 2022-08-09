#include "stdafx.h"

CFlyAwayBattlePlayer::CFlyAwayBattlePlayer(
	const SBattlePlayer Super_,
	FRegen fRegen_,
	const SPoint& InitialPos_,
	const SCharacterMeta* const pMeta_,
	const shared_ptr<SCharacter>& pCharacter_,
	TBattlesIt itBattle_,
	CUser* Player_,
	FGetItem fGetItem_,
	FLand fLand_,
	CFlyAwayBattle* pFlyAwayBattle_) :
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
	_fGetItem(fGetItem_),
	_fLand(fLand_),
	pFlyAwayBattle(pFlyAwayBattle_)
{
}
void CFlyAwayBattlePlayer::BattleEnd(int64 Tick_)
{
	QuestDone(EQuestType::PlaySingle, 1);

	if (BattleInfo.PassedCount > 0)
		QuestDone(EQuestType::IslandCount, BattleInfo.PassedCount);

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

	pPlayer->FlyAwayBattleEnd(Tick_, BattleInfo, _DoneQuests);
}
void CFlyAwayBattlePlayer::_FixedUpdate(int64 Tick_)
{
	_UpdatePhysics(Tick_);
}
bool CFlyAwayBattlePlayer::_CheckCollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (__super::_CheckCollisionEnter(Tick_, Normal_, pCollider_, pOtherCollider_, pOtherMovingObject_))
		return true;

	if (pOtherCollider_->Number == CEngineGlobal::c_LandNumber &&
		pCollider_->Number == CEngineGlobal::c_BodyNumber && Normal_.Y > 0.0f)
	{
		_SetLandingVelocity(pOtherMovingObject_);
		_AttachGround(pOtherCollider_);

		auto pLand = dynamic_pointer_cast<CFlyAwayLand>(pOtherCollider_);
		if (pLand->StartShake(Tick_))
			_fLand(Tick_, pLand);

		return true;
	}
	else if (pOtherCollider_->Number == CEngineGlobal::c_ItemNumber)
	{
		_fGetItem(Tick_, dynamic_pointer_cast<CFlyAwayItem>(pOtherCollider_));
		return true;
	}
	else
	{
		return false;
	}
}
bool CFlyAwayBattlePlayer::_CheckCollisionStay(const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (__super::_CheckCollisionStay(Normal_, pCollider_, pOtherCollider_, pOtherMovingObject_))
		return true;

	if (pCollider_->Number != CEngineGlobal::c_BodyNumber || pOtherCollider_->Number != CEngineGlobal::c_LandNumber) // ¸öÀÌ ¼¶¿¡ ¾È ´ê¾ÒÀ¸¸é
		return false;

	if (Normal_.Y > 0.0f)
	{
		_SetLandingVelocity(pOtherMovingObject_);
		_AttachGround(pOtherCollider_);
	}
	else
	{
		_DetachGround(pOtherCollider_);
	}

	return true;
}
bool CFlyAwayBattlePlayer::_CheckCollisionExit(const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (__super::_CheckCollisionExit(pCollider_, pOtherCollider_, pOtherMovingObject_))
		return true;

	if (pCollider_->Number != CEngineGlobal::c_BodyNumber || pOtherCollider_->Number != CEngineGlobal::c_LandNumber)
		return false;

	_DetachGround(pOtherCollider_);

	return true;
}
void CFlyAwayBattlePlayer::SetItem(const SFlyAwayItemMeta& Meta_)
{
	BattleInfo.Point += Meta_.AddedPoint;
	BattleInfo.Gold += Meta_.AddedGold;

	pCharacter->StaminaInfo.Stamina += Meta_.AddedStamina;
	if (pCharacter->StaminaInfo.Stamina > pMeta->StaminaMax)
		pCharacter->StaminaInfo.Stamina = pMeta->StaminaMax;
}
