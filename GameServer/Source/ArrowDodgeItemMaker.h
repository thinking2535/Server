#pragma once

#include <Rso/GameUtil/FixedRandom64.h>

using namespace std;
using namespace rso;
using namespace gameutil;

class CArrowDodgeItemMaker
{
	static const float _PositionPrecision;
	static const float _PositionMultiplier;
	static const float _ItemScreenWidth;
	static const float _ItemScreenHeight;
	static const float _HalfItemScreenWidth;
	static const float _HalfItemScreenHeight;
	static const uint64 _IntItemScreenWidth;
	static const uint64 _IntItemScreenHeight;

	CFixedRandom64& _FixedRandom;
	int64 _NextItemTick = g_MetaData->ArrowDodgeMeta.ItemRegenPeriodTick;

public:
	int64 GetNextItemTick(void) const { return _NextItemTick; }
public:
	CArrowDodgeItemMaker(CFixedRandom64& FixedRandom_);
	void FixedUpdate(int64 Tick_, function<void(const shared_ptr<CArrowDodgeItem>& pItem_)> fAddItem_);
	static shared_ptr<CArrowDodgeItem> MakeItem(const SPoint& LocalPosition_, int32 Number_);
private:
	SPoint _GetItemRandomPosition(void);
};