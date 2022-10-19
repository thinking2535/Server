#pragma once

class CArrowDodgeBattlePlayer : public CBattlePlayer
{
public:
	using FHitArrow = function<void(const CArrow* pArrow_, bool IsDefended_)>;
	using FGetItem = function<void(const CArrowDodgeItem* pItem_)>;

private:
	FHitArrow _fHitArrow;
	FGetItem _fGetItem;
public:
	CArrowDodgeBattle* pArrowDodgeBattle;
	SArrowDodgeBattleInfo BattleInfo;
	SArrowDodgeBattleBufs Bufs;

	CArrowDodgeBattlePlayer(
		const SBattlePlayer Super_,
		const SPoint& InitialPos_,
		const SCharacterMeta* const pMeta_,
		const shared_ptr<SCharacter>& pCharacter_,
		TBattlesIt itBattle_,
		CUser* Player_,
		FHitArrow fHitArrow_,
		FGetItem fGetItem_,
		CArrowDodgeBattle* pArrowDodgeBattle_);
	void Link(void) override;
	void BattleEnd(int64 tick);
protected:
	bool IsStaminaFree(void) const override;
	void _FixedUpdate(int64 tick) override;
	bool _CollisionEnter(int64 tick, const SCollision2D& Collision_) override;
	bool _TriggerEnter(const CCollider2D* pCollider_) override;
public:
	void SetItem(const SArrowDodgeItemMeta& Meta_);
	void SetShieldItem(int64 tick, const CArrowDodgeShield* pShield_);
	void SetStaminaItem(int64 tick, const CArrowDodgeStamina* pStamina_);
};
