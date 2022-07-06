#pragma once

#include "BalloonHitControl.h"
#include "BattlePlayerObject.h"
#include "PlayerCollider.h"
#include "EnginePumpControl.h"
#include "EngineParachuteControl.h"

using FIcon = function<void(int32 PlayerIndex_, const SMultiBattleIconNetCs& Proto_)>;

class CBattlePlayer : public SBattlePlayer
{
public:
	using FRegen = function<void(int32 PlayerIndex_)>;

private:
	FRegen _fRegen;
public:
	const int32 PlayerIndex;
	const SPoint InitialPos;
	const SCharacterMeta* const pMeta;
	const int8 TeamIndex;
	const shared_ptr<SCharacter> pCharacter;
	const TBattlesIt itBattle;
	CUser* const pPlayer = nullptr;
protected:
	CBalloonHitControl _BalloonHitControl;
	TQuests _DoneQuests; // ������ �Ϸ��� ����Ʈ
	CPlayerCollider _PlayerCollider;
public:
	shared_ptr<CPlayerObject2D> pPlayerObject; // _PlayerCollider �Ʒ��� ��ġ�ϵ���
	inline SCharacterNet GetCharacterNet(void) { return SCharacterNet(*pCharacter, pPlayerObject->LocalPosition, pPlayerObject->Velocity); }
private:
	unordered_set<shared_ptr<CCollider2D>> _AttachedGrounds;
	CEnginePumpControl _PumpControl;
	CEngineParachuteControl _ParachuteControl;

	void _PumpCallback(void);
	void _PumpDoneCallback(void);
	void _ParachuteOnCallback(bool On_);
protected:
	void _AttachGround(const shared_ptr<CCollider2D>& pOtherCollider_);
	void _DetachGround(const shared_ptr<CCollider2D>& pOtherCollider_);
public:
	void Bounce(const SPoint& Normal_);
	void Die(int64 Tick_);
protected:
	void _Die(int64 Tick_);
	bool _HitBalloon(int64 Tick_, const SPoint& Normal_);
	void _SetLandingVelocity(const shared_ptr<CMovingObject2D>& pOtherMovingObject_);
protected:
	virtual bool _CheckCollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_);
private:
	void _CollisionEnter(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_);
protected:
	virtual bool _CheckCollisionStay(const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_);
private:
	void _CollisionStay(int64 Tick_, const SPoint& Normal_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_);
protected:
	virtual bool _CheckCollisionExit(const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_);
private:
	void _CollisionExit(int64 Tick_, const shared_ptr<CCollider2D>& pCollider_, const shared_ptr<CCollider2D>& pOtherCollider_, const shared_ptr<CMovingObject2D>& pOtherMovingObject_);
protected:
	virtual void _FixedUpdate(int64 Tick_);
	virtual void _UpdateStamina(int64 Tick_);
	virtual void _UpdatePhysics(int64 Tick_);
public:
	bool IsInvulerable(int64 Tick_);
	bool IsAlive(void) const;
	bool Touch(int8 Dir_);
protected:
	virtual bool IsStaminaFree(void) const
	{
		return false;
	}
public:
	bool Push(int64 Tick_);
	void Link(int64 Tick_);
	void UnLink(int64 Tick_);
	void CheckRegen(int64 Tick_);

	CBattlePlayer(
		const SBattlePlayer Super_,
		FRegen fRegen_,
		const int32 PlayerIndex_,
		const SPoint& InitialPos_,
		const SCharacterMeta* const pMeta_,
		const int8 TeamIndex_,
		const shared_ptr<SCharacter>& pCharacter_,
		TBattlesIt itBattle_,
		CUser* Player_,
		CBattlePlayer* pVirtualBattlePlayer_);
	void OnLine(void);
	void OffLine(void);
	ERet Touch(const SBattleTouchNetCs& Proto_);
	ERet Push(const SBattlePushNetCs& Proto_);
	void BattleEnd(void);
	template<typename _TProto>
	void Send(const _TProto& Proto_) { pPlayer->Send(Proto_); }
	bool WillClose(void) { return pPlayer->WillClose(); }
	inline int32 GetPoint(void) const { return pPlayer->GetPoint(); }
	inline const u16string& GetNick(void) const { return pPlayer->GetNick(); }
	CUser* GetUser() { return pPlayer; }
	void QuestDone(EQuestType QuestType_, int32 Count_);
};
