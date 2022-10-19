#include "stdafx.h"

void CBattle::_SyncMessage()
{
	_BroadCast(SBattleSyncNetSc(_pEngine->GetTick()));
}
void CBattle::_AddBattlePlayer(const shared_ptr<CBattlePlayer>& pBattlePlayer_)
{
	_BattlePlayers.emplace_back(pBattlePlayer_);
	_pEngine->AddPlayer(pBattlePlayer_->pPlayerObject);
}
ERet CBattle::Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_)
{
	if (!_pEngine->IsStarted())
		return ERet::Ok; // MultiBattle 에서는 게임도중 Engine.Stop 될 수 있고, 시간차로 유저가 Touch를 보낼 수 있으므로 Ok처리

	_pEngine->Update();

	if (!_BattlePlayers[PlayerIndex_]->touch(Proto_.Dir))
		return ERet::Ok;

	_pEngine->Send();
	_BroadCast(SBattleDirectNetSc(_pEngine->GetTick(), PlayerIndex_, Proto_.Dir));

	return ERet::Ok;
}
ERet CBattle::Push(int32 PlayerIndex_, const SBattlePushNetCs& Proto_)
{
	if (!_pEngine->IsStarted())
		return ERet::Ok; // MultiBattle 에서는 게임도중 Engine.Stop 될 수 있고, 시간차로 유저가 Touch를 보낼 수 있으므로 Ok처리

	_pEngine->Update();

	auto pushType = _BattlePlayers[PlayerIndex_]->push(_pEngine->GetTick());
	if (pushType == CBattlePlayer::PushType::null)
		return ERet::Ok;

	_pEngine->Send();

	switch (pushType)
	{
	case CBattlePlayer::PushType::flap:
		_BroadCast(SBattleFlapNetSc(_pEngine->GetTick(), PlayerIndex_));
		break;

	case CBattlePlayer::PushType::pump:
		_BroadCast(SBattlePumpNetSc(_pEngine->GetTick(), PlayerIndex_));
		break;

	default:
		throw 0;
	}

	return ERet::Ok;
}

CBattle::CBattle(const SBattleType& BattleType_, const SPoint* pMap_) :
	_pEngine(make_unique<CServerEngine>(
		0,
		c_ContactOffset,
		c_FPS,
		std::bind(&CBattle::_SyncMessage, this),
		c_NetworkTickSync)),
	_BattleType(BattleType_)
{
	_pEngine->fFixedUpdate = std::bind(&CBattle::_fixedUpdate, this);
	_pMap = pMap_;
	_pRootObject = make_shared<CObject2D>(GetDefaultTransform(*_pMap));
}
CBattle::~CBattle()
{
}
bool CBattle::_CanEngineStart(void) const
{
	return _IsStarted;
}
void CBattle::_CheckAndStartEngine(void)
{
	if (!_CanEngineStart())
		return;

	_pEngine->Start();
}
bool CBattle::Update(void)
{
	if (!_pEngine->IsStarted())
		return true;

	_pEngine->UpdateAndSyncMessage();

	return true;
}
void CBattle::Link(int32 PlayerIndex_)
{
}
void CBattle::UnLink(int32 PlayerIndex_)
{
}
