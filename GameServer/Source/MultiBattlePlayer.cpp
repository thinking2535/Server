#include "stdafx.h"

CMultiBattlePlayer::CMultiBattlePlayer(
	const SBattlePlayer Super_,
	FHit fHit_,
	FRegen fRegen_,
	FIcon fIcon_,
	const int32 PlayerIndex_,
	const SPoint& InitialPos_,
	const SCharacterMeta* const pMeta_,
	const int8 TeamIndex_,
	const shared_ptr<SCharacter>& pCharacter_,
	TBattlesIt itBattle_,
	CUser* Player_) :
	CBattlePlayer(
		Super_,
		fRegen_,
		PlayerIndex_,
		InitialPos_,
		pMeta_,
		TeamIndex_,
		pCharacter_,
		itBattle_,
		Player_,
		this),
	_fHit(fHit_),
	_fIcon(fIcon_)
{
}
void CMultiBattlePlayer::Icon(const SMultiBattleIconNetCs& Proto_)
{
	_fIcon(PlayerIndex, Proto_);
}
SBattleEndInfo CMultiBattlePlayer::BattleEnd(const vector<SBattleEndPlayer>& BattleEndPlayers_, const vector<STeamEndInfo>& TeamEndInfos_, bool BestPlayer_, TDoneQuestDBs& DoneQuestDBs_)
{
	switch (pMeta->Grade)
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

	if (BestPlayer_)
		QuestDone(EQuestType::IngameBestPlayer, 1);

	auto& BattleEndPlayer = BattleEndPlayers_[PlayerIndex];
	if (BattleEndPlayer.AddedPoint > 0)
		QuestDone(EQuestType::RankPointGet, BattleEndPlayer.AddedPoint);

	auto BattleEndInfo = pPlayer->MultiBattleEnd(BattleEndPlayers_, _DoneQuests, DoneQuestDBs_);
	CBattlePlayer::BattleEnd();
	return std::move(BattleEndInfo);
}
void CMultiBattlePlayer::Kill(int32 AddedPoint_)
{
	BattleInfo.Point += AddedPoint_;

	++pPlayer->GetUserDB().KillTotal;

	if (pCharacter->ChainKillCount > 1)
		++pPlayer->GetUserDB().ChainKillTotal;

	QuestDone(EQuestType::IngameKill, 1);

	if (pCharacter->ChainKillCount > 1)
		QuestDone(EQuestType::IngameConsecutiveKill, 1);
}
void CMultiBattlePlayer::AttackBalloon(int32 AddedPoint_)
{
	BattleInfo.Point += AddedPoint_;
	QuestDone(EQuestType::IngameBalloonPopping, 1);
}
bool CMultiBattlePlayer::_CheckCollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_)
{
	if (__super::_CheckCollisionEnter(Tick_, Normal_, pCollider_, pOtherCollider_, pOtherMovingObject_))
		return true;

	auto pOtherBattlePlayerObject = dynamic_pointer_cast<CBattlePlayerObject>(pOtherMovingObject_);
	if (!pOtherBattlePlayerObject)
		return false;

	auto pOtherBattlePlayer = pOtherBattlePlayerObject->pBattlePlayer;

	if (TeamIndex != pOtherBattlePlayer->TeamIndex && // 다른편이고
		pOtherCollider_->Number == CEngineGlobal::c_BodyNumber && // 적의 몸과 부딪혔고
		!IsInvulerable(Tick_) && // 내가 무적이 아니고
		!pOtherBattlePlayer->IsInvulerable(Tick_) && // 적이 무적이 아니고
		pOtherBattlePlayer->pCharacter->BalloonCount > 0 && // 적이 풍선이 있고
		(pCollider_->Number == CEngineGlobal::c_BalloonNumber || pCharacter->BalloonCount == 0)) // 내 풍선과 부딪혔거나, 내 풍선이 없으면
	{
		if (_HitBalloon(Tick_, Normal_)) // Dead
		{
			if ((Tick_ - pOtherBattlePlayer->pCharacter->LastKillTick) < c_ChainKillDelayTickCount)
				++pOtherBattlePlayer->pCharacter->ChainKillCount;
			else
				pOtherBattlePlayer->pCharacter->ChainKillCount = 1;

			pOtherBattlePlayer->pCharacter->LastKillTick = Tick_;
			_Die(Tick_);
		}

		_fHit(pOtherBattlePlayer->PlayerIndex, PlayerIndex);

		pOtherBattlePlayer->Bounce(Normal_ * -1.0f);
		return true;
	}

	return false;
}
