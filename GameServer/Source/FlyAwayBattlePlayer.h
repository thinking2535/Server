#pragma once

class CFlyAwayBattlePlayer : public CBattlePlayer
{
public:
	using FGetItem = function<void(const CFlyAwayItem* pItem_)>;
	using FLand = function<void(const CFlyAwayLand* pLand_)>;
	using FDead = function<void()>;

private:
	FGetItem _fGetItem;
	FLand _fLand;
	FDead _fDead;
public:
	CFlyAwayBattle* pFlyAwayBattle;
	SFlyAwayBattleInfo BattleInfo;

	CFlyAwayBattlePlayer(
		const SBattlePlayer Super_,
		const SPoint& InitialPos_,
		const SCharacterMeta* const pMeta_,
		const shared_ptr<SCharacter>& pCharacter_,
		TBattlesIt itBattle_,
		CUser* Player_,
		FGetItem fGetItem_,
		FLand fLand_,
		FDead fDead,
		CFlyAwayBattle* pFlyAwayBattle_);
	void Link(void) override;
	void BattleEnd(int64 tick);
protected:
	void _FixedUpdate(int64 tick) override;
	bool _CollisionEnter(int64 tick, const SCollision2D& Collision_) override;
	bool _CollisionStay(int64 tick, const SCollision2D& Collision_) override;
	bool _CollisionExit(int64 tick, const SCollision2D& Collision_) override;
	bool _TriggerEnter(const CCollider2D* pCollider_) override;
public:
	void SetItem(const SFlyAwayItemMeta& Meta_);
	void addStamina(float stamina);
};
