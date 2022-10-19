#pragma once

class FlyAwayPathMaker
{
    const float _minY;
    const float _maxY;
    const int32 _mainLevelCount;
    const int32 _subLevelCount;
    const float _verticalStep;

    CFixedRandom32& _fixedRandom;
    FlyAwayPathMakerState _state; // currentCount ��,�� ����� �� Ⱦ������ ���� ������ ���� �� ������ �ξ� ��,�� ���⿡�� _destCount ���� �ݺ��Ͽ� ��ǥ ������ üũ

public:
    FlyAwayPathMaker(float minY, float maxY, int32 mainLevelCount, int32 subLevelCount, CFixedRandom32& fixedRandom);
    FlyAwayPathMaker(float minY, float maxY, int32 mainLevelCount, int32 subLevelCount, CFixedRandom32& fixedRandom, const FlyAwayPathMakerState& state);
    float getNextY();
    float getCurrentY();
    inline FlyAwayPathMakerState getState() const { return _state; }
    inline float getVerticalStep() const { return _verticalStep; }
};