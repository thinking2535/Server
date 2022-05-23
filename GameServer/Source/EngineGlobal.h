#pragma once

using FHit = function<void(const CEnginePlayer& Attacker_, const CEnginePlayer& Target_)>;
using FRegen = function<void(const CEnginePlayer& Player_)>;
using FGetItem = function<void(const CEnginePlayer& Player_, int32 ItemCode_)>;

class CEngineGlobal
{
public:
    static const int32 c_ContainerNumber = 0;
    static const int32 c_StructureNumber = 1;
    static const int32 c_BodyNumber = 2;
    static const int32 c_BalloonNumber = 3;
    static const int32 c_ParachuteNumber = 4;

    static inline bool IsAlive(const SCharacter& Char_) { return (Char_.BalloonCount >= 0); }
    static inline bool IsInvulerable(const SCharacter& Char_, int64 Tick_) { return (Tick_ < Char_.InvulnerableEndTick); }
    static inline int8 GetFace(const SPoint& Pos_) { return (Pos_.X < c_ScreenCenterX ? 1 : -1); }
    static inline int64 GetInvulnerableEndTick(int64 Tick_) { return (Tick_ + g_GameData->ConfigMeta.InvulnerableDurationSec * 10000000); }
    inline static SRectCollider2D GetPlayerRect(void) { return SRectCollider2D(SPoint(c_PlayerWidth, c_PlayerHeight), SPoint(0.0f, c_PlayerOffsetY), SPoint(1.0f, 1.0f)); }
    static float BalloonWidth(int8 BalloonCount_);
    inline static SPoint GetBalloonSize(int8 BalloonCount_) { return SPoint(BalloonWidth(BalloonCount_), c_BalloonHeight); }
    inline static SRectCollider2D GetBalloonRect(int8 BalloonCount_) { return SRectCollider2D(GetBalloonSize(BalloonCount_), SPoint(0.0f, c_BalloonOffsetY), SPoint(c_BalloonLocalScale, c_BalloonLocalScale)); }
    inline static SRectCollider2D GetParachuteRect(float Scale_) { return SRectCollider2D(SPoint(c_ParachuteWidth, c_ParachuteHeight), SPoint(0.0f, c_ParachuteOffsetY), SPoint(Scale_, Scale_)); }
    inline static bool IsScaling(const SPumpInfo& PumpInfo_) { return (PumpInfo_.Count < PumpInfo_.CountTo); }
    inline static bool IsScaling(const SParachuteInfo& ParachuteInfo_) { return (ParachuteInfo_.Velocity != 0.0f || (ParachuteInfo_.Scale > 0.0f && ParachuteInfo_.Scale < c_ParachuteLocalScale)); }
    static unique_ptr<CEngineGameMode> GetGameModeMulti(const SBattleType& BattleType_);
    static unique_ptr<CEnginePlayer> GetEnginePlayer(
        FHit fHit_,
        FRegen fRegen_,
        FGetItem fGetItem_,
        int32 PlayerIndex_,
        const SPoint& InitialPos_,
        const SCharacterMeta* pMeta_,
        int8 TeamIndex_,
        unique_ptr<SCharacter> pCharacter_,
        CBattlePlayer* pBattlePlayer_);
};