#include "stdafx.h"

CMultiBattlePlayer::CMultiBattlePlayer(
	const SBattlePlayer Super_,
	FHit fHit_,
	FIcon fIcon_,
	const int32 PlayerIndex_,
	const SPoint& InitialPos_,
	const SCharacterMeta* const pMeta_,
	const int8 TeamIndex_,
	const shared_ptr<SCharacter>& pCharacter_,
	TBattlesIt itBattle_,
	CMultiBattle* pMultiBattle_,
	CUser* Player_) :
	CBattlePlayer(
		Super_,
		PlayerIndex_,
		InitialPos_,
		pMeta_,
		TeamIndex_,
		pCharacter_,
		itBattle_,
		Player_,
		this),
	_fHit(fHit_),
	_fIcon(fIcon_),
	_pMultiBattle(pMultiBattle_)
{
}
void CMultiBattlePlayer::Link(void)
{
	// LeftMillisecondsToInvalidBattle 가 음수가 되더라도 상관 없음.
	LeftMillisecondsToInvalidBattle = duration_cast<milliseconds>(DisconnectEndTime - system_clock::now());
	_pMultiBattle->Link(PlayerIndex);
}
void CMultiBattlePlayer::UnLink(void)
{
	DisconnectEndTime = system_clock::now() + LeftMillisecondsToInvalidBattle;
	_pMultiBattle->UnLink(PlayerIndex);
}
void CMultiBattlePlayer::Icon(const SMultiBattleIconNetCs& Proto_)
{
	_fIcon(PlayerIndex, Proto_);
}
void CMultiBattlePlayer::_BattleEnd(const SBattleType& BattleType_, bool IsBestPlayer_)
{
	if (IsOneOnOneBattle(BattleType_))
		QuestDone(EQuestType::SoloPlay, 1);

	switch (pMeta->pCharacterTypeMeta->grade)
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
}
void CMultiBattlePlayer::BattleEnd(
	TTime Now_,
	const SBattleType& BattleType_,
	bool IsBestPlayer_,
	const BattleEndInfo& battleEndInfo,
	int32 myTeamRanking,
	TDoneQuestDBs& DoneQuestDBs_)
{
	_BattleEnd(BattleType_, IsBestPlayer_);

	if (IsOneOnOneBattle(BattleType_))
	{
		if (myTeamRanking == 0)
		{
			QuestDone(EQuestType::SoloVictory, 1);
			++pPlayer->GetUserDB().WinCountSolo;
		}
		else
		{
			++pPlayer->GetUserDB().LoseCountSolo;
		}
	}
	else
	{
		if (myTeamRanking == 0)
			++pPlayer->GetUserDB().WinCountMulti;
		else
			++pPlayer->GetUserDB().LoseCountMulti;
	}

	pPlayer->MultiBattleEnd(Now_, battleEndInfo, myTeamRanking, _DoneQuests, DoneQuestDBs_);
}
void CMultiBattlePlayer::BattleEndDraw(TTime Now_, const SBattleType& BattleType_, bool IsBestPlayer_, TDoneQuestDBs& DoneQuestDBs_)
{
	_BattleEnd(BattleType_, IsBestPlayer_);
	pPlayer->MultiBattleEndDraw(Now_, BattleInfo.Point, _DoneQuests, DoneQuestDBs_);
}
void CMultiBattlePlayer::BattleEndInvalid(TTime Now_)
{
	pPlayer->MultiBattleEndInvalid(Now_);
}
void CMultiBattlePlayer::BattleEndInvalidPunish(void)
{
	pPlayer->MultiBattleEndInvalidPunish();
}
void CMultiBattlePlayer::Kill(int32 AddedPoint_)
{
	BattleInfo.Point += AddedPoint_;

	++pPlayer->GetUserDB().KillTotal;

	if (pCharacter->ChainKillCount > 1)
		++pPlayer->GetUserDB().ChainKillTotal;

	QuestDone(EQuestType::IngameKill, 1);
}
void CMultiBattlePlayer::AttackBalloon(int32 AddedPoint_)
{
	BattleInfo.Point += AddedPoint_;
	QuestDone(EQuestType::IngameBalloonPopping, 1);
}
bool CMultiBattlePlayer::_CollisionEnter(int64 tick, const SCollision2D& Collision_)
{
	if (_LandEnter(Collision_))
		return false;

	auto pOtherBattlePlayerObject = dynamic_cast<const CBattlePlayerObject*>(Collision_.pOtherMovingObject);
	if (pOtherBattlePlayerObject != nullptr)
	{
		auto pOtherBattlePlayer = pOtherBattlePlayerObject->pBattlePlayer;

		if (TeamIndex != pOtherBattlePlayer->TeamIndex && // 다른편이고
			Collision_.pOtherCollider->Number == CEngineGlobal::c_BodyNumber && // 적의 몸과 부딪혔고
			!IsInvulerable(tick) && // 내가 무적이 아니고
			!pOtherBattlePlayer->IsInvulerable(tick) && // 적이 무적이 아니고
			pOtherBattlePlayer->pCharacter->BalloonCount > 0 && // 적이 풍선이 있고
			(Collision_.pCollider->Number == CEngineGlobal::c_BalloonNumber || pCharacter->BalloonCount == 0)) // 내 풍선과 부딪혔거나, 내 풍선이 없으면
		{
			if (_beHitBalloon(Collision_.Normal)) // Dead
			{
				if ((tick - pOtherBattlePlayer->pCharacter->LastKillTick) < c_ChainKillDelayTickCount)
					++pOtherBattlePlayer->pCharacter->ChainKillCount;
				else
					pOtherBattlePlayer->pCharacter->ChainKillCount = 1;

				pOtherBattlePlayer->pCharacter->LastKillTick = tick;
				_Die(tick);
			}

			_fHit(pOtherBattlePlayer->PlayerIndex, PlayerIndex);
		}
	}

	if (IsAlive())
		bounce(Collision_);

	return false;
}
