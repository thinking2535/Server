#pragma once

#include <Rso/GameUtil/FixedRandom64.h>

using namespace std;
using namespace rso;
using namespace gameutil;

class CArrowDodgeArrowMaker
{
    static SRectCollider2D _GetArrowCollider2D(const SPoint& Velocity_);

    CFixedRandom32& _FixedRandom;
    int64 _NextDownArrowTick = 0;
    int64 _NextLeftArrowTick = arrowDodgeFirstLeftArrowTick;
    int64 _NextRightArrowTick = arrowDodgeFirstRightArrowTick;
public:
    int64 GetNextDownArrowTick(void) const { return _NextDownArrowTick; }
    int64 GetNextLeftArrowTick(void) const { return _NextLeftArrowTick; }
    int64 GetNextRightArrowTick(void) const { return _NextRightArrowTick; }
    CArrowDodgeArrowMaker(CFixedRandom32& FixedRandom_);
    void FixedUpdate(int64 tick, CArrowDodgeBattle& battle, function<void(const shared_ptr<CArrow>& pArrow_)> fAddArrow_);
    static shared_ptr<CArrow> MakeArrow(const SPoint& LocalPosition_, const SPoint& Velocity_);
    inline uint32 GetRandomSeed(void) const
    {
        return _FixedRandom.GetSeed();
    }
    static inline int64 _GetDownArrowDuration(Int64 Tick_)
    {
        return Tick_ > arrowDodgeFirstLeftArrowTick ? 5000000 : -Tick_ / 20 + 20000000;
    }
    static inline int64 _GetLeftArrowDuration(Int64 Tick_)
    {
        return Tick_ > arrowDodgeFirstRightArrowTick ? 10000000 : -(Tick_ - arrowDodgeFirstLeftArrowTick) / 30 + 20000000;
    }
    static inline int64 _GetRightArrowDuration(Int64 Tick_)
    {
        return Tick_ > arrowDodgeMaxArrowTick ? 10000000 : -(Tick_ - arrowDodgeFirstRightArrowTick) / 30 + 20000000;
    }
};