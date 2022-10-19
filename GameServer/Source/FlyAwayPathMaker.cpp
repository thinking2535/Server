#include "stdafx.h"

FlyAwayPathMaker::FlyAwayPathMaker(float minY, float maxY, int32 mainLevelCount, int32 subLevelCount, CFixedRandom32& fixedRandom) :
    FlyAwayPathMaker(
        minY,
        maxY,
        mainLevelCount,
        subLevelCount,
        fixedRandom,
        FlyAwayPathMakerState(
            (mainLevelCount / 2)* subLevelCount,
            (((int32)fixedRandom.Get()) % 3) - 1,
            mainLevelCount / 2,
            0,
            0))
{
}
FlyAwayPathMaker::FlyAwayPathMaker(float minY, float maxY, int32 mainLevelCount, int32 subLevelCount, CFixedRandom32& fixedRandom, const FlyAwayPathMakerState& state) :
    _minY(minY),
    _maxY(maxY),
    _mainLevelCount(mainLevelCount),
    _subLevelCount(subLevelCount),
    _verticalStep((_maxY - _minY) / (mainLevelCount * subLevelCount)),
    _fixedRandom(fixedRandom),
    _state(state)
{
    ASSERTION(mainLevelCount > 2);
    ASSERTION(subLevelCount > 0);
}
float FlyAwayPathMaker::getNextY()
{
    if (_state.currentCount == _state.destCount)
    {
        _state.currentCount = 0;

        // 경로를 진행시킬 방향(newLevelDirection) 결정
        int32 newLevelDirection;
        if (_state.levelDirection == 0 && _state.destMainLevel == 0)
        {
            newLevelDirection = 1;
        }
        else if (_state.levelDirection == 0 && _state.destMainLevel == _mainLevelCount - 1)
        {
            newLevelDirection = -1;
        }
        else
        {
            newLevelDirection = (((int32)_fixedRandom.Get()) % 2) - 1;
            if (newLevelDirection >= _state.levelDirection) ++newLevelDirection; // _lastDirection 를 피하여 랜덤값 설정
        }

        // 결정된 방향으로 반복할 회수(_destCount) 결정
        if (newLevelDirection == 0) // mid
        {
            // 전체 level 개수 이내의 랜덤값 만큼 반복
            _state.destCount = ((((int32)_fixedRandom.Get()) % _mainLevelCount) + 1) * _subLevelCount;
        }
        else
        {
            if (newLevelDirection == -1) // down
            {
                // 직전 _destMainLevel 아래 영역(_destMainLevel 의 크기)에서 결정된 changedMainLevel 에 _subLevelCount 를 곱한 값 만큼 반복
                auto changedMainLevel = (((int32)_fixedRandom.Get()) % _state.destMainLevel) + 1;
                _state.destCount = changedMainLevel * _subLevelCount;
                _state.destMainLevel -= changedMainLevel;
            }
            else // up
            {
                // 직전 _destMainLevel 위 영역(_mainLevelCount - _destMainLevel)에서 결정된 changedMainLevel 에 _subLevelCount 를 곱한 값 만큼 반복
                auto changedMainLevel = (((int32)_fixedRandom.Get()) % ((_mainLevelCount - 1) - _state.destMainLevel)) + 1;
                _state.destCount = changedMainLevel * _subLevelCount;
                _state.destMainLevel += changedMainLevel;
            }
        }

        _state.levelDirection = newLevelDirection;
    }

    ++_state.currentCount;
    _state.currentLevel += _state.levelDirection;

    return getCurrentY();
}
float FlyAwayPathMaker::getCurrentY()
{
    return _minY + _verticalStep * _state.currentLevel;
}