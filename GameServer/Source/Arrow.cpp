#include "stdafx.h"

CArrow::CArrow(const SPoint& LocalPosition_, const list<shared_ptr<CCollider2D>>& Colliders_, const SPoint& Velocity_) :
    CMovingObject2D(GetDefaultTransform(LocalPosition_), Colliders_, Velocity_)
{
    isKinematic = true;
}
bool CArrow::FixedUpdate() // true : ȭ�� ������ �������� �ϴ� ȭ��
{
    LocalPosition += (Velocity * CEngine::GetDeltaTime());

    return (LocalPosition.X > -arrowDodgeArrowActiveAreaHalfWidth &&
        LocalPosition.X < arrowDodgeArrowActiveAreaHalfWidth &&
        LocalPosition.Y > arrowDodgeArrowActiveBottom &&
        LocalPosition.Y < arrowDodgeArrowActiveTop);
}
