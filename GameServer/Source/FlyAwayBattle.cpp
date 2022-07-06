#include "stdafx.h"

const float CFlyAwayBattle::_LandTopY = c_ScreenHeight_2 * 0.6f;
const float CFlyAwayBattle::_LandBottomY = -c_ScreenHeight_2 * 0.9f;
const float CFlyAwayBattle::_LandHeightRange = _LandTopY - _LandBottomY;
const uint32 CFlyAwayBattle::_IntHeightRange = (uint32)(_LandHeightRange * 1000.0f);
const int32 CFlyAwayBattle::_MaxDistanceLandCounter = 30;
const float CFlyAwayBattle::_LimitLandDistance = 3.4f;
const float CFlyAwayBattle::_MinLandDistance = 0.8f;
const float CFlyAwayBattle::_LandDistanceRange = 1.0f;
const float CFlyAwayBattle::_RandomMinLandDistance = 0.5f;
const float CFlyAwayBattle::_RandomLandDistanceRange = 1.5f;
const int64 CFlyAwayBattle::_LandTypeFactor = 600000000;
const float CFlyAwayBattle::_ItemYOffset = 0.1f;
const SPoint CFlyAwayBattle::_InitialPos(-1.0f, 0.0f);

SFlyAwayLandObject::SFlyAwayLandObject(const shared_ptr<CFlyAwayLand>& pLand_, const CList<shared_ptr<CCollider2D>>::iterator& LandIterator_)
{
	pLand = pLand_;
	LandIterator = LandIterator_;
}
SFlyAwayLand SFlyAwayLandObject::GetSFlyAwayLand(void) const
{
	return pLand->GetSFlyAwayLand();
}

SFlyAwayItemObject::SFlyAwayItemObject(const shared_ptr<CFlyAwayItem>& pItem_, const CList<shared_ptr<CCollider2D>>::iterator& ItemIterator_)
{
	pItem = pItem_;
	ItemIterator = ItemIterator_;
}
SFlyAwayItem SFlyAwayItemObject::GetSFlyAwayItem(void) const
{
	return SFlyAwayItem(pItem->LocalPosition, pItem->GetItemType());
}

void CFlyAwayBattle::_AddBattlePlayer(const shared_ptr<CFlyAwayBattlePlayer>& pBattlePlayer_)
{
	_pFlyAwayBattlePlayer = pBattlePlayer_;

	_XMoveDelta = _pFlyAwayBattlePlayer->pMeta->MaxVelXAir * CEngine::GetDeltaTime();
	_LandUpYFactor = 0.5f * g_MetaData->GetMinVelUp() / g_MetaData->GetMinVelXAir();
	_LandDownYFactor = 0.5f * g_MetaData->GetMinVelDown() / g_MetaData->GetMinVelXAir();

	CBattle::_AddBattlePlayer(pBattlePlayer_);
}
void CFlyAwayBattle::_RegenCallback(int32 PlayerIndex_)
{
}
void CFlyAwayBattle::_GetItemCallback(int64 Tick_, const shared_ptr<CFlyAwayItem>& pItem_)
{
	_RemoveItem(pItem_->Iterator);
	pItem_->Proc(Tick_, _pFlyAwayBattlePlayer, this);
}
void CFlyAwayBattle::_LandCallback(int64 Tick_, const shared_ptr<CFlyAwayLand>& pLand_)
{
	if (pLand_->GetLandNumber() == 0)
		return;

	++_pFlyAwayBattlePlayer->BattleInfo.PassedCount;

	auto Diff = _pFlyAwayBattlePlayer->pPlayerObject->LocalPosition.X - pLand_->LocalPosition.X;
	if (Diff < 0.0f)
		Diff = -Diff;

	int32 AddedPoint;
	if (Diff < 0.05f)
	{
		++_pFlyAwayBattlePlayer->BattleInfo.PerfectCombo;
		AddedPoint = 100 * _pFlyAwayBattlePlayer->BattleInfo.PerfectCombo;
	}
	else
	{
		_pFlyAwayBattlePlayer->BattleInfo.PerfectCombo = 0;

		if (Diff < 0.1f)
		{
			AddedPoint = 50;
		}
		else
		{
			AddedPoint = 10;
		}
	}

	_pFlyAwayBattlePlayer->BattleInfo.Point += AddedPoint;
}
CFlyAwayBattle::CFlyAwayBattle(CUser* pUser_, TBattlesIt itBattle_) :
	CBattle(SBattleType(1, 1)),
	_LastLandPosition(_InitialPos.X, _InitialPos.Y + 0.002f)
{
	auto pMap = g_MetaData->GetFlyAwayMap();
	_pRootObject = make_shared<CObject2D>(GetDefaultTransform(pMap->PropPosition));

	// Structure /////////////////////////////////
	list<shared_ptr<CCollider2D>> StructureColliders;
	for (auto& s : pMap->Structures)
		StructureColliders.emplace_back(make_shared<CRectCollider2D>(s, CEngineGlobal::c_StructureNumber, s.RectCollider2D));

	auto pCollectionCollider = make_shared<CCollectionCollider2D>(GetDefaultTransform(pMap->PropPosition), CEngineGlobal::c_ContainerNumber);
	SetCollectionToCollectionCollider2D(std::move(StructureColliders), pCollectionCollider);
	_pEngine->AddObject(pCollectionCollider);


	// Players ////////////////////////////
	auto pMeta = pUser_->GetSelectedChar();
	auto pCharacter = make_shared<SCharacter>(false, 0, c_BalloonCountForRegen, SPumpInfo(), SParachuteInfo(), SStaminaInfo(_pEngine->GetTick(), pMeta->StaminaMax), CEngineGlobal::GetFaceWithPosition(_InitialPos),
		SPoint(0.0f, c_Gravity), CEngineGlobal::GetInvulnerableEndTick(_pEngine->GetTick()), 0, 0, 0);

	_pFlyAwayBattlePlayer = make_shared<CFlyAwayBattlePlayer>(
		SBattlePlayer(
			pUser_->GetUID(),
			pUser_->GetNick(),
			pUser_->GetCountryCode(),
			0,
			pUser_->GetSelectedCharCode()),
		std::bind(&CFlyAwayBattle::_RegenCallback, this, _1),
		_InitialPos,
		pMeta,
		pCharacter,
		itBattle_,
		pUser_,
		std::bind(&CFlyAwayBattle::_GetItemCallback, this, _1, _2),
		std::bind(&CFlyAwayBattle::_LandCallback, this, _1, _2),
		this);

	_pFlyAwayBattlePlayer->pPlayerObject->SetParent(_pRootObject);
	_AddBattlePlayer(_pFlyAwayBattlePlayer);

	_pEngine->fFixedUpdate = std::bind(&CFlyAwayBattle::_FixedUpdate, this, _1);

	_AddLand(_MakeLand(_LastLandPosition, _LandCounter, (int32)(g_MetaData->MapMeta.FlyAwayMapInfo.Lands.size() - 1)));

	while (_LateAddLand(0));

	pUser_->Send(GetFlyAwayBattleBeginNetSc());
}
CFlyAwayBattle::~CFlyAwayBattle()
{
	_pFlyAwayBattlePlayer->BattleEnd(_pEngine->GetTick());
}
ERet CFlyAwayBattle::Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_)
{
	return ERet::Ok;
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
		*_pFlyAwayBattlePlayer,
		_pFlyAwayBattlePlayer->BattleInfo,
		_pFlyAwayBattlePlayer->GetCharacterNet(),
		_pEngine->GetTick(),
		_FixedRandom.GetSeed(),
		_LandCounter,
		_LastLandPosition,
		std::move(Lands),
		std::move(Items),
		_pEngine->IsStarted());
}
bool CFlyAwayBattle::Update(void)
{
	if (!CBattle::Update()) // 클라쪽에 화살 맞는 연출이 되어야 하므로
		return false;

	auto Now = system_clock::now(); // ing   CMultiBattle 에서는 now() 대신 GetTickCount() 를 쓸것.

	if (!_pEngine->IsStarted())
	{
		if (Now - _BeginTime >= milliseconds(c_BattleStartDelayMilliSec))
		{
			_pEngine->Start();
			BroadCast(SFlyAwayBattleStartNetSc());
		}
	}
	else if (_EndTime < Now)
	{
		return false;
	}

	return true;
}
void CFlyAwayBattle::OnLine(int32 PlayerIndex_)
{
	Send(PlayerIndex_, GetFlyAwayBattleBeginNetSc());
}
void CFlyAwayBattle::OffLine(int32 PlayerIndex_)
{
}
void CFlyAwayBattle::_FixedUpdate(int64 Tick_)
{
	for (auto& i : _LandIts)
		i.pLand->FixedUpdate(Tick_);

	if (!_pFlyAwayBattlePlayer->pCharacter->IsGround)
	{
		auto itFirstLand = _LandIts.begin();
		if (itFirstLand != _LandIts.end())
		{
			if (itFirstLand->pLand->LocalPosition.X < (-c_ScreenWidth_2 - _MinLandDistance))
				_RemoveLand(itFirstLand);
		}

		auto itFirstItem = _ItemIts.begin();
		if (itFirstItem != _ItemIts.end())
		{
			if (itFirstItem->pItem->LocalPosition.X < (-c_ScreenWidth_2 - _MinLandDistance))
				_RemoveItem(itFirstItem);
		}

		_LateAddLand(Tick_);

		for (auto& i : _LandIts)
			i.pLand->LocalPosition.X -= _XMoveDelta;

		for (auto& i : _ItemIts)
			i.pItem->LocalPosition.X -= _XMoveDelta;

		_LastLandPosition.X -= _XMoveDelta;
	}
		
	if (_pFlyAwayBattlePlayer->IsAlive() &&
		(_pFlyAwayBattlePlayer->pPlayerObject->LocalPosition.Y < -c_ScreenHeight_2 || _pFlyAwayBattlePlayer->pPlayerObject->LocalPosition.X < -c_ScreenWidth_2 + c_PlayerWidth_2))
	{
		_pFlyAwayBattlePlayer->Die(Tick_);
		_EndTime = system_clock::now() + seconds(2);
	}
}
void CFlyAwayBattle::_AddLand(const shared_ptr<CFlyAwayLand>& pLand_)
{
	pLand_->SetParent(_pRootObject);
	auto LandIt = _pEngine->AddObject(pLand_);
	pLand_->Iterator = _LandIts.emplace(SFlyAwayLandObject(pLand_, LandIt));
}
void CFlyAwayBattle::_RemoveLand(CList<SFlyAwayLandObject>::iterator LandObjectIt_)
{
	if (!LandObjectIt_)
		return;

	_pEngine->RemoveObject(LandObjectIt_->LandIterator);
	_LandIts.erase(LandObjectIt_);
}
bool CFlyAwayBattle::_LateAddLand(int64 Tick_)
{
	if (_LastLandPosition.X > c_ScreenWidth_2)
		return false;

	++_LandCounter;

	// Set Random X
	auto RangeFactor = _LandCounter < _MaxDistanceLandCounter ? (float)(_LandCounter) / (float)_MaxDistanceLandCounter : 1.0f;
	auto BaseDistance = _MinLandDistance + (_LandDistanceRange * RangeFactor);
	auto RandomDistance = (float)(_FixedRandom.Get() % 1000) * 0.001f * (_RandomMinLandDistance + _RandomLandDistanceRange * RangeFactor);
	auto Distance = BaseDistance + RandomDistance;
	if (Distance > _LimitLandDistance)
		Distance = _LimitLandDistance;

	_LastLandPosition.X += Distance;

	// Set Random Y
	uint32 RandomIntHeightRange = _FixedRandom.Get() % _IntHeightRange;
	auto RandomY = _LandBottomY + (float)((float)RandomIntHeightRange * 0.001f);

	auto MaxUpDiff = _LandUpYFactor * Distance;
	auto YDiff = RandomY - _LastLandPosition.Y;
	if (YDiff > MaxUpDiff)
	{
		_LastLandPosition.Y += MaxUpDiff;
	}
	else
	{
		auto MaxDownDiff = _LandDownYFactor * Distance;
		if (YDiff < -MaxDownDiff)
			_LastLandPosition.Y -= MaxDownDiff;
		else
			_LastLandPosition.Y = RandomY;
	}


	auto Index = (int32)((float)g_MetaData->MapMeta.FlyAwayMapInfo.Lands.size() * (1.0f - RangeFactor));
	if (Index >= g_MetaData->MapMeta.FlyAwayMapInfo.Lands.size())
		Index = (int32)g_MetaData->MapMeta.FlyAwayMapInfo.Lands.size() - 1;

	_AddLand(_MakeLand(_LastLandPosition, _LandCounter, Index));
	_LateAddItem(SPoint(_LastLandPosition.X, _LastLandPosition.Y + _ItemYOffset));

	return true;
}
void CFlyAwayBattle::_AddItem(const shared_ptr<CFlyAwayItem>& pItem_)
{
	pItem_->SetParent(_pRootObject);
	auto ItemIt = _pEngine->AddObject(pItem_);
	pItem_->Iterator = _ItemIts.emplace(SFlyAwayItemObject(pItem_, ItemIt));
}
void CFlyAwayBattle::_LateAddItem(const SPoint& LocalPosition_)
{
	_AddItem(_MakeItem(LocalPosition_, g_MetaData->GetRandomFlyAwayStaminaItemType(_FixedRandom.Get())));
}
void CFlyAwayBattle::_RemoveItem(CList<SFlyAwayItemObject>::iterator ItemObjectIt_)
{
	if (!ItemObjectIt_)
		return;

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
