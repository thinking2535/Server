#pragma once

#include <string>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <Rso/Core/Stream.h>
#include <Rso/Json/Json.h>

#include "MetaProtocol.h"
namespace bb
{
	enum class EProtoNetSs
	{
		Message,
		Max,
		Null,
	};
	enum class EProtoRankingNetSr
	{
		UpdateMulti,
		UpdateSingle,
		UpdateIsland,
	};
	enum class EProtoRankingNetRs
	{
		RankingInfo,
		UserPointMin,
	};
	struct SRankingUpdateMultiNetSr : public SProto
	{
		TRankingUsers UsersChanged{};
		SRankingUpdateMultiNetSr()
		{
		}
		SRankingUpdateMultiNetSr(const TRankingUsers& UsersChanged_) : UsersChanged(UsersChanged_)
		{
		}
		SRankingUpdateMultiNetSr(TRankingUsers&& UsersChanged_) : UsersChanged(std::move(UsersChanged_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UsersChanged;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UsersChanged"] >> UsersChanged;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UsersChanged;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UsersChanged"] = UsersChanged;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TRankingUsers());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TRankingUsers(), L"UsersChanged");
		}
	};
	struct SRankingUpdateSingleNetSr : public SProto
	{
		SRankingUser UserSingle{};
		SRankingUpdateSingleNetSr()
		{
		}
		SRankingUpdateSingleNetSr(const SRankingUser& UserSingle_) : UserSingle(UserSingle_)
		{
		}
		SRankingUpdateSingleNetSr(SRankingUser&& UserSingle_) : UserSingle(std::move(UserSingle_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UserSingle;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UserSingle"] >> UserSingle;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UserSingle;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UserSingle"] = UserSingle;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRankingUser());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRankingUser(), L"UserSingle");
		}
	};
	struct SRankingUpdateIslandNetSr : public SProto
	{
		SRankingUser UserIsland{};
		SRankingUpdateIslandNetSr()
		{
		}
		SRankingUpdateIslandNetSr(const SRankingUser& UserIsland_) : UserIsland(UserIsland_)
		{
		}
		SRankingUpdateIslandNetSr(SRankingUser&& UserIsland_) : UserIsland(std::move(UserIsland_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UserIsland;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UserIsland"] >> UserIsland;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UserIsland;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UserIsland"] = UserIsland;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRankingUser());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRankingUser(), L"UserIsland");
		}
	};
	struct SRankingRankingInfoNetRs : public SProto
	{
		int64 Counter{};
		TRankingPointArray UserPointMinArray{};
		TRankingRewardsArray RewardsArray{};
		SRankingRankingInfoNetRs()
		{
		}
		SRankingRankingInfoNetRs(const int64& Counter_, const TRankingPointArray& UserPointMinArray_, const TRankingRewardsArray& RewardsArray_) : Counter(Counter_), UserPointMinArray(UserPointMinArray_), RewardsArray(RewardsArray_)
		{
		}
		SRankingRankingInfoNetRs(int64&& Counter_, TRankingPointArray&& UserPointMinArray_, TRankingRewardsArray&& RewardsArray_) : Counter(std::move(Counter_)), UserPointMinArray(std::move(UserPointMinArray_)), RewardsArray(std::move(RewardsArray_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Counter;
			Stream_ >> UserPointMinArray;
			Stream_ >> RewardsArray;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Counter"] >> Counter;
			Value_["UserPointMinArray"] >> UserPointMinArray;
			Value_["RewardsArray"] >> RewardsArray;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Counter;
			Stream_ << UserPointMinArray;
			Stream_ << RewardsArray;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Counter"] = Counter;
			Value_["UserPointMinArray"] = UserPointMinArray;
			Value_["RewardsArray"] = RewardsArray;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(TRankingPointArray()) + L"," + 
				GetStdName(TRankingRewardsArray());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Counter") + L"," + 
				GetMemberName(TRankingPointArray(), L"UserPointMinArray") + L"," + 
				GetMemberName(TRankingRewardsArray(), L"RewardsArray");
		}
	};
}
