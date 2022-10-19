#pragma once

#include "BattlePlayerObject.h"
#include "PlayerCollider.h"
#include "EnginePumpControl.h"
#include "EngineParachuteControl.h"

using FIcon = function<void(int32 PlayerIndex_, const SMultiBattleIconNetCs& Proto_)>;

class CBattlePlayer : public SBattlePlayer
{
public:
	enum class PushType
	{
		flap,
		pump,
		max,
		null
	};

	const int32 PlayerIndex;
	const SPoint InitialPos;
	const SCharacterMeta* const pMeta;
	const int8 TeamIndex;
	const shared_ptr<SCharacter> pCharacter;
	const TBattlesIt itBattle;
	CUser* const pPlayer = nullptr;
protected:
	TQuests _DoneQuests; // 전투중 완료한 퀘스트
	CPlayerCollider _PlayerCollider;
public:
	shared_ptr<CPlayerObject2D> pPlayerObject; // _PlayerCollider 아래에 위치하도록
	inline SCharacterNet GetCharacterNet(void) { return SCharacterNet(*pCharacter, pPlayerObject->LocalPosition, pPlayerObject->Velocity); }
private:
	unordered_set<const CCollider2D*> _AttachedGrounds;
	CEnginePumpControl _PumpControl;
	CEngineParachuteControl _ParachuteControl;

	void _PumpCallback(void);
	void _PumpDoneCallback(void);
	void _ParachuteOnCallback(bool On_);
protected:
	void _AttachGround(const CCollider2D* pOtherCollider_);
	void _DetachGround(const CCollider2D* pOtherCollider_);
public:
	void bounce(const SCollision2D& collision);
	void Die(int64 tick);
protected:
	void _Die(int64 tick);
	bool _beHitBalloon(const SPoint& Normal_);
	bool _LandEnter(const SCollision2D& Collision_);
	virtual bool _CollisionEnter(int64 tick, const SCollision2D& Collision_);
	virtual void _LandStay(const SCollision2D& Collision_);
	virtual bool _CollisionStay(int64 tick, const SCollision2D& Collision_);
	virtual bool _CollisionExit(int64 tick, const SCollision2D& Collision_);
	virtual bool _TriggerEnter(const CCollider2D* pCollider_);
	virtual void _FixedUpdate(int64 tick);
	virtual void _UpdateStamina(int64 tick);
	void _UpdateGroundPhysics(const CMovingObject2D* pOtherMovingObject_);
	void _UpdatePhysics();
private:
	void _updateXVelocityInAir();
	void _updateYVelocityInAir();
	void _approximateAirXVelocity(float value);
public:
	bool IsInvulerable(int64 tick);
	bool IsAlive(void) const;
protected:
	virtual bool IsStaminaFree(void) const
	{
		return false;
	}
public:
	bool touch(int8 dir);
	void direct(int8 dir);
	PushType push(int64 tick);
	void flap(int64 tick);
	void pump();
	void CheckRegen(int64 tick);

	CBattlePlayer(
		const SBattlePlayer Super_,
		const int32 PlayerIndex_,
		const SPoint& InitialPos_,
		const SCharacterMeta* const pMeta_,
		const int8 TeamIndex_,
		const shared_ptr<SCharacter>& pCharacter_,
		TBattlesIt itBattle_,
		CUser* Player_,
		CBattlePlayer* pVirtualBattlePlayer_);
	virtual ~CBattlePlayer();
	virtual void Link(void);
	virtual void UnLink(void);
	ERet Touch(const SBattleTouchNetCs& Proto_);
	ERet Push(const SBattlePushNetCs& Proto_);
	template<typename _TProto>
	void Send(const _TProto& Proto_) { pPlayer->Send(Proto_); }
	bool WillClose(void) { return pPlayer->WillClose(); }
	inline int32 GetPoint(void) const { return pPlayer->GetPoint(); }
	inline const u16string& GetNick(void) const { return pPlayer->GetNick(); }
	CUser* GetUser() { return pPlayer; }
	void QuestDone(EQuestType QuestType_, int32 Count_);
};
