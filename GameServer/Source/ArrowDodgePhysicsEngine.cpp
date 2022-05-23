#include "stdafx.h"

void CArrowDodgePhysicsEngine::_HitCallback(const CEnginePlayer& Attacker_, const CEnginePlayer& Target_)
{
}
void CArrowDodgePhysicsEngine::_RegenCallback(const CEnginePlayer& Player_)
{
}
void CArrowDodgePhysicsEngine::_GetItemCallback(const CEnginePlayer& Player_, int32 ItemCode_)
{
}

CArrowDodgePhysicsEngine::CArrowDodgePhysicsEngine(
    FHit fHit_,
    FGetItem fGetItem_,
    Int64 CurTick_,
    SPoint PropPosition_,
    const list<SStructure>& Structures_,
    const SCharacterMeta* pMeta_,
    unique_ptr<SCharacterNet> pCharacter_,
    CBattlePlayer* pBattlePlayer_,
    const list<SStructureMove>& Arrows_,
    CServerEngine::FSyncMessage fSyncMessage_) :
        _fHit(fHit_),
        _fGetItem(fGetItem_)
{

    // Structure /////////////////////////////////
    list<unique_ptr<CCollider2D>> StructureColliders;
    for (auto& s : Structures_)
        StructureColliders.emplace_back(make_unique<CRectCollider2D>(s.LocalPosition, CEngineGlobal::c_StructureNumber, s));

    _pRootObject = make_unique<CObject2D>(PropPosition_);

    list<unique_ptr<CMovingObject2D>> Arrows;

    //for (Int32 i = 0; i < Arrows_.Count; ++i)
    //{
    //    var s = StructureMoves_[i];
    //    var StructMovePosition = StructMovePositions_[i];

    //    var Colliders = new List<CCollider2D>();
    //    foreach (var c in s.Colliders)
    //        Colliders.Add(new CRectCollider2D(new SPoint(), CEngineGlobal.c_StructureNumber, c));

    //    var ShuttleObject = new CShuttleObject2D(
    //        StructMovePosition.LocalPosition,
    //        new CCollectionCollider2D(new SPoint(), CEngineGlobal.c_ContainerNumber, Colliders),
    //        s.BeginPos,
    //        s.EndPos,
    //        s.Velocity,
    //        s.Delay,
    //        StructMovePosition);
    //    ShuttleObject.SetParent(_RootObject);
    //    _MovingStructures.Add(ShuttleObject);
    //}

    auto pPlayer = CEngineGlobal::GetEnginePlayer(
        std::bind(&CArrowDodgePhysicsEngine::_HitCallback, this, _1, _2),
        std::bind(&CArrowDodgePhysicsEngine::_RegenCallback, this, _1),
        std::bind(&CArrowDodgePhysicsEngine::_GetItemCallback, this, _1, _2),
        0,
        PropPosition_,
        pMeta_,
        0,
        std::move(pCharacter_),
        pBattlePlayer_);

    vector<unique_ptr<CPlayerObject2D>> Players;
    Players.emplace_back(std::move(pPlayer));

    // Engine ////////////////////////////
    _pEngine = make_unique<CServerEngine>(
        c_NetworkTickSync,
        CurTick_,
        c_ContactOffset,
        c_FPS,
        make_unique<CCollectionCollider2D>(PropPosition_, CEngineGlobal::c_ContainerNumber, std::move(StructureColliders)),
        std::move(Arrows),
        std::move(Players),
        fSyncMessage_);

    _pEngine->OnFixedUpdate = std::bind(&CArrowDodgePhysicsEngine::_FixedUpdate, this, _1);
}
void CArrowDodgePhysicsEngine::Update()
{
    _pEngine->Update();
}
void CArrowDodgePhysicsEngine::_FixedUpdate(Int64 Tick_)
{
}
CEnginePlayer* CArrowDodgePhysicsEngine::GetEnginePlayer()
{
    return _pEnginePlayer.get();
}
