#include "stdafx.h"

const float CFlyAwayBattle::_InitialPosX = -1.0f;

SFlyAwayLandObject::SFlyAwayLandObject(CFlyAwayLand* pLand_, const CList<shared_ptr<CCollider2D>>::iterator& LandIterator_)
{
	pLand = pLand_;
	LandIterator = LandIterator_;
}
SFlyAwayLand SFlyAwayLandObject::GetSFlyAwayLand(void) const
{
	return pLand->GetSFlyAwayLand();
}

SFlyAwayItemObject::SFlyAwayItemObject(CFlyAwayItem* pItem_, const CList<shared_ptr<CCollider2D>>::iterator& ItemIterator_)
{
	pItem = pItem_;
	ItemIterator = ItemIterator_;
}
SFlyAwayItem SFlyAwayItemObject::GetSFlyAwayItem(void) const
{
	return SFlyAwayItem(pItem->LocalPosition, pItem->GetItemType());
}

void CFlyAwayBattle::_GetItemCallback(const CFlyAwayItem* pItem_)
{
	pItem_->Proc(_pFlyAwayBattlePlayer, this);
	_RemoveItem(pItem_->Iterator);
}
void CFlyAwayBattle::_LandCallback(const CFlyAwayLand* pLand_)
{
	if (pLand_->GetLandNumber() == 0)
		return;

	_pFlyAwayBattlePlayer->addStamina(g_MetaData->flyAwayConfigMeta.landingAddedStamina);

	auto Diff = _pFlyAwayBattlePlayer->pPlayerObject->LocalPosition.X - pLand_->LocalPosition.X;
	if (Diff < 0.0f)
		Diff = -Diff;

	int32 AddedPoint;
	if (Diff < 0.05f)
	{
		++_pFlyAwayBattlePlayer->BattleInfo.PerfectCombo;

		if (_pFlyAwayBattlePlayer->BattleInfo.PerfectCombo > _pFlyAwayBattlePlayer->pPlayer->GetUserDB().IslandComboBest)
			_pFlyAwayBattlePlayer->pPlayer->GetUserDB().IslandComboBest = _pFlyAwayBattlePlayer->BattleInfo.PerfectCombo;

		AddedPoint = 100 * (_pFlyAwayBattlePlayer->BattleInfo.PerfectCombo < g_MetaData->flyAwayConfigMeta.maxComboMultiplier ? _pFlyAwayBattlePlayer->BattleInfo.PerfectCombo : g_MetaData->flyAwayConfigMeta.maxComboMultiplier);
	}
	else
	{
		_pFlyAwayBattlePlayer->BattleInfo.PerfectCombo = 0;

		if (Diff < 0.1f)
			AddedPoint = 50;
		else
			AddedPoint = 10;
	}

	_pFlyAwayBattlePlayer->BattleInfo.Point += AddedPoint;
}
void CFlyAwayBattle::_deadCallback()
{
	_EndTime = system_clock::now() + seconds(2);
}
CFlyAwayBattle::CFlyAwayBattle(CUser* pUser_, TBattlesIt itBattle_) :
	CBattle(SBattleType(1, 1), g_MetaData->GetFlyAwayMap()),
	_pFlyAwayMap(static_cast<const SFlyAwayMap*>(_pMap))
{

	// Structure /////////////////////////////////
	for (auto& s : _pFlyAwayMap->Structures)
		_pEngine->AddObject(make_shared<CRectCollider2D>(s, CEngineGlobal::c_StructureNumber, s.RectCollider2D, _pRootObject.get()));

	for (auto& s : _pFlyAwayMap->deadZones)
		_pEngine->AddObject(make_shared<CRectCollider2D>(s, CEngineGlobal::c_DeadZoneNumber, s.RectCollider2D, _pRootObject.get()));

	_pEngine->AddObject(make_shared<CRectCollider2D>(_pFlyAwayMap->ocean, CEngineGlobal::c_OceanNumber, _pFlyAwayMap->ocean.RectCollider2D, _pRootObject.get()));

	auto minVelocityY = min(g_MetaData->GetMinVelAir(), c_MaxVelDown);
	auto itemPathSlope = minVelocityY * flyAwayItemSlopeFactor / g_MetaData->GetMinVelAir();
	_itemXDistance = _pathMaker.getVerticalStep() / itemPathSlope;
	_itemLandXDistance = _itemXDistance * flyAwayItemCoinXDistanceMultiplier;

	// Players ////////////////////////////
	auto pMeta = pUser_->GetSelectedChar();
	auto pCharacter = make_shared<SCharacter>(
		false,
		0,
		c_BalloonCountForRegen,
		SPumpInfo(),
		SParachuteInfo(),
		SStaminaInfo(_pEngine->GetTick(), pMeta->pCharacterTypeMeta->StaminaMax),
		CEngineGlobal::GetFaceWithX(_InitialPosX),
		CEngineGlobal::GetInvulnerableEndTick(_pEngine->GetTick()),
		0,
		0,
		0);

	_pFlyAwayBattlePlayer = make_shared<CFlyAwayBattlePlayer>(
		SBattlePlayer(
			pUser_->GetUID(),
			pUser_->GetNick(),
			pUser_->GetCountryCode(),
			0,
			pUser_->GetSelectedCharCode()),
		_LastLandPosition,
		pMeta,
		pCharacter,
		itBattle_,
		pUser_,
		std::bind(&CFlyAwayBattle::_GetItemCallback, this, _1),
		std::bind(&CFlyAwayBattle::_LandCallback, this, _1),
		std::bind(&CFlyAwayBattle::_deadCallback, this),
		this);
	_XMoveDelta = _pFlyAwayBattlePlayer->pMeta->pCharacterTypeMeta->MaxVelAir * CEngine::GetDeltaTime();

	_pFlyAwayBattlePlayer->pPlayerObject->SetParent(_pRootObject.get());
	_AddBattlePlayer(_pFlyAwayBattlePlayer);

	_AddLand(_MakeLand(_LastLandPosition, _LandCounter, (int32)(g_MetaData->MapMeta.FlyAwayMapInfo.Lands.size() - 1)));

	while (_LateAddLand());

	pUser_->Send(GetFlyAwayBattleBeginNetSc());
}
CFlyAwayBattle::~CFlyAwayBattle()
{
	_pFlyAwayBattlePlayer->BattleEnd(_pEngine->GetTick());
}
ERet CFlyAwayBattle::Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_)
{
	return ERet::InvalidProtocol;
}
SFlyAwayBattleBeginNetSc CFlyAwayBattle::GetFlyAwayBattleBeginNetSc(void) const
{
	vector<SFlyAwayLand> Lands;
	for (auto& i : _LandIts)
		Lands.emplace_back(i.GetSFlyAwayLand());

	vector<SFlyAwayItem> Items;
	for (auto& i : _ItemIts)
		Items.emplace_back(i.GetSFlyAwayItem());

	return SFlyAwayBattleBeginNetSc(
		SingleBattleBeginNetSc(
			*_pFlyAwayBattlePlayer,
			_pFlyAwayBattlePlayer->GetCharacterNet(),
			_pEngine->GetTick(),
			_FixedRandom.GetSeed(),
			_pEngine->IsStarted()),
		_pathMaker.getState(),
		_pFlyAwayBattlePlayer->BattleInfo,
		_LandCounter,
		_LastLandPosition,
		std::move(Lands),
		std::move(Items));
}
bool CFlyAwayBattle::Update(void)
{
	if (!CBattle::Update()) // 클라쪽에 화살 맞는 연출이 되어야 하므로
		return false;

	auto Now = system_clock::now(); // ing   CMultiBattle 에서는 now() 대신 GetTickCount() 를 쓸것.

	if (!_IsStarted)
	{
		if (Now - _BeginTime >= milliseconds(c_BattleStartDelayMilliSec))
		{
			_IsStarted = true;
			_CheckAndStartEngine();
			_Send(0, SFlyAwayBattleStartNetSc());
		}
	}
	else if (Now >= _EndTime)
	{
		return false;
	}

	return true;
}
void CFlyAwayBattle::Link(int32 PlayerIndex_)
{
	_Send(PlayerIndex_, GetFlyAwayBattleBeginNetSc());
}
void CFlyAwayBattle::_AddLand(const shared_ptr<CFlyAwayLand>& pLand_)
{
	pLand_->SetParent(_pRootObject.get());
	auto LandIt = _pEngine->AddObject(pLand_);
	pLand_->Iterator = _LandIts.emplace(SFlyAwayLandObject(pLand_.get(), LandIt));
}
void CFlyAwayBattle::_RemoveLand(CList<SFlyAwayLandObject>::iterator LandObjectIt_)
{
	_pEngine->RemoveObject(LandObjectIt_->LandIterator);
	_LandIts.erase(LandObjectIt_);
}
bool CFlyAwayBattle::_LateAddLand()
{
	if (_LastLandPosition.X > c_ScreenWidth_2)
		return false;

	++_LandCounter;

	auto RangeFactor = (float)(_LandCounter) / (float)flyAwayLandDistanceBase;
	auto Distance = flyAwayMinLandDistance + RangeFactor;

	// Add Items
	{
		_LastLandPosition.X += _itemLandXDistance;
		_LateAddItem(SPoint(_LastLandPosition.X, _pathMaker.getCurrentY()));

		float itemsDistanse = 0.0f;
		while (true)
		{
			if (itemsDistanse > Distance)
			{
				_LastLandPosition.X += _itemLandXDistance;
				_LastLandPosition.Y = _pathMaker.getCurrentY() - _getItemLandYDistance();
				break;
			}

			_LastLandPosition.X += _itemXDistance;
			itemsDistanse += _itemXDistance;
			_LateAddItem(SPoint(_LastLandPosition.X, _pathMaker.getNextY()));
		}
	}

	float normalizedLandNumber = RangeFactor > 1.0f ? 0.0f : 1.0f - RangeFactor;
	auto Index = (int32)((float)g_MetaData->MapMeta.FlyAwayMapInfo.Lands.size() * normalizedLandNumber);
	if (Index >= g_MetaData->MapMeta.FlyAwayMapInfo.Lands.size())
		Index = (int32)g_MetaData->MapMeta.FlyAwayMapInfo.Lands.size() - 1;

	_AddLand(_MakeLand(_LastLandPosition, _LandCounter, Index));

	return true;
}
void CFlyAwayBattle::_AddItem(const shared_ptr<CFlyAwayItem>& pItem_)
{
	pItem_->SetParent(_pRootObject.get());
	auto ItemIt = _pEngine->AddObject(pItem_);
	pItem_->Iterator = _ItemIts.emplace(SFlyAwayItemObject(pItem_.get(), ItemIt));
}
void CFlyAwayBattle::_LateAddItem(const SPoint& LocalPosition_)
{
	_AddItem(_MakeItem(LocalPosition_, g_MetaData->GetRandomFlyAwayStaminaItemType(_FixedRandom.Get())));
}
void CFlyAwayBattle::_RemoveItem(CList<SFlyAwayItemObject>::iterator ItemObjectIt_)
{
	_pEngine->RemoveObject(ItemObjectIt_->ItemIterator);
	_ItemIts.erase(ItemObjectIt_);
}
shared_ptr<CFlyAwayLand> CFlyAwayBattle::_MakeLand(const SPoint& LocalPosition_, int32 Number_, int32 Index_)
{
	return make_shared<CFlyAwayLand>(LocalPosition_, Number_, Index_);
}
shared_ptr<CFlyAwayItem> CFlyAwayBattle::_MakeItem(const SPoint& LocalPosition_, EFlyAwayItemType ItemType_)
{
	switch (ItemType_)
	{
	case EFlyAwayItemType::Coin:
		return make_shared<CFlyAwayCoin>(LocalPosition_);

	case EFlyAwayItemType::GoldBar:
		return make_shared<CFlyAwayGoldBar>(LocalPosition_);

	case EFlyAwayItemType::Apple:
		return make_shared<CFlyAwayApple>(LocalPosition_);

	case EFlyAwayItemType::Meat:
		return make_shared<CFlyAwayMeat>(LocalPosition_);

	case EFlyAwayItemType::Chicken:
		return make_shared<CFlyAwayChicken>(LocalPosition_);

	default:
		throw exception();
	}
}
void CFlyAwayBattle::_fixedUpdate()
{
	for (auto& i : _LandIts)
		i.pLand->FixedUpdate(_pEngine->GetTick());

	if (!_pFlyAwayBattlePlayer->pCharacter->IsGround)
	{
		auto itFirstLand = _LandIts.begin();
		if (itFirstLand != _LandIts.end())
		{
			if (itFirstLand->pLand->LocalPosition.X < (-c_ScreenWidth_2 - flyAwayMinLandDistance))
				_RemoveLand(itFirstLand);
		}

		auto itFirstItem = _ItemIts.begin();
		if (itFirstItem != _ItemIts.end())
		{
			if (itFirstItem->pItem->LocalPosition.X < (-c_ScreenWidth_2 - flyAwayMinLandDistance))
				_RemoveItem(itFirstItem);
		}

		_LateAddLand();

		for (auto& i : _LandIts)
			i.pLand->LocalPosition.X -= _XMoveDelta;

		for (auto& i : _ItemIts)
			i.pItem->LocalPosition.X -= _XMoveDelta;

		_LastLandPosition.X -= _XMoveDelta;
	}
}
