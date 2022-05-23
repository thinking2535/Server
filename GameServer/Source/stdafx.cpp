#include "stdafx.h"
#include <Rso/Win/ConsoleCtrlHandler.h>

using namespace rso;
using namespace win;

extern CConsoleCtrlHandler g_ConsoleCtrlHandler;

TMatches g_Matches;
TArrowDodgeBattles g_ArrowDodgeBattles;
TRooms g_Rooms;
TServer::TDBCallbacks g_BinderDB;
TRecvSsFuncs g_BinderRecvSessionHold;
TRecvFuncs g_BinderRecvM;
TRecvCFuncs g_BinderRecvC;
TRecvSsFuncs g_BinderRecvSs;
TRecvRFuncs g_BinderRecvR;
TGameData g_GameData;
TReceiptCheck g_ReceiptCheck;
TMonitor g_Monitor;
int32 g_CCUSended = -1; // ���� �ѹ� ������ ����
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
CPeriod<seconds> g_CCULogPeriod = seconds(60);
seconds g_BattleWaitDuration = seconds(30); // jjj �����ð� ó��
TBattles g_Battles;
TSingleBattles g_SingleBattles;

TBulkCopyConnect g_BulkCopyConnect;
CIPInfo g_IPInfo{ L"ipv4.bin" };
SOption g_Option;
default_random_engine en;
int32 g_MapIndex = -1;
TCouponDB g_pCouponDB;

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
bool IsDia(EResource Resource_)
{
	return (Resource_ == EResource::Dia || Resource_ == EResource::DiaPaid);
}
bool HaveCost(const TResources& Resources_, EResource CostType_, TResource Cost_)
{
	if (IsDia(CostType_))
		return (GetDia(Resources_) >= Cost_);
	else
		return (Resources_[(int)CostType_] >= Cost_);
}
bool HaveCost(const TResources& Resources_, const TResources& Cost_)
{
	TResource DiaResource = 0;
	TResource DiaCost = 0;

	for (size_t i = 0; i < Resources_.size(); ++i)
	{
		if (IsDia((EResource)i))
		{
			DiaResource += Resources_[i];
			DiaCost += Cost_[i];
		}
		else if (Resources_[i] < Cost_[i])
		{
			return false;
		}
	}

	return (DiaResource >= DiaCost);
}
static_assert(EResource::Dia < EResource::DiaPaid, "Must Be EResource::Dia < EResource::DiaPaid");
TResource GetDia(const TResources& Resources_)
{
	TResource Dia = 0;
	for (size_t i = 0; i < Resources_.size(); ++i)
	{
		if (IsDia((EResource)i))
			Dia += Resources_[i];
	}

	return Dia;
}
void SubDia(TResources& Resources_, TResource Dia_)
{
	for (size_t i = 0; i < Resources_.size(); ++i)
	{
		if ((EResource)i == EResource::Dia) // DiaPaid ���ö� ���� DiaAdded ���� ����
		{
			if (Resources_[i] - Dia_ < 0)
			{
				Dia_ -= Resources_[i];
				Resources_[i] = 0;
			}
			else
			{
				Resources_[i] -= Dia_;
				Dia_ = 0;
			}
		}
		else if ((EResource)i == EResource::DiaPaid)
		{
			if (Resources_[i] - Dia_ < 0)
				Resources_[i] = 0;
			else
				Resources_[i] -= Dia_;

			Dia_ = 0;
		}
	}
}
void AddResource(TResources& Resources_, size_t Index_, TResource Data_)
{
	if (Resources_[Index_] + Data_ < 0)
		Resources_[Index_] = MaxValue<TResource>();
	else
		Resources_[Index_] += Data_;
}
void AddResource(TResources& Resources_, EResource Resource_, TResource Data_)
{
	AddResource(Resources_, (size_t)Resource_, Data_);
}
void SubResource(TResources& Resources_, size_t Index_, TResource Data_)
{
	if (Resources_[Index_] - Data_ < 0)
		Resources_[Index_] = 0;
	else
		Resources_[Index_] -= Data_;
}
void SubResource(TResources& Resources_, EResource Resource_, TResource Data_)
{
	if (IsDia(Resource_))
		SubDia(Resources_, Data_);
	else
		SubResource(Resources_, (size_t)Resource_, Data_);
}
void AddResources(TResources& Resources_, const TResources& Added_)
{
	for (size_t i = 0; i < Resources_.size(); ++i)
		AddResource(Resources_, i, Added_[i]);
}
void SubResources(TResources& Resources_, const TResources& Added_)
{
	for (size_t i = 0; i < Resources_.size(); ++i)
	{
		if (IsDia((EResource)i))
			continue;

		SubResource(Resources_, i, Added_[i]);
	}

	SubDia(Resources_, GetDia(Added_));
}
void SetResource(TResources& Resources_, size_t Index_, TResource Data_)
{
	if (Data_ < 0)
		Resources_[Index_] = 0;
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
void CheckResourceTypeValue(const SResourceTypeData& Resource_)
{
	ASSERTION((int32)Resource_.Type >= 0 && Resource_.Type < EResource::Max && Resource_.Data >= 0);
}
TResources GetResources(EResource Type_, TResource Data_)
{
	TResources Resources{};
	Resources[(size_t)Type_] = Data_;
	return Resources;
}
TResources GetResources(const SResourceTypeData& Resource_)
{
	TResources Resources{};
	Resources[(size_t)Resource_.Type] = Resource_.Data;
	return Resources;
}
TResources CheckAndGetResources(const SResourceTypeData& Resource_)
{
	CheckResourceTypeValue(Resource_);
	return GetResources(Resource_);
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

bool operator < (const SBattleType& Lhs_, const SBattleType& Rhs_)
{
	if (Lhs_.MemberCount < Rhs_.MemberCount)
		return true;
	else if (Lhs_.MemberCount > Rhs_.MemberCount)
		return false;
	else if (Lhs_.TeamCount < Rhs_.TeamCount)
		return true;
	else
		return false;
}
bool IsOverlapped(const SPoint& Pos0_, const SPoint& Pos1_) // �� ��ǥ�� % ������ X�� ū ���� ���(+ Width ���� �ʴ�)���� �ϰ� ��ø�˻�
{
	if (Pos0_.X < Pos1_.X)
		return IsOverlapped(Pos0_, GetCharRect(Pos1_));
	else
		return IsOverlapped(Pos1_, GetCharRect(Pos0_));
}
float GetSOverMax(float Acc_, float Vel_, float MaxVel_, float Duration_)
{
	auto S = 0.0f;
	auto ElapsedDurationToMaxVel = (MaxVel_ - Vel_) / Acc_; // ElapsedDurationToMaxVel �� ������ �ƴ϶�� ����

	if (ElapsedDurationToMaxVel > 0.0f)
		S = GetS(Acc_, Vel_, ElapsedDurationToMaxVel);

	if (Duration_ >= ElapsedDurationToMaxVel) // �������� ��������
	{
		Duration_ -= ElapsedDurationToMaxVel;

		if (Duration_ > 0.0f)
			S += (Duration_ * MaxVel_);
	}

	return S;
}
float GetMaxVelDown(const SCharacter& Char_, const SCharacterMeta* pMeta_)
{
	if (Char_.BalloonCount > 0)
		return -pMeta_->MaxVelDown;
	else if (Char_.BalloonCount == 0)
		return -c_MaxVelParachuteY;
	else
		return -c_MaxVelDeadY;
}
void Center(SCharacter& Char_)
{
	Char_.Dir = 0;
	Char_.Acc.X = 0.0f;
}
void LeftRight(SCharacter& Char_, const SCharacterMeta* pMeta_, int8 Dir_)
{
	Char_.Dir = Dir_;

	if (Char_.Face != Dir_)
		Char_.Face = Dir_;

	if (Char_.IsGround)
	{
		Char_.Acc.X = pMeta_->RunAcc * Char_.Dir;
		Char_.PumpInfo.Count = 0;
	}
	else if (Char_.BalloonCount == 0)
	{
		Char_.Acc.X = c_ParachuteAccX * Char_.Dir;
	}
}
void Fly(SCharacter& Char_)
{
	Char_.IsGround = false;

	if (Char_.BalloonCount == 0)
		Char_.Acc.X = c_ParachuteAccX * Char_.Dir;
}
void Land(SCharacter& Char_, const SCharacterMeta* pMeta_)
{
	Char_.IsGround = true;
	Char_.Acc.X = pMeta_->RunAcc * Char_.Dir;
}
bool IsValidRankingInfo(void)
{
	return (g_RankingInfo.Counter > 0);
}