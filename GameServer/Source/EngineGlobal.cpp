#include "stdafx.h"

float CEngineGlobal::BalloonWidth(int8 BalloonCount_)
{
    if (BalloonCount_ > c_BalloonCountForRegen)
        BalloonCount_ = 2;
    else if (BalloonCount_ < 0)
        BalloonCount_ = 0;

    return c_BalloonWidth * BalloonCount_;
}
unique_ptr<CEngineGameMode> CEngineGlobal::GetGameModeMulti(const SBattleType& BattleType_)
{
    switch (BattleType_.GameMode)
    {
    case EGameMode::Solo:
        return unique_ptr<CEngineGameMode>(new CEngineGameModeMultiSolo(BattleType_));
        break;
    case EGameMode::SurvivalSmall:
        return unique_ptr<CEngineGameMode>(new CEngineGameModeMultiSurvivalSmall(BattleType_));
        break;
    case EGameMode::TeamSmall:
        return unique_ptr<CEngineGameMode>(new CEngineGameModeMultiTeamSmall(BattleType_));
        break;
    case EGameMode::Team:
        return unique_ptr<CEngineGameMode>(new CEngineGameModeMultiTeam(BattleType_));
        break;
    case EGameMode::Survival:
        return unique_ptr<CEngineGameMode>(new CEngineGameModeMultiSurvival(BattleType_));
        break;
    case EGameMode::IslandSolo:
        return unique_ptr<CEngineGameMode>(new CEngineGameModeMultiIslandSolo(BattleType_));
        break;
    case EGameMode::DodgeSolo:
        return unique_ptr<CEngineGameMode>(new CEngineGameModeMultiDodgeSolo(BattleType_));
        break;
    default:
        THROWEXA(L"Invalid TeamCount[%d]", (int)BattleType_.GameMode);
        break;
    }
}
unique_ptr<CEnginePlayer> CEngineGlobal::GetEnginePlayer(
    FHit fHit_,
    FRegen fRegen_,
    FGetItem fGetItem_,
    int32 PlayerIndex_,
    const SPoint& InitialPos_,
    const SCharacterMeta* pMeta_,
    int8 TeamIndex_,
    unique_ptr<SCharacter> pCharacter_,
    CBattlePlayer* pBattlePlayer_)
{
    list<unique_ptr<CCollider2D>> PlayerColliders;

    auto pBodyPtr = make_unique<CRectCollider2D>(SPoint(), CEngineGlobal::c_BodyNumber, CEngineGlobal::GetPlayerRect());
    auto pBody = pBodyPtr.get();
    PlayerColliders.emplace_back(std::move(pBodyPtr));

    auto pBalloonPtr = make_unique<CRectCollider2D>(SPoint(), CEngineGlobal::c_BalloonNumber, CEngineGlobal::GetBalloonRect(pCharacter_->BalloonCount));
    auto pBalloon = pBalloonPtr.get();
    PlayerColliders.emplace_back(std::move(pBalloonPtr));

    auto pParachutePtr = make_unique<CRectCollider2D>(SPoint(), CEngineGlobal::c_ParachuteNumber, CEngineGlobal::GetParachuteRect(pCharacter_->ParachuteInfo.Scale));
    auto pParachute = pParachutePtr.get();
    PlayerColliders.emplace_back(std::move(pParachutePtr));

    return make_unique<CEnginePlayer>(
        fHit_,
        fRegen_,
        fGetItem_,
        PlayerIndex_,
        InitialPos_,
        pMeta_,
        TeamIndex_,
        std::move(pCharacter_),
        make_unique<CCollectionCollider2D>(SPoint(), CEngineGlobal::c_ContainerNumber, std::move(PlayerColliders)),
        pBody, pBalloon, pParachute, pBattlePlayer_);
}
