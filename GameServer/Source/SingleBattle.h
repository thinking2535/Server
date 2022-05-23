#pragma once

#include <queue>

using namespace std;
using namespace rso;
using namespace gameutil;

class CSingleBattle sealed
{
	SBattleType _BattleType;
	const SBattleTypeInfo* _pBattleTypeInfo = nullptr;
	vector<CSingleBattlePlayer> _Players;
	TTeamBattleInfos _TeamBattleInfos; // for SBattleEndNetSc
	// ����� emplace ���� �߻����� �ʵ��� �����ڿ��� �Ҵ��ϱ� ���� ��������� ó�� ////
	vector<STeamEndInfo> _TeamEndInfos;
	vector<SBattleEndInfo> _BattleEndInfos; // for DB Push
	////////////////////////////////////////////////////////////////////////////////////
	int32 _UserCount = 0; // ����� �� ������ ������ ���� �ϱ� ����
	TTime _BeginTime = system_clock::now();
	TTime _StartTime;
	TTime _EndTime;
	CPeriod<milliseconds> _Period{ milliseconds(500) };
	int32 _RoomIdx = 0; //���� ���� �� ����� ������ ���� �� �ε��� ����.

	inline bool _IsStarted(void) const { return _EndTime > TTime(); }
	inline float _GetTime(const TTime& Now_) const { return (Now_ - _StartTime).count() / 10000000.0f; }
	inline float _GetTime(void) const { return _GetTime(system_clock::now()); }
	set<int32> SetBestPlayer(map<int32, list<TTeamCnt>, greater<int32>> PointTeamIndices_);
public:
	CSingleBattle(const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_, const TMatch::element_type::TMatchedUsers& Users_, int32 BattleIndex_, int32 RoomIdx_);
	~CSingleBattle();
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
	bool OffLine(int32 PlayerIndex_);
	ERet Icon(int32 PlayerIndex_, const SSingleBattleIconNetCs& Proto_);
	ERet Score(int32 PlayerIndex_, const SSingleBattleScoreNetCs& Proto_);
	ERet Item(int32 PlayerIndex_, const SSingleBattleItemNetCs& Proto_);
	void Link(int32 PlayerIndex_);
	void UnLink(int32 PlayerIndex_);
	bool Proc(void);
};
