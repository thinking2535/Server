#pragma once

#include <Rso/GameUtil/FixedRandom64.h>

using namespace std;
using namespace rso;
using namespace gameutil;

class CArrowDodgeArrowMaker
{
    static const float _PositionPrecision;
    static const float _PositionMultiplier;
    static const uint32 _IntScreenWidth;
    static const uint32 _IntScreenHeight;
    static const float _MinDownVelocity;
    static const float _MinHorizontalVelocity;
    static const uint32 _VelocityRange;
    static const float _VelocityMultiplier;

    static const float _ArrowCreateAreaHalfWidth;
    static const float _ArrowCreateAreaHalfHeight;
    static const float _ArrowCreateScreenLeft;
    static const float _ArrowCreateScreenRight;
    static const float _ArrowCreateScreenBottom;
    static const float _ArrowCreateScreenTop;

    static const float _ArrowActiveAreaHalfWidth;
    static const float _ArrowActiveAreaHalfHeight;
public:
    static const float ArrowDeleteScreenLeft;
    static const float ArrowDeleteScreenRight;
    static const float ArrowDeleteScreenBottom;
    static const float ArrowDeleteScreenTop;
private:
    static const int64 _FirstLeftArrowTick;
    static const int64 _FirstRightArrowTick;
    static const int64 _MaxArrowTick;

    static SRectCollider2D _GetArrowCollider2D(const SPoint& Velocity_);

    CFixedRandom32& _FixedRandom;
    int64 _NextDownArrowTick = 0;
    int64 _NextLeftArrowTick = _FirstLeftArrowTick;
    int64 _NextRightArrowTick = _FirstRightArrowTick;
public:
    int64 GetNextDownArrowTick(void) const { return _NextDownArrowTick; }
    int64 GetNextLeftArrowTick(void) const { return _NextLeftArrowTick; }
    int64 GetNextRightArrowTick(void) const { return _NextRightArrowTick; }
    CArrowDodgeArrowMaker(CFixedRandom32& FixedRandom_);
    void FixedUpdate(int64 Tick_, function<void(const shared_ptr<CArrow>& pArrow_)> fAddArrow_);
    static shared_ptr<CArrow> MakeArrow(const SPoint& LocalPosition_, const SPoint& Velocity_);
    inline uint32 GetRandomSeed(void) const
    {
        return _FixedRandom.GetSeed();
    }
    static inline int64 _GetDownArrowDuration(Int64 Tick_)
    {
        return Tick_ > _FirstLeftArrowTick ? 5000000 : -Tick_ / 20 + 20000000;
    }
    static inline int64 _GetLeftArrowDuration(Int64 Tick_)
    {
        return Tick_ > _FirstRightArrowTick ? 10000000 : -(Tick_ - _FirstLeftArrowTick) / 30 + 20000000;
    }
    static inline int64 _GetRightArrowDuration(Int64 Tick_)
    {
        return Tick_ > _MaxArrowTick ? 10000000 : -(Tick_ - _FirstRightArrowTick) / 30 + 20000000;
    }
};