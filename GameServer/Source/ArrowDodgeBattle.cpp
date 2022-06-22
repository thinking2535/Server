#include "stdafx.h"

SArrowObject::SArrowObject(const shared_ptr<CArrow>& pArrow_, const CList<shared_ptr<CMovingObject2D>>::iterator& ArrowIterator_)
{
	pArrow = pArrow_;
	ArrowIterator = ArrowIterator_;
}
SArrow SArrowObject::GetSArrow(void) const
{
	return SArrow(*pArrow, pArrow->Velocity);
}

SItemObject::SItemObject(const shared_ptr<CArrowDodgeItem>& pItem_, const CList<shared_ptr<CCollider2D>>::iterator& ItemIterator_)
{
	pItem = pItem_;
	ItemIterator = ItemIterator_;
}
SItem SItemObject::GetSItem(void) const
{
	return SItem(*pItem, pItem->Number);
}

void CArrowDodgeBattle::_AddBattlePlayer(const shared_ptr<CArrowDodgeBattlePlayer>& pBattlePlayer_)
{
	_pArrowDodgeBattlePlayer = pBattlePlayer_;
	CBattle::_AddBattlePlayer(pBattlePlayer_);
}
void CArrowDodgeBattle::_RegenCallback(int32 PlayerIndex_)
{
}
void CArrowDodgeBattle::_HitArrowCallback(const shared_ptr<CArrow>& pArrow_, bool IsDefended_)
{
	_RemoveArrow(pArrow_->Iterator);

	if (IsDefended_)
		_UpdateScore(g_MetaData->ArrowDodgeMeta.ArrowGetPoint);
	else if (!_pArrowDodgeBattlePlayer->IsAlive())
		_EndTime = system_clock::now() + seconds(2);
}
void CArrowDodgeBattle::_GetItemCallback(int64 Tick_, const shared_ptr<CArrowDodgeItem>& pItem_)
{
	_RemoveItem(pItem_->Iterator);
	_UpdateScore(g_MetaData->ArrowDodgeMeta.ItemGetPoint);
	pItem_->Proc(Tick_, _pArrowDodgeBattlePlayer, this);
}
CArrowDodgeBattle::CArrowDodgeBattle(CUser* pUser_, TBattlesIt itBattle_) :
	CBattle(
		make_unique<CServerEngine>(
			c_NetworkTickSync,
			0,
			c_ContactOffset,
			c_FPS,
			std::bind(&CArrowDodgeBattle::_SyncMessage, this, _1)),
		SBattleType(1, 1))
{
	auto pMap = g_MetaData->GetArrowDodgeMap();
	_pRootObject = make_shared<CObject2D>(GetDefaultTransform(pMap->PropPosition));

	// Structure /////////////////////////////////
	list<shared_ptr<CCollider2D>> StructureColliders;
	for (auto& s : pMap->Structures)
		StructureColliders.emplace_back(make_shared<CRectCollider2D>(s, CEngineGlobal::c_StructureNumber, s.RectCollider2D));

	auto pCollectionCollider = make_shared<CCollectionCollider2D>(GetDefaultTransform(pMap->PropPosition), CEngineGlobal::c_ContainerNumber);
	SetCollectionToCollectionCollider2D(std::move(StructureColliders), pCollectionCollider);
	_pEngine->AddObject(pCollectionCollider);


	// Players ////////////////////////////
	SPoint InitialPos(0.0f, -0.95f);
	auto pMeta = pUser_->GetSelectedChar();
	auto pCharacter = make_shared<SCharacter>(false, 0, c_BalloonCountForRegen, SPumpInfo(), SParachuteInfo(), SStaminaInfo(_pEngine->GetTick(), pMeta->StaminaMax), CEngineGlobal::GetFaceWithPosition(InitialPos),
		SPoint(0.0f, c_Gravity), CEngineGlobal::GetInvulnerableEndTick(_pEngine->GetTick()), 0, 0, 0);

	_pArrowDodgeBattlePlayer = make_shared<CArrowDodgeBattlePlayer>(
		SBattlePlayer(
			pUser_->GetUID(),
			pUser_->GetNick(),
			pUser_->GetCountryCode(),
			0,
			pUser_->GetSelectedCharCode()),
		std::bind(&CArrowDodgeBattle::_RegenCallback, this, _1),
		InitialPos,
		pMeta,
		pCharacter,
		itBattle_,
		pUser_,
		std::bind(&CArrowDodgeBattle::_HitArrowCallback, this, _1, _2),
		std::bind(&CArrowDodgeBattle::_GetItemCallback, this, _1, _2),
		this);

	_pArrowDodgeBattlePlayer->pPlayerObject->SetParent(_pRootObject);
	_AddBattlePlayer(_pArrowDodgeBattlePlayer);

	_pEngine->fFixedUpdate = std::bind(&CArrowDodgeBattle::_FixedUpdate, this, _1);

	pUser_->Send(GetArrowDodgeBattleBeginNetSc());
}
CArrowDodgeBattle::~CArrowDodgeBattle()
{
	_pArrowDodgeBattlePlayer->BattleEnd(_pEngine->GetTick());
}
void CArrowDodgeBattle::_SyncMessage(int64 Tick_)
{
	BroadCast(SBattleSyncNetSc(Tick_));
}
SArrowDodgeBattleBeginNetSc CArrowDodgeBattle::GetArrowDodgeBattleBeginNetSc(void) const
{
	vector<SArrow> Arrows;
	for (auto& i : _ArrowIts)
		Arrows.emplace_back(i.GetSArrow());

	vector<SItem> Items;
	for (auto& i : _ItemIts)
		Items.emplace_back(i.GetSItem());

	return SArrowDodgeBattleBeginNetSc(
		*_pArrowDodgeBattlePlayer,
		_pArrowDodgeBattlePlayer->BattleInfo,
		_pArrowDodgeBattlePlayer->Bufs,
		_pArrowDodgeBattlePlayer->GetCharacterNet(),
		_pEngine->GetTick(),
		_ArrowMaker.GetRandomSeed(),
		_ArrowMaker.GetNextDownArrowTick(),
		_ArrowMaker.GetNextLeftArrowTick(),
		_ArrowMaker.GetNextRightArrowTick(),
		_ItemMaker.GetNextItemTick(),
		std::move(Arrows),
		std::move(Items),
		_pEngine->IsStarted());
}
bool CArrowDodgeBattle::Update(void)
{
	if (!CBattle::Update()) // 클라쪽에 화살 맞는 연출이 되어야 하므로
		return false;

	auto Now = system_clock::now(); // ing   CMultiBattle 에서는 now() 대신 GetTickCount() 를 쓸것.

	if (!_pEngine->IsStarted())
	{
		if (Now - _BeginTime >= milliseconds(c_BattleStartDelayMilliSec))
		{
			_pEngine->Start();
			BroadCast(SArrowDodgeBattleStartNetSc());
		}
	}
	else if (_EndTime < Now)
	{
		return false;
	}

	return true;
}
void CArrowDodgeBattle::OnLine(int32 PlayerIndex_)
{
	Send(PlayerIndex_, GetArrowDodgeBattleBeginNetSc());
}
void CArrowDodgeBattle::OffLine(int32 PlayerIndex_)
{
}
void CArrowDodgeBattle::_FixedUpdate(int64 Tick_)
{
	if (_pArrowDodgeBattlePlayer->IsAlive())
		_pArrowDodgeBattlePlayer->BattleInfo.Tick = Tick_;

	_ArrowMaker.FixedUpdate(Tick_, std::bind(&CArrowDodgeBattle::_AddArrow, this, _1));

	if (_ItemIts.size() < _MaxItemCount)
		_ItemMaker.FixedUpdate(Tick_, std::bind(&CArrowDodgeBattle::_AddItem, this, _1));

	for (auto it = _ArrowIts.begin(); it;)
	{
		auto itCheck = it;
		++it;

		if (!itCheck->pArrow->FixedUpdate())
		{
			_RemoveArrow(itCheck);

			if (_pArrowDodgeBattlePlayer->IsAlive())
				_UpdateScore(g_MetaData->ArrowDodgeMeta.ArrowDodgePoint);
		}
	}
}
void CArrowDodgeBattle::_UpdateScore(int32 AddedPoint_)
{
	_pArrowDodgeBattlePlayer->BattleInfo.Point += AddedPoint_;
}
void CArrowDodgeBattle::_AddArrow(const shared_ptr<CArrow>& pArrow_)
{
	pArrow_->SetParent(_pRootObject);
	auto ArrowIt = _pEngine->AddMovingObject(pArrow_);
	pArrow_->Iterator = _ArrowIts.emplace(SArrowObject(pArrow_, ArrowIt));
}
void CArrowDodgeBattle::_RemoveArrow(CList<SArrowObject>::iterator ArrowObjectIt_)
{
	_pEngine->RemoveMovingObject(ArrowObjectIt_->ArrowIterator);
	_ArrowIts.erase(ArrowObjectIt_);
}
void CArrowDodgeBattle::_AddItem(const shared_ptr<CArrowDodgeItem>& pItem_)
{
	pItem_->SetParent(_pRootObject);
	auto ItemIt = _pEngine->AddObject(pItem_);
	pItem_->Iterator = _ItemIts.emplace(SItemObject(pItem_, ItemIt));
}
void CArrowDodgeBattle::_RemoveItem(CList<SItemObject>::iterator ItemObjectIt_)
{
	_pEngine->RemoveObject(ItemObjectIt_->ItemIterator);
	_ItemIts.erase(ItemObjectIt_);
}
