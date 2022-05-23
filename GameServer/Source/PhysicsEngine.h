#pragma once

#include <Rso/Physics/ShuttleObject2D.h>

class CPhysicsEngine
{
public:
    using FMove = function<void(int32 PlayerIndex_, int8 Dir_)>;
    using FFace = function<void(int32 PlayerIndex_, int8 Dir_)>;
    using FFly = function<void(int32 PlayerIndex_)>;
    using FLand = function<void(int32 PlayerIndex_)>;
    using FFlap = function<void(int32 PlayerIndex_)>;
    using FPump = function<void(int32 PlayerIndex_)>;
    using FPumpDone = function<void(int32 PlayerIndex_)>;
    using FParachuteOn = function<void(int32 PlayerIndex_, bool On_)>;
    using FBounce = function<void(int32 PlayerIndex_)>;
    using FHit = function<void(int32 AttackerIndex_, int32 TargetIndex_, int32 AddedPoint_)>;
    using FRegen = function<void(int32 PlayerIndex_, const SCharacter& Character_)>;
    using FGetItem = function<void(int32 PlayerIndex_, int32 ItemCode_)>;

private:
    // 중요 !!! 서버의 CPhysicsEngine 처리 결과 콜백의 내용을 클라의 CPhysicsEngine으로 전달하는 프로토콜을 날리면 안됨
    const CEngineGameMode* _pGameMode = nullptr;
    FHit _fHit;
    FRegen _fRegen;
    FGetItem _fGetItem;
    SBattleRecord _BattleRecord;
    unique_ptr<CObject2D> _pRootObject;
public:
    const SBattleRecord& GetBattleRecord(void) const { return _BattleRecord; }
private:
    const TPoses& _PlayerPoses;
    unique_ptr<CServerEngine> _pEngine;
    vector<CEnginePlayer*> _EnginePlayers;
    vector<CShuttleObject2D*> _ShuttleStructures;

    void _HitCallback(const CEnginePlayer& Attacker_, const CEnginePlayer& Target_);
    void _RegenCallback(const CEnginePlayer& Player_);
    void _GetItemCallback(const CEnginePlayer& Player_, int32 ItemCode_);
public:
    CPhysicsEngine(
        const CEngineGameMode* pGameMode_,
        FHit fHit_,
        FRegen fRegen_,
        FGetItem fGetItem_,
        int64 CurTick_,
        SBattleRecord BattleRecord_,
        const SPoint& PropPosition_,
        const list<SStructure>& Structures_,
        const list<SStructureMove>& StructureMoves_,
        const TPoses& PlayerPoses_,
        const vector<const SCharacterMeta*>& Metas_,
        const vector<int8>& TeamIndices_,
        vector<unique_ptr<SCharacter>>&& Characters_,
        vector<CBattlePlayer*> BattlePlayers_,
        CServerEngine::FSyncMessage fSyncMessage_);
    inline int64 GetTick(void) { return _pEngine->GetTick(); }
    const CEngineGameMode* GetGameMode(void) const { return _pGameMode; }
    vector<SCharacterNet> GetCharacters(void) const;
    vector<SStructMovePosition> GetStructMovePositions(void) const;
    bool Touch(int32 PlayerIndex_, int8 Dir_);
    bool Push(int32 PlayerIndex_);
    void Link(int32 PlayerIndex_);
    void UnLink(int32 PlayerIndex_);
    void Update(void);
private:
    void _FixedUpdate(int64 Tick_);
};
