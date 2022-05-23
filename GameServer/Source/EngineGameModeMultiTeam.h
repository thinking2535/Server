#pragma once

class CEngineGameModeMultiTeam : public CEngineGameModeMulti
{
public:
    CEngineGameModeMultiTeam(const SBattleType& BattleType_);
    EGameMode GetGameMode(void) const override { return EGameMode::Team; }
    void BattleEnd(const STeamEndInfo& TeamEndInfo_, FQuestDone fQuestDone_) const override;
    void BattleEnd(SUserDB& UserDB_, bool Win_) const override;
};

