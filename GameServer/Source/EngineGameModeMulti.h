#pragma once

class CEngineGameModeMulti abstract : public CEngineGameMode
{
public:
    CEngineGameModeMulti(const SBattleType& BattleType_);
    void FixPos(SPoint& Pos_) const override;
    const vector<SMultiMap>& GetMap(const SMapMeta& Map_) const override;
    inline seconds GetPlaySeconds(void) const override { return seconds(g_GameData->ConfigMeta.BattleDurationSec); }
};
