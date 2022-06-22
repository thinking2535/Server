#include "stdafx.h"

const float CArrowDodgeItemMaker::_PositionPrecision = 1000.0f;
const float CArrowDodgeItemMaker::_PositionMultiplier = 1.0f / _PositionPrecision;
const float CArrowDodgeItemMaker::_ItemScreenWidth = c_ScreenWidth * 0.8f;
const float CArrowDodgeItemMaker::_ItemScreenHeight = c_ScreenHeight * 0.8f;
const float CArrowDodgeItemMaker::_HalfItemScreenWidth = _ItemScreenWidth * 0.5f;
const float CArrowDodgeItemMaker::_HalfItemScreenHeight = _ItemScreenHeight * 0.5f;
const uint64 CArrowDodgeItemMaker::_IntItemScreenWidth = (uint64)(_ItemScreenWidth * _PositionPrecision);
const uint64 CArrowDodgeItemMaker::_IntItemScreenHeight = (uint64)(_ItemScreenHeight * _PositionPrecision);

CArrowDodgeItemMaker::CArrowDodgeItemMaker(CFixedRandom64& FixedRandom_) :
	_FixedRandom(FixedRandom_)
{
}
void CArrowDodgeItemMaker::FixedUpdate(int64 Tick_, function<void(const shared_ptr<CArrowDodgeItem>& pItem_)> fAddItem_)
{
	if (Tick_ > _NextItemTick)
	{
		_NextItemTick += g_MetaData->ArrowDodgeMeta.ItemRegenPeriodTick;

		auto ItemNumber = g_MetaData->GetRandomArrowDodgeItemNumber(_FixedRandom.Get());
		fAddItem_(MakeItem(_GetItemRandomPosition(), ItemNumber));
	}
}
shared_ptr<CArrowDodgeItem> CArrowDodgeItemMaker::MakeItem(const SPoint& LocalPosition_, int32 Number_)
{
	switch (Number_)
	{
	case CEngineGlobal::c_CoinNumber:
		return make_shared<CArrowDodgeCoin>(LocalPosition_);

	case CEngineGlobal::c_GoldBarNumber:
		return make_shared<CArrowDodgeGoldBar>(LocalPosition_);

	case CEngineGlobal::c_ShieldNumber:
		return make_shared<CArrowDodgeShield>(LocalPosition_);

	case CEngineGlobal::c_StaminaNumber:
		return make_shared<CArrowDodgeStamina>(LocalPosition_);

	default:
		throw exception();
	}
}
SPoint CArrowDodgeItemMaker::_GetItemRandomPosition()
{
	auto X = (_FixedRandom.Get() % _IntItemScreenWidth) * _PositionMultiplier - _HalfItemScreenWidth;
	auto Y = (_FixedRandom.Get() % _IntItemScreenHeight) * _PositionMultiplier - _HalfItemScreenHeight;

	return SPoint(X, Y);
}
