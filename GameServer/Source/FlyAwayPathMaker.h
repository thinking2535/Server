#pragma once

class FlyAwayPathMaker
{
    const float _minY;
    const float _maxY;
    const int32 _mainLevelCount;
    const int32 _subLevelCount;
    const float _verticalStep;

    CFixedRandom32& _fixedRandom;
    FlyAwayPathMakerState _state; // currentCount 상,하 방향과 와 횡방향의 로직 통일을 위해 이 변수를 두어 상,하 방향에도 _destCount 까지 반복하여 목표 도달을 체크

public:
    FlyAwayPathMaker(float minY, float maxY, int32 mainLevelCount, int32 subLevelCount, CFixedRandom32& fixedRandom);
    FlyAwayPathMaker(float minY, float maxY, int32 mainLevelCount, int32 subLevelCount, CFixedRandom32& fixedRandom, const FlyAwayPathMakerState& state);
    float getNextY();
    float getCurrentY();
    inline FlyAwayPathMakerState getState() const { return _state; }
    inline float getVerticalStep() const { return _verticalStep; }
};