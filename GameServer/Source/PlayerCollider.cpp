#include "stdafx.h"

CPlayerCollider::CPlayerCollider(const SCharacter* pCharacter_)
{
    list<shared_ptr<CCollider2D>> PlayerColliders;

    pBody = make_shared<CRectCollider2D>(
        ZeroTransform,
        CEngineGlobal::c_BodyNumber,
        CEngineGlobal::GetPlayerRect());
    PlayerColliders.emplace_back(pBody);

    pBalloon = make_shared<CRectCollider2D>(
        STransform(
            SPoint(),
            SPoint3(),
            SPoint(c_BalloonLocalScale, c_BalloonLocalScale)),
        CEngineGlobal::c_BalloonNumber,
        CEngineGlobal::GetBalloonRect(pCharacter_->BalloonCount));
    PlayerColliders.emplace_back(pBalloon);

    pParachute = make_shared<CRectCollider2D>(
        STransform(
            SPoint(),
            SPoint3(),
            SPoint(pCharacter_->ParachuteInfo.Scale, pCharacter_->ParachuteInfo.Scale)),
        CEngineGlobal::c_ParachuteNumber,
        CEngineGlobal::GetParachuteRect());
    PlayerColliders.emplace_back(pParachute);

    pPlayer = make_shared<CCollectionCollider2D>(ZeroTransform, CEngineGlobal::c_ContainerNumber);
    SetCollectionToCollectionCollider2D(PlayerColliders, pPlayer);
}