#include "stdafx.h"

void CBattle::_AddBattlePlayer(const shared_ptr<CBattlePlayer>& pBattlePlayer_)
{
	_BattlePlayers.emplace_back(pBattlePlayer_);
	_pEngine->AddPlayer(pBattlePlayer_->pPlayerObject);
}
ERet CBattle::Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_)
{
	if (!_pEngine->IsStarted())
		return ERet::InvalidProtocol;

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
		return ERet::InvalidProtocol;

	_pEngine->Update();
	if (!_BattlePlayers[PlayerIndex_]->Push(_pEngine->GetTick()))
		return ERet::Ok;

	_pEngine->Send();
	BroadCast(SBattlePushNetSc(_pEngine->GetTick(), PlayerIndex_));

	return ERet::Ok;
}

CBattle::CBattle(unique_ptr<CServerEngine> pEngine_, const SBattleType& BattleType_) :
	_pEngine(std::move(pEngine_)),
	_BattleType(BattleType_)
{
}
CBattle::~CBattle()
{
}
bool CBattle::Update(void)
{
	if (!_pEngine->IsStarted())
		return true;

	_pEngine->UpdateAndSyncMessage();

	return true;
}
bool CBattle::IsOneOnOne(void) const
{
	return _BattleType.TeamCount == 1 && _BattleType.TeamMemberCount == 1;
}
