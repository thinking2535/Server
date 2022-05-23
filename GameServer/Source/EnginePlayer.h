#pragma once

#include <functional>
#include <unordered_set>
#include <Rso/Physics/Collider2D.h>
#include <Rso/Physics/PlayerObject2D.h>
#include <Rso/Physics/RectCollider2D.h>

using namespace std;
using namespace rso;
using namespace physics;

class CEnginePlayer : public CPlayerObject2D
{
    FHit _fHit;
    FRegen _fRegen;
    FGetItem _fGetItem;

    int32 _PlayerIndex = 0;
    SPoint _InitialPos;
public:
    inline int32 GetPlayerIndex(void) const { return _PlayerIndex; }
private:
    const SCharacterMeta* _pMeta;
    int8 _TeamIndex;
    unique_ptr<SCharacter> _pCharacter;
public:
    inline const SCharacterMeta* GetMeta(void) const { return _pMeta; }
    inline int8 GetTeamIndex(void) const { return _TeamIndex; }
    inline const SCharacter* Character(void) const { return _pCharacter.get(); }
    inline SCharacter* Character(void) { return _pCharacter.get(); }
    inline SCharacterNet GetCharacterNet(void) { return SCharacterNet(*Character(), LocalPosition, Velocity); }
private:
    unordered_set<CCollider2D*> _AttachedGrounds;
    CEnginePumpControl _PumpControl;
    CEngineParachuteControl _ParachuteControl;
    CRectCollider2D* _pBody;
    CRectCollider2D* _pBalloon;
    CRectCollider2D* _pParachute;
    CBattlePlayer* _pBattlePlayer;

    void _PumpCallback(void);
    void _PumpDoneCallback(void);
    void _ParachuteOnCallback(bool On_);
    void _AttachGround(CCollider2D* pOtherCollider_);
    void _DetachGround(CCollider2D* pOtherCollider_);
    void _Bounce(const SPoint& Normal_);
public:
    CEnginePlayer(
        FHit fHit_,
        FRegen fRegen_,
        FGetItem fGetItem_,
        int32 PlayerIndex_,
        const SPoint& Pos_,
        const SCharacterMeta* pMeta_,
        int8 TeamIndex_,
        unique_ptr<SCharacter> pCharacter_,
        unique_ptr<CCollider2D> pPlayerCollider_,
        CRectCollider2D* pBody_,
        CRectCollider2D* pBalloon_,
        CRectCollider2D* pParachute_,
        CBattlePlayer* pBattlePlayer_);
private:
    void _Hit(int64 Tick_, const SPoint& Normal_, CEnginePlayer* pAttacker_);
    void _SetLandingVelocity(CMovingObject2D* pOtherMovingObject_);
public:
    void OnCollisionEnter(int64 Tick_, const SPoint& Normal_, CCollider2D* pCollider_, CCollider2D* pOtherCollider_, CMovingObject2D* pOtherMovingObject_) override;
    void OnCollisionStay(int64 Tick_, const CPlayerObject2D::TContactPoint2Ds& ContactPoint2Ds_) override;
    void OnCollisionExit(int64 Tick_, const SPoint& Normal_, CCollider2D* pCollider_, CCollider2D* pOtherCollider_, CMovingObject2D* pOtherMovingObject_) override;
    bool IsAlive(void) const;
    bool Touch(int8 Dir_);
    bool Push(int64 Tick_);
    void Link(int64 Tick_);
    void UnLink(int64 Tick_);
    void CheckRegen(int64 Tick_);
    void FixedUpdate(int64 Tick_) override;
};
