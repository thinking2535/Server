#pragma once

#include "Battle.h"
#include <Rso/Physics/ShuttleObject2D.h>

class CMultiBattle : public CBattle
{
	// 팀 랭킹으로 정렬된 map의 value 타입으로 const STeamBattleInfo* 를 사용하여 중복 인스턴스 제거
	struct _STeamBattleInfo
	{
		const STeamBattleInfo* pTeamBattleInfo;
		TTeamIndexGroup TeamIndexGroup;

		_STeamBattleInfo(const STeamBattleInfo* pTeamBattleInfo_) :
			pTeamBattleInfo(pTeamBattleInfo_)
		{
		}
	};

	SBattleRecord _BattleRecord;
	shared_ptr<CObject2D> _pRootObject;
	vector<CShuttleObject2D*> _ShuttleStructures;
	const SBattleTypeInfo* _pBattleTypeInfo = nullptr;
	vector<shared_ptr<CMultiBattlePlayer>> _MultiBattlePlayers;
	set<int32> _DisconnectedPlayerIndices;
	int32 _MapIndex = 0;
	int64 _EndTick = 0;
	int32 _DisconnectedPlayerIndex = -1;

protected:
	void _AddBattlePlayer(const shared_ptr<CMultiBattlePlayer>& pBattlePlayer_);
private:
	void _HitCallback(int32 AttackerIndex_, int32 TargetIndex_);
	void _RegenCallback(int32 PlayerIndex_);
	void _IconCallback(int32 PlayerIndex_, const SMultiBattleIconNetCs& Proto_);
	void _FixedUpdate(int64 Tick_);
public:
	CMultiBattle(const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_, const TMatch::element_type::TMatchedUsers& Users_, TBattlesIt itBattle_);
	virtual ~CMultiBattle();
	bool _CanEngineStart(void) const override;
	const vector<SMultiMap>& GetMaps(void) const;
	int64 GetPlayTicks(void) const;

	template<typename _TProto>
	inline void Send(int32 PlayerIndex_, const _TProto& Proto_)
	{
		_BattlePlayers[PlayerIndex_]->Send(Proto_);
	}
	template<typename _TProto>
	void BroadCast(const _TProto& Proto_)
	{
		for (auto& i : _BattlePlayers)
			i->Send(Proto_);
	}
	template<typename _TProto>
	void BroadCastExcept(int32 ExceptPlayerIndex_, const _TProto& Proto_)
	{
		for (int32 i = 0; i < _BattlePlayers.size(); ++i)
		{
			if (i == ExceptPlayerIndex_)
				continue;

			_BattlePlayers[i]->Send(Proto_);
		}
	}
	vector<SCharacterNet> GetCharacters(void) const;
	vector<SStructMovePosition> GetStructMovePositions(void) const;
	SMultiBattleBeginNetSc GetBattleBeginNetSc(void) const;
	bool Update(void) override;
	void Link(int32 PlayerIndex_) override;
	void UnLink(int32 PlayerIndex_) override;
};
