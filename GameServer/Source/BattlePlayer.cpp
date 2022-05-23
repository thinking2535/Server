#include "stdafx.h"

CBattlePlayer::CBattlePlayer(const SBattlePlayer Super_, const SCharacterMeta* pMeta_, const SCharacter* pCharacter_, int32 PlayerIndex_, CUser* Player_) :
	SBattlePlayer(Super_),
	_pMeta(pMeta_),
	_pCharacter(pCharacter_),
	_PlayerIndex(PlayerIndex_),
	_Player(Player_),
	_BalloonHitControl(PlayerIndex_)
{
}
bool CBattlePlayer::IsAlive(void) const
{
	return CEngineGlobal::IsAlive(*_pCharacter);
}
void CBattlePlayer::BattleBegin(const SBattleInfo& Info_)
{
	_Player->BattleBegin(Info_);

	if (_Player->IsBot())
		return;

	g_Users.battle_begin(_Player->GetKey().PeerNum);
	g_Net->SessionHold(_Player->GetSession());
}
void CBattlePlayer::_QuestDone(EQuestType QuestType_, int32 Count_)
{
	auto ib = _DoneQuests.emplace(QuestType_, Count_);
	if (!ib.second)
		ib.first->second += Count_;
}
SBattleEndInfo CBattlePlayer::BattleEnd(const CEngineGameMode* pGameMode_, const SBattleEndPlayer& BattleEndPlayer_, const STeamEndInfo& TeamEndInfo_, bool BestPlayer_, TDoneQuestDBs& DoneQuestDBs_, TDoneQuests& DoneQuestNets_)
{
	switch (_pMeta->Grade)
	{
	case EGrade::Normal:
		_QuestDone(EQuestType::PlayNormal, 1);
		break;

	case EGrade::Rare:
		_QuestDone(EQuestType::PlayRare, 1);
		break;

	case EGrade::Epic:
		_QuestDone(EQuestType::PlayEpic, 1);
		break;
	}

	pGameMode_->BattleEnd(TeamEndInfo_, std::bind(&CBattlePlayer::_QuestDone, this, _1, _2));

	if (BestPlayer_)
		_QuestDone(EQuestType::IngameBestPlayer, 1);

	if (BattleEndPlayer_.AddedPoint > 0)
		_QuestDone(EQuestType::RankPointGet, BattleEndPlayer_.AddedPoint);

	_Player->QuestDone(_DoneQuests, DoneQuestDBs_, DoneQuestNets_);
	auto BattleEndInfo = _Player->BattleEnd(pGameMode_, BattleEndPlayer_, TeamEndInfo_.IsWin(pGameMode_->TeamCount));
	auto itSession = _Player->GetSession();
	g_Users.battle_end(itSession->first);
	g_Net->SessionUnHold(itSession); // SessionUnHold 하면 itSession 이 삭제되므로 마지막에 호출
	return std::move(BattleEndInfo);
}
void CBattlePlayer::Kill(int32 AddedPoint_)
{
	Point += AddedPoint_;

	++_Player->GetUserDB().KillTotal;

	if (_pCharacter->ChainKillCount > 1)
		++_Player->GetUserDB().ChainKillTotal;

	_QuestDone(EQuestType::IngameKill, 1);

	if (_pCharacter->ChainKillCount > 1)
		_QuestDone(EQuestType::IngameConsecutiveKill, 1);
}
void CBattlePlayer::AttackBalloon(int32 AddedPoint_)
{
	Point += AddedPoint_;
	_QuestDone(EQuestType::IngameBalloonPopping, 1);
}
void CBattlePlayer::PumpDone(void)
{
	++_Player->GetUserDB().BlowBalloonTotal;

	_QuestDone(EQuestType::BlowBalloon, 1);
}
void CBattlePlayer::SendSBattleEndNetSc(const list<SBattleEndPlayer>& BattleEndPlayers_, const TTeamBattleInfos& TeamBattleInfos_, const TDoneQuests& DoneQuests_)
{
	Send(SBattleEndNetSc(BattleEndPlayers_, TeamBattleInfos_, DoneQuests_));
}
