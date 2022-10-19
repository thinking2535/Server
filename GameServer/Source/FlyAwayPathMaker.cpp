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

        // ��θ� �����ų ����(newLevelDirection) ����
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
            if (newLevelDirection >= _state.levelDirection) ++newLevelDirection; // _lastDirection �� ���Ͽ� ������ ����
        }

        // ������ �������� �ݺ��� ȸ��(_destCount) ����
        if (newLevelDirection == 0) // mid
        {
            // ��ü level ���� �̳��� ������ ��ŭ �ݺ�
            _state.destCount = ((((int32)_fixedRandom.Get()) % _mainLevelCount) + 1) * _subLevelCount;
        }
        else
        {
            if (newLevelDirection == -1) // down
            {
                // ���� _destMainLevel �Ʒ� ����(_destMainLevel �� ũ��)���� ������ changedMainLevel �� _subLevelCount �� ���� �� ��ŭ �ݺ�
                auto changedMainLevel = (((int32)_fixedRandom.Get()) % _state.destMainLevel) + 1;
                _state.destCount = changedMainLevel * _subLevelCount;
                _state.destMainLevel -= changedMainLevel;
            }
            else // up
            {
                // ���� _destMainLevel �� ����(_mainLevelCount - _destMainLevel)���� ������ changedMainLevel �� _subLevelCount �� ���� �� ��ŭ �ݺ�
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