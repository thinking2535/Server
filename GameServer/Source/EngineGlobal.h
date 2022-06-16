#pragma once

class CEngineGlobal
{
public:
    static const int32 c_ContainerNumber = 0;
    static const int32 c_StructureNumber = 1;
    static const int32 c_BodyNumber = 2;
    static const int32 c_BalloonNumber = 3;
    static const int32 c_ParachuteNumber = 4;
    static const int32 c_ArrowNumber = 5;
    static const int32 c_CoinNumber = 6;
    static const int32 c_GoldBarNumber = 7;
    static const int32 c_ShieldNumber = 8;
    static const int32 c_StaminaNumber = 9;

    static inline int8 GetFaceWithPosition(const SPoint& Position_) { return (Position_.X <= 0.0f ? 1 : -1); }
    static inline int64 GetInvulnerableEndTick(int64 Tick_) { return (Tick_ + g_MetaData->ConfigMeta.InvulnerableDurationSec * 10000000); }
    inline static SRectCollider2D GetPlayerRect(void) { return SRectCollider2D(SPoint(c_PlayerWidth, c_PlayerHeight), SPoint(0.0f, c_PlayerOffsetY)); }
    static float BalloonWidth(int8 BalloonCount_);
    inline static SPoint GetBalloonSize(int8 BalloonCount_) { return SPoint(BalloonWidth(BalloonCount_), c_BalloonHeight); }
    inline static SRectCollider2D GetBalloonRect(int8 BalloonCount_) { return SRectCollider2D(GetBalloonSize(BalloonCount_), SPoint(0.0f, c_BalloonOffsetY)); }
    inline static SRectCollider2D GetParachuteRect(void) { return SRectCollider2D(SPoint(c_ParachuteWidth, c_ParachuteHeight), SPoint(0.0f, c_ParachuteOffsetY)); }
    inline static bool IsScaling(const SPumpInfo& PumpInfo_) { return (PumpInfo_.Count < PumpInfo_.CountTo); }
    inline static bool IsScaling(const SParachuteInfo& ParachuteInfo_) { return (ParachuteInfo_.Velocity != 0.0f || (ParachuteInfo_.Scale > 0.0f && ParachuteInfo_.Scale < c_ParachuteLocalScale)); }
};