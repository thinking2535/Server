#pragma once

class CMultiBattlePlayer : public CBattlePlayer
{
public:
	using FHit = function<void(int32 AttackerIndex_, int32 TargetIndex_)>;

private:
	FHit _fHit;
	FIcon _fIcon;
public:
	SMultiBattleInfo BattleInfo;

	CMultiBattlePlayer(
		const SBattlePlayer Super_,
		FHit fHit_,
		FRegen fRegen_,
		FIcon fIcon_,
		const int32 PlayerIndex_,
		const SPoint& InitialPos_,
		const SCharacterMeta* const pMeta_,
		const int8 TeamIndex_,
		const shared_ptr<SCharacter>& pCharacter_,
		TBattlesIt itBattle_,
		CUser* Player_);
	void Icon(const SMultiBattleIconNetCs& Proto_);
	SBattleEndInfo BattleEnd(const vector<SBattleEndPlayer>& BattleEndPlayers_, const vector<STeamEndInfo>& TeamEndInfos_, bool BestPlayer_, TDoneQuestDBs& DoneQuestDBs_);
	void Kill(int32 AddedPoint_);
	void AttackBalloon(int32 AddedPoint_);
protected:
	bool _CheckCollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_) override;
};