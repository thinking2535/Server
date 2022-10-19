#include "stdafx.h"

const uint32 CArrowDodgeBattle::_intItemScreenWidth = (uint32)(arrowDodgeItemScreenWidth * arrowDodgePositionPrecision);
const uint32 CArrowDodgeBattle::_intItemScreenHeight = (uint32)(arrowDodgeItemScreenHeight * arrowDodgePositionPrecision);

SArrowObject::SArrowObject(CArrow* pArrow_, const CList<shared_ptr<CMovingObject2D>>::iterator& ArrowIterator_)
{
	pArrow = pArrow_;
	ArrowIterator = ArrowIterator_;
}
SArrow SArrowObject::GetSArrow(void) const
{
	return SArrow(pArrow->LocalPosition, pArrow->Velocity);
}

SArrowDodgeItemObject::SArrowDodgeItemObject(CArrowDodgeItem* pItem_)
{
	pItem = pItem_;
}
SArrowDodgeItem SArrowDodgeItemObject::GetSArrowDodgeItem(void) const
{
	return SArrowDodgeItem(pItem->LocalPosition, pItem->GetItemType());
}

float CArrowDodgeBattle::_getRandomItemPointX(CFixedRandom32& fixedRandom)
{
	auto widthRandom = fixedRandom.Get() % _intItemScreenWidth;
	float floatWidthRandom = (float)widthRandom;
	return floatWidthRandom / arrowDodgePositionPrecision - arrowDodgeHalfItemScreenWidth;
}
float CArrowDodgeBattle::_getRandomItemPointY(CFixedRandom32& fixedRandom)
{
	auto heightRandom = fixedRandom.Get() % _intItemScreenHeight;
	float floatHeightRandom = (float)heightRandom;
	return floatHeightRandom / arrowDodgePositionPrecision;
}
SPoint CArrowDodgeBattle::getRandomItemPoint()
{
	auto x = _getRandomItemPointX(_FixedRandom);
	auto y = _getRandomItemPointY(_FixedRandom);
	return SPoint(x, y);
}

void CArrowDodgeBattle::_AddBattlePlayer(const shared_ptr<CArrowDodgeBattlePlayer>& pBattlePlayer_)
{
	_pArrowDodgeBattlePlayer = pBattlePlayer_;
	CBattle::_AddBattlePlayer(pBattlePlayer_);
}
void CArrowDodgeBattle::_HitArrowCallback(const CArrow* pArrow_, bool IsDefended_)
{
	if (IsDefended_)
		_UpdateScore(g_MetaData->arrowDodgeConfigMeta.ArrowGetPoint);
	else if (!_pArrowDodgeBattlePlayer->IsAlive())
		_EndTime = system_clock::now() + seconds(2);

	_ArrowIts.erase(pArrow_->Iterator);
}
void CArrowDodgeBattle::_GetItemCallback(const CArrowDodgeItem* pItem_)
{
	pItem_->Proc(_pEngine->GetTick(), _pArrowDodgeBattlePlayer, this);
	_ItemIts.erase(pItem_->Iterator);
}
CArrowDodgeBattle::CArrowDodgeBattle(CUser* pUser_, TBattlesIt itBattle_) :
	CBattle(SBattleType(1, 1), g_MetaData->GetArrowDodgeMap()),
	_pArrowDodgeMap(static_cast<const SArrowDodgeMap*>(_pMap))
{
	// Structure /////////////////////////////////
	for (auto& s : _pArrowDodgeMap->Structures)
		_pEngine->AddObject(make_shared<CRectCollider2D>(s, CEngineGlobal::c_StructureNumber, s.RectCollider2D, _pRootObject.get()));

	// Players ////////////////////////////
	SPoint InitialPos(0.0f, 0.0f);
	auto pMeta = pUser_->GetSelectedChar();
	auto pCharacter = make_shared<SCharacter>(
		false,
		0,
		c_BalloonCountForRegen,
		SPumpInfo(),
		SParachuteInfo(),
		SStaminaInfo(_pEngine->GetTick(), pMeta->pCharacterTypeMeta->StaminaMax),
		CEngineGlobal::GetFaceWithX(InitialPos.X),
		CEngineGlobal::GetInvulnerableEndTick(_pEngine->GetTick()),
		0,
		0,
		0);

	_pArrowDodgeBattlePlayer = make_shared<CArrowDodgeBattlePlayer>(
		SBattlePlayer(
			pUser_->GetUID(),
			pUser_->GetNick(),
			pUser_->GetCountryCode(),
			0,
			pUser_->GetSelectedCharCode()),
		InitialPos,
		pMeta,
		pCharacter,
		itBattle_,
		pUser_,
		std::bind(&CArrowDodgeBattle::_HitArrowCallback, this, _1, _2),
		std::bind(&CArrowDodgeBattle::_GetItemCallback, this, _1),
		this);

	_pArrowDodgeBattlePlayer->pPlayerObject->SetParent(_pRootObject.get());
	_AddBattlePlayer(_pArrowDodgeBattlePlayer);

	pUser_->Send(GetArrowDodgeBattleBeginNetSc());
}
CArrowDodgeBattle::~CArrowDodgeBattle()
{
	_pArrowDodgeBattlePlayer->BattleEnd(_pEngine->GetTick());
}
SArrowDodgeBattleBeginNetSc CArrowDodgeBattle::GetArrowDodgeBattleBeginNetSc(void) const
{
	vector<SArrow> Arrows;
	for (auto& i : _ArrowIts)
		Arrows.emplace_back(i.GetSArrow());

	vector<SArrowDodgeItem> Items;
	for (auto& i : _ItemIts)
		Items.emplace_back(i.GetSArrowDodgeItem());

	return SArrowDodgeBattleBeginNetSc(
		SingleBattleBeginNetSc(
			*_pArrowDodgeBattlePlayer,
			_pArrowDodgeBattlePlayer->GetCharacterNet(),
			_pEngine->GetTick(),
			_FixedRandom.GetSeed(),
			_pEngine->IsStarted()),
		_pArrowDodgeBattlePlayer->BattleInfo,
		_pArrowDodgeBattlePlayer->Bufs,
		_ArrowMaker.GetNextDownArrowTick(),
		_ArrowMaker.GetNextLeftArrowTick(),
		_ArrowMaker.GetNextRightArrowTick(),
		_ItemMaker.GetNextItemTick(),
		std::move(Arrows),
		std::move(Items));
}
bool CArrowDodgeBattle::Update(void)
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
			_Send(0, SArrowDodgeBattleStartNetSc());
		}
	}
	else if (Now >= _EndTime)
	{
		return false;
	}

	return true;
}
void CArrowDodgeBattle::Link(int32 PlayerIndex_)
{
	_Send(PlayerIndex_, GetArrowDodgeBattleBeginNetSc());
}
void CArrowDodgeBattle::_UpdateScore(int32 AddedPoint_)
{
	_pArrowDodgeBattlePlayer->BattleInfo.Point += AddedPoint_;
}
void CArrowDodgeBattle::_AddArrow(const shared_ptr<CArrow>& pArrow_)
{
	pArrow_->SetParent(_pRootObject.get());
	auto ArrowIt = _pEngine->AddMovingObject(pArrow_);
	pArrow_->Iterator = _ArrowIts.emplace(SArrowObject(pArrow_.get(), ArrowIt));
}
void CArrowDodgeBattle::_RemoveArrow(CList<SArrowObject>::iterator ArrowObjectIt_)
{
	_pEngine->RemoveMovingObject(ArrowObjectIt_->ArrowIterator);
	_ArrowIts.erase(ArrowObjectIt_);
}
void CArrowDodgeBattle::_AddItem(const shared_ptr<CArrowDodgeItem>& pItem_)
{
	pItem_->SetParent(_pRootObject.get());
	_pEngine->AddObject(pItem_);
	pItem_->Iterator = _ItemIts.emplace(SArrowDodgeItemObject(pItem_.get()));
}
void CArrowDodgeBattle::_fixedUpdate()
{
	_ArrowMaker.FixedUpdate(_pEngine->GetTick(), *this, std::bind(&CArrowDodgeBattle::_AddArrow, this, _1));

	if (_ItemIts.size() < g_MetaData->arrowDodgeConfigMeta.maxItemCount)
		_ItemMaker.FixedUpdate(_pEngine->GetTick(), *this, std::bind(&CArrowDodgeBattle::_AddItem, this, _1));

	for (auto it = _ArrowIts.begin(); it;)
	{
		auto itCheck = it;
		++it;

		if (!itCheck->pArrow->FixedUpdate())
		{
			_RemoveArrow(itCheck);

			if (_pArrowDodgeBattlePlayer->IsAlive())
				_UpdateScore(g_MetaData->arrowDodgeConfigMeta.ArrowDodgePoint);
		}
	}
}
