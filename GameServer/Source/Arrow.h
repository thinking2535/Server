#pragma once

class CArrow : public CMovingObject2D
{
public:
    CList<SArrowObject>::iterator Iterator;

    CArrow(const STransform& Transform_, const SPoint& Velocity_);
    bool FixedUpdate(); // true : 화면 내에서 보여져야 하는 화살
};