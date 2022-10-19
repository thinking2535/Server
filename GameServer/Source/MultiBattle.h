#pragma once

#include "Battle.h"
#include <Rso/Physics/ShuttleObject2D.h>

class CMultiBattle : public CBattle
{
	const SMultiMap* _pMultiMap;
	SBattleRecord _BattleRecord;
	vector<CShuttleObject2D*> _ShuttleStructures;
	vector<shared_ptr<CMultiBattlePlayer>> _MultiBattlePlayers;
	set<int32> _DisconnectedPlayerIndices;
	int64 _EndTick = 0;
	int32 _DisconnectedPlayerIndex = -1;

protected:
	void _AddBattlePlayer(const shared_ptr<CMultiBattlePlayer>& pBattlePlayer_);
private:
	void _HitCallback(int32 AttackerIndex_, int32 TargetIndex_);
	void _IconCallback(int32 PlayerIndex_, const SMultiBattleIconNetCs& Proto_);
public:
	CMultiBattle(const SBattleType& BattleType_, const TMatch::element_type::TMatchedUsers& Users_, TBattlesIt itBattle_);
	virtual ~CMultiBattle();
	bool _CanEngineStart(void) const override;
	const vector<SMultiMap>& GetMaps(void) const;
	int64 GetPlayTicks(void) const;
	vector<SCharacterNet> GetCharacters(void) const;
	vector<SStructMovePosition> GetStructMovePositions(void) const;
	SMultiBattleBeginNetSc GetBattleBeginNetSc(void) const;
	bool Update(void) override;
	void Link(int32 PlayerIndex_) override;
	void UnLink(int32 PlayerIndex_) override;
protected:
	void _fixedUpdate() override;
};
