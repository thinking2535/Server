#pragma once

class CArrow : public CMovingObject2D
{
public:
    CList<SArrowObject>::iterator Iterator;

    CArrow(const SPoint& LocalPosition_, const list<shared_ptr<CCollider2D>>& Colliders_, const SPoint& Velocity_);
    bool FixedUpdate(); // true : 화면 내에서 보여져야 하는 화살
};