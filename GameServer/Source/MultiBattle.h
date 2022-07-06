#pragma once

#include "Battle.h"
#include <Rso/Physics/ShuttleObject2D.h>

class CMultiBattle : public CBattle
{
	SBattleRecord _BattleRecord;
	shared_ptr<CObject2D> _pRootObject;
	vector<CShuttleObject2D*> _ShuttleStructures;
	const SBattleTypeInfo* _pBattleTypeInfo = nullptr;
	vector<shared_ptr<CMultiBattlePlayer>> _MultiBattlePlayers;
	int32 _MapIndex = 0;
	// 종료시 emplace 에러 발생하지 않도록 생성자에서 할당하기 위해 멤버변수로 처리 ////
	////////////////////////////////////////////////////////////////////////////////////
	TTime _EndTime;

protected:
	void _AddBattlePlayer(const shared_ptr<CMultiBattlePlayer>& pBattlePlayer_);
private:
	void _HitCallback(int32 AttackerIndex_, int32 TargetIndex_);
	void _RegenCallback(int32 PlayerIndex_);
	void _GetItemCallback(int32 PlayerIndex_, int32 ItemCode_);
	void _IconCallback(int32 PlayerIndex_, const SMultiBattleIconNetCs& Proto_);
	void _FixedUpdate(int64 Tick_);
public:
	CMultiBattle(const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_, const TMatch::element_type::TMatchedUsers& Users_, TBattlesIt itBattle_);
	virtual ~CMultiBattle();
	const vector<SMultiMap>& GetMaps(void) const;
	seconds GetPlaySeconds(void) const;

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
	void OnLine(int32 PlayerIndex_) override;
	void OffLine(int32 PlayerIndex_) override;
	void Link(int32 PlayerIndex_);
	void UnLink(int32 PlayerIndex_);
};
