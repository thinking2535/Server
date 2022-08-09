#include "stdafx.h"

void CBattle::_SyncMessage(int64 Tick_)
{
	BroadCast(SBattleSyncNetSc(Tick_));
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
	if (!_BattlePlayers[PlayerIndex_]->Touch(Proto_.Dir))
		return ERet::Ok;

	_pEngine->Send();
	BroadCast(SBattleTouchNetSc(_pEngine->GetTick(), PlayerIndex_, Proto_.Dir));

	return ERet::Ok;
}
ERet CBattle::Push(int32 PlayerIndex_, const SBattlePushNetCs& Proto_)
{
	if (!_pEngine->IsStarted())
		return ERet::Ok; // MultiBattle 에서는 게임도중 Engine.Stop 될 수 있고, 시간차로 유저가 Touch를 보낼 수 있으므로 Ok처리

	_pEngine->Update();
	if (!_BattlePlayers[PlayerIndex_]->Push(_pEngine->GetTick()))
		return ERet::Ok;

	_pEngine->Send();
	BroadCast(SBattlePushNetSc(_pEngine->GetTick(), PlayerIndex_));

	return ERet::Ok;
}

CBattle::CBattle(const SBattleType& BattleType_) :
	_pEngine(make_unique<CServerEngine>(
		c_NetworkTickSync,
		0,
		c_ContactOffset,
		c_FPS,
		std::bind(&CBattle::_SyncMessage, this, _1))),
	_BattleType(BattleType_)
{
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
