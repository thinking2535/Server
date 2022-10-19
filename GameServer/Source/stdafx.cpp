#include "stdafx.h"
#include <Rso/Win/ConsoleCtrlHandler.h>

using namespace rso;
using namespace win;

namespace bb
{
	bool operator < (const SBattleType& Lhs_, const SBattleType& Rhs_)
	{
		if (Lhs_.TeamCount < Rhs_.TeamCount)
			return true;
		else if (Lhs_.TeamCount > Rhs_.TeamCount)
			return false;
		else if (Lhs_.TeamMemberCount < Rhs_.TeamMemberCount)
			return true;
		else
			return false;
	}
}

extern CConsoleCtrlHandler g_ConsoleCtrlHandler;

TMatches g_Matches;
TServer::TDBCallbacks g_BinderDB;
TRecvSsFuncs g_BinderRecvSessionHold;
TRecvFuncs g_BinderRecvM;
TRecvCFuncs g_BinderRecvC;
TRecvSsFuncs g_BinderRecvSs;
TRecvRFuncs g_BinderRecvR;
TMetaData g_MetaData;
TReceiptCheck g_ReceiptCheck;
TMonitor g_Monitor;
int32 g_CCUSended = -1; // 최초 한번 보내기 위함
CUsers g_Users;
CKey g_MasterKey;
TNet g_Net;
CKey g_NetRankingKey;
TNetRanking g_NetRanking;
SRankingRankingInfoNetRs g_RankingInfo;
TTimers g_Timers(TimersCallback);
CLog g_Log(ETarget::Target_Console | ETarget::Target_File, EPeriod::Day, L"Log/", L"Log", ELocale::Korean);
TCommand g_Command;
CPeriod<seconds> g_TimerPeriod = seconds(1);
CPeriod<milliseconds> g_BattlePeriod = milliseconds(16);
CPeriod<seconds> g_CCULogPeriod = seconds(60);
TBattles g_Battles;

TBulkCopyConnect g_BulkCopyConnect;
CIPInfo g_IPInfo{ L"ipv4.bin" };
SOption g_Option;
int32 g_MapIndex = -1;
TCouponDB g_pCouponDB;
EloController eloController;

CUser* GetUser(const CKey& Key_)
{
	auto User = g_Users.get(Key_.PeerNum);
	if (!User)
		return nullptr;

	if (User->Key() != Key_)
		return nullptr;

	return User;
}
void SendRet(const CKey& Key_, ERet Ret_)
{
	DLOG(L"Ret Key[%d] [%d]", Key_.PeerNum, int32(Ret_));
	Send(Key_, SRetNetSc(Ret_));
}
void SendMsg(const CKey& Key_, const wstring& Msg_)
{
	DLOG(L"Msg Key[%d] [%s]", Key_.PeerNum, Msg_);
	Send(Key_, SMsgNetSc(Msg_));
}
bool doesHaveCost(const TResources& resources, const SResourceTypeData& cost)
{
	return doesHaveCost(resources, cost.Type, cost.Data);
}
bool doesHaveCost(const TResources& resources, EResource costType, TResource costValue)
{
	return (resources[(int32)costType] >= costValue);
}
bool doesHaveCost(const TResources& resources, const TResources& cost)
{
	for (size_t i = 0; i < resources.size(); ++i)
	{
		if (resources[i] < cost[i])
			return false;
	}

	return true;
}
TResources getFullResources(void)
{
	TResources Resources;

	for (auto& i : Resources)
		i = MaxValue<TResource>();

	return Resources;
}

TResource getResourceFreeSpace(TResource currentResource, EResource resourceType)
{
	return getResourceFreeSpace(currentResource, (size_t)resourceType);
}
TResource getResourceFreeSpace(TResource currentResource, size_t index)
{
	return g_MetaData->MaxResources[index] - currentResource;
}

void AddResource(TResources& Resources_, size_t Index_, TResource Data_)
{
	Resources_[Index_] = AddResource(Resources_[Index_], Index_, Data_);
}
void AddResource(TResources& Resources_, EResource ResourceType_, TResource Data_)
{
	AddResource(Resources_, (size_t)ResourceType_, Data_);
}
void AddResource(TResources& Resources_, const SResourceTypeData& ResourceTypeData_)
{
	AddResource(Resources_, ResourceTypeData_.Type, ResourceTypeData_.Data);
}

TResource AddResource(TResource Resource_, size_t Index_, TResource Data_)
{
	if (Data_ > 0)
	{
		if (Resource_ + Data_ > g_MetaData->MaxResources[Index_] || Resource_ + Data_ < 0)
			return g_MetaData->MaxResources[Index_];
		else
			return Resource_ + Data_;
	}
	else if (Data_ < 0)
	{
		if (Resource_ + Data_ < 0)
			return 0;
		else
			return Resource_ + Data_;
	}
	else
	{
		return Resource_;
	}
}
TResource AddResource(TResource Resource_, EResource ResourceType_, TResource Data_)
{
	return AddResource(Resource_, (size_t)ResourceType_, Data_);
}
TResource AddResource(TResource Resource_, const SResourceTypeData& ResourceTypeData_)
{
	return AddResource(Resource_, ResourceTypeData_.Type, ResourceTypeData_.Data);
}

void AddResources(TResources& Resources_, const TResources& Added_)
{
	for (size_t i = 0; i < Resources_.size(); ++i)
		AddResource(Resources_, i, Added_[i]);
}
void SetResource(TResources& Resources_, size_t Index_, TResource Data_)
{
	if (Data_ < 0)
		Resources_[Index_] = 0;
	else if (Data_ > g_MetaData->MaxResources[Index_])
		Resources_[Index_] = g_MetaData->MaxResources[Index_];
	else
		Resources_[Index_] = Data_;
}
void SetResource(TResources& Resources_, EResource Resource_, TResource Data_)
{
	SetResource(Resources_, (size_t)Resource_, Data_);
}
void SetResources(TResources& Resources_, const TResources& Set_)
{
	for (size_t i = 0; i < Resources_.size(); ++i)
		SetResource(Resources_, i, Set_[i]);
}
void CheckResource(EResource resourceType, TResource resourceValue)
{
	ASSERTION((int32)resourceType >= 0 && resourceType < EResource::Max&& resourceValue >= 0);
}
void CheckResourceTypeValue(const SResourceTypeData& Resource_)
{
	CheckResource(Resource_.Type, Resource_.Data);
}

void TimersCallback(wstring& Data_)
{
	g_ConsoleCtrlHandler.SetExit();
}
SLoginDBIn GetLoginDBIn(TUID UID_, const SUserLoginInfo& Info_)
{
	return SLoginDBIn(UID_, Info_.Option.OS, Info_.CountryCodeMinuteOffset.CountryCode);
}
ELocale LanguageToLocale(ELanguage Language_)
{
	switch (Language_)
	{
	case ELanguage::English:
		return ELocale::English;

	case ELanguage::Korean:
		return ELocale::Korean;

	default:
		return ELocale::English_UnitedStates;
	}
}

float GetSOverMax(float Acc_, float Vel_, float MaxVel_, float Duration_)
{
	auto S = 0.0f;
	auto ElapsedDurationToMaxVel = (MaxVel_ - Vel_) / Acc_; // ElapsedDurationToMaxVel 은 음수가 아니라고 가정

	if (ElapsedDurationToMaxVel > 0.0f)
		S = GetS(Acc_, Vel_, ElapsedDurationToMaxVel);

	if (Duration_ >= ElapsedDurationToMaxVel) // 변곡점을 지났으면
	{
		Duration_ -= ElapsedDurationToMaxVel;

		if (Duration_ > 0.0f)
			S += (Duration_ * MaxVel_);
	}

	return S;
}
bool canFlap(const SCharacter& character)
{
	return character.BalloonCount > 0 && character.StaminaInfo.Stamina >= 1.0f;
}
bool canPump(const SCharacter& character)
{
	return character.BalloonCount == 0 && character.IsGround && character.Dir == 0;
}
bool IsValidRankingInfo(void)
{
	return (g_RankingInfo.Counter > 0);
}
int32 GetAllMemberCount(const SBattleType& BattleType_)
{
	return BattleType_.TeamCount * BattleType_.TeamMemberCount;
}
bool IsOneOnOneBattle(const SBattleType& BattleType_)
{
	return BattleType_.TeamCount == 2 && BattleType_.TeamMemberCount == 1;
}
bool IsMultiBattle(const SBattleType& BattleType_)
{
	return BattleType_.TeamCount >= 2;
}
