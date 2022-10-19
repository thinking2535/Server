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
		int32 ChangeNickFreeCount{};
		EResource ChangeNickCostType{};
		TResource ChangeNickCostValue{};
		EResource TutorialRewardType{};
		TResource TutorialRewardValue{};
		TResource MaxTicket{};
		EResource BattleCostType{};
		TResource BattleCostValue{};
		SConfigMeta()
		{
		}
		SConfigMeta(const int32& BattleDurationSec_, const int32& BattleOneOnOneDurationSec_, const int32& GhostDelaySec_, const int32& InvulnerableDurationSec_, const int32& BalloonHitPoint_, const int32& ParachuteHitPoint_, const int32& FirstBalloonHitPoint_, const int32& ChangeNickFreeCount_, const EResource& ChangeNickCostType_, const TResource& ChangeNickCostValue_, const EResource& TutorialRewardType_, const TResource& TutorialRewardValue_, const TResource& MaxTicket_, const EResource& BattleCostType_, const TResource& BattleCostValue_) : BattleDurationSec(BattleDurationSec_), BattleOneOnOneDurationSec(BattleOneOnOneDurationSec_), GhostDelaySec(GhostDelaySec_), InvulnerableDurationSec(InvulnerableDurationSec_), BalloonHitPoint(BalloonHitPoint_), ParachuteHitPoint(ParachuteHitPoint_), FirstBalloonHitPoint(FirstBalloonHitPoint_), ChangeNickFreeCount(ChangeNickFreeCount_), ChangeNickCostType(ChangeNickCostType_), ChangeNickCostValue(ChangeNickCostValue_), TutorialRewardType(TutorialRewardType_), TutorialRewardValue(TutorialRewardValue_), MaxTicket(MaxTicket_), BattleCostType(BattleCostType_), BattleCostValue(BattleCostValue_)
		{
		}
		SConfigMeta(int32&& BattleDurationSec_, int32&& BattleOneOnOneDurationSec_, int32&& GhostDelaySec_, int32&& InvulnerableDurationSec_, int32&& BalloonHitPoint_, int32&& ParachuteHitPoint_, int32&& FirstBalloonHitPoint_, int32&& ChangeNickFreeCount_, EResource&& ChangeNickCostType_, TResource&& ChangeNickCostValue_, EResource&& TutorialRewardType_, TResource&& TutorialRewardValue_, TResource&& MaxTicket_, EResource&& BattleCostType_, TResource&& BattleCostValue_) : BattleDurationSec(std::move(BattleDurationSec_)), BattleOneOnOneDurationSec(std::move(BattleOneOnOneDurationSec_)), GhostDelaySec(std::move(GhostDelaySec_)), InvulnerableDurationSec(std::move(InvulnerableDurationSec_)), BalloonHitPoint(std::move(BalloonHitPoint_)), ParachuteHitPoint(std::move(ParachuteHitPoint_)), FirstBalloonHitPoint(std::move(FirstBalloonHitPoint_)), ChangeNickFreeCount(std::move(ChangeNickFreeCount_)), ChangeNickCostType(std::move(ChangeNickCostType_)), ChangeNickCostValue(std::move(ChangeNickCostValue_)), TutorialRewardType(std::move(TutorialRewardType_)), TutorialRewardValue(std::move(TutorialRewardValue_)), MaxTicket(std::move(MaxTicket_)), BattleCostType(std::move(BattleCostType_)), BattleCostValue(std::move(BattleCostValue_))
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
			Stream_ >> ChangeNickFreeCount;
			Stream_ >> ChangeNickCostType;
			Stream_ >> ChangeNickCostValue;
			Stream_ >> TutorialRewardType;
			Stream_ >> TutorialRewardValue;
			Stream_ >> MaxTicket;
			Stream_ >> BattleCostType;
			Stream_ >> BattleCostValue;
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
			Value_["ChangeNickFreeCount"] >> ChangeNickFreeCount;
			Value_["ChangeNickCostType"] >> ChangeNickCostType;
			Value_["ChangeNickCostValue"] >> ChangeNickCostValue;
			Value_["TutorialRewardType"] >> TutorialRewardType;
			Value_["TutorialRewardValue"] >> TutorialRewardValue;
			Value_["MaxTicket"] >> MaxTicket;
			Value_["BattleCostType"] >> BattleCostType;
			Value_["BattleCostValue"] >> BattleCostValue;
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
			Stream_ << ChangeNickFreeCount;
			Stream_ << ChangeNickCostType;
			Stream_ << ChangeNickCostValue;
			Stream_ << TutorialRewardType;
			Stream_ << TutorialRewardValue;
			Stream_ << MaxTicket;
			Stream_ << BattleCostType;
			Stream_ << BattleCostValue;
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
			Value_["ChangeNickFreeCount"] = ChangeNickFreeCount;
			Value_["ChangeNickCostType"] = ChangeNickCostType;
			Value_["ChangeNickCostValue"] = ChangeNickCostValue;
			Value_["TutorialRewardType"] = TutorialRewardType;
			Value_["TutorialRewardValue"] = TutorialRewardValue;
			Value_["MaxTicket"] = MaxTicket;
			Value_["BattleCostType"] = BattleCostType;
			Value_["BattleCostValue"] = BattleCostValue;
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
				GetStdName(EResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(EResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(EResource()) + L"," + 
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
				GetMemberName(int32(), L"ChangeNickFreeCount") + L"," + 
				GetMemberName(EResource(), L"ChangeNickCostType") + L"," + 
				GetMemberName(TResource(), L"ChangeNickCostValue") + L"," + 
				GetMemberName(EResource(), L"TutorialRewardType") + L"," + 
				GetMemberName(TResource(), L"TutorialRewardValue") + L"," + 
				GetMemberName(TResource(), L"MaxTicket") + L"," + 
				GetMemberName(EResource(), L"BattleCostType") + L"," + 
				GetMemberName(TResource(), L"BattleCostValue");
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
	struct ExchangeValue : public SProto
	{
		EResource costResourceType{};
		double rate{};
		ExchangeValue()
		{
		}
		ExchangeValue(const EResource& costResourceType_, const double& rate_) : costResourceType(costResourceType_), rate(rate_)
		{
		}
		ExchangeValue(EResource&& costResourceType_, double&& rate_) : costResourceType(std::move(costResourceType_)), rate(std::move(rate_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> costResourceType;
			Stream_ >> rate;
		}
		void operator << (const Value& Value_) override
		{
			Value_["costResourceType"] >> costResourceType;
			Value_["rate"] >> rate;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << costResourceType;
			Stream_ << rate;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["costResourceType"] = costResourceType;
			Value_["rate"] = rate;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EResource()) + L"," + 
				GetStdName(double());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EResource(), L"costResourceType") + L"," + 
				GetMemberName(double(), L"rate");
		}
	};
	struct ShopExchangeMeta : public SProto
	{
		EResource targetResourceType{};
		ExchangeValue exchangeValue{};
		ShopExchangeMeta()
		{
		}
		ShopExchangeMeta(const EResource& targetResourceType_, const ExchangeValue& exchangeValue_) : targetResourceType(targetResourceType_), exchangeValue(exchangeValue_)
		{
		}
		ShopExchangeMeta(EResource&& targetResourceType_, ExchangeValue&& exchangeValue_) : targetResourceType(std::move(targetResourceType_)), exchangeValue(std::move(exchangeValue_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> targetResourceType;
			Stream_ >> exchangeValue;
		}
		void operator << (const Value& Value_) override
		{
			Value_["targetResourceType"] >> targetResourceType;
			Value_["exchangeValue"] >> exchangeValue;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << targetResourceType;
			Stream_ << exchangeValue;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["targetResourceType"] = targetResourceType;
			Value_["exchangeValue"] = exchangeValue;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EResource()) + L"," + 
				GetStdName(ExchangeValue());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EResource(), L"targetResourceType") + L"," + 
				GetMemberName(ExchangeValue(), L"exchangeValue");
		}
	};
	struct CharacterTypeMeta : public SProto
	{
		EGrade grade{};
		int32 subGrade{};
		wstring howToGet{};
		TResource CostValue{};
		EResource RefundType{};
		TResource RefundValue{};
		float MaxVelAir{};
		float MaxVelXGround{};
		float StaminaMax{};
		float PumpSpeed{};
		float Weight{};
		CharacterTypeMeta()
		{
		}
		CharacterTypeMeta(const EGrade& grade_, const int32& subGrade_, const wstring& howToGet_, const TResource& CostValue_, const EResource& RefundType_, const TResource& RefundValue_, const float& MaxVelAir_, const float& MaxVelXGround_, const float& StaminaMax_, const float& PumpSpeed_, const float& Weight_) : grade(grade_), subGrade(subGrade_), howToGet(howToGet_), CostValue(CostValue_), RefundType(RefundType_), RefundValue(RefundValue_), MaxVelAir(MaxVelAir_), MaxVelXGround(MaxVelXGround_), StaminaMax(StaminaMax_), PumpSpeed(PumpSpeed_), Weight(Weight_)
		{
		}
		CharacterTypeMeta(EGrade&& grade_, int32&& subGrade_, wstring&& howToGet_, TResource&& CostValue_, EResource&& RefundType_, TResource&& RefundValue_, float&& MaxVelAir_, float&& MaxVelXGround_, float&& StaminaMax_, float&& PumpSpeed_, float&& Weight_) : grade(std::move(grade_)), subGrade(std::move(subGrade_)), howToGet(std::move(howToGet_)), CostValue(std::move(CostValue_)), RefundType(std::move(RefundType_)), RefundValue(std::move(RefundValue_)), MaxVelAir(std::move(MaxVelAir_)), MaxVelXGround(std::move(MaxVelXGround_)), StaminaMax(std::move(StaminaMax_)), PumpSpeed(std::move(PumpSpeed_)), Weight(std::move(Weight_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> grade;
			Stream_ >> subGrade;
			Stream_ >> howToGet;
			Stream_ >> CostValue;
			Stream_ >> RefundType;
			Stream_ >> RefundValue;
			Stream_ >> MaxVelAir;
			Stream_ >> MaxVelXGround;
			Stream_ >> StaminaMax;
			Stream_ >> PumpSpeed;
			Stream_ >> Weight;
		}
		void operator << (const Value& Value_) override
		{
			Value_["grade"] >> grade;
			Value_["subGrade"] >> subGrade;
			Value_["howToGet"] >> howToGet;
			Value_["CostValue"] >> CostValue;
			Value_["RefundType"] >> RefundType;
			Value_["RefundValue"] >> RefundValue;
			Value_["MaxVelAir"] >> MaxVelAir;
			Value_["MaxVelXGround"] >> MaxVelXGround;
			Value_["StaminaMax"] >> StaminaMax;
			Value_["PumpSpeed"] >> PumpSpeed;
			Value_["Weight"] >> Weight;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << grade;
			Stream_ << subGrade;
			Stream_ << howToGet;
			Stream_ << CostValue;
			Stream_ << RefundType;
			Stream_ << RefundValue;
			Stream_ << MaxVelAir;
			Stream_ << MaxVelXGround;
			Stream_ << StaminaMax;
			Stream_ << PumpSpeed;
			Stream_ << Weight;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["grade"] = grade;
			Value_["subGrade"] = subGrade;
			Value_["howToGet"] = howToGet;
			Value_["CostValue"] = CostValue;
			Value_["RefundType"] = RefundType;
			Value_["RefundValue"] = RefundValue;
			Value_["MaxVelAir"] = MaxVelAir;
			Value_["MaxVelXGround"] = MaxVelXGround;
			Value_["StaminaMax"] = StaminaMax;
			Value_["PumpSpeed"] = PumpSpeed;
			Value_["Weight"] = Weight;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EGrade()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(EResource()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(float());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EGrade(), L"grade") + L"," + 
				GetMemberName(int32(), L"subGrade") + L"," + 
				GetMemberName(wstring(), L"howToGet") + L"," + 
				GetMemberName(TResource(), L"CostValue") + L"," + 
				GetMemberName(EResource(), L"RefundType") + L"," + 
				GetMemberName(TResource(), L"RefundValue") + L"," + 
				GetMemberName(float(), L"MaxVelAir") + L"," + 
				GetMemberName(float(), L"MaxVelXGround") + L"," + 
				GetMemberName(float(), L"StaminaMax") + L"," + 
				GetMemberName(float(), L"PumpSpeed") + L"," + 
				GetMemberName(float(), L"Weight");
		}
	};
	struct CharacterTypeKeyValueMeta : public SProto
	{
		wstring type{};
		CharacterTypeMeta value{};
		CharacterTypeKeyValueMeta()
		{
		}
		CharacterTypeKeyValueMeta(const wstring& type_, const CharacterTypeMeta& value_) : type(type_), value(value_)
		{
		}
		CharacterTypeKeyValueMeta(wstring&& type_, CharacterTypeMeta&& value_) : type(std::move(type_)), value(std::move(value_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> type;
			Stream_ >> value;
		}
		void operator << (const Value& Value_) override
		{
			Value_["type"] >> type;
			Value_["value"] >> value;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << type;
			Stream_ << value;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["type"] = type;
			Value_["value"] = value;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(CharacterTypeMeta());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"type") + L"," + 
				GetMemberName(CharacterTypeMeta(), L"value");
		}
	};
	struct CharacterMeta : public SProto
	{
		int32 Code{};
		wstring type{};
		bool isDefault{};
		CharacterMeta()
		{
		}
		CharacterMeta(const int32& Code_, const wstring& type_, const bool& isDefault_) : Code(Code_), type(type_), isDefault(isDefault_)
		{
		}
		CharacterMeta(int32&& Code_, wstring&& type_, bool&& isDefault_) : Code(std::move(Code_)), type(std::move(type_)), isDefault(std::move(isDefault_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Code;
			Stream_ >> type;
			Stream_ >> isDefault;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Code"] >> Code;
			Value_["type"] >> type;
			Value_["isDefault"] >> isDefault;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Code;
			Stream_ << type;
			Stream_ << isDefault;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Code"] = Code;
			Value_["type"] = type;
			Value_["isDefault"] = isDefault;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(wstring(), L"type") + L"," + 
				GetMemberName(bool(), L"isDefault");
		}
	};
	using TPoses = vector<SPoint>;
	struct SMultiMap : public SPoint
	{
		int32 index{};
		wstring PrefabName{};
		TPoses Poses{};
		list<SBoxCollider2D> Structures{};
		list<SStructureMove> StructureMoves{};
		SMultiMap()
		{
		}
		SMultiMap(const SPoint& Super_, const int32& index_, const wstring& PrefabName_, const TPoses& Poses_, const list<SBoxCollider2D>& Structures_, const list<SStructureMove>& StructureMoves_) : SPoint(Super_), index(index_), PrefabName(PrefabName_), Poses(Poses_), Structures(Structures_), StructureMoves(StructureMoves_)
		{
		}
		SMultiMap(SPoint&& Super_, int32&& index_, wstring&& PrefabName_, TPoses&& Poses_, list<SBoxCollider2D>&& Structures_, list<SStructureMove>&& StructureMoves_) : SPoint(std::move(Super_)), index(std::move(index_)), PrefabName(std::move(PrefabName_)), Poses(std::move(Poses_)), Structures(std::move(Structures_)), StructureMoves(std::move(StructureMoves_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SPoint::operator << (Stream_);
			Stream_ >> index;
			Stream_ >> PrefabName;
			Stream_ >> Poses;
			Stream_ >> Structures;
			Stream_ >> StructureMoves;
		}
		void operator << (const Value& Value_) override
		{
			SPoint::operator << (Value_);
			Value_["index"] >> index;
			Value_["PrefabName"] >> PrefabName;
			Value_["Poses"] >> Poses;
			Value_["Structures"] >> Structures;
			Value_["StructureMoves"] >> StructureMoves;
		}
		void operator >> (CStream& Stream_) const override
		{
			SPoint::operator >> (Stream_);
			Stream_ << index;
			Stream_ << PrefabName;
			Stream_ << Poses;
			Stream_ << Structures;
			Stream_ << StructureMoves;
		}
		void operator >> (Value& Value_) const override
		{
			SPoint::operator >> (Value_);
			Value_["index"] = index;
			Value_["PrefabName"] = PrefabName;
			Value_["Poses"] = Poses;
			Value_["Structures"] = Structures;
			Value_["StructureMoves"] = StructureMoves;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SPoint()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(TPoses()) + L"," + 
				GetStdName(list<SBoxCollider2D>()) + L"," + 
				GetStdName(list<SStructureMove>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SPoint(), L"") + L"," + 
				GetMemberName(int32(), L"index") + L"," + 
				GetMemberName(wstring(), L"PrefabName") + L"," + 
				GetMemberName(TPoses(), L"Poses") + L"," + 
				GetMemberName(list<SBoxCollider2D>(), L"Structures") + L"," + 
				GetMemberName(list<SStructureMove>(), L"StructureMoves");
		}
	};
	struct SPrefabNameCollider : public SProto
	{
		wstring PrefabName{};
		SRectCollider2D Collider{};
		SPrefabNameCollider()
		{
		}
		SPrefabNameCollider(const wstring& PrefabName_, const SRectCollider2D& Collider_) : PrefabName(PrefabName_), Collider(Collider_)
		{
		}
		SPrefabNameCollider(wstring&& PrefabName_, SRectCollider2D&& Collider_) : PrefabName(std::move(PrefabName_)), Collider(std::move(Collider_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> PrefabName;
			Stream_ >> Collider;
		}
		void operator << (const Value& Value_) override
		{
			Value_["PrefabName"] >> PrefabName;
			Value_["Collider"] >> Collider;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << PrefabName;
			Stream_ << Collider;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["PrefabName"] = PrefabName;
			Value_["Collider"] = Collider;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(SRectCollider2D());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"PrefabName") + L"," + 
				GetMemberName(SRectCollider2D(), L"Collider");
		}
	};
	struct SArrowDodgeMap : public SPoint
	{
		wstring PrefabName{};
		list<SBoxCollider2D> Structures{};
		SArrowDodgeMap()
		{
		}
		SArrowDodgeMap(const SPoint& Super_, const wstring& PrefabName_, const list<SBoxCollider2D>& Structures_) : SPoint(Super_), PrefabName(PrefabName_), Structures(Structures_)
		{
		}
		SArrowDodgeMap(SPoint&& Super_, wstring&& PrefabName_, list<SBoxCollider2D>&& Structures_) : SPoint(std::move(Super_)), PrefabName(std::move(PrefabName_)), Structures(std::move(Structures_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SPoint::operator << (Stream_);
			Stream_ >> PrefabName;
			Stream_ >> Structures;
		}
		void operator << (const Value& Value_) override
		{
			SPoint::operator << (Value_);
			Value_["PrefabName"] >> PrefabName;
			Value_["Structures"] >> Structures;
		}
		void operator >> (CStream& Stream_) const override
		{
			SPoint::operator >> (Stream_);
			Stream_ << PrefabName;
			Stream_ << Structures;
		}
		void operator >> (Value& Value_) const override
		{
			SPoint::operator >> (Value_);
			Value_["PrefabName"] = PrefabName;
			Value_["Structures"] = Structures;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SPoint()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(list<SBoxCollider2D>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SPoint(), L"") + L"," + 
				GetMemberName(wstring(), L"PrefabName") + L"," + 
				GetMemberName(list<SBoxCollider2D>(), L"Structures");
		}
	};
	struct SArrowDodgeMapInfo : public SProto
	{
		vector<SArrowDodgeMap> Maps{};
		SPrefabNameCollider Arrow{};
		SPrefabNameCollider Coin{};
		SPrefabNameCollider GoldBar{};
		SPrefabNameCollider Shield{};
		SPrefabNameCollider Stamina{};
		SArrowDodgeMapInfo()
		{
		}
		SArrowDodgeMapInfo(const vector<SArrowDodgeMap>& Maps_, const SPrefabNameCollider& Arrow_, const SPrefabNameCollider& Coin_, const SPrefabNameCollider& GoldBar_, const SPrefabNameCollider& Shield_, const SPrefabNameCollider& Stamina_) : Maps(Maps_), Arrow(Arrow_), Coin(Coin_), GoldBar(GoldBar_), Shield(Shield_), Stamina(Stamina_)
		{
		}
		SArrowDodgeMapInfo(vector<SArrowDodgeMap>&& Maps_, SPrefabNameCollider&& Arrow_, SPrefabNameCollider&& Coin_, SPrefabNameCollider&& GoldBar_, SPrefabNameCollider&& Shield_, SPrefabNameCollider&& Stamina_) : Maps(std::move(Maps_)), Arrow(std::move(Arrow_)), Coin(std::move(Coin_)), GoldBar(std::move(GoldBar_)), Shield(std::move(Shield_)), Stamina(std::move(Stamina_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Maps;
			Stream_ >> Arrow;
			Stream_ >> Coin;
			Stream_ >> GoldBar;
			Stream_ >> Shield;
			Stream_ >> Stamina;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Maps"] >> Maps;
			Value_["Arrow"] >> Arrow;
			Value_["Coin"] >> Coin;
			Value_["GoldBar"] >> GoldBar;
			Value_["Shield"] >> Shield;
			Value_["Stamina"] >> Stamina;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Maps;
			Stream_ << Arrow;
			Stream_ << Coin;
			Stream_ << GoldBar;
			Stream_ << Shield;
			Stream_ << Stamina;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Maps"] = Maps;
			Value_["Arrow"] = Arrow;
			Value_["Coin"] = Coin;
			Value_["GoldBar"] = GoldBar;
			Value_["Shield"] = Shield;
			Value_["Stamina"] = Stamina;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(vector<SArrowDodgeMap>()) + L"," + 
				GetStdName(SPrefabNameCollider()) + L"," + 
				GetStdName(SPrefabNameCollider()) + L"," + 
				GetStdName(SPrefabNameCollider()) + L"," + 
				GetStdName(SPrefabNameCollider()) + L"," + 
				GetStdName(SPrefabNameCollider());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(vector<SArrowDodgeMap>(), L"Maps") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"Arrow") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"Coin") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"GoldBar") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"Shield") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"Stamina");
		}
	};
	struct SFlyAwayMap : public SPoint
	{
		wstring PrefabName{};
		list<SBoxCollider2D> Structures{};
		list<SBoxCollider2D> deadZones{};
		SBoxCollider2D ocean{};
		SFlyAwayMap()
		{
		}
		SFlyAwayMap(const SPoint& Super_, const wstring& PrefabName_, const list<SBoxCollider2D>& Structures_, const list<SBoxCollider2D>& deadZones_, const SBoxCollider2D& ocean_) : SPoint(Super_), PrefabName(PrefabName_), Structures(Structures_), deadZones(deadZones_), ocean(ocean_)
		{
		}
		SFlyAwayMap(SPoint&& Super_, wstring&& PrefabName_, list<SBoxCollider2D>&& Structures_, list<SBoxCollider2D>&& deadZones_, SBoxCollider2D&& ocean_) : SPoint(std::move(Super_)), PrefabName(std::move(PrefabName_)), Structures(std::move(Structures_)), deadZones(std::move(deadZones_)), ocean(std::move(ocean_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SPoint::operator << (Stream_);
			Stream_ >> PrefabName;
			Stream_ >> Structures;
			Stream_ >> deadZones;
			Stream_ >> ocean;
		}
		void operator << (const Value& Value_) override
		{
			SPoint::operator << (Value_);
			Value_["PrefabName"] >> PrefabName;
			Value_["Structures"] >> Structures;
			Value_["deadZones"] >> deadZones;
			Value_["ocean"] >> ocean;
		}
		void operator >> (CStream& Stream_) const override
		{
			SPoint::operator >> (Stream_);
			Stream_ << PrefabName;
			Stream_ << Structures;
			Stream_ << deadZones;
			Stream_ << ocean;
		}
		void operator >> (Value& Value_) const override
		{
			SPoint::operator >> (Value_);
			Value_["PrefabName"] = PrefabName;
			Value_["Structures"] = Structures;
			Value_["deadZones"] = deadZones;
			Value_["ocean"] = ocean;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SPoint()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(list<SBoxCollider2D>()) + L"," + 
				GetStdName(list<SBoxCollider2D>()) + L"," + 
				GetStdName(SBoxCollider2D());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SPoint(), L"") + L"," + 
				GetMemberName(wstring(), L"PrefabName") + L"," + 
				GetMemberName(list<SBoxCollider2D>(), L"Structures") + L"," + 
				GetMemberName(list<SBoxCollider2D>(), L"deadZones") + L"," + 
				GetMemberName(SBoxCollider2D(), L"ocean");
		}
	};
	struct SFlyAwayMapInfo : public SProto
	{
		vector<SFlyAwayMap> Maps{};
		vector<SPrefabNameCollider> Lands{};
		SPrefabNameCollider Coin{};
		SPrefabNameCollider GoldBar{};
		SPrefabNameCollider Apple{};
		SPrefabNameCollider Meat{};
		SPrefabNameCollider Chicken{};
		SFlyAwayMapInfo()
		{
		}
		SFlyAwayMapInfo(const vector<SFlyAwayMap>& Maps_, const vector<SPrefabNameCollider>& Lands_, const SPrefabNameCollider& Coin_, const SPrefabNameCollider& GoldBar_, const SPrefabNameCollider& Apple_, const SPrefabNameCollider& Meat_, const SPrefabNameCollider& Chicken_) : Maps(Maps_), Lands(Lands_), Coin(Coin_), GoldBar(GoldBar_), Apple(Apple_), Meat(Meat_), Chicken(Chicken_)
		{
		}
		SFlyAwayMapInfo(vector<SFlyAwayMap>&& Maps_, vector<SPrefabNameCollider>&& Lands_, SPrefabNameCollider&& Coin_, SPrefabNameCollider&& GoldBar_, SPrefabNameCollider&& Apple_, SPrefabNameCollider&& Meat_, SPrefabNameCollider&& Chicken_) : Maps(std::move(Maps_)), Lands(std::move(Lands_)), Coin(std::move(Coin_)), GoldBar(std::move(GoldBar_)), Apple(std::move(Apple_)), Meat(std::move(Meat_)), Chicken(std::move(Chicken_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Maps;
			Stream_ >> Lands;
			Stream_ >> Coin;
			Stream_ >> GoldBar;
			Stream_ >> Apple;
			Stream_ >> Meat;
			Stream_ >> Chicken;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Maps"] >> Maps;
			Value_["Lands"] >> Lands;
			Value_["Coin"] >> Coin;
			Value_["GoldBar"] >> GoldBar;
			Value_["Apple"] >> Apple;
			Value_["Meat"] >> Meat;
			Value_["Chicken"] >> Chicken;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Maps;
			Stream_ << Lands;
			Stream_ << Coin;
			Stream_ << GoldBar;
			Stream_ << Apple;
			Stream_ << Meat;
			Stream_ << Chicken;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Maps"] = Maps;
			Value_["Lands"] = Lands;
			Value_["Coin"] = Coin;
			Value_["GoldBar"] = GoldBar;
			Value_["Apple"] = Apple;
			Value_["Meat"] = Meat;
			Value_["Chicken"] = Chicken;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(vector<SFlyAwayMap>()) + L"," + 
				GetStdName(vector<SPrefabNameCollider>()) + L"," + 
				GetStdName(SPrefabNameCollider()) + L"," + 
				GetStdName(SPrefabNameCollider()) + L"," + 
				GetStdName(SPrefabNameCollider()) + L"," + 
				GetStdName(SPrefabNameCollider()) + L"," + 
				GetStdName(SPrefabNameCollider());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(vector<SFlyAwayMap>(), L"Maps") + L"," + 
				GetMemberName(vector<SPrefabNameCollider>(), L"Lands") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"Coin") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"GoldBar") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"Apple") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"Meat") + L"," + 
				GetMemberName(SPrefabNameCollider(), L"Chicken");
		}
	};
	struct SMapMeta : public SProto
	{
		vector<SMultiMap> OneOnOneMaps{};
		SArrowDodgeMapInfo ArrowDodgeMapInfo{};
		SFlyAwayMapInfo FlyAwayMapInfo{};
		SMapMeta()
		{
		}
		SMapMeta(const vector<SMultiMap>& OneOnOneMaps_, const SArrowDodgeMapInfo& ArrowDodgeMapInfo_, const SFlyAwayMapInfo& FlyAwayMapInfo_) : OneOnOneMaps(OneOnOneMaps_), ArrowDodgeMapInfo(ArrowDodgeMapInfo_), FlyAwayMapInfo(FlyAwayMapInfo_)
		{
		}
		SMapMeta(vector<SMultiMap>&& OneOnOneMaps_, SArrowDodgeMapInfo&& ArrowDodgeMapInfo_, SFlyAwayMapInfo&& FlyAwayMapInfo_) : OneOnOneMaps(std::move(OneOnOneMaps_)), ArrowDodgeMapInfo(std::move(ArrowDodgeMapInfo_)), FlyAwayMapInfo(std::move(FlyAwayMapInfo_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> OneOnOneMaps;
			Stream_ >> ArrowDodgeMapInfo;
			Stream_ >> FlyAwayMapInfo;
		}
		void operator << (const Value& Value_) override
		{
			Value_["OneOnOneMaps"] >> OneOnOneMaps;
			Value_["ArrowDodgeMapInfo"] >> ArrowDodgeMapInfo;
			Value_["FlyAwayMapInfo"] >> FlyAwayMapInfo;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << OneOnOneMaps;
			Stream_ << ArrowDodgeMapInfo;
			Stream_ << FlyAwayMapInfo;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["OneOnOneMaps"] = OneOnOneMaps;
			Value_["ArrowDodgeMapInfo"] = ArrowDodgeMapInfo;
			Value_["FlyAwayMapInfo"] = FlyAwayMapInfo;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(vector<SMultiMap>()) + L"," + 
				GetStdName(SArrowDodgeMapInfo()) + L"," + 
				GetStdName(SFlyAwayMapInfo());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(vector<SMultiMap>(), L"OneOnOneMaps") + L"," + 
				GetMemberName(SArrowDodgeMapInfo(), L"ArrowDodgeMapInfo") + L"," + 
				GetMemberName(SFlyAwayMapInfo(), L"FlyAwayMapInfo");
		}
	};
	struct SRankTierMeta : public SProto
	{
		ERank Rank{};
		int32 Tier{};
		int32 MaxPoint{};
		SRankTierMeta()
		{
		}
		SRankTierMeta(const ERank& Rank_, const int32& Tier_, const int32& MaxPoint_) : Rank(Rank_), Tier(Tier_), MaxPoint(MaxPoint_)
		{
		}
		SRankTierMeta(ERank&& Rank_, int32&& Tier_, int32&& MaxPoint_) : Rank(std::move(Rank_)), Tier(std::move(Tier_)), MaxPoint(std::move(MaxPoint_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Rank;
			Stream_ >> Tier;
			Stream_ >> MaxPoint;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Rank"] >> Rank;
			Value_["Tier"] >> Tier;
			Value_["MaxPoint"] >> MaxPoint;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Rank;
			Stream_ << Tier;
			Stream_ << MaxPoint;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Rank"] = Rank;
			Value_["Tier"] = Tier;
			Value_["MaxPoint"] = MaxPoint;
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
				GetMemberName(int32(), L"MaxPoint");
		}
	};
	struct SRankRewardMeta : public SProto
	{
		int32 point{};
		wstring rewardType{};
		int32 rewardValue{};
		SRankRewardMeta()
		{
		}
		SRankRewardMeta(const int32& point_, const wstring& rewardType_, const int32& rewardValue_) : point(point_), rewardType(rewardType_), rewardValue(rewardValue_)
		{
		}
		SRankRewardMeta(int32&& point_, wstring&& rewardType_, int32&& rewardValue_) : point(std::move(point_)), rewardType(std::move(rewardType_)), rewardValue(std::move(rewardValue_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> point;
			Stream_ >> rewardType;
			Stream_ >> rewardValue;
		}
		void operator << (const Value& Value_) override
		{
			Value_["point"] >> point;
			Value_["rewardType"] >> rewardType;
			Value_["rewardValue"] >> rewardValue;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << point;
			Stream_ << rewardType;
			Stream_ << rewardValue;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["point"] = point;
			Value_["rewardType"] = rewardType;
			Value_["rewardValue"] = rewardValue;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"point") + L"," + 
				GetMemberName(wstring(), L"rewardType") + L"," + 
				GetMemberName(int32(), L"rewardValue");
		}
	};
	struct SQuestMeta : public SProto
	{
		EQuestType QuestType{};
		int32 Code{};
		int32 unitCompleteCount{};
		int32 completeCount{};
		wstring rewardType{};
		int32 rewardValue{};
		SQuestMeta()
		{
		}
		SQuestMeta(const EQuestType& QuestType_, const int32& Code_, const int32& unitCompleteCount_, const int32& completeCount_, const wstring& rewardType_, const int32& rewardValue_) : QuestType(QuestType_), Code(Code_), unitCompleteCount(unitCompleteCount_), completeCount(completeCount_), rewardType(rewardType_), rewardValue(rewardValue_)
		{
		}
		SQuestMeta(EQuestType&& QuestType_, int32&& Code_, int32&& unitCompleteCount_, int32&& completeCount_, wstring&& rewardType_, int32&& rewardValue_) : QuestType(std::move(QuestType_)), Code(std::move(Code_)), unitCompleteCount(std::move(unitCompleteCount_)), completeCount(std::move(completeCount_)), rewardType(std::move(rewardType_)), rewardValue(std::move(rewardValue_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> QuestType;
			Stream_ >> Code;
			Stream_ >> unitCompleteCount;
			Stream_ >> completeCount;
			Stream_ >> rewardType;
			Stream_ >> rewardValue;
		}
		void operator << (const Value& Value_) override
		{
			Value_["QuestType"] >> QuestType;
			Value_["Code"] >> Code;
			Value_["unitCompleteCount"] >> unitCompleteCount;
			Value_["completeCount"] >> completeCount;
			Value_["rewardType"] >> rewardType;
			Value_["rewardValue"] >> rewardValue;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << QuestType;
			Stream_ << Code;
			Stream_ << unitCompleteCount;
			Stream_ << completeCount;
			Stream_ << rewardType;
			Stream_ << rewardValue;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["QuestType"] = QuestType;
			Value_["Code"] = Code;
			Value_["unitCompleteCount"] = unitCompleteCount;
			Value_["completeCount"] = completeCount;
			Value_["rewardType"] = rewardType;
			Value_["rewardValue"] = rewardValue;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EQuestType()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EQuestType(), L"QuestType") + L"," + 
				GetMemberName(int32(), L"Code") + L"," + 
				GetMemberName(int32(), L"unitCompleteCount") + L"," + 
				GetMemberName(int32(), L"completeCount") + L"," + 
				GetMemberName(wstring(), L"rewardType") + L"," + 
				GetMemberName(int32(), L"rewardValue");
		}
	};
	struct QuestConfigMeta : public SProto
	{
		minutes coolMinutes{};
		int32 dailyRequirementCount{};
		wstring dailyRewardType{};
		int32 dailyRewardValue{};
		minutes dailyRefreshMinutes{};
		QuestConfigMeta()
		{
		}
		QuestConfigMeta(const minutes& coolMinutes_, const int32& dailyRequirementCount_, const wstring& dailyRewardType_, const int32& dailyRewardValue_, const minutes& dailyRefreshMinutes_) : coolMinutes(coolMinutes_), dailyRequirementCount(dailyRequirementCount_), dailyRewardType(dailyRewardType_), dailyRewardValue(dailyRewardValue_), dailyRefreshMinutes(dailyRefreshMinutes_)
		{
		}
		QuestConfigMeta(minutes&& coolMinutes_, int32&& dailyRequirementCount_, wstring&& dailyRewardType_, int32&& dailyRewardValue_, minutes&& dailyRefreshMinutes_) : coolMinutes(std::move(coolMinutes_)), dailyRequirementCount(std::move(dailyRequirementCount_)), dailyRewardType(std::move(dailyRewardType_)), dailyRewardValue(std::move(dailyRewardValue_)), dailyRefreshMinutes(std::move(dailyRefreshMinutes_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> coolMinutes;
			Stream_ >> dailyRequirementCount;
			Stream_ >> dailyRewardType;
			Stream_ >> dailyRewardValue;
			Stream_ >> dailyRefreshMinutes;
		}
		void operator << (const Value& Value_) override
		{
			Value_["coolMinutes"] >> coolMinutes;
			Value_["dailyRequirementCount"] >> dailyRequirementCount;
			Value_["dailyRewardType"] >> dailyRewardType;
			Value_["dailyRewardValue"] >> dailyRewardValue;
			Value_["dailyRefreshMinutes"] >> dailyRefreshMinutes;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << coolMinutes;
			Stream_ << dailyRequirementCount;
			Stream_ << dailyRewardType;
			Stream_ << dailyRewardValue;
			Stream_ << dailyRefreshMinutes;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["coolMinutes"] = coolMinutes;
			Value_["dailyRequirementCount"] = dailyRequirementCount;
			Value_["dailyRewardType"] = dailyRewardType;
			Value_["dailyRewardValue"] = dailyRewardValue;
			Value_["dailyRefreshMinutes"] = dailyRefreshMinutes;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(minutes()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(minutes());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(minutes(), L"coolMinutes") + L"," + 
				GetMemberName(int32(), L"dailyRequirementCount") + L"," + 
				GetMemberName(wstring(), L"dailyRewardType") + L"," + 
				GetMemberName(int32(), L"dailyRewardValue") + L"," + 
				GetMemberName(minutes(), L"dailyRefreshMinutes");
		}
	};
	struct MultiBattleConfigMeta : public SProto
	{
		int32 DisconnectableSeconds{};
		int32 PunishMinutesForDisconnect{};
		TResource rewardDiaValue{};
		int32 eloDiffPoint{};
		double eloDiffWinRatio{};
		double eloKWeight{};
		MultiBattleConfigMeta()
		{
		}
		MultiBattleConfigMeta(const int32& DisconnectableSeconds_, const int32& PunishMinutesForDisconnect_, const TResource& rewardDiaValue_, const int32& eloDiffPoint_, const double& eloDiffWinRatio_, const double& eloKWeight_) : DisconnectableSeconds(DisconnectableSeconds_), PunishMinutesForDisconnect(PunishMinutesForDisconnect_), rewardDiaValue(rewardDiaValue_), eloDiffPoint(eloDiffPoint_), eloDiffWinRatio(eloDiffWinRatio_), eloKWeight(eloKWeight_)
		{
		}
		MultiBattleConfigMeta(int32&& DisconnectableSeconds_, int32&& PunishMinutesForDisconnect_, TResource&& rewardDiaValue_, int32&& eloDiffPoint_, double&& eloDiffWinRatio_, double&& eloKWeight_) : DisconnectableSeconds(std::move(DisconnectableSeconds_)), PunishMinutesForDisconnect(std::move(PunishMinutesForDisconnect_)), rewardDiaValue(std::move(rewardDiaValue_)), eloDiffPoint(std::move(eloDiffPoint_)), eloDiffWinRatio(std::move(eloDiffWinRatio_)), eloKWeight(std::move(eloKWeight_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> DisconnectableSeconds;
			Stream_ >> PunishMinutesForDisconnect;
			Stream_ >> rewardDiaValue;
			Stream_ >> eloDiffPoint;
			Stream_ >> eloDiffWinRatio;
			Stream_ >> eloKWeight;
		}
		void operator << (const Value& Value_) override
		{
			Value_["DisconnectableSeconds"] >> DisconnectableSeconds;
			Value_["PunishMinutesForDisconnect"] >> PunishMinutesForDisconnect;
			Value_["rewardDiaValue"] >> rewardDiaValue;
			Value_["eloDiffPoint"] >> eloDiffPoint;
			Value_["eloDiffWinRatio"] >> eloDiffWinRatio;
			Value_["eloKWeight"] >> eloKWeight;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << DisconnectableSeconds;
			Stream_ << PunishMinutesForDisconnect;
			Stream_ << rewardDiaValue;
			Stream_ << eloDiffPoint;
			Stream_ << eloDiffWinRatio;
			Stream_ << eloKWeight;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["DisconnectableSeconds"] = DisconnectableSeconds;
			Value_["PunishMinutesForDisconnect"] = PunishMinutesForDisconnect;
			Value_["rewardDiaValue"] = rewardDiaValue;
			Value_["eloDiffPoint"] = eloDiffPoint;
			Value_["eloDiffWinRatio"] = eloDiffWinRatio;
			Value_["eloKWeight"] = eloKWeight;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(double()) + L"," + 
				GetStdName(double());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"DisconnectableSeconds") + L"," + 
				GetMemberName(int32(), L"PunishMinutesForDisconnect") + L"," + 
				GetMemberName(TResource(), L"rewardDiaValue") + L"," + 
				GetMemberName(int32(), L"eloDiffPoint") + L"," + 
				GetMemberName(double(), L"eloDiffWinRatio") + L"," + 
				GetMemberName(double(), L"eloKWeight");
		}
	};
	struct MultiBattleDiaRewardMeta : public SProto
	{
		EResource diaType{};
		double ratio{};
		MultiBattleDiaRewardMeta()
		{
		}
		MultiBattleDiaRewardMeta(const EResource& diaType_, const double& ratio_) : diaType(diaType_), ratio(ratio_)
		{
		}
		MultiBattleDiaRewardMeta(EResource&& diaType_, double&& ratio_) : diaType(std::move(diaType_)), ratio(std::move(ratio_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> diaType;
			Stream_ >> ratio;
		}
		void operator << (const Value& Value_) override
		{
			Value_["diaType"] >> diaType;
			Value_["ratio"] >> ratio;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << diaType;
			Stream_ << ratio;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["diaType"] = diaType;
			Value_["ratio"] = ratio;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EResource()) + L"," + 
				GetStdName(double());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EResource(), L"diaType") + L"," + 
				GetMemberName(double(), L"ratio");
		}
	};
	struct SMultiMatchDeniedDurationMeta : public SProto
	{
		int32 DisconnectedCount{};
		int32 DeniedSeconds{};
		SMultiMatchDeniedDurationMeta()
		{
		}
		SMultiMatchDeniedDurationMeta(const int32& DisconnectedCount_, const int32& DeniedSeconds_) : DisconnectedCount(DisconnectedCount_), DeniedSeconds(DeniedSeconds_)
		{
		}
		SMultiMatchDeniedDurationMeta(int32&& DisconnectedCount_, int32&& DeniedSeconds_) : DisconnectedCount(std::move(DisconnectedCount_)), DeniedSeconds(std::move(DeniedSeconds_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> DisconnectedCount;
			Stream_ >> DeniedSeconds;
		}
		void operator << (const Value& Value_) override
		{
			Value_["DisconnectedCount"] >> DisconnectedCount;
			Value_["DeniedSeconds"] >> DeniedSeconds;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << DisconnectedCount;
			Stream_ << DeniedSeconds;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["DisconnectedCount"] = DisconnectedCount;
			Value_["DeniedSeconds"] = DeniedSeconds;
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
				GetMemberName(int32(), L"DisconnectedCount") + L"," + 
				GetMemberName(int32(), L"DeniedSeconds");
		}
	};
	struct ArrowDodgeConfigMeta : public SProto
	{
		int32 ArrowDodgePoint{};
		int32 ArrowGetPoint{};
		int64 ItemDurationTick{};
		int64 ItemRegenPeriodTick{};
		int32 maxItemCount{};
		int32 PlayCountMax{};
		TResource ChargeCostGold{};
		int32 RefreshDurationMinute{};
		int32 scorePerGold{};
		ArrowDodgeConfigMeta()
		{
		}
		ArrowDodgeConfigMeta(const int32& ArrowDodgePoint_, const int32& ArrowGetPoint_, const int64& ItemDurationTick_, const int64& ItemRegenPeriodTick_, const int32& maxItemCount_, const int32& PlayCountMax_, const TResource& ChargeCostGold_, const int32& RefreshDurationMinute_, const int32& scorePerGold_) : ArrowDodgePoint(ArrowDodgePoint_), ArrowGetPoint(ArrowGetPoint_), ItemDurationTick(ItemDurationTick_), ItemRegenPeriodTick(ItemRegenPeriodTick_), maxItemCount(maxItemCount_), PlayCountMax(PlayCountMax_), ChargeCostGold(ChargeCostGold_), RefreshDurationMinute(RefreshDurationMinute_), scorePerGold(scorePerGold_)
		{
		}
		ArrowDodgeConfigMeta(int32&& ArrowDodgePoint_, int32&& ArrowGetPoint_, int64&& ItemDurationTick_, int64&& ItemRegenPeriodTick_, int32&& maxItemCount_, int32&& PlayCountMax_, TResource&& ChargeCostGold_, int32&& RefreshDurationMinute_, int32&& scorePerGold_) : ArrowDodgePoint(std::move(ArrowDodgePoint_)), ArrowGetPoint(std::move(ArrowGetPoint_)), ItemDurationTick(std::move(ItemDurationTick_)), ItemRegenPeriodTick(std::move(ItemRegenPeriodTick_)), maxItemCount(std::move(maxItemCount_)), PlayCountMax(std::move(PlayCountMax_)), ChargeCostGold(std::move(ChargeCostGold_)), RefreshDurationMinute(std::move(RefreshDurationMinute_)), scorePerGold(std::move(scorePerGold_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> ArrowDodgePoint;
			Stream_ >> ArrowGetPoint;
			Stream_ >> ItemDurationTick;
			Stream_ >> ItemRegenPeriodTick;
			Stream_ >> maxItemCount;
			Stream_ >> PlayCountMax;
			Stream_ >> ChargeCostGold;
			Stream_ >> RefreshDurationMinute;
			Stream_ >> scorePerGold;
		}
		void operator << (const Value& Value_) override
		{
			Value_["ArrowDodgePoint"] >> ArrowDodgePoint;
			Value_["ArrowGetPoint"] >> ArrowGetPoint;
			Value_["ItemDurationTick"] >> ItemDurationTick;
			Value_["ItemRegenPeriodTick"] >> ItemRegenPeriodTick;
			Value_["maxItemCount"] >> maxItemCount;
			Value_["PlayCountMax"] >> PlayCountMax;
			Value_["ChargeCostGold"] >> ChargeCostGold;
			Value_["RefreshDurationMinute"] >> RefreshDurationMinute;
			Value_["scorePerGold"] >> scorePerGold;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << ArrowDodgePoint;
			Stream_ << ArrowGetPoint;
			Stream_ << ItemDurationTick;
			Stream_ << ItemRegenPeriodTick;
			Stream_ << maxItemCount;
			Stream_ << PlayCountMax;
			Stream_ << ChargeCostGold;
			Stream_ << RefreshDurationMinute;
			Stream_ << scorePerGold;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["ArrowDodgePoint"] = ArrowDodgePoint;
			Value_["ArrowGetPoint"] = ArrowGetPoint;
			Value_["ItemDurationTick"] = ItemDurationTick;
			Value_["ItemRegenPeriodTick"] = ItemRegenPeriodTick;
			Value_["maxItemCount"] = maxItemCount;
			Value_["PlayCountMax"] = PlayCountMax;
			Value_["ChargeCostGold"] = ChargeCostGold;
			Value_["RefreshDurationMinute"] = RefreshDurationMinute;
			Value_["scorePerGold"] = scorePerGold;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"ArrowDodgePoint") + L"," + 
				GetMemberName(int32(), L"ArrowGetPoint") + L"," + 
				GetMemberName(int64(), L"ItemDurationTick") + L"," + 
				GetMemberName(int64(), L"ItemRegenPeriodTick") + L"," + 
				GetMemberName(int32(), L"maxItemCount") + L"," + 
				GetMemberName(int32(), L"PlayCountMax") + L"," + 
				GetMemberName(TResource(), L"ChargeCostGold") + L"," + 
				GetMemberName(int32(), L"RefreshDurationMinute") + L"," + 
				GetMemberName(int32(), L"scorePerGold");
		}
	};
	struct SArrowDodgeItemMeta : public SProto
	{
		EArrowDodgeItemType ItemType{};
		uint32 CreateWeight{};
		TResource AddedGold{};
		SArrowDodgeItemMeta()
		{
		}
		SArrowDodgeItemMeta(const EArrowDodgeItemType& ItemType_, const uint32& CreateWeight_, const TResource& AddedGold_) : ItemType(ItemType_), CreateWeight(CreateWeight_), AddedGold(AddedGold_)
		{
		}
		SArrowDodgeItemMeta(EArrowDodgeItemType&& ItemType_, uint32&& CreateWeight_, TResource&& AddedGold_) : ItemType(std::move(ItemType_)), CreateWeight(std::move(CreateWeight_)), AddedGold(std::move(AddedGold_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> ItemType;
			Stream_ >> CreateWeight;
			Stream_ >> AddedGold;
		}
		void operator << (const Value& Value_) override
		{
			Value_["ItemType"] >> ItemType;
			Value_["CreateWeight"] >> CreateWeight;
			Value_["AddedGold"] >> AddedGold;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << ItemType;
			Stream_ << CreateWeight;
			Stream_ << AddedGold;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["ItemType"] = ItemType;
			Value_["CreateWeight"] = CreateWeight;
			Value_["AddedGold"] = AddedGold;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EArrowDodgeItemType()) + L"," + 
				GetStdName(uint32()) + L"," + 
				GetStdName(TResource());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EArrowDodgeItemType(), L"ItemType") + L"," + 
				GetMemberName(uint32(), L"CreateWeight") + L"," + 
				GetMemberName(TResource(), L"AddedGold");
		}
	};
	struct FlyAwayConfigMeta : public SProto
	{
		int32 maxComboMultiplier{};
		float landingAddedStamina{};
		int32 PlayCountMax{};
		TResource ChargeCostGold{};
		int32 RefreshDurationMinute{};
		int32 scorePerGold{};
		FlyAwayConfigMeta()
		{
		}
		FlyAwayConfigMeta(const int32& maxComboMultiplier_, const float& landingAddedStamina_, const int32& PlayCountMax_, const TResource& ChargeCostGold_, const int32& RefreshDurationMinute_, const int32& scorePerGold_) : maxComboMultiplier(maxComboMultiplier_), landingAddedStamina(landingAddedStamina_), PlayCountMax(PlayCountMax_), ChargeCostGold(ChargeCostGold_), RefreshDurationMinute(RefreshDurationMinute_), scorePerGold(scorePerGold_)
		{
		}
		FlyAwayConfigMeta(int32&& maxComboMultiplier_, float&& landingAddedStamina_, int32&& PlayCountMax_, TResource&& ChargeCostGold_, int32&& RefreshDurationMinute_, int32&& scorePerGold_) : maxComboMultiplier(std::move(maxComboMultiplier_)), landingAddedStamina(std::move(landingAddedStamina_)), PlayCountMax(std::move(PlayCountMax_)), ChargeCostGold(std::move(ChargeCostGold_)), RefreshDurationMinute(std::move(RefreshDurationMinute_)), scorePerGold(std::move(scorePerGold_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> maxComboMultiplier;
			Stream_ >> landingAddedStamina;
			Stream_ >> PlayCountMax;
			Stream_ >> ChargeCostGold;
			Stream_ >> RefreshDurationMinute;
			Stream_ >> scorePerGold;
		}
		void operator << (const Value& Value_) override
		{
			Value_["maxComboMultiplier"] >> maxComboMultiplier;
			Value_["landingAddedStamina"] >> landingAddedStamina;
			Value_["PlayCountMax"] >> PlayCountMax;
			Value_["ChargeCostGold"] >> ChargeCostGold;
			Value_["RefreshDurationMinute"] >> RefreshDurationMinute;
			Value_["scorePerGold"] >> scorePerGold;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << maxComboMultiplier;
			Stream_ << landingAddedStamina;
			Stream_ << PlayCountMax;
			Stream_ << ChargeCostGold;
			Stream_ << RefreshDurationMinute;
			Stream_ << scorePerGold;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["maxComboMultiplier"] = maxComboMultiplier;
			Value_["landingAddedStamina"] = landingAddedStamina;
			Value_["PlayCountMax"] = PlayCountMax;
			Value_["ChargeCostGold"] = ChargeCostGold;
			Value_["RefreshDurationMinute"] = RefreshDurationMinute;
			Value_["scorePerGold"] = scorePerGold;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(float()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"maxComboMultiplier") + L"," + 
				GetMemberName(float(), L"landingAddedStamina") + L"," + 
				GetMemberName(int32(), L"PlayCountMax") + L"," + 
				GetMemberName(TResource(), L"ChargeCostGold") + L"," + 
				GetMemberName(int32(), L"RefreshDurationMinute") + L"," + 
				GetMemberName(int32(), L"scorePerGold");
		}
	};
	struct SFlyAwayItemMeta : public SProto
	{
		EFlyAwayItemType ItemType{};
		uint32 StaminaCreateWeight{};
		TResource AddedGold{};
		float AddedStamina{};
		SFlyAwayItemMeta()
		{
		}
		SFlyAwayItemMeta(const EFlyAwayItemType& ItemType_, const uint32& StaminaCreateWeight_, const TResource& AddedGold_, const float& AddedStamina_) : ItemType(ItemType_), StaminaCreateWeight(StaminaCreateWeight_), AddedGold(AddedGold_), AddedStamina(AddedStamina_)
		{
		}
		SFlyAwayItemMeta(EFlyAwayItemType&& ItemType_, uint32&& StaminaCreateWeight_, TResource&& AddedGold_, float&& AddedStamina_) : ItemType(std::move(ItemType_)), StaminaCreateWeight(std::move(StaminaCreateWeight_)), AddedGold(std::move(AddedGold_)), AddedStamina(std::move(AddedStamina_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> ItemType;
			Stream_ >> StaminaCreateWeight;
			Stream_ >> AddedGold;
			Stream_ >> AddedStamina;
		}
		void operator << (const Value& Value_) override
		{
			Value_["ItemType"] >> ItemType;
			Value_["StaminaCreateWeight"] >> StaminaCreateWeight;
			Value_["AddedGold"] >> AddedGold;
			Value_["AddedStamina"] >> AddedStamina;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << ItemType;
			Stream_ << StaminaCreateWeight;
			Stream_ << AddedGold;
			Stream_ << AddedStamina;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["ItemType"] = ItemType;
			Value_["StaminaCreateWeight"] = StaminaCreateWeight;
			Value_["AddedGold"] = AddedGold;
			Value_["AddedStamina"] = AddedStamina;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EFlyAwayItemType()) + L"," + 
				GetStdName(uint32()) + L"," + 
				GetStdName(TResource()) + L"," + 
				GetStdName(float());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EFlyAwayItemType(), L"ItemType") + L"," + 
				GetMemberName(uint32(), L"StaminaCreateWeight") + L"," + 
				GetMemberName(TResource(), L"AddedGold") + L"," + 
				GetMemberName(float(), L"AddedStamina");
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
		wstring rewardType{};
		int32 rewardValue{};
		SCouponMeta()
		{
		}
		SCouponMeta(const int32& Code_, const int32& StartYear_, const int32& StartMonth_, const int32& StartDay_, const int32& StartHour_, const int32& EndYear_, const int32& EndMonth_, const int32& EndDay_, const int32& EndHour_, const wstring& rewardType_, const int32& rewardValue_) : Code(Code_), StartYear(StartYear_), StartMonth(StartMonth_), StartDay(StartDay_), StartHour(StartHour_), EndYear(EndYear_), EndMonth(EndMonth_), EndDay(EndDay_), EndHour(EndHour_), rewardType(rewardType_), rewardValue(rewardValue_)
		{
		}
		SCouponMeta(int32&& Code_, int32&& StartYear_, int32&& StartMonth_, int32&& StartDay_, int32&& StartHour_, int32&& EndYear_, int32&& EndMonth_, int32&& EndDay_, int32&& EndHour_, wstring&& rewardType_, int32&& rewardValue_) : Code(std::move(Code_)), StartYear(std::move(StartYear_)), StartMonth(std::move(StartMonth_)), StartDay(std::move(StartDay_)), StartHour(std::move(StartHour_)), EndYear(std::move(EndYear_)), EndMonth(std::move(EndMonth_)), EndDay(std::move(EndDay_)), EndHour(std::move(EndHour_)), rewardType(std::move(rewardType_)), rewardValue(std::move(rewardValue_))
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
			Stream_ >> rewardType;
			Stream_ >> rewardValue;
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
			Value_["rewardType"] >> rewardType;
			Value_["rewardValue"] >> rewardValue;
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
			Stream_ << rewardType;
			Stream_ << rewardValue;
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
			Value_["rewardType"] = rewardType;
			Value_["rewardValue"] = rewardValue;
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
				GetStdName(wstring()) + L"," + 
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
				GetMemberName(wstring(), L"rewardType") + L"," + 
				GetMemberName(int32(), L"rewardValue");
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
		wstring rewardType{};
		int32 rewardValue{};
		SRankingRewardMeta()
		{
		}
		SRankingRewardMeta(const wstring& Mode_, const int32& End_, const wstring& rewardType_, const int32& rewardValue_) : Mode(Mode_), End(End_), rewardType(rewardType_), rewardValue(rewardValue_)
		{
		}
		SRankingRewardMeta(wstring&& Mode_, int32&& End_, wstring&& rewardType_, int32&& rewardValue_) : Mode(std::move(Mode_)), End(std::move(End_)), rewardType(std::move(rewardType_)), rewardValue(std::move(rewardValue_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Mode;
			Stream_ >> End;
			Stream_ >> rewardType;
			Stream_ >> rewardValue;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Mode"] >> Mode;
			Value_["End"] >> End;
			Value_["rewardType"] >> rewardType;
			Value_["rewardValue"] >> rewardValue;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Mode;
			Stream_ << End;
			Stream_ << rewardType;
			Stream_ << rewardValue;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Mode"] = Mode;
			Value_["End"] = End;
			Value_["rewardType"] = rewardType;
			Value_["rewardValue"] = rewardValue;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Mode") + L"," + 
				GetMemberName(int32(), L"End") + L"," + 
				GetMemberName(wstring(), L"rewardType") + L"," + 
				GetMemberName(int32(), L"rewardValue");
		}
	};
}
