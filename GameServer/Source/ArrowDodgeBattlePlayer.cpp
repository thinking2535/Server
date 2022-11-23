#include "stdafx.h"

CArrowDodgeBattlePlayer::CArrowDodgeBattlePlayer(
	const SBattlePlayer Super_,
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
	pPlayerObject->fTriggerEnter = std::bind(&CArrowDodgeBattlePlayer::_TriggerEnter, this, _1, _2);
}
void CArrowDodgeBattlePlayer::Link(void)
{
	pArrowDodgeBattle->Link(0);
}
void CArrowDodgeBattlePlayer::BattleEnd(int64 tick)
{
	QuestDone(EQuestType::PlaySingle, 1);

	if (BattleInfo.Point > 0)
		QuestDone(EQuestType::SinglePlayScoreGet, BattleInfo.Point);

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

	pPlayer->ArrowDodgeBattleEnd(tick, BattleInfo, _DoneQuests);
}
bool CArrowDodgeBattlePlayer::IsStaminaFree(void) const
{
	return Bufs.Stamina.Enabled;
}
void CArrowDodgeBattlePlayer::_FixedUpdate(int64 tick)
{
	CBattlePlayer::_FixedUpdate(tick);

	if (Bufs.Shield.Enabled && Bufs.Shield.EndTick < tick)
		Bufs.Shield.Enabled = false;

	if (Bufs.Stamina.Enabled && Bufs.Stamina.EndTick < tick)
		Bufs.Stamina.Enabled = false;
}
bool CArrowDodgeBattlePlayer::_CollisionEnter(int64 tick, const SCollision2D& collision)
{
	if (_LandEnter(collision))
		return false;

	bool isHitArrow = false;

	// 원래 속도 복원
	if (collision.Normal.X != 0.0f)
		pPlayerObject->Velocity.X -= collision.RelativeVelocity.X;
	else
		pPlayerObject->Velocity.Y -= collision.RelativeVelocity.Y;

	if (collision.pOtherCollider->Number == CEngineGlobal::c_ArrowNumber &&
		collision.pOtherMovingObject != nullptr)
	{
		auto pArrow = dynamic_cast<const CArrow*>(collision.pOtherMovingObject);

		if (Bufs.Shield.Enabled)
		{
			_fHitArrow(pArrow, true);
			return true;
		}

		if (pArrow->Velocity.X * collision.Normal.X > 0.0f ||
			pArrow->Velocity.Y * collision.Normal.Y > 0.0f)
		{
			isHitArrow = true;

			if (collision.pCollider->Number == CEngineGlobal::c_BalloonNumber)
			{
				if (_beHitBalloon(collision.Normal))
					_Die(tick);
			}
			else if (collision.pCollider->Number == CEngineGlobal::c_BodyNumber || collision.pCollider->Number == CEngineGlobal::c_ParachuteNumber)
			{
				Die(tick);
			}

			_fHitArrow(pArrow, false);
		}
	}
	else
	{
		bounce(collision.Normal);
	}

	return isHitArrow;
}
bool CArrowDodgeBattlePlayer::_TriggerEnter(int64 tick, const CCollider2D* pCollider)
{
	if (pCollider->Number == CEngineGlobal::c_ItemNumber)
	{
		_fGetItem(dynamic_cast<const CArrowDodgeItem*>(pCollider));
		return true;
	}

	return false;
}
void CArrowDodgeBattlePlayer::SetItem(const SArrowDodgeItemMeta& Meta_)
{
	BattleInfo.Gold += Meta_.AddedGold;
}
void CArrowDodgeBattlePlayer::SetShieldItem(int64 tick, const CArrowDodgeShield* pShield_)
{
	int64 Duration = g_MetaData->arrowDodgeConfigMeta.ItemDurationTick;
	Bufs.Shield.Enabled = true;
	Bufs.Shield.EndTick = tick + Duration;
}
void CArrowDodgeBattlePlayer::SetStaminaItem(int64 tick, const CArrowDodgeStamina* pStamina_)
{
	int64 Duration = g_MetaData->arrowDodgeConfigMeta.ItemDurationTick;
	pCharacter->StaminaInfo.Stamina = pMeta->pCharacterTypeMeta->StaminaMax;
	Bufs.Stamina.Enabled = true;
	Bufs.Stamina.EndTick = tick + Duration;
}
