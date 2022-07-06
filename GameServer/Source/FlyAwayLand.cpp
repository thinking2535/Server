#include "stdafx.h"

bool CFlyAwayLand::StartShake(int64 Tick_)
{
    if (State != EFlyAwayLandState::Normal)
        return false;

    State = EFlyAwayLandState::Shaking;
    NextActionTick = Tick_ + 15000000;

    return true;
}
void CFlyAwayLand::FixedUpdate(Int64 Tick_)
{
    if (State == EFlyAwayLandState::Normal)
        return;

    switch (State)
    {
    case EFlyAwayLandState::Shaking:
    {
        if (Tick_ >= NextActionTick)
        {
            State = EFlyAwayLandState::Falling;
            NextActionTick = Tick_ + 20000000;
        }
    }
    break;

    case EFlyAwayLandState::Falling:
    {
        if (Tick_ < NextActionTick)
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
