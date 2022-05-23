#pragma once

#include <queue>
#include <Rso/Physics/ServerEngine.h>

using namespace std;
using namespace rso;
using namespace gameutil;

class CBattle sealed
{
	unique_ptr<CPhysicsEngine> _pEngine;
	SBattleType _BattleType;
	const SBattleTypeInfo* _pBattleTypeInfo = nullptr;
	vector<CBattlePlayer> _Players;
	int32 _MapIndex = 0;
	TTeamBattleInfos _TeamBattleInfos; // for SBattleEndNetSc
	// ����� emplace ���� �߻����� �ʵ��� �����ڿ��� �Ҵ��ϱ� ���� ��������� ó�� ////
	vector<STeamEndInfo> _TeamEndInfos;
	vector<SBattleEndInfo> _BattleEndInfos; // for DB Push
	////////////////////////////////////////////////////////////////////////////////////
	int32 _UserCount = 0; // ����� �� ������ ������ ���� �ϱ� ����
	TTime _BeginTime = system_clock::now();
	TTime _EndTime;
	int32 _RoomIdx = 0; //���� ���� �� ����� ������ ���� �� �ε��� ����.

	inline bool _IsStarted(void) const { return _EndTime > TTime(); }
	void _HitCallback(int32 AttackerIndex_, int32 TargetIndex_, int32 AddedPoint_);
	void _RegenCallback(int32 PlayerIndex_, const SCharacter& Character_);
	void _GetItemCallback(int32 PlayerIndex_, int32 ItemCode_);

public:
	CBattle(const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_, const TMatch::element_type::TMatchedUsers& Users_, int32 BattleIndex_, int32 RoomIdx_);
	~CBattle();
	template<typename _TProto>
	inline void Send(int32 PlayerIndex_, const _TProto& Proto_)
	{
		_Players[PlayerIndex_].Send(Proto_);
	}
	template<typename _TProto>
	void BroadCast(const _TProto& Proto_)
	{
		for (auto& i : _Players)
			i.Send(Proto_);
	}
	template<typename _TProto>
	void BroadCastExcept(int32 ExceptPlayerIndex_, const _TProto& Proto_)
	{
		for (int32 i = 0; i < _Players.size(); ++i)
		{
			if (i == ExceptPlayerIndex_)
				continue;

			_Players[i].Send(Proto_);
		}
	}
	SBattleBeginNetSc GetBattleBeginNetSc(void) const;
	void OnLine(int32 PlayerIndex_);
	bool OffLine(int32 PlayerIndex_);
	ERet Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_);
	ERet Push(int32 PlayerIndex_, const SBattlePushNetCs& Proto_);
	ERet Icon(int32 PlayerIndex_, const SBattleIconNetCs& Proto_);
	void Link(int32 PlayerIndex_);
	void UnLink(int32 PlayerIndex_);
	bool Proc(void);
private:
	void _SyncMessage(int64 Tick_);
};
