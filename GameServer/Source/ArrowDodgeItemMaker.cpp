#include "stdafx.h"

const float CArrowDodgeItemMaker::_PositionPrecision = 1000.0f;
const float CArrowDodgeItemMaker::_PositionMultiplier = 1.0f / _PositionPrecision;
const float CArrowDodgeItemMaker::_ItemScreenWidth = c_ScreenWidth * 0.8f;
const float CArrowDodgeItemMaker::_ItemScreenHeight = c_ScreenHeight * 0.8f;
const float CArrowDodgeItemMaker::_HalfItemScreenWidth = _ItemScreenWidth * 0.5f;
const float CArrowDodgeItemMaker::_HalfItemScreenHeight = _ItemScreenHeight * 0.5f;
const uint32 CArrowDodgeItemMaker::_IntItemScreenWidth = (uint32)(_ItemScreenWidth * _PositionPrecision);
const uint32 CArrowDodgeItemMaker::_IntItemScreenHeight = (uint32)(_ItemScreenHeight * _PositionPrecision);

CArrowDodgeItemMaker::CArrowDodgeItemMaker(CFixedRandom32& FixedRandom_) :
	_FixedRandom(FixedRandom_)
{
}
void CArrowDodgeItemMaker::FixedUpdate(int64 Tick_, function<void(const shared_ptr<CArrowDodgeItem>& pItem_)> fAddItem_)
{
	if (Tick_ > _NextItemTick)
	{
		_NextItemTick += g_MetaData->ArrowDodgeMeta.ItemRegenPeriodTick;

		// 클라이언트와 맞추기 위해 순서대로 호출되어야 함
		auto RandomPosition = _GetItemRandomPosition();
		auto RandomType = g_MetaData->GetRandomArrowDodgeItemType(_FixedRandom.Get());

		fAddItem_(MakeItem(RandomPosition, RandomType));
	}
}
shared_ptr<CArrowDodgeItem> CArrowDodgeItemMaker::MakeItem(const SPoint& LocalPosition_, EArrowDodgeItemType ItemType_)
{
	switch (ItemType_)
	{
	case EArrowDodgeItemType::Coin:
		return make_shared<CArrowDodgeCoin>(LocalPosition_);

	case EArrowDodgeItemType::GoldBar:
		return make_shared<CArrowDodgeGoldBar>(LocalPosition_);

	case EArrowDodgeItemType::Shield:
		return make_shared<CArrowDodgeShield>(LocalPosition_);

	case EArrowDodgeItemType::Stamina:
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
