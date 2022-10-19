#include "stdafx.h"

CFlyAwayLand::CFlyAwayLand(const SPoint& LocalPosition_, int32 LandNumber_, int32 Index_) :
    CFlyAwayObject(GetDefaultTransform(LocalPosition_), CEngineGlobal::c_LandNumber, g_MetaData->MapMeta.FlyAwayMapInfo.Lands[Index_].Collider),
    _LandNumber(LandNumber_),
    _Index(Index_)
{
}
void CFlyAwayLand::Proc(const shared_ptr<CFlyAwayBattlePlayer>& pPlayer_, CFlyAwayBattle* pBattle_) const
{
}
bool CFlyAwayLand::StartShake(int64 tick)
{
    if (State != EFlyAwayLandState::Normal)
        return false;

    State = EFlyAwayLandState::Shaking;
    NextActionTick = tick + 15000000;

    return true;
}
void CFlyAwayLand::FixedUpdate(int64 tick)
{
    if (State == EFlyAwayLandState::Normal)
        return;

    switch (State)
    {
    case EFlyAwayLandState::Shaking:
    {
        if (tick >= NextActionTick)
        {
            SetEnabled(false);
            State = EFlyAwayLandState::Falling;
            NextActionTick = tick + 20000000;
        }
    }
    break;

    case EFlyAwayLandState::Falling:
    {
        if (tick < NextActionTick)
        {
            _YVelocity += c_Gravity * CEngine::GetDeltaTime();
            LocalPosition.Y += (CEngine::GetDeltaTime() * (0.5f * c_Gravity * CEngine::GetDeltaTime() + _YVelocity));
        }
    }
    break;

    default:
        break;
    }
}
