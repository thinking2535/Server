#include "stdafx.h"

CArrow::CArrow(const SPoint& LocalPosition_, const SPoint& Velocity_) :
    CMovingObject2D(GetDefaultTransform(LocalPosition_), Velocity_)
{
}
bool CArrow::FixedUpdate() // true : ȭ�� ������ �������� �ϴ� ȭ��
{
    LocalPosition += (Velocity * CEngine::GetDeltaTime());

    return (LocalPosition.X > CArrowDodgeArrowMaker::ArrowDeleteScreenLeft &&
        LocalPosition.X < CArrowDodgeArrowMaker::ArrowDeleteScreenRight&&
        LocalPosition.Y > CArrowDodgeArrowMaker::ArrowDeleteScreenBottom &&
        LocalPosition.Y < CArrowDodgeArrowMaker::ArrowDeleteScreenTop);
}
