#include "stdafx.h"

CSingleBattlePlayer::CSingleBattlePlayer(const SBattlePlayer Super_, const SCharacterMeta* pMeta_, int32 PlayerIndex_, CUser* Player_) :
	SBattlePlayer(Super_),
	_pMeta(pMeta_),
	_PlayerIndex(PlayerIndex_),
	_Player(Player_),
	_IsAlive(true)
{
}
bool CSingleBattlePlayer::IsAlive(void) const
{
	return _IsAlive;
}
void CSingleBattlePlayer::BattleBegin(const SBattleInfo& Info_, EGameMode GameMode_)
{
	_Player->SingleBattleBegin(Info_);
	_GameMode = GameMode_;

	if (_Player->IsBot())
		return;

	g_Users.battle_begin(_Player->GetKey().PeerNum);
	g_Net->SessionHold(_Player->GetSession());
}
void CSingleBattlePlayer::_QuestDone(EQuestType QuestType_, int32 Count_)
{
	auto ib = _DoneQuests.emplace(QuestType_, Count_);
	if (!ib.second)
		ib.first->second += Count_;
}
SBattleEndInfo CSingleBattlePlayer::BattleEnd(const CEngineGameMode* pGameMode_, const SBattleEndPlayer& BattleEndPlayer_, const STeamEndInfo& TeamEndInfo_, bool BestPlayer_, TDoneQuestDBs& DoneQuestDBs_, TDoneQuests& DoneQuestNets_)
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

	pGameMode_->BattleEnd(TeamEndInfo_, std::bind(&CSingleBattlePlayer::_QuestDone, this, _1, _2));

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
void CSingleBattlePlayer::SendSSingleBattleEndNetSc(const list<SBattleEndPlayer>& BattleEndPlayers_, const TTeamBattleInfos& TeamBattleInfos_, const TDoneQuests& DoneQuests_)
{
	Send(SSingleBattleEndNetSc(SBattleEndNetSc(BattleEndPlayers_, TeamBattleInfos_, DoneQuests_), _GameMode));
}
