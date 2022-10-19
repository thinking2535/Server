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
	const SPoint* _pMap;
	shared_ptr<CObject2D> _pRootObject;
	SBattleType _BattleType;
	TTime _BeginTime = system_clock::now();
	vector<shared_ptr<CBattlePlayer>> _BattlePlayers;
	bool _IsStarted = false;

	void _SyncMessage();
	void _AddBattlePlayer(const shared_ptr<CBattlePlayer>& pBattlePlayer_);
	template<typename _TProto>
	void _Send(int32 playerIndex, const _TProto& Proto_)
	{
		_BattlePlayers[playerIndex]->Send(Proto_);
	}
	template<typename _TProto>
	void _BroadCast(const _TProto& Proto_)
	{
		for (auto& i : _BattlePlayers)
			i->Send(Proto_);
	}
	template<typename _TProto>
	void _BroadCastExcept(int32 ExceptPlayerIndex_, const _TProto& Proto_)
	{
		for (int32 i = 0; i < _BattlePlayers.size(); ++i)
		{
			if (i == ExceptPlayerIndex_)
				continue;

			_BattlePlayers[i]->Send(Proto_);
		}
	}

public:
	CBattle(const SBattleType& BattleType_, const SPoint* pMap_);
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
protected:
	virtual void _fixedUpdate() = 0;
};
