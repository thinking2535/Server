#pragma once

class CArrow : public CMovingObject2D
{
public:
    CList<SArrowObject>::iterator Iterator;

    CArrow(const SPoint& LocalPosition_, const SPoint& Velocity_);
    bool FixedUpdate(); // true : ȭ�� ������ �������� �ϴ� ȭ��
};