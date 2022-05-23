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


#include <Rso/Game/Protocol.h>
#include <Rso/Physics/Protocol.h>
#include <Rso/GameUtil/Protocol.h>
using namespace rso;
using namespace rso::game;
using namespace rso::physics;
using namespace rso::gameutil;
using TIndex = __int64;
using TID = __int32;
using TLevel = __int32;
using THP = __int32;
using TSlotNo = __int8;
using TLeaguePoint = __int32;
using TExp = __int32;
using TRank = __int32;
using TEnchant = __int32;
const TVer c_Ver_Main = 21;
const __int32 c_EdgeSize = 5;
const __int32 c_GridSize = 4;
const __int32 c_GridCnt = 10;
const __int32 c_FullMapSize = (c_EdgeSize*2+c_GridSize*c_GridCnt);
const __int32 c_OpenedLayerCnt = 6;
const __int32 c_ClanBookMarkCnt_Max = 20;
const __int32 c_BarrierTimeReductionMinutes = 20;
enum class EProtoNetCs
{
	BuyResourcesWithTopaz,
	Build,
	BuildingUpgrade,
	BuildingUpgradeCancel,
	BuildingUpgradeComplete,
	BuildingMove,
	BuildingChangeMode,
	BuildingReinstall,
	BuildingBulletChange,
	Collect,
	Train,
	TrainWithTopaz,
	BarrackSync,
	UnitUpgrade,
	UnitUpgradeComplete,
	AvatarSlotAdd,
	AvatarSaveSlot,
	AvatarActivate,
	AvatarUpgrade,
	AvatarUpgradeComplete,
	AvatarCoolEnded,
	AvatarRepairDefence,
	AvatarEnableDefence,
	BattleSingleStart,
	BattleSingleUnitDrop,
	BattleSingleClanUnitDrop,
	BattleSingleAvatarDrop,
	BattleSingleResourceGot,
	BattleSingleAvatarCoolTime,
	BattleSingleEnd,
	BattleScout,
	BattleScoutTarget,
	BattleRevenge,
	BattleCheckPoint,
	BattleUnitDrop,
	BattleClanUnitDrop,
	BattleAvatarAction,
	BattleEnd,
	BattleFinish,
	ReplayLoadAttack,
	ReplayLoadDefence,
	Chat,
	ClanCastleCoolEndWithTopaz,
	ClanCastleDelUnit,
	EnvObjectDel,
	EnvObjectDelCancel,
	EnvObjectDelComplete,
	EnvDevelopDel,
	EnvDevelopDelCancel,
	EnvDevelopDelComplete,
	BootyTake,
	BoostBuilding,
	BoostBB,
	BoostBatch,
	BankDeposit,
	BankWithdraw,
	InvitationReject,
	MailDelete,
	UserProfileInfo,
	UserVisitInfo,
	TutorialComplete,
	AchievementReward,
	ClanInfo,
	ClanSearch,
	ClanSearchWithFilter,
	ClanSupportRequest,
	ClanSupport,
	ClanBookMarkList,
	ClanBookMarkAdd,
	ClanBookMarkDel,
	ClanJoinResponse,
	ClanModify,
	ClanInvite,
	ClanChatStream2Load,
	ClanChangeGrade,
	ClanBanish,
	ClanOut,
	ClanSendMessageAll,
	ClanChatMsg,
	ClanReplayShare,
	FCMTokenSet,
	FCMTokenUnset,
	Max,
	Null,
};
enum class EProtoNetSc
{
	Message,
	BattleInfo,
	UnderAttack,
	UserInfo,
	Build,
	BuildingUpgrade,
	BuildingUpgradeCancel,
	BuildingUpgradeComplete,
	BuildingMove,
	BuildingChangeMode,
	BuildingReinstall,
	BuildingBulletChange,
	Collect,
	Train,
	TrainWithTopaz,
	UnitUpgrade,
	UnitUpgradeComplete,
	AvatarSaveSlot,
	AvatarActivate,
	AvatarUpgrade,
	AvatarRepairDefence,
	BattleScout,
	BattleCheckPoint,
	BattleUnitDropOther,
	BattleClanUnitDropOther,
	BattleAvatarActionOther,
	BattleEnded,
	UserInfoSub,
	ReplayLoadAttack,
	ReplayLoadDefence,
	ReplayAttackAdded,
	Chat,
	ResourceLeft,
	UserExp,
	ClanCastleCoolEndWithTopaz,
	EnvObjectDel,
	EnvObjectDelCancel,
	EnvObjectDelComplete,
	EnvDevelopDel,
	EnvDevelopDelCancel,
	EnvDevelopDelComplete,
	BootyTake,
	BoostBuilding,
	BoostBB,
	BoostBatch,
	BankDeposit,
	BankWithdraw,
	InvitationRecv,
	MailRecv,
	UserProfileInfo,
	UserVisitInfo,
	ClanCreateOk,
	ClanUnset,
	ClanInfo,
	ClanSearch,
	ClanBookMarkList,
	ClanJoinAllowOk,
	ClanOnlineInfo,
	ClanLogin,
	ClanJoin,
	ClanModify,
	ClanChatStream2Load,
	ClanChangeGrade,
	ClanOut,
	ClanSupportRequest,
	ClanSupport,
	ClanReceive,
	ClanChat,
	ClanChatModify,
	ClanChatDelete,
	Max,
};
enum class ERet
{
	Ok,
	AchievementOverLevel,
	AchievementNotEnoughCount,
	CanNotSupportToMe,
	CanNotBoost,
	CanNotChangeGrade,
	CanNotChangeMode,
	InvalidTime,
	InvalidAccess,
	InvalidAchievementType,
	InvalidCall,
	InvalidCPLevel,
	InvalidResource,
	InvalidResourceValue,
	InvalidGroupID,
	InvalidUnitID,
	InvalidUnitCnt,
	InvalidUnitLevel,
	InvalidShopID,
	InvalidColorID,
	InvalidDevObjectIndex,
	InvalidEnvObjectID,
	InvalidSlotNo,
	InvalidIndex,
	InvalidEnvObjectIndex,
	InvalidEnvObjectCompleteTime,
	InvalidBuildingIndex,
	InvalidBuildingID,
	InvalidBuildingMode,
	InvalidLevel,
	InvalidBankLevel,
	InvalidBuildingLevel,
	InvalidBuildingRotate,
	InvalidDefenceBuildingType,
	InvalidCoolTime,
	InvalidUID,
	InvalidPW,
	InvalidBulletLeft,
	InvalidSingleArea,
	InvalidSingleType,
	InvalidSingleGroup,
	InvalidSingleStage,
	InvalidStarGot,
	InvalidResourceFromCollector,
	InvalidCollectorIndex,
	InvalidBuildingPos,
	InvalidEnvObjectPos,
	InvalidDevObjectPos,
	InvalidReplayIndex,
	InvalidChatIndex,
	InvalidBootyPos,
	InvalidMailIndex,
	InvalidShuttleSize,
	InvalidShuttleNum,
	InvalidStartTime,
	InvalidForceType,
	InvalidTutorialNumber,
	InvalidDropCnt,
	InvalidCheckPoint,
	InvalidProtocol,
	UnitAllDropped,
	UnitIsNotReady,
	AlreadyCompleted,
	AlreadyCompleting,
	AlreadyCoolEnded,
	AlreadyInstalled,
	AlreadyInBoost,
	AlreadyRevenged,
	AlreadyInvited,
	AlreadyResponsed,
	AlreadyJoinRequested,
	AlreadyBookMarkedClan,
	BattleEndDelayed,
	DupLogin,
	EmptyBooty,
	EmptyBookMark,
	MustClearPrevStage,
	OverOccupied,
	OverCapacity,
	OverCount,
	OverSendCount,
	OverRecvCount,
	OverUpgrade,
	OverSlotNo,
	OverSendLimit,
	OverFlow,
	OverResource,
	OverResourceCanGet,
	OverClanDescSize,
	OverClanBookMarkCnt,
	OverAvatarSlot,
	OnlyDefencePortalCanChangeUnitGroup,
	UnderMinLeaguePoint,
	NeedTechLab,
	NeedFactory,
	NeedWeaponLab,
	NeedAvatarPlatform,
	NeedAvatarLab,
	NeedMoreRecharger,
	NeedToBattleFinish,
	NoInFieldUnits,
	NoUserToBattle,
	TargetIsGuarded,
	TargetIsLogon,
	NoBuildingToRepair,
	NoDefenceAvatar,
	NotCompleted,
	NotCompleting,
	NotEnoughTopaz,
	NotEnoughMoney,
	NotEnoughUserLevel,
	NotEnoughCPLevel,
	NotEnoughTechLabLevel,
	NotEnoughAvatarLabLevel,
	NotEnoughSupportData,
	NotEnoughFactoryLevel,
	NotEnoughWeaponLabLevel,
	NotInBattle,
	NotInBattleSingle,
	NotHaveBooty,
	NotHaveClan,
	NotHaveUnionCenter,
	NotHaveBank,
	NotReadyAvatar,
	NotReadyDefenceAvatar,
	NotUpgrading,
	NotNeedToBattleFinish,
	NotDefencePortal,
	UnderConstruction,
	MinLevel,
	MaxLevel,
	BattleIsAlreadyStarted,
	InBusy,
	InCompleting,
	InUpgrading,
	InBattleSingle,
	InScouting,
	InScout,
	InScouted,
	SingleCoolTime,
	SameClanMemberGrade,
	SameMode,
	SameBulletGroupID,
	TooFastTraining,
	ResourcesChanged,
	ClanCastleFull,
	BankIsUnderConstruction,
	BankIsNotEmpty,
	BankIsEmpty,
	SystemError,
	SystemErrorInsert,
	SPError,
	InvalidClanCastleLevel,
	InvalidClanLogin,
	InvalidClanName,
	InvalidClanUID,
	InvalidClanType,
	InvalidClanJoin,
	InvalidClanChatType,
	InvalidClanMember,
	InvalidClanMemberUID,
	InvalidClanMemberGrade,
	InvalidClanLevel,
	AlreadyExistClan,
	AlreadyHaveAClan,
	AlreadyJoinedClanMember,
	CoolTimeClanCastle,
	EmptyClanCastleUnit,
	ClanIsAlreadyCreated,
	SpNotEnoughMoney=50004,
	SpNotUnionMember=51000,
	SpAlreadyHaveAClan=51001,
	SpInvalidClanUID=51002,
	SpInvalidReplayIndex=51003,
	Max,
	Null,
};
struct SCsRet : public SProto
{
	EProtoNetCs CsProto;
	ERet Ret;
	SCsRet()
	{
	}
	SCsRet(const EProtoNetCs& CsProto_, const ERet& Ret_) : CsProto(CsProto_), Ret(Ret_)
	{
	}
	SCsRet(EProtoNetCs&& CsProto_, ERet&& Ret_) : CsProto(std::move(CsProto_)), Ret(std::move(Ret_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int32&)CsProto;
		Stream_ >> (__int32&)Ret;
	}
	void operator << (const Value& Value_) override
	{
		Value_["CsProto"] >> (__int32&)CsProto;
		Value_["Ret"] >> (__int32&)Ret;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int32)CsProto;
		Stream_ << (__int32)Ret;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["CsProto"] = (__int32)CsProto;
		Value_["Ret"] = (__int32)Ret;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"CsProto,Ret";
	}
};
enum class EBuilding
{
	CP,
	Storage,
	Collector,
	Factory,
	RechargingStation,
	UnionCenter,
	SpacePlatform,
	TechLab,
	ExploreDock,
	Armory,
	AvatarPlatform,
	AvatarLab,
	Defence,
	RnDCenter,
	Bank,
	Max,
	Null,
};
enum class EZoneType
{
	Defender,
	Base,
	Factory,
	Platform,
	Max,
	Null,
};
enum class EBuildingRotate : __int8
{
	D0,
	D90,
	D180,
	D270,
	Max,
	Null,
};
enum class EBuildingRotateHead : __int8
{
	D0,
	D45,
	D90,
	D135,
	D180,
	D225,
	D270,
	D315,
	Max,
	Null,
};
enum class EResource
{
	Topaz,
	Ame,
	Acid,
	Aqua,
	Dark,
	Max,
	Null,
};
enum class EForceType
{
	Unit,
	Weapon,
	Max,
	Null,
};
enum class ERegion : __int8
{
	Asia,
	NorthAmerica,
	Europe,
	SouthAmerica,
	Oceania,
	Africa,
	Max,
	Null,
};
using TResource = __int32;
using TResources = array<TResource,5>;
using TResourcesI64 = array<__int64,5>;
using TResourcesDbl = array<double,5>;
using TForceCnts = array<__int32,2>;
enum EMessageType
{
	SystemError,
	GameError,
	Notification,
};
struct SMessageNetSc : public SProto
{
	EMessageType Type;
	EProtoNetCs ProtoCs;
	ERet Ret;
	wstring Msg;
	SMessageNetSc()
	{
	}
	SMessageNetSc(const EMessageType& Type_, const EProtoNetCs& ProtoCs_, const ERet& Ret_, const wstring& Msg_) : Type(Type_), ProtoCs(ProtoCs_), Ret(Ret_), Msg(Msg_)
	{
	}
	SMessageNetSc(EMessageType&& Type_, EProtoNetCs&& ProtoCs_, ERet&& Ret_, wstring&& Msg_) : Type(std::move(Type_)), ProtoCs(std::move(ProtoCs_)), Ret(std::move(Ret_)), Msg(std::move(Msg_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int32&)Type;
		Stream_ >> (__int32&)ProtoCs;
		Stream_ >> (__int32&)Ret;
		Stream_ >> Msg;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Type"] >> (__int32&)Type;
		Value_["ProtoCs"] >> (__int32&)ProtoCs;
		Value_["Ret"] >> (__int32&)Ret;
		Value_["Msg"] >> Msg;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int32)Type;
		Stream_ << (__int32)ProtoCs;
		Stream_ << (__int32)Ret;
		Stream_ << Msg;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Type"] = (__int32)Type;
		Value_["ProtoCs"] = (__int32)ProtoCs;
		Value_["Ret"] = (__int32)Ret;
		Value_["Msg"] = Msg;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,wstring";
	}
	static wstring MemberName(void)
	{
		return L"Type,ProtoCs,Ret,Msg";
	}
};
struct SResourceTypeData : public SProto
{
	EResource Type;
	TResource Data = 0;
	SResourceTypeData()
	{
	}
	SResourceTypeData(const EResource& Type_, const TResource& Data_) : Type(Type_), Data(Data_)
	{
	}
	SResourceTypeData(EResource&& Type_, TResource&& Data_) : Type(std::move(Type_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int32&)Type;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Type"] >> (__int32&)Type;
		Value_["Data"] >> Data;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int32)Type;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Type"] = (__int32)Type;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Type,Data";
	}
};
struct SPos : public SProto
{
	__int32 X = 0;
	__int32 Y = 0;
	SPos()
	{
	}
	SPos(const __int32& X_, const __int32& Y_) : X(X_), Y(Y_)
	{
	}
	SPos(__int32&& X_, __int32&& Y_) : X(std::move(X_)), Y(std::move(Y_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> X;
		Stream_ >> Y;
	}
	void operator << (const Value& Value_) override
	{
		Value_["X"] >> X;
		Value_["Y"] >> Y;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << X;
		Stream_ << Y;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["X"] = X;
		Value_["Y"] = Y;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"X,Y";
	}
};
struct SLeaguePoint : public SProto
{
	TLeaguePoint LeaguePoint = 0;
	TID LeagueCur = 0;
	TID LeagueBest = 0;
	SLeaguePoint()
	{
	}
	SLeaguePoint(const TLeaguePoint& LeaguePoint_, const TID& LeagueCur_, const TID& LeagueBest_) : LeaguePoint(LeaguePoint_), LeagueCur(LeagueCur_), LeagueBest(LeagueBest_)
	{
	}
	SLeaguePoint(TLeaguePoint&& LeaguePoint_, TID&& LeagueCur_, TID&& LeagueBest_) : LeaguePoint(std::move(LeaguePoint_)), LeagueCur(std::move(LeagueCur_)), LeagueBest(std::move(LeagueBest_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> LeaguePoint;
		Stream_ >> LeagueCur;
		Stream_ >> LeagueBest;
	}
	void operator << (const Value& Value_) override
	{
		Value_["LeaguePoint"] >> LeaguePoint;
		Value_["LeagueCur"] >> LeagueCur;
		Value_["LeagueBest"] >> LeagueBest;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << LeaguePoint;
		Stream_ << LeagueCur;
		Stream_ << LeagueBest;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["LeaguePoint"] = LeaguePoint;
		Value_["LeagueCur"] = LeagueCur;
		Value_["LeagueBest"] = LeagueBest;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"LeaguePoint,LeagueCur,LeagueBest";
	}
};
struct SLeaguePointGot : public SProto
{
	TLeaguePoint Win = 0;
	TLeaguePoint Lose = 0;
	SLeaguePointGot()
	{
	}
	SLeaguePointGot(const TLeaguePoint& Win_, const TLeaguePoint& Lose_) : Win(Win_), Lose(Lose_)
	{
	}
	SLeaguePointGot(TLeaguePoint&& Win_, TLeaguePoint&& Lose_) : Win(std::move(Win_)), Lose(std::move(Lose_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Win;
		Stream_ >> Lose;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Win"] >> Win;
		Value_["Lose"] >> Lose;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Win;
		Stream_ << Lose;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Win"] = Win;
		Value_["Lose"] = Lose;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Win,Lose";
	}
};
struct SUserBase : public SProto
{
	TResources Resource{};
	SLeaguePoint LeaguePoint;
	TSlotNo AvatarActivatedSlotNo = 0;
	TExp Exp = 0;
	__int8 Debug = 0;
	system_clock::time_point LastEnvObjectGenTime;
	SUserBase()
	{
	}
	SUserBase(const TResources& Resource_, const SLeaguePoint& LeaguePoint_, const TSlotNo& AvatarActivatedSlotNo_, const TExp& Exp_, const __int8& Debug_, const system_clock::time_point& LastEnvObjectGenTime_) : Resource(Resource_), LeaguePoint(LeaguePoint_), AvatarActivatedSlotNo(AvatarActivatedSlotNo_), Exp(Exp_), Debug(Debug_), LastEnvObjectGenTime(LastEnvObjectGenTime_)
	{
	}
	SUserBase(TResources&& Resource_, SLeaguePoint&& LeaguePoint_, TSlotNo&& AvatarActivatedSlotNo_, TExp&& Exp_, __int8&& Debug_, system_clock::time_point&& LastEnvObjectGenTime_) : Resource(std::move(Resource_)), LeaguePoint(std::move(LeaguePoint_)), AvatarActivatedSlotNo(std::move(AvatarActivatedSlotNo_)), Exp(std::move(Exp_)), Debug(std::move(Debug_)), LastEnvObjectGenTime(std::move(LastEnvObjectGenTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Resource;
		Stream_ >> LeaguePoint;
		Stream_ >> AvatarActivatedSlotNo;
		Stream_ >> Exp;
		Stream_ >> Debug;
		Stream_ >> LastEnvObjectGenTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Resource"] >> Resource;
		LeaguePoint << Value_["LeaguePoint"];
		Value_["AvatarActivatedSlotNo"] >> AvatarActivatedSlotNo;
		Value_["Exp"] >> Exp;
		Value_["Debug"] >> Debug;
		Value_["LastEnvObjectGenTime"] >> LastEnvObjectGenTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Resource;
		Stream_ << LeaguePoint;
		Stream_ << AvatarActivatedSlotNo;
		Stream_ << Exp;
		Stream_ << Debug;
		Stream_ << LastEnvObjectGenTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Resource"] = Resource;
		Value_["LeaguePoint"] = LeaguePoint;
		Value_["AvatarActivatedSlotNo"] = AvatarActivatedSlotNo;
		Value_["Exp"] = Exp;
		Value_["Debug"] = Debug;
		Value_["LastEnvObjectGenTime"] = LastEnvObjectGenTime;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,int8,int32,int8,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Resource,LeaguePoint,LeagueCur,LeagueBest,AvatarActivatedSlotNo,Exp,Debug,LastEnvObjectGenTime";
	}
};
struct SBooty : public SProto
{
	TResources Resources{};
	SPos Pos;
	SBooty()
	{
	}
	SBooty(const TResources& Resources_, const SPos& Pos_) : Resources(Resources_), Pos(Pos_)
	{
	}
	SBooty(TResources&& Resources_, SPos&& Pos_) : Resources(std::move(Resources_)), Pos(std::move(Pos_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Resources;
		Stream_ >> Pos;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Resources"] >> Resources;
		Pos << Value_["Pos"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Resources;
		Stream_ << Pos;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Resources"] = Resources;
		Value_["Pos"] = Pos;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Resources,X,Y";
	}
};
struct SBankInfo : public SProto
{
	system_clock::time_point DepositTime;
	TLevel BankLevel = 0;
	TIndex InterestIndex = 0;
	EResource ResourceType;
	TResource ResourceValue = 0;
	SBankInfo()
	{
	}
	SBankInfo(const system_clock::time_point& DepositTime_, const TLevel& BankLevel_, const TIndex& InterestIndex_, const EResource& ResourceType_, const TResource& ResourceValue_) : DepositTime(DepositTime_), BankLevel(BankLevel_), InterestIndex(InterestIndex_), ResourceType(ResourceType_), ResourceValue(ResourceValue_)
	{
	}
	SBankInfo(system_clock::time_point&& DepositTime_, TLevel&& BankLevel_, TIndex&& InterestIndex_, EResource&& ResourceType_, TResource&& ResourceValue_) : DepositTime(std::move(DepositTime_)), BankLevel(std::move(BankLevel_)), InterestIndex(std::move(InterestIndex_)), ResourceType(std::move(ResourceType_)), ResourceValue(std::move(ResourceValue_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> DepositTime;
		Stream_ >> BankLevel;
		Stream_ >> InterestIndex;
		Stream_ >> (__int32&)ResourceType;
		Stream_ >> ResourceValue;
	}
	void operator << (const Value& Value_) override
	{
		Value_["DepositTime"] >> DepositTime;
		Value_["BankLevel"] >> BankLevel;
		Value_["InterestIndex"] >> InterestIndex;
		Value_["ResourceType"] >> (__int32&)ResourceType;
		Value_["ResourceValue"] >> ResourceValue;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << DepositTime;
		Stream_ << BankLevel;
		Stream_ << InterestIndex;
		Stream_ << (__int32)ResourceType;
		Stream_ << ResourceValue;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["DepositTime"] = DepositTime;
		Value_["BankLevel"] = BankLevel;
		Value_["InterestIndex"] = InterestIndex;
		Value_["ResourceType"] = (__int32)ResourceType;
		Value_["ResourceValue"] = ResourceValue;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int64,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"DepositTime,BankLevel,InterestIndex,ResourceType,ResourceValue";
	}
};
struct SUserCore : public SUserBase
{
	wstring Nick;
	system_clock::time_point ClanCastleCoolEndTime;
	SBooty Booty;
	STimeBoost BBBoost;
	system_clock::time_point BatchBoostCoolEndTime;
	SBankInfo BankInfo;
	TIndex LastEnvObjectIndex = 0;
	TIndex EnvObjectRewardIndex = 0;
	SUserCore()
	{
	}
	SUserCore(const SUserBase& Super_, const wstring& Nick_, const system_clock::time_point& ClanCastleCoolEndTime_, const SBooty& Booty_, const STimeBoost& BBBoost_, const system_clock::time_point& BatchBoostCoolEndTime_, const SBankInfo& BankInfo_, const TIndex& LastEnvObjectIndex_, const TIndex& EnvObjectRewardIndex_) : SUserBase(Super_), Nick(Nick_), ClanCastleCoolEndTime(ClanCastleCoolEndTime_), Booty(Booty_), BBBoost(BBBoost_), BatchBoostCoolEndTime(BatchBoostCoolEndTime_), BankInfo(BankInfo_), LastEnvObjectIndex(LastEnvObjectIndex_), EnvObjectRewardIndex(EnvObjectRewardIndex_)
	{
	}
	SUserCore(SUserBase&& Super_, wstring&& Nick_, system_clock::time_point&& ClanCastleCoolEndTime_, SBooty&& Booty_, STimeBoost&& BBBoost_, system_clock::time_point&& BatchBoostCoolEndTime_, SBankInfo&& BankInfo_, TIndex&& LastEnvObjectIndex_, TIndex&& EnvObjectRewardIndex_) : SUserBase(std::move(Super_)), Nick(std::move(Nick_)), ClanCastleCoolEndTime(std::move(ClanCastleCoolEndTime_)), Booty(std::move(Booty_)), BBBoost(std::move(BBBoost_)), BatchBoostCoolEndTime(std::move(BatchBoostCoolEndTime_)), BankInfo(std::move(BankInfo_)), LastEnvObjectIndex(std::move(LastEnvObjectIndex_)), EnvObjectRewardIndex(std::move(EnvObjectRewardIndex_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Nick;
		Stream_ >> ClanCastleCoolEndTime;
		Stream_ >> Booty;
		Stream_ >> BBBoost;
		Stream_ >> BatchBoostCoolEndTime;
		Stream_ >> BankInfo;
		Stream_ >> LastEnvObjectIndex;
		Stream_ >> EnvObjectRewardIndex;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Nick"] >> Nick;
		Value_["ClanCastleCoolEndTime"] >> ClanCastleCoolEndTime;
		Booty << Value_["Booty"];
		BBBoost << Value_["BBBoost"];
		Value_["BatchBoostCoolEndTime"] >> BatchBoostCoolEndTime;
		BankInfo << Value_["BankInfo"];
		Value_["LastEnvObjectIndex"] >> LastEnvObjectIndex;
		Value_["EnvObjectRewardIndex"] >> EnvObjectRewardIndex;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Nick;
		Stream_ << ClanCastleCoolEndTime;
		Stream_ << Booty;
		Stream_ << BBBoost;
		Stream_ << BatchBoostCoolEndTime;
		Stream_ << BankInfo;
		Stream_ << LastEnvObjectIndex;
		Stream_ << EnvObjectRewardIndex;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Nick"] = Nick;
		Value_["ClanCastleCoolEndTime"] = ClanCastleCoolEndTime;
		Value_["Booty"] = Booty;
		Value_["BBBoost"] = BBBoost;
		Value_["BatchBoostCoolEndTime"] = BatchBoostCoolEndTime;
		Value_["BankInfo"] = BankInfo;
		Value_["LastEnvObjectIndex"] = LastEnvObjectIndex;
		Value_["EnvObjectRewardIndex"] = EnvObjectRewardIndex;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,int8,int32,int8,time_point,wstring,time_point,int32,int32,int32,int32,int32,int32,int32,time_point,time_point,double,time_point,time_point,int32,int64,int32,int32,int64,int64";
	}
	static wstring MemberName(void)
	{
		return L"Resource,LeaguePoint,LeagueCur,LeagueBest,AvatarActivatedSlotNo,Exp,Debug,LastEnvObjectGenTime,Nick,ClanCastleCoolEndTime,Resources,X,Y,BeginTime,EndTime,Speed,BatchBoostCoolEndTime,DepositTime,BankLevel,InterestIndex,ResourceType,ResourceValue,LastEnvObjectIndex,EnvObjectRewardIndex";
	}
};
struct SClanCore : public SProto
{
	TUID UID = 0;
	wstring Name;
	wstring Mark;
	SClanCore()
	{
	}
	SClanCore(const TUID& UID_, const wstring& Name_, const wstring& Mark_) : UID(UID_), Name(Name_), Mark(Mark_)
	{
	}
	SClanCore(TUID&& UID_, wstring&& Name_, wstring&& Mark_) : UID(std::move(UID_)), Name(std::move(Name_)), Mark(std::move(Mark_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
		Stream_ >> Name;
		Stream_ >> Mark;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
		Value_["Name"] >> Name;
		Value_["Mark"] >> Mark;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
		Stream_ << Name;
		Stream_ << Mark;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
		Value_["Name"] = Name;
		Value_["Mark"] = Mark;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Mark";
	}
};
struct SClanBase : public SClanCore
{
	TExp Exp = 0;
	SClanBase()
	{
	}
	SClanBase(const SClanCore& Super_, const TExp& Exp_) : SClanCore(Super_), Exp(Exp_)
	{
	}
	SClanBase(SClanCore&& Super_, TExp&& Exp_) : SClanCore(std::move(Super_)), Exp(std::move(Exp_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Exp;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Exp"] >> Exp;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Exp;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Exp"] = Exp;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,wstring,int32";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Mark,Exp";
	}
};
struct SBattleBonus : public SProto
{
	__int32 Count = 0;
	__int32 Point = 0;
	system_clock::time_point LastCheckTime;
	SBattleBonus()
	{
	}
	SBattleBonus(const __int32& Count_, const __int32& Point_, const system_clock::time_point& LastCheckTime_) : Count(Count_), Point(Point_), LastCheckTime(LastCheckTime_)
	{
	}
	SBattleBonus(__int32&& Count_, __int32&& Point_, system_clock::time_point&& LastCheckTime_) : Count(std::move(Count_)), Point(std::move(Point_)), LastCheckTime(std::move(LastCheckTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Count;
		Stream_ >> Point;
		Stream_ >> LastCheckTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Count"] >> Count;
		Value_["Point"] >> Point;
		Value_["LastCheckTime"] >> LastCheckTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Count;
		Stream_ << Point;
		Stream_ << LastCheckTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Count"] = Count;
		Value_["Point"] = Point;
		Value_["LastCheckTime"] = LastCheckTime;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Count,Point,LastCheckTime";
	}
};
struct SUserNet : public SUserCore
{
	SClanBase ClanInfo;
	system_clock::time_point GuardEndTime;
	system_clock::time_point InsertedTimePoint;
	SBattleBonus BattleBonus;
	SUserNet()
	{
	}
	SUserNet(const SUserCore& Super_, const SClanBase& ClanInfo_, const system_clock::time_point& GuardEndTime_, const system_clock::time_point& InsertedTimePoint_, const SBattleBonus& BattleBonus_) : SUserCore(Super_), ClanInfo(ClanInfo_), GuardEndTime(GuardEndTime_), InsertedTimePoint(InsertedTimePoint_), BattleBonus(BattleBonus_)
	{
	}
	SUserNet(SUserCore&& Super_, SClanBase&& ClanInfo_, system_clock::time_point&& GuardEndTime_, system_clock::time_point&& InsertedTimePoint_, SBattleBonus&& BattleBonus_) : SUserCore(std::move(Super_)), ClanInfo(std::move(ClanInfo_)), GuardEndTime(std::move(GuardEndTime_)), InsertedTimePoint(std::move(InsertedTimePoint_)), BattleBonus(std::move(BattleBonus_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> ClanInfo;
		Stream_ >> GuardEndTime;
		Stream_ >> InsertedTimePoint;
		Stream_ >> BattleBonus;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		ClanInfo << Value_["ClanInfo"];
		Value_["GuardEndTime"] >> GuardEndTime;
		Value_["InsertedTimePoint"] >> InsertedTimePoint;
		BattleBonus << Value_["BattleBonus"];
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << ClanInfo;
		Stream_ << GuardEndTime;
		Stream_ << InsertedTimePoint;
		Stream_ << BattleBonus;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["ClanInfo"] = ClanInfo;
		Value_["GuardEndTime"] = GuardEndTime;
		Value_["InsertedTimePoint"] = InsertedTimePoint;
		Value_["BattleBonus"] = BattleBonus;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,int8,int32,int8,time_point,wstring,time_point,int32,int32,int32,int32,int32,int32,int32,time_point,time_point,double,time_point,time_point,int32,int64,int32,int32,int64,int64,int64,wstring,wstring,int32,time_point,time_point,int32,int32,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Resource,LeaguePoint,LeagueCur,LeagueBest,AvatarActivatedSlotNo,Exp,Debug,LastEnvObjectGenTime,Nick,ClanCastleCoolEndTime,Resources,X,Y,BeginTime,EndTime,Speed,BatchBoostCoolEndTime,DepositTime,BankLevel,InterestIndex,ResourceType,ResourceValue,LastEnvObjectIndex,EnvObjectRewardIndex,UID,Name,Mark,Exp,GuardEndTime,InsertedTimePoint,Count,Point,LastCheckTime";
	}
};
struct SBuildingRotate : public SProto
{
	EBuildingRotate Rotate;
	EBuildingRotateHead RotateHead;
	SBuildingRotate()
	{
	}
	SBuildingRotate(const EBuildingRotate& Rotate_, const EBuildingRotateHead& RotateHead_) : Rotate(Rotate_), RotateHead(RotateHead_)
	{
	}
	SBuildingRotate(EBuildingRotate&& Rotate_, EBuildingRotateHead&& RotateHead_) : Rotate(std::move(Rotate_)), RotateHead(std::move(RotateHead_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int8&)Rotate;
		Stream_ >> (__int8&)RotateHead;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Rotate"] >> (__int8&)Rotate;
		Value_["RotateHead"] >> (__int8&)RotateHead;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int8)Rotate;
		Stream_ << (__int8)RotateHead;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Rotate"] = (__int8)Rotate;
		Value_["RotateHead"] = (__int8)RotateHead;
	}
	static wstring StdName(void)
	{
		return L"int8,int8";
	}
	static wstring MemberName(void)
	{
		return L"Rotate,RotateHead";
	}
};
struct SBuildingCore : public SProto
{
	TIndex Index = 0;
	TID GroupID = 0;
	TLevel Level = 0;
	SPos Pos;
	__int8 Mode = 0;
	TID BulletGroupID = 0;
	__int32 BulletLeft = 0;
	SBuildingRotate Rotate;
	system_clock::time_point BaseTime;
	SBuildingCore()
	{
	}
	SBuildingCore(const TIndex& Index_, const TID& GroupID_, const TLevel& Level_, const SPos& Pos_, const __int8& Mode_, const TID& BulletGroupID_, const __int32& BulletLeft_, const SBuildingRotate& Rotate_, const system_clock::time_point& BaseTime_) : Index(Index_), GroupID(GroupID_), Level(Level_), Pos(Pos_), Mode(Mode_), BulletGroupID(BulletGroupID_), BulletLeft(BulletLeft_), Rotate(Rotate_), BaseTime(BaseTime_)
	{
	}
	SBuildingCore(TIndex&& Index_, TID&& GroupID_, TLevel&& Level_, SPos&& Pos_, __int8&& Mode_, TID&& BulletGroupID_, __int32&& BulletLeft_, SBuildingRotate&& Rotate_, system_clock::time_point&& BaseTime_) : Index(std::move(Index_)), GroupID(std::move(GroupID_)), Level(std::move(Level_)), Pos(std::move(Pos_)), Mode(std::move(Mode_)), BulletGroupID(std::move(BulletGroupID_)), BulletLeft(std::move(BulletLeft_)), Rotate(std::move(Rotate_)), BaseTime(std::move(BaseTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> GroupID;
		Stream_ >> Level;
		Stream_ >> Pos;
		Stream_ >> Mode;
		Stream_ >> BulletGroupID;
		Stream_ >> BulletLeft;
		Stream_ >> Rotate;
		Stream_ >> BaseTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["GroupID"] >> GroupID;
		Value_["Level"] >> Level;
		Pos << Value_["Pos"];
		Value_["Mode"] >> Mode;
		Value_["BulletGroupID"] >> BulletGroupID;
		Value_["BulletLeft"] >> BulletLeft;
		Rotate << Value_["Rotate"];
		Value_["BaseTime"] >> BaseTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << GroupID;
		Stream_ << Level;
		Stream_ << Pos;
		Stream_ << Mode;
		Stream_ << BulletGroupID;
		Stream_ << BulletLeft;
		Stream_ << Rotate;
		Stream_ << BaseTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["GroupID"] = GroupID;
		Value_["Level"] = Level;
		Value_["Pos"] = Pos;
		Value_["Mode"] = Mode;
		Value_["BulletGroupID"] = BulletGroupID;
		Value_["BulletLeft"] = BulletLeft;
		Value_["Rotate"] = Rotate;
		Value_["BaseTime"] = BaseTime;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,int32,int32,int32,int8,int32,int32,int8,int8,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Index,GroupID,Level,X,Y,Mode,BulletGroupID,BulletLeft,Rotate,RotateHead,BaseTime";
	}
};
struct SBuildingBase : public SBuildingCore
{
	bool IsCompleted = false;
	system_clock::time_point UpgradeEndTime;
	__int64 DurationTicks = 0;
	STimeBoost Boost;
	SBuildingBase()
	{
	}
	SBuildingBase(const SBuildingCore& Super_, const bool& IsCompleted_, const system_clock::time_point& UpgradeEndTime_, const __int64& DurationTicks_, const STimeBoost& Boost_) : SBuildingCore(Super_), IsCompleted(IsCompleted_), UpgradeEndTime(UpgradeEndTime_), DurationTicks(DurationTicks_), Boost(Boost_)
	{
	}
	SBuildingBase(SBuildingCore&& Super_, bool&& IsCompleted_, system_clock::time_point&& UpgradeEndTime_, __int64&& DurationTicks_, STimeBoost&& Boost_) : SBuildingCore(std::move(Super_)), IsCompleted(std::move(IsCompleted_)), UpgradeEndTime(std::move(UpgradeEndTime_)), DurationTicks(std::move(DurationTicks_)), Boost(std::move(Boost_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> IsCompleted;
		Stream_ >> UpgradeEndTime;
		Stream_ >> DurationTicks;
		Stream_ >> Boost;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["IsCompleted"] >> IsCompleted;
		Value_["UpgradeEndTime"] >> UpgradeEndTime;
		Value_["DurationTicks"] >> DurationTicks;
		Boost << Value_["Boost"];
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << IsCompleted;
		Stream_ << UpgradeEndTime;
		Stream_ << DurationTicks;
		Stream_ << Boost;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["IsCompleted"] = IsCompleted;
		Value_["UpgradeEndTime"] = UpgradeEndTime;
		Value_["DurationTicks"] = DurationTicks;
		Value_["Boost"] = Boost;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,int32,int32,int32,int8,int32,int32,int8,int8,time_point,bool,time_point,int64,time_point,time_point,double";
	}
	static wstring MemberName(void)
	{
		return L"Index,GroupID,Level,X,Y,Mode,BulletGroupID,BulletLeft,Rotate,RotateHead,BaseTime,IsCompleted,UpgradeEndTime,DurationTicks,BeginTime,EndTime,Speed";
	}
};
struct SUnitUpgradeInfo : public SProto
{
	TLevel Level = 0;
	bool IsCompleted = false;
	system_clock::time_point CompleteTime;
	SUnitUpgradeInfo()
	{
	}
	SUnitUpgradeInfo(const TLevel& Level_, const bool& IsCompleted_, const system_clock::time_point& CompleteTime_) : Level(Level_), IsCompleted(IsCompleted_), CompleteTime(CompleteTime_)
	{
	}
	SUnitUpgradeInfo(TLevel&& Level_, bool&& IsCompleted_, system_clock::time_point&& CompleteTime_) : Level(std::move(Level_)), IsCompleted(std::move(IsCompleted_)), CompleteTime(std::move(CompleteTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Level;
		Stream_ >> IsCompleted;
		Stream_ >> CompleteTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Level"] >> Level;
		Value_["IsCompleted"] >> IsCompleted;
		Value_["CompleteTime"] >> CompleteTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Level;
		Stream_ << IsCompleted;
		Stream_ << CompleteTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Level"] = Level;
		Value_["IsCompleted"] = IsCompleted;
		Value_["CompleteTime"] = CompleteTime;
	}
	static wstring StdName(void)
	{
		return L"int32,bool,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Level,IsCompleted,CompleteTime";
	}
};
using TUpgrades = map<TID,SUnitUpgradeInfo>;
struct SAvatarDB : public SProto
{
	TRank Rank = 0;
	TEnchant Enchant = 0;
	bool IsCompleted = false;
	system_clock::time_point CompleteTime;
	SAvatarDB()
	{
	}
	SAvatarDB(const TRank& Rank_, const TEnchant& Enchant_, const bool& IsCompleted_, const system_clock::time_point& CompleteTime_) : Rank(Rank_), Enchant(Enchant_), IsCompleted(IsCompleted_), CompleteTime(CompleteTime_)
	{
	}
	SAvatarDB(TRank&& Rank_, TEnchant&& Enchant_, bool&& IsCompleted_, system_clock::time_point&& CompleteTime_) : Rank(std::move(Rank_)), Enchant(std::move(Enchant_)), IsCompleted(std::move(IsCompleted_)), CompleteTime(std::move(CompleteTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Rank;
		Stream_ >> Enchant;
		Stream_ >> IsCompleted;
		Stream_ >> CompleteTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Rank"] >> Rank;
		Value_["Enchant"] >> Enchant;
		Value_["IsCompleted"] >> IsCompleted;
		Value_["CompleteTime"] >> CompleteTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Rank;
		Stream_ << Enchant;
		Stream_ << IsCompleted;
		Stream_ << CompleteTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Rank"] = Rank;
		Value_["Enchant"] = Enchant;
		Value_["IsCompleted"] = IsCompleted;
		Value_["CompleteTime"] = CompleteTime;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,bool,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Rank,Enchant,IsCompleted,CompleteTime";
	}
};
struct SAvatarPart : public SProto
{
	TID GroupID = 0;
	TID ColorID = 0;
	SAvatarPart()
	{
	}
	SAvatarPart(const TID& GroupID_, const TID& ColorID_) : GroupID(GroupID_), ColorID(ColorID_)
	{
	}
	SAvatarPart(TID&& GroupID_, TID&& ColorID_) : GroupID(std::move(GroupID_)), ColorID(std::move(ColorID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> GroupID;
		Stream_ >> ColorID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["GroupID"] >> GroupID;
		Value_["ColorID"] >> ColorID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << GroupID;
		Stream_ << ColorID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["GroupID"] = GroupID;
		Value_["ColorID"] = ColorID;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"GroupID,ColorID";
	}
};
using TAvatarParts = array<SAvatarPart,4>;
struct SAvatarBase : public SProto
{
	TAvatarParts Parts{};
	SAvatarBase()
	{
	}
	SAvatarBase(const TAvatarParts& Parts_) : Parts(Parts_)
	{
	}
	SAvatarBase(TAvatarParts&& Parts_) : Parts(std::move(Parts_))
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
struct SAvatarSlot : public SAvatarBase
{
	bool IsCoolEnded = false;
	system_clock::time_point CoolEndTime;
	SAvatarSlot()
	{
	}
	SAvatarSlot(const SAvatarBase& Super_, const bool& IsCoolEnded_, const system_clock::time_point& CoolEndTime_) : SAvatarBase(Super_), IsCoolEnded(IsCoolEnded_), CoolEndTime(CoolEndTime_)
	{
	}
	SAvatarSlot(SAvatarBase&& Super_, bool&& IsCoolEnded_, system_clock::time_point&& CoolEndTime_) : SAvatarBase(std::move(Super_)), IsCoolEnded(std::move(IsCoolEnded_)), CoolEndTime(std::move(CoolEndTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> IsCoolEnded;
		Stream_ >> CoolEndTime;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["IsCoolEnded"] >> IsCoolEnded;
		Value_["CoolEndTime"] >> CoolEndTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << IsCoolEnded;
		Stream_ << CoolEndTime;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["IsCoolEnded"] = IsCoolEnded;
		Value_["CoolEndTime"] = CoolEndTime;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,bool,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Parts,IsCoolEnded,CoolEndTime";
	}
};
struct SAvatarDefence : public SAvatarBase
{
	bool GuardEnabled = false;
	bool Used = false;
	SAvatarDefence()
	{
	}
	SAvatarDefence(const SAvatarBase& Super_, const bool& GuardEnabled_, const bool& Used_) : SAvatarBase(Super_), GuardEnabled(GuardEnabled_), Used(Used_)
	{
	}
	SAvatarDefence(SAvatarBase&& Super_, bool&& GuardEnabled_, bool&& Used_) : SAvatarBase(std::move(Super_)), GuardEnabled(std::move(GuardEnabled_)), Used(std::move(Used_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> GuardEnabled;
		Stream_ >> Used;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["GuardEnabled"] >> GuardEnabled;
		Value_["Used"] >> Used;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << GuardEnabled;
		Stream_ << Used;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["GuardEnabled"] = GuardEnabled;
		Value_["Used"] = Used;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,bool,bool";
	}
	static wstring MemberName(void)
	{
		return L"Parts,GuardEnabled,Used";
	}
};
using TAvatarSlots = vector<SAvatarSlot>;
using TAvatarDefences = list<SAvatarDefence>;
using TAvatarUpgrades = map<TID,SAvatarDB>;
struct SSingleStage : public SProto
{
	TLevel Level = 0;
	bool Cleared = false;
	system_clock::time_point CoolEndTime;
	SSingleStage()
	{
	}
	SSingleStage(const TLevel& Level_, const bool& Cleared_, const system_clock::time_point& CoolEndTime_) : Level(Level_), Cleared(Cleared_), CoolEndTime(CoolEndTime_)
	{
	}
	SSingleStage(TLevel&& Level_, bool&& Cleared_, system_clock::time_point&& CoolEndTime_) : Level(std::move(Level_)), Cleared(std::move(Cleared_)), CoolEndTime(std::move(CoolEndTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Level;
		Stream_ >> Cleared;
		Stream_ >> CoolEndTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Level"] >> Level;
		Value_["Cleared"] >> Cleared;
		Value_["CoolEndTime"] >> CoolEndTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Level;
		Stream_ << Cleared;
		Stream_ << CoolEndTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Level"] = Level;
		Value_["Cleared"] = Cleared;
		Value_["CoolEndTime"] = CoolEndTime;
	}
	static wstring StdName(void)
	{
		return L"int32,bool,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Level,Cleared,CoolEndTime";
	}
};
using TSingleGroup = map<TID,SSingleStage>;
struct SSingleGroup : public SProto
{
	TSingleGroup Group;
	SSingleGroup()
	{
	}
	SSingleGroup(const TSingleGroup& Group_) : Group(Group_)
	{
	}
	SSingleGroup(TSingleGroup&& Group_) : Group(std::move(Group_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Group;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Group"] >> Group;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Group;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Group"] = Group;
	}
	static wstring StdName(void)
	{
		return L"{int32,int32,bool,time_point}";
	}
	static wstring MemberName(void)
	{
		return L"Group";
	}
};
using TSingleArea = map<__int32,SSingleGroup>;
struct SSingleArea : public SProto
{
	TSingleArea Area;
	SSingleArea()
	{
	}
	SSingleArea(const TSingleArea& Area_) : Area(Area_)
	{
	}
	SSingleArea(TSingleArea&& Area_) : Area(std::move(Area_))
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
		return L"{int32,{int32,int32,bool,time_point}}";
	}
	static wstring MemberName(void)
	{
		return L"Area";
	}
};
using TSingleWorld = map<__int32,SSingleArea>;
enum class EClanLoginType
{
	Create,
	Join,
	Login,
	Max,
	Null,
};
enum class EClanType : __int8
{
	Public,
	Invitation,
	Private,
	Max,
	Null,
};
enum class EClanMemberGrade : __int8
{
	Leader,
	CoLeader,
	Elder,
	Member,
	Max,
	Null,
};
struct SClanCreateOkNetSc : public SProto
{
	TResources Cost{};
	SClanCreateOkNetSc()
	{
	}
	SClanCreateOkNetSc(const TResources& Cost_) : Cost(Cost_)
	{
	}
	SClanCreateOkNetSc(TResources&& Cost_) : Cost(std::move(Cost_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Cost;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Cost"] >> Cost;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Cost;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Cost"] = Cost;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Cost";
	}
};
struct SClanUnsetNetSc : public SProto
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
struct SClanCreateCore : public SProto
{
	ERegion Region;
	TLeaguePoint MinLeaguePoint = 0;
	EClanType Type;
	wstring Desc;
	SClanCreateCore()
	{
	}
	SClanCreateCore(const ERegion& Region_, const TLeaguePoint& MinLeaguePoint_, const EClanType& Type_, const wstring& Desc_) : Region(Region_), MinLeaguePoint(MinLeaguePoint_), Type(Type_), Desc(Desc_)
	{
	}
	SClanCreateCore(ERegion&& Region_, TLeaguePoint&& MinLeaguePoint_, EClanType&& Type_, wstring&& Desc_) : Region(std::move(Region_)), MinLeaguePoint(std::move(MinLeaguePoint_)), Type(std::move(Type_)), Desc(std::move(Desc_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int8&)Region;
		Stream_ >> MinLeaguePoint;
		Stream_ >> (__int8&)Type;
		Stream_ >> Desc;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Region"] >> (__int8&)Region;
		Value_["MinLeaguePoint"] >> MinLeaguePoint;
		Value_["Type"] >> (__int8&)Type;
		Value_["Desc"] >> Desc;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int8)Region;
		Stream_ << MinLeaguePoint;
		Stream_ << (__int8)Type;
		Stream_ << Desc;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Region"] = (__int8)Region;
		Value_["MinLeaguePoint"] = MinLeaguePoint;
		Value_["Type"] = (__int8)Type;
		Value_["Desc"] = Desc;
	}
	static wstring StdName(void)
	{
		return L"int8,int32,int8,wstring";
	}
	static wstring MemberName(void)
	{
		return L"Region,MinLeaguePoint,Type,Desc";
	}
};
struct SClanCreateInfo : public SClanCore
{
	SClanCreateCore CreateCore;
	SClanCreateInfo()
	{
	}
	SClanCreateInfo(const SClanCore& Super_, const SClanCreateCore& CreateCore_) : SClanCore(Super_), CreateCore(CreateCore_)
	{
	}
	SClanCreateInfo(SClanCore&& Super_, SClanCreateCore&& CreateCore_) : SClanCore(std::move(Super_)), CreateCore(std::move(CreateCore_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> CreateCore;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		CreateCore << Value_["CreateCore"];
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << CreateCore;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["CreateCore"] = CreateCore;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,wstring,int8,int32,int8,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Mark,Region,MinLeaguePoint,Type,Desc";
	}
};
struct SClanCreate : public SProto
{
	TUID UserUID = 0;
	TAccountType AccountType = 0;
	wstring UserID;
	wstring Name;
	wstring Mark;
	SClanCreateCore CreateCore;
	SClanCreate()
	{
	}
	SClanCreate(const TUID& UserUID_, const TAccountType& AccountType_, const wstring& UserID_, const wstring& Name_, const wstring& Mark_, const SClanCreateCore& CreateCore_) : UserUID(UserUID_), AccountType(AccountType_), UserID(UserID_), Name(Name_), Mark(Mark_), CreateCore(CreateCore_)
	{
	}
	SClanCreate(TUID&& UserUID_, TAccountType&& AccountType_, wstring&& UserID_, wstring&& Name_, wstring&& Mark_, SClanCreateCore&& CreateCore_) : UserUID(std::move(UserUID_)), AccountType(std::move(AccountType_)), UserID(std::move(UserID_)), Name(std::move(Name_)), Mark(std::move(Mark_)), CreateCore(std::move(CreateCore_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UserUID;
		Stream_ >> AccountType;
		Stream_ >> UserID;
		Stream_ >> Name;
		Stream_ >> Mark;
		Stream_ >> CreateCore;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UserUID"] >> UserUID;
		Value_["AccountType"] >> AccountType;
		Value_["UserID"] >> UserID;
		Value_["Name"] >> Name;
		Value_["Mark"] >> Mark;
		CreateCore << Value_["CreateCore"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UserUID;
		Stream_ << AccountType;
		Stream_ << UserID;
		Stream_ << Name;
		Stream_ << Mark;
		Stream_ << CreateCore;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UserUID"] = UserUID;
		Value_["AccountType"] = AccountType;
		Value_["UserID"] = UserID;
		Value_["Name"] = Name;
		Value_["Mark"] = Mark;
		Value_["CreateCore"] = CreateCore;
	}
	static wstring StdName(void)
	{
		return L"int64,uint8,wstring,wstring,wstring,int8,int32,int8,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UserUID,AccountType,UserID,Name,Mark,Region,MinLeaguePoint,Type,Desc";
	}
};
struct SClanJoin : public SProto
{
	TUID UserUID = 0;
	TAccountType AccountType = 0;
	wstring UserID;
	__int32 PassCode = 0;
	wstring Message;
	SClanJoin()
	{
	}
	SClanJoin(const TUID& UserUID_, const TAccountType& AccountType_, const wstring& UserID_, const __int32& PassCode_, const wstring& Message_) : UserUID(UserUID_), AccountType(AccountType_), UserID(UserID_), PassCode(PassCode_), Message(Message_)
	{
	}
	SClanJoin(TUID&& UserUID_, TAccountType&& AccountType_, wstring&& UserID_, __int32&& PassCode_, wstring&& Message_) : UserUID(std::move(UserUID_)), AccountType(std::move(AccountType_)), UserID(std::move(UserID_)), PassCode(std::move(PassCode_)), Message(std::move(Message_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UserUID;
		Stream_ >> AccountType;
		Stream_ >> UserID;
		Stream_ >> PassCode;
		Stream_ >> Message;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UserUID"] >> UserUID;
		Value_["AccountType"] >> AccountType;
		Value_["UserID"] >> UserID;
		Value_["PassCode"] >> PassCode;
		Value_["Message"] >> Message;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UserUID;
		Stream_ << AccountType;
		Stream_ << UserID;
		Stream_ << PassCode;
		Stream_ << Message;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UserUID"] = UserUID;
		Value_["AccountType"] = AccountType;
		Value_["UserID"] = UserID;
		Value_["PassCode"] = PassCode;
		Value_["Message"] = Message;
	}
	static wstring StdName(void)
	{
		return L"int64,uint8,wstring,int32,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UserUID,AccountType,UserID,PassCode,Message";
	}
};
struct SClanLogin : public SProto
{
	TUID UserUID = 0;
	TAccountType AccountType = 0;
	wstring UserID;
	SClanLogin()
	{
	}
	SClanLogin(const TUID& UserUID_, const TAccountType& AccountType_, const wstring& UserID_) : UserUID(UserUID_), AccountType(AccountType_), UserID(UserID_)
	{
	}
	SClanLogin(TUID&& UserUID_, TAccountType&& AccountType_, wstring&& UserID_) : UserUID(std::move(UserUID_)), AccountType(std::move(AccountType_)), UserID(std::move(UserID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UserUID;
		Stream_ >> AccountType;
		Stream_ >> UserID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UserUID"] >> UserUID;
		Value_["AccountType"] >> AccountType;
		Value_["UserID"] >> UserID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UserUID;
		Stream_ << AccountType;
		Stream_ << UserID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UserUID"] = UserUID;
		Value_["AccountType"] = AccountType;
		Value_["UserID"] = UserID;
	}
	static wstring StdName(void)
	{
		return L"int64,uint8,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UserUID,AccountType,UserID";
	}
};
struct SClanMember : public SProto
{
	TUID UID = 0;
	TExp Exp = 0;
	TAccountType AccountType = 0;
	wstring ID;
	wstring Nick;
	EClanMemberGrade Grade;
	TLeaguePoint LeaguePoint = 0;
	__int32 SupportCnt = 0;
	__int32 ReceiveCnt = 0;
	TRank OldRank = 0;
	TRank CurRank = 0;
	SClanMember()
	{
	}
	SClanMember(const TUID& UID_, const TExp& Exp_, const TAccountType& AccountType_, const wstring& ID_, const wstring& Nick_, const EClanMemberGrade& Grade_, const TLeaguePoint& LeaguePoint_, const __int32& SupportCnt_, const __int32& ReceiveCnt_, const TRank& OldRank_, const TRank& CurRank_) : UID(UID_), Exp(Exp_), AccountType(AccountType_), ID(ID_), Nick(Nick_), Grade(Grade_), LeaguePoint(LeaguePoint_), SupportCnt(SupportCnt_), ReceiveCnt(ReceiveCnt_), OldRank(OldRank_), CurRank(CurRank_)
	{
	}
	SClanMember(TUID&& UID_, TExp&& Exp_, TAccountType&& AccountType_, wstring&& ID_, wstring&& Nick_, EClanMemberGrade&& Grade_, TLeaguePoint&& LeaguePoint_, __int32&& SupportCnt_, __int32&& ReceiveCnt_, TRank&& OldRank_, TRank&& CurRank_) : UID(std::move(UID_)), Exp(std::move(Exp_)), AccountType(std::move(AccountType_)), ID(std::move(ID_)), Nick(std::move(Nick_)), Grade(std::move(Grade_)), LeaguePoint(std::move(LeaguePoint_)), SupportCnt(std::move(SupportCnt_)), ReceiveCnt(std::move(ReceiveCnt_)), OldRank(std::move(OldRank_)), CurRank(std::move(CurRank_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
		Stream_ >> Exp;
		Stream_ >> AccountType;
		Stream_ >> ID;
		Stream_ >> Nick;
		Stream_ >> (__int8&)Grade;
		Stream_ >> LeaguePoint;
		Stream_ >> SupportCnt;
		Stream_ >> ReceiveCnt;
		Stream_ >> OldRank;
		Stream_ >> CurRank;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
		Value_["Exp"] >> Exp;
		Value_["AccountType"] >> AccountType;
		Value_["ID"] >> ID;
		Value_["Nick"] >> Nick;
		Value_["Grade"] >> (__int8&)Grade;
		Value_["LeaguePoint"] >> LeaguePoint;
		Value_["SupportCnt"] >> SupportCnt;
		Value_["ReceiveCnt"] >> ReceiveCnt;
		Value_["OldRank"] >> OldRank;
		Value_["CurRank"] >> CurRank;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
		Stream_ << Exp;
		Stream_ << AccountType;
		Stream_ << ID;
		Stream_ << Nick;
		Stream_ << (__int8)Grade;
		Stream_ << LeaguePoint;
		Stream_ << SupportCnt;
		Stream_ << ReceiveCnt;
		Stream_ << OldRank;
		Stream_ << CurRank;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
		Value_["Exp"] = Exp;
		Value_["AccountType"] = AccountType;
		Value_["ID"] = ID;
		Value_["Nick"] = Nick;
		Value_["Grade"] = (__int8)Grade;
		Value_["LeaguePoint"] = LeaguePoint;
		Value_["SupportCnt"] = SupportCnt;
		Value_["ReceiveCnt"] = ReceiveCnt;
		Value_["OldRank"] = OldRank;
		Value_["CurRank"] = CurRank;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,uint8,wstring,wstring,int8,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"UID,Exp,AccountType,ID,Nick,Grade,LeaguePoint,SupportCnt,ReceiveCnt,OldRank,CurRank";
	}
};
struct SClanInfoSearch : public SClanBase
{
	TLeaguePoint LeaguePoint = 0;
	__int32 MemberCnt = 0;
	EClanType Type;
	SClanInfoSearch()
	{
	}
	SClanInfoSearch(const SClanBase& Super_, const TLeaguePoint& LeaguePoint_, const __int32& MemberCnt_, const EClanType& Type_) : SClanBase(Super_), LeaguePoint(LeaguePoint_), MemberCnt(MemberCnt_), Type(Type_)
	{
	}
	SClanInfoSearch(SClanBase&& Super_, TLeaguePoint&& LeaguePoint_, __int32&& MemberCnt_, EClanType&& Type_) : SClanBase(std::move(Super_)), LeaguePoint(std::move(LeaguePoint_)), MemberCnt(std::move(MemberCnt_)), Type(std::move(Type_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> LeaguePoint;
		Stream_ >> MemberCnt;
		Stream_ >> (__int8&)Type;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["LeaguePoint"] >> LeaguePoint;
		Value_["MemberCnt"] >> MemberCnt;
		Value_["Type"] >> (__int8&)Type;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << LeaguePoint;
		Stream_ << MemberCnt;
		Stream_ << (__int8)Type;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["LeaguePoint"] = LeaguePoint;
		Value_["MemberCnt"] = MemberCnt;
		Value_["Type"] = (__int8)Type;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,wstring,int32,int32,int32,int8";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Mark,Exp,LeaguePoint,MemberCnt,Type";
	}
};
struct SClanInfoDetail : public SClanInfoSearch
{
	ERegion Region;
	TLeaguePoint MinLeaguePoint = 0;
	wstring Desc;
	SClanInfoDetail()
	{
	}
	SClanInfoDetail(const SClanInfoSearch& Super_, const ERegion& Region_, const TLeaguePoint& MinLeaguePoint_, const wstring& Desc_) : SClanInfoSearch(Super_), Region(Region_), MinLeaguePoint(MinLeaguePoint_), Desc(Desc_)
	{
	}
	SClanInfoDetail(SClanInfoSearch&& Super_, ERegion&& Region_, TLeaguePoint&& MinLeaguePoint_, wstring&& Desc_) : SClanInfoSearch(std::move(Super_)), Region(std::move(Region_)), MinLeaguePoint(std::move(MinLeaguePoint_)), Desc(std::move(Desc_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> (__int8&)Region;
		Stream_ >> MinLeaguePoint;
		Stream_ >> Desc;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Region"] >> (__int8&)Region;
		Value_["MinLeaguePoint"] >> MinLeaguePoint;
		Value_["Desc"] >> Desc;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << (__int8)Region;
		Stream_ << MinLeaguePoint;
		Stream_ << Desc;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Region"] = (__int8)Region;
		Value_["MinLeaguePoint"] = MinLeaguePoint;
		Value_["Desc"] = Desc;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,wstring,int32,int32,int32,int8,int8,int32,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Mark,Exp,LeaguePoint,MemberCnt,Type,Region,MinLeaguePoint,Desc";
	}
};
struct SClanInfoNetSc : public SClanInfoDetail
{
	list<SClanMember> Members;
	SClanInfoNetSc()
	{
	}
	SClanInfoNetSc(const SClanInfoDetail& Super_, const list<SClanMember>& Members_) : SClanInfoDetail(Super_), Members(Members_)
	{
	}
	SClanInfoNetSc(SClanInfoDetail&& Super_, list<SClanMember>&& Members_) : SClanInfoDetail(std::move(Super_)), Members(std::move(Members_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Members;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Members"] >> Members;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Members;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Members"] = Members;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,wstring,int32,int32,int32,int8,int8,int32,wstring,{int64,int32,uint8,wstring,wstring,int8,int32,int32,int32,int32,int32}";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Mark,Exp,LeaguePoint,MemberCnt,Type,Region,MinLeaguePoint,Desc,Members";
	}
};
struct SEnvObjectDB : public SProto
{
	TIndex Index = 0;
	TID ObjectID = 0;
	SPos Pos;
	system_clock::time_point EndTime;
	SEnvObjectDB()
	{
	}
	SEnvObjectDB(const TIndex& Index_, const TID& ObjectID_, const SPos& Pos_, const system_clock::time_point& EndTime_) : Index(Index_), ObjectID(ObjectID_), Pos(Pos_), EndTime(EndTime_)
	{
	}
	SEnvObjectDB(TIndex&& Index_, TID&& ObjectID_, SPos&& Pos_, system_clock::time_point&& EndTime_) : Index(std::move(Index_)), ObjectID(std::move(ObjectID_)), Pos(std::move(Pos_)), EndTime(std::move(EndTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> ObjectID;
		Stream_ >> Pos;
		Stream_ >> EndTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["ObjectID"] >> ObjectID;
		Pos << Value_["Pos"];
		Value_["EndTime"] >> EndTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << ObjectID;
		Stream_ << Pos;
		Stream_ << EndTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["ObjectID"] = ObjectID;
		Value_["Pos"] = Pos;
		Value_["EndTime"] = EndTime;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,int32,int32,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Index,ObjectID,X,Y,EndTime";
	}
};
using TEnvObjectDBs = list<SEnvObjectDB>;
struct SBattleUserInfo : public SProto
{
	TUID UID = 0;
	wstring Nick;
	TExp Exp = 0;
	TLeaguePoint LeaguePoint = 0;
	SClanCore Clan;
	SBattleUserInfo()
	{
	}
	SBattleUserInfo(const TUID& UID_, const wstring& Nick_, const TExp& Exp_, const TLeaguePoint& LeaguePoint_, const SClanCore& Clan_) : UID(UID_), Nick(Nick_), Exp(Exp_), LeaguePoint(LeaguePoint_), Clan(Clan_)
	{
	}
	SBattleUserInfo(TUID&& UID_, wstring&& Nick_, TExp&& Exp_, TLeaguePoint&& LeaguePoint_, SClanCore&& Clan_) : UID(std::move(UID_)), Nick(std::move(Nick_)), Exp(std::move(Exp_)), LeaguePoint(std::move(LeaguePoint_)), Clan(std::move(Clan_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
		Stream_ >> Nick;
		Stream_ >> Exp;
		Stream_ >> LeaguePoint;
		Stream_ >> Clan;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
		Value_["Nick"] >> Nick;
		Value_["Exp"] >> Exp;
		Value_["LeaguePoint"] >> LeaguePoint;
		Clan << Value_["Clan"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
		Stream_ << Nick;
		Stream_ << Exp;
		Stream_ << LeaguePoint;
		Stream_ << Clan;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
		Value_["Nick"] = Nick;
		Value_["Exp"] = Exp;
		Value_["LeaguePoint"] = LeaguePoint;
		Value_["Clan"] = Clan;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int32,int64,wstring,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,Exp,LeaguePoint,UID,Name,Mark";
	}
};
struct SReplayCore : public SProto
{
	TIndex Index = 0;
	SBattleUserInfo Attacker;
	SBattleUserInfo Defender;
	SLeaguePointGot AttackerLeaguePointGot;
	SLeaguePointGot DefenderLeaguePointGot;
	__int32 Percentage = 0;
	SReplayCore()
	{
	}
	SReplayCore(const TIndex& Index_, const SBattleUserInfo& Attacker_, const SBattleUserInfo& Defender_, const SLeaguePointGot& AttackerLeaguePointGot_, const SLeaguePointGot& DefenderLeaguePointGot_, const __int32& Percentage_) : Index(Index_), Attacker(Attacker_), Defender(Defender_), AttackerLeaguePointGot(AttackerLeaguePointGot_), DefenderLeaguePointGot(DefenderLeaguePointGot_), Percentage(Percentage_)
	{
	}
	SReplayCore(TIndex&& Index_, SBattleUserInfo&& Attacker_, SBattleUserInfo&& Defender_, SLeaguePointGot&& AttackerLeaguePointGot_, SLeaguePointGot&& DefenderLeaguePointGot_, __int32&& Percentage_) : Index(std::move(Index_)), Attacker(std::move(Attacker_)), Defender(std::move(Defender_)), AttackerLeaguePointGot(std::move(AttackerLeaguePointGot_)), DefenderLeaguePointGot(std::move(DefenderLeaguePointGot_)), Percentage(std::move(Percentage_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> Attacker;
		Stream_ >> Defender;
		Stream_ >> AttackerLeaguePointGot;
		Stream_ >> DefenderLeaguePointGot;
		Stream_ >> Percentage;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Attacker << Value_["Attacker"];
		Defender << Value_["Defender"];
		AttackerLeaguePointGot << Value_["AttackerLeaguePointGot"];
		DefenderLeaguePointGot << Value_["DefenderLeaguePointGot"];
		Value_["Percentage"] >> Percentage;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << Attacker;
		Stream_ << Defender;
		Stream_ << AttackerLeaguePointGot;
		Stream_ << DefenderLeaguePointGot;
		Stream_ << Percentage;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["Attacker"] = Attacker;
		Value_["Defender"] = Defender;
		Value_["AttackerLeaguePointGot"] = AttackerLeaguePointGot;
		Value_["DefenderLeaguePointGot"] = DefenderLeaguePointGot;
		Value_["Percentage"] = Percentage;
	}
	static wstring StdName(void)
	{
		return L"int64,int64,wstring,int32,int32,int64,wstring,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,Win,Lose,Win,Lose,Percentage";
	}
};
struct SReplay : public SReplayCore
{
	bool IsCPDestroyed = false;
	TResources ResourcesGotLoss{};
	TLeaguePoint LeaguePointReached = 0;
	system_clock::time_point BattleStartTime;
	CStream Stream_SBattleUsedInfo;
	SReplay()
	{
	}
	SReplay(const SReplayCore& Super_, const bool& IsCPDestroyed_, const TResources& ResourcesGotLoss_, const TLeaguePoint& LeaguePointReached_, const system_clock::time_point& BattleStartTime_, const CStream& Stream_SBattleUsedInfo_) : SReplayCore(Super_), IsCPDestroyed(IsCPDestroyed_), ResourcesGotLoss(ResourcesGotLoss_), LeaguePointReached(LeaguePointReached_), BattleStartTime(BattleStartTime_), Stream_SBattleUsedInfo(Stream_SBattleUsedInfo_)
	{
	}
	SReplay(SReplayCore&& Super_, bool&& IsCPDestroyed_, TResources&& ResourcesGotLoss_, TLeaguePoint&& LeaguePointReached_, system_clock::time_point&& BattleStartTime_, CStream&& Stream_SBattleUsedInfo_) : SReplayCore(std::move(Super_)), IsCPDestroyed(std::move(IsCPDestroyed_)), ResourcesGotLoss(std::move(ResourcesGotLoss_)), LeaguePointReached(std::move(LeaguePointReached_)), BattleStartTime(std::move(BattleStartTime_)), Stream_SBattleUsedInfo(std::move(Stream_SBattleUsedInfo_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> IsCPDestroyed;
		Stream_ >> ResourcesGotLoss;
		Stream_ >> LeaguePointReached;
		Stream_ >> BattleStartTime;
		Stream_ >> Stream_SBattleUsedInfo;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["IsCPDestroyed"] >> IsCPDestroyed;
		Value_["ResourcesGotLoss"] >> ResourcesGotLoss;
		Value_["LeaguePointReached"] >> LeaguePointReached;
		Value_["BattleStartTime"] >> BattleStartTime;
		Value_["Stream_SBattleUsedInfo"] >> Stream_SBattleUsedInfo;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << IsCPDestroyed;
		Stream_ << ResourcesGotLoss;
		Stream_ << LeaguePointReached;
		Stream_ << BattleStartTime;
		Stream_ << Stream_SBattleUsedInfo;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["IsCPDestroyed"] = IsCPDestroyed;
		Value_["ResourcesGotLoss"] = ResourcesGotLoss;
		Value_["LeaguePointReached"] = LeaguePointReached;
		Value_["BattleStartTime"] = BattleStartTime;
		Value_["Stream_SBattleUsedInfo"] = Stream_SBattleUsedInfo;
	}
	static wstring StdName(void)
	{
		return L"int64,int64,wstring,int32,int32,int64,wstring,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,bool,int32,int32,int32,int32,int32,int32,time_point,stream";
	}
	static wstring MemberName(void)
	{
		return L"Index,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,Win,Lose,Win,Lose,Percentage,IsCPDestroyed,ResourcesGotLoss,LeaguePointReached,BattleStartTime,Stream_SBattleUsedInfo";
	}
};
struct SReplayDefence : public SReplay
{
	bool CanRevenge = false;
	SReplayDefence()
	{
	}
	SReplayDefence(const SReplay& Super_, const bool& CanRevenge_) : SReplay(Super_), CanRevenge(CanRevenge_)
	{
	}
	SReplayDefence(SReplay&& Super_, bool&& CanRevenge_) : SReplay(std::move(Super_)), CanRevenge(std::move(CanRevenge_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> CanRevenge;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["CanRevenge"] >> CanRevenge;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << CanRevenge;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["CanRevenge"] = CanRevenge;
	}
	static wstring StdName(void)
	{
		return L"int64,int64,wstring,int32,int32,int64,wstring,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,bool,int32,int32,int32,int32,int32,int32,time_point,stream,bool";
	}
	static wstring MemberName(void)
	{
		return L"Index,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,Win,Lose,Win,Lose,Percentage,IsCPDestroyed,ResourcesGotLoss,LeaguePointReached,BattleStartTime,Stream_SBattleUsedInfo,CanRevenge";
	}
};
enum class EMailType
{
	Message,
	Banish,
	Reject,
	Max,
	Null,
};
struct SUserBrief : public SProto
{
	TUID UID = 0;
	wstring Name;
	TRank Rank = 0;
	SUserBrief()
	{
	}
	SUserBrief(const TUID& UID_, const wstring& Name_, const TRank& Rank_) : UID(UID_), Name(Name_), Rank(Rank_)
	{
	}
	SUserBrief(TUID&& UID_, wstring&& Name_, TRank&& Rank_) : UID(std::move(UID_)), Name(std::move(Name_)), Rank(std::move(Rank_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
		Stream_ >> Name;
		Stream_ >> Rank;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
		Value_["Name"] >> Name;
		Value_["Rank"] >> Rank;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
		Stream_ << Name;
		Stream_ << Rank;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
		Value_["Name"] = Name;
		Value_["Rank"] = Rank;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Rank";
	}
};
struct SClanBrief : public SUserBrief
{
	wstring Mark;
	SClanBrief()
	{
	}
	SClanBrief(const SUserBrief& Super_, const wstring& Mark_) : SUserBrief(Super_), Mark(Mark_)
	{
	}
	SClanBrief(SUserBrief&& Super_, wstring&& Mark_) : SUserBrief(std::move(Super_)), Mark(std::move(Mark_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Mark;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Mark"] >> Mark;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Mark;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Mark"] = Mark;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Rank,Mark";
	}
};
struct SMailCore : public SProto
{
	system_clock::time_point Time;
	SUserBrief FromUser;
	SClanBrief FromClan;
	wstring Text;
	EMailType Type;
	CStream Stream;
	SMailCore()
	{
	}
	SMailCore(const system_clock::time_point& Time_, const SUserBrief& FromUser_, const SClanBrief& FromClan_, const wstring& Text_, const EMailType& Type_, const CStream& Stream_) : Time(Time_), FromUser(FromUser_), FromClan(FromClan_), Text(Text_), Type(Type_), Stream(Stream_)
	{
	}
	SMailCore(system_clock::time_point&& Time_, SUserBrief&& FromUser_, SClanBrief&& FromClan_, wstring&& Text_, EMailType&& Type_, CStream&& Stream_) : Time(std::move(Time_)), FromUser(std::move(FromUser_)), FromClan(std::move(FromClan_)), Text(std::move(Text_)), Type(std::move(Type_)), Stream(std::move(Stream_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> FromUser;
		Stream_ >> FromClan;
		Stream_ >> Text;
		Stream_ >> (__int32&)Type;
		Stream_ >> Stream;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		FromUser << Value_["FromUser"];
		FromClan << Value_["FromClan"];
		Value_["Text"] >> Text;
		Value_["Type"] >> (__int32&)Type;
		Value_["Stream"] >> Stream;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << FromUser;
		Stream_ << FromClan;
		Stream_ << Text;
		Stream_ << (__int32)Type;
		Stream_ << Stream;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["FromUser"] = FromUser;
		Value_["FromClan"] = FromClan;
		Value_["Text"] = Text;
		Value_["Type"] = (__int32)Type;
		Value_["Stream"] = Stream;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,wstring,int32,int64,wstring,int32,wstring,wstring,int32,stream";
	}
	static wstring MemberName(void)
	{
		return L"Time,UID,Name,Rank,UID,Name,Rank,Mark,Text,Type,Stream";
	}
};
struct SMail : public SProto
{
	TIndex Index = 0;
	SMailCore MailCore;
	SMail()
	{
	}
	SMail(const TIndex& Index_, const SMailCore& MailCore_) : Index(Index_), MailCore(MailCore_)
	{
	}
	SMail(TIndex&& Index_, SMailCore&& MailCore_) : Index(std::move(Index_)), MailCore(std::move(MailCore_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> MailCore;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		MailCore << Value_["MailCore"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << MailCore;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["MailCore"] = MailCore;
	}
	static wstring StdName(void)
	{
		return L"int64,time_point,int64,wstring,int32,int64,wstring,int32,wstring,wstring,int32,stream";
	}
	static wstring MemberName(void)
	{
		return L"Index,Time,UID,Name,Rank,UID,Name,Rank,Mark,Text,Type,Stream";
	}
};
struct SShuttle : public SProto
{
	TID GroupID = 0;
	bool Trained = false;
	SShuttle()
	{
	}
	SShuttle(const TID& GroupID_, const bool& Trained_) : GroupID(GroupID_), Trained(Trained_)
	{
	}
	SShuttle(TID&& GroupID_, bool&& Trained_) : GroupID(std::move(GroupID_)), Trained(std::move(Trained_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> GroupID;
		Stream_ >> Trained;
	}
	void operator << (const Value& Value_) override
	{
		Value_["GroupID"] >> GroupID;
		Value_["Trained"] >> Trained;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << GroupID;
		Stream_ << Trained;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["GroupID"] = GroupID;
		Value_["Trained"] = Trained;
	}
	static wstring StdName(void)
	{
		return L"int32,bool";
	}
	static wstring MemberName(void)
	{
		return L"GroupID,Trained";
	}
};
using TShuttles = vector<SShuttle>;
struct SSpacePlatform : public SProto
{
	system_clock::time_point StartTime;
	__int64 StartIndex = 0;
	TShuttles Shuttles;
	SSpacePlatform()
	{
	}
	SSpacePlatform(const system_clock::time_point& StartTime_, const __int64& StartIndex_, const TShuttles& Shuttles_) : StartTime(StartTime_), StartIndex(StartIndex_), Shuttles(Shuttles_)
	{
	}
	SSpacePlatform(system_clock::time_point&& StartTime_, __int64&& StartIndex_, TShuttles&& Shuttles_) : StartTime(std::move(StartTime_)), StartIndex(std::move(StartIndex_)), Shuttles(std::move(Shuttles_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> StartTime;
		Stream_ >> StartIndex;
		Stream_ >> Shuttles;
	}
	void operator << (const Value& Value_) override
	{
		Value_["StartTime"] >> StartTime;
		Value_["StartIndex"] >> StartIndex;
		Value_["Shuttles"] >> Shuttles;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << StartTime;
		Stream_ << StartIndex;
		Stream_ << Shuttles;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["StartTime"] = StartTime;
		Value_["StartIndex"] = StartIndex;
		Value_["Shuttles"] = Shuttles;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,{int32,bool}";
	}
	static wstring MemberName(void)
	{
		return L"StartTime,StartIndex,Shuttles";
	}
};
struct SGroupIDLevel : public SProto
{
	TID GroupID = 0;
	TLevel Level = 0;
	SGroupIDLevel()
	{
	}
	SGroupIDLevel(const TID& GroupID_, const TLevel& Level_) : GroupID(GroupID_), Level(Level_)
	{
	}
	SGroupIDLevel(TID&& GroupID_, TLevel&& Level_) : GroupID(std::move(GroupID_)), Level(std::move(Level_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> GroupID;
		Stream_ >> Level;
	}
	void operator << (const Value& Value_) override
	{
		Value_["GroupID"] >> GroupID;
		Value_["Level"] >> Level;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << GroupID;
		Stream_ << Level;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["GroupID"] = GroupID;
		Value_["Level"] = Level;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"GroupID,Level";
	}
};
using TClanForce = map<__int64,SGroupIDLevel>;
using TClanForces = array<TClanForce,2>;
using TTutorialIndex = __int8;
using TTutorialNumber = __int64;
using TTutorials = map<TTutorialIndex,TTutorialNumber>;
using TMails = list<SMail>;
struct SAchievement : public SProto
{
	TLevel Level = 0;
	__int64 Count = 0;
	SAchievement()
	{
	}
	SAchievement(const TLevel& Level_, const __int64& Count_) : Level(Level_), Count(Count_)
	{
	}
	SAchievement(TLevel&& Level_, __int64&& Count_) : Level(std::move(Level_)), Count(std::move(Count_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Level;
		Stream_ >> Count;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Level"] >> Level;
		Value_["Count"] >> Count;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Level;
		Stream_ << Count;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Level"] = Level;
		Value_["Count"] = Count;
	}
	static wstring StdName(void)
	{
		return L"int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"Level,Count";
	}
};
using TAchievements = map<__int32,SAchievement>;
struct SUserInfoNetSc : public SProto
{
	SUserNet User;
	list<SBuildingBase> Buildings;
	TEnvObjectDBs EnvObjects;
	TEnvObjectDBs EnvDevelops;
	array<SSpacePlatform,2> Units{};
	TUpgrades Upgrades;
	TAvatarSlots AvatarSlots;
	TAvatarDefences AvatarDefences;
	TAvatarUpgrades AvatarUpgrades;
	TSingleWorld SingleWorld;
	TTutorials Tutorials;
	system_clock::time_point ServerNowTime;
	TClanForces ClanCastleUnits{};
	TAchievements Achievements;
	SUserInfoNetSc()
	{
	}
	SUserInfoNetSc(const SUserNet& User_, const list<SBuildingBase>& Buildings_, const TEnvObjectDBs& EnvObjects_, const TEnvObjectDBs& EnvDevelops_, const array<SSpacePlatform,2>& Units_, const TUpgrades& Upgrades_, const TAvatarSlots& AvatarSlots_, const TAvatarDefences& AvatarDefences_, const TAvatarUpgrades& AvatarUpgrades_, const TSingleWorld& SingleWorld_, const TTutorials& Tutorials_, const system_clock::time_point& ServerNowTime_, const TClanForces& ClanCastleUnits_, const TAchievements& Achievements_) : User(User_), Buildings(Buildings_), EnvObjects(EnvObjects_), EnvDevelops(EnvDevelops_), Units(Units_), Upgrades(Upgrades_), AvatarSlots(AvatarSlots_), AvatarDefences(AvatarDefences_), AvatarUpgrades(AvatarUpgrades_), SingleWorld(SingleWorld_), Tutorials(Tutorials_), ServerNowTime(ServerNowTime_), ClanCastleUnits(ClanCastleUnits_), Achievements(Achievements_)
	{
	}
	SUserInfoNetSc(SUserNet&& User_, list<SBuildingBase>&& Buildings_, TEnvObjectDBs&& EnvObjects_, TEnvObjectDBs&& EnvDevelops_, array<SSpacePlatform,2>&& Units_, TUpgrades&& Upgrades_, TAvatarSlots&& AvatarSlots_, TAvatarDefences&& AvatarDefences_, TAvatarUpgrades&& AvatarUpgrades_, TSingleWorld&& SingleWorld_, TTutorials&& Tutorials_, system_clock::time_point&& ServerNowTime_, TClanForces&& ClanCastleUnits_, TAchievements&& Achievements_) : User(std::move(User_)), Buildings(std::move(Buildings_)), EnvObjects(std::move(EnvObjects_)), EnvDevelops(std::move(EnvDevelops_)), Units(std::move(Units_)), Upgrades(std::move(Upgrades_)), AvatarSlots(std::move(AvatarSlots_)), AvatarDefences(std::move(AvatarDefences_)), AvatarUpgrades(std::move(AvatarUpgrades_)), SingleWorld(std::move(SingleWorld_)), Tutorials(std::move(Tutorials_)), ServerNowTime(std::move(ServerNowTime_)), ClanCastleUnits(std::move(ClanCastleUnits_)), Achievements(std::move(Achievements_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> User;
		Stream_ >> Buildings;
		Stream_ >> EnvObjects;
		Stream_ >> EnvDevelops;
		Stream_ >> Units;
		Stream_ >> Upgrades;
		Stream_ >> AvatarSlots;
		Stream_ >> AvatarDefences;
		Stream_ >> AvatarUpgrades;
		Stream_ >> SingleWorld;
		Stream_ >> Tutorials;
		Stream_ >> ServerNowTime;
		Stream_ >> ClanCastleUnits;
		Stream_ >> Achievements;
	}
	void operator << (const Value& Value_) override
	{
		User << Value_["User"];
		Value_["Buildings"] >> Buildings;
		Value_["EnvObjects"] >> EnvObjects;
		Value_["EnvDevelops"] >> EnvDevelops;
		Value_["Units"] >> Units;
		Value_["Upgrades"] >> Upgrades;
		Value_["AvatarSlots"] >> AvatarSlots;
		Value_["AvatarDefences"] >> AvatarDefences;
		Value_["AvatarUpgrades"] >> AvatarUpgrades;
		Value_["SingleWorld"] >> SingleWorld;
		Value_["Tutorials"] >> Tutorials;
		Value_["ServerNowTime"] >> ServerNowTime;
		Value_["ClanCastleUnits"] >> ClanCastleUnits;
		Value_["Achievements"] >> Achievements;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << User;
		Stream_ << Buildings;
		Stream_ << EnvObjects;
		Stream_ << EnvDevelops;
		Stream_ << Units;
		Stream_ << Upgrades;
		Stream_ << AvatarSlots;
		Stream_ << AvatarDefences;
		Stream_ << AvatarUpgrades;
		Stream_ << SingleWorld;
		Stream_ << Tutorials;
		Stream_ << ServerNowTime;
		Stream_ << ClanCastleUnits;
		Stream_ << Achievements;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["User"] = User;
		Value_["Buildings"] = Buildings;
		Value_["EnvObjects"] = EnvObjects;
		Value_["EnvDevelops"] = EnvDevelops;
		Value_["Units"] = Units;
		Value_["Upgrades"] = Upgrades;
		Value_["AvatarSlots"] = AvatarSlots;
		Value_["AvatarDefences"] = AvatarDefences;
		Value_["AvatarUpgrades"] = AvatarUpgrades;
		Value_["SingleWorld"] = SingleWorld;
		Value_["Tutorials"] = Tutorials;
		Value_["ServerNowTime"] = ServerNowTime;
		Value_["ClanCastleUnits"] = ClanCastleUnits;
		Value_["Achievements"] = Achievements;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,int8,int32,int8,time_point,wstring,time_point,int32,int32,int32,int32,int32,int32,int32,time_point,time_point,double,time_point,time_point,int32,int64,int32,int32,int64,int64,int64,wstring,wstring,int32,time_point,time_point,int32,int32,time_point,{int64,int32,int32,int32,int32,int8,int32,int32,int8,int8,time_point,bool,time_point,int64,time_point,time_point,double},{int64,int32,int32,int32,time_point},{int64,int32,int32,int32,time_point},time_point,int64,{int32,bool},time_point,int64,{int32,bool},{int32,int32,bool,time_point},{int32,int32,int32,int32,int32,int32,int32,int32,bool,time_point},{int32,int32,int32,int32,int32,int32,int32,int32,bool,bool},{int32,int32,int32,bool,time_point},{int32,{int32,{int32,int32,bool,time_point}}},{int8,int64},time_point,{int64,int32,int32},{int64,int32,int32},{int32,int32,int64}";
	}
	static wstring MemberName(void)
	{
		return L"Resource,LeaguePoint,LeagueCur,LeagueBest,AvatarActivatedSlotNo,Exp,Debug,LastEnvObjectGenTime,Nick,ClanCastleCoolEndTime,Resources,X,Y,BeginTime,EndTime,Speed,BatchBoostCoolEndTime,DepositTime,BankLevel,InterestIndex,ResourceType,ResourceValue,LastEnvObjectIndex,EnvObjectRewardIndex,UID,Name,Mark,Exp,GuardEndTime,InsertedTimePoint,Count,Point,LastCheckTime,Buildings,EnvObjects,EnvDevelops,Units,Upgrades,AvatarSlots,AvatarDefences,AvatarUpgrades,SingleWorld,Tutorials,ServerNowTime,ClanCastleUnits,Achievements";
	}
};
struct SBuyResourcesWithTopazNetCs : public SResourceTypeData
{
	SBuyResourcesWithTopazNetCs()
	{
	}
	SBuyResourcesWithTopazNetCs(const SResourceTypeData& Super_) : SResourceTypeData(Super_)
	{
	}
	SBuyResourcesWithTopazNetCs(SResourceTypeData&& Super_) : SResourceTypeData(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Type,Data";
	}
};
struct SBuildNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	TID GroupID = 0;
	SPos Pos;
	SBuildingRotate Rotate;
	SBuildNetCs()
	{
	}
	SBuildNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_, const TID& GroupID_, const SPos& Pos_, const SBuildingRotate& Rotate_) : Time(Time_), TopazUseInfo(TopazUseInfo_), GroupID(GroupID_), Pos(Pos_), Rotate(Rotate_)
	{
	}
	SBuildNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_, TID&& GroupID_, SPos&& Pos_, SBuildingRotate&& Rotate_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_)), GroupID(std::move(GroupID_)), Pos(std::move(Pos_)), Rotate(std::move(Rotate_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
		Stream_ >> GroupID;
		Stream_ >> Pos;
		Stream_ >> Rotate;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["GroupID"] >> GroupID;
		Pos << Value_["Pos"];
		Rotate << Value_["Rotate"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
		Stream_ << GroupID;
		Stream_ << Pos;
		Stream_ << Rotate;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["GroupID"] = GroupID;
		Value_["Pos"] = Pos;
		Value_["Rotate"] = Rotate;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32,int32,int32,int32,int8,int8";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data,GroupID,X,Y,Rotate,RotateHead";
	}
};
struct SBuildNetSc : public SBuildingBase
{
	TResources ResourceLeft{};
	SBuildNetSc()
	{
	}
	SBuildNetSc(const SBuildingBase& Super_, const TResources& ResourceLeft_) : SBuildingBase(Super_), ResourceLeft(ResourceLeft_)
	{
	}
	SBuildNetSc(SBuildingBase&& Super_, TResources&& ResourceLeft_) : SBuildingBase(std::move(Super_)), ResourceLeft(std::move(ResourceLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> ResourceLeft;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["ResourceLeft"] >> ResourceLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << ResourceLeft;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["ResourceLeft"] = ResourceLeft;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,int32,int32,int32,int8,int32,int32,int8,int8,time_point,bool,time_point,int64,time_point,time_point,double,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,GroupID,Level,X,Y,Mode,BulletGroupID,BulletLeft,Rotate,RotateHead,BaseTime,IsCompleted,UpgradeEndTime,DurationTicks,BeginTime,EndTime,Speed,ResourceLeft";
	}
};
struct SBuildingUpgradeNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	TIndex Index = 0;
	SBuildingUpgradeNetCs()
	{
	}
	SBuildingUpgradeNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_, const TIndex& Index_) : Time(Time_), TopazUseInfo(TopazUseInfo_), Index(Index_)
	{
	}
	SBuildingUpgradeNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_, TIndex&& Index_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_)), Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data,Index";
	}
};
struct SBuildingUpgradeNetSc : public SProto
{
	TIndex Index = 0;
	TLevel Level = 0;
	system_clock::time_point StartTime;
	TResources ResourceLeft{};
	SBuildingUpgradeNetSc()
	{
	}
	SBuildingUpgradeNetSc(const TIndex& Index_, const TLevel& Level_, const system_clock::time_point& StartTime_, const TResources& ResourceLeft_) : Index(Index_), Level(Level_), StartTime(StartTime_), ResourceLeft(ResourceLeft_)
	{
	}
	SBuildingUpgradeNetSc(TIndex&& Index_, TLevel&& Level_, system_clock::time_point&& StartTime_, TResources&& ResourceLeft_) : Index(std::move(Index_)), Level(std::move(Level_)), StartTime(std::move(StartTime_)), ResourceLeft(std::move(ResourceLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> Level;
		Stream_ >> StartTime;
		Stream_ >> ResourceLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["Level"] >> Level;
		Value_["StartTime"] >> StartTime;
		Value_["ResourceLeft"] >> ResourceLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << Level;
		Stream_ << StartTime;
		Stream_ << ResourceLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["Level"] = Level;
		Value_["StartTime"] = StartTime;
		Value_["ResourceLeft"] = ResourceLeft;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,time_point,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,Level,StartTime,ResourceLeft";
	}
};
struct SBuildingUpgradeCancelNetCs : public SProto
{
	system_clock::time_point Time;
	TIndex Index = 0;
	SBuildingUpgradeCancelNetCs()
	{
	}
	SBuildingUpgradeCancelNetCs(const system_clock::time_point& Time_, const TIndex& Index_) : Time(Time_), Index(Index_)
	{
	}
	SBuildingUpgradeCancelNetCs(system_clock::time_point&& Time_, TIndex&& Index_) : Time(std::move(Time_)), Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,Index";
	}
};
struct SBuildingUpgradeCancelNetSc : public SProto
{
	TIndex Index = 0;
	system_clock::time_point CollectedTime;
	TResources ResourceLeft{};
	SBuildingUpgradeCancelNetSc()
	{
	}
	SBuildingUpgradeCancelNetSc(const TIndex& Index_, const system_clock::time_point& CollectedTime_, const TResources& ResourceLeft_) : Index(Index_), CollectedTime(CollectedTime_), ResourceLeft(ResourceLeft_)
	{
	}
	SBuildingUpgradeCancelNetSc(TIndex&& Index_, system_clock::time_point&& CollectedTime_, TResources&& ResourceLeft_) : Index(std::move(Index_)), CollectedTime(std::move(CollectedTime_)), ResourceLeft(std::move(ResourceLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> CollectedTime;
		Stream_ >> ResourceLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["CollectedTime"] >> CollectedTime;
		Value_["ResourceLeft"] >> ResourceLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << CollectedTime;
		Stream_ << ResourceLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["CollectedTime"] = CollectedTime;
		Value_["ResourceLeft"] = ResourceLeft;
	}
	static wstring StdName(void)
	{
		return L"int64,time_point,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,CollectedTime,ResourceLeft";
	}
};
struct SBuildingUpgradeCompleteNetCs : public SProto
{
	system_clock::time_point Time;
	TIndex Index = 0;
	bool UseTopaz = false;
	SBuildingUpgradeCompleteNetCs()
	{
	}
	SBuildingUpgradeCompleteNetCs(const system_clock::time_point& Time_, const TIndex& Index_, const bool& UseTopaz_) : Time(Time_), Index(Index_), UseTopaz(UseTopaz_)
	{
	}
	SBuildingUpgradeCompleteNetCs(system_clock::time_point&& Time_, TIndex&& Index_, bool&& UseTopaz_) : Time(std::move(Time_)), Index(std::move(Index_)), UseTopaz(std::move(UseTopaz_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Index;
		Stream_ >> UseTopaz;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Index"] >> Index;
		Value_["UseTopaz"] >> UseTopaz;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Index;
		Stream_ << UseTopaz;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Index"] = Index;
		Value_["UseTopaz"] = UseTopaz;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,bool";
	}
	static wstring MemberName(void)
	{
		return L"Time,Index,UseTopaz";
	}
};
struct SBuildingUpgradeCompleteNetSc : public SProto
{
	TIndex Index = 0;
	system_clock::time_point CollectedTime;
	TExp Exp = 0;
	SBuildingUpgradeCompleteNetSc()
	{
	}
	SBuildingUpgradeCompleteNetSc(const TIndex& Index_, const system_clock::time_point& CollectedTime_, const TExp& Exp_) : Index(Index_), CollectedTime(CollectedTime_), Exp(Exp_)
	{
	}
	SBuildingUpgradeCompleteNetSc(TIndex&& Index_, system_clock::time_point&& CollectedTime_, TExp&& Exp_) : Index(std::move(Index_)), CollectedTime(std::move(CollectedTime_)), Exp(std::move(Exp_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> CollectedTime;
		Stream_ >> Exp;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["CollectedTime"] >> CollectedTime;
		Value_["Exp"] >> Exp;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << CollectedTime;
		Stream_ << Exp;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["CollectedTime"] = CollectedTime;
		Value_["Exp"] = Exp;
	}
	static wstring StdName(void)
	{
		return L"int64,time_point,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,CollectedTime,Exp";
	}
};
struct SBuildingMoveNetCs : public SProto
{
	TIndex Index = 0;
	SPos Pos;
	SBuildingRotate Rotate;
	SBuildingMoveNetCs()
	{
	}
	SBuildingMoveNetCs(const TIndex& Index_, const SPos& Pos_, const SBuildingRotate& Rotate_) : Index(Index_), Pos(Pos_), Rotate(Rotate_)
	{
	}
	SBuildingMoveNetCs(TIndex&& Index_, SPos&& Pos_, SBuildingRotate&& Rotate_) : Index(std::move(Index_)), Pos(std::move(Pos_)), Rotate(std::move(Rotate_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> Pos;
		Stream_ >> Rotate;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Pos << Value_["Pos"];
		Rotate << Value_["Rotate"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << Pos;
		Stream_ << Rotate;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["Pos"] = Pos;
		Value_["Rotate"] = Rotate;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,int32,int8,int8";
	}
	static wstring MemberName(void)
	{
		return L"Index,X,Y,Rotate,RotateHead";
	}
};
struct SBuildingMoveNetSc : public SProto
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
struct SBuildingChangeModeNetCs : public SProto
{
	TIndex Index = 0;
	__int8 Mode = 0;
	SBuildingChangeModeNetCs()
	{
	}
	SBuildingChangeModeNetCs(const TIndex& Index_, const __int8& Mode_) : Index(Index_), Mode(Mode_)
	{
	}
	SBuildingChangeModeNetCs(TIndex&& Index_, __int8&& Mode_) : Index(std::move(Index_)), Mode(std::move(Mode_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> Mode;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["Mode"] >> Mode;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << Mode;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["Mode"] = Mode;
	}
	static wstring StdName(void)
	{
		return L"int64,int8";
	}
	static wstring MemberName(void)
	{
		return L"Index,Mode";
	}
};
struct SBuildingChangeModeNetSc : public SProto
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
enum class EDefenceBuildingType
{
	Trap,
	Tower,
	Max,
	Null,
};
struct SBuildingReinstallNetCs : public SProto
{
	SResourceTypeData TopazUseInfo;
	EDefenceBuildingType Type;
	TIndex BuildingIndex = 0;
	SBuildingReinstallNetCs()
	{
	}
	SBuildingReinstallNetCs(const SResourceTypeData& TopazUseInfo_, const EDefenceBuildingType& Type_, const TIndex& BuildingIndex_) : TopazUseInfo(TopazUseInfo_), Type(Type_), BuildingIndex(BuildingIndex_)
	{
	}
	SBuildingReinstallNetCs(SResourceTypeData&& TopazUseInfo_, EDefenceBuildingType&& Type_, TIndex&& BuildingIndex_) : TopazUseInfo(std::move(TopazUseInfo_)), Type(std::move(Type_)), BuildingIndex(std::move(BuildingIndex_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TopazUseInfo;
		Stream_ >> (__int32&)Type;
		Stream_ >> BuildingIndex;
	}
	void operator << (const Value& Value_) override
	{
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["Type"] >> (__int32&)Type;
		Value_["BuildingIndex"] >> BuildingIndex;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TopazUseInfo;
		Stream_ << (__int32)Type;
		Stream_ << BuildingIndex;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["Type"] = (__int32)Type;
		Value_["BuildingIndex"] = BuildingIndex;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"Type,Data,Type,BuildingIndex";
	}
};
struct SBuildingReinstallNetSc : public SProto
{
	TResources ResourceLeft{};
	SBuildingReinstallNetSc()
	{
	}
	SBuildingReinstallNetSc(const TResources& ResourceLeft_) : ResourceLeft(ResourceLeft_)
	{
	}
	SBuildingReinstallNetSc(TResources&& ResourceLeft_) : ResourceLeft(std::move(ResourceLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourceLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourceLeft"] >> ResourceLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourceLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourceLeft"] = ResourceLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourceLeft";
	}
};
struct SBuildingBulletChangeNetCs : public SProto
{
	SResourceTypeData TopazUseInfo;
	TIndex BuildingIndex = 0;
	TID BulletGroupID = 0;
	SBuildingBulletChangeNetCs()
	{
	}
	SBuildingBulletChangeNetCs(const SResourceTypeData& TopazUseInfo_, const TIndex& BuildingIndex_, const TID& BulletGroupID_) : TopazUseInfo(TopazUseInfo_), BuildingIndex(BuildingIndex_), BulletGroupID(BulletGroupID_)
	{
	}
	SBuildingBulletChangeNetCs(SResourceTypeData&& TopazUseInfo_, TIndex&& BuildingIndex_, TID&& BulletGroupID_) : TopazUseInfo(std::move(TopazUseInfo_)), BuildingIndex(std::move(BuildingIndex_)), BulletGroupID(std::move(BulletGroupID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TopazUseInfo;
		Stream_ >> BuildingIndex;
		Stream_ >> BulletGroupID;
	}
	void operator << (const Value& Value_) override
	{
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["BuildingIndex"] >> BuildingIndex;
		Value_["BulletGroupID"] >> BulletGroupID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TopazUseInfo;
		Stream_ << BuildingIndex;
		Stream_ << BulletGroupID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["BuildingIndex"] = BuildingIndex;
		Value_["BulletGroupID"] = BulletGroupID;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int64,int32";
	}
	static wstring MemberName(void)
	{
		return L"Type,Data,BuildingIndex,BulletGroupID";
	}
};
struct SBuildingBulletChangeNetSc : public SProto
{
	TResources ResourceLeft{};
	SBuildingBulletChangeNetSc()
	{
	}
	SBuildingBulletChangeNetSc(const TResources& ResourceLeft_) : ResourceLeft(ResourceLeft_)
	{
	}
	SBuildingBulletChangeNetSc(TResources&& ResourceLeft_) : ResourceLeft(std::move(ResourceLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourceLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourceLeft"] >> ResourceLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourceLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourceLeft"] = ResourceLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourceLeft";
	}
};
struct SCollectNetCs : public SProto
{
	system_clock::time_point Time;
	TIndex Index = 0;
	SCollectNetCs()
	{
	}
	SCollectNetCs(const system_clock::time_point& Time_, const TIndex& Index_) : Time(Time_), Index(Index_)
	{
	}
	SCollectNetCs(system_clock::time_point&& Time_, TIndex&& Index_) : Time(std::move(Time_)), Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,Index";
	}
};
struct SIndexTime : public SProto
{
	TIndex Index = 0;
	system_clock::time_point Time;
	SIndexTime()
	{
	}
	SIndexTime(const TIndex& Index_, const system_clock::time_point& Time_) : Index(Index_), Time(Time_)
	{
	}
	SIndexTime(TIndex&& Index_, system_clock::time_point&& Time_) : Index(std::move(Index_)), Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"int64,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Index,Time";
	}
};
using TIndexTimes = list<SIndexTime>;
struct SSlotNoTime : public SProto
{
	TSlotNo SlotNo = 0;
	system_clock::time_point Time;
	SSlotNoTime()
	{
	}
	SSlotNoTime(const TSlotNo& SlotNo_, const system_clock::time_point& Time_) : SlotNo(SlotNo_), Time(Time_)
	{
	}
	SSlotNoTime(TSlotNo&& SlotNo_, system_clock::time_point&& Time_) : SlotNo(std::move(SlotNo_)), Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> SlotNo;
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		Value_["SlotNo"] >> SlotNo;
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << SlotNo;
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["SlotNo"] = SlotNo;
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"int8,time_point";
	}
	static wstring MemberName(void)
	{
		return L"SlotNo,Time";
	}
};
using TSlotNoTimes = list<SSlotNoTime>;
struct SCollectNetSc : public SProto
{
	TResources LeftResource{};
	TIndexTimes CollectedBuildingIndexTimes;
	SCollectNetSc()
	{
	}
	SCollectNetSc(const TResources& LeftResource_, const TIndexTimes& CollectedBuildingIndexTimes_) : LeftResource(LeftResource_), CollectedBuildingIndexTimes(CollectedBuildingIndexTimes_)
	{
	}
	SCollectNetSc(TResources&& LeftResource_, TIndexTimes&& CollectedBuildingIndexTimes_) : LeftResource(std::move(LeftResource_)), CollectedBuildingIndexTimes(std::move(CollectedBuildingIndexTimes_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> LeftResource;
		Stream_ >> CollectedBuildingIndexTimes;
	}
	void operator << (const Value& Value_) override
	{
		Value_["LeftResource"] >> LeftResource;
		Value_["CollectedBuildingIndexTimes"] >> CollectedBuildingIndexTimes;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << LeftResource;
		Stream_ << CollectedBuildingIndexTimes;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["LeftResource"] = LeftResource;
		Value_["CollectedBuildingIndexTimes"] = CollectedBuildingIndexTimes;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,{int64,time_point}";
	}
	static wstring MemberName(void)
	{
		return L"LeftResource,CollectedBuildingIndexTimes";
	}
};
struct STrain : public SSpacePlatform
{
	system_clock::time_point Time;
	EForceType Force;
	STrain()
	{
	}
	STrain(const SSpacePlatform& Super_, const system_clock::time_point& Time_, const EForceType& Force_) : SSpacePlatform(Super_), Time(Time_), Force(Force_)
	{
	}
	STrain(SSpacePlatform&& Super_, system_clock::time_point&& Time_, EForceType&& Force_) : SSpacePlatform(std::move(Super_)), Time(std::move(Time_)), Force(std::move(Force_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Time;
		Stream_ >> (__int32&)Force;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Time"] >> Time;
		Value_["Force"] >> (__int32&)Force;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Time;
		Stream_ << (__int32)Force;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Time"] = Time;
		Value_["Force"] = (__int32)Force;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,{int32,bool},time_point,int32";
	}
	static wstring MemberName(void)
	{
		return L"StartTime,StartIndex,Shuttles,Time,Force";
	}
};
struct STrainNetCs : public STrain
{
	SResourceTypeData TopazUseInfo;
	STrainNetCs()
	{
	}
	STrainNetCs(const STrain& Super_, const SResourceTypeData& TopazUseInfo_) : STrain(Super_), TopazUseInfo(TopazUseInfo_)
	{
	}
	STrainNetCs(STrain&& Super_, SResourceTypeData&& TopazUseInfo_) : STrain(std::move(Super_)), TopazUseInfo(std::move(TopazUseInfo_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> TopazUseInfo;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		TopazUseInfo << Value_["TopazUseInfo"];
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << TopazUseInfo;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["TopazUseInfo"] = TopazUseInfo;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,{int32,bool},time_point,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"StartTime,StartIndex,Shuttles,Time,Force,Type,Data";
	}
};
struct STrainNetSc : public SProto
{
	TResources ResourceLeft{};
	STrainNetSc()
	{
	}
	STrainNetSc(const TResources& ResourceLeft_) : ResourceLeft(ResourceLeft_)
	{
	}
	STrainNetSc(TResources&& ResourceLeft_) : ResourceLeft(std::move(ResourceLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourceLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourceLeft"] >> ResourceLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourceLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourceLeft"] = ResourceLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourceLeft";
	}
};
struct STrainWithTopazNetCs : public STrain
{
	STrainWithTopazNetCs()
	{
	}
	STrainWithTopazNetCs(const STrain& Super_) : STrain(Super_)
	{
	}
	STrainWithTopazNetCs(STrain&& Super_) : STrain(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,{int32,bool},time_point,int32";
	}
	static wstring MemberName(void)
	{
		return L"StartTime,StartIndex,Shuttles,Time,Force";
	}
};
struct STrainWithTopazNetSc : public SProto
{
	TResource TopazLeft = 0;
	STrainWithTopazNetSc()
	{
	}
	STrainWithTopazNetSc(const TResource& TopazLeft_) : TopazLeft(TopazLeft_)
	{
	}
	STrainWithTopazNetSc(TResource&& TopazLeft_) : TopazLeft(std::move(TopazLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TopazLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["TopazLeft"] >> TopazLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TopazLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TopazLeft"] = TopazLeft;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"TopazLeft";
	}
};
struct SBarrackSyncNetCs : public STrain
{
	SBarrackSyncNetCs()
	{
	}
	SBarrackSyncNetCs(const STrain& Super_) : STrain(Super_)
	{
	}
	SBarrackSyncNetCs(STrain&& Super_) : STrain(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,{int32,bool},time_point,int32";
	}
	static wstring MemberName(void)
	{
		return L"StartTime,StartIndex,Shuttles,Time,Force";
	}
};
struct SUnitUpgradeNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	TID GroupID = 0;
	SUnitUpgradeNetCs()
	{
	}
	SUnitUpgradeNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_, const TID& GroupID_) : Time(Time_), TopazUseInfo(TopazUseInfo_), GroupID(GroupID_)
	{
	}
	SUnitUpgradeNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_, TID&& GroupID_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_)), GroupID(std::move(GroupID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
		Stream_ >> GroupID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["GroupID"] >> GroupID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
		Stream_ << GroupID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["GroupID"] = GroupID;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data,GroupID";
	}
};
struct SUnitUpgradeNetSc : public SUnitUpgradeInfo
{
	TID GroupID = 0;
	TResources ResourcesLeft{};
	SUnitUpgradeNetSc()
	{
	}
	SUnitUpgradeNetSc(const SUnitUpgradeInfo& Super_, const TID& GroupID_, const TResources& ResourcesLeft_) : SUnitUpgradeInfo(Super_), GroupID(GroupID_), ResourcesLeft(ResourcesLeft_)
	{
	}
	SUnitUpgradeNetSc(SUnitUpgradeInfo&& Super_, TID&& GroupID_, TResources&& ResourcesLeft_) : SUnitUpgradeInfo(std::move(Super_)), GroupID(std::move(GroupID_)), ResourcesLeft(std::move(ResourcesLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> GroupID;
		Stream_ >> ResourcesLeft;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["GroupID"] >> GroupID;
		Value_["ResourcesLeft"] >> ResourcesLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << GroupID;
		Stream_ << ResourcesLeft;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["GroupID"] = GroupID;
		Value_["ResourcesLeft"] = ResourcesLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,bool,time_point,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Level,IsCompleted,CompleteTime,GroupID,ResourcesLeft";
	}
};
struct SUnitUpgradeCompleteNetCs : public SProto
{
	system_clock::time_point Time;
	TID GroupID = 0;
	bool UseTopaz = false;
	SUnitUpgradeCompleteNetCs()
	{
	}
	SUnitUpgradeCompleteNetCs(const system_clock::time_point& Time_, const TID& GroupID_, const bool& UseTopaz_) : Time(Time_), GroupID(GroupID_), UseTopaz(UseTopaz_)
	{
	}
	SUnitUpgradeCompleteNetCs(system_clock::time_point&& Time_, TID&& GroupID_, bool&& UseTopaz_) : Time(std::move(Time_)), GroupID(std::move(GroupID_)), UseTopaz(std::move(UseTopaz_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> GroupID;
		Stream_ >> UseTopaz;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["GroupID"] >> GroupID;
		Value_["UseTopaz"] >> UseTopaz;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << GroupID;
		Stream_ << UseTopaz;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["GroupID"] = GroupID;
		Value_["UseTopaz"] = UseTopaz;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,bool";
	}
	static wstring MemberName(void)
	{
		return L"Time,GroupID,UseTopaz";
	}
};
struct SUnitUpgradeCompleteNetSc : public SProto
{
	TID GroupID = 0;
	TExp Exp = 0;
	SUnitUpgradeCompleteNetSc()
	{
	}
	SUnitUpgradeCompleteNetSc(const TID& GroupID_, const TExp& Exp_) : GroupID(GroupID_), Exp(Exp_)
	{
	}
	SUnitUpgradeCompleteNetSc(TID&& GroupID_, TExp&& Exp_) : GroupID(std::move(GroupID_)), Exp(std::move(Exp_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> GroupID;
		Stream_ >> Exp;
	}
	void operator << (const Value& Value_) override
	{
		Value_["GroupID"] >> GroupID;
		Value_["Exp"] >> Exp;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << GroupID;
		Stream_ << Exp;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["GroupID"] = GroupID;
		Value_["Exp"] = Exp;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"GroupID,Exp";
	}
};
enum class EAvatarPartsType
{
	HBody,
	Arm,
	Leg,
	Core,
	Max,
	Null,
};
struct SAvatarSlotAddNetCs : public SProto
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
struct SAvatarSaveSlotNetCs : public SProto
{
	TSlotNo SlotNo = 0;
	TAvatarParts Parts{};
	SAvatarSaveSlotNetCs()
	{
	}
	SAvatarSaveSlotNetCs(const TSlotNo& SlotNo_, const TAvatarParts& Parts_) : SlotNo(SlotNo_), Parts(Parts_)
	{
	}
	SAvatarSaveSlotNetCs(TSlotNo&& SlotNo_, TAvatarParts&& Parts_) : SlotNo(std::move(SlotNo_)), Parts(std::move(Parts_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> SlotNo;
		Stream_ >> Parts;
	}
	void operator << (const Value& Value_) override
	{
		Value_["SlotNo"] >> SlotNo;
		Value_["Parts"] >> Parts;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << SlotNo;
		Stream_ << Parts;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["SlotNo"] = SlotNo;
		Value_["Parts"] = Parts;
	}
	static wstring StdName(void)
	{
		return L"int8,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"SlotNo,Parts";
	}
};
struct SAvatarSaveSlotNetSc : public SProto
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
struct SAvatarActivateNetCs : public SProto
{
	TSlotNo SlotNo = 0;
	SAvatarActivateNetCs()
	{
	}
	SAvatarActivateNetCs(const TSlotNo& SlotNo_) : SlotNo(SlotNo_)
	{
	}
	SAvatarActivateNetCs(TSlotNo&& SlotNo_) : SlotNo(std::move(SlotNo_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> SlotNo;
	}
	void operator << (const Value& Value_) override
	{
		Value_["SlotNo"] >> SlotNo;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << SlotNo;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["SlotNo"] = SlotNo;
	}
	static wstring StdName(void)
	{
		return L"int8";
	}
	static wstring MemberName(void)
	{
		return L"SlotNo";
	}
};
struct SAvatarActivateNetSc : public SProto
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
struct SAvatarUpgradeNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	TID GroupID = 0;
	SAvatarUpgradeNetCs()
	{
	}
	SAvatarUpgradeNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_, const TID& GroupID_) : Time(Time_), TopazUseInfo(TopazUseInfo_), GroupID(GroupID_)
	{
	}
	SAvatarUpgradeNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_, TID&& GroupID_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_)), GroupID(std::move(GroupID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
		Stream_ >> GroupID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["GroupID"] >> GroupID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
		Stream_ << GroupID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["GroupID"] = GroupID;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data,GroupID";
	}
};
struct SAvatarUpgradeNetSc : public SProto
{
	TResources ResourceLeft{};
	TID GroupID = 0;
	system_clock::time_point CompleteTime;
	SAvatarUpgradeNetSc()
	{
	}
	SAvatarUpgradeNetSc(const TResources& ResourceLeft_, const TID& GroupID_, const system_clock::time_point& CompleteTime_) : ResourceLeft(ResourceLeft_), GroupID(GroupID_), CompleteTime(CompleteTime_)
	{
	}
	SAvatarUpgradeNetSc(TResources&& ResourceLeft_, TID&& GroupID_, system_clock::time_point&& CompleteTime_) : ResourceLeft(std::move(ResourceLeft_)), GroupID(std::move(GroupID_)), CompleteTime(std::move(CompleteTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourceLeft;
		Stream_ >> GroupID;
		Stream_ >> CompleteTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourceLeft"] >> ResourceLeft;
		Value_["GroupID"] >> GroupID;
		Value_["CompleteTime"] >> CompleteTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourceLeft;
		Stream_ << GroupID;
		Stream_ << CompleteTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourceLeft"] = ResourceLeft;
		Value_["GroupID"] = GroupID;
		Value_["CompleteTime"] = CompleteTime;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,time_point";
	}
	static wstring MemberName(void)
	{
		return L"ResourceLeft,GroupID,CompleteTime";
	}
};
struct SAvatarUpgradeCompleteNetCs : public SProto
{
	system_clock::time_point Time;
	TID GroupID = 0;
	bool UseTopaz = false;
	SAvatarUpgradeCompleteNetCs()
	{
	}
	SAvatarUpgradeCompleteNetCs(const system_clock::time_point& Time_, const TID& GroupID_, const bool& UseTopaz_) : Time(Time_), GroupID(GroupID_), UseTopaz(UseTopaz_)
	{
	}
	SAvatarUpgradeCompleteNetCs(system_clock::time_point&& Time_, TID&& GroupID_, bool&& UseTopaz_) : Time(std::move(Time_)), GroupID(std::move(GroupID_)), UseTopaz(std::move(UseTopaz_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> GroupID;
		Stream_ >> UseTopaz;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["GroupID"] >> GroupID;
		Value_["UseTopaz"] >> UseTopaz;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << GroupID;
		Stream_ << UseTopaz;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["GroupID"] = GroupID;
		Value_["UseTopaz"] = UseTopaz;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,bool";
	}
	static wstring MemberName(void)
	{
		return L"Time,GroupID,UseTopaz";
	}
};
struct SAvatarCoolEndedNetCs : public SProto
{
	system_clock::time_point Time;
	TSlotNo SlotNo = 0;
	bool UseTopaz = false;
	SAvatarCoolEndedNetCs()
	{
	}
	SAvatarCoolEndedNetCs(const system_clock::time_point& Time_, const TSlotNo& SlotNo_, const bool& UseTopaz_) : Time(Time_), SlotNo(SlotNo_), UseTopaz(UseTopaz_)
	{
	}
	SAvatarCoolEndedNetCs(system_clock::time_point&& Time_, TSlotNo&& SlotNo_, bool&& UseTopaz_) : Time(std::move(Time_)), SlotNo(std::move(SlotNo_)), UseTopaz(std::move(UseTopaz_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> SlotNo;
		Stream_ >> UseTopaz;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["SlotNo"] >> SlotNo;
		Value_["UseTopaz"] >> UseTopaz;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << SlotNo;
		Stream_ << UseTopaz;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["SlotNo"] = SlotNo;
		Value_["UseTopaz"] = UseTopaz;
	}
	static wstring StdName(void)
	{
		return L"time_point,int8,bool";
	}
	static wstring MemberName(void)
	{
		return L"Time,SlotNo,UseTopaz";
	}
};
struct SAvatarRepairDefenceNetCs : public SProto
{
	SResourceTypeData TopazUseInfo;
	SAvatarRepairDefenceNetCs()
	{
	}
	SAvatarRepairDefenceNetCs(const SResourceTypeData& TopazUseInfo_) : TopazUseInfo(TopazUseInfo_)
	{
	}
	SAvatarRepairDefenceNetCs(SResourceTypeData&& TopazUseInfo_) : TopazUseInfo(std::move(TopazUseInfo_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TopazUseInfo;
	}
	void operator << (const Value& Value_) override
	{
		TopazUseInfo << Value_["TopazUseInfo"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TopazUseInfo;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TopazUseInfo"] = TopazUseInfo;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Type,Data";
	}
};
struct SAvatarRepairDefenceNetSc : public SProto
{
	TResources ResourcesLeft{};
	SAvatarRepairDefenceNetSc()
	{
	}
	SAvatarRepairDefenceNetSc(const TResources& ResourcesLeft_) : ResourcesLeft(ResourcesLeft_)
	{
	}
	SAvatarRepairDefenceNetSc(TResources&& ResourcesLeft_) : ResourcesLeft(std::move(ResourcesLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourcesLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourcesLeft"] >> ResourcesLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourcesLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourcesLeft"] = ResourcesLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourcesLeft";
	}
};
struct SAvatarEnableDefenceNetCs : public SProto
{
	bool Enable = false;
	SAvatarEnableDefenceNetCs()
	{
	}
	SAvatarEnableDefenceNetCs(const bool& Enable_) : Enable(Enable_)
	{
	}
	SAvatarEnableDefenceNetCs(bool&& Enable_) : Enable(std::move(Enable_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Enable;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Enable"] >> Enable;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Enable;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Enable"] = Enable;
	}
	static wstring StdName(void)
	{
		return L"bool";
	}
	static wstring MemberName(void)
	{
		return L"Enable";
	}
};
struct SSingleStageCode : public SProto
{
	__int32 Area = 0;
	__int32 Group = 0;
	TID Stage = 0;
	SSingleStageCode()
	{
	}
	SSingleStageCode(const __int32& Area_, const __int32& Group_, const TID& Stage_) : Area(Area_), Group(Group_), Stage(Stage_)
	{
	}
	SSingleStageCode(__int32&& Area_, __int32&& Group_, TID&& Stage_) : Area(std::move(Area_)), Group(std::move(Group_)), Stage(std::move(Stage_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Area;
		Stream_ >> Group;
		Stream_ >> Stage;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Area"] >> Area;
		Value_["Group"] >> Group;
		Value_["Stage"] >> Stage;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Area;
		Stream_ << Group;
		Stream_ << Stage;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Area"] = Area;
		Value_["Group"] = Group;
		Value_["Stage"] = Stage;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Area,Group,Stage";
	}
};
struct SBattleSingleStartNetCs : public SSingleStageCode
{
	system_clock::time_point Time;
	SBattleSingleStartNetCs()
	{
	}
	SBattleSingleStartNetCs(const SSingleStageCode& Super_, const system_clock::time_point& Time_) : SSingleStageCode(Super_), Time(Time_)
	{
	}
	SBattleSingleStartNetCs(SSingleStageCode&& Super_, system_clock::time_point&& Time_) : SSingleStageCode(std::move(Super_)), Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,time_point";
	}
	static wstring MemberName(void)
	{
		return L"Area,Group,Stage,Time";
	}
};
struct SBattleSingleUnit : public SProto
{
	TID GroupID = 0;
	__int8 Cnt = 0;
	SBattleSingleUnit()
	{
	}
	SBattleSingleUnit(const TID& GroupID_, const __int8& Cnt_) : GroupID(GroupID_), Cnt(Cnt_)
	{
	}
	SBattleSingleUnit(TID&& GroupID_, __int8&& Cnt_) : GroupID(std::move(GroupID_)), Cnt(std::move(Cnt_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> GroupID;
		Stream_ >> Cnt;
	}
	void operator << (const Value& Value_) override
	{
		Value_["GroupID"] >> GroupID;
		Value_["Cnt"] >> Cnt;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << GroupID;
		Stream_ << Cnt;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["GroupID"] = GroupID;
		Value_["Cnt"] = Cnt;
	}
	static wstring StdName(void)
	{
		return L"int32,int8";
	}
	static wstring MemberName(void)
	{
		return L"GroupID,Cnt";
	}
};
using TIndexForce = list<__int64>;
using TIndexForces = array<TIndexForce,2>;
struct SDrop : public SProto
{
	EForceType ForceType;
	__int64 Index = 0;
	SDrop()
	{
	}
	SDrop(const EForceType& ForceType_, const __int64& Index_) : ForceType(ForceType_), Index(Index_)
	{
	}
	SDrop(EForceType&& ForceType_, __int64&& Index_) : ForceType(std::move(ForceType_)), Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int32&)ForceType;
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ForceType"] >> (__int32&)ForceType;
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int32)ForceType;
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ForceType"] = (__int32)ForceType;
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"ForceType,Index";
	}
};
using TDrops = list<SDrop>;
struct SBattleSingleUnitDropNetCs : public SProto
{
	system_clock::time_point Time;
	TDrops Drops;
	SBattleSingleUnitDropNetCs()
	{
	}
	SBattleSingleUnitDropNetCs(const system_clock::time_point& Time_, const TDrops& Drops_) : Time(Time_), Drops(Drops_)
	{
	}
	SBattleSingleUnitDropNetCs(system_clock::time_point&& Time_, TDrops&& Drops_) : Time(std::move(Time_)), Drops(std::move(Drops_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Drops;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Drops"] >> Drops;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Drops;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Drops"] = Drops;
	}
	static wstring StdName(void)
	{
		return L"time_point,{int32,int64}";
	}
	static wstring MemberName(void)
	{
		return L"Time,Drops";
	}
};
struct SBattleSingleClanUnitDropNetCs : public SProto
{
	system_clock::time_point Time;
	TDrops Drops;
	SBattleSingleClanUnitDropNetCs()
	{
	}
	SBattleSingleClanUnitDropNetCs(const system_clock::time_point& Time_, const TDrops& Drops_) : Time(Time_), Drops(Drops_)
	{
	}
	SBattleSingleClanUnitDropNetCs(system_clock::time_point&& Time_, TDrops&& Drops_) : Time(std::move(Time_)), Drops(std::move(Drops_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Drops;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Drops"] >> Drops;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Drops;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Drops"] = Drops;
	}
	static wstring StdName(void)
	{
		return L"time_point,{int32,int64}";
	}
	static wstring MemberName(void)
	{
		return L"Time,Drops";
	}
};
struct SBattleSingleAvatarDropNetCs : public SProto
{
	system_clock::time_point Time;
	SBattleSingleAvatarDropNetCs()
	{
	}
	SBattleSingleAvatarDropNetCs(const system_clock::time_point& Time_) : Time(Time_)
	{
	}
	SBattleSingleAvatarDropNetCs(system_clock::time_point&& Time_) : Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"time_point";
	}
	static wstring MemberName(void)
	{
		return L"Time";
	}
};
struct SBattleSingleResourceGotNetCs : public SProto
{
	TResources ResourcesGot{};
	SBattleSingleResourceGotNetCs()
	{
	}
	SBattleSingleResourceGotNetCs(const TResources& ResourcesGot_) : ResourcesGot(ResourcesGot_)
	{
	}
	SBattleSingleResourceGotNetCs(TResources&& ResourcesGot_) : ResourcesGot(std::move(ResourcesGot_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourcesGot;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourcesGot"] >> ResourcesGot;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourcesGot;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourcesGot"] = ResourcesGot;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourcesGot";
	}
};
struct SBattleSingleAvatarCoolTimeNetCs : public SProto
{
	__int32 CoolMilliseconds = 0;
	SBattleSingleAvatarCoolTimeNetCs()
	{
	}
	SBattleSingleAvatarCoolTimeNetCs(const __int32& CoolMilliseconds_) : CoolMilliseconds(CoolMilliseconds_)
	{
	}
	SBattleSingleAvatarCoolTimeNetCs(__int32&& CoolMilliseconds_) : CoolMilliseconds(std::move(CoolMilliseconds_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> CoolMilliseconds;
	}
	void operator << (const Value& Value_) override
	{
		Value_["CoolMilliseconds"] >> CoolMilliseconds;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << CoolMilliseconds;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["CoolMilliseconds"] = CoolMilliseconds;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"CoolMilliseconds";
	}
};
struct SBattleSingleEndNetCs : public SProto
{
	system_clock::time_point Time;
	bool Cleared = false;
	__int32 AttackAvatarCoolMilliseconds = 0;
	SBattleSingleEndNetCs()
	{
	}
	SBattleSingleEndNetCs(const system_clock::time_point& Time_, const bool& Cleared_, const __int32& AttackAvatarCoolMilliseconds_) : Time(Time_), Cleared(Cleared_), AttackAvatarCoolMilliseconds(AttackAvatarCoolMilliseconds_)
	{
	}
	SBattleSingleEndNetCs(system_clock::time_point&& Time_, bool&& Cleared_, __int32&& AttackAvatarCoolMilliseconds_) : Time(std::move(Time_)), Cleared(std::move(Cleared_)), AttackAvatarCoolMilliseconds(std::move(AttackAvatarCoolMilliseconds_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Cleared;
		Stream_ >> AttackAvatarCoolMilliseconds;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Cleared"] >> Cleared;
		Value_["AttackAvatarCoolMilliseconds"] >> AttackAvatarCoolMilliseconds;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Cleared;
		Stream_ << AttackAvatarCoolMilliseconds;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Cleared"] = Cleared;
		Value_["AttackAvatarCoolMilliseconds"] = AttackAvatarCoolMilliseconds;
	}
	static wstring StdName(void)
	{
		return L"time_point,bool,int32";
	}
	static wstring MemberName(void)
	{
		return L"Time,Cleared,AttackAvatarCoolMilliseconds";
	}
};
struct SBattleScoutNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	SBattleScoutNetCs()
	{
	}
	SBattleScoutNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_) : Time(Time_), TopazUseInfo(TopazUseInfo_)
	{
	}
	SBattleScoutNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data";
	}
};
struct SBattleScoutTargetNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	TUID TargetUID = 0;
	SBattleScoutTargetNetCs()
	{
	}
	SBattleScoutTargetNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_, const TUID& TargetUID_) : Time(Time_), TopazUseInfo(TopazUseInfo_), TargetUID(TargetUID_)
	{
	}
	SBattleScoutTargetNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_, TUID&& TargetUID_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_)), TargetUID(std::move(TargetUID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
		Stream_ >> TargetUID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["TargetUID"] >> TargetUID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
		Stream_ << TargetUID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["TargetUID"] = TargetUID;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data,TargetUID";
	}
};
struct SBattleRevengeNetCs : public SProto
{
	system_clock::time_point Time;
	TIndex ReplayIndex = 0;
	SBattleRevengeNetCs()
	{
	}
	SBattleRevengeNetCs(const system_clock::time_point& Time_, const TIndex& ReplayIndex_) : Time(Time_), ReplayIndex(ReplayIndex_)
	{
	}
	SBattleRevengeNetCs(system_clock::time_point&& Time_, TIndex&& ReplayIndex_) : Time(std::move(Time_)), ReplayIndex(std::move(ReplayIndex_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> ReplayIndex;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["ReplayIndex"] >> ReplayIndex;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << ReplayIndex;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["ReplayIndex"] = ReplayIndex;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,ReplayIndex";
	}
};
struct SBattleScoutInfoBuilding : public SBuildingBase
{
	TResources ResourcesCanGet{};
	SBattleScoutInfoBuilding()
	{
	}
	SBattleScoutInfoBuilding(const SBuildingBase& Super_, const TResources& ResourcesCanGet_) : SBuildingBase(Super_), ResourcesCanGet(ResourcesCanGet_)
	{
	}
	SBattleScoutInfoBuilding(SBuildingBase&& Super_, TResources&& ResourcesCanGet_) : SBuildingBase(std::move(Super_)), ResourcesCanGet(std::move(ResourcesCanGet_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> ResourcesCanGet;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["ResourcesCanGet"] >> ResourcesCanGet;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << ResourcesCanGet;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["ResourcesCanGet"] = ResourcesCanGet;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,int32,int32,int32,int8,int32,int32,int8,int8,time_point,bool,time_point,int64,time_point,time_point,double,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,GroupID,Level,X,Y,Mode,BulletGroupID,BulletLeft,Rotate,RotateHead,BaseTime,IsCompleted,UpgradeEndTime,DurationTicks,BeginTime,EndTime,Speed,ResourcesCanGet";
	}
};
struct SBattleScoutInfo : public SProto
{
	SBattleUserInfo Defender;
	TLevel DefenderCPLevel = 0;
	TResources ResourcesCanGet{};
	TResources ResourcesCanGetFromCollector{};
	CStream Stream_SBattleScoutCore;
	SBattleScoutInfo()
	{
	}
	SBattleScoutInfo(const SBattleUserInfo& Defender_, const TLevel& DefenderCPLevel_, const TResources& ResourcesCanGet_, const TResources& ResourcesCanGetFromCollector_, const CStream& Stream_SBattleScoutCore_) : Defender(Defender_), DefenderCPLevel(DefenderCPLevel_), ResourcesCanGet(ResourcesCanGet_), ResourcesCanGetFromCollector(ResourcesCanGetFromCollector_), Stream_SBattleScoutCore(Stream_SBattleScoutCore_)
	{
	}
	SBattleScoutInfo(SBattleUserInfo&& Defender_, TLevel&& DefenderCPLevel_, TResources&& ResourcesCanGet_, TResources&& ResourcesCanGetFromCollector_, CStream&& Stream_SBattleScoutCore_) : Defender(std::move(Defender_)), DefenderCPLevel(std::move(DefenderCPLevel_)), ResourcesCanGet(std::move(ResourcesCanGet_)), ResourcesCanGetFromCollector(std::move(ResourcesCanGetFromCollector_)), Stream_SBattleScoutCore(std::move(Stream_SBattleScoutCore_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Defender;
		Stream_ >> DefenderCPLevel;
		Stream_ >> ResourcesCanGet;
		Stream_ >> ResourcesCanGetFromCollector;
		Stream_ >> Stream_SBattleScoutCore;
	}
	void operator << (const Value& Value_) override
	{
		Defender << Value_["Defender"];
		Value_["DefenderCPLevel"] >> DefenderCPLevel;
		Value_["ResourcesCanGet"] >> ResourcesCanGet;
		Value_["ResourcesCanGetFromCollector"] >> ResourcesCanGetFromCollector;
		Value_["Stream_SBattleScoutCore"] >> Stream_SBattleScoutCore;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Defender;
		Stream_ << DefenderCPLevel;
		Stream_ << ResourcesCanGet;
		Stream_ << ResourcesCanGetFromCollector;
		Stream_ << Stream_SBattleScoutCore;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Defender"] = Defender;
		Value_["DefenderCPLevel"] = DefenderCPLevel;
		Value_["ResourcesCanGet"] = ResourcesCanGet;
		Value_["ResourcesCanGetFromCollector"] = ResourcesCanGetFromCollector;
		Value_["Stream_SBattleScoutCore"] = Stream_SBattleScoutCore;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,Exp,LeaguePoint,UID,Name,Mark,DefenderCPLevel,ResourcesCanGet,ResourcesCanGetFromCollector,Stream_SBattleScoutCore";
	}
};
struct SFrame : public SProto
{
	__int32 Main = 0;
	__int32 Sub = 0;
	SFrame()
	{
	}
	SFrame(const __int32& Main_, const __int32& Sub_) : Main(Main_), Sub(Sub_)
	{
	}
	SFrame(__int32&& Main_, __int32&& Sub_) : Main(std::move(Main_)), Sub(std::move(Sub_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Main;
		Stream_ >> Sub;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Main"] >> Main;
		Value_["Sub"] >> Sub;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Main;
		Stream_ << Sub;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Main"] = Main;
		Value_["Sub"] = Sub;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Main,Sub";
	}
};
struct SBattleAvatarAction : public SProto
{
	SFrame Frame;
	__int8 Action = 0;
	SPoint Point;
	SBattleAvatarAction()
	{
	}
	SBattleAvatarAction(const SFrame& Frame_, const __int8& Action_, const SPoint& Point_) : Frame(Frame_), Action(Action_), Point(Point_)
	{
	}
	SBattleAvatarAction(SFrame&& Frame_, __int8&& Action_, SPoint&& Point_) : Frame(std::move(Frame_)), Action(std::move(Action_)), Point(std::move(Point_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Frame;
		Stream_ >> Action;
		Stream_ >> Point;
	}
	void operator << (const Value& Value_) override
	{
		Frame << Value_["Frame"];
		Value_["Action"] >> Action;
		Point << Value_["Point"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Frame;
		Stream_ << Action;
		Stream_ << Point;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Frame"] = Frame;
		Value_["Action"] = Action;
		Value_["Point"] = Point;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int8,double,double";
	}
	static wstring MemberName(void)
	{
		return L"Main,Sub,Action,X,Y";
	}
};
struct SReplayUnit : public SProto
{
	TLevel Level = 0;
	__int32 Cnt = 0;
	SReplayUnit()
	{
	}
	SReplayUnit(const TLevel& Level_, const __int32& Cnt_) : Level(Level_), Cnt(Cnt_)
	{
	}
	SReplayUnit(TLevel&& Level_, __int32&& Cnt_) : Level(std::move(Level_)), Cnt(std::move(Cnt_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Level;
		Stream_ >> Cnt;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Level"] >> Level;
		Value_["Cnt"] >> Cnt;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Level;
		Stream_ << Cnt;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Level"] = Level;
		Value_["Cnt"] = Cnt;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Level,Cnt";
	}
};
struct SForce : public SGroupIDLevel
{
	__int64 Index = 0;
	SForce()
	{
	}
	SForce(const SGroupIDLevel& Super_, const __int64& Index_) : SGroupIDLevel(Super_), Index(Index_)
	{
	}
	SForce(SGroupIDLevel&& Super_, __int64&& Index_) : SGroupIDLevel(std::move(Super_)), Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"GroupID,Level,Index";
	}
};
using TListForce = list<SForce>;
using TListForces = array<TListForce,2>;
struct SAvatarInfo : public SProto
{
	list<TAvatarParts> Parts;
	TAvatarUpgrades Upgrades;
	SAvatarInfo()
	{
	}
	SAvatarInfo(const list<TAvatarParts>& Parts_, const TAvatarUpgrades& Upgrades_) : Parts(Parts_), Upgrades(Upgrades_)
	{
	}
	SAvatarInfo(list<TAvatarParts>&& Parts_, TAvatarUpgrades&& Upgrades_) : Parts(std::move(Parts_)), Upgrades(std::move(Upgrades_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Parts;
		Stream_ >> Upgrades;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Parts"] >> Parts;
		Value_["Upgrades"] >> Upgrades;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Parts;
		Stream_ << Upgrades;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Parts"] = Parts;
		Value_["Upgrades"] = Upgrades;
	}
	static wstring StdName(void)
	{
		return L"{int32,int32,int32,int32,int32,int32,int32,int32},{int32,int32,int32,bool,time_point}";
	}
	static wstring MemberName(void)
	{
		return L"Parts,Upgrades";
	}
};
struct SBattleCanUseInfo : public SProto
{
	SAvatarInfo AvatarInfo;
	TListForces Units{};
	TClanForces ClanUnits{};
	SBattleCanUseInfo()
	{
	}
	SBattleCanUseInfo(const SAvatarInfo& AvatarInfo_, const TListForces& Units_, const TClanForces& ClanUnits_) : AvatarInfo(AvatarInfo_), Units(Units_), ClanUnits(ClanUnits_)
	{
	}
	SBattleCanUseInfo(SAvatarInfo&& AvatarInfo_, TListForces&& Units_, TClanForces&& ClanUnits_) : AvatarInfo(std::move(AvatarInfo_)), Units(std::move(Units_)), ClanUnits(std::move(ClanUnits_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> AvatarInfo;
		Stream_ >> Units;
		Stream_ >> ClanUnits;
	}
	void operator << (const Value& Value_) override
	{
		AvatarInfo << Value_["AvatarInfo"];
		Value_["Units"] >> Units;
		Value_["ClanUnits"] >> ClanUnits;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << AvatarInfo;
		Stream_ << Units;
		Stream_ << ClanUnits;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["AvatarInfo"] = AvatarInfo;
		Value_["Units"] = Units;
		Value_["ClanUnits"] = ClanUnits;
	}
	static wstring StdName(void)
	{
		return L"{int32,int32,int32,int32,int32,int32,int32,int32},{int32,int32,int32,bool,time_point},{int32,int32,int64},{int32,int32,int64},{int64,int32,int32},{int64,int32,int32}";
	}
	static wstring MemberName(void)
	{
		return L"Parts,Upgrades,Units,ClanUnits";
	}
};
struct SBattleUsedInfo : public SProto
{
	SAvatarInfo AvatarInfo;
	TListForces Units{};
	TClanForces ClanUnits{};
	SBattleUsedInfo()
	{
	}
	SBattleUsedInfo(const SAvatarInfo& AvatarInfo_, const TListForces& Units_, const TClanForces& ClanUnits_) : AvatarInfo(AvatarInfo_), Units(Units_), ClanUnits(ClanUnits_)
	{
	}
	SBattleUsedInfo(SAvatarInfo&& AvatarInfo_, TListForces&& Units_, TClanForces&& ClanUnits_) : AvatarInfo(std::move(AvatarInfo_)), Units(std::move(Units_)), ClanUnits(std::move(ClanUnits_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> AvatarInfo;
		Stream_ >> Units;
		Stream_ >> ClanUnits;
	}
	void operator << (const Value& Value_) override
	{
		AvatarInfo << Value_["AvatarInfo"];
		Value_["Units"] >> Units;
		Value_["ClanUnits"] >> ClanUnits;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << AvatarInfo;
		Stream_ << Units;
		Stream_ << ClanUnits;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["AvatarInfo"] = AvatarInfo;
		Value_["Units"] = Units;
		Value_["ClanUnits"] = ClanUnits;
	}
	static wstring StdName(void)
	{
		return L"{int32,int32,int32,int32,int32,int32,int32,int32},{int32,int32,int32,bool,time_point},{int32,int32,int64},{int32,int32,int64},{int64,int32,int32},{int64,int32,int32}";
	}
	static wstring MemberName(void)
	{
		return L"Parts,Upgrades,Units,ClanUnits";
	}
};
struct SBattleScoutEnvObject : public SProto
{
	TID ObjectID = 0;
	SPos Pos;
	SBattleScoutEnvObject()
	{
	}
	SBattleScoutEnvObject(const TID& ObjectID_, const SPos& Pos_) : ObjectID(ObjectID_), Pos(Pos_)
	{
	}
	SBattleScoutEnvObject(TID&& ObjectID_, SPos&& Pos_) : ObjectID(std::move(ObjectID_)), Pos(std::move(Pos_))
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
using TScoutEnvObjects = list<SBattleScoutEnvObject>;
struct SBattleScoutEnvDevelop : public SBattleScoutEnvObject
{
	bool IsDeleting = false;
	SBattleScoutEnvDevelop()
	{
	}
	SBattleScoutEnvDevelop(const SBattleScoutEnvObject& Super_, const bool& IsDeleting_) : SBattleScoutEnvObject(Super_), IsDeleting(IsDeleting_)
	{
	}
	SBattleScoutEnvDevelop(SBattleScoutEnvObject&& Super_, bool&& IsDeleting_) : SBattleScoutEnvObject(std::move(Super_)), IsDeleting(std::move(IsDeleting_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> IsDeleting;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["IsDeleting"] >> IsDeleting;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << IsDeleting;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["IsDeleting"] = IsDeleting;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,bool";
	}
	static wstring MemberName(void)
	{
		return L"ObjectID,X,Y,IsDeleting";
	}
};
using TScoutEnvDevelops = list<SBattleScoutEnvDevelop>;
struct SBattleScoutCore : public SProto
{
	list<SBattleScoutInfoBuilding> Buildings;
	TScoutEnvObjects EnvObjects;
	TScoutEnvDevelops EnvDevelops;
	TClanForce ClanUnits;
	map<TID,TLevel> UnitUpgrades;
	SAvatarInfo AvatarInfo;
	bool GuardEnable = false;
	bool Used = false;
	SBattleScoutCore()
	{
	}
	SBattleScoutCore(const list<SBattleScoutInfoBuilding>& Buildings_, const TScoutEnvObjects& EnvObjects_, const TScoutEnvDevelops& EnvDevelops_, const TClanForce& ClanUnits_, const map<TID,TLevel>& UnitUpgrades_, const SAvatarInfo& AvatarInfo_, const bool& GuardEnable_, const bool& Used_) : Buildings(Buildings_), EnvObjects(EnvObjects_), EnvDevelops(EnvDevelops_), ClanUnits(ClanUnits_), UnitUpgrades(UnitUpgrades_), AvatarInfo(AvatarInfo_), GuardEnable(GuardEnable_), Used(Used_)
	{
	}
	SBattleScoutCore(list<SBattleScoutInfoBuilding>&& Buildings_, TScoutEnvObjects&& EnvObjects_, TScoutEnvDevelops&& EnvDevelops_, TClanForce&& ClanUnits_, map<TID,TLevel>&& UnitUpgrades_, SAvatarInfo&& AvatarInfo_, bool&& GuardEnable_, bool&& Used_) : Buildings(std::move(Buildings_)), EnvObjects(std::move(EnvObjects_)), EnvDevelops(std::move(EnvDevelops_)), ClanUnits(std::move(ClanUnits_)), UnitUpgrades(std::move(UnitUpgrades_)), AvatarInfo(std::move(AvatarInfo_)), GuardEnable(std::move(GuardEnable_)), Used(std::move(Used_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Buildings;
		Stream_ >> EnvObjects;
		Stream_ >> EnvDevelops;
		Stream_ >> ClanUnits;
		Stream_ >> UnitUpgrades;
		Stream_ >> AvatarInfo;
		Stream_ >> GuardEnable;
		Stream_ >> Used;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Buildings"] >> Buildings;
		Value_["EnvObjects"] >> EnvObjects;
		Value_["EnvDevelops"] >> EnvDevelops;
		Value_["ClanUnits"] >> ClanUnits;
		Value_["UnitUpgrades"] >> UnitUpgrades;
		AvatarInfo << Value_["AvatarInfo"];
		Value_["GuardEnable"] >> GuardEnable;
		Value_["Used"] >> Used;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Buildings;
		Stream_ << EnvObjects;
		Stream_ << EnvDevelops;
		Stream_ << ClanUnits;
		Stream_ << UnitUpgrades;
		Stream_ << AvatarInfo;
		Stream_ << GuardEnable;
		Stream_ << Used;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Buildings"] = Buildings;
		Value_["EnvObjects"] = EnvObjects;
		Value_["EnvDevelops"] = EnvDevelops;
		Value_["ClanUnits"] = ClanUnits;
		Value_["UnitUpgrades"] = UnitUpgrades;
		Value_["AvatarInfo"] = AvatarInfo;
		Value_["GuardEnable"] = GuardEnable;
		Value_["Used"] = Used;
	}
	static wstring StdName(void)
	{
		return L"{int64,int32,int32,int32,int32,int8,int32,int32,int8,int8,time_point,bool,time_point,int64,time_point,time_point,double,int32,int32,int32,int32,int32},{int32,int32,int32},{int32,int32,int32,bool},{int64,int32,int32},{int32,int32},{int32,int32,int32,int32,int32,int32,int32,int32},{int32,int32,int32,bool,time_point},bool,bool";
	}
	static wstring MemberName(void)
	{
		return L"Buildings,EnvObjects,EnvDevelops,ClanUnits,UnitUpgrades,Parts,Upgrades,GuardEnable,Used";
	}
};
struct SBattleScoutNetSc : public SBattleScoutInfo
{
	SLeaguePointGot LeaguePointGot;
	TResources ResourceLeft{};
	SBattleScoutNetSc()
	{
	}
	SBattleScoutNetSc(const SBattleScoutInfo& Super_, const SLeaguePointGot& LeaguePointGot_, const TResources& ResourceLeft_) : SBattleScoutInfo(Super_), LeaguePointGot(LeaguePointGot_), ResourceLeft(ResourceLeft_)
	{
	}
	SBattleScoutNetSc(SBattleScoutInfo&& Super_, SLeaguePointGot&& LeaguePointGot_, TResources&& ResourceLeft_) : SBattleScoutInfo(std::move(Super_)), LeaguePointGot(std::move(LeaguePointGot_)), ResourceLeft(std::move(ResourceLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> LeaguePointGot;
		Stream_ >> ResourceLeft;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		LeaguePointGot << Value_["LeaguePointGot"];
		Value_["ResourceLeft"] >> ResourceLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << LeaguePointGot;
		Stream_ << ResourceLeft;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["LeaguePointGot"] = LeaguePointGot;
		Value_["ResourceLeft"] = ResourceLeft;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,Exp,LeaguePoint,UID,Name,Mark,DefenderCPLevel,ResourcesCanGet,ResourcesCanGetFromCollector,Stream_SBattleScoutCore,Win,Lose,ResourceLeft";
	}
};
struct SBattleCheckPointNetCs : public SProto
{
	SFrame Frame;
	SBattleCheckPointNetCs()
	{
	}
	SBattleCheckPointNetCs(const SFrame& Frame_) : Frame(Frame_)
	{
	}
	SBattleCheckPointNetCs(SFrame&& Frame_) : Frame(std::move(Frame_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Frame;
	}
	void operator << (const Value& Value_) override
	{
		Frame << Value_["Frame"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Frame;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Frame"] = Frame;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Main,Sub";
	}
};
struct SBattleCheckPointNetSc : public SProto
{
	SFrame Frame;
	SBattleCheckPointNetSc()
	{
	}
	SBattleCheckPointNetSc(const SFrame& Frame_) : Frame(Frame_)
	{
	}
	SBattleCheckPointNetSc(SFrame&& Frame_) : Frame(std::move(Frame_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Frame;
	}
	void operator << (const Value& Value_) override
	{
		Frame << Value_["Frame"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Frame;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Frame"] = Frame;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Main,Sub";
	}
};
struct SDropMulti : public SDrop
{
	SFrame Frame;
	SPoint Point;
	SDropMulti()
	{
	}
	SDropMulti(const SDrop& Super_, const SFrame& Frame_, const SPoint& Point_) : SDrop(Super_), Frame(Frame_), Point(Point_)
	{
	}
	SDropMulti(SDrop&& Super_, SFrame&& Frame_, SPoint&& Point_) : SDrop(std::move(Super_)), Frame(std::move(Frame_)), Point(std::move(Point_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Frame;
		Stream_ >> Point;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Frame << Value_["Frame"];
		Point << Value_["Point"];
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Frame;
		Stream_ << Point;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Frame"] = Frame;
		Value_["Point"] = Point;
	}
	static wstring StdName(void)
	{
		return L"int32,int64,int32,int32,double,double";
	}
	static wstring MemberName(void)
	{
		return L"ForceType,Index,Main,Sub,X,Y";
	}
};
using TDropMultis = list<SDropMulti>;
struct SBattleUnitDropNetCs : public SProto
{
	TDropMultis Drops;
	SBattleUnitDropNetCs()
	{
	}
	SBattleUnitDropNetCs(const TDropMultis& Drops_) : Drops(Drops_)
	{
	}
	SBattleUnitDropNetCs(TDropMultis&& Drops_) : Drops(std::move(Drops_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Drops;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Drops"] >> Drops;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Drops;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Drops"] = Drops;
	}
	static wstring StdName(void)
	{
		return L"{int32,int64,int32,int32,double,double}";
	}
	static wstring MemberName(void)
	{
		return L"Drops";
	}
};
struct SBattleUnitDropOtherNetSc : public SBattleUnitDropNetCs
{
	SBattleUnitDropOtherNetSc()
	{
	}
	SBattleUnitDropOtherNetSc(const SBattleUnitDropNetCs& Super_) : SBattleUnitDropNetCs(Super_)
	{
	}
	SBattleUnitDropOtherNetSc(SBattleUnitDropNetCs&& Super_) : SBattleUnitDropNetCs(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"{int32,int64,int32,int32,double,double}";
	}
	static wstring MemberName(void)
	{
		return L"Drops";
	}
};
struct SBattleClanUnitDropNetCs : public SProto
{
	TDropMultis Drops;
	SBattleClanUnitDropNetCs()
	{
	}
	SBattleClanUnitDropNetCs(const TDropMultis& Drops_) : Drops(Drops_)
	{
	}
	SBattleClanUnitDropNetCs(TDropMultis&& Drops_) : Drops(std::move(Drops_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Drops;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Drops"] >> Drops;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Drops;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Drops"] = Drops;
	}
	static wstring StdName(void)
	{
		return L"{int32,int64,int32,int32,double,double}";
	}
	static wstring MemberName(void)
	{
		return L"Drops";
	}
};
struct SBattleClanUnitDropOtherNetSc : public SBattleClanUnitDropNetCs
{
	SBattleClanUnitDropOtherNetSc()
	{
	}
	SBattleClanUnitDropOtherNetSc(const SBattleClanUnitDropNetCs& Super_) : SBattleClanUnitDropNetCs(Super_)
	{
	}
	SBattleClanUnitDropOtherNetSc(SBattleClanUnitDropNetCs&& Super_) : SBattleClanUnitDropNetCs(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"{int32,int64,int32,int32,double,double}";
	}
	static wstring MemberName(void)
	{
		return L"Drops";
	}
};
struct SBattleAvatarActionNetCs : public SProto
{
	list<SBattleAvatarAction> Infos;
	SBattleAvatarActionNetCs()
	{
	}
	SBattleAvatarActionNetCs(const list<SBattleAvatarAction>& Infos_) : Infos(Infos_)
	{
	}
	SBattleAvatarActionNetCs(list<SBattleAvatarAction>&& Infos_) : Infos(std::move(Infos_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Infos;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Infos"] >> Infos;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Infos;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Infos"] = Infos;
	}
	static wstring StdName(void)
	{
		return L"{int32,int32,int8,double,double}";
	}
	static wstring MemberName(void)
	{
		return L"Infos";
	}
};
struct SBattleAvatarActionOtherNetSc : public SBattleAvatarActionNetCs
{
	SBattleAvatarActionOtherNetSc()
	{
	}
	SBattleAvatarActionOtherNetSc(const SBattleAvatarActionNetCs& Super_) : SBattleAvatarActionNetCs(Super_)
	{
	}
	SBattleAvatarActionOtherNetSc(SBattleAvatarActionNetCs&& Super_) : SBattleAvatarActionNetCs(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"{int32,int32,int8,double,double}";
	}
	static wstring MemberName(void)
	{
		return L"Infos";
	}
};
struct SBattlePlayInfo : public SProto
{
	list<SBattleAvatarAction> AvatarActions;
	SBattleUnitDropNetCs UnitDrops;
	SBattleClanUnitDropNetCs ClanUnitDrops;
	SBattlePlayInfo()
	{
	}
	SBattlePlayInfo(const list<SBattleAvatarAction>& AvatarActions_, const SBattleUnitDropNetCs& UnitDrops_, const SBattleClanUnitDropNetCs& ClanUnitDrops_) : AvatarActions(AvatarActions_), UnitDrops(UnitDrops_), ClanUnitDrops(ClanUnitDrops_)
	{
	}
	SBattlePlayInfo(list<SBattleAvatarAction>&& AvatarActions_, SBattleUnitDropNetCs&& UnitDrops_, SBattleClanUnitDropNetCs&& ClanUnitDrops_) : AvatarActions(std::move(AvatarActions_)), UnitDrops(std::move(UnitDrops_)), ClanUnitDrops(std::move(ClanUnitDrops_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> AvatarActions;
		Stream_ >> UnitDrops;
		Stream_ >> ClanUnitDrops;
	}
	void operator << (const Value& Value_) override
	{
		Value_["AvatarActions"] >> AvatarActions;
		UnitDrops << Value_["UnitDrops"];
		ClanUnitDrops << Value_["ClanUnitDrops"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << AvatarActions;
		Stream_ << UnitDrops;
		Stream_ << ClanUnitDrops;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["AvatarActions"] = AvatarActions;
		Value_["UnitDrops"] = UnitDrops;
		Value_["ClanUnitDrops"] = ClanUnitDrops;
	}
	static wstring StdName(void)
	{
		return L"{int32,int32,int8,double,double},{int32,int64,int32,int32,double,double},{int32,int64,int32,int32,double,double}";
	}
	static wstring MemberName(void)
	{
		return L"AvatarActions,Drops,Drops";
	}
};
struct SBattleInfoCore : public SBattleScoutInfo
{
	CStream Stream_SBattleCanUseInfo;
	CStream Stream_SBattlePlayInfo;
	SBattleInfoCore()
	{
	}
	SBattleInfoCore(const SBattleScoutInfo& Super_, const CStream& Stream_SBattleCanUseInfo_, const CStream& Stream_SBattlePlayInfo_) : SBattleScoutInfo(Super_), Stream_SBattleCanUseInfo(Stream_SBattleCanUseInfo_), Stream_SBattlePlayInfo(Stream_SBattlePlayInfo_)
	{
	}
	SBattleInfoCore(SBattleScoutInfo&& Super_, CStream&& Stream_SBattleCanUseInfo_, CStream&& Stream_SBattlePlayInfo_) : SBattleScoutInfo(std::move(Super_)), Stream_SBattleCanUseInfo(std::move(Stream_SBattleCanUseInfo_)), Stream_SBattlePlayInfo(std::move(Stream_SBattlePlayInfo_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Stream_SBattleCanUseInfo;
		Stream_ >> Stream_SBattlePlayInfo;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Stream_SBattleCanUseInfo"] >> Stream_SBattleCanUseInfo;
		Value_["Stream_SBattlePlayInfo"] >> Stream_SBattlePlayInfo;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Stream_SBattleCanUseInfo;
		Stream_ << Stream_SBattlePlayInfo;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Stream_SBattleCanUseInfo"] = Stream_SBattleCanUseInfo;
		Value_["Stream_SBattlePlayInfo"] = Stream_SBattlePlayInfo;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream,stream,stream";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,Exp,LeaguePoint,UID,Name,Mark,DefenderCPLevel,ResourcesCanGet,ResourcesCanGetFromCollector,Stream_SBattleScoutCore,Stream_SBattleCanUseInfo,Stream_SBattlePlayInfo";
	}
};
struct SBattleInfoBase : public SBattleInfoCore
{
	system_clock::time_point BattleStartTime;
	SFrame EndFrame;
	SBattleInfoBase()
	{
	}
	SBattleInfoBase(const SBattleInfoCore& Super_, const system_clock::time_point& BattleStartTime_, const SFrame& EndFrame_) : SBattleInfoCore(Super_), BattleStartTime(BattleStartTime_), EndFrame(EndFrame_)
	{
	}
	SBattleInfoBase(SBattleInfoCore&& Super_, system_clock::time_point&& BattleStartTime_, SFrame&& EndFrame_) : SBattleInfoCore(std::move(Super_)), BattleStartTime(std::move(BattleStartTime_)), EndFrame(std::move(EndFrame_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> BattleStartTime;
		Stream_ >> EndFrame;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["BattleStartTime"] >> BattleStartTime;
		EndFrame << Value_["EndFrame"];
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << BattleStartTime;
		Stream_ << EndFrame;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["BattleStartTime"] = BattleStartTime;
		Value_["EndFrame"] = EndFrame;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream,stream,stream,time_point,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,Exp,LeaguePoint,UID,Name,Mark,DefenderCPLevel,ResourcesCanGet,ResourcesCanGetFromCollector,Stream_SBattleScoutCore,Stream_SBattleCanUseInfo,Stream_SBattlePlayInfo,BattleStartTime,Main,Sub";
	}
};
struct SBattleInfoNetSc : public SBattleInfoBase
{
	SBattleInfoNetSc()
	{
	}
	SBattleInfoNetSc(const SBattleInfoBase& Super_) : SBattleInfoBase(Super_)
	{
	}
	SBattleInfoNetSc(SBattleInfoBase&& Super_) : SBattleInfoBase(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream,stream,stream,time_point,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,Exp,LeaguePoint,UID,Name,Mark,DefenderCPLevel,ResourcesCanGet,ResourcesCanGetFromCollector,Stream_SBattleScoutCore,Stream_SBattleCanUseInfo,Stream_SBattlePlayInfo,BattleStartTime,Main,Sub";
	}
};
struct SUnderAttackNetSc : public SBattleInfoCore
{
	SBattleUserInfo Attacker;
	SFrame Frame;
	SLeaguePointGot LeaguePointGot;
	SUnderAttackNetSc()
	{
	}
	SUnderAttackNetSc(const SBattleInfoCore& Super_, const SBattleUserInfo& Attacker_, const SFrame& Frame_, const SLeaguePointGot& LeaguePointGot_) : SBattleInfoCore(Super_), Attacker(Attacker_), Frame(Frame_), LeaguePointGot(LeaguePointGot_)
	{
	}
	SUnderAttackNetSc(SBattleInfoCore&& Super_, SBattleUserInfo&& Attacker_, SFrame&& Frame_, SLeaguePointGot&& LeaguePointGot_) : SBattleInfoCore(std::move(Super_)), Attacker(std::move(Attacker_)), Frame(std::move(Frame_)), LeaguePointGot(std::move(LeaguePointGot_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Attacker;
		Stream_ >> Frame;
		Stream_ >> LeaguePointGot;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Attacker << Value_["Attacker"];
		Frame << Value_["Frame"];
		LeaguePointGot << Value_["LeaguePointGot"];
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Attacker;
		Stream_ << Frame;
		Stream_ << LeaguePointGot;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Attacker"] = Attacker;
		Value_["Frame"] = Frame;
		Value_["LeaguePointGot"] = LeaguePointGot;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream,stream,stream,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,Exp,LeaguePoint,UID,Name,Mark,DefenderCPLevel,ResourcesCanGet,ResourcesCanGetFromCollector,Stream_SBattleScoutCore,Stream_SBattleCanUseInfo,Stream_SBattlePlayInfo,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,Main,Sub,Win,Lose";
	}
};
struct SBattleEndNetCs : public SProto
{
	SFrame EndFrame;
	SBattleEndNetCs()
	{
	}
	SBattleEndNetCs(const SFrame& EndFrame_) : EndFrame(EndFrame_)
	{
	}
	SBattleEndNetCs(SFrame&& EndFrame_) : EndFrame(std::move(EndFrame_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> EndFrame;
	}
	void operator << (const Value& Value_) override
	{
		EndFrame << Value_["EndFrame"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << EndFrame;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["EndFrame"] = EndFrame;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Main,Sub";
	}
};
struct SBattleEndedNetSc : public SBattleEndNetCs
{
	SBattleEndedNetSc()
	{
	}
	SBattleEndedNetSc(const SBattleEndNetCs& Super_) : SBattleEndNetCs(Super_)
	{
	}
	SBattleEndedNetSc(SBattleEndNetCs&& Super_) : SBattleEndNetCs(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Main,Sub";
	}
};
using TUsedBuildings = map<TIndex,__int32>;
struct SBattleFinishNetCs : public SProto
{
	bool IsCPDestroyed = false;
	TResources ResourcesGotFromStorage{};
	TResources ResourcesGotFromCollector{};
	map<TIndex,TResource> ResourcesGotFromCollectorDetail;
	array<TUsedBuildings,2> UsedBuildings{};
	__int32 Percentage = 0;
	bool DefenceAvatarUsed = false;
	bool DefenderClanUnitUsed = false;
	__int32 AttackAvatarCoolMilliseconds = 0;
	SFrame EndFrame;
	SBattleFinishNetCs()
	{
	}
	SBattleFinishNetCs(const bool& IsCPDestroyed_, const TResources& ResourcesGotFromStorage_, const TResources& ResourcesGotFromCollector_, const map<TIndex,TResource>& ResourcesGotFromCollectorDetail_, const array<TUsedBuildings,2>& UsedBuildings_, const __int32& Percentage_, const bool& DefenceAvatarUsed_, const bool& DefenderClanUnitUsed_, const __int32& AttackAvatarCoolMilliseconds_, const SFrame& EndFrame_) : IsCPDestroyed(IsCPDestroyed_), ResourcesGotFromStorage(ResourcesGotFromStorage_), ResourcesGotFromCollector(ResourcesGotFromCollector_), ResourcesGotFromCollectorDetail(ResourcesGotFromCollectorDetail_), UsedBuildings(UsedBuildings_), Percentage(Percentage_), DefenceAvatarUsed(DefenceAvatarUsed_), DefenderClanUnitUsed(DefenderClanUnitUsed_), AttackAvatarCoolMilliseconds(AttackAvatarCoolMilliseconds_), EndFrame(EndFrame_)
	{
	}
	SBattleFinishNetCs(bool&& IsCPDestroyed_, TResources&& ResourcesGotFromStorage_, TResources&& ResourcesGotFromCollector_, map<TIndex,TResource>&& ResourcesGotFromCollectorDetail_, array<TUsedBuildings,2>&& UsedBuildings_, __int32&& Percentage_, bool&& DefenceAvatarUsed_, bool&& DefenderClanUnitUsed_, __int32&& AttackAvatarCoolMilliseconds_, SFrame&& EndFrame_) : IsCPDestroyed(std::move(IsCPDestroyed_)), ResourcesGotFromStorage(std::move(ResourcesGotFromStorage_)), ResourcesGotFromCollector(std::move(ResourcesGotFromCollector_)), ResourcesGotFromCollectorDetail(std::move(ResourcesGotFromCollectorDetail_)), UsedBuildings(std::move(UsedBuildings_)), Percentage(std::move(Percentage_)), DefenceAvatarUsed(std::move(DefenceAvatarUsed_)), DefenderClanUnitUsed(std::move(DefenderClanUnitUsed_)), AttackAvatarCoolMilliseconds(std::move(AttackAvatarCoolMilliseconds_)), EndFrame(std::move(EndFrame_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> IsCPDestroyed;
		Stream_ >> ResourcesGotFromStorage;
		Stream_ >> ResourcesGotFromCollector;
		Stream_ >> ResourcesGotFromCollectorDetail;
		Stream_ >> UsedBuildings;
		Stream_ >> Percentage;
		Stream_ >> DefenceAvatarUsed;
		Stream_ >> DefenderClanUnitUsed;
		Stream_ >> AttackAvatarCoolMilliseconds;
		Stream_ >> EndFrame;
	}
	void operator << (const Value& Value_) override
	{
		Value_["IsCPDestroyed"] >> IsCPDestroyed;
		Value_["ResourcesGotFromStorage"] >> ResourcesGotFromStorage;
		Value_["ResourcesGotFromCollector"] >> ResourcesGotFromCollector;
		Value_["ResourcesGotFromCollectorDetail"] >> ResourcesGotFromCollectorDetail;
		Value_["UsedBuildings"] >> UsedBuildings;
		Value_["Percentage"] >> Percentage;
		Value_["DefenceAvatarUsed"] >> DefenceAvatarUsed;
		Value_["DefenderClanUnitUsed"] >> DefenderClanUnitUsed;
		Value_["AttackAvatarCoolMilliseconds"] >> AttackAvatarCoolMilliseconds;
		EndFrame << Value_["EndFrame"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << IsCPDestroyed;
		Stream_ << ResourcesGotFromStorage;
		Stream_ << ResourcesGotFromCollector;
		Stream_ << ResourcesGotFromCollectorDetail;
		Stream_ << UsedBuildings;
		Stream_ << Percentage;
		Stream_ << DefenceAvatarUsed;
		Stream_ << DefenderClanUnitUsed;
		Stream_ << AttackAvatarCoolMilliseconds;
		Stream_ << EndFrame;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["IsCPDestroyed"] = IsCPDestroyed;
		Value_["ResourcesGotFromStorage"] = ResourcesGotFromStorage;
		Value_["ResourcesGotFromCollector"] = ResourcesGotFromCollector;
		Value_["ResourcesGotFromCollectorDetail"] = ResourcesGotFromCollectorDetail;
		Value_["UsedBuildings"] = UsedBuildings;
		Value_["Percentage"] = Percentage;
		Value_["DefenceAvatarUsed"] = DefenceAvatarUsed;
		Value_["DefenderClanUnitUsed"] = DefenderClanUnitUsed;
		Value_["AttackAvatarCoolMilliseconds"] = AttackAvatarCoolMilliseconds;
		Value_["EndFrame"] = EndFrame;
	}
	static wstring StdName(void)
	{
		return L"bool,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,{int64,int32},{int64,int32},{int64,int32},int32,bool,bool,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"IsCPDestroyed,ResourcesGotFromStorage,ResourcesGotFromCollector,ResourcesGotFromCollectorDetail,UsedBuildings,Percentage,DefenceAvatarUsed,DefenderClanUnitUsed,AttackAvatarCoolMilliseconds,Main,Sub";
	}
};
struct SInvitation : public SProto
{
	SUserBrief FromUser;
	SClanBrief FromClan;
	__int32 PassCode = 0;
	wstring Text;
	system_clock::time_point Time;
	SInvitation()
	{
	}
	SInvitation(const SUserBrief& FromUser_, const SClanBrief& FromClan_, const __int32& PassCode_, const wstring& Text_, const system_clock::time_point& Time_) : FromUser(FromUser_), FromClan(FromClan_), PassCode(PassCode_), Text(Text_), Time(Time_)
	{
	}
	SInvitation(SUserBrief&& FromUser_, SClanBrief&& FromClan_, __int32&& PassCode_, wstring&& Text_, system_clock::time_point&& Time_) : FromUser(std::move(FromUser_)), FromClan(std::move(FromClan_)), PassCode(std::move(PassCode_)), Text(std::move(Text_)), Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> FromUser;
		Stream_ >> FromClan;
		Stream_ >> PassCode;
		Stream_ >> Text;
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		FromUser << Value_["FromUser"];
		FromClan << Value_["FromClan"];
		Value_["PassCode"] >> PassCode;
		Value_["Text"] >> Text;
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << FromUser;
		Stream_ << FromClan;
		Stream_ << PassCode;
		Stream_ << Text;
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["FromUser"] = FromUser;
		Value_["FromClan"] = FromClan;
		Value_["PassCode"] = PassCode;
		Value_["Text"] = Text;
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int64,wstring,int32,wstring,int32,wstring,time_point";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Rank,UID,Name,Rank,Mark,PassCode,Text,Time";
	}
};
using TInvitations = list<SInvitation>;
using TClanBookMarks = set<TUID>;
struct SUserInfoSubNetSc : public SProto
{
	list<system_clock::time_point> LastLoginTimes;
	list<SReplay> AttackReplays;
	list<SReplayDefence> DefenceReplays;
	TInvitations Invitations;
	TMails Mails;
	TClanBookMarks ClanBookMarks;
	SUserInfoSubNetSc()
	{
	}
	SUserInfoSubNetSc(const list<system_clock::time_point>& LastLoginTimes_, const list<SReplay>& AttackReplays_, const list<SReplayDefence>& DefenceReplays_, const TInvitations& Invitations_, const TMails& Mails_, const TClanBookMarks& ClanBookMarks_) : LastLoginTimes(LastLoginTimes_), AttackReplays(AttackReplays_), DefenceReplays(DefenceReplays_), Invitations(Invitations_), Mails(Mails_), ClanBookMarks(ClanBookMarks_)
	{
	}
	SUserInfoSubNetSc(list<system_clock::time_point>&& LastLoginTimes_, list<SReplay>&& AttackReplays_, list<SReplayDefence>&& DefenceReplays_, TInvitations&& Invitations_, TMails&& Mails_, TClanBookMarks&& ClanBookMarks_) : LastLoginTimes(std::move(LastLoginTimes_)), AttackReplays(std::move(AttackReplays_)), DefenceReplays(std::move(DefenceReplays_)), Invitations(std::move(Invitations_)), Mails(std::move(Mails_)), ClanBookMarks(std::move(ClanBookMarks_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> LastLoginTimes;
		Stream_ >> AttackReplays;
		Stream_ >> DefenceReplays;
		Stream_ >> Invitations;
		Stream_ >> Mails;
		Stream_ >> ClanBookMarks;
	}
	void operator << (const Value& Value_) override
	{
		Value_["LastLoginTimes"] >> LastLoginTimes;
		Value_["AttackReplays"] >> AttackReplays;
		Value_["DefenceReplays"] >> DefenceReplays;
		Value_["Invitations"] >> Invitations;
		Value_["Mails"] >> Mails;
		Value_["ClanBookMarks"] >> ClanBookMarks;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << LastLoginTimes;
		Stream_ << AttackReplays;
		Stream_ << DefenceReplays;
		Stream_ << Invitations;
		Stream_ << Mails;
		Stream_ << ClanBookMarks;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["LastLoginTimes"] = LastLoginTimes;
		Value_["AttackReplays"] = AttackReplays;
		Value_["DefenceReplays"] = DefenceReplays;
		Value_["Invitations"] = Invitations;
		Value_["Mails"] = Mails;
		Value_["ClanBookMarks"] = ClanBookMarks;
	}
	static wstring StdName(void)
	{
		return L"{time_point},{int64,int64,wstring,int32,int32,int64,wstring,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,bool,int32,int32,int32,int32,int32,int32,time_point,stream},{int64,int64,wstring,int32,int32,int64,wstring,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,bool,int32,int32,int32,int32,int32,int32,time_point,stream,bool},{int64,wstring,int32,int64,wstring,int32,wstring,int32,wstring,time_point},{int64,time_point,int64,wstring,int32,int64,wstring,int32,wstring,wstring,int32,stream},{int64}";
	}
	static wstring MemberName(void)
	{
		return L"LastLoginTimes,AttackReplays,DefenceReplays,Invitations,Mails,ClanBookMarks";
	}
};
struct SReplayLoadAttackNetCs : public SProto
{
	TIndex Index = 0;
	SReplayLoadAttackNetCs()
	{
	}
	SReplayLoadAttackNetCs(const TIndex& Index_) : Index(Index_)
	{
	}
	SReplayLoadAttackNetCs(TIndex&& Index_) : Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"Index";
	}
};
struct SReplayAvailableUnit : public SProto
{
	TID GroupID = 0;
	TLevel Level = 0;
	__int32 Cnt = 0;
	SReplayAvailableUnit()
	{
	}
	SReplayAvailableUnit(const TID& GroupID_, const TLevel& Level_, const __int32& Cnt_) : GroupID(GroupID_), Level(Level_), Cnt(Cnt_)
	{
	}
	SReplayAvailableUnit(TID&& GroupID_, TLevel&& Level_, __int32&& Cnt_) : GroupID(std::move(GroupID_)), Level(std::move(Level_)), Cnt(std::move(Cnt_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> GroupID;
		Stream_ >> Level;
		Stream_ >> Cnt;
	}
	void operator << (const Value& Value_) override
	{
		Value_["GroupID"] >> GroupID;
		Value_["Level"] >> Level;
		Value_["Cnt"] >> Cnt;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << GroupID;
		Stream_ << Level;
		Stream_ << Cnt;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["GroupID"] = GroupID;
		Value_["Level"] = Level;
		Value_["Cnt"] = Cnt;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"GroupID,Level,Cnt";
	}
};
struct SReplayAvailableUnits : public SProto
{
	list<SReplayAvailableUnit> Units;
	SReplayAvailableUnits()
	{
	}
	SReplayAvailableUnits(const list<SReplayAvailableUnit>& Units_) : Units(Units_)
	{
	}
	SReplayAvailableUnits(list<SReplayAvailableUnit>&& Units_) : Units(std::move(Units_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Units;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Units"] >> Units;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Units;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Units"] = Units;
	}
	static wstring StdName(void)
	{
		return L"{int32,int32,int32}";
	}
	static wstring MemberName(void)
	{
		return L"Units";
	}
};
struct SReplayLoadAttackNetSc : public SProto
{
	list<SBattleInfoBase> Datas;
	SReplayLoadAttackNetSc()
	{
	}
	SReplayLoadAttackNetSc(const list<SBattleInfoBase>& Datas_) : Datas(Datas_)
	{
	}
	SReplayLoadAttackNetSc(list<SBattleInfoBase>&& Datas_) : Datas(std::move(Datas_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Datas;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Datas"] >> Datas;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Datas;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Datas"] = Datas;
	}
	static wstring StdName(void)
	{
		return L"{int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream,stream,stream,time_point,int32,int32}";
	}
	static wstring MemberName(void)
	{
		return L"Datas";
	}
};
struct SReplayLoadDefenceNetCs : public SProto
{
	TIndex Index = 0;
	SReplayLoadDefenceNetCs()
	{
	}
	SReplayLoadDefenceNetCs(const TIndex& Index_) : Index(Index_)
	{
	}
	SReplayLoadDefenceNetCs(TIndex&& Index_) : Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"Index";
	}
};
struct SReplayLoadDefenceNetSc : public SProto
{
	list<SBattleInfoBase> Datas;
	SReplayLoadDefenceNetSc()
	{
	}
	SReplayLoadDefenceNetSc(const list<SBattleInfoBase>& Datas_) : Datas(Datas_)
	{
	}
	SReplayLoadDefenceNetSc(list<SBattleInfoBase>&& Datas_) : Datas(std::move(Datas_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Datas;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Datas"] >> Datas;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Datas;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Datas"] = Datas;
	}
	static wstring StdName(void)
	{
		return L"{int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream,stream,stream,time_point,int32,int32}";
	}
	static wstring MemberName(void)
	{
		return L"Datas";
	}
};
struct SReplayAttackAddedNetSc : public SReplay
{
	SReplayAttackAddedNetSc()
	{
	}
	SReplayAttackAddedNetSc(const SReplay& Super_) : SReplay(Super_)
	{
	}
	SReplayAttackAddedNetSc(SReplay&& Super_) : SReplay(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"int64,int64,wstring,int32,int32,int64,wstring,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,bool,int32,int32,int32,int32,int32,int32,time_point,stream";
	}
	static wstring MemberName(void)
	{
		return L"Index,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,Win,Lose,Win,Lose,Percentage,IsCPDestroyed,ResourcesGotLoss,LeaguePointReached,BattleStartTime,Stream_SBattleUsedInfo";
	}
};
struct SChatNetCs : public SProto
{
	wstring Msg;
	SChatNetCs()
	{
	}
	SChatNetCs(const wstring& Msg_) : Msg(Msg_)
	{
	}
	SChatNetCs(wstring&& Msg_) : Msg(std::move(Msg_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Msg;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Msg"] >> Msg;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Msg;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Msg"] = Msg;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"Msg";
	}
};
struct SChatUser : public SProto
{
	TUID UID = 0;
	wstring Nick;
	TID LeagueID = 0;
	SClanCore Clan;
	SChatUser()
	{
	}
	SChatUser(const TUID& UID_, const wstring& Nick_, const TID& LeagueID_, const SClanCore& Clan_) : UID(UID_), Nick(Nick_), LeagueID(LeagueID_), Clan(Clan_)
	{
	}
	SChatUser(TUID&& UID_, wstring&& Nick_, TID&& LeagueID_, SClanCore&& Clan_) : UID(std::move(UID_)), Nick(std::move(Nick_)), LeagueID(std::move(LeagueID_)), Clan(std::move(Clan_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
		Stream_ >> Nick;
		Stream_ >> LeagueID;
		Stream_ >> Clan;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
		Value_["Nick"] >> Nick;
		Value_["LeagueID"] >> LeagueID;
		Clan << Value_["Clan"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
		Stream_ << Nick;
		Stream_ << LeagueID;
		Stream_ << Clan;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
		Value_["Nick"] = Nick;
		Value_["LeagueID"] = LeagueID;
		Value_["Clan"] = Clan;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int64,wstring,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,LeagueID,UID,Name,Mark";
	}
};
struct SChatNetSc : public SProto
{
	SChatUser User;
	wstring Msg;
	SChatNetSc()
	{
	}
	SChatNetSc(const SChatUser& User_, const wstring& Msg_) : User(User_), Msg(Msg_)
	{
	}
	SChatNetSc(SChatUser&& User_, wstring&& Msg_) : User(std::move(User_)), Msg(std::move(Msg_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> User;
		Stream_ >> Msg;
	}
	void operator << (const Value& Value_) override
	{
		User << Value_["User"];
		Value_["Msg"] >> Msg;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << User;
		Stream_ << Msg;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["User"] = User;
		Value_["Msg"] = Msg;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int64,wstring,wstring,wstring";
	}
	static wstring MemberName(void)
	{
		return L"UID,Nick,LeagueID,UID,Name,Mark,Msg";
	}
};
struct SResourceLeftNetSc : public SProto
{
	TResources ResourceLeft{};
	SResourceLeftNetSc()
	{
	}
	SResourceLeftNetSc(const TResources& ResourceLeft_) : ResourceLeft(ResourceLeft_)
	{
	}
	SResourceLeftNetSc(TResources&& ResourceLeft_) : ResourceLeft(std::move(ResourceLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourceLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourceLeft"] >> ResourceLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourceLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourceLeft"] = ResourceLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourceLeft";
	}
};
struct SUserExpNetSc : public SProto
{
	TExp Exp = 0;
	SUserExpNetSc()
	{
	}
	SUserExpNetSc(const TExp& Exp_) : Exp(Exp_)
	{
	}
	SUserExpNetSc(TExp&& Exp_) : Exp(std::move(Exp_))
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
struct SClanCastleCoolEndWithTopazNetCs : public SProto
{
	system_clock::time_point Time;
	SClanCastleCoolEndWithTopazNetCs()
	{
	}
	SClanCastleCoolEndWithTopazNetCs(const system_clock::time_point& Time_) : Time(Time_)
	{
	}
	SClanCastleCoolEndWithTopazNetCs(system_clock::time_point&& Time_) : Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"time_point";
	}
	static wstring MemberName(void)
	{
		return L"Time";
	}
};
struct SClanCastleCoolEndWithTopazNetSc : public SProto
{
	TResource TopazLeft = 0;
	system_clock::time_point CoolEndTime;
	SClanCastleCoolEndWithTopazNetSc()
	{
	}
	SClanCastleCoolEndWithTopazNetSc(const TResource& TopazLeft_, const system_clock::time_point& CoolEndTime_) : TopazLeft(TopazLeft_), CoolEndTime(CoolEndTime_)
	{
	}
	SClanCastleCoolEndWithTopazNetSc(TResource&& TopazLeft_, system_clock::time_point&& CoolEndTime_) : TopazLeft(std::move(TopazLeft_)), CoolEndTime(std::move(CoolEndTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TopazLeft;
		Stream_ >> CoolEndTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["TopazLeft"] >> TopazLeft;
		Value_["CoolEndTime"] >> CoolEndTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TopazLeft;
		Stream_ << CoolEndTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TopazLeft"] = TopazLeft;
		Value_["CoolEndTime"] = CoolEndTime;
	}
	static wstring StdName(void)
	{
		return L"int32,time_point";
	}
	static wstring MemberName(void)
	{
		return L"TopazLeft,CoolEndTime";
	}
};
struct SClanCastleDelUnitNetCs : public SProto
{
	TIndexForces Deleted{};
	SClanCastleDelUnitNetCs()
	{
	}
	SClanCastleDelUnitNetCs(const TIndexForces& Deleted_) : Deleted(Deleted_)
	{
	}
	SClanCastleDelUnitNetCs(TIndexForces&& Deleted_) : Deleted(std::move(Deleted_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Deleted;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Deleted"] >> Deleted;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Deleted;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Deleted"] = Deleted;
	}
	static wstring StdName(void)
	{
		return L"{int64},{int64}";
	}
	static wstring MemberName(void)
	{
		return L"Deleted";
	}
};
struct SEnvObjectDelNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	TIndex Index = 0;
	SEnvObjectDelNetCs()
	{
	}
	SEnvObjectDelNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_, const TIndex& Index_) : Time(Time_), TopazUseInfo(TopazUseInfo_), Index(Index_)
	{
	}
	SEnvObjectDelNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_, TIndex&& Index_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_)), Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data,Index";
	}
};
struct SEnvObjectDelNetSc : public SProto
{
	TResources Resources{};
	SEnvObjectDelNetSc()
	{
	}
	SEnvObjectDelNetSc(const TResources& Resources_) : Resources(Resources_)
	{
	}
	SEnvObjectDelNetSc(TResources&& Resources_) : Resources(std::move(Resources_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Resources;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Resources"] >> Resources;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Resources;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Resources"] = Resources;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Resources";
	}
};
struct SEnvObjectDelCancelNetCs : public SProto
{
	TIndex Index = 0;
	SEnvObjectDelCancelNetCs()
	{
	}
	SEnvObjectDelCancelNetCs(const TIndex& Index_) : Index(Index_)
	{
	}
	SEnvObjectDelCancelNetCs(TIndex&& Index_) : Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"Index";
	}
};
struct SEnvObjectDelCancelNetSc : public SProto
{
	TResources ResourcesLeft{};
	SEnvObjectDelCancelNetSc()
	{
	}
	SEnvObjectDelCancelNetSc(const TResources& ResourcesLeft_) : ResourcesLeft(ResourcesLeft_)
	{
	}
	SEnvObjectDelCancelNetSc(TResources&& ResourcesLeft_) : ResourcesLeft(std::move(ResourcesLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourcesLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourcesLeft"] >> ResourcesLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourcesLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourcesLeft"] = ResourcesLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourcesLeft";
	}
};
struct SEnvObjectDelCompleteNetCs : public SProto
{
	system_clock::time_point Time;
	TIndex Index = 0;
	bool UseTopaz = false;
	SEnvObjectDelCompleteNetCs()
	{
	}
	SEnvObjectDelCompleteNetCs(const system_clock::time_point& Time_, const TIndex& Index_, const bool& UseTopaz_) : Time(Time_), Index(Index_), UseTopaz(UseTopaz_)
	{
	}
	SEnvObjectDelCompleteNetCs(system_clock::time_point&& Time_, TIndex&& Index_, bool&& UseTopaz_) : Time(std::move(Time_)), Index(std::move(Index_)), UseTopaz(std::move(UseTopaz_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Index;
		Stream_ >> UseTopaz;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Index"] >> Index;
		Value_["UseTopaz"] >> UseTopaz;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Index;
		Stream_ << UseTopaz;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Index"] = Index;
		Value_["UseTopaz"] = UseTopaz;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,bool";
	}
	static wstring MemberName(void)
	{
		return L"Time,Index,UseTopaz";
	}
};
struct SEnvObjectDelCompleteNetSc : public SProto
{
	TIndex Index = 0;
	TResources ResourcesLeft{};
	TResources Reward{};
	TExp ExpLeft = 0;
	SEnvObjectDelCompleteNetSc()
	{
	}
	SEnvObjectDelCompleteNetSc(const TIndex& Index_, const TResources& ResourcesLeft_, const TResources& Reward_, const TExp& ExpLeft_) : Index(Index_), ResourcesLeft(ResourcesLeft_), Reward(Reward_), ExpLeft(ExpLeft_)
	{
	}
	SEnvObjectDelCompleteNetSc(TIndex&& Index_, TResources&& ResourcesLeft_, TResources&& Reward_, TExp&& ExpLeft_) : Index(std::move(Index_)), ResourcesLeft(std::move(ResourcesLeft_)), Reward(std::move(Reward_)), ExpLeft(std::move(ExpLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> ResourcesLeft;
		Stream_ >> Reward;
		Stream_ >> ExpLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["ResourcesLeft"] >> ResourcesLeft;
		Value_["Reward"] >> Reward;
		Value_["ExpLeft"] >> ExpLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << ResourcesLeft;
		Stream_ << Reward;
		Stream_ << ExpLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["ResourcesLeft"] = ResourcesLeft;
		Value_["Reward"] = Reward;
		Value_["ExpLeft"] = ExpLeft;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,ResourcesLeft,Reward,ExpLeft";
	}
};
struct SEnvDevelopDelNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	TIndex Index = 0;
	SEnvDevelopDelNetCs()
	{
	}
	SEnvDevelopDelNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_, const TIndex& Index_) : Time(Time_), TopazUseInfo(TopazUseInfo_), Index(Index_)
	{
	}
	SEnvDevelopDelNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_, TIndex&& Index_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_)), Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data,Index";
	}
};
struct SEnvDevelopDelNetSc : public SProto
{
	TResources Resources{};
	SEnvDevelopDelNetSc()
	{
	}
	SEnvDevelopDelNetSc(const TResources& Resources_) : Resources(Resources_)
	{
	}
	SEnvDevelopDelNetSc(TResources&& Resources_) : Resources(std::move(Resources_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Resources;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Resources"] >> Resources;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Resources;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Resources"] = Resources;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Resources";
	}
};
struct SEnvDevelopDelCancelNetCs : public SProto
{
	TIndex Index = 0;
	SEnvDevelopDelCancelNetCs()
	{
	}
	SEnvDevelopDelCancelNetCs(const TIndex& Index_) : Index(Index_)
	{
	}
	SEnvDevelopDelCancelNetCs(TIndex&& Index_) : Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"Index";
	}
};
struct SEnvDevelopDelCancelNetSc : public SProto
{
	TResources ResourcesLeft{};
	SEnvDevelopDelCancelNetSc()
	{
	}
	SEnvDevelopDelCancelNetSc(const TResources& ResourcesLeft_) : ResourcesLeft(ResourcesLeft_)
	{
	}
	SEnvDevelopDelCancelNetSc(TResources&& ResourcesLeft_) : ResourcesLeft(std::move(ResourcesLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourcesLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourcesLeft"] >> ResourcesLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourcesLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourcesLeft"] = ResourcesLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourcesLeft";
	}
};
struct SEnvDevelopDelCompleteNetCs : public SProto
{
	system_clock::time_point Time;
	TIndex Index = 0;
	bool UseTopaz = false;
	SEnvDevelopDelCompleteNetCs()
	{
	}
	SEnvDevelopDelCompleteNetCs(const system_clock::time_point& Time_, const TIndex& Index_, const bool& UseTopaz_) : Time(Time_), Index(Index_), UseTopaz(UseTopaz_)
	{
	}
	SEnvDevelopDelCompleteNetCs(system_clock::time_point&& Time_, TIndex&& Index_, bool&& UseTopaz_) : Time(std::move(Time_)), Index(std::move(Index_)), UseTopaz(std::move(UseTopaz_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Index;
		Stream_ >> UseTopaz;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Index"] >> Index;
		Value_["UseTopaz"] >> UseTopaz;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Index;
		Stream_ << UseTopaz;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Index"] = Index;
		Value_["UseTopaz"] = UseTopaz;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,bool";
	}
	static wstring MemberName(void)
	{
		return L"Time,Index,UseTopaz";
	}
};
struct SEnvDevelopDelCompleteNetSc : public SProto
{
	TIndex Index = 0;
	TResources ResourcesLeft{};
	TResources Reward{};
	TExp ExpLeft = 0;
	SEnvDevelopDelCompleteNetSc()
	{
	}
	SEnvDevelopDelCompleteNetSc(const TIndex& Index_, const TResources& ResourcesLeft_, const TResources& Reward_, const TExp& ExpLeft_) : Index(Index_), ResourcesLeft(ResourcesLeft_), Reward(Reward_), ExpLeft(ExpLeft_)
	{
	}
	SEnvDevelopDelCompleteNetSc(TIndex&& Index_, TResources&& ResourcesLeft_, TResources&& Reward_, TExp&& ExpLeft_) : Index(std::move(Index_)), ResourcesLeft(std::move(ResourcesLeft_)), Reward(std::move(Reward_)), ExpLeft(std::move(ExpLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> ResourcesLeft;
		Stream_ >> Reward;
		Stream_ >> ExpLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["ResourcesLeft"] >> ResourcesLeft;
		Value_["Reward"] >> Reward;
		Value_["ExpLeft"] >> ExpLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << ResourcesLeft;
		Stream_ << Reward;
		Stream_ << ExpLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["ResourcesLeft"] = ResourcesLeft;
		Value_["Reward"] = Reward;
		Value_["ExpLeft"] = ExpLeft;
	}
	static wstring StdName(void)
	{
		return L"int64,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,ResourcesLeft,Reward,ExpLeft";
	}
};
struct SBootyTakeNetCs : public SProto
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
struct SBootyTakeNetSc : public SProto
{
	TResources ResourcesLeft{};
	TResources BootyResourcesLeft{};
	SBootyTakeNetSc()
	{
	}
	SBootyTakeNetSc(const TResources& ResourcesLeft_, const TResources& BootyResourcesLeft_) : ResourcesLeft(ResourcesLeft_), BootyResourcesLeft(BootyResourcesLeft_)
	{
	}
	SBootyTakeNetSc(TResources&& ResourcesLeft_, TResources&& BootyResourcesLeft_) : ResourcesLeft(std::move(ResourcesLeft_)), BootyResourcesLeft(std::move(BootyResourcesLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourcesLeft;
		Stream_ >> BootyResourcesLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourcesLeft"] >> ResourcesLeft;
		Value_["BootyResourcesLeft"] >> BootyResourcesLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourcesLeft;
		Stream_ << BootyResourcesLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourcesLeft"] = ResourcesLeft;
		Value_["BootyResourcesLeft"] = BootyResourcesLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourcesLeft,BootyResourcesLeft";
	}
};
struct SBoostBuildingNetCs : public SProto
{
	system_clock::time_point Time;
	list<TIndex> Indices;
	SBoostBuildingNetCs()
	{
	}
	SBoostBuildingNetCs(const system_clock::time_point& Time_, const list<TIndex>& Indices_) : Time(Time_), Indices(Indices_)
	{
	}
	SBoostBuildingNetCs(system_clock::time_point&& Time_, list<TIndex>&& Indices_) : Time(std::move(Time_)), Indices(std::move(Indices_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> Indices;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["Indices"] >> Indices;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << Indices;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["Indices"] = Indices;
	}
	static wstring StdName(void)
	{
		return L"time_point,{int64}";
	}
	static wstring MemberName(void)
	{
		return L"Time,Indices";
	}
};
struct SBoostBuildingNet : public SProto
{
	TIndex Index = 0;
	STimeBoost Boost;
	SBoostBuildingNet()
	{
	}
	SBoostBuildingNet(const TIndex& Index_, const STimeBoost& Boost_) : Index(Index_), Boost(Boost_)
	{
	}
	SBoostBuildingNet(TIndex&& Index_, STimeBoost&& Boost_) : Index(std::move(Index_)), Boost(std::move(Boost_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> Boost;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Boost << Value_["Boost"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << Boost;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["Boost"] = Boost;
	}
	static wstring StdName(void)
	{
		return L"int64,time_point,time_point,double";
	}
	static wstring MemberName(void)
	{
		return L"Index,BeginTime,EndTime,Speed";
	}
};
struct SBoostBuildingNetSc : public SProto
{
	list<SBoostBuildingNet> Boosts;
	TResource TopazLeft = 0;
	SBoostBuildingNetSc()
	{
	}
	SBoostBuildingNetSc(const list<SBoostBuildingNet>& Boosts_, const TResource& TopazLeft_) : Boosts(Boosts_), TopazLeft(TopazLeft_)
	{
	}
	SBoostBuildingNetSc(list<SBoostBuildingNet>&& Boosts_, TResource&& TopazLeft_) : Boosts(std::move(Boosts_)), TopazLeft(std::move(TopazLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Boosts;
		Stream_ >> TopazLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Boosts"] >> Boosts;
		Value_["TopazLeft"] >> TopazLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Boosts;
		Stream_ << TopazLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Boosts"] = Boosts;
		Value_["TopazLeft"] = TopazLeft;
	}
	static wstring StdName(void)
	{
		return L"{int64,time_point,time_point,double},int32";
	}
	static wstring MemberName(void)
	{
		return L"Boosts,TopazLeft";
	}
};
struct SBoostBBNetCs : public SProto
{
	system_clock::time_point Time;
	SBoostBBNetCs()
	{
	}
	SBoostBBNetCs(const system_clock::time_point& Time_) : Time(Time_)
	{
	}
	SBoostBBNetCs(system_clock::time_point&& Time_) : Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"time_point";
	}
	static wstring MemberName(void)
	{
		return L"Time";
	}
};
struct SBoostBBNetSc : public SProto
{
	STimeBoost Boost;
	TResource TopazLeft = 0;
	SBoostBBNetSc()
	{
	}
	SBoostBBNetSc(const STimeBoost& Boost_, const TResource& TopazLeft_) : Boost(Boost_), TopazLeft(TopazLeft_)
	{
	}
	SBoostBBNetSc(STimeBoost&& Boost_, TResource&& TopazLeft_) : Boost(std::move(Boost_)), TopazLeft(std::move(TopazLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Boost;
		Stream_ >> TopazLeft;
	}
	void operator << (const Value& Value_) override
	{
		Boost << Value_["Boost"];
		Value_["TopazLeft"] >> TopazLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Boost;
		Stream_ << TopazLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Boost"] = Boost;
		Value_["TopazLeft"] = TopazLeft;
	}
	static wstring StdName(void)
	{
		return L"time_point,time_point,double,int32";
	}
	static wstring MemberName(void)
	{
		return L"BeginTime,EndTime,Speed,TopazLeft";
	}
};
struct SBoostBatchNetCs : public SProto
{
	system_clock::time_point Time;
	SBoostBatchNetCs()
	{
	}
	SBoostBatchNetCs(const system_clock::time_point& Time_) : Time(Time_)
	{
	}
	SBoostBatchNetCs(system_clock::time_point&& Time_) : Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"time_point";
	}
	static wstring MemberName(void)
	{
		return L"Time";
	}
};
struct SBoostBatchNetSc : public SProto
{
	TResource TopazLeft = 0;
	SBoostBatchNetSc()
	{
	}
	SBoostBatchNetSc(const TResource& TopazLeft_) : TopazLeft(TopazLeft_)
	{
	}
	SBoostBatchNetSc(TResource&& TopazLeft_) : TopazLeft(std::move(TopazLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> TopazLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["TopazLeft"] >> TopazLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << TopazLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["TopazLeft"] = TopazLeft;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"TopazLeft";
	}
};
struct SBankDepositNetCs : public SProto
{
	system_clock::time_point Time;
	SResourceTypeData TopazUseInfo;
	EResource ResourceType;
	TIndex InterestIndex = 0;
	SBankDepositNetCs()
	{
	}
	SBankDepositNetCs(const system_clock::time_point& Time_, const SResourceTypeData& TopazUseInfo_, const EResource& ResourceType_, const TIndex& InterestIndex_) : Time(Time_), TopazUseInfo(TopazUseInfo_), ResourceType(ResourceType_), InterestIndex(InterestIndex_)
	{
	}
	SBankDepositNetCs(system_clock::time_point&& Time_, SResourceTypeData&& TopazUseInfo_, EResource&& ResourceType_, TIndex&& InterestIndex_) : Time(std::move(Time_)), TopazUseInfo(std::move(TopazUseInfo_)), ResourceType(std::move(ResourceType_)), InterestIndex(std::move(InterestIndex_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> TopazUseInfo;
		Stream_ >> (__int32&)ResourceType;
		Stream_ >> InterestIndex;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		TopazUseInfo << Value_["TopazUseInfo"];
		Value_["ResourceType"] >> (__int32&)ResourceType;
		Value_["InterestIndex"] >> InterestIndex;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << TopazUseInfo;
		Stream_ << (__int32)ResourceType;
		Stream_ << InterestIndex;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["TopazUseInfo"] = TopazUseInfo;
		Value_["ResourceType"] = (__int32)ResourceType;
		Value_["InterestIndex"] = InterestIndex;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int32,int32,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,Type,Data,ResourceType,InterestIndex";
	}
};
struct SBankDepositNetSc : public SProto
{
	SBankInfo BankInfo;
	TResources ResourcesLeft{};
	SBankDepositNetSc()
	{
	}
	SBankDepositNetSc(const SBankInfo& BankInfo_, const TResources& ResourcesLeft_) : BankInfo(BankInfo_), ResourcesLeft(ResourcesLeft_)
	{
	}
	SBankDepositNetSc(SBankInfo&& BankInfo_, TResources&& ResourcesLeft_) : BankInfo(std::move(BankInfo_)), ResourcesLeft(std::move(ResourcesLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> BankInfo;
		Stream_ >> ResourcesLeft;
	}
	void operator << (const Value& Value_) override
	{
		BankInfo << Value_["BankInfo"];
		Value_["ResourcesLeft"] >> ResourcesLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << BankInfo;
		Stream_ << ResourcesLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["BankInfo"] = BankInfo;
		Value_["ResourcesLeft"] = ResourcesLeft;
	}
	static wstring StdName(void)
	{
		return L"time_point,int32,int64,int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"DepositTime,BankLevel,InterestIndex,ResourceType,ResourceValue,ResourcesLeft";
	}
};
struct SBankWithdrawNetCs : public SProto
{
	system_clock::time_point Time;
	SBankWithdrawNetCs()
	{
	}
	SBankWithdrawNetCs(const system_clock::time_point& Time_) : Time(Time_)
	{
	}
	SBankWithdrawNetCs(system_clock::time_point&& Time_) : Time(std::move(Time_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
	}
	static wstring StdName(void)
	{
		return L"time_point";
	}
	static wstring MemberName(void)
	{
		return L"Time";
	}
};
struct SBankWithdrawNetSc : public SProto
{
	TResources ResourcesLeft{};
	SBankWithdrawNetSc()
	{
	}
	SBankWithdrawNetSc(const TResources& ResourcesLeft_) : ResourcesLeft(ResourcesLeft_)
	{
	}
	SBankWithdrawNetSc(TResources&& ResourcesLeft_) : ResourcesLeft(std::move(ResourcesLeft_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ResourcesLeft;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ResourcesLeft"] >> ResourcesLeft;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ResourcesLeft;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ResourcesLeft"] = ResourcesLeft;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ResourcesLeft";
	}
};
struct SInvitationRejectNetCs : public SProto
{
	TUID FromClanUID = 0;
	SInvitationRejectNetCs()
	{
	}
	SInvitationRejectNetCs(const TUID& FromClanUID_) : FromClanUID(FromClanUID_)
	{
	}
	SInvitationRejectNetCs(TUID&& FromClanUID_) : FromClanUID(std::move(FromClanUID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> FromClanUID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["FromClanUID"] >> FromClanUID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << FromClanUID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["FromClanUID"] = FromClanUID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"FromClanUID";
	}
};
struct SMailDeleteNetCs : public SProto
{
	list<TIndex> Indices;
	SMailDeleteNetCs()
	{
	}
	SMailDeleteNetCs(const list<TIndex>& Indices_) : Indices(Indices_)
	{
	}
	SMailDeleteNetCs(list<TIndex>&& Indices_) : Indices(std::move(Indices_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Indices;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Indices"] >> Indices;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Indices;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Indices"] = Indices;
	}
	static wstring StdName(void)
	{
		return L"{int64}";
	}
	static wstring MemberName(void)
	{
		return L"Indices";
	}
};
struct SInvitationRecvNetSc : public SInvitation
{
	SInvitationRecvNetSc()
	{
	}
	SInvitationRecvNetSc(const SInvitation& Super_) : SInvitation(Super_)
	{
	}
	SInvitationRecvNetSc(SInvitation&& Super_) : SInvitation(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,int32,int64,wstring,int32,wstring,int32,wstring,time_point";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Rank,UID,Name,Rank,Mark,PassCode,Text,Time";
	}
};
struct SMailRecvNetSc : public SMail
{
	SMailRecvNetSc()
	{
	}
	SMailRecvNetSc(const SMail& Super_) : SMail(Super_)
	{
	}
	SMailRecvNetSc(SMail&& Super_) : SMail(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"int64,time_point,int64,wstring,int32,int64,wstring,int32,wstring,wstring,int32,stream";
	}
	static wstring MemberName(void)
	{
		return L"Index,Time,UID,Name,Rank,UID,Name,Rank,Mark,Text,Type,Stream";
	}
};
struct SUserProfileInfoNetCs : public SProto
{
	TUID UID = 0;
	SUserProfileInfoNetCs()
	{
	}
	SUserProfileInfoNetCs(const TUID& UID_) : UID(UID_)
	{
	}
	SUserProfileInfoNetCs(TUID&& UID_) : UID(std::move(UID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"UID";
	}
};
struct SUserProfileInfo : public SProto
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
struct SUserProfileInfoNetSc : public SUserProfileInfo
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
struct SUserVisitInfoNetCs : public SProto
{
	TUID UID = 0;
	SUserVisitInfoNetCs()
	{
	}
	SUserVisitInfoNetCs(const TUID& UID_) : UID(UID_)
	{
	}
	SUserVisitInfoNetCs(TUID&& UID_) : UID(std::move(UID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"UID";
	}
};
struct SUserVisitInfo : public SProto
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
struct SUserVisitInfoNetSc : public SUserVisitInfo
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
struct STutorialCompleteNetCs : public SProto
{
	TTutorialIndex Index = 0;
	TTutorialNumber Number = 0;
	STutorialCompleteNetCs()
	{
	}
	STutorialCompleteNetCs(const TTutorialIndex& Index_, const TTutorialNumber& Number_) : Index(Index_), Number(Number_)
	{
	}
	STutorialCompleteNetCs(TTutorialIndex&& Index_, TTutorialNumber&& Number_) : Index(std::move(Index_)), Number(std::move(Number_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> Number;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["Number"] >> Number;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << Number;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["Number"] = Number;
	}
	static wstring StdName(void)
	{
		return L"int8,int64";
	}
	static wstring MemberName(void)
	{
		return L"Index,Number";
	}
};
enum class EAchievement
{
	MultiWinCount,
	Max,
	Null,
};
struct SAchievementRewardNetCs : public SProto
{
	EAchievement Type;
	SAchievementRewardNetCs()
	{
	}
	SAchievementRewardNetCs(const EAchievement& Type_) : Type(Type_)
	{
	}
	SAchievementRewardNetCs(EAchievement&& Type_) : Type(std::move(Type_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int32&)Type;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Type"] >> (__int32&)Type;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int32)Type;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Type"] = (__int32)Type;
	}
	static wstring StdName(void)
	{
		return L"int32";
	}
	static wstring MemberName(void)
	{
		return L"Type";
	}
};
enum class EClanChatType
{
	Msg,
	JoinRequest,
	Join,
	Out,
	ClanModify,
	ChangeGrade,
	Banish,
	SupportRequest,
	Replay,
	Challange,
	Max,
	Null,
};
struct SClanChat : public SProto
{
	system_clock::time_point Time;
	TUID UID = 0;
	wstring Nick;
	EClanMemberGrade Grade;
	EClanChatType Type;
	CStream Stream;
	SClanChat()
	{
	}
	SClanChat(const system_clock::time_point& Time_, const TUID& UID_, const wstring& Nick_, const EClanMemberGrade& Grade_, const EClanChatType& Type_, const CStream& Stream_) : Time(Time_), UID(UID_), Nick(Nick_), Grade(Grade_), Type(Type_), Stream(Stream_)
	{
	}
	SClanChat(system_clock::time_point&& Time_, TUID&& UID_, wstring&& Nick_, EClanMemberGrade&& Grade_, EClanChatType&& Type_, CStream&& Stream_) : Time(std::move(Time_)), UID(std::move(UID_)), Nick(std::move(Nick_)), Grade(std::move(Grade_)), Type(std::move(Type_)), Stream(std::move(Stream_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Time;
		Stream_ >> UID;
		Stream_ >> Nick;
		Stream_ >> (__int8&)Grade;
		Stream_ >> (__int32&)Type;
		Stream_ >> Stream;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Time"] >> Time;
		Value_["UID"] >> UID;
		Value_["Nick"] >> Nick;
		Value_["Grade"] >> (__int8&)Grade;
		Value_["Type"] >> (__int32&)Type;
		Value_["Stream"] >> Stream;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Time;
		Stream_ << UID;
		Stream_ << Nick;
		Stream_ << (__int8)Grade;
		Stream_ << (__int32)Type;
		Stream_ << Stream;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Time"] = Time;
		Value_["UID"] = UID;
		Value_["Nick"] = Nick;
		Value_["Grade"] = (__int8)Grade;
		Value_["Type"] = (__int32)Type;
		Value_["Stream"] = Stream;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,wstring,int8,int32,stream";
	}
	static wstring MemberName(void)
	{
		return L"Time,UID,Nick,Grade,Type,Stream";
	}
};
struct SClanChatNetSc : public SClanChat
{
	TIndex Index = 0;
	SClanChatNetSc()
	{
	}
	SClanChatNetSc(const SClanChat& Super_, const TIndex& Index_) : SClanChat(Super_), Index(Index_)
	{
	}
	SClanChatNetSc(SClanChat&& Super_, TIndex&& Index_) : SClanChat(std::move(Super_)), Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"time_point,int64,wstring,int8,int32,stream,int64";
	}
	static wstring MemberName(void)
	{
		return L"Time,UID,Nick,Grade,Type,Stream,Index";
	}
};
struct SClanChatModifyNetSc : public SProto
{
	TIndex Index = 0;
	CStream Stream;
	SClanChatModifyNetSc()
	{
	}
	SClanChatModifyNetSc(const TIndex& Index_, const CStream& Stream_) : Index(Index_), Stream(Stream_)
	{
	}
	SClanChatModifyNetSc(TIndex&& Index_, CStream&& Stream_) : Index(std::move(Index_)), Stream(std::move(Stream_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
		Stream_ >> Stream;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
		Value_["Stream"] >> Stream;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
		Stream_ << Stream;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
		Value_["Stream"] = Stream;
	}
	static wstring StdName(void)
	{
		return L"int64,stream";
	}
	static wstring MemberName(void)
	{
		return L"Index,Stream";
	}
};
struct SClanChatDeleteNetSc : public SProto
{
	TIndex Index = 0;
	SClanChatDeleteNetSc()
	{
	}
	SClanChatDeleteNetSc(const TIndex& Index_) : Index(Index_)
	{
	}
	SClanChatDeleteNetSc(TIndex&& Index_) : Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"Index";
	}
};
struct SClanOnlineInfoNetSc : public SProto
{
	__int32 OnlineCnt = 0;
	__int32 TotalCnt = 0;
	SClanOnlineInfoNetSc()
	{
	}
	SClanOnlineInfoNetSc(const __int32& OnlineCnt_, const __int32& TotalCnt_) : OnlineCnt(OnlineCnt_), TotalCnt(TotalCnt_)
	{
	}
	SClanOnlineInfoNetSc(__int32&& OnlineCnt_, __int32&& TotalCnt_) : OnlineCnt(std::move(OnlineCnt_)), TotalCnt(std::move(TotalCnt_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> OnlineCnt;
		Stream_ >> TotalCnt;
	}
	void operator << (const Value& Value_) override
	{
		Value_["OnlineCnt"] >> OnlineCnt;
		Value_["TotalCnt"] >> TotalCnt;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << OnlineCnt;
		Stream_ << TotalCnt;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["OnlineCnt"] = OnlineCnt;
		Value_["TotalCnt"] = TotalCnt;
	}
	static wstring StdName(void)
	{
		return L"int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"OnlineCnt,TotalCnt";
	}
};
using TChats = list<SClanChatNetSc>;
struct SClanLoginNetSc : public SClanInfoNetSc
{
	EClanMemberGrade Grade;
	TChats Chats;
	SClanLoginNetSc()
	{
	}
	SClanLoginNetSc(const SClanInfoNetSc& Super_, const EClanMemberGrade& Grade_, const TChats& Chats_) : SClanInfoNetSc(Super_), Grade(Grade_), Chats(Chats_)
	{
	}
	SClanLoginNetSc(SClanInfoNetSc&& Super_, EClanMemberGrade&& Grade_, TChats&& Chats_) : SClanInfoNetSc(std::move(Super_)), Grade(std::move(Grade_)), Chats(std::move(Chats_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> (__int8&)Grade;
		Stream_ >> Chats;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Grade"] >> (__int8&)Grade;
		Value_["Chats"] >> Chats;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << (__int8)Grade;
		Stream_ << Chats;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Grade"] = (__int8)Grade;
		Value_["Chats"] = Chats;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring,wstring,int32,int32,int32,int8,int8,int32,wstring,{int64,int32,uint8,wstring,wstring,int8,int32,int32,int32,int32,int32},int8,{time_point,int64,wstring,int8,int32,stream,int64}";
	}
	static wstring MemberName(void)
	{
		return L"UID,Name,Mark,Exp,LeaguePoint,MemberCnt,Type,Region,MinLeaguePoint,Desc,Members,Grade,Chats";
	}
};
struct SClanSearchNetCs : public SProto
{
	__int32 Counter = 0;
	wstring Name;
	SClanSearchNetCs()
	{
	}
	SClanSearchNetCs(const __int32& Counter_, const wstring& Name_) : Counter(Counter_), Name(Name_)
	{
	}
	SClanSearchNetCs(__int32&& Counter_, wstring&& Name_) : Counter(std::move(Counter_)), Name(std::move(Name_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Counter;
		Stream_ >> Name;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Counter"] >> Counter;
		Value_["Name"] >> Name;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Counter;
		Stream_ << Name;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Counter"] = Counter;
		Value_["Name"] = Name;
	}
	static wstring StdName(void)
	{
		return L"int32,wstring";
	}
	static wstring MemberName(void)
	{
		return L"Counter,Name";
	}
};
struct SClanSearchWithFilterNetCs : public SProto
{
	__int32 Counter = 0;
	wstring Name;
	__int32 MinMemberCnt = 0;
	__int32 MaxMemberCnt = 0;
	ERegion Region;
	TLeaguePoint MinClanPoint = 0;
	TLevel MinClanLevel = 0;
	bool ShowOnlyJoinable = false;
	SClanSearchWithFilterNetCs()
	{
	}
	SClanSearchWithFilterNetCs(const __int32& Counter_, const wstring& Name_, const __int32& MinMemberCnt_, const __int32& MaxMemberCnt_, const ERegion& Region_, const TLeaguePoint& MinClanPoint_, const TLevel& MinClanLevel_, const bool& ShowOnlyJoinable_) : Counter(Counter_), Name(Name_), MinMemberCnt(MinMemberCnt_), MaxMemberCnt(MaxMemberCnt_), Region(Region_), MinClanPoint(MinClanPoint_), MinClanLevel(MinClanLevel_), ShowOnlyJoinable(ShowOnlyJoinable_)
	{
	}
	SClanSearchWithFilterNetCs(__int32&& Counter_, wstring&& Name_, __int32&& MinMemberCnt_, __int32&& MaxMemberCnt_, ERegion&& Region_, TLeaguePoint&& MinClanPoint_, TLevel&& MinClanLevel_, bool&& ShowOnlyJoinable_) : Counter(std::move(Counter_)), Name(std::move(Name_)), MinMemberCnt(std::move(MinMemberCnt_)), MaxMemberCnt(std::move(MaxMemberCnt_)), Region(std::move(Region_)), MinClanPoint(std::move(MinClanPoint_)), MinClanLevel(std::move(MinClanLevel_)), ShowOnlyJoinable(std::move(ShowOnlyJoinable_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Counter;
		Stream_ >> Name;
		Stream_ >> MinMemberCnt;
		Stream_ >> MaxMemberCnt;
		Stream_ >> (__int8&)Region;
		Stream_ >> MinClanPoint;
		Stream_ >> MinClanLevel;
		Stream_ >> ShowOnlyJoinable;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Counter"] >> Counter;
		Value_["Name"] >> Name;
		Value_["MinMemberCnt"] >> MinMemberCnt;
		Value_["MaxMemberCnt"] >> MaxMemberCnt;
		Value_["Region"] >> (__int8&)Region;
		Value_["MinClanPoint"] >> MinClanPoint;
		Value_["MinClanLevel"] >> MinClanLevel;
		Value_["ShowOnlyJoinable"] >> ShowOnlyJoinable;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Counter;
		Stream_ << Name;
		Stream_ << MinMemberCnt;
		Stream_ << MaxMemberCnt;
		Stream_ << (__int8)Region;
		Stream_ << MinClanPoint;
		Stream_ << MinClanLevel;
		Stream_ << ShowOnlyJoinable;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Counter"] = Counter;
		Value_["Name"] = Name;
		Value_["MinMemberCnt"] = MinMemberCnt;
		Value_["MaxMemberCnt"] = MaxMemberCnt;
		Value_["Region"] = (__int8)Region;
		Value_["MinClanPoint"] = MinClanPoint;
		Value_["MinClanLevel"] = MinClanLevel;
		Value_["ShowOnlyJoinable"] = ShowOnlyJoinable;
	}
	static wstring StdName(void)
	{
		return L"int32,wstring,int32,int32,int8,int32,int32,bool";
	}
	static wstring MemberName(void)
	{
		return L"Counter,Name,MinMemberCnt,MaxMemberCnt,Region,MinClanPoint,MinClanLevel,ShowOnlyJoinable";
	}
};
struct SClanSearchOut : public SProto
{
	list<SClanInfoSearch> Clans;
	SClanSearchOut()
	{
	}
	SClanSearchOut(const list<SClanInfoSearch>& Clans_) : Clans(Clans_)
	{
	}
	SClanSearchOut(list<SClanInfoSearch>&& Clans_) : Clans(std::move(Clans_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Clans;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Clans"] >> Clans;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Clans;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Clans"] = Clans;
	}
	static wstring StdName(void)
	{
		return L"{int64,wstring,wstring,int32,int32,int32,int8}";
	}
	static wstring MemberName(void)
	{
		return L"Clans";
	}
};
struct SClanSearchNetSc : public SClanSearchOut
{
	__int32 Counter = 0;
	SClanSearchNetSc()
	{
	}
	SClanSearchNetSc(const SClanSearchOut& Super_, const __int32& Counter_) : SClanSearchOut(Super_), Counter(Counter_)
	{
	}
	SClanSearchNetSc(SClanSearchOut&& Super_, __int32&& Counter_) : SClanSearchOut(std::move(Super_)), Counter(std::move(Counter_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Counter;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Counter"] >> Counter;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Counter;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Counter"] = Counter;
	}
	static wstring StdName(void)
	{
		return L"{int64,wstring,wstring,int32,int32,int32,int8},int32";
	}
	static wstring MemberName(void)
	{
		return L"Clans,Counter";
	}
};
struct SClanChatStream2LoadNetCs : public SProto
{
	TIndex Index = 0;
	SClanChatStream2LoadNetCs()
	{
	}
	SClanChatStream2LoadNetCs(const TIndex& Index_) : Index(Index_)
	{
	}
	SClanChatStream2LoadNetCs(TIndex&& Index_) : Index(std::move(Index_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Index;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Index"] >> Index;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Index;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Index"] = Index;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"Index";
	}
};
struct SClanChatStream2LoadNetSc : public SProto
{
	list<CStream> Datas;
	SClanChatStream2LoadNetSc()
	{
	}
	SClanChatStream2LoadNetSc(const list<CStream>& Datas_) : Datas(Datas_)
	{
	}
	SClanChatStream2LoadNetSc(list<CStream>&& Datas_) : Datas(std::move(Datas_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Datas;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Datas"] >> Datas;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Datas;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Datas"] = Datas;
	}
	static wstring StdName(void)
	{
		return L"{stream}";
	}
	static wstring MemberName(void)
	{
		return L"Datas";
	}
};
struct SClanJoinAllowOkNetSc : public SProto
{
	TUID ClanUID = 0;
	wstring ClanName;
	SClanJoinAllowOkNetSc()
	{
	}
	SClanJoinAllowOkNetSc(const TUID& ClanUID_, const wstring& ClanName_) : ClanUID(ClanUID_), ClanName(ClanName_)
	{
	}
	SClanJoinAllowOkNetSc(TUID&& ClanUID_, wstring&& ClanName_) : ClanUID(std::move(ClanUID_)), ClanName(std::move(ClanName_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ClanUID;
		Stream_ >> ClanName;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ClanUID"] >> ClanUID;
		Value_["ClanName"] >> ClanName;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ClanUID;
		Stream_ << ClanName;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ClanUID"] = ClanUID;
		Value_["ClanName"] = ClanName;
	}
	static wstring StdName(void)
	{
		return L"int64,wstring";
	}
	static wstring MemberName(void)
	{
		return L"ClanUID,ClanName";
	}
};
struct SClanInfoNetCs : public SProto
{
	TUID ClanUID = 0;
	SClanInfoNetCs()
	{
	}
	SClanInfoNetCs(const TUID& ClanUID_) : ClanUID(ClanUID_)
	{
	}
	SClanInfoNetCs(TUID&& ClanUID_) : ClanUID(std::move(ClanUID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ClanUID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ClanUID"] >> ClanUID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ClanUID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ClanUID"] = ClanUID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"ClanUID";
	}
};
struct SClanJoinResponseNetCs : public SProto
{
	TIndex ChatIndex = 0;
	bool Allow = false;
	SClanJoinResponseNetCs()
	{
	}
	SClanJoinResponseNetCs(const TIndex& ChatIndex_, const bool& Allow_) : ChatIndex(ChatIndex_), Allow(Allow_)
	{
	}
	SClanJoinResponseNetCs(TIndex&& ChatIndex_, bool&& Allow_) : ChatIndex(std::move(ChatIndex_)), Allow(std::move(Allow_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ChatIndex;
		Stream_ >> Allow;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ChatIndex"] >> ChatIndex;
		Value_["Allow"] >> Allow;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ChatIndex;
		Stream_ << Allow;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ChatIndex"] = ChatIndex;
		Value_["Allow"] = Allow;
	}
	static wstring StdName(void)
	{
		return L"int64,bool";
	}
	static wstring MemberName(void)
	{
		return L"ChatIndex,Allow";
	}
};
struct SClanInviteNetCs : public SProto
{
	TUID UID = 0;
	SClanInviteNetCs()
	{
	}
	SClanInviteNetCs(const TUID& UID_) : UID(UID_)
	{
	}
	SClanInviteNetCs(TUID&& UID_) : UID(std::move(UID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"UID";
	}
};
struct SClanJoinNetSc : public SClanMember
{
	SClanJoinNetSc()
	{
	}
	SClanJoinNetSc(const SClanMember& Super_) : SClanMember(Super_)
	{
	}
	SClanJoinNetSc(SClanMember&& Super_) : SClanMember(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"int64,int32,uint8,wstring,wstring,int8,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"UID,Exp,AccountType,ID,Nick,Grade,LeaguePoint,SupportCnt,ReceiveCnt,OldRank,CurRank";
	}
};
struct SClanModifyNetCs : public SProto
{
	EClanType Type;
	wstring Mark;
	TLeaguePoint MinLeaguePoint = 0;
	wstring Desc;
	SClanModifyNetCs()
	{
	}
	SClanModifyNetCs(const EClanType& Type_, const wstring& Mark_, const TLeaguePoint& MinLeaguePoint_, const wstring& Desc_) : Type(Type_), Mark(Mark_), MinLeaguePoint(MinLeaguePoint_), Desc(Desc_)
	{
	}
	SClanModifyNetCs(EClanType&& Type_, wstring&& Mark_, TLeaguePoint&& MinLeaguePoint_, wstring&& Desc_) : Type(std::move(Type_)), Mark(std::move(Mark_)), MinLeaguePoint(std::move(MinLeaguePoint_)), Desc(std::move(Desc_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int8&)Type;
		Stream_ >> Mark;
		Stream_ >> MinLeaguePoint;
		Stream_ >> Desc;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Type"] >> (__int8&)Type;
		Value_["Mark"] >> Mark;
		Value_["MinLeaguePoint"] >> MinLeaguePoint;
		Value_["Desc"] >> Desc;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int8)Type;
		Stream_ << Mark;
		Stream_ << MinLeaguePoint;
		Stream_ << Desc;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Type"] = (__int8)Type;
		Value_["Mark"] = Mark;
		Value_["MinLeaguePoint"] = MinLeaguePoint;
		Value_["Desc"] = Desc;
	}
	static wstring StdName(void)
	{
		return L"int8,wstring,int32,wstring";
	}
	static wstring MemberName(void)
	{
		return L"Type,Mark,MinLeaguePoint,Desc";
	}
};
struct SClanModifyNetSc : public SClanModifyNetCs
{
	SClanModifyNetSc()
	{
	}
	SClanModifyNetSc(const SClanModifyNetCs& Super_) : SClanModifyNetCs(Super_)
	{
	}
	SClanModifyNetSc(SClanModifyNetCs&& Super_) : SClanModifyNetCs(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"int8,wstring,int32,wstring";
	}
	static wstring MemberName(void)
	{
		return L"Type,Mark,MinLeaguePoint,Desc";
	}
};
struct SUIDGrade : public SProto
{
	TUID UID = 0;
	EClanMemberGrade Grade;
	SUIDGrade()
	{
	}
	SUIDGrade(const TUID& UID_, const EClanMemberGrade& Grade_) : UID(UID_), Grade(Grade_)
	{
	}
	SUIDGrade(TUID&& UID_, EClanMemberGrade&& Grade_) : UID(std::move(UID_)), Grade(std::move(Grade_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
		Stream_ >> (__int8&)Grade;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
		Value_["Grade"] >> (__int8&)Grade;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
		Stream_ << (__int8)Grade;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
		Value_["Grade"] = (__int8)Grade;
	}
	static wstring StdName(void)
	{
		return L"int64,int8";
	}
	static wstring MemberName(void)
	{
		return L"UID,Grade";
	}
};
using TUIDGrades = list<SUIDGrade>;
struct SClanChangeGradeNetCs : public SProto
{
	TUID UID = 0;
	EClanMemberGrade Grade;
	SClanChangeGradeNetCs()
	{
	}
	SClanChangeGradeNetCs(const TUID& UID_, const EClanMemberGrade& Grade_) : UID(UID_), Grade(Grade_)
	{
	}
	SClanChangeGradeNetCs(TUID&& UID_, EClanMemberGrade&& Grade_) : UID(std::move(UID_)), Grade(std::move(Grade_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
		Stream_ >> (__int8&)Grade;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
		Value_["Grade"] >> (__int8&)Grade;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
		Stream_ << (__int8)Grade;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
		Value_["Grade"] = (__int8)Grade;
	}
	static wstring StdName(void)
	{
		return L"int64,int8";
	}
	static wstring MemberName(void)
	{
		return L"UID,Grade";
	}
};
struct SClanChangeGradeNetSc : public SProto
{
	TUIDGrades Changed;
	SClanChangeGradeNetSc()
	{
	}
	SClanChangeGradeNetSc(const TUIDGrades& Changed_) : Changed(Changed_)
	{
	}
	SClanChangeGradeNetSc(TUIDGrades&& Changed_) : Changed(std::move(Changed_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Changed;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Changed"] >> Changed;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Changed;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Changed"] = Changed;
	}
	static wstring StdName(void)
	{
		return L"{int64,int8}";
	}
	static wstring MemberName(void)
	{
		return L"Changed";
	}
};
struct SClanBanishNetCs : public SProto
{
	TUID UID = 0;
	SClanBanishNetCs()
	{
	}
	SClanBanishNetCs(const TUID& UID_) : UID(UID_)
	{
	}
	SClanBanishNetCs(TUID&& UID_) : UID(std::move(UID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"UID";
	}
};
struct SClanOutNetSc : public SProto
{
	TUID UID = 0;
	SClanOutNetSc()
	{
	}
	SClanOutNetSc(const TUID& UID_) : UID(UID_)
	{
	}
	SClanOutNetSc(TUID&& UID_) : UID(std::move(UID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> UID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["UID"] >> UID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << UID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["UID"] = UID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"UID";
	}
};
struct SClanSendMessageAllNetCs : public SProto
{
	wstring Message;
	SClanSendMessageAllNetCs()
	{
	}
	SClanSendMessageAllNetCs(const wstring& Message_) : Message(Message_)
	{
	}
	SClanSendMessageAllNetCs(wstring&& Message_) : Message(std::move(Message_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Message;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Message"] >> Message;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Message;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Message"] = Message;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"Message";
	}
};
struct SClanOutNetCs : public SProto
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
struct SClanSupportRequestNetCs : public SProto
{
	wstring Msg;
	SClanSupportRequestNetCs()
	{
	}
	SClanSupportRequestNetCs(const wstring& Msg_) : Msg(Msg_)
	{
	}
	SClanSupportRequestNetCs(wstring&& Msg_) : Msg(std::move(Msg_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Msg;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Msg"] >> Msg;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Msg;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Msg"] = Msg;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"Msg";
	}
};
struct SClanSupportRequestNetSc : public SProto
{
	system_clock::time_point CoolEndTime;
	SClanSupportRequestNetSc()
	{
	}
	SClanSupportRequestNetSc(const system_clock::time_point& CoolEndTime_) : CoolEndTime(CoolEndTime_)
	{
	}
	SClanSupportRequestNetSc(system_clock::time_point&& CoolEndTime_) : CoolEndTime(std::move(CoolEndTime_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> CoolEndTime;
	}
	void operator << (const Value& Value_) override
	{
		Value_["CoolEndTime"] >> CoolEndTime;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << CoolEndTime;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["CoolEndTime"] = CoolEndTime;
	}
	static wstring StdName(void)
	{
		return L"time_point";
	}
	static wstring MemberName(void)
	{
		return L"CoolEndTime";
	}
};
struct SClanSupportNetCs : public SProto
{
	TIndex ChatIndex = 0;
	TID GroupID = 0;
	SClanSupportNetCs()
	{
	}
	SClanSupportNetCs(const TIndex& ChatIndex_, const TID& GroupID_) : ChatIndex(ChatIndex_), GroupID(GroupID_)
	{
	}
	SClanSupportNetCs(TIndex&& ChatIndex_, TID&& GroupID_) : ChatIndex(std::move(ChatIndex_)), GroupID(std::move(GroupID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ChatIndex;
		Stream_ >> GroupID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ChatIndex"] >> ChatIndex;
		Value_["GroupID"] >> GroupID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ChatIndex;
		Stream_ << GroupID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ChatIndex"] = ChatIndex;
		Value_["GroupID"] = GroupID;
	}
	static wstring StdName(void)
	{
		return L"int64,int32";
	}
	static wstring MemberName(void)
	{
		return L"ChatIndex,GroupID";
	}
};
struct SClanSupportNetSc : public SProto
{
	TExp ExpLeft = 0;
	TResources ResourcesLeft{};
	TID GroupID = 0;
	SClanSupportNetSc()
	{
	}
	SClanSupportNetSc(const TExp& ExpLeft_, const TResources& ResourcesLeft_, const TID& GroupID_) : ExpLeft(ExpLeft_), ResourcesLeft(ResourcesLeft_), GroupID(GroupID_)
	{
	}
	SClanSupportNetSc(TExp&& ExpLeft_, TResources&& ResourcesLeft_, TID&& GroupID_) : ExpLeft(std::move(ExpLeft_)), ResourcesLeft(std::move(ResourcesLeft_)), GroupID(std::move(GroupID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ExpLeft;
		Stream_ >> ResourcesLeft;
		Stream_ >> GroupID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ExpLeft"] >> ExpLeft;
		Value_["ResourcesLeft"] >> ResourcesLeft;
		Value_["GroupID"] >> GroupID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ExpLeft;
		Stream_ << ResourcesLeft;
		Stream_ << GroupID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ExpLeft"] = ExpLeft;
		Value_["ResourcesLeft"] = ResourcesLeft;
		Value_["GroupID"] = GroupID;
	}
	static wstring StdName(void)
	{
		return L"int32,int32,int32,int32,int32,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"ExpLeft,ResourcesLeft,GroupID";
	}
};
struct SClanReceiveNetSc : public SProto
{
	wstring FromNick;
	__int64 Index = 0;
	SGroupIDLevel Data;
	SClanReceiveNetSc()
	{
	}
	SClanReceiveNetSc(const wstring& FromNick_, const __int64& Index_, const SGroupIDLevel& Data_) : FromNick(FromNick_), Index(Index_), Data(Data_)
	{
	}
	SClanReceiveNetSc(wstring&& FromNick_, __int64&& Index_, SGroupIDLevel&& Data_) : FromNick(std::move(FromNick_)), Index(std::move(Index_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> FromNick;
		Stream_ >> Index;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		Value_["FromNick"] >> FromNick;
		Value_["Index"] >> Index;
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << FromNick;
		Stream_ << Index;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["FromNick"] = FromNick;
		Value_["Index"] = Index;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"wstring,int64,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"FromNick,Index,GroupID,Level";
	}
};
struct SClanBookMarkListNetCs : public SProto
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
struct SClanBookMarkListNetSc : public SClanSearchOut
{
	SClanBookMarkListNetSc()
	{
	}
	SClanBookMarkListNetSc(const SClanSearchOut& Super_) : SClanSearchOut(Super_)
	{
	}
	SClanBookMarkListNetSc(SClanSearchOut&& Super_) : SClanSearchOut(std::move(Super_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
	}
	static wstring StdName(void)
	{
		return L"{int64,wstring,wstring,int32,int32,int32,int8}";
	}
	static wstring MemberName(void)
	{
		return L"Clans";
	}
};
struct SClanBookMarkAddNetCs : public SProto
{
	TUID ClanUID = 0;
	SClanBookMarkAddNetCs()
	{
	}
	SClanBookMarkAddNetCs(const TUID& ClanUID_) : ClanUID(ClanUID_)
	{
	}
	SClanBookMarkAddNetCs(TUID&& ClanUID_) : ClanUID(std::move(ClanUID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ClanUID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ClanUID"] >> ClanUID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ClanUID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ClanUID"] = ClanUID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"ClanUID";
	}
};
struct SClanBookMarkDelNetCs : public SProto
{
	TUID ClanUID = 0;
	SClanBookMarkDelNetCs()
	{
	}
	SClanBookMarkDelNetCs(const TUID& ClanUID_) : ClanUID(ClanUID_)
	{
	}
	SClanBookMarkDelNetCs(TUID&& ClanUID_) : ClanUID(std::move(ClanUID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ClanUID;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ClanUID"] >> ClanUID;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ClanUID;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ClanUID"] = ClanUID;
	}
	static wstring StdName(void)
	{
		return L"int64";
	}
	static wstring MemberName(void)
	{
		return L"ClanUID";
	}
};
struct SClanReplayShareNetCs : public SProto
{
	bool IsAttack = false;
	TIndex ReplayIndex = 0;
	wstring Note;
	SClanReplayShareNetCs()
	{
	}
	SClanReplayShareNetCs(const bool& IsAttack_, const TIndex& ReplayIndex_, const wstring& Note_) : IsAttack(IsAttack_), ReplayIndex(ReplayIndex_), Note(Note_)
	{
	}
	SClanReplayShareNetCs(bool&& IsAttack_, TIndex&& ReplayIndex_, wstring&& Note_) : IsAttack(std::move(IsAttack_)), ReplayIndex(std::move(ReplayIndex_)), Note(std::move(Note_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> IsAttack;
		Stream_ >> ReplayIndex;
		Stream_ >> Note;
	}
	void operator << (const Value& Value_) override
	{
		Value_["IsAttack"] >> IsAttack;
		Value_["ReplayIndex"] >> ReplayIndex;
		Value_["Note"] >> Note;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << IsAttack;
		Stream_ << ReplayIndex;
		Stream_ << Note;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["IsAttack"] = IsAttack;
		Value_["ReplayIndex"] = ReplayIndex;
		Value_["Note"] = Note;
	}
	static wstring StdName(void)
	{
		return L"bool,int64,wstring";
	}
	static wstring MemberName(void)
	{
		return L"IsAttack,ReplayIndex,Note";
	}
};
struct SClanChatMsgNetCs : public SProto
{
	wstring Msg;
	SClanChatMsgNetCs()
	{
	}
	SClanChatMsgNetCs(const wstring& Msg_) : Msg(Msg_)
	{
	}
	SClanChatMsgNetCs(wstring&& Msg_) : Msg(std::move(Msg_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Msg;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Msg"] >> Msg;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Msg;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Msg"] = Msg;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"Msg";
	}
};
struct SClanChatMsg : public SProto
{
	wstring Msg;
	SClanChatMsg()
	{
	}
	SClanChatMsg(const wstring& Msg_) : Msg(Msg_)
	{
	}
	SClanChatMsg(wstring&& Msg_) : Msg(std::move(Msg_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Msg;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Msg"] >> Msg;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Msg;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Msg"] = Msg;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"Msg";
	}
};
struct SClanChatJoin : public SProto
{
	wstring ByNick;
	SClanChatJoin()
	{
	}
	SClanChatJoin(const wstring& ByNick_) : ByNick(ByNick_)
	{
	}
	SClanChatJoin(wstring&& ByNick_) : ByNick(std::move(ByNick_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ByNick;
	}
	void operator << (const Value& Value_) override
	{
		Value_["ByNick"] >> ByNick;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ByNick;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ByNick"] = ByNick;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"ByNick";
	}
};
enum EClanJoinRequestState
{
	Allowed,
	Rejected,
	Max,
	Null,
};
struct SClanChatJoinRequest : public SProto
{
	EClanJoinRequestState State;
	wstring Message;
	wstring ByNick;
	SClanChatJoinRequest()
	{
	}
	SClanChatJoinRequest(const EClanJoinRequestState& State_, const wstring& Message_, const wstring& ByNick_) : State(State_), Message(Message_), ByNick(ByNick_)
	{
	}
	SClanChatJoinRequest(EClanJoinRequestState&& State_, wstring&& Message_, wstring&& ByNick_) : State(std::move(State_)), Message(std::move(Message_)), ByNick(std::move(ByNick_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> (__int32&)State;
		Stream_ >> Message;
		Stream_ >> ByNick;
	}
	void operator << (const Value& Value_) override
	{
		Value_["State"] >> (__int32&)State;
		Value_["Message"] >> Message;
		Value_["ByNick"] >> ByNick;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << (__int32)State;
		Stream_ << Message;
		Stream_ << ByNick;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["State"] = (__int32)State;
		Value_["Message"] = Message;
		Value_["ByNick"] = ByNick;
	}
	static wstring StdName(void)
	{
		return L"int32,wstring,wstring";
	}
	static wstring MemberName(void)
	{
		return L"State,Message,ByNick";
	}
};
struct SClanChatOut : public SProto
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
struct SClanChatClanModify : public SProto
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
struct SClanChatChangeGrade : public SProto
{
	bool Up = false;
	wstring ChangedByNick;
	SClanChatChangeGrade()
	{
	}
	SClanChatChangeGrade(const bool& Up_, const wstring& ChangedByNick_) : Up(Up_), ChangedByNick(ChangedByNick_)
	{
	}
	SClanChatChangeGrade(bool&& Up_, wstring&& ChangedByNick_) : Up(std::move(Up_)), ChangedByNick(std::move(ChangedByNick_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Up;
		Stream_ >> ChangedByNick;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Up"] >> Up;
		Value_["ChangedByNick"] >> ChangedByNick;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Up;
		Stream_ << ChangedByNick;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Up"] = Up;
		Value_["ChangedByNick"] = ChangedByNick;
	}
	static wstring StdName(void)
	{
		return L"bool,wstring";
	}
	static wstring MemberName(void)
	{
		return L"Up,ChangedByNick";
	}
};
struct SClanChatBanish : public SProto
{
	wstring BanishedByNick;
	SClanChatBanish()
	{
	}
	SClanChatBanish(const wstring& BanishedByNick_) : BanishedByNick(BanishedByNick_)
	{
	}
	SClanChatBanish(wstring&& BanishedByNick_) : BanishedByNick(std::move(BanishedByNick_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> BanishedByNick;
	}
	void operator << (const Value& Value_) override
	{
		Value_["BanishedByNick"] >> BanishedByNick;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << BanishedByNick;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["BanishedByNick"] = BanishedByNick;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"BanishedByNick";
	}
};
using TListClanForce = list<SGroupIDLevel>;
using TListClanForces = array<TListClanForce,2>;
struct SClanSupportRequest : public SProto
{
	wstring Msg;
	TForceCnts RecvLimits{};
	TListClanForces ListClanForces{};
	SClanSupportRequest()
	{
	}
	SClanSupportRequest(const wstring& Msg_, const TForceCnts& RecvLimits_, const TListClanForces& ListClanForces_) : Msg(Msg_), RecvLimits(RecvLimits_), ListClanForces(ListClanForces_)
	{
	}
	SClanSupportRequest(wstring&& Msg_, TForceCnts&& RecvLimits_, TListClanForces&& ListClanForces_) : Msg(std::move(Msg_)), RecvLimits(std::move(RecvLimits_)), ListClanForces(std::move(ListClanForces_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Msg;
		Stream_ >> RecvLimits;
		Stream_ >> ListClanForces;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Msg"] >> Msg;
		Value_["RecvLimits"] >> RecvLimits;
		Value_["ListClanForces"] >> ListClanForces;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Msg;
		Stream_ << RecvLimits;
		Stream_ << ListClanForces;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Msg"] = Msg;
		Value_["RecvLimits"] = RecvLimits;
		Value_["ListClanForces"] = ListClanForces;
	}
	static wstring StdName(void)
	{
		return L"wstring,int32,int32,{int32,int32},{int32,int32}";
	}
	static wstring MemberName(void)
	{
		return L"Msg,RecvLimits,ListClanForces";
	}
};
struct SSupportedCntPerMember : public SProto
{
	map<TUID,__int32> Cnts;
	SSupportedCntPerMember()
	{
	}
	SSupportedCntPerMember(const map<TUID,__int32>& Cnts_) : Cnts(Cnts_)
	{
	}
	SSupportedCntPerMember(map<TUID,__int32>&& Cnts_) : Cnts(std::move(Cnts_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Cnts;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Cnts"] >> Cnts;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Cnts;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Cnts"] = Cnts;
	}
	static wstring StdName(void)
	{
		return L"{int64,int32}";
	}
	static wstring MemberName(void)
	{
		return L"Cnts";
	}
};
using TSupportedCntPerMembers = array<SSupportedCntPerMember,2>;
struct SClanChatSupportRequest : public SClanSupportRequest
{
	TLevel ClanCastleLevel = 0;
	TSupportedCntPerMembers SupportedCntPerMembers{};
	SClanChatSupportRequest()
	{
	}
	SClanChatSupportRequest(const SClanSupportRequest& Super_, const TLevel& ClanCastleLevel_, const TSupportedCntPerMembers& SupportedCntPerMembers_) : SClanSupportRequest(Super_), ClanCastleLevel(ClanCastleLevel_), SupportedCntPerMembers(SupportedCntPerMembers_)
	{
	}
	SClanChatSupportRequest(SClanSupportRequest&& Super_, TLevel&& ClanCastleLevel_, TSupportedCntPerMembers&& SupportedCntPerMembers_) : SClanSupportRequest(std::move(Super_)), ClanCastleLevel(std::move(ClanCastleLevel_)), SupportedCntPerMembers(std::move(SupportedCntPerMembers_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> ClanCastleLevel;
		Stream_ >> SupportedCntPerMembers;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["ClanCastleLevel"] >> ClanCastleLevel;
		Value_["SupportedCntPerMembers"] >> SupportedCntPerMembers;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << ClanCastleLevel;
		Stream_ << SupportedCntPerMembers;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["ClanCastleLevel"] = ClanCastleLevel;
		Value_["SupportedCntPerMembers"] = SupportedCntPerMembers;
	}
	static wstring StdName(void)
	{
		return L"wstring,int32,int32,{int32,int32},{int32,int32},int32,{int64,int32},{int64,int32}";
	}
	static wstring MemberName(void)
	{
		return L"Msg,RecvLimits,ListClanForces,ClanCastleLevel,SupportedCntPerMembers";
	}
};
struct SClanChatReplay : public SReplayCore
{
	wstring Note;
	SClanChatReplay()
	{
	}
	SClanChatReplay(const SReplayCore& Super_, const wstring& Note_) : SReplayCore(Super_), Note(Note_)
	{
	}
	SClanChatReplay(SReplayCore&& Super_, wstring&& Note_) : SReplayCore(std::move(Super_)), Note(std::move(Note_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> Note;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["Note"] >> Note;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << Note;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["Note"] = Note;
	}
	static wstring StdName(void)
	{
		return L"int64,int64,wstring,int32,int32,int64,wstring,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,wstring";
	}
	static wstring MemberName(void)
	{
		return L"Index,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,Win,Lose,Win,Lose,Percentage,Note";
	}
};
struct SClanChatReplayDB : public SProto
{
	SClanChatReplay ClanChatReplay;
	SBattleInfoBase Data;
	SClanChatReplayDB()
	{
	}
	SClanChatReplayDB(const SClanChatReplay& ClanChatReplay_, const SBattleInfoBase& Data_) : ClanChatReplay(ClanChatReplay_), Data(Data_)
	{
	}
	SClanChatReplayDB(SClanChatReplay&& ClanChatReplay_, SBattleInfoBase&& Data_) : ClanChatReplay(std::move(ClanChatReplay_)), Data(std::move(Data_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> ClanChatReplay;
		Stream_ >> Data;
	}
	void operator << (const Value& Value_) override
	{
		ClanChatReplay << Value_["ClanChatReplay"];
		Data << Value_["Data"];
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << ClanChatReplay;
		Stream_ << Data;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["ClanChatReplay"] = ClanChatReplay;
		Value_["Data"] = Data;
	}
	static wstring StdName(void)
	{
		return L"int64,int64,wstring,int32,int32,int64,wstring,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,wstring,int64,wstring,int32,int32,int64,wstring,wstring,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,stream,stream,stream,time_point,int32,int32";
	}
	static wstring MemberName(void)
	{
		return L"Index,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,Win,Lose,Win,Lose,Percentage,Note,UID,Nick,Exp,LeaguePoint,UID,Name,Mark,DefenderCPLevel,ResourcesCanGet,ResourcesCanGetFromCollector,Stream_SBattleScoutCore,Stream_SBattleCanUseInfo,Stream_SBattlePlayInfo,BattleStartTime,Main,Sub";
	}
};
struct SJoinAllowTargetBase : public SProto
{
	TExp Exp = 0;
	wstring Nick;
	TLeaguePoint LeaguePoint = 0;
	SJoinAllowTargetBase()
	{
	}
	SJoinAllowTargetBase(const TExp& Exp_, const wstring& Nick_, const TLeaguePoint& LeaguePoint_) : Exp(Exp_), Nick(Nick_), LeaguePoint(LeaguePoint_)
	{
	}
	SJoinAllowTargetBase(TExp&& Exp_, wstring&& Nick_, TLeaguePoint&& LeaguePoint_) : Exp(std::move(Exp_)), Nick(std::move(Nick_)), LeaguePoint(std::move(LeaguePoint_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Exp;
		Stream_ >> Nick;
		Stream_ >> LeaguePoint;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Exp"] >> Exp;
		Value_["Nick"] >> Nick;
		Value_["LeaguePoint"] >> LeaguePoint;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Exp;
		Stream_ << Nick;
		Stream_ << LeaguePoint;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Exp"] = Exp;
		Value_["Nick"] = Nick;
		Value_["LeaguePoint"] = LeaguePoint;
	}
	static wstring StdName(void)
	{
		return L"int32,wstring,int32";
	}
	static wstring MemberName(void)
	{
		return L"Exp,Nick,LeaguePoint";
	}
};
struct SJoinAllowTarget : public SJoinAllowTargetBase
{
	TUID UID = 0;
	TAccountType AccountType = 0;
	wstring ID;
	SJoinAllowTarget()
	{
	}
	SJoinAllowTarget(const SJoinAllowTargetBase& Super_, const TUID& UID_, const TAccountType& AccountType_, const wstring& ID_) : SJoinAllowTargetBase(Super_), UID(UID_), AccountType(AccountType_), ID(ID_)
	{
	}
	SJoinAllowTarget(SJoinAllowTargetBase&& Super_, TUID&& UID_, TAccountType&& AccountType_, wstring&& ID_) : SJoinAllowTargetBase(std::move(Super_)), UID(std::move(UID_)), AccountType(std::move(AccountType_)), ID(std::move(ID_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		__super::operator << (Stream_);
		Stream_ >> UID;
		Stream_ >> AccountType;
		Stream_ >> ID;
	}
	void operator << (const Value& Value_) override
	{
		__super::operator << (Value_);
		Value_["UID"] >> UID;
		Value_["AccountType"] >> AccountType;
		Value_["ID"] >> ID;
	}
	void operator >> (CStream& Stream_) const override
	{
		__super::operator >> (Stream_);
		Stream_ << UID;
		Stream_ << AccountType;
		Stream_ << ID;
	}
	void operator >> (Value& Value_) const override
	{
		__super::operator >> (Value_);
		Value_["UID"] = UID;
		Value_["AccountType"] = AccountType;
		Value_["ID"] = ID;
	}
	static wstring StdName(void)
	{
		return L"int32,wstring,int32,int64,uint8,wstring";
	}
	static wstring MemberName(void)
	{
		return L"Exp,Nick,LeaguePoint,UID,AccountType,ID";
	}
};
struct SFCMTokenSetNetCs : public SProto
{
	wstring Token;
	SFCMTokenSetNetCs()
	{
	}
	SFCMTokenSetNetCs(const wstring& Token_) : Token(Token_)
	{
	}
	SFCMTokenSetNetCs(wstring&& Token_) : Token(std::move(Token_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> Token;
	}
	void operator << (const Value& Value_) override
	{
		Value_["Token"] >> Token;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << Token;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["Token"] = Token;
	}
	static wstring StdName(void)
	{
		return L"wstring";
	}
	static wstring MemberName(void)
	{
		return L"Token";
	}
};
struct SFCMTokenUnsetNetCs : public SProto
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
