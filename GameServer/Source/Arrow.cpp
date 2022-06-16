#include "stdafx.h"

CArrow::CArrow(const STransform& Transform_, const SPoint& Velocity_) :
    CMovingObject2D(Transform_, Velocity_)
{
}
bool CArrow::FixedUpdate() // true : 화면 내에서 보여져야 하는 화살
{
    LocalPosition += (Velocity * CEngine::GetDeltaTime());

    return (LocalPosition.X > CArrowDodgeArrowMaker::ArrowDeleteScreenLeft &&
        LocalPosition.X < CArrowDodgeArrowMaker::ArrowDeleteScreenRight&&
        LocalPosition.Y > CArrowDodgeArrowMaker::ArrowDeleteScreenBottom &&
        LocalPosition.Y < CArrowDodgeArrowMaker::ArrowDeleteScreenTop);
}
