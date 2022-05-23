#pragma once

#include <string>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <Rso/Core/Stream.h>
#include <Rso/Json/Json.h>

#include "NetProtocol.h"
#include <Rso/Physics/Protocol.h>
namespace bb
{
	using namespace rso;
	using namespace core;
	using namespace physics;
	enum class ECashItemType
	{
		ResourcesPack,
		Max,
		Null,
	};
	enum class EGoodsItemType
	{
		AvatarColor,
		Max,
		Null,
	};
	enum class ERank : uint8
	{
		Unranked,
		Bronze,
		Silver,
		Gold,
		Diamond,
		Champion,
		Max,
	};
	struct SServerConfigMeta : public SProto
	{
		void operator << (CStream&) override
		{
		}
		void operator << (const Value&) override
		{
		}
		void operator >> (CStream&) const override
		{
		}
		void operator >> (Value&) const override
		{
		}
		static wstring StdName(void)
		{
			return L"";
		}
		static wstring MemberName(void)
		{
			return L"";
		}
	};
	struct SStructure : public SRectCollider2D
	{
		SPoint LocalPosition{};
		SStructure()
		{
		}
		SStructure(const SRectCollider2D& Super_, const SPoint& LocalPosition_) : SRectCollider2D(Super_), LocalPosition(LocalPosition_)
		{
		}
		SStructure(SRectCollider2D&& Super_, SPoint&& LocalPosition_) : SRectCollider2D(std::move(Super_)), LocalPosition(std::move(LocalPosition_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRectCollider2D::operator << (Stream_);
			Stream_ >> LocalPosition;
		}
		void operator << (const Value& Value_) override
		{
			SRectCollider2D::operator << (Value_);
			Value_["LocalPosition"] >> LocalPosition;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRectCollider2D::operator >> (Stream_);
			Stream_ << LocalPosition;
		}
		void operator >> (Value& Value_) const override
		{
			SRectCollider2D::operator >> (Value_);
			Value_["LocalPosition"] = LocalPosition;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRectCollider2D()) + L"," + 
				GetStdName(SPoint());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRectCollider2D(), L"") + L"," + 
				GetMemberName(SPoint(), L"LocalPosition");
		}
	};
	struct SStructureMove : public SProto
	{
		list<SRectCollider2D> Colliders{};
		SPoint BeginPos{};
		SPoint EndPos{};
		float Velocity{};
		float Delay{};
		SStructureMove()
		{
		}
		SStructureMove(const list<SRectCollider2D>& Colliders_, const SPoint& BeginPos_, const SPoint& EndPos_, const float& Velocity_, const float& Delay_) : Colliders(Colliders_), BeginPos(BeginPos_), EndPos(EndPos_), Velocity(Velocity_), Delay(Delay_)
		{
		}
		SStructureMove(list<SRectCollider2D>&& Colliders_, SPoint&& BeginPos_, SPoint&& EndPos_, float&& Velocity_, float&& Delay_) : Colliders(std::move(Colliders_)), BeginPos(std::move(BeginPos_)), EndPos(std::move(EndPos_)), Velocity(std::move(Velocity_)), Delay(std::move(Delay_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Colliders;
			Stream_ >> BeginPos;
			Stream_ >> EndPos;
			Stream_ >> Velocity;
			Stream_ >> Delay;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Colliders"] >> Colliders;
			Value_["BeginPos"] >> BeginPos;
			Value_["EndPos"] >> EndPos;
			Value_["Velocity"] >> Velocity;
			Value_["Delay"] >> Delay;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Colliders;
			Stream_ << BeginPos;
			Stream_ << EndPos;
			Stream_ << Velocity;
			Stream_ << Delay;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Colliders"] = Colliders;
			Value_["BeginPos"] = BeginPos;
			Value_["EndPos"] = EndPos;
			Value_["Velocity"] = Velocity;
			Value_["Delay"] = Delay;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(list<SRectCollider2D>()) + L"," + 
				GetStdName(SPoint()) + L"," + 
				GetStdName(SPoint()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(list<SRectCollider2D>(), L"Colliders") + L"," + 
				GetMemberName(SPoint(), L"BeginPos") + L"," + 
				GetMemberName(SPoint(), L"EndPos") + L"," + 
				GetMemberName(float(), L"Velocity") + L"," + 
				GetMemberName(float(), L"Delay");
		}
	};
	struct SConfigMeta : public SProto
	{
		int32 BattleDurationSec{};
		int32 BattleOneOnOneDurationSec{};
		int32 GhostDelaySec{};
		int32 InvulnerableDurationSec{};
		int32 BalloonHitPoint{};
		int32 ParachuteHitPoint{};
		int32 FirstBalloonHitPoint{};
		int32 QuestCoolMinutes{};
		TResource QuestNextCostGold{};
		int32 ChangeNickFreeCount{};
		TResource ChangeNickCostDia{};
		TResource TutorialRewardDia{};
		SConfigMeta()
		{
		}
		SConfigMeta(const int32& BattleDurationSec_, const int32& BattleOneOnOneDurationSec_, const int32& GhostDelaySec_, const int32& InvulnerableDurationSec_, const int32& BalloonHitPoint_, const int32& ParachuteHitPoint_, const int32& FirstBalloonHitPoint_, const int32& QuestCoolMinutes_, const TResource& QuestNextCostGold_, const int32& ChangeNickFreeCount_, const TResource& ChangeNickCostDia_, const TResource& TutorialRewardDia_) : BattleDurationSec(BattleDurationSec_), BattleOneOnOneDurationSec(BattleOneOnOneDurationSec_), GhostDelaySec(GhostDelaySec_), InvulnerableDurationSec(InvulnerableDurationSec_), BalloonHitPoint(BalloonHitPoint_), ParachuteHitPoint(ParachuteHitPoint_), FirstBalloonHitPoint(FirstBalloonHitPoint_), QuestCoolMinutes(QuestCoolMinutes_), QuestNextCostGold(QuestNextCostGold_), ChangeNickFreeCount(ChangeNickFreeCount_), ChangeNickCostDia(ChangeNickCostDia_), TutorialRewardDia(TutorialRewardDia_)
		{
		}
		SConfigMeta(int32&& BattleDurationSec_, int32&& BattleOneOnOneDurationSec_, int32&& GhostDelaySec_, int32&& InvulnerableDurationSec_, int32&& BalloonHitPoint_, int32&& ParachuteHitPoint_, int32&& FirstBalloonHitPoint_, int32&& QuestCoolMinutes_, TResource&& QuestNextCostGold_, int32&& ChangeNickFreeCount_, TResource&& ChangeNickCostDia_, TResource&& TutorialRewardDia_) : BattleDurationSec(std::move(BattleDurationSec_)), BattleOneOnOneDurationSec(std::move(BattleOneOnOneDurationSec_)), GhostDelaySec(std::move(GhostDelaySec_)), InvulnerableDurationSec(std::move(InvulnerableDurationSec_)), BalloonHitPoint(std::move(BalloonHitPoint_)), ParachuteHitPoint(std::move(ParachuteHitPoint_)), FirstBalloonHitPoint(std::move(FirstBalloonHitPoint_)), QuestCoolMinutes(std::move(QuestCoolMinutes_)), QuestNextCostGold(std::move(QuestNextCostGold_)), ChangeNickFreeCount(std::move(ChangeNickFreeCount_)), ChangeNickCostDia(std::move(ChangeNickCostDia_)), TutorialRewardDia(std::move(TutorialRewardDia_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> BattleDurationSec;
			Stream_ >> BattleOneOnOneDurationSec;
			Stream_ >> GhostDelaySec;
			Stream_ >> InvulnerableDurationSec;
			Stream_ >> BalloonHitPoint;
			Stream_ >> ParachuteHitPoint;
			Stream_ >> FirstBalloonHitPoint;
			Stream_ >> QuestCoolMinutes;
			Stream_ >> QuestNextCostGold;
			Stream_ >> ChangeNickFreeCount;
			Stream_ >> ChangeNickCostDia;
			Stream_ >> TutorialRewardDia;
		}
		void operator << (const Value& Value_) override
		{
			Value_["BattleDurationSec"] >> BattleDurationSec;
			Value_["BattleOneOnOneDurationSec"] >> BattleOneOnOneDurationSec;
			Value_["GhostDelaySec"] >> GhostDelaySec;
			Value_["InvulnerableDurationSec"] >> InvulnerableDurationSec;
			Value_["BalloonHitPoint"] >> BalloonHitPoint;
			Value_["ParachuteHitPoint"] >> ParachuteHitPoint;
			Value_["FirstBalloonHitPoint"] >> FirstBalloonHitPoint;
			Value_["QuestCoolMinutes"] >> QuestCoolMinutes;
			Value_["QuestNextCostGold"] >> QuestNextCostGold;
			Value_["ChangeNickFreeCount"] >> ChangeNickFreeCount;
			Value_["ChangeNickCostDia"] >> ChangeNickCostDia;
			Value_["TutorialRewardDia"] >> TutorialRewardDia;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << BattleDurationSec;
			Stream_ << BattleOneOnOneDurationSec;
			Stream_ << GhostDelaySec;
			Stream_ << InvulnerableDurationSec;
			Stream_ << BalloonHitPoint;
			Stream_ << ParachuteHitPoint;
			Stream_ << FirstBalloonHitPoint;
			Stream_ << QuestCoolMinutes;
			Stream_ << QuestNextCostGold;
			Stream_ << ChangeNickFreeCount;
			Stream_ << ChangeNickCostDia;
			Stream_ << TutorialRewardDia;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["BattleDurationSec"] = BattleDurationSec;
			Value_["BattleOneOnOneDurationSec"] = BattleOneOnOneDurationSec;
			Value_["GhostDelaySec"] = GhostDelaySec;
			Value_["InvulnerableDurationSec"] = InvulnerableDurationSec;
			Value_["BalloonHitPoint"] = BalloonHitPoint;
			Value_["ParachuteHitPoint"] = ParachuteHitPoint;
			Value_["FirstBalloonHitPoint"] = FirstBalloonHitPoint;
			Value_["QuestCoolMinutes"] = QuestCoolMinutes;
			Value_["QuestNextCostGold"] = QuestNextCostGold;
			Value_["ChangeNickFreeCount"] = ChangeNickFreeCount;
			Value_["ChangeNickCostDia"] = ChangeNickCostDia;
			Value_["TutorialRewardDia"] = TutorialRewardDia;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"BattleDurationSec") + L"," + 
				GetMemberName(int32(), L"BattleOneOnOneDurationSec") + L"," + 
				GetMemberName(int32(), L"GhostDelaySec") + L"," + 
				GetMemberName(int32(), L"InvulnerableDurationSec") + L"," + 
				GetMemberName(int32(), L"BalloonHitPoint") + L"," + 
				GetMemberName(int32(), L"ParachuteHitPoint") + L"," + 
				GetMemberName(int32(), L"FirstBalloonHitPoint") + L"," + 
				GetMemberName(int32(), L"QuestCoolMinutes") + L"," + 
				GetMemberName(TResource(), L"QuestNextCostGold") + L"," + 
				GetMemberName(int32(), L"ChangeNickFreeCount") + L"," + 
				GetMemberName(TResource(), L"ChangeNickCostDia") + L"," + 
				GetMemberName(TResource(), L"TutorialRewardDia");
		}
	};
	struct SForbiddenWordMeta : public SProto
	{
		wstring Word{};
		SForbiddenWordMeta()
		{
		}
		SForbiddenWordMeta(const wstring& Word_) : Word(Word_)
		{
		}
		SForbiddenWordMeta(wstring&& Word_) : Word(std::move(Word_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Word;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Word"] >> Word;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Word;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Word"] = Word;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Word");
		}
	};
	struct SShopConfigServerMeta : public SProto
	{
		int32 DailyRewardDurationMinute{};
		int32 DailyRewardFreeCount{};
		int32 DailyRewardAdCount{};
		SShopConfigServerMeta()
		{
		}
		SShopConfigServerMeta(const int32& DailyRewardDurationMinute_, const int32& DailyRewardFreeCount_, const int32& DailyRewardAdCount_) : DailyRewardDurationMinute(DailyRewardDurationMinute_), DailyRewardFreeCount(DailyRewardFreeCount_), DailyRewardAdCount(DailyRewardAdCount_)
		{
		}
		SShopConfigServerMeta(int32&& DailyRewardDurationMinute_, int32&& DailyRewardFreeCount_, int32&& DailyRewardAdCount_) : DailyRewardDurationMinute(std::move(DailyRewardDurationMinute_)), DailyRewardFreeCount(std::move(DailyRewardFreeCount_)), DailyRewardAdCount(std::move(DailyRewardAdCount_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> DailyRewardDurationMinute;
			Stream_ >> DailyRewardFreeCount;
			Stream_ >> DailyRewardAdCount;
		}
		void operator << (const Value& Value_) override
		{
			Value_["DailyRewardDurationMinute"] >> DailyRewardDurationMinute;
			Value_["DailyRewardFreeCount"] >> DailyRewardFreeCount;
			Value_["DailyRewardAdCount"] >> DailyRewardAdCount;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << DailyRewardDurationMinute;
			Stream_ << DailyRewardFreeCount;
			Stream_ << DailyRewardAdCount;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["DailyRewardDurationMinute"] = DailyRewardDurationMinute;
			Value_["DailyRewardFreeCount"] = DailyRewardFreeCount;
			Value_["DailyRewardAdCount"] = DailyRewardAdCount;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"DailyRewardDurationMinute") + L"," + 
				GetMemberName(int32(), L"DailyRewardFreeCount") + L"," + 
				GetMemberName(int32(), L"DailyRewardAdCount");
		}
	};
	struct SShopServerMeta : public SProto
	{
		int32 Code{};
		EResource CostType{};
		TResource CostValue{};
		int32 RewardCode{};
		SShopServerMeta()
		{
		}
		SShopServerMeta(const int32& Code_, const EResource& CostType_, const TResource& CostValue_, const int32& RewardCode_) : Code(Code_), CostType(CostType_), CostValue(CostValue_), RewardCode(RewardCode_)
		{
		}
		SShopServerMeta(int32&& Code_, EResource&& CostType_, TResource&& CostValue_, int32&& RewardCode_) : Code(std::move(Code_)), CostType(std::move(CostType_)), CostValue(std::move(CostValue_)), RewardCode(std::move(RewardCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
			Stream_ >> CostType;
			Stream_ >> CostValue;
			Stream_ >> RewardCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
			Value_["CostType"] >> CostType;
			Value_["CostValue"] >> CostValue;
			Value_["RewardCode"] >> RewardCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
			Stream_ << CostType;
			Stream_ << CostValue;
			Stream_ << RewardCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
			Value_["CostType"] = CostType;
			Value_["CostValue"] = CostValue;
			Value_["RewardCode"] = RewardCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(EResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(EResource(), L"CostType") + L"," + 
				GetMemberName(TResource(), L"CostValue") + L"," + 
				GetMemberName(int32(), L"RewardCode");
		}
	};
	struct SShopPackageServerMeta : public SProto
	{
		int32 Code{};
		EResource CostType{};
		TResource CostValue{};
		int32 RewardCode{};
		SShopPackageServerMeta()
		{
		}
		SShopPackageServerMeta(const int32& Code_, const EResource& CostType_, const TResource& CostValue_, const int32& RewardCode_) : Code(Code_), CostType(CostType_), CostValue(CostValue_), RewardCode(RewardCode_)
		{
		}
		SShopPackageServerMeta(int32&& Code_, EResource&& CostType_, TResource&& CostValue_, int32&& RewardCode_) : Code(std::move(Code_)), CostType(std::move(CostType_)), CostValue(std::move(CostValue_)), RewardCode(std::move(RewardCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
			Stream_ >> CostType;
			Stream_ >> CostValue;
			Stream_ >> RewardCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
			Value_["CostType"] >> CostType;
			Value_["CostValue"] >> CostValue;
			Value_["RewardCode"] >> RewardCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
			Stream_ << CostType;
			Stream_ << CostValue;
			Stream_ << RewardCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
			Value_["CostType"] = CostType;
			Value_["CostValue"] = CostValue;
			Value_["RewardCode"] = RewardCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(EResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(EResource(), L"CostType") + L"," + 
				GetMemberName(TResource(), L"CostValue") + L"," + 
				GetMemberName(int32(), L"RewardCode");
		}
	};
	struct SShopDailyRewardServerMeta : public SProto
	{
		double Probability{};
		EResource RewardType{};
		TResource RewardValue{};
		SShopDailyRewardServerMeta()
		{
		}
		SShopDailyRewardServerMeta(const double& Probability_, const EResource& RewardType_, const TResource& RewardValue_) : Probability(Probability_), RewardType(RewardType_), RewardValue(RewardValue_)
		{
		}
		SShopDailyRewardServerMeta(double&& Probability_, EResource&& RewardType_, TResource&& RewardValue_) : Probability(std::move(Probability_)), RewardType(std::move(RewardType_)), RewardValue(std::move(RewardValue_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Probability;
			Stream_ >> RewardType;
			Stream_ >> RewardValue;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Probability"] >> Probability;
			Value_["RewardType"] >> RewardType;
			Value_["RewardValue"] >> RewardValue;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Probability;
			Stream_ << RewardType;
			Stream_ << RewardValue;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Probability"] = Probability;
			Value_["RewardType"] = RewardType;
			Value_["RewardValue"] = RewardValue;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(double()) + L"," + 
				GetStdName(EResource()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(double(), L"Probability") + L"," + 
				GetMemberName(EResource(), L"RewardType") + L"," + 
				GetMemberName(TResource(), L"RewardValue");
		}
	};
	struct SShopCashServerMeta : public SProto
	{
		wstring Pid{};
		TResource DiaCount{};
		SShopCashServerMeta()
		{
		}
		SShopCashServerMeta(const wstring& Pid_, const TResource& DiaCount_) : Pid(Pid_), DiaCount(DiaCount_)
		{
		}
		SShopCashServerMeta(wstring&& Pid_, TResource&& DiaCount_) : Pid(std::move(Pid_)), DiaCount(std::move(DiaCount_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Pid;
			Stream_ >> DiaCount;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Pid"] >> Pid;
			Value_["DiaCount"] >> DiaCount;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Pid;
			Stream_ << DiaCount;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Pid"] = Pid;
			Value_["DiaCount"] = DiaCount;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Pid") + L"," + 
				GetMemberName(TResource(), L"DiaCount");
		}
	};
	struct SCharacterMeta : public SProto
	{
		int32 Code{};
		EGrade Grade{};
		EResource Cost_Type{};
		TResource Price{};
		TResource CPRefund{};
		float MaxVelUp{};
		float MaxVelDown{};
		float MaxVelXGround{};
		float MaxVelXAir{};
		float FlapDeltaVelX{};
		float FlapDeltaVelUp{};
		float RunAcc{};
		float StaminaMax{};
		float StaminaPerTick{};
		int32 StaminaRegenDelay{};
		float PumpSpeed{};
		SCharacterMeta()
		{
		}
		SCharacterMeta(const int32& Code_, const EGrade& Grade_, const EResource& Cost_Type_, const TResource& Price_, const TResource& CPRefund_, const float& MaxVelUp_, const float& MaxVelDown_, const float& MaxVelXGround_, const float& MaxVelXAir_, const float& FlapDeltaVelX_, const float& FlapDeltaVelUp_, const float& RunAcc_, const float& StaminaMax_, const float& StaminaPerTick_, const int32& StaminaRegenDelay_, const float& PumpSpeed_) : Code(Code_), Grade(Grade_), Cost_Type(Cost_Type_), Price(Price_), CPRefund(CPRefund_), MaxVelUp(MaxVelUp_), MaxVelDown(MaxVelDown_), MaxVelXGround(MaxVelXGround_), MaxVelXAir(MaxVelXAir_), FlapDeltaVelX(FlapDeltaVelX_), FlapDeltaVelUp(FlapDeltaVelUp_), RunAcc(RunAcc_), StaminaMax(StaminaMax_), StaminaPerTick(StaminaPerTick_), StaminaRegenDelay(StaminaRegenDelay_), PumpSpeed(PumpSpeed_)
		{
		}
		SCharacterMeta(int32&& Code_, EGrade&& Grade_, EResource&& Cost_Type_, TResource&& Price_, TResource&& CPRefund_, float&& MaxVelUp_, float&& MaxVelDown_, float&& MaxVelXGround_, float&& MaxVelXAir_, float&& FlapDeltaVelX_, float&& FlapDeltaVelUp_, float&& RunAcc_, float&& StaminaMax_, float&& StaminaPerTick_, int32&& StaminaRegenDelay_, float&& PumpSpeed_) : Code(std::move(Code_)), Grade(std::move(Grade_)), Cost_Type(std::move(Cost_Type_)), Price(std::move(Price_)), CPRefund(std::move(CPRefund_)), MaxVelUp(std::move(MaxVelUp_)), MaxVelDown(std::move(MaxVelDown_)), MaxVelXGround(std::move(MaxVelXGround_)), MaxVelXAir(std::move(MaxVelXAir_)), FlapDeltaVelX(std::move(FlapDeltaVelX_)), FlapDeltaVelUp(std::move(FlapDeltaVelUp_)), RunAcc(std::move(RunAcc_)), StaminaMax(std::move(StaminaMax_)), StaminaPerTick(std::move(StaminaPerTick_)), StaminaRegenDelay(std::move(StaminaRegenDelay_)), PumpSpeed(std::move(PumpSpeed_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
			Stream_ >> Grade;
			Stream_ >> Cost_Type;
			Stream_ >> Price;
			Stream_ >> CPRefund;
			Stream_ >> MaxVelUp;
			Stream_ >> MaxVelDown;
			Stream_ >> MaxVelXGround;
			Stream_ >> MaxVelXAir;
			Stream_ >> FlapDeltaVelX;
			Stream_ >> FlapDeltaVelUp;
			Stream_ >> RunAcc;
			Stream_ >> StaminaMax;
			Stream_ >> StaminaPerTick;
			Stream_ >> StaminaRegenDelay;
			Stream_ >> PumpSpeed;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
			Value_["Grade"] >> Grade;
			Value_["Cost_Type"] >> Cost_Type;
			Value_["Price"] >> Price;
			Value_["CPRefund"] >> CPRefund;
			Value_["MaxVelUp"] >> MaxVelUp;
			Value_["MaxVelDown"] >> MaxVelDown;
			Value_["MaxVelXGround"] >> MaxVelXGround;
			Value_["MaxVelXAir"] >> MaxVelXAir;
			Value_["FlapDeltaVelX"] >> FlapDeltaVelX;
			Value_["FlapDeltaVelUp"] >> FlapDeltaVelUp;
			Value_["RunAcc"] >> RunAcc;
			Value_["StaminaMax"] >> StaminaMax;
			Value_["StaminaPerTick"] >> StaminaPerTick;
			Value_["StaminaRegenDelay"] >> StaminaRegenDelay;
			Value_["PumpSpeed"] >> PumpSpeed;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
			Stream_ << Grade;
			Stream_ << Cost_Type;
			Stream_ << Price;
			Stream_ << CPRefund;
			Stream_ << MaxVelUp;
			Stream_ << MaxVelDown;
			Stream_ << MaxVelXGround;
			Stream_ << MaxVelXAir;
			Stream_ << FlapDeltaVelX;
			Stream_ << FlapDeltaVelUp;
			Stream_ << RunAcc;
			Stream_ << StaminaMax;
			Stream_ << StaminaPerTick;
			Stream_ << StaminaRegenDelay;
			Stream_ << PumpSpeed;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
			Value_["Grade"] = Grade;
			Value_["Cost_Type"] = Cost_Type;
			Value_["Price"] = Price;
			Value_["CPRefund"] = CPRefund;
			Value_["MaxVelUp"] = MaxVelUp;
			Value_["MaxVelDown"] = MaxVelDown;
			Value_["MaxVelXGround"] = MaxVelXGround;
			Value_["MaxVelXAir"] = MaxVelXAir;
			Value_["FlapDeltaVelX"] = FlapDeltaVelX;
			Value_["FlapDeltaVelUp"] = FlapDeltaVelUp;
			Value_["RunAcc"] = RunAcc;
			Value_["StaminaMax"] = StaminaMax;
			Value_["StaminaPerTick"] = StaminaPerTick;
			Value_["StaminaRegenDelay"] = StaminaRegenDelay;
			Value_["PumpSpeed"] = PumpSpeed;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(EGrade()) + L"," + 
				GetStdName(EResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(float());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(EGrade(), L"Grade") + L"," + 
				GetMemberName(EResource(), L"Cost_Type") + L"," + 
				GetMemberName(TResource(), L"Price") + L"," + 
				GetMemberName(TResource(), L"CPRefund") + L"," + 
				GetMemberName(float(), L"MaxVelUp") + L"," + 
				GetMemberName(float(), L"MaxVelDown") + L"," + 
				GetMemberName(float(), L"MaxVelXGround") + L"," + 
				GetMemberName(float(), L"MaxVelXAir") + L"," + 
				GetMemberName(float(), L"FlapDeltaVelX") + L"," + 
				GetMemberName(float(), L"FlapDeltaVelUp") + L"," + 
				GetMemberName(float(), L"RunAcc") + L"," + 
				GetMemberName(float(), L"StaminaMax") + L"," + 
				GetMemberName(float(), L"StaminaPerTick") + L"," + 
				GetMemberName(int32(), L"StaminaRegenDelay") + L"," + 
				GetMemberName(float(), L"PumpSpeed");
		}
	};
	struct SCharacterServerMeta : public SCharacterMeta
	{
		bool Default{};
		SCharacterServerMeta()
		{
		}
		SCharacterServerMeta(const SCharacterMeta& Super_, const bool& Default_) : SCharacterMeta(Super_), Default(Default_)
		{
		}
		SCharacterServerMeta(SCharacterMeta&& Super_, bool&& Default_) : SCharacterMeta(std::move(Super_)), Default(std::move(Default_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SCharacterMeta::operator << (Stream_);
			Stream_ >> Default;
		}
		void operator << (const Value& Value_) override
		{
			SCharacterMeta::operator << (Value_);
			Value_["Default"] >> Default;
		}
		void operator >> (CStream& Stream_) const override
		{
			SCharacterMeta::operator >> (Stream_);
			Stream_ << Default;
		}
		void operator >> (Value& Value_) const override
		{
			SCharacterMeta::operator >> (Value_);
			Value_["Default"] = Default;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SCharacterMeta()) + L"," + 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SCharacterMeta(), L"") + L"," + 
				GetMemberName(bool(), L"Default");
		}
	};
	struct SCharacterGradeMeta : public SProto
	{
		EGrade Grade{};
		SCharacterGradeMeta()
		{
		}
		SCharacterGradeMeta(const EGrade& Grade_) : Grade(Grade_)
		{
		}
		SCharacterGradeMeta(EGrade&& Grade_) : Grade(std::move(Grade_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Grade;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Grade"] >> Grade;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Grade;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Grade"] = Grade;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EGrade());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EGrade(), L"Grade");
		}
	};
	using TPoses = vector<SPoint>;
	struct SPlayerPos : public SProto
	{
		TPoses Poses{};
		SPlayerPos()
		{
		}
		SPlayerPos(const TPoses& Poses_) : Poses(Poses_)
		{
		}
		SPlayerPos(TPoses&& Poses_) : Poses(std::move(Poses_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Poses;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Poses"] >> Poses;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Poses;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Poses"] = Poses;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TPoses());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TPoses(), L"Poses");
		}
	};
	struct SMapMulti : public SProto
	{
		wstring PrefabName{};
		map<TTeamCnt,SPlayerPos> PlayerPoses{};
		SPoint PropPosition{};
		list<SStructure> Structures{};
		list<SStructureMove> StructureMoves{};
		SMapMulti()
		{
		}
		SMapMulti(const wstring& PrefabName_, const map<TTeamCnt,SPlayerPos>& PlayerPoses_, const SPoint& PropPosition_, const list<SStructure>& Structures_, const list<SStructureMove>& StructureMoves_) : PrefabName(PrefabName_), PlayerPoses(PlayerPoses_), PropPosition(PropPosition_), Structures(Structures_), StructureMoves(StructureMoves_)
		{
		}
		SMapMulti(wstring&& PrefabName_, map<TTeamCnt,SPlayerPos>&& PlayerPoses_, SPoint&& PropPosition_, list<SStructure>&& Structures_, list<SStructureMove>&& StructureMoves_) : PrefabName(std::move(PrefabName_)), PlayerPoses(std::move(PlayerPoses_)), PropPosition(std::move(PropPosition_)), Structures(std::move(Structures_)), StructureMoves(std::move(StructureMoves_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> PrefabName;
			Stream_ >> PlayerPoses;
			Stream_ >> PropPosition;
			Stream_ >> Structures;
			Stream_ >> StructureMoves;
		}
		void operator << (const Value& Value_) override
		{
			Value_["PrefabName"] >> PrefabName;
			Value_["PlayerPoses"] >> PlayerPoses;
			Value_["PropPosition"] >> PropPosition;
			Value_["Structures"] >> Structures;
			Value_["StructureMoves"] >> StructureMoves;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << PrefabName;
			Stream_ << PlayerPoses;
			Stream_ << PropPosition;
			Stream_ << Structures;
			Stream_ << StructureMoves;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["PrefabName"] = PrefabName;
			Value_["PlayerPoses"] = PlayerPoses;
			Value_["PropPosition"] = PropPosition;
			Value_["Structures"] = Structures;
			Value_["StructureMoves"] = StructureMoves;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(map<TTeamCnt,SPlayerPos>()) + L"," + 
				GetStdName(SPoint()) + L"," + 
				GetStdName(list<SStructure>()) + L"," + 
				GetStdName(list<SStructureMove>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"PrefabName") + L"," + 
				GetMemberName(map<TTeamCnt,SPlayerPos>(), L"PlayerPoses") + L"," + 
				GetMemberName(SPoint(), L"PropPosition") + L"," + 
				GetMemberName(list<SStructure>(), L"Structures") + L"," + 
				GetMemberName(list<SStructureMove>(), L"StructureMoves");
		}
	};
	struct SMapMeta : public SProto
	{
		vector<SMapMulti> MapOneOnOnes{};
		vector<SMapMulti> MapMulties{};
		SMapMeta()
		{
		}
		SMapMeta(const vector<SMapMulti>& MapOneOnOnes_, const vector<SMapMulti>& MapMulties_) : MapOneOnOnes(MapOneOnOnes_), MapMulties(MapMulties_)
		{
		}
		SMapMeta(vector<SMapMulti>&& MapOneOnOnes_, vector<SMapMulti>&& MapMulties_) : MapOneOnOnes(std::move(MapOneOnOnes_)), MapMulties(std::move(MapMulties_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> MapOneOnOnes;
			Stream_ >> MapMulties;
		}
		void operator << (const Value& Value_) override
		{
			Value_["MapOneOnOnes"] >> MapOneOnOnes;
			Value_["MapMulties"] >> MapMulties;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << MapOneOnOnes;
			Stream_ << MapMulties;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["MapOneOnOnes"] = MapOneOnOnes;
			Value_["MapMulties"] = MapMulties;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(vector<SMapMulti>()) + L"," + 
				GetStdName(vector<SMapMulti>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(vector<SMapMulti>(), L"MapOneOnOnes") + L"," + 
				GetMemberName(vector<SMapMulti>(), L"MapMulties");
		}
	};
	struct SSingleMeta : public SProto
	{
		int32 PlayCountMax{};
		TResource ChargeCostGold{};
		int32 ScoreFactorWave{};
		int32 ScoreFactorTime{};
		int32 ScoreFactorGold{};
		int32 RefreshDurationMinute{};
		SSingleMeta()
		{
		}
		SSingleMeta(const int32& PlayCountMax_, const TResource& ChargeCostGold_, const int32& ScoreFactorWave_, const int32& ScoreFactorTime_, const int32& ScoreFactorGold_, const int32& RefreshDurationMinute_) : PlayCountMax(PlayCountMax_), ChargeCostGold(ChargeCostGold_), ScoreFactorWave(ScoreFactorWave_), ScoreFactorTime(ScoreFactorTime_), ScoreFactorGold(ScoreFactorGold_), RefreshDurationMinute(RefreshDurationMinute_)
		{
		}
		SSingleMeta(int32&& PlayCountMax_, TResource&& ChargeCostGold_, int32&& ScoreFactorWave_, int32&& ScoreFactorTime_, int32&& ScoreFactorGold_, int32&& RefreshDurationMinute_) : PlayCountMax(std::move(PlayCountMax_)), ChargeCostGold(std::move(ChargeCostGold_)), ScoreFactorWave(std::move(ScoreFactorWave_)), ScoreFactorTime(std::move(ScoreFactorTime_)), ScoreFactorGold(std::move(ScoreFactorGold_)), RefreshDurationMinute(std::move(RefreshDurationMinute_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> PlayCountMax;
			Stream_ >> ChargeCostGold;
			Stream_ >> ScoreFactorWave;
			Stream_ >> ScoreFactorTime;
			Stream_ >> ScoreFactorGold;
			Stream_ >> RefreshDurationMinute;
		}
		void operator << (const Value& Value_) override
		{
			Value_["PlayCountMax"] >> PlayCountMax;
			Value_["ChargeCostGold"] >> ChargeCostGold;
			Value_["ScoreFactorWave"] >> ScoreFactorWave;
			Value_["ScoreFactorTime"] >> ScoreFactorTime;
			Value_["ScoreFactorGold"] >> ScoreFactorGold;
			Value_["RefreshDurationMinute"] >> RefreshDurationMinute;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << PlayCountMax;
			Stream_ << ChargeCostGold;
			Stream_ << ScoreFactorWave;
			Stream_ << ScoreFactorTime;
			Stream_ << ScoreFactorGold;
			Stream_ << RefreshDurationMinute;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["PlayCountMax"] = PlayCountMax;
			Value_["ChargeCostGold"] = ChargeCostGold;
			Value_["ScoreFactorWave"] = ScoreFactorWave;
			Value_["ScoreFactorTime"] = ScoreFactorTime;
			Value_["ScoreFactorGold"] = ScoreFactorGold;
			Value_["RefreshDurationMinute"] = RefreshDurationMinute;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"PlayCountMax") + L"," + 
				GetMemberName(TResource(), L"ChargeCostGold") + L"," + 
				GetMemberName(int32(), L"ScoreFactorWave") + L"," + 
				GetMemberName(int32(), L"ScoreFactorTime") + L"," + 
				GetMemberName(int32(), L"ScoreFactorGold") + L"," + 
				GetMemberName(int32(), L"RefreshDurationMinute");
		}
	};
	struct SIslandMeta : public SProto
	{
		int32 PlayCountMax{};
		TResource ChargeCostGold{};
		int32 ScoreFactorIsland{};
		int32 ScoreFactorGold{};
		int32 RefreshDurationMinute{};
		SIslandMeta()
		{
		}
		SIslandMeta(const int32& PlayCountMax_, const TResource& ChargeCostGold_, const int32& ScoreFactorIsland_, const int32& ScoreFactorGold_, const int32& RefreshDurationMinute_) : PlayCountMax(PlayCountMax_), ChargeCostGold(ChargeCostGold_), ScoreFactorIsland(ScoreFactorIsland_), ScoreFactorGold(ScoreFactorGold_), RefreshDurationMinute(RefreshDurationMinute_)
		{
		}
		SIslandMeta(int32&& PlayCountMax_, TResource&& ChargeCostGold_, int32&& ScoreFactorIsland_, int32&& ScoreFactorGold_, int32&& RefreshDurationMinute_) : PlayCountMax(std::move(PlayCountMax_)), ChargeCostGold(std::move(ChargeCostGold_)), ScoreFactorIsland(std::move(ScoreFactorIsland_)), ScoreFactorGold(std::move(ScoreFactorGold_)), RefreshDurationMinute(std::move(RefreshDurationMinute_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> PlayCountMax;
			Stream_ >> ChargeCostGold;
			Stream_ >> ScoreFactorIsland;
			Stream_ >> ScoreFactorGold;
			Stream_ >> RefreshDurationMinute;
		}
		void operator << (const Value& Value_) override
		{
			Value_["PlayCountMax"] >> PlayCountMax;
			Value_["ChargeCostGold"] >> ChargeCostGold;
			Value_["ScoreFactorIsland"] >> ScoreFactorIsland;
			Value_["ScoreFactorGold"] >> ScoreFactorGold;
			Value_["RefreshDurationMinute"] >> RefreshDurationMinute;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << PlayCountMax;
			Stream_ << ChargeCostGold;
			Stream_ << ScoreFactorIsland;
			Stream_ << ScoreFactorGold;
			Stream_ << RefreshDurationMinute;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["PlayCountMax"] = PlayCountMax;
			Value_["ChargeCostGold"] = ChargeCostGold;
			Value_["ScoreFactorIsland"] = ScoreFactorIsland;
			Value_["ScoreFactorGold"] = ScoreFactorGold;
			Value_["RefreshDurationMinute"] = RefreshDurationMinute;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"PlayCountMax") + L"," + 
				GetMemberName(TResource(), L"ChargeCostGold") + L"," + 
				GetMemberName(int32(), L"ScoreFactorIsland") + L"," + 
				GetMemberName(int32(), L"ScoreFactorGold") + L"," + 
				GetMemberName(int32(), L"RefreshDurationMinute");
		}
	};
	struct SGachaMeta : public SProto
	{
		EResource CostResource{};
		int32 CostValue{};
		EResource TenCostResource{};
		int32 TenCostValue{};
		int32 RewardCode{};
		SGachaMeta()
		{
		}
		SGachaMeta(const EResource& CostResource_, const int32& CostValue_, const EResource& TenCostResource_, const int32& TenCostValue_, const int32& RewardCode_) : CostResource(CostResource_), CostValue(CostValue_), TenCostResource(TenCostResource_), TenCostValue(TenCostValue_), RewardCode(RewardCode_)
		{
		}
		SGachaMeta(EResource&& CostResource_, int32&& CostValue_, EResource&& TenCostResource_, int32&& TenCostValue_, int32&& RewardCode_) : CostResource(std::move(CostResource_)), CostValue(std::move(CostValue_)), TenCostResource(std::move(TenCostResource_)), TenCostValue(std::move(TenCostValue_)), RewardCode(std::move(RewardCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> CostResource;
			Stream_ >> CostValue;
			Stream_ >> TenCostResource;
			Stream_ >> TenCostValue;
			Stream_ >> RewardCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["CostResource"] >> CostResource;
			Value_["CostValue"] >> CostValue;
			Value_["TenCostResource"] >> TenCostResource;
			Value_["TenCostValue"] >> TenCostValue;
			Value_["RewardCode"] >> RewardCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << CostResource;
			Stream_ << CostValue;
			Stream_ << TenCostResource;
			Stream_ << TenCostValue;
			Stream_ << RewardCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["CostResource"] = CostResource;
			Value_["CostValue"] = CostValue;
			Value_["TenCostResource"] = TenCostResource;
			Value_["TenCostValue"] = TenCostValue;
			Value_["RewardCode"] = RewardCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(EResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EResource(), L"CostResource") + L"," + 
				GetMemberName(int32(), L"CostValue") + L"," + 
				GetMemberName(EResource(), L"TenCostResource") + L"," + 
				GetMemberName(int32(), L"TenCostValue") + L"," + 
				GetMemberName(int32(), L"RewardCode");
		}
	};
	struct SGachaGradeMeta : public SProto
	{
		EGrade Grade{};
		double Probability{};
		SGachaGradeMeta()
		{
		}
		SGachaGradeMeta(const EGrade& Grade_, const double& Probability_) : Grade(Grade_), Probability(Probability_)
		{
		}
		SGachaGradeMeta(EGrade&& Grade_, double&& Probability_) : Grade(std::move(Grade_)), Probability(std::move(Probability_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Grade;
			Stream_ >> Probability;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Grade"] >> Grade;
			Value_["Probability"] >> Probability;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Grade;
			Stream_ << Probability;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Grade"] = Grade;
			Value_["Probability"] = Probability;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EGrade()) + L"," + 
				GetStdName(double());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EGrade(), L"Grade") + L"," + 
				GetMemberName(double(), L"Probability");
		}
	};
	struct SGachaRewardMeta : public SProto
	{
		int32 Code{};
		double Probability{};
		int32 CharCode{};
		SGachaRewardMeta()
		{
		}
		SGachaRewardMeta(const int32& Code_, const double& Probability_, const int32& CharCode_) : Code(Code_), Probability(Probability_), CharCode(CharCode_)
		{
		}
		SGachaRewardMeta(int32&& Code_, double&& Probability_, int32&& CharCode_) : Code(std::move(Code_)), Probability(std::move(Probability_)), CharCode(std::move(CharCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
			Stream_ >> Probability;
			Stream_ >> CharCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
			Value_["Probability"] >> Probability;
			Value_["CharCode"] >> CharCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
			Stream_ << Probability;
			Stream_ << CharCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
			Value_["Probability"] = Probability;
			Value_["CharCode"] = CharCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(double()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(double(), L"Probability") + L"," + 
				GetMemberName(int32(), L"CharCode");
		}
	};
	struct SRewardMeta : public SProto
	{
		ERewardType Type{};
		int32 Data{};
		SRewardMeta()
		{
		}
		SRewardMeta(const ERewardType& Type_, const int32& Data_) : Type(Type_), Data(Data_)
		{
		}
		SRewardMeta(ERewardType&& Type_, int32&& Data_) : Type(std::move(Type_)), Data(std::move(Data_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Type;
			Stream_ >> Data;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Type"] >> Type;
			Value_["Data"] >> Data;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Type;
			Stream_ << Data;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Type"] = Type;
			Value_["Data"] = Data;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(ERewardType()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(ERewardType(), L"Type") + L"," + 
				GetMemberName(int32(), L"Data");
		}
	};
	struct SKeyRewardMeta : public SProto
	{
		int32 Code{};
		SRewardMeta Reward{};
		SKeyRewardMeta()
		{
		}
		SKeyRewardMeta(const int32& Code_, const SRewardMeta& Reward_) : Code(Code_), Reward(Reward_)
		{
		}
		SKeyRewardMeta(int32&& Code_, SRewardMeta&& Reward_) : Code(std::move(Code_)), Reward(std::move(Reward_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
			Stream_ >> Reward;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
			Value_["Reward"] >> Reward;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
			Stream_ << Reward;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
			Value_["Reward"] = Reward;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(SRewardMeta());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(SRewardMeta(), L"Reward");
		}
	};
	struct SRankMeta : public SProto
	{
		ERank Rank{};
		SRankMeta()
		{
		}
		SRankMeta(const ERank& Rank_) : Rank(Rank_)
		{
		}
		SRankMeta(ERank&& Rank_) : Rank(std::move(Rank_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Rank;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Rank"] >> Rank;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Rank;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Rank"] = Rank;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(ERank());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(ERank(), L"Rank");
		}
	};
	struct SRankTierMeta : public SProto
	{
		ERank Rank{};
		int32 Tier{};
		int32 MinPoint{};
		SRankTierMeta()
		{
		}
		SRankTierMeta(const ERank& Rank_, const int32& Tier_, const int32& MinPoint_) : Rank(Rank_), Tier(Tier_), MinPoint(MinPoint_)
		{
		}
		SRankTierMeta(ERank&& Rank_, int32&& Tier_, int32&& MinPoint_) : Rank(std::move(Rank_)), Tier(std::move(Tier_)), MinPoint(std::move(MinPoint_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Rank;
			Stream_ >> Tier;
			Stream_ >> MinPoint;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Rank"] >> Rank;
			Value_["Tier"] >> Tier;
			Value_["MinPoint"] >> MinPoint;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Rank;
			Stream_ << Tier;
			Stream_ << MinPoint;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Rank"] = Rank;
			Value_["Tier"] = Tier;
			Value_["MinPoint"] = MinPoint;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(ERank()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(ERank(), L"Rank") + L"," + 
				GetMemberName(int32(), L"Tier") + L"," + 
				GetMemberName(int32(), L"MinPoint");
		}
	};
	struct SRankRewardMeta : public SProto
	{
		int32 Point{};
		int32 RewardCode{};
		SRankRewardMeta()
		{
		}
		SRankRewardMeta(const int32& Point_, const int32& RewardCode_) : Point(Point_), RewardCode(RewardCode_)
		{
		}
		SRankRewardMeta(int32&& Point_, int32&& RewardCode_) : Point(std::move(Point_)), RewardCode(std::move(RewardCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Point;
			Stream_ >> RewardCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Point"] >> Point;
			Value_["RewardCode"] >> RewardCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Point;
			Stream_ << RewardCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Point"] = Point;
			Value_["RewardCode"] = RewardCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Point") + L"," + 
				GetMemberName(int32(), L"RewardCode");
		}
	};
	struct SQuestMeta : public SProto
	{
		EQuestType QuestType{};
		int32 Code{};
		int32 RequirmentCount{};
		wstring Param{};
		wstring Operator{};
		int32 RewardCode{};
		SQuestMeta()
		{
		}
		SQuestMeta(const EQuestType& QuestType_, const int32& Code_, const int32& RequirmentCount_, const wstring& Param_, const wstring& Operator_, const int32& RewardCode_) : QuestType(QuestType_), Code(Code_), RequirmentCount(RequirmentCount_), Param(Param_), Operator(Operator_), RewardCode(RewardCode_)
		{
		}
		SQuestMeta(EQuestType&& QuestType_, int32&& Code_, int32&& RequirmentCount_, wstring&& Param_, wstring&& Operator_, int32&& RewardCode_) : QuestType(std::move(QuestType_)), Code(std::move(Code_)), RequirmentCount(std::move(RequirmentCount_)), Param(std::move(Param_)), Operator(std::move(Operator_)), RewardCode(std::move(RewardCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> QuestType;
			Stream_ >> Code;
			Stream_ >> RequirmentCount;
			Stream_ >> Param;
			Stream_ >> Operator;
			Stream_ >> RewardCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["QuestType"] >> QuestType;
			Value_["Code"] >> Code;
			Value_["RequirmentCount"] >> RequirmentCount;
			Value_["Param"] >> Param;
			Value_["Operator"] >> Operator;
			Value_["RewardCode"] >> RewardCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << QuestType;
			Stream_ << Code;
			Stream_ << RequirmentCount;
			Stream_ << Param;
			Stream_ << Operator;
			Stream_ << RewardCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["QuestType"] = QuestType;
			Value_["Code"] = Code;
			Value_["RequirmentCount"] = RequirmentCount;
			Value_["Param"] = Param;
			Value_["Operator"] = Operator;
			Value_["RewardCode"] = RewardCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EQuestType()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EQuestType(), L"QuestType") + L"," + 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(int32(), L"RequirmentCount") + L"," + 
				GetMemberName(wstring(), L"Param") + L"," + 
				GetMemberName(wstring(), L"Operator") + L"," + 
				GetMemberName(int32(), L"RewardCode");
		}
	};
	struct SQuestDailyCompleteMeta : public SProto
	{
		int32 RequirmentCount{};
		int32 RewardCode{};
		int32 RefreshMinutes{};
		SQuestDailyCompleteMeta()
		{
		}
		SQuestDailyCompleteMeta(const int32& RequirmentCount_, const int32& RewardCode_, const int32& RefreshMinutes_) : RequirmentCount(RequirmentCount_), RewardCode(RewardCode_), RefreshMinutes(RefreshMinutes_)
		{
		}
		SQuestDailyCompleteMeta(int32&& RequirmentCount_, int32&& RewardCode_, int32&& RefreshMinutes_) : RequirmentCount(std::move(RequirmentCount_)), RewardCode(std::move(RewardCode_)), RefreshMinutes(std::move(RefreshMinutes_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RequirmentCount;
			Stream_ >> RewardCode;
			Stream_ >> RefreshMinutes;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RequirmentCount"] >> RequirmentCount;
			Value_["RewardCode"] >> RewardCode;
			Value_["RefreshMinutes"] >> RefreshMinutes;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RequirmentCount;
			Stream_ << RewardCode;
			Stream_ << RefreshMinutes;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RequirmentCount"] = RequirmentCount;
			Value_["RewardCode"] = RewardCode;
			Value_["RefreshMinutes"] = RefreshMinutes;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"RequirmentCount") + L"," + 
				GetMemberName(int32(), L"RewardCode") + L"," + 
				GetMemberName(int32(), L"RefreshMinutes");
		}
	};
	struct SBattleRewardMeta : public SProto
	{
		EGameMode GameMode{};
		TTeamCnt TeamCount{};
		int32 TeamMemberCount{};
		int32 AddGold{};
		int32 Unranked{};
		int32 Bronze{};
		int32 Silver{};
		int32 Gold{};
		int32 Diamond{};
		int32 Champion{};
		SBattleRewardMeta()
		{
		}
		SBattleRewardMeta(const EGameMode& GameMode_, const TTeamCnt& TeamCount_, const int32& TeamMemberCount_, const int32& AddGold_, const int32& Unranked_, const int32& Bronze_, const int32& Silver_, const int32& Gold_, const int32& Diamond_, const int32& Champion_) : GameMode(GameMode_), TeamCount(TeamCount_), TeamMemberCount(TeamMemberCount_), AddGold(AddGold_), Unranked(Unranked_), Bronze(Bronze_), Silver(Silver_), Gold(Gold_), Diamond(Diamond_), Champion(Champion_)
		{
		}
		SBattleRewardMeta(EGameMode&& GameMode_, TTeamCnt&& TeamCount_, int32&& TeamMemberCount_, int32&& AddGold_, int32&& Unranked_, int32&& Bronze_, int32&& Silver_, int32&& Gold_, int32&& Diamond_, int32&& Champion_) : GameMode(std::move(GameMode_)), TeamCount(std::move(TeamCount_)), TeamMemberCount(std::move(TeamMemberCount_)), AddGold(std::move(AddGold_)), Unranked(std::move(Unranked_)), Bronze(std::move(Bronze_)), Silver(std::move(Silver_)), Gold(std::move(Gold_)), Diamond(std::move(Diamond_)), Champion(std::move(Champion_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> GameMode;
			Stream_ >> TeamCount;
			Stream_ >> TeamMemberCount;
			Stream_ >> AddGold;
			Stream_ >> Unranked;
			Stream_ >> Bronze;
			Stream_ >> Silver;
			Stream_ >> Gold;
			Stream_ >> Diamond;
			Stream_ >> Champion;
		}
		void operator << (const Value& Value_) override
		{
			Value_["GameMode"] >> GameMode;
			Value_["TeamCount"] >> TeamCount;
			Value_["TeamMemberCount"] >> TeamMemberCount;
			Value_["AddGold"] >> AddGold;
			Value_["Unranked"] >> Unranked;
			Value_["Bronze"] >> Bronze;
			Value_["Silver"] >> Silver;
			Value_["Gold"] >> Gold;
			Value_["Diamond"] >> Diamond;
			Value_["Champion"] >> Champion;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << GameMode;
			Stream_ << TeamCount;
			Stream_ << TeamMemberCount;
			Stream_ << AddGold;
			Stream_ << Unranked;
			Stream_ << Bronze;
			Stream_ << Silver;
			Stream_ << Gold;
			Stream_ << Diamond;
			Stream_ << Champion;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["GameMode"] = GameMode;
			Value_["TeamCount"] = TeamCount;
			Value_["TeamMemberCount"] = TeamMemberCount;
			Value_["AddGold"] = AddGold;
			Value_["Unranked"] = Unranked;
			Value_["Bronze"] = Bronze;
			Value_["Silver"] = Silver;
			Value_["Gold"] = Gold;
			Value_["Diamond"] = Diamond;
			Value_["Champion"] = Champion;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EGameMode()) + L"," + 
				GetStdName(TTeamCnt()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EGameMode(), L"GameMode") + L"," + 
				GetMemberName(TTeamCnt(), L"TeamCount") + L"," + 
				GetMemberName(int32(), L"TeamMemberCount") + L"," + 
				GetMemberName(int32(), L"AddGold") + L"," + 
				GetMemberName(int32(), L"Unranked") + L"," + 
				GetMemberName(int32(), L"Bronze") + L"," + 
				GetMemberName(int32(), L"Silver") + L"," + 
				GetMemberName(int32(), L"Gold") + L"," + 
				GetMemberName(int32(), L"Diamond") + L"," + 
				GetMemberName(int32(), L"Champion");
		}
	};
	struct SCouponMeta : public SProto
	{
		int32 Code{};
		int32 StartYear{};
		int32 StartMonth{};
		int32 StartDay{};
		int32 StartHour{};
		int32 EndYear{};
		int32 EndMonth{};
		int32 EndDay{};
		int32 EndHour{};
		int32 RewardCode{};
		SCouponMeta()
		{
		}
		SCouponMeta(const int32& Code_, const int32& StartYear_, const int32& StartMonth_, const int32& StartDay_, const int32& StartHour_, const int32& EndYear_, const int32& EndMonth_, const int32& EndDay_, const int32& EndHour_, const int32& RewardCode_) : Code(Code_), StartYear(StartYear_), StartMonth(StartMonth_), StartDay(StartDay_), StartHour(StartHour_), EndYear(EndYear_), EndMonth(EndMonth_), EndDay(EndDay_), EndHour(EndHour_), RewardCode(RewardCode_)
		{
		}
		SCouponMeta(int32&& Code_, int32&& StartYear_, int32&& StartMonth_, int32&& StartDay_, int32&& StartHour_, int32&& EndYear_, int32&& EndMonth_, int32&& EndDay_, int32&& EndHour_, int32&& RewardCode_) : Code(std::move(Code_)), StartYear(std::move(StartYear_)), StartMonth(std::move(StartMonth_)), StartDay(std::move(StartDay_)), StartHour(std::move(StartHour_)), EndYear(std::move(EndYear_)), EndMonth(std::move(EndMonth_)), EndDay(std::move(EndDay_)), EndHour(std::move(EndHour_)), RewardCode(std::move(RewardCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
			Stream_ >> StartYear;
			Stream_ >> StartMonth;
			Stream_ >> StartDay;
			Stream_ >> StartHour;
			Stream_ >> EndYear;
			Stream_ >> EndMonth;
			Stream_ >> EndDay;
			Stream_ >> EndHour;
			Stream_ >> RewardCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
			Value_["StartYear"] >> StartYear;
			Value_["StartMonth"] >> StartMonth;
			Value_["StartDay"] >> StartDay;
			Value_["StartHour"] >> StartHour;
			Value_["EndYear"] >> EndYear;
			Value_["EndMonth"] >> EndMonth;
			Value_["EndDay"] >> EndDay;
			Value_["EndHour"] >> EndHour;
			Value_["RewardCode"] >> RewardCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
			Stream_ << StartYear;
			Stream_ << StartMonth;
			Stream_ << StartDay;
			Stream_ << StartHour;
			Stream_ << EndYear;
			Stream_ << EndMonth;
			Stream_ << EndDay;
			Stream_ << EndHour;
			Stream_ << RewardCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
			Value_["StartYear"] = StartYear;
			Value_["StartMonth"] = StartMonth;
			Value_["StartDay"] = StartDay;
			Value_["StartHour"] = StartHour;
			Value_["EndYear"] = EndYear;
			Value_["EndMonth"] = EndMonth;
			Value_["EndDay"] = EndDay;
			Value_["EndHour"] = EndHour;
			Value_["RewardCode"] = RewardCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(int32(), L"StartYear") + L"," + 
				GetMemberName(int32(), L"StartMonth") + L"," + 
				GetMemberName(int32(), L"StartDay") + L"," + 
				GetMemberName(int32(), L"StartHour") + L"," + 
				GetMemberName(int32(), L"EndYear") + L"," + 
				GetMemberName(int32(), L"EndMonth") + L"," + 
				GetMemberName(int32(), L"EndDay") + L"," + 
				GetMemberName(int32(), L"EndHour") + L"," + 
				GetMemberName(int32(), L"RewardCode");
		}
	};
	struct SCouponKeyMeta : public SProto
	{
		wstring Key{};
		int32 Code{};
		SCouponKeyMeta()
		{
		}
		SCouponKeyMeta(const wstring& Key_, const int32& Code_) : Key(Key_), Code(Code_)
		{
		}
		SCouponKeyMeta(wstring&& Key_, int32&& Code_) : Key(std::move(Key_)), Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Key;
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Key"] >> Key;
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Key;
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Key"] = Key;
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Key") + L"," + 
				GetMemberName(int32(), L"Code");
		}
	};
	struct SRankingConfigMeta : public SProto
	{
		int32 PeriodMinutes{};
		wstring BaseTime{};
		SRankingConfigMeta()
		{
		}
		SRankingConfigMeta(const int32& PeriodMinutes_, const wstring& BaseTime_) : PeriodMinutes(PeriodMinutes_), BaseTime(BaseTime_)
		{
		}
		SRankingConfigMeta(int32&& PeriodMinutes_, wstring&& BaseTime_) : PeriodMinutes(std::move(PeriodMinutes_)), BaseTime(std::move(BaseTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> PeriodMinutes;
			Stream_ >> BaseTime;
		}
		void operator << (const Value& Value_) override
		{
			Value_["PeriodMinutes"] >> PeriodMinutes;
			Value_["BaseTime"] >> BaseTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << PeriodMinutes;
			Stream_ << BaseTime;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["PeriodMinutes"] = PeriodMinutes;
			Value_["BaseTime"] = BaseTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"PeriodMinutes") + L"," + 
				GetMemberName(wstring(), L"BaseTime");
		}
	};
	struct SRankingRewardMeta : public SProto
	{
		wstring Mode{};
		int32 End{};
		int32 RewardCode{};
		SRankingRewardMeta()
		{
		}
		SRankingRewardMeta(const wstring& Mode_, const int32& End_, const int32& RewardCode_) : Mode(Mode_), End(End_), RewardCode(RewardCode_)
		{
		}
		SRankingRewardMeta(wstring&& Mode_, int32&& End_, int32&& RewardCode_) : Mode(std::move(Mode_)), End(std::move(End_)), RewardCode(std::move(RewardCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Mode;
			Stream_ >> End;
			Stream_ >> RewardCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Mode"] >> Mode;
			Value_["End"] >> End;
			Value_["RewardCode"] >> RewardCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Mode;
			Stream_ << End;
			Stream_ << RewardCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Mode"] = Mode;
			Value_["End"] = End;
			Value_["RewardCode"] = RewardCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Mode") + L"," + 
				GetMemberName(int32(), L"End") + L"," + 
				GetMemberName(int32(), L"RewardCode");
		}
	};
}
