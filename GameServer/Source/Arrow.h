#pragma once

class CArrow : public CMovingObject2D
{
public:
    CList<SArrowObject>::iterator Iterator;

    CArrow(const STransform& Transform_, const SPoint& Velocity_);
    bool FixedUpdate(); // true : ȭ�� ������ �������� �ϴ� ȭ��
};