#include "stdafx.h"

CEngineGameModeMultiTeam::CEngineGameModeMultiTeam(const SBattleType& BattleType_) :
    CEngineGameModeMulti(BattleType_)
{
}
void CEngineGameModeMultiTeam::BattleEnd(const STeamEndInfo& TeamEndInfo_, FQuestDone fQuestDone_) const
{
	fQuestDone_(EQuestType::TeamPlay, 1);

	if (TeamEndInfo_.IsWin(TeamCount))
		fQuestDone_(EQuestType::TeamVictory, 1);
}
void CEngineGameModeMultiTeam::BattleEnd(SUserDB& UserDB_, bool Win_) const
{
	if (Win_)
		++UserDB_.WinCountMulti;
	else
		++UserDB_.LoseCountMulti;
}
