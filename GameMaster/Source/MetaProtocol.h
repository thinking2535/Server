#pragma once


#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <Rso/Core/Stream.h>
#include <Rso/Json/Json.h>


using namespace std;
using namespace rso;
using namespace core;
using namespace json;


#include "NetProtocol.h"
struct SServerConfigMeta : public SProto
{
	__int32 EnvObjectRegenDurationHour = 0;
	double CartRewardRatio = 0.0;
	SServerConfigMeta()
	{
	}
	SServerConfigMeta(const __int32& EnvObjectRegenDurationHour_, const double& CartRewardRatio_) : EnvObjectRegenDurationHour(EnvObjectRegenDurationHour_), CartRewardRatio(CartRewardRatio_)
	{
	}
	SServerConfigMeta(__int32&& EnvObjectRegenDurationHour_, double&& CartRewardRatio_) : EnvObjectRegenDurationHour(std::move(EnvObjectRegenDurationHour_)), CartRewardRatio(std::move(CartRewardRatio_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> EnvObjectRegenDurationHour;
		Stream_ >> CartRewardRatio;
	}
	void operator << (const Value& Value_) override
	{
		Value_["EnvObjectRegenDurationHour"] >> EnvObjectRegenDurationHour;
		Value_["CartRewardRatio"] >> CartRewardRatio;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << EnvObjectRegenDurationHour;
		Stream_ << CartRewardRatio;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["EnvObjectRegenDurationHour"] = EnvObjectRegenDurationHour;
		Value_["CartRewardRatio"] = CartRewardRatio;
	}
	static wstring StdName(void)
	{
		return L"int32,double";
	}
	static wstring MemberName(void)
	{
		return L"EnvObjectRegenDurationHour,CartRewardRatio";
	}
};
struct SBatchBoostMeta : public SProto
{
	__int32 TimeMinute = 0;
	double Cost = 0.0;
	__int32 CoolTimeHour = 0;
	SBatchBoostMeta()
	{
	}
	SBatchBoostMeta(const __int32& TimeMinute_, const double& Cost_, const __int32& CoolTimeHour_) : TimeMinute(TimeMinute_), Cost(Cost_), CoolTimeHour(CoolTimeHour_)
	{
	}
	SBatchBoostMeta(__int32&& TimeMinute_, double&& Cost_, __int32&& CoolTimeHour_) : TimeMinute(std::move(TimeMinute_)), Cost(std::move(Cost_)), CoolTimeHour(std::move(CoolTimeHour_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TimeMinute;
		Stream_ >> Cost;
		Stream_ >> CoolTimeHour;
	}
	void operator << (const Value& Value_) override
	{
		Value_["TimeMinute"] >> TimeMinute;
		Value_["Cost"] >> Cost;
		Value_["CoolTimeHour"] >> CoolTimeHour;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TimeMinute;
		Stream_ << Cost;
		Stream_ << CoolTimeHour;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TimeMinute"] = TimeMinute;
		Value_["Cost"] = Cost;
		Value_["CoolTimeHour"] = CoolTimeHour;
	}
	static wstring StdName(void)
	{
		return L"int32,double,int32";
	}
	static wstring MemberName(void)
	{
		return L"TimeMinute,Cost,CoolTimeHour";
	}
};
struct SConfigMeta : public SProto
{
	__int32 battleTime = 0;
	EClanMemberGrade UnionJoinAllowMinGrade;
	EClanMemberGrade UnionInviteMinGrade;
	EClanMemberGrade UnionEditMinGrade;
	EClanMemberGrade UnionMessageMinGrade;
	__int32 UnionReJoinLimitDay = 0;
	TResource UnionMakeValueAme = 0;
	TSlotNo DefaultAvatarSlotCnt = 0;
	SBatchBoostMeta BatchBoost;
	double SecToTopazFactor = 0.0;
	double ResourceToTopazFactor = 0.0;
	double AquaToTopazFactor = 0.0;
	SConfigMeta()
	{
	}
	SConfigMeta(const __int32& battleTime_, const EClanMemberGrade& UnionJoinAllowMinGrade_, const EClanMemberGrade& UnionInviteMinGrade_, const EClanMemberGrade& UnionEditMinGrade_, const EClanMemberGrade& UnionMessageMinGrade_, const __int32& UnionReJoinLimitDay_, const TResource& UnionMakeValueAme_, const TSlotNo& DefaultAvatarSlotCnt_, const SBatchBoostMeta& BatchBoost_, const double& SecToTopazFactor_, const double& ResourceToTopazFactor_, const double& AquaToTopazFactor_) : battleTime(battleTime_), UnionJoinAllowMinGrade(UnionJoinAllowMinGrade_), UnionInviteMinGrade(UnionInviteMinGrade_), UnionEditMinGrade(UnionEditMinGrade_), UnionMessageMinGrade(UnionMessageMinGrade_), UnionReJoinLimitDay(UnionReJoinLimitDay_), UnionMakeValueAme(UnionMakeValueAme_), DefaultAvatarSlotCnt(DefaultAvatarSlotCnt_), BatchBoost(BatchBoost_), SecToTopazFactor(SecToTopazFactor_), ResourceToTopazFactor(ResourceToTopazFactor_), AquaToTopazFactor(AquaToTopazFactor_)
	{
	}
	SConfigMeta(__int32&& battleTime_, EClanMemberGrade&& UnionJoinAllowMinGrade_, EClanMemberGrade&& UnionInviteMinGrade_, EClanMemberGrade&& UnionEditMinGrade_, EClanMemberGrade&& UnionMessageMinGrade_, __int32&& UnionReJoinLimitDay_, TResource&& UnionMakeValueAme_, TSlotNo&& DefaultAvatarSlotCnt_, SBatchBoostMeta&& BatchBoost_, double&& SecToTopazFactor_, double&& ResourceToTopazFactor_, double&& AquaToTopazFactor_) : battleTime(std::move(battleTime_)), UnionJoinAllowMinGrade(std::move(UnionJoinAllowMinGrade_)), UnionInviteMinGrade(std::move(UnionInviteMinGrade_)), UnionEditMinGrade(std::move(UnionEditMinGrade_)), UnionMessageMinGrade(std::move(UnionMessageMinGrade_)), UnionReJoinLimitDay(std::move(UnionReJoinLimitDay_)), UnionMakeValueAme(std::move(UnionMakeValueAme_)), DefaultAvatarSlotCnt(std::move(DefaultAvatarSlotCnt_)), BatchBoost(std::move(BatchBoost_)), SecToTopazFactor(std::move(SecToTopazFactor_)), ResourceToTopazFactor(std::move(ResourceToTopazFactor_)), AquaToTopazFactor(std::move(AquaToTopazFactor_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> battleTime;
		Stream_ >> (__int8&)UnionJoinAllowMinGrade;
		Stream_ >> (__int8&)UnionInviteMinGrade;
		Stream_ >> (__int8&)UnionEditMinGrade;
		Stream_ >> (__int8&)UnionMessageMinGrade;
		Stream_ >> UnionReJoinLimitDay;
		Stream_ >> UnionMakeValueAme;
		Stream_ >> DefaultAvatarSlotCnt;
		Stream_ >> BatchBoost;
		Stream_ >> SecToTopazFactor;
		Stream_ >> ResourceToTopazFactor;
		Stream_ >> AquaToTopazFactor;
	}
	void operator << (const Value& Value_) override
	{
		Value_["battleTime"] >> battleTime;
		Value_["UnionJoinAllowMinGrade"] >> (__int8&)UnionJoinAllowMinGrade;
		Value_["UnionInviteMinGrade"] >> (__int8&)UnionInviteMinGrade;
		Value_["UnionEditMinGrade"] >> (__int8&)UnionEditMinGrade;
		Value_["UnionMessageMinGrade"] >> (__int8&)UnionMessageMinGrade;
		Value_["UnionReJoinLimitDay"] >> UnionReJoinLimitDay;
		Value_["UnionMakeValueAme"] >> UnionMakeValueAme;
		Value_["DefaultAvatarSlotCnt"] >> DefaultAvatarSlotCnt;
		BatchBoost << Value_["BatchBoost"];
		Value_["SecToTopazFactor"] >> SecToTopazFactor;
		Value_["ResourceToTopazFactor"] >> ResourceToTopazFactor;
		Value_["AquaToTopazFactor"] >> AquaToTopazFactor;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << battleTime;
		Stream_ << (__int8)UnionJoinAllowMinGrade;
		Stream_ << (__int8)UnionInviteMinGrade;
		Stream_ << (__int8)UnionEditMinGrade;
		Stream_ << (__int8)UnionMessageMinGrade;
		Stream_ << UnionReJoinLimitDay;
		Stream_ << UnionMakeValueAme;
		Stream_ << DefaultAvatarSlotCnt;
		Stream_ << BatchBoost;
		Stream_ << SecToTopazFactor;
		Stream_ << ResourceToTopazFactor;
		Stream_ << AquaToTopazFactor;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["battleTime"] = battleTime;
		Value_["UnionJoinAllowMinGrade"] = (__int8)UnionJoinAllowMinGrade;
		Value_["UnionInviteMinGrade"] = (__int8)UnionInviteMinGrade;
		Value_["UnionEditMinGrade"] = (__int8)UnionEditMinGrade;
		Value_["UnionMessageMinGrade"] = (__int8)UnionMessageMinGrade;
		Value_["UnionReJoinLimitDay"] = UnionReJoinLimitDay;
		Value_["UnionMakeValueAme"] = UnionMakeValueAme;
		Value_["DefaultAvatarSlotCnt"] = DefaultAvatarSlotCnt;
		Value_["BatchBoost"] = BatchBoost;
		Value_["SecToTopazFactor"] = SecToTopazFactor;
		Value_["ResourceToTopazFactor"] = ResourceToTopazFactor;
		Value_["AquaToTopazFactor"] = AquaToTopazFactor;
	}
	static wstring StdName(void)
	{
		return L"int32,int8,int8,int8,int8,int32,int32,int8,int32,double,int32,double,double,double";
	}
	static wstring MemberName(void)
	{
		return L"battleTime,UnionJoinAllowMinGrade,UnionInviteMinGrade,UnionEditMinGrade,UnionMessageMinGrade,UnionReJoinLimitDay,UnionMakeValueAme,DefaultAvatarSlotCnt,TimeMinute,Cost,CoolTimeHour,SecToTopazFactor,ResourceToTopazFactor,AquaToTopazFactor";
	}
};
struct SExpMeta : public SProto
{
	__int32 Exp = 0;
	SExpMeta()
	{
	}
	SExpMeta(const __int32& Exp_) : Exp(Exp_)
	{
	}
	SExpMeta(__int32&& Exp_) : Exp(std::move(Exp_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Exp;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Exp"] >> Exp;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Exp;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Exp"] = Exp;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"Exp";
	}
};
using TCPLevelCnts = array<TLevel,10>;
struct SBuildingMaxQuantityMeta : public SProto
{
	TID GroupID = 0;
	TCPLevelCnts CPLevelCnts{};
	SBuildingMaxQuantityMeta()
	{
	}
	SBuildingMaxQuantityMeta(const TID& GroupID_, const TCPLevelCnts& CPLevelCnts_) : GroupID(GroupID_), CPLevelCnts(CPLevelCnts_)
	{
	}
	SBuildingMaxQuantityMeta(TID&& GroupID_, TCPLevelCnts&& CPLevelCnts_) : GroupID(std::move(GroupID_)), CPLevelCnts(std::move(CPLevelCnts_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> GroupID;
		Stream_ >> CPLevelCnts;
	}
	void operator << (const Value& Value_) override
	{
		Value_["GroupID"] >> GroupID;
		Value_["CPLevelCnts"] >> CPLevelCnts;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << GroupID;
		Stream_ << CPLevelCnts;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["GroupID"] = GroupID;
		Value_["CPLevelCnts"] = CPLevelCnts;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"GroupID,CPLevelCnts";
	}
};
struct SBuildingRect : public SProto
{
	__int32 Width = 0;
	__int32 Height = 0;
	SBuildingRect()
	{
	}
	SBuildingRect(const __int32& Width_, const __int32& Height_) : Width(Width_), Height(Height_)
	{
	}
	SBuildingRect(__int32&& Width_, __int32&& Height_) : Width(std::move(Width_)), Height(std::move(Height_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Width;
		Stream_ >> Height;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Width"] >> Width;
		Value_["Height"] >> Height;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Width;
		Stream_ << Height;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Width"] = Width;
		Value_["Height"] = Height;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Width,Height";
	}
};
struct SBuildingBasicMeta : public SProto
{
	wstring bd_type;
	wstring bd_group_type;
	TID BulletGroupID = 0;
	EZoneType ZoneType;
	SBuildingRect Rect;
	__int32 gain_type = 0;
	wstring RearmType;
	__int32 BoostTimeHour = 0;
	double BoostRatio = 0.0;
	bool IsBatch = false;
	SBuildingBasicMeta()
	{
	}
	SBuildingBasicMeta(const wstring& bd_type_, const wstring& bd_group_type_, const TID& BulletGroupID_, const EZoneType& ZoneType_, const SBuildingRect& Rect_, const __int32& gain_type_, const wstring& RearmType_, const __int32& BoostTimeHour_, const double& BoostRatio_, const bool& IsBatch_) : bd_type(bd_type_), bd_group_type(bd_group_type_), BulletGroupID(BulletGroupID_), ZoneType(ZoneType_), Rect(Rect_), gain_type(gain_type_), RearmType(RearmType_), BoostTimeHour(BoostTimeHour_), BoostRatio(BoostRatio_), IsBatch(IsBatch_)
	{
	}
	SBuildingBasicMeta(wstring&& bd_type_, wstring&& bd_group_type_, TID&& BulletGroupID_, EZoneType&& ZoneType_, SBuildingRect&& Rect_, __int32&& gain_type_, wstring&& RearmType_, __int32&& BoostTimeHour_, double&& BoostRatio_, bool&& IsBatch_) : bd_type(std::move(bd_type_)), bd_group_type(std::move(bd_group_type_)), BulletGroupID(std::move(BulletGroupID_)), ZoneType(std::move(ZoneType_)), Rect(std::move(Rect_)), gain_type(std::move(gain_type_)), RearmType(std::move(RearmType_)), BoostTimeHour(std::move(BoostTimeHour_)), BoostRatio(std::move(BoostRatio_)), IsBatch(std::move(IsBatch_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> bd_type;
		Stream_ >> bd_group_type;
		Stream_ >> BulletGroupID;
		Stream_ >> (__int32&)ZoneType;
		Stream_ >> Rect;
		Stream_ >> gain_type;
		Stream_ >> RearmType;
		Stream_ >> BoostTimeHour;
		Stream_ >> BoostRatio;
		Stream_ >> IsBatch;
	}
	void operator << (const Value& Value_) override
	{
		Value_["bd_type"] >> bd_type;
		Value_["bd_group_type"] >> bd_group_type;
		Value_["BulletGroupID"] >> BulletGroupID;
		Value_["ZoneType"] >> (__int32&)ZoneType;
		Rect << Value_["Rect"];
		Value_["gain_type"] >> gain_type;
		Value_["RearmType"] >> RearmType;
		Value_["BoostTimeHour"] >> BoostTimeHour;
		Value_["BoostRatio"] >> BoostRatio;
		Value_["IsBatch"] >> IsBatch;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << bd_type;
		Stream_ << bd_group_type;
		Stream_ << BulletGroupID;
		Stream_ << (__int32)ZoneType;
		Stream_ << Rect;
		Stream_ << gain_type;
		Stream_ << RearmType;
		Stream_ << BoostTimeHour;
		Stream_ << BoostRatio;
		Stream_ << IsBatch;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["bd_type"] = bd_type;
		Value_["bd_group_type"] = bd_group_type;
		Value_["BulletGroupID"] = BulletGroupID;
		Value_["ZoneType"] = (__int32)ZoneType;
		Value_["Rect"] = Rect;
		Value_["gain_type"] = gain_type;
		Value_["RearmType"] = RearmType;
		Value_["BoostTimeHour"] = BoostTimeHour;
		Value_["BoostRatio"] = BoostRatio;
		Value_["IsBatch"] = IsBatch;
	}
	static wstring StdName(void)
	{
		return L"wstring,wstring,int32,int32,int32,int32,int32,wstring,int32,double,bool";
	}
	static wstring MemberName(void)
	{
		return L"bd_type,bd_group_type,BulletGroupID,ZoneType,Width,Height,gain_type,RearmType,BoostTimeHour,BoostRatio,IsBatch";
	}
};
struct SKeyBuildingBasicMeta : public SProto
{
	TID Key = 0;
	SBuildingBasicMeta Data;
	SKeyBuildingBasicMeta()
	{
	}
	SKeyBuildingBasicMeta(const TID& Key_, const SBuildingBasicMeta& Data_) : Key(Key_), Data(Data_)
	{
	}
	SKeyBuildingBasicMeta(TID&& Key_, SBuildingBasicMeta&& Data_) : Key(std::move(Key_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Key;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Key"] >> Key;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Key;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Key"] = Key;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,wstring,wstring,int32,int32,int32,int32,int32,wstring,int32,double,bool";
	}
	static wstring MemberName(void)
	{
		return L"Key,bd_type,bd_group_type,BulletGroupID,ZoneType,Width,Height,gain_type,RearmType,BoostTimeHour,BoostRatio,IsBatch";
	}
};
struct SBuildingNormalMeta : public SProto
{
	TID ID = 0;
	TID bd_group_ID = 0;
	TLevel level = 0;
	THP HP = 0;
	SResourceTypeData UpgradeResource;
	__int32 building_time_min = 0;
	TLevel upgrade_user_lv_limit = 0;
	TLevel upgrade_cp_lv_limit = 0;
	__int32 ame_max_capacity = 0;
	__int32 acid_max_capacity = 0;
	__int32 aqua_max_capacity = 0;
	__int32 gain_quantity_hour = 0;
	__int32 human_limit = 0;
	TResource BoostCost = 0;
	SBuildingNormalMeta()
	{
	}
	SBuildingNormalMeta(const TID& ID_, const TID& bd_group_ID_, const TLevel& level_, const THP& HP_, const SResourceTypeData& UpgradeResource_, const __int32& building_time_min_, const TLevel& upgrade_user_lv_limit_, const TLevel& upgrade_cp_lv_limit_, const __int32& ame_max_capacity_, const __int32& acid_max_capacity_, const __int32& aqua_max_capacity_, const __int32& gain_quantity_hour_, const __int32& human_limit_, const TResource& BoostCost_) : ID(ID_), bd_group_ID(bd_group_ID_), level(level_), HP(HP_), UpgradeResource(UpgradeResource_), building_time_min(building_time_min_), upgrade_user_lv_limit(upgrade_user_lv_limit_), upgrade_cp_lv_limit(upgrade_cp_lv_limit_), ame_max_capacity(ame_max_capacity_), acid_max_capacity(acid_max_capacity_), aqua_max_capacity(aqua_max_capacity_), gain_quantity_hour(gain_quantity_hour_), human_limit(human_limit_), BoostCost(BoostCost_)
	{
	}
	SBuildingNormalMeta(TID&& ID_, TID&& bd_group_ID_, TLevel&& level_, THP&& HP_, SResourceTypeData&& UpgradeResource_, __int32&& building_time_min_, TLevel&& upgrade_user_lv_limit_, TLevel&& upgrade_cp_lv_limit_, __int32&& ame_max_capacity_, __int32&& acid_max_capacity_, __int32&& aqua_max_capacity_, __int32&& gain_quantity_hour_, __int32&& human_limit_, TResource&& BoostCost_) : ID(std::move(ID_)), bd_group_ID(std::move(bd_group_ID_)), level(std::move(level_)), HP(std::move(HP_)), UpgradeResource(std::move(UpgradeResource_)), building_time_min(std::move(building_time_min_)), upgrade_user_lv_limit(std::move(upgrade_user_lv_limit_)), upgrade_cp_lv_limit(std::move(upgrade_cp_lv_limit_)), ame_max_capacity(std::move(ame_max_capacity_)), acid_max_capacity(std::move(acid_max_capacity_)), aqua_max_capacity(std::move(aqua_max_capacity_)), gain_quantity_hour(std::move(gain_quantity_hour_)), human_limit(std::move(human_limit_)), BoostCost(std::move(BoostCost_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ID;
		Stream_ >> bd_group_ID;
		Stream_ >> level;
		Stream_ >> HP;
		Stream_ >> UpgradeResource;
		Stream_ >> building_time_min;
		Stream_ >> upgrade_user_lv_limit;
		Stream_ >> upgrade_cp_lv_limit;
		Stream_ >> ame_max_capacity;
		Stream_ >> acid_max_capacity;
		Stream_ >> aqua_max_capacity;
		Stream_ >> gain_quantity_hour;
		Stream_ >> human_limit;
		Stream_ >> BoostCost;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ID"] >> ID;
		Value_["bd_group_ID"] >> bd_group_ID;
		Value_["level"] >> level;
		Value_["HP"] >> HP;
		UpgradeResource << Value_["UpgradeResource"];
		Value_["building_time_min"] >> building_time_min;
		Value_["upgrade_user_lv_limit"] >> upgrade_user_lv_limit;
		Value_["upgrade_cp_lv_limit"] >> upgrade_cp_lv_limit;
		Value_["ame_max_capacity"] >> ame_max_capacity;
		Value_["acid_max_capacity"] >> acid_max_capacity;
		Value_["aqua_max_capacity"] >> aqua_max_capacity;
		Value_["gain_quantity_hour"] >> gain_quantity_hour;
		Value_["human_limit"] >> human_limit;
		Value_["BoostCost"] >> BoostCost;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ID;
		Stream_ << bd_group_ID;
		Stream_ << level;
		Stream_ << HP;
		Stream_ << UpgradeResource;
		Stream_ << building_time_min;
		Stream_ << upgrade_user_lv_limit;
		Stream_ << upgrade_cp_lv_limit;
		Stream_ << ame_max_capacity;
		Stream_ << acid_max_capacity;
		Stream_ << aqua_max_capacity;
		Stream_ << gain_quantity_hour;
		Stream_ << human_limit;
		Stream_ << BoostCost;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ID"] = ID;
		Value_["bd_group_ID"] = bd_group_ID;
		Value_["level"] = level;
		Value_["HP"] = HP;
		Value_["UpgradeResource"] = UpgradeResource;
		Value_["building_time_min"] = building_time_min;
		Value_["upgrade_user_lv_limit"] = upgrade_user_lv_limit;
		Value_["upgrade_cp_lv_limit"] = upgrade_cp_lv_limit;
		Value_["ame_max_capacity"] = ame_max_capacity;
		Value_["acid_max_capacity"] = acid_max_capacity;
		Value_["aqua_max_capacity"] = aqua_max_capacity;
		Value_["gain_quantity_hour"] = gain_quantity_hour;
		Value_["human_limit"] = human_limit;
		Value_["BoostCost"] = BoostCost;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ID,bd_group_ID,level,HP,Type,Data,building_time_min,upgrade_user_lv_limit,upgrade_cp_lv_limit,ame_max_capacity,acid_max_capacity,aqua_max_capacity,gain_quantity_hour,human_limit,BoostCost";
	}
};
struct SBuildingDefenceMeta : public SProto
{
	TID ID = 0;
	TID bd_group_ID = 0;
	TLevel level = 0;
	__int8 Mode = 0;
	THP HP = 0;
	SResourceTypeData UpgradeResource;
	__int32 building_time_min = 0;
	TLevel upgrade_cp_lv_limit = 0;
	__int32 BulletCount = 0;
	SResourceTypeData RearmCost;
	SBuildingDefenceMeta()
	{
	}
	SBuildingDefenceMeta(const TID& ID_, const TID& bd_group_ID_, const TLevel& level_, const __int8& Mode_, const THP& HP_, const SResourceTypeData& UpgradeResource_, const __int32& building_time_min_, const TLevel& upgrade_cp_lv_limit_, const __int32& BulletCount_, const SResourceTypeData& RearmCost_) : ID(ID_), bd_group_ID(bd_group_ID_), level(level_), Mode(Mode_), HP(HP_), UpgradeResource(UpgradeResource_), building_time_min(building_time_min_), upgrade_cp_lv_limit(upgrade_cp_lv_limit_), BulletCount(BulletCount_), RearmCost(RearmCost_)
	{
	}
	SBuildingDefenceMeta(TID&& ID_, TID&& bd_group_ID_, TLevel&& level_, __int8&& Mode_, THP&& HP_, SResourceTypeData&& UpgradeResource_, __int32&& building_time_min_, TLevel&& upgrade_cp_lv_limit_, __int32&& BulletCount_, SResourceTypeData&& RearmCost_) : ID(std::move(ID_)), bd_group_ID(std::move(bd_group_ID_)), level(std::move(level_)), Mode(std::move(Mode_)), HP(std::move(HP_)), UpgradeResource(std::move(UpgradeResource_)), building_time_min(std::move(building_time_min_)), upgrade_cp_lv_limit(std::move(upgrade_cp_lv_limit_)), BulletCount(std::move(BulletCount_)), RearmCost(std::move(RearmCost_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ID;
		Stream_ >> bd_group_ID;
		Stream_ >> level;
		Stream_ >> Mode;
		Stream_ >> HP;
		Stream_ >> UpgradeResource;
		Stream_ >> building_time_min;
		Stream_ >> upgrade_cp_lv_limit;
		Stream_ >> BulletCount;
		Stream_ >> RearmCost;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ID"] >> ID;
		Value_["bd_group_ID"] >> bd_group_ID;
		Value_["level"] >> level;
		Value_["Mode"] >> Mode;
		Value_["HP"] >> HP;
		UpgradeResource << Value_["UpgradeResource"];
		Value_["building_time_min"] >> building_time_min;
		Value_["upgrade_cp_lv_limit"] >> upgrade_cp_lv_limit;
		Value_["BulletCount"] >> BulletCount;
		RearmCost << Value_["RearmCost"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ID;
		Stream_ << bd_group_ID;
		Stream_ << level;
		Stream_ << Mode;
		Stream_ << HP;
		Stream_ << UpgradeResource;
		Stream_ << building_time_min;
		Stream_ << upgrade_cp_lv_limit;
		Stream_ << BulletCount;
		Stream_ << RearmCost;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ID"] = ID;
		Value_["bd_group_ID"] = bd_group_ID;
		Value_["level"] = level;
		Value_["Mode"] = Mode;
		Value_["HP"] = HP;
		Value_["UpgradeResource"] = UpgradeResource;
		Value_["building_time_min"] = building_time_min;
		Value_["upgrade_cp_lv_limit"] = upgrade_cp_lv_limit;
		Value_["BulletCount"] = BulletCount;
		Value_["RearmCost"] = RearmCost;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int8,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ID,bd_group_ID,level,Mode,HP,Type,Data,building_time_min,upgrade_cp_lv_limit,BulletCount,Type,Data";
	}
};
struct SShopBuildingMeta : public SProto
{
	TID bd_group_id = 0;
	__int32 cost_increase = 0;
	__int32 recharger_count = 0;
	__int32 cost_trunc = 0;
	SShopBuildingMeta()
	{
	}
	SShopBuildingMeta(const TID& bd_group_id_, const __int32& cost_increase_, const __int32& recharger_count_, const __int32& cost_trunc_) : bd_group_id(bd_group_id_), cost_increase(cost_increase_), recharger_count(recharger_count_), cost_trunc(cost_trunc_)
	{
	}
	SShopBuildingMeta(TID&& bd_group_id_, __int32&& cost_increase_, __int32&& recharger_count_, __int32&& cost_trunc_) : bd_group_id(std::move(bd_group_id_)), cost_increase(std::move(cost_increase_)), recharger_count(std::move(recharger_count_)), cost_trunc(std::move(cost_trunc_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> bd_group_id;
		Stream_ >> cost_increase;
		Stream_ >> recharger_count;
		Stream_ >> cost_trunc;
	}
	void operator << (const Value& Value_) override
	{
		Value_["bd_group_id"] >> bd_group_id;
		Value_["cost_increase"] >> cost_increase;
		Value_["recharger_count"] >> recharger_count;
		Value_["cost_trunc"] >> cost_trunc;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << bd_group_id;
		Stream_ << cost_increase;
		Stream_ << recharger_count;
		Stream_ << cost_trunc;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["bd_group_id"] = bd_group_id;
		Value_["cost_increase"] = cost_increase;
		Value_["recharger_count"] = recharger_count;
		Value_["cost_trunc"] = cost_trunc;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"bd_group_id,cost_increase,recharger_count,cost_trunc";
	}
};
struct SUserDataPresetMeta : public SProto
{
	__int32 Ame = 0;
	__int32 Acid = 0;
	__int32 Aqua = 0;
	__int32 Topaz = 0;
	__int32 LeaguePoint = 0;
	__int32 UserLevel = 0;
	__int32 RechargingStationCnt = 0;
	SUserDataPresetMeta()
	{
	}
	SUserDataPresetMeta(const __int32& Ame_, const __int32& Acid_, const __int32& Aqua_, const __int32& Topaz_, const __int32& LeaguePoint_, const __int32& UserLevel_, const __int32& RechargingStationCnt_) : Ame(Ame_), Acid(Acid_), Aqua(Aqua_), Topaz(Topaz_), LeaguePoint(LeaguePoint_), UserLevel(UserLevel_), RechargingStationCnt(RechargingStationCnt_)
	{
	}
	SUserDataPresetMeta(__int32&& Ame_, __int32&& Acid_, __int32&& Aqua_, __int32&& Topaz_, __int32&& LeaguePoint_, __int32&& UserLevel_, __int32&& RechargingStationCnt_) : Ame(std::move(Ame_)), Acid(std::move(Acid_)), Aqua(std::move(Aqua_)), Topaz(std::move(Topaz_)), LeaguePoint(std::move(LeaguePoint_)), UserLevel(std::move(UserLevel_)), RechargingStationCnt(std::move(RechargingStationCnt_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Ame;
		Stream_ >> Acid;
		Stream_ >> Aqua;
		Stream_ >> Topaz;
		Stream_ >> LeaguePoint;
		Stream_ >> UserLevel;
		Stream_ >> RechargingStationCnt;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Ame"] >> Ame;
		Value_["Acid"] >> Acid;
		Value_["Aqua"] >> Aqua;
		Value_["Topaz"] >> Topaz;
		Value_["LeaguePoint"] >> LeaguePoint;
		Value_["UserLevel"] >> UserLevel;
		Value_["RechargingStationCnt"] >> RechargingStationCnt;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Ame;
		Stream_ << Acid;
		Stream_ << Aqua;
		Stream_ << Topaz;
		Stream_ << LeaguePoint;
		Stream_ << UserLevel;
		Stream_ << RechargingStationCnt;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Ame"] = Ame;
		Value_["Acid"] = Acid;
		Value_["Aqua"] = Aqua;
		Value_["Topaz"] = Topaz;
		Value_["LeaguePoint"] = LeaguePoint;
		Value_["UserLevel"] = UserLevel;
		Value_["RechargingStationCnt"] = RechargingStationCnt;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Ame,Acid,Aqua,Topaz,LeaguePoint,UserLevel,RechargingStationCnt";
	}
};
struct SStartUserBuildingMeta : public SProto
{
	SPos Pos;
	SBuildingRotate Rotate;
	bool need_to_restore = false;
	SStartUserBuildingMeta()
	{
	}
	SStartUserBuildingMeta(const SPos& Pos_, const SBuildingRotate& Rotate_, const bool& need_to_restore_) : Pos(Pos_), Rotate(Rotate_), need_to_restore(need_to_restore_)
	{
	}
	SStartUserBuildingMeta(SPos&& Pos_, SBuildingRotate&& Rotate_, bool&& need_to_restore_) : Pos(std::move(Pos_)), Rotate(std::move(Rotate_)), need_to_restore(std::move(need_to_restore_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Pos;
		Stream_ >> Rotate;
		Stream_ >> need_to_restore;
	}
	void operator << (const Value& Value_) override
	{
		Pos << Value_["Pos"];
		Rotate << Value_["Rotate"];
		Value_["need_to_restore"] >> need_to_restore;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Pos;
		Stream_ << Rotate;
		Stream_ << need_to_restore;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Pos"] = Pos;
		Value_["Rotate"] = Rotate;
		Value_["need_to_restore"] = need_to_restore;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int8,int8,bool";
	}
	static wstring MemberName(void)
	{
		return L"X,Y,Rotate,RotateHead,need_to_restore";
	}
};
struct SKeyStartUserBuildingMeta : public SProto
{
	TID Key = 0;
	SStartUserBuildingMeta Data;
	SKeyStartUserBuildingMeta()
	{
	}
	SKeyStartUserBuildingMeta(const TID& Key_, const SStartUserBuildingMeta& Data_) : Key(Key_), Data(Data_)
	{
	}
	SKeyStartUserBuildingMeta(TID&& Key_, SStartUserBuildingMeta&& Data_) : Key(std::move(Key_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Key;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Key"] >> Key;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Key;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Key"] = Key;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int8,int8,bool";
	}
	static wstring MemberName(void)
	{
		return L"Key,X,Y,Rotate,RotateHead,need_to_restore";
	}
};
struct SStartUserObjectMeta : public SProto
{
	TID ID = 0;
	SPos Pos;
	SStartUserObjectMeta()
	{
	}
	SStartUserObjectMeta(const TID& ID_, const SPos& Pos_) : ID(ID_), Pos(Pos_)
	{
	}
	SStartUserObjectMeta(TID&& ID_, SPos&& Pos_) : ID(std::move(ID_)), Pos(std::move(Pos_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ID;
		Stream_ >> Pos;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ID"] >> ID;
		Pos << Value_["Pos"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ID;
		Stream_ << Pos;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ID"] = ID;
		Value_["Pos"] = Pos;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ID,X,Y";
	}
};
struct SUnitBasicMeta : public SProto
{
	TLevel FactoryLevel = 0;
	__int32 CountPerSlot = 0;
	EResource TrainingCostType;
	SUnitBasicMeta()
	{
	}
	SUnitBasicMeta(const TLevel& FactoryLevel_, const __int32& CountPerSlot_, const EResource& TrainingCostType_) : FactoryLevel(FactoryLevel_), CountPerSlot(CountPerSlot_), TrainingCostType(TrainingCostType_)
	{
	}
	SUnitBasicMeta(TLevel&& FactoryLevel_, __int32&& CountPerSlot_, EResource&& TrainingCostType_) : FactoryLevel(std::move(FactoryLevel_)), CountPerSlot(std::move(CountPerSlot_)), TrainingCostType(std::move(TrainingCostType_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> FactoryLevel;
		Stream_ >> CountPerSlot;
		Stream_ >> (__int32&)TrainingCostType;
	}
	void operator << (const Value& Value_) override
	{
		Value_["FactoryLevel"] >> FactoryLevel;
		Value_["CountPerSlot"] >> CountPerSlot;
		Value_["TrainingCostType"] >> (__int32&)TrainingCostType;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << FactoryLevel;
		Stream_ << CountPerSlot;
		Stream_ << (__int32)TrainingCostType;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["FactoryLevel"] = FactoryLevel;
		Value_["CountPerSlot"] = CountPerSlot;
		Value_["TrainingCostType"] = (__int32)TrainingCostType;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"FactoryLevel,CountPerSlot,TrainingCostType";
	}
};
struct SKeyUnitBasicMeta : public SProto
{
	TID Key = 0;
	SUnitBasicMeta Data;
	SKeyUnitBasicMeta()
	{
	}
	SKeyUnitBasicMeta(const TID& Key_, const SUnitBasicMeta& Data_) : Key(Key_), Data(Data_)
	{
	}
	SKeyUnitBasicMeta(TID&& Key_, SUnitBasicMeta&& Data_) : Key(std::move(Key_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Key;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Key"] >> Key;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Key;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Key"] = Key;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Key,FactoryLevel,CountPerSlot,TrainingCostType";
	}
};
struct SUpgradeCostMeta : public SProto
{
	TLevel TechLabLevel = 0;
	SResourceTypeData UpgradeCost;
	__int32 UpgradeHour = 0;
	SUpgradeCostMeta()
	{
	}
	SUpgradeCostMeta(const TLevel& TechLabLevel_, const SResourceTypeData& UpgradeCost_, const __int32& UpgradeHour_) : TechLabLevel(TechLabLevel_), UpgradeCost(UpgradeCost_), UpgradeHour(UpgradeHour_)
	{
	}
	SUpgradeCostMeta(TLevel&& TechLabLevel_, SResourceTypeData&& UpgradeCost_, __int32&& UpgradeHour_) : TechLabLevel(std::move(TechLabLevel_)), UpgradeCost(std::move(UpgradeCost_)), UpgradeHour(std::move(UpgradeHour_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TechLabLevel;
		Stream_ >> UpgradeCost;
		Stream_ >> UpgradeHour;
	}
	void operator << (const Value& Value_) override
	{
		Value_["TechLabLevel"] >> TechLabLevel;
		UpgradeCost << Value_["UpgradeCost"];
		Value_["UpgradeHour"] >> UpgradeHour;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TechLabLevel;
		Stream_ << UpgradeCost;
		Stream_ << UpgradeHour;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TechLabLevel"] = TechLabLevel;
		Value_["UpgradeCost"] = UpgradeCost;
		Value_["UpgradeHour"] = UpgradeHour;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"TechLabLevel,Type,Data,UpgradeHour";
	}
};
struct SKeyUpgradeCostMeta : public SProto
{
	TID Key = 0;
	SUpgradeCostMeta Data;
	SKeyUpgradeCostMeta()
	{
	}
	SKeyUpgradeCostMeta(const TID& Key_, const SUpgradeCostMeta& Data_) : Key(Key_), Data(Data_)
	{
	}
	SKeyUpgradeCostMeta(TID&& Key_, SUpgradeCostMeta&& Data_) : Key(std::move(Key_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Key;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Key"] >> Key;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Key;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Key"] = Key;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Key,TechLabLevel,Type,Data,UpgradeHour";
	}
};
struct SUnitGrowUpMeta : public SProto
{
	TID ID = 0;
	TID GroupID = 0;
	TLevel Level = 0;
	__int32 TrainingCost = 0;
	__int32 TrainingSec = 0;
	SUnitGrowUpMeta()
	{
	}
	SUnitGrowUpMeta(const TID& ID_, const TID& GroupID_, const TLevel& Level_, const __int32& TrainingCost_, const __int32& TrainingSec_) : ID(ID_), GroupID(GroupID_), Level(Level_), TrainingCost(TrainingCost_), TrainingSec(TrainingSec_)
	{
	}
	SUnitGrowUpMeta(TID&& ID_, TID&& GroupID_, TLevel&& Level_, __int32&& TrainingCost_, __int32&& TrainingSec_) : ID(std::move(ID_)), GroupID(std::move(GroupID_)), Level(std::move(Level_)), TrainingCost(std::move(TrainingCost_)), TrainingSec(std::move(TrainingSec_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ID;
		Stream_ >> GroupID;
		Stream_ >> Level;
		Stream_ >> TrainingCost;
		Stream_ >> TrainingSec;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ID"] >> ID;
		Value_["GroupID"] >> GroupID;
		Value_["Level"] >> Level;
		Value_["TrainingCost"] >> TrainingCost;
		Value_["TrainingSec"] >> TrainingSec;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ID;
		Stream_ << GroupID;
		Stream_ << Level;
		Stream_ << TrainingCost;
		Stream_ << TrainingSec;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ID"] = ID;
		Value_["GroupID"] = GroupID;
		Value_["Level"] = Level;
		Value_["TrainingCost"] = TrainingCost;
		Value_["TrainingSec"] = TrainingSec;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ID,GroupID,Level,TrainingCost,TrainingSec";
	}
};
struct SAvatarPartsMeta : public SProto
{
	TID ID = 0;
	TID GroupID = 0;
	__int32 Rank = 0;
	__int32 EnchantLevel = 0;
	SResourceTypeData Resource;
	__int32 UpgradeHour = 0;
	TLevel AvatarlabLevel = 0;
	__int32 RechargingSec = 0;
	SAvatarPartsMeta()
	{
	}
	SAvatarPartsMeta(const TID& ID_, const TID& GroupID_, const __int32& Rank_, const __int32& EnchantLevel_, const SResourceTypeData& Resource_, const __int32& UpgradeHour_, const TLevel& AvatarlabLevel_, const __int32& RechargingSec_) : ID(ID_), GroupID(GroupID_), Rank(Rank_), EnchantLevel(EnchantLevel_), Resource(Resource_), UpgradeHour(UpgradeHour_), AvatarlabLevel(AvatarlabLevel_), RechargingSec(RechargingSec_)
	{
	}
	SAvatarPartsMeta(TID&& ID_, TID&& GroupID_, __int32&& Rank_, __int32&& EnchantLevel_, SResourceTypeData&& Resource_, __int32&& UpgradeHour_, TLevel&& AvatarlabLevel_, __int32&& RechargingSec_) : ID(std::move(ID_)), GroupID(std::move(GroupID_)), Rank(std::move(Rank_)), EnchantLevel(std::move(EnchantLevel_)), Resource(std::move(Resource_)), UpgradeHour(std::move(UpgradeHour_)), AvatarlabLevel(std::move(AvatarlabLevel_)), RechargingSec(std::move(RechargingSec_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ID;
		Stream_ >> GroupID;
		Stream_ >> Rank;
		Stream_ >> EnchantLevel;
		Stream_ >> Resource;
		Stream_ >> UpgradeHour;
		Stream_ >> AvatarlabLevel;
		Stream_ >> RechargingSec;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ID"] >> ID;
		Value_["GroupID"] >> GroupID;
		Value_["Rank"] >> Rank;
		Value_["EnchantLevel"] >> EnchantLevel;
		Resource << Value_["Resource"];
		Value_["UpgradeHour"] >> UpgradeHour;
		Value_["AvatarlabLevel"] >> AvatarlabLevel;
		Value_["RechargingSec"] >> RechargingSec;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ID;
		Stream_ << GroupID;
		Stream_ << Rank;
		Stream_ << EnchantLevel;
		Stream_ << Resource;
		Stream_ << UpgradeHour;
		Stream_ << AvatarlabLevel;
		Stream_ << RechargingSec;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ID"] = ID;
		Value_["GroupID"] = GroupID;
		Value_["Rank"] = Rank;
		Value_["EnchantLevel"] = EnchantLevel;
		Value_["Resource"] = Resource;
		Value_["UpgradeHour"] = UpgradeHour;
		Value_["AvatarlabLevel"] = AvatarlabLevel;
		Value_["RechargingSec"] = RechargingSec;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ID,GroupID,Rank,EnchantLevel,Type,Data,UpgradeHour,AvatarlabLevel,RechargingSec";
	}
};
struct SAvatarPartsCoreMeta : public SProto
{
	TID ID = 0;
	TID GroupID = 0;
	__int32 Rank = 0;
	__int32 EnchantLevel = 0;
	SResourceTypeData Resource;
	__int32 UpgradeHour = 0;
	TLevel AvatarlabLevel = 0;
	SAvatarPartsCoreMeta()
	{
	}
	SAvatarPartsCoreMeta(const TID& ID_, const TID& GroupID_, const __int32& Rank_, const __int32& EnchantLevel_, const SResourceTypeData& Resource_, const __int32& UpgradeHour_, const TLevel& AvatarlabLevel_) : ID(ID_), GroupID(GroupID_), Rank(Rank_), EnchantLevel(EnchantLevel_), Resource(Resource_), UpgradeHour(UpgradeHour_), AvatarlabLevel(AvatarlabLevel_)
	{
	}
	SAvatarPartsCoreMeta(TID&& ID_, TID&& GroupID_, __int32&& Rank_, __int32&& EnchantLevel_, SResourceTypeData&& Resource_, __int32&& UpgradeHour_, TLevel&& AvatarlabLevel_) : ID(std::move(ID_)), GroupID(std::move(GroupID_)), Rank(std::move(Rank_)), EnchantLevel(std::move(EnchantLevel_)), Resource(std::move(Resource_)), UpgradeHour(std::move(UpgradeHour_)), AvatarlabLevel(std::move(AvatarlabLevel_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ID;
		Stream_ >> GroupID;
		Stream_ >> Rank;
		Stream_ >> EnchantLevel;
		Stream_ >> Resource;
		Stream_ >> UpgradeHour;
		Stream_ >> AvatarlabLevel;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ID"] >> ID;
		Value_["GroupID"] >> GroupID;
		Value_["Rank"] >> Rank;
		Value_["EnchantLevel"] >> EnchantLevel;
		Resource << Value_["Resource"];
		Value_["UpgradeHour"] >> UpgradeHour;
		Value_["AvatarlabLevel"] >> AvatarlabLevel;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ID;
		Stream_ << GroupID;
		Stream_ << Rank;
		Stream_ << EnchantLevel;
		Stream_ << Resource;
		Stream_ << UpgradeHour;
		Stream_ << AvatarlabLevel;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ID"] = ID;
		Value_["GroupID"] = GroupID;
		Value_["Rank"] = Rank;
		Value_["EnchantLevel"] = EnchantLevel;
		Value_["Resource"] = Resource;
		Value_["UpgradeHour"] = UpgradeHour;
		Value_["AvatarlabLevel"] = AvatarlabLevel;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ID,GroupID,Rank,EnchantLevel,Type,Data,UpgradeHour,AvatarlabLevel";
	}
};
struct SAvatarSlotMeta : public SProto
{
	TResource TopazCost = 0;
	SAvatarSlotMeta()
	{
	}
	SAvatarSlotMeta(const TResource& TopazCost_) : TopazCost(TopazCost_)
	{
	}
	SAvatarSlotMeta(TResource&& TopazCost_) : TopazCost(std::move(TopazCost_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TopazCost;
	}
	void operator << (const Value& Value_) override
	{
		Value_["TopazCost"] >> TopazCost;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TopazCost;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TopazCost"] = TopazCost;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"TopazCost";
	}
};
struct SLeaguePointBasicMeta : public SProto
{
	__int32 Diff = 0;
	__int32 GotPointWhenWin = 0;
	__int32 LossPointWhenLose = 0;
	SLeaguePointBasicMeta()
	{
	}
	SLeaguePointBasicMeta(const __int32& Diff_, const __int32& GotPointWhenWin_, const __int32& LossPointWhenLose_) : Diff(Diff_), GotPointWhenWin(GotPointWhenWin_), LossPointWhenLose(LossPointWhenLose_)
	{
	}
	SLeaguePointBasicMeta(__int32&& Diff_, __int32&& GotPointWhenWin_, __int32&& LossPointWhenLose_) : Diff(std::move(Diff_)), GotPointWhenWin(std::move(GotPointWhenWin_)), LossPointWhenLose(std::move(LossPointWhenLose_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Diff;
		Stream_ >> GotPointWhenWin;
		Stream_ >> LossPointWhenLose;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Diff"] >> Diff;
		Value_["GotPointWhenWin"] >> GotPointWhenWin;
		Value_["LossPointWhenLose"] >> LossPointWhenLose;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Diff;
		Stream_ << GotPointWhenWin;
		Stream_ << LossPointWhenLose;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Diff"] = Diff;
		Value_["GotPointWhenWin"] = GotPointWhenWin;
		Value_["LossPointWhenLose"] = LossPointWhenLose;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Diff,GotPointWhenWin,LossPointWhenLose";
	}
};
struct SLeaguePointTierMeta : public SProto
{
	TID ID = 0;
	__int32 League = 0;
	__int32 Tier = 0;
	__int32 LeaguePoint = 0;
	__int32 DegradePoint = 0;
	SResourceTypeData ScoutCost;
	SLeaguePointTierMeta()
	{
	}
	SLeaguePointTierMeta(const TID& ID_, const __int32& League_, const __int32& Tier_, const __int32& LeaguePoint_, const __int32& DegradePoint_, const SResourceTypeData& ScoutCost_) : ID(ID_), League(League_), Tier(Tier_), LeaguePoint(LeaguePoint_), DegradePoint(DegradePoint_), ScoutCost(ScoutCost_)
	{
	}
	SLeaguePointTierMeta(TID&& ID_, __int32&& League_, __int32&& Tier_, __int32&& LeaguePoint_, __int32&& DegradePoint_, SResourceTypeData&& ScoutCost_) : ID(std::move(ID_)), League(std::move(League_)), Tier(std::move(Tier_)), LeaguePoint(std::move(LeaguePoint_)), DegradePoint(std::move(DegradePoint_)), ScoutCost(std::move(ScoutCost_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ID;
		Stream_ >> League;
		Stream_ >> Tier;
		Stream_ >> LeaguePoint;
		Stream_ >> DegradePoint;
		Stream_ >> ScoutCost;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ID"] >> ID;
		Value_["League"] >> League;
		Value_["Tier"] >> Tier;
		Value_["LeaguePoint"] >> LeaguePoint;
		Value_["DegradePoint"] >> DegradePoint;
		ScoutCost << Value_["ScoutCost"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ID;
		Stream_ << League;
		Stream_ << Tier;
		Stream_ << LeaguePoint;
		Stream_ << DegradePoint;
		Stream_ << ScoutCost;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ID"] = ID;
		Value_["League"] = League;
		Value_["Tier"] = Tier;
		Value_["LeaguePoint"] = LeaguePoint;
		Value_["DegradePoint"] = DegradePoint;
		Value_["ScoutCost"] = ScoutCost;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ID,League,Tier,LeaguePoint,DegradePoint,Type,Data";
	}
};
struct SSingleConfigMeta : public SProto
{
	TResource GiveTopaz = 0;
	TResource GiveAme = 0;
	TResource GiveAcid = 0;
	TResource GiveAqua = 0;
	double StageIncreaseFactor = 0.0;
	double LevelIncreaseFactor = 0.0;
	SSingleConfigMeta()
	{
	}
	SSingleConfigMeta(const TResource& GiveTopaz_, const TResource& GiveAme_, const TResource& GiveAcid_, const TResource& GiveAqua_, const double& StageIncreaseFactor_, const double& LevelIncreaseFactor_) : GiveTopaz(GiveTopaz_), GiveAme(GiveAme_), GiveAcid(GiveAcid_), GiveAqua(GiveAqua_), StageIncreaseFactor(StageIncreaseFactor_), LevelIncreaseFactor(LevelIncreaseFactor_)
	{
	}
	SSingleConfigMeta(TResource&& GiveTopaz_, TResource&& GiveAme_, TResource&& GiveAcid_, TResource&& GiveAqua_, double&& StageIncreaseFactor_, double&& LevelIncreaseFactor_) : GiveTopaz(std::move(GiveTopaz_)), GiveAme(std::move(GiveAme_)), GiveAcid(std::move(GiveAcid_)), GiveAqua(std::move(GiveAqua_)), StageIncreaseFactor(std::move(StageIncreaseFactor_)), LevelIncreaseFactor(std::move(LevelIncreaseFactor_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> GiveTopaz;
		Stream_ >> GiveAme;
		Stream_ >> GiveAcid;
		Stream_ >> GiveAqua;
		Stream_ >> StageIncreaseFactor;
		Stream_ >> LevelIncreaseFactor;
	}
	void operator << (const Value& Value_) override
	{
		Value_["GiveTopaz"] >> GiveTopaz;
		Value_["GiveAme"] >> GiveAme;
		Value_["GiveAcid"] >> GiveAcid;
		Value_["GiveAqua"] >> GiveAqua;
		Value_["StageIncreaseFactor"] >> StageIncreaseFactor;
		Value_["LevelIncreaseFactor"] >> LevelIncreaseFactor;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << GiveTopaz;
		Stream_ << GiveAme;
		Stream_ << GiveAcid;
		Stream_ << GiveAqua;
		Stream_ << StageIncreaseFactor;
		Stream_ << LevelIncreaseFactor;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["GiveTopaz"] = GiveTopaz;
		Value_["GiveAme"] = GiveAme;
		Value_["GiveAcid"] = GiveAcid;
		Value_["GiveAqua"] = GiveAqua;
		Value_["StageIncreaseFactor"] = StageIncreaseFactor;
		Value_["LevelIncreaseFactor"] = LevelIncreaseFactor;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,double,double";
	}
	static wstring MemberName(void)
	{
		return L"GiveTopaz,GiveAme,GiveAcid,GiveAqua,StageIncreaseFactor,LevelIncreaseFactor";
	}
};
struct SSingleStageNormalMeta : public SProto
{
	__int32 CoolMinutes = 0;
	__int32 StageArea = 0;
	__int32 StageGroup = 0;
	TLevel MaxLevel = 0;
	SSingleStageNormalMeta()
	{
	}
	SSingleStageNormalMeta(const __int32& CoolMinutes_, const __int32& StageArea_, const __int32& StageGroup_, const TLevel& MaxLevel_) : CoolMinutes(CoolMinutes_), StageArea(StageArea_), StageGroup(StageGroup_), MaxLevel(MaxLevel_)
	{
	}
	SSingleStageNormalMeta(__int32&& CoolMinutes_, __int32&& StageArea_, __int32&& StageGroup_, TLevel&& MaxLevel_) : CoolMinutes(std::move(CoolMinutes_)), StageArea(std::move(StageArea_)), StageGroup(std::move(StageGroup_)), MaxLevel(std::move(MaxLevel_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> CoolMinutes;
		Stream_ >> StageArea;
		Stream_ >> StageGroup;
		Stream_ >> MaxLevel;
	}
	void operator << (const Value& Value_) override
	{
		Value_["CoolMinutes"] >> CoolMinutes;
		Value_["StageArea"] >> StageArea;
		Value_["StageGroup"] >> StageGroup;
		Value_["MaxLevel"] >> MaxLevel;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << CoolMinutes;
		Stream_ << StageArea;
		Stream_ << StageGroup;
		Stream_ << MaxLevel;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["CoolMinutes"] = CoolMinutes;
		Value_["StageArea"] = StageArea;
		Value_["StageGroup"] = StageGroup;
		Value_["MaxLevel"] = MaxLevel;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"CoolMinutes,StageArea,StageGroup,MaxLevel";
	}
};
struct SSingleReward : public SProto
{
	TResources Basic{};
	SSingleReward()
	{
	}
	SSingleReward(const TResources& Basic_) : Basic(Basic_)
	{
	}
	SSingleReward(TResources&& Basic_) : Basic(std::move(Basic_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Basic;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Basic"] >> Basic;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Basic;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Basic"] = Basic;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Basic";
	}
};
struct SSingleStageMeta : public SSingleStageNormalMeta
{
	vector<SSingleReward> Rewards;
	SSingleStageMeta()
	{
	}
	SSingleStageMeta(const SSingleStageNormalMeta& Super_, const vector<SSingleReward>& Rewards_) : SSingleStageNormalMeta(Super_), Rewards(Rewards_)
	{
	}
	SSingleStageMeta(SSingleStageNormalMeta&& Super_, vector<SSingleReward>&& Rewards_) : SSingleStageNormalMeta(std::move(Super_)), Rewards(std::move(Rewards_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Rewards;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Rewards"] >> Rewards;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Rewards;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Rewards"] = Rewards;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,{int32,int32,int32,int32,int32}";
	}
	static wstring MemberName(void)
	{
		return L"CoolMinutes,StageArea,StageGroup,MaxLevel,Rewards";
	}
};
struct SPillageResourceMeta : public SProto
{
	TResource AmeRatio = 0;
	TResource AcidRatio = 0;
	TResource AquaRatio = 0;
	TResource AmeMax = 0;
	TResource AcidMax = 0;
	TResource AquaMax = 0;
	SPillageResourceMeta()
	{
	}
	SPillageResourceMeta(const TResource& AmeRatio_, const TResource& AcidRatio_, const TResource& AquaRatio_, const TResource& AmeMax_, const TResource& AcidMax_, const TResource& AquaMax_) : AmeRatio(AmeRatio_), AcidRatio(AcidRatio_), AquaRatio(AquaRatio_), AmeMax(AmeMax_), AcidMax(AcidMax_), AquaMax(AquaMax_)
	{
	}
	SPillageResourceMeta(TResource&& AmeRatio_, TResource&& AcidRatio_, TResource&& AquaRatio_, TResource&& AmeMax_, TResource&& AcidMax_, TResource&& AquaMax_) : AmeRatio(std::move(AmeRatio_)), AcidRatio(std::move(AcidRatio_)), AquaRatio(std::move(AquaRatio_)), AmeMax(std::move(AmeMax_)), AcidMax(std::move(AcidMax_)), AquaMax(std::move(AquaMax_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> AmeRatio;
		Stream_ >> AcidRatio;
		Stream_ >> AquaRatio;
		Stream_ >> AmeMax;
		Stream_ >> AcidMax;
		Stream_ >> AquaMax;
	}
	void operator << (const Value& Value_) override
	{
		Value_["AmeRatio"] >> AmeRatio;
		Value_["AcidRatio"] >> AcidRatio;
		Value_["AquaRatio"] >> AquaRatio;
		Value_["AmeMax"] >> AmeMax;
		Value_["AcidMax"] >> AcidMax;
		Value_["AquaMax"] >> AquaMax;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << AmeRatio;
		Stream_ << AcidRatio;
		Stream_ << AquaRatio;
		Stream_ << AmeMax;
		Stream_ << AcidMax;
		Stream_ << AquaMax;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["AmeRatio"] = AmeRatio;
		Value_["AcidRatio"] = AcidRatio;
		Value_["AquaRatio"] = AquaRatio;
		Value_["AmeMax"] = AmeMax;
		Value_["AcidMax"] = AcidMax;
		Value_["AquaMax"] = AquaMax;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"AmeRatio,AcidRatio,AquaRatio,AmeMax,AcidMax,AquaMax";
	}
};
struct SPillagePenaltyMeta : public SProto
{
	TResource Ratio = 0;
	SPillagePenaltyMeta()
	{
	}
	SPillagePenaltyMeta(const TResource& Ratio_) : Ratio(Ratio_)
	{
	}
	SPillagePenaltyMeta(TResource&& Ratio_) : Ratio(std::move(Ratio_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Ratio;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Ratio"] >> Ratio;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Ratio;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Ratio"] = Ratio;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"Ratio";
	}
};
struct SAvatarDefaultSetMeta : public SProto
{
	TAvatarParts Parts{};
	SAvatarDefaultSetMeta()
	{
	}
	SAvatarDefaultSetMeta(const TAvatarParts& Parts_) : Parts(Parts_)
	{
	}
	SAvatarDefaultSetMeta(TAvatarParts&& Parts_) : Parts(std::move(Parts_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Parts;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Parts"] >> Parts;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Parts;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Parts"] = Parts;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Parts";
	}
};
struct SAvatarColorMeta : public SProto
{
	TID Color = 0;
	SAvatarColorMeta()
	{
	}
	SAvatarColorMeta(const TID& Color_) : Color(Color_)
	{
	}
	SAvatarColorMeta(TID&& Color_) : Color(std::move(Color_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Color;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Color"] >> Color;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Color;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Color"] = Color;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"Color";
	}
};
struct SUnionSupportLimitMeta : public SProto
{
	TForceCnts SendLimits{};
	TForceCnts RecvLimits{};
	SUnionSupportLimitMeta()
	{
	}
	SUnionSupportLimitMeta(const TForceCnts& SendLimits_, const TForceCnts& RecvLimits_) : SendLimits(SendLimits_), RecvLimits(RecvLimits_)
	{
	}
	SUnionSupportLimitMeta(TForceCnts&& SendLimits_, TForceCnts&& RecvLimits_) : SendLimits(std::move(SendLimits_)), RecvLimits(std::move(RecvLimits_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> SendLimits;
		Stream_ >> RecvLimits;
	}
	void operator << (const Value& Value_) override
	{
		Value_["SendLimits"] >> SendLimits;
		Value_["RecvLimits"] >> RecvLimits;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << SendLimits;
		Stream_ << RecvLimits;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["SendLimits"] = SendLimits;
		Value_["RecvLimits"] = RecvLimits;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"SendLimits,RecvLimits";
	}
};
struct SUnionLevelMeta : public SProto
{
	TExp AccExp = 0;
	__int32 BankCapacityUp = 0;
	__int32 UnionBossRewardUp = 0;
	__int32 TroopsLevelAdd = 0;
	__int32 UnionRequestTime = 0;
	__int32 UnitCountAdd = 0;
	__int32 ResourceReturn = 0;
	SUnionLevelMeta()
	{
	}
	SUnionLevelMeta(const TExp& AccExp_, const __int32& BankCapacityUp_, const __int32& UnionBossRewardUp_, const __int32& TroopsLevelAdd_, const __int32& UnionRequestTime_, const __int32& UnitCountAdd_, const __int32& ResourceReturn_) : AccExp(AccExp_), BankCapacityUp(BankCapacityUp_), UnionBossRewardUp(UnionBossRewardUp_), TroopsLevelAdd(TroopsLevelAdd_), UnionRequestTime(UnionRequestTime_), UnitCountAdd(UnitCountAdd_), ResourceReturn(ResourceReturn_)
	{
	}
	SUnionLevelMeta(TExp&& AccExp_, __int32&& BankCapacityUp_, __int32&& UnionBossRewardUp_, __int32&& TroopsLevelAdd_, __int32&& UnionRequestTime_, __int32&& UnitCountAdd_, __int32&& ResourceReturn_) : AccExp(std::move(AccExp_)), BankCapacityUp(std::move(BankCapacityUp_)), UnionBossRewardUp(std::move(UnionBossRewardUp_)), TroopsLevelAdd(std::move(TroopsLevelAdd_)), UnionRequestTime(std::move(UnionRequestTime_)), UnitCountAdd(std::move(UnitCountAdd_)), ResourceReturn(std::move(ResourceReturn_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> AccExp;
		Stream_ >> BankCapacityUp;
		Stream_ >> UnionBossRewardUp;
		Stream_ >> TroopsLevelAdd;
		Stream_ >> UnionRequestTime;
		Stream_ >> UnitCountAdd;
		Stream_ >> ResourceReturn;
	}
	void operator << (const Value& Value_) override
	{
		Value_["AccExp"] >> AccExp;
		Value_["BankCapacityUp"] >> BankCapacityUp;
		Value_["UnionBossRewardUp"] >> UnionBossRewardUp;
		Value_["TroopsLevelAdd"] >> TroopsLevelAdd;
		Value_["UnionRequestTime"] >> UnionRequestTime;
		Value_["UnitCountAdd"] >> UnitCountAdd;
		Value_["ResourceReturn"] >> ResourceReturn;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << AccExp;
		Stream_ << BankCapacityUp;
		Stream_ << UnionBossRewardUp;
		Stream_ << TroopsLevelAdd;
		Stream_ << UnionRequestTime;
		Stream_ << UnitCountAdd;
		Stream_ << ResourceReturn;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["AccExp"] = AccExp;
		Value_["BankCapacityUp"] = BankCapacityUp;
		Value_["UnionBossRewardUp"] = UnionBossRewardUp;
		Value_["TroopsLevelAdd"] = TroopsLevelAdd;
		Value_["UnionRequestTime"] = UnionRequestTime;
		Value_["UnitCountAdd"] = UnitCountAdd;
		Value_["ResourceReturn"] = ResourceReturn;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"AccExp,BankCapacityUp,UnionBossRewardUp,TroopsLevelAdd,UnionRequestTime,UnitCountAdd,ResourceReturn";
	}
};
struct SEnvObjectRewardMeta : public SProto
{
	TResource Topaz = 0;
	SEnvObjectRewardMeta()
	{
	}
	SEnvObjectRewardMeta(const TResource& Topaz_) : Topaz(Topaz_)
	{
	}
	SEnvObjectRewardMeta(TResource&& Topaz_) : Topaz(std::move(Topaz_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Topaz;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Topaz"] >> Topaz;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Topaz;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Topaz"] = Topaz;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"Topaz";
	}
};
struct SEnvObjectMeta : public SProto
{
	TID ID = 0;
	__int32 Size = 0;
	bool Regen = false;
	__int32 RemoveSec = 0;
	SResourceTypeData RemoveCost;
	__int32 Period = 0;
	SResourceTypeData Reward;
	SEnvObjectMeta()
	{
	}
	SEnvObjectMeta(const TID& ID_, const __int32& Size_, const bool& Regen_, const __int32& RemoveSec_, const SResourceTypeData& RemoveCost_, const __int32& Period_, const SResourceTypeData& Reward_) : ID(ID_), Size(Size_), Regen(Regen_), RemoveSec(RemoveSec_), RemoveCost(RemoveCost_), Period(Period_), Reward(Reward_)
	{
	}
	SEnvObjectMeta(TID&& ID_, __int32&& Size_, bool&& Regen_, __int32&& RemoveSec_, SResourceTypeData&& RemoveCost_, __int32&& Period_, SResourceTypeData&& Reward_) : ID(std::move(ID_)), Size(std::move(Size_)), Regen(std::move(Regen_)), RemoveSec(std::move(RemoveSec_)), RemoveCost(std::move(RemoveCost_)), Period(std::move(Period_)), Reward(std::move(Reward_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ID;
		Stream_ >> Size;
		Stream_ >> Regen;
		Stream_ >> RemoveSec;
		Stream_ >> RemoveCost;
		Stream_ >> Period;
		Stream_ >> Reward;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ID"] >> ID;
		Value_["Size"] >> Size;
		Value_["Regen"] >> Regen;
		Value_["RemoveSec"] >> RemoveSec;
		RemoveCost << Value_["RemoveCost"];
		Value_["Period"] >> Period;
		Reward << Value_["Reward"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ID;
		Stream_ << Size;
		Stream_ << Regen;
		Stream_ << RemoveSec;
		Stream_ << RemoveCost;
		Stream_ << Period;
		Stream_ << Reward;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ID"] = ID;
		Value_["Size"] = Size;
		Value_["Regen"] = Regen;
		Value_["RemoveSec"] = RemoveSec;
		Value_["RemoveCost"] = RemoveCost;
		Value_["Period"] = Period;
		Value_["Reward"] = Reward;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,bool,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ID,Size,Regen,RemoveSec,Type,Data,Period,Type,Data";
	}
};
struct SKeyEnvObjectMeta : public SProto
{
	TID Key = 0;
	SEnvObjectMeta Data;
	SKeyEnvObjectMeta()
	{
	}
	SKeyEnvObjectMeta(const TID& Key_, const SEnvObjectMeta& Data_) : Key(Key_), Data(Data_)
	{
	}
	SKeyEnvObjectMeta(TID&& Key_, SEnvObjectMeta&& Data_) : Key(std::move(Key_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Key;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Key"] >> Key;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Key;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Key"] = Key;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,bool,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Key,ID,Size,Regen,RemoveSec,Type,Data,Period,Type,Data";
	}
};
struct SBootyCapacityMeta : public SProto
{
	TResource Ame = 0;
	TResource Acid = 0;
	TResource Aqua = 0;
	SBootyCapacityMeta()
	{
	}
	SBootyCapacityMeta(const TResource& Ame_, const TResource& Acid_, const TResource& Aqua_) : Ame(Ame_), Acid(Acid_), Aqua(Aqua_)
	{
	}
	SBootyCapacityMeta(TResource&& Ame_, TResource&& Acid_, TResource&& Aqua_) : Ame(std::move(Ame_)), Acid(std::move(Acid_)), Aqua(std::move(Aqua_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Ame;
		Stream_ >> Acid;
		Stream_ >> Aqua;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Ame"] >> Ame;
		Value_["Acid"] >> Acid;
		Value_["Aqua"] >> Aqua;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Ame;
		Stream_ << Acid;
		Stream_ << Aqua;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Ame"] = Ame;
		Value_["Acid"] = Acid;
		Value_["Aqua"] = Aqua;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Ame,Acid,Aqua";
	}
};
struct SBootyCartMeta : public SProto
{
	__int32 Area = 0;
	SBootyCartMeta()
	{
	}
	SBootyCartMeta(const __int32& Area_) : Area(Area_)
	{
	}
	SBootyCartMeta(__int32&& Area_) : Area(std::move(Area_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Area;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Area"] >> Area;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Area;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Area"] = Area;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"Area";
	}
};
struct SEnvDevelopRewardMeta : public SProto
{
	TResources Reward{};
	SEnvDevelopRewardMeta()
	{
	}
	SEnvDevelopRewardMeta(const TResources& Reward_) : Reward(Reward_)
	{
	}
	SEnvDevelopRewardMeta(TResources&& Reward_) : Reward(std::move(Reward_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Reward;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Reward"] >> Reward;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Reward;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Reward"] = Reward;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Reward";
	}
};
struct SDevObjectLayerMeta : public SProto
{
	__int32 RemoveSec = 0;
	SResourceTypeData Cost;
	SDevObjectLayerMeta()
	{
	}
	SDevObjectLayerMeta(const __int32& RemoveSec_, const SResourceTypeData& Cost_) : RemoveSec(RemoveSec_), Cost(Cost_)
	{
	}
	SDevObjectLayerMeta(__int32&& RemoveSec_, SResourceTypeData&& Cost_) : RemoveSec(std::move(RemoveSec_)), Cost(std::move(Cost_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> RemoveSec;
		Stream_ >> Cost;
	}
	void operator << (const Value& Value_) override
	{
		Value_["RemoveSec"] >> RemoveSec;
		Cost << Value_["Cost"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << RemoveSec;
		Stream_ << Cost;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["RemoveSec"] = RemoveSec;
		Value_["Cost"] = Cost;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"RemoveSec,Type,Data";
	}
};
struct SEnvDevelopPresetMeta : public SProto
{
	TID ObjectID = 0;
	SPos Pos;
	SEnvDevelopPresetMeta()
	{
	}
	SEnvDevelopPresetMeta(const TID& ObjectID_, const SPos& Pos_) : ObjectID(ObjectID_), Pos(Pos_)
	{
	}
	SEnvDevelopPresetMeta(TID&& ObjectID_, SPos&& Pos_) : ObjectID(std::move(ObjectID_)), Pos(std::move(Pos_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ObjectID;
		Stream_ >> Pos;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ObjectID"] >> ObjectID;
		Pos << Value_["Pos"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ObjectID;
		Stream_ << Pos;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ObjectID"] = ObjectID;
		Value_["Pos"] = Pos;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ObjectID,X,Y";
	}
};
struct SEnvDevelopObjectMeta : public SProto
{
	__int32 Size = 0;
	SEnvDevelopObjectMeta()
	{
	}
	SEnvDevelopObjectMeta(const __int32& Size_) : Size(Size_)
	{
	}
	SEnvDevelopObjectMeta(__int32&& Size_) : Size(std::move(Size_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Size;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Size"] >> Size;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Size;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Size"] = Size;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"Size";
	}
};
struct SKeyEnvDevelopObjectMeta : public SProto
{
	TID Key = 0;
	SEnvDevelopObjectMeta Data;
	SKeyEnvDevelopObjectMeta()
	{
	}
	SKeyEnvDevelopObjectMeta(const TID& Key_, const SEnvDevelopObjectMeta& Data_) : Key(Key_), Data(Data_)
	{
	}
	SKeyEnvDevelopObjectMeta(TID&& Key_, SEnvDevelopObjectMeta&& Data_) : Key(std::move(Key_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Key;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Key"] >> Key;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Key;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Key"] = Key;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Key,Size";
	}
};
struct SBoostCostMeta : public SProto
{
	__int32 DurationHour = 0;
	TResource CostTopaz = 0;
	double Speed = 0.0;
	SBoostCostMeta()
	{
	}
	SBoostCostMeta(const __int32& DurationHour_, const TResource& CostTopaz_, const double& Speed_) : DurationHour(DurationHour_), CostTopaz(CostTopaz_), Speed(Speed_)
	{
	}
	SBoostCostMeta(__int32&& DurationHour_, TResource&& CostTopaz_, double&& Speed_) : DurationHour(std::move(DurationHour_)), CostTopaz(std::move(CostTopaz_)), Speed(std::move(Speed_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> DurationHour;
		Stream_ >> CostTopaz;
		Stream_ >> Speed;
	}
	void operator << (const Value& Value_) override
	{
		Value_["DurationHour"] >> DurationHour;
		Value_["CostTopaz"] >> CostTopaz;
		Value_["Speed"] >> Speed;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << DurationHour;
		Stream_ << CostTopaz;
		Stream_ << Speed;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["DurationHour"] = DurationHour;
		Value_["CostTopaz"] = CostTopaz;
		Value_["Speed"] = Speed;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,double";
	}
	static wstring MemberName(void)
	{
		return L"DurationHour,CostTopaz,Speed";
	}
};
struct SBoostRechargerMeta : public SProto
{
	__int32 DurationHour = 0;
	TResource CostTopaz = 0;
	double Speed = 0.0;
	SBoostRechargerMeta()
	{
	}
	SBoostRechargerMeta(const __int32& DurationHour_, const TResource& CostTopaz_, const double& Speed_) : DurationHour(DurationHour_), CostTopaz(CostTopaz_), Speed(Speed_)
	{
	}
	SBoostRechargerMeta(__int32&& DurationHour_, TResource&& CostTopaz_, double&& Speed_) : DurationHour(std::move(DurationHour_)), CostTopaz(std::move(CostTopaz_)), Speed(std::move(Speed_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> DurationHour;
		Stream_ >> CostTopaz;
		Stream_ >> Speed;
	}
	void operator << (const Value& Value_) override
	{
		Value_["DurationHour"] >> DurationHour;
		Value_["CostTopaz"] >> CostTopaz;
		Value_["Speed"] >> Speed;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << DurationHour;
		Stream_ << CostTopaz;
		Stream_ << Speed;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["DurationHour"] = DurationHour;
		Value_["CostTopaz"] = CostTopaz;
		Value_["Speed"] = Speed;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,double";
	}
	static wstring MemberName(void)
	{
		return L"DurationHour,CostTopaz,Speed";
	}
};
struct SBankMeta : public SProto
{
	TResources Resources{};
	TID InterestID = 0;
	SBankMeta()
	{
	}
	SBankMeta(const TResources& Resources_, const TID& InterestID_) : Resources(Resources_), InterestID(InterestID_)
	{
	}
	SBankMeta(TResources&& Resources_, TID&& InterestID_) : Resources(std::move(Resources_)), InterestID(std::move(InterestID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Resources;
		Stream_ >> InterestID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Resources"] >> Resources;
		Value_["InterestID"] >> InterestID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Resources;
		Stream_ << InterestID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Resources"] = Resources;
		Value_["InterestID"] = InterestID;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Resources,InterestID";
	}
};
struct SBankInterestMeta : public SProto
{
	__int32 DurationDay = 0;
	__int32 InterestPercent = 0;
	SBankInterestMeta()
	{
	}
	SBankInterestMeta(const __int32& DurationDay_, const __int32& InterestPercent_) : DurationDay(DurationDay_), InterestPercent(InterestPercent_)
	{
	}
	SBankInterestMeta(__int32&& DurationDay_, __int32&& InterestPercent_) : DurationDay(std::move(DurationDay_)), InterestPercent(std::move(InterestPercent_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> DurationDay;
		Stream_ >> InterestPercent;
	}
	void operator << (const Value& Value_) override
	{
		Value_["DurationDay"] >> DurationDay;
		Value_["InterestPercent"] >> InterestPercent;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << DurationDay;
		Stream_ << InterestPercent;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["DurationDay"] = DurationDay;
		Value_["InterestPercent"] = InterestPercent;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"DurationDay,InterestPercent";
	}
};
struct SKeyBankInterestMeta : public SProto
{
	TID Key = 0;
	SBankInterestMeta Data;
	SKeyBankInterestMeta()
	{
	}
	SKeyBankInterestMeta(const TID& Key_, const SBankInterestMeta& Data_) : Key(Key_), Data(Data_)
	{
	}
	SKeyBankInterestMeta(TID&& Key_, SBankInterestMeta&& Data_) : Key(std::move(Key_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Key;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Key"] >> Key;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Key;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Key"] = Key;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Key,DurationDay,InterestPercent";
	}
};
struct SBattleBonusConfigMeta : public SProto
{
	__int32 MaxHaveCnt = 0;
	__int32 PeriodMinutes = 0;
	__int32 RewardGoalPoint = 0;
	SBattleBonusConfigMeta()
	{
	}
	SBattleBonusConfigMeta(const __int32& MaxHaveCnt_, const __int32& PeriodMinutes_, const __int32& RewardGoalPoint_) : MaxHaveCnt(MaxHaveCnt_), PeriodMinutes(PeriodMinutes_), RewardGoalPoint(RewardGoalPoint_)
	{
	}
	SBattleBonusConfigMeta(__int32&& MaxHaveCnt_, __int32&& PeriodMinutes_, __int32&& RewardGoalPoint_) : MaxHaveCnt(std::move(MaxHaveCnt_)), PeriodMinutes(std::move(PeriodMinutes_)), RewardGoalPoint(std::move(RewardGoalPoint_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> MaxHaveCnt;
		Stream_ >> PeriodMinutes;
		Stream_ >> RewardGoalPoint;
	}
	void operator << (const Value& Value_) override
	{
		Value_["MaxHaveCnt"] >> MaxHaveCnt;
		Value_["PeriodMinutes"] >> PeriodMinutes;
		Value_["RewardGoalPoint"] >> RewardGoalPoint;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << MaxHaveCnt;
		Stream_ << PeriodMinutes;
		Stream_ << RewardGoalPoint;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["MaxHaveCnt"] = MaxHaveCnt;
		Value_["PeriodMinutes"] = PeriodMinutes;
		Value_["RewardGoalPoint"] = RewardGoalPoint;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"MaxHaveCnt,PeriodMinutes,RewardGoalPoint";
	}
};
struct SBattleBonusRewardMeta : public SProto
{
	__int32 Amethyst = 0;
	__int32 Acid = 0;
	__int32 Aquajelly = 0;
	SBattleBonusRewardMeta()
	{
	}
	SBattleBonusRewardMeta(const __int32& Amethyst_, const __int32& Acid_, const __int32& Aquajelly_) : Amethyst(Amethyst_), Acid(Acid_), Aquajelly(Aquajelly_)
	{
	}
	SBattleBonusRewardMeta(__int32&& Amethyst_, __int32&& Acid_, __int32&& Aquajelly_) : Amethyst(std::move(Amethyst_)), Acid(std::move(Acid_)), Aquajelly(std::move(Aquajelly_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Amethyst;
		Stream_ >> Acid;
		Stream_ >> Aquajelly;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Amethyst"] >> Amethyst;
		Value_["Acid"] >> Acid;
		Value_["Aquajelly"] >> Aquajelly;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Amethyst;
		Stream_ << Acid;
		Stream_ << Aquajelly;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Amethyst"] = Amethyst;
		Value_["Acid"] = Acid;
		Value_["Aquajelly"] = Aquajelly;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Amethyst,Acid,Aquajelly";
	}
};
struct SKeyBattleBonusRewardMeta : public SProto
{
	TLeaguePoint Key = 0;
	SBattleBonusRewardMeta Data;
	SKeyBattleBonusRewardMeta()
	{
	}
	SKeyBattleBonusRewardMeta(const TLeaguePoint& Key_, const SBattleBonusRewardMeta& Data_) : Key(Key_), Data(Data_)
	{
	}
	SKeyBattleBonusRewardMeta(TLeaguePoint&& Key_, SBattleBonusRewardMeta&& Data_) : Key(std::move(Key_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Key;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Key"] >> Key;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Key;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Key"] = Key;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Key,Amethyst,Acid,Aquajelly";
	}
};
struct _SAchievementMeta : public SProto
{
	__int32 goal_value = 0;
	TExp reward_exp = 0;
	TResource reward_topaz = 0;
	_SAchievementMeta()
	{
	}
	_SAchievementMeta(const __int32& goal_value_, const TExp& reward_exp_, const TResource& reward_topaz_) : goal_value(goal_value_), reward_exp(reward_exp_), reward_topaz(reward_topaz_)
	{
	}
	_SAchievementMeta(__int32&& goal_value_, TExp&& reward_exp_, TResource&& reward_topaz_) : goal_value(std::move(goal_value_)), reward_exp(std::move(reward_exp_)), reward_topaz(std::move(reward_topaz_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> goal_value;
		Stream_ >> reward_exp;
		Stream_ >> reward_topaz;
	}
	void operator << (const Value& Value_) override
	{
		Value_["goal_value"] >> goal_value;
		Value_["reward_exp"] >> reward_exp;
		Value_["reward_topaz"] >> reward_topaz;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << goal_value;
		Stream_ << reward_exp;
		Stream_ << reward_topaz;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["goal_value"] = goal_value;
		Value_["reward_exp"] = reward_exp;
		Value_["reward_topaz"] = reward_topaz;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"goal_value,reward_exp,reward_topaz";
	}
};
struct SAchievementMeta : public SProto
{
	EAchievement type;
	_SAchievementMeta data;
	SAchievementMeta()
	{
	}
	SAchievementMeta(const EAchievement& type_, const _SAchievementMeta& data_) : type(type_), data(data_)
	{
	}
	SAchievementMeta(EAchievement&& type_, _SAchievementMeta&& data_) : type(std::move(type_)), data(std::move(data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int32&)type;
		Stream_ >> data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["type"] >> (__int32&)type;
		data << Value_["data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int32)type;
		Stream_ << data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["type"] = (__int32)type;
		Value_["data"] = data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"type,goal_value,reward_exp,reward_topaz";
	}
};
struct SForbiddenTextMeta : public SProto
{
	wstring text;
	SForbiddenTextMeta()
	{
	}
	SForbiddenTextMeta(const wstring& text_) : text(text_)
	{
	}
	SForbiddenTextMeta(wstring&& text_) : text(std::move(text_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> text;
	}
	void operator << (const Value& Value_) override
	{
		Value_["text"] >> text;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << text;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["text"] = text;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"text";
	}
};
