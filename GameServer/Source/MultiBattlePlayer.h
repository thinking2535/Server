#pragma once

class CMultiBattlePlayer : public CBattlePlayer
{
public:
	using FHit = function<void(int32 AttackerIndex_, int32 TargetIndex_)>;

private:
	FHit _fHit;
	FIcon _fIcon;
	CMultiBattle* _pMultiBattle;
public:
	milliseconds LeftMillisecondsToInvalidBattle = g_MetaData->pMultiBattleConfig->DisconnectableMilliseconds;
	TTime DisconnectEndTime; // 정상 종료시각을 고려할 필요 없음.
	SMultiBattleInfo BattleInfo;

	CMultiBattlePlayer(
		const SBattlePlayer Super_,
		FHit fHit_,
		FIcon fIcon_,
		const int32 PlayerIndex_,
		const SPoint& InitialPos_,
		const SCharacterMeta* const pMeta_,
		const int8 TeamIndex_,
		const shared_ptr<SCharacter>& pCharacter_,
		TBattlesIt itBattle_,
		CMultiBattle* pMultiBattle_,
		CUser* Player_);
	void Link(void) override;
	void UnLink(void) override;
	void Icon(const SMultiBattleIconNetCs& Proto_);
private:
	void _BattleEnd(const SBattleType& BattleType_, bool IsBestPlayer_);
public:
	void BattleEnd(
		TTime Now_,
		const SBattleType& BattleType_,
		bool IsBestPlayer_,
		const BattleEndInfo& battleEndInfo,
		int32 myTeamRanking,
		TDoneQuestDBs& DoneQuestDBs_);
	void BattleEndDraw(TTime Now_, const SBattleType& BattleType_, bool IsBestPlayer_, TDoneQuestDBs& DoneQuestDBs_);
	void BattleEndInvalid(TTime Now_);
	void BattleEndInvalidPunish(void);
	void Kill(int32 AddedPoint_);
	void AttackBalloon(int32 AddedPoint_);
protected:
	bool _CollisionEnter(int64 tick, const SCollision2D& Collision_) override;
};