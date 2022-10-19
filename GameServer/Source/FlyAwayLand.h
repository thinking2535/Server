#pragma once

#include "EngineGlobal.h"

class CFlyAwayLand : public CFlyAwayObject
{
    int32 _LandNumber;
public:
    inline int32 GetLandNumber(void) const { return _LandNumber; }
private:
    int32 _Index;
public:
    CList<SFlyAwayLandObject>::iterator Iterator;
    EFlyAwayLandState State = EFlyAwayLandState::Normal;
    int64 NextActionTick = 0;
private:
    float _YVelocity = 0.0f;
public:
    CFlyAwayLand(const SPoint& LocalPosition_, int32 LandNumber_, int32 Index_);
    void Proc(const shared_ptr<CFlyAwayBattlePlayer>& pPlayer_, CFlyAwayBattle* pBattle_) const override;
    inline SFlyAwayLand GetSFlyAwayLand(void) const
    {
        return SFlyAwayLand(LocalPosition, _LandNumber, _Index, State, NextActionTick);
    }
    bool StartShake(int64 tick);
    void FixedUpdate(int64 tick);
};
