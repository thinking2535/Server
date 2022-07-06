#pragma once

class CArrowDodgeBattlePlayer : public CBattlePlayer
{
public:
	using FHitArrow = function<void(const shared_ptr<CArrow>& pArrow_, bool IsDefended_)>;
	using FGetItem = function<void(int64 Tick_, const shared_ptr<CArrowDodgeItem>& pItem_)>;

private:
	FHitArrow _fHitArrow;
	FGetItem _fGetItem;
public:
	CArrowDodgeBattle* pArrowDodgeBattle;
	SArrowDodgeBattleInfo BattleInfo;
	SArrowDodgeBattleBufs Bufs;

	CArrowDodgeBattlePlayer(
		const SBattlePlayer Super_,
		FRegen fRegen_,
		const SPoint& InitialPos_,
		const SCharacterMeta* const pMeta_,
		const shared_ptr<SCharacter>& pCharacter_,
		TBattlesIt itBattle_,
		CUser* Player_,
		FHitArrow fHitArrow_,
		FGetItem fGetItem_,
		CArrowDodgeBattle* pArrowDodgeBattle_);
	void BattleEnd(int64 Tick_);
protected:
	bool IsStaminaFree(void) const override;
	void _FixedUpdate(int64 Tick_) override;
	bool _CheckCollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_) override;
public:
	void SetItem(const SArrowDodgeItemMeta& Meta_);
	void SetShieldItem(int64 Tick_, const CArrowDodgeShield* pShield_);
	void SetStaminaItem(int64 Tick_, const CArrowDodgeStamina* pStamina_);
};
