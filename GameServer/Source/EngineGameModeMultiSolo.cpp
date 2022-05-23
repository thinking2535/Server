#include "stdafx.h"

CEngineGameModeMultiSolo::CEngineGameModeMultiSolo(const SBattleType& BattleType_) :
    CEngineGameModeMulti(BattleType_)
{
}
void CEngineGameModeMultiSolo::FixPos(SPoint& Pos_) const
{
}
void CEngineGameModeMultiSolo::BattleEnd(const STeamEndInfo& TeamEndInfo_, FQuestDone fQuestDone_) const
{
    fQuestDone_(EQuestType::SoloPlay, 1);

    if (TeamEndInfo_.IsWin(TeamCount))
        fQuestDone_(EQuestType::SoloVictory, 1);
}
void CEngineGameModeMultiSolo::BattleEnd(SUserDB& UserDB_, bool Win_) const
{
    if (Win_)
        ++UserDB_.WinCountSolo;
    else
        ++UserDB_.LoseCountSolo;
}
const vector<SMultiMap>& CEngineGameModeMultiSolo::GetMap(const SMapMeta& Map_) const
{
    return Map_.OneOnOneMaps;
}
