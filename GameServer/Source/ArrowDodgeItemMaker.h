#pragma once

#include <Rso/GameUtil/FixedRandom.h>

using namespace std;
using namespace rso;
using namespace gameutil;

class CArrowDodgeItemMaker
{
	static const float _PositionPrecision;
	static const float _PositionMultiplier;
	static const int64 _ItemDurationTick;
	static const float _ItemScreenWidth;
	static const float _ItemScreenHeight;
	static const float _HalfItemScreenWidth;
	static const float _HalfItemScreenHeight;
	static const uint64 _IntItemScreenWidth;
	static const uint64 _IntItemScreenHeight;

	CFixedRandom& _FixedRandom;
	int64 _NextItemTick = _ItemDurationTick;

public:
	int64 GetNextItemTick(void) const { return _NextItemTick; }
public:
	CArrowDodgeItemMaker(CFixedRandom& FixedRandom_);
	void FixedUpdate(int64 Tick_, function<void(const shared_ptr<CArrowDodgeItem>& pItem_)> fAddItem_);
	static shared_ptr<CArrowDodgeItem> MakeItem(const SPoint& LocalPosition_, int32 Number_);
private:
	SPoint _GetItemRandomPosition(void);
};