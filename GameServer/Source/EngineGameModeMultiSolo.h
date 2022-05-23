#pragma once

class CEngineGameModeMultiSolo : public CEngineGameModeMulti
{
public:
    CEngineGameModeMultiSolo(const SBattleType& BattleType_);
    EGameMode GetGameMode(void) const override { return EGameMode::Solo; }
    void FixPos(SPoint& Pos_) const override;
    void BattleEnd(const STeamEndInfo& TeamEndInfo_, FQuestDone fQuestDone_) const override;
    void BattleEnd(SUserDB& UserDB_, bool Win_) const override;
    const vector<SMultiMap>& GetMap(const SMapMeta& Map_) const override;
    inline seconds GetPlaySeconds(void) const override { return seconds(g_GameData->ConfigMeta.BattleOneOnOneDurationSec); }
};
