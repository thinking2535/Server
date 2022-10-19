#pragma once

#include <Rso/GameUtil/FixedRandom64.h>

using namespace std;
using namespace rso;
using namespace gameutil;

class CArrowDodgeItemMaker
{
	CFixedRandom32& _FixedRandom;
	int64 _NextItemTick = g_MetaData->arrowDodgeConfigMeta.ItemRegenPeriodTick;

public:
	int64 GetNextItemTick(void) const { return _NextItemTick; }
	CArrowDodgeItemMaker(CFixedRandom32& FixedRandom_);
	void FixedUpdate(int64 tick, CArrowDodgeBattle& battle, function<void(const shared_ptr<CArrowDodgeItem>& pItem_)> fAddItem_);
	static shared_ptr<CArrowDodgeItem> MakeItem(const SPoint& LocalPosition_, EArrowDodgeItemType ItemType_);
};