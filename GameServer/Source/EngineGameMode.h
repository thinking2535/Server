#pragma once

class CEngineGameMode abstract : public SBattleType
{
public:
    CEngineGameMode(const SBattleType& BattleType_) :
        SBattleType(BattleType_)
    {
    }
    int32 GetAllMemberCount(void) const { return MemberCount * TeamCount; }
    virtual EGameMode GetGameMode(void) const = 0;
    virtual void FixPos(SPoint& Pos_) const = 0;
    virtual void BattleEnd(const STeamEndInfo& TeamEndInfo_, FQuestDone fQuestDone_) const = 0;
    virtual void BattleEnd(SUserDB& UserDB_, bool Win_) const = 0;
    virtual const vector<SMultiMap>& GetMap(const SMapMeta& Map_) const = 0;
    virtual seconds GetPlaySeconds(void) const = 0;
};
