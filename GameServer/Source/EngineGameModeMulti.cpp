#include "stdafx.h"

CEngineGameModeMulti::CEngineGameModeMulti(const SBattleType& BattleType_) :
    CEngineGameMode(BattleType_)
{
}
void CEngineGameModeMulti::FixPos(SPoint& Pos_) const
{
    // Fix X
    Pos_.X -= c_ScreenWidth_2;
    if (Pos_.X < 0.0f)
        Pos_.X += ((int32)(-Pos_.X / c_ScreenWidth) + 1) * c_ScreenWidth;
    Pos_.X = fmod(Pos_.X, c_ScreenWidth);
    Pos_.X += c_ScreenWidth_2;


    // Fix Y
    if (Pos_.Y < 0.0f)
        Pos_.Y += ((int32)(-Pos_.Y / c_ScreenHeight) + 1) * c_ScreenHeight;
    Pos_.Y = fmod(Pos_.Y, c_ScreenHeight);
}
const vector<SMultiMap>& CEngineGameModeMulti::GetMap(const SMapMeta& Map_) const
{
    return Map_.OneOnOneMaps;
}
