#pragma once

class CArrowDodgePhysicsEngine
{
public:
    using FHit = function<void()>;
    using FGetItem = function<void(int32 ItemCode_)>;

private:
    FHit _fHit;
    FGetItem _fGetItem;

    unique_ptr<CServerEngine> _pEngine;
    unique_ptr<CEnginePlayer> _pEnginePlayer;
    unique_ptr<CObject2D> _pRootObject;

    void _HitCallback(const CEnginePlayer& Attacker_, const CEnginePlayer& Target_);
    void _RegenCallback(const CEnginePlayer& Player_);
    void _GetItemCallback(const CEnginePlayer& Player_, int32 ItemCode_);
public:
    CArrowDodgePhysicsEngine(
        FHit fHit_,
        FGetItem fGetItem_,
        Int64 CurTick_,
        SPoint PropPosition_,
        const list<SStructure>& Structures_,
        const SCharacterMeta* pMeta_,
        unique_ptr<SCharacterNet> pCharacter_,
        CBattlePlayer* pBattlePlayer_,
        const list<SStructureMove>& Arrows_,
        CServerEngine::FSyncMessage fSyncMessage_);
    void Update();
private:
    void _FixedUpdate(Int64 Tick_);
public:
    CEnginePlayer* GetEnginePlayer(void);
};