#include "stdafx.h"

CArrowDodgeItemMaker::CArrowDodgeItemMaker(CFixedRandom32& FixedRandom_) :
	_FixedRandom(FixedRandom_)
{
}
void CArrowDodgeItemMaker::FixedUpdate(int64 tick, CArrowDodgeBattle& battle, function<void(const shared_ptr<CArrowDodgeItem>& pItem_)> fAddItem_)
{
	if (tick > _NextItemTick)
	{
		_NextItemTick += g_MetaData->arrowDodgeConfigMeta.ItemRegenPeriodTick;

		// Ŭ���̾�Ʈ�� ���߱� ���� ������� ȣ��Ǿ�� ��
		auto RandomPosition = battle.getRandomItemPoint();
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
