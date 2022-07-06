#pragma once

class CFlyAwayBattlePlayer : public CBattlePlayer
{
public:
	using FGetItem = function<void(int64 Tick_, const shared_ptr<CFlyAwayItem>& pItem_)>;
	using FLand = function<void(int64 Tick_, const shared_ptr<CFlyAwayLand>& pLand_)>;

private:
	FGetItem _fGetItem;
	FLand _fLand;
public:
	CFlyAwayBattle* pFlyAwayBattle;
	SFlyAwayBattleInfo BattleInfo;

	CFlyAwayBattlePlayer(
		const SBattlePlayer Super_,
		FRegen fRegen_,
		const SPoint& InitialPos_,
		const SCharacterMeta* const pMeta_,
		const shared_ptr<SCharacter>& pCharacter_,
		TBattlesIt itBattle_,
		CUser* Player_,
		FGetItem fGetItem_,
		FLand fLand_,
		CFlyAwayBattle* pFlyAwayBattle_);
	void BattleEnd(int64 Tick_);
protected:
	void _FixedUpdate(int64 Tick_) override;
	bool _CheckCollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_) override;
	bool _CheckCollisionStay(const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_) override;
	bool _CheckCollisionExit(const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_) override;
public:
	void SetItem(const SFlyAwayItemMeta& Meta_);
};
