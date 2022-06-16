#pragma once

#include <queue>
#include <Rso/Physics/ServerEngine.h>

using namespace std;
using namespace rso;
using namespace gameutil;

class CBattle abstract
{
protected:
	unique_ptr<CServerEngine> _pEngine;
	SBattleType _BattleType;
	TTime _BeginTime = system_clock::now();
	vector<shared_ptr<CBattlePlayer>> _BattlePlayers;

	void _AddBattlePlayer(const shared_ptr<CBattlePlayer>& pBattlePlayer_);
protected:
	template<typename _TProto>
	void BroadCast(const _TProto& Proto_)
	{
		for (auto& i : _BattlePlayers)
			i->Send(Proto_);
	}

public:
	CBattle(unique_ptr<CServerEngine> pEngine_, const SBattleType& BattleType_);
	virtual ~CBattle();
	ERet Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_);
	ERet Push(int32 PlayerIndex_, const SBattlePushNetCs& Proto_);
	virtual bool Update(void);
	virtual void OnLine(int32 PlayerIndex_) = 0;
	virtual void OffLine(int32 PlayerIndex_) = 0;
	bool IsOneOnOne(void) const;
};
