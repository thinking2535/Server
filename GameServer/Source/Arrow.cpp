#include "stdafx.h"

CArrow::CArrow(const SPoint& LocalPosition_, const list<shared_ptr<CCollider2D>>& Colliders_, const SPoint& Velocity_) :
    CMovingObject2D(GetDefaultTransform(LocalPosition_), Colliders_, Velocity_)
{
    isKinematic = true;
}
bool CArrow::FixedUpdate() // true : 화면 내에서 보여져야 하는 화살
{
    LocalPosition += (Velocity * CEngine::GetDeltaTime());

    return (LocalPosition.X > -arrowDodgeArrowActiveAreaHalfWidth &&
        LocalPosition.X < arrowDodgeArrowActiveAreaHalfWidth &&
        LocalPosition.Y > arrowDodgeArrowActiveBottom &&
        LocalPosition.Y < arrowDodgeArrowActiveTop);
}
