#include "stdafx.h"

CPlayerCollider::CPlayerCollider(const SCharacter* pCharacter_)
{
    pBody = make_shared<CRectCollider2D>(
        ZeroTransform,
        CEngineGlobal::c_BodyNumber,
        CEngineGlobal::GetPlayerRect());
    Colliders.emplace_back(pBody);

    pBalloon = make_shared<CRectCollider2D>(
        STransform(
            SPoint(),
            SPoint3(),
            SPoint(c_BalloonLocalScale, c_BalloonLocalScale)),
        CEngineGlobal::c_BalloonNumber,
        CEngineGlobal::GetBalloonRect(pCharacter_->BalloonCount));
    Colliders.emplace_back(pBalloon);

    pParachute = make_shared<CRectCollider2D>(
        STransform(
            SPoint(),
            SPoint3(),
            SPoint(pCharacter_->ParachuteInfo.Scale, pCharacter_->ParachuteInfo.Scale)),
        CEngineGlobal::c_ParachuteNumber,
        CEngineGlobal::GetParachuteRect());
    Colliders.emplace_back(pParachute);
}