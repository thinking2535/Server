#include "stdafx.h"

CFlyAwayBattlePlayer::CFlyAwayBattlePlayer(
	const SBattlePlayer Super_,
	const SPoint& InitialPos_,
	const SCharacterMeta* const pMeta_,
	const shared_ptr<SCharacter>& pCharacter_,
	TBattlesIt itBattle_,
	CUser* Player_,
	FGetItem fGetItem_,
	FLand fLand_,
	FDead fDead,
	CFlyAwayBattle* pFlyAwayBattle_) :
	CBattlePlayer(
		Super_,
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
	_fDead(fDead),
	pFlyAwayBattle(pFlyAwayBattle_)
{
	pPlayerObject->fTriggerEnter = std::bind(&CFlyAwayBattlePlayer::_TriggerEnter, this, _1, _2);
}
void CFlyAwayBattlePlayer::Link(void)
{
	pFlyAwayBattle->Link(0);
}
void CFlyAwayBattlePlayer::BattleEnd(int64 tick)
{
	QuestDone(EQuestType::PlayIsland, 1);

	if (BattleInfo.Point > 0)
		QuestDone(EQuestType::IslandScoreGet, BattleInfo.Point);

	switch (pPlayer->GetSelectedChar()->pCharacterTypeMeta->grade)
	{
	case EGrade::Common:
		QuestDone(EQuestType::PlayNormal, 1);
		break;

	case EGrade::Rare:
		QuestDone(EQuestType::PlayRare, 1);
		break;

	case EGrade::Epic:
		QuestDone(EQuestType::PlayEpic, 1);
		break;
	}

	pPlayer->FlyAwayBattleEnd(tick, BattleInfo, _DoneQuests);
}
void CFlyAwayBattlePlayer::_FixedUpdate(int64 tick)
{
	_UpdatePhysics();
}
bool CFlyAwayBattlePlayer::_CollisionEnter(int64 tick, const SCollision2D& Collision_)
{
	if (_LandEnter(Collision_))
		return true;

	if (Collision_.pOtherCollider->Number == CEngineGlobal::c_LandNumber &&
		Collision_.pCollider->Number == CEngineGlobal::c_BodyNumber && Collision_.Normal.Y > 0.0f)
	{
		_AttachGround(Collision_.pOtherCollider);

		auto pLand = dynamic_cast<CFlyAwayLand* const>(Collision_.pOtherCollider);
		if (pLand->StartShake(tick))
			_fLand(pLand);

		return false;
	}
	else if (
		Collision_.pOtherCollider->Number == CEngineGlobal::c_DeadZoneNumber ||
		Collision_.pOtherCollider->Number == CEngineGlobal::c_OceanNumber)
	{
		Collision_.pOtherCollider->SetEnabled(false);
		Die(tick);
		_fDead();
		return true;
	}
	else
	{
		bounce(Collision_);
		return false;
	}
}
bool CFlyAwayBattlePlayer::_CollisionStay(int64 tick, const SCollision2D& Collision_)
{
	return false;
}
bool CFlyAwayBattlePlayer::_CollisionExit(int64 tick, const SCollision2D& Collision_)
{
	if (Collision_.pCollider->Number != CEngineGlobal::c_BodyNumber || (Collision_.pOtherCollider->Number != CEngineGlobal::c_StructureNumber && Collision_.pOtherCollider->Number != CEngineGlobal::c_LandNumber))
		return false;

	_DetachGround(Collision_.pOtherCollider);

	return false;
}
bool CFlyAwayBattlePlayer::_TriggerEnter(int64 tick, const CCollider2D* pCollider_)
{
	if (pCollider_->Number == CEngineGlobal::c_ItemNumber)
	{
		_fGetItem(dynamic_cast<const CFlyAwayItem*>(pCollider_));
		return true;
	}

	return false;
}
void CFlyAwayBattlePlayer::SetItem(const SFlyAwayItemMeta& Meta_)
{
	BattleInfo.Gold += Meta_.AddedGold;
	addStamina(Meta_.AddedStamina);
}
void CFlyAwayBattlePlayer::addStamina(float stamina)
{
	pCharacter->StaminaInfo.Stamina += stamina;

	if (pCharacter->StaminaInfo.Stamina > pMeta->pCharacterTypeMeta->StaminaMax)
		pCharacter->StaminaInfo.Stamina = pMeta->pCharacterTypeMeta->StaminaMax;
}