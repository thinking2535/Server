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
	bool _IsStarted = false;

	void _SyncMessage(int64 Tick_);
	void _AddBattlePlayer(const shared_ptr<CBattlePlayer>& pBattlePlayer_);
	template<typename _TProto>
	void BroadCast(const _TProto& Proto_)
	{
		for (auto& i : _BattlePlayers)
			i->Send(Proto_);
	}

public:
	CBattle(const SBattleType& BattleType_);
	virtual ~CBattle();
protected:
	virtual bool _CanEngineStart(void) const;
	void _CheckAndStartEngine(void);
public:
	virtual ERet Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_);
	ERet Push(int32 PlayerIndex_, const SBattlePushNetCs& Proto_);
	virtual bool Update(void);
	virtual void Link(int32 PlayerIndex_);
	virtual void UnLink(int32 PlayerIndex_);
};
