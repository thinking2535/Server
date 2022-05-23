#pragma once

#include <string>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <Rso/Core/Stream.h>
#include <Rso/Json/Json.h>

#include <Rso/MSSQL/Protocol.h>
#include <GameServer/Common/NetProtocol.h>
namespace bb
{
	using namespace rso;
	using namespace net;
	using namespace mssql;
	enum class EProtoRankingDB
	{
		RankingConfigLoad,
		RankingRefresh,
		RankingUpdate,
		RankingUpdateSingle,
		RankingUpdateIsland,
	};
	struct SOption : public SProto
	{
		TPort MonitorAgentBindPort{};
		TPort GameServerBindPort{};
		SNamePort MasterNamePort{};
		int32 NetCThreadCnt{};
		TPort ChildBindPort{};
		TPort ClientBindPort{};
		SNamePort ClientBindNamePortPub{};
		string Title{};
		int32 MaxList{};
		SOption()
		{
		}
		SOption(const TPort& MonitorAgentBindPort_, const TPort& GameServerBindPort_, const SNamePort& MasterNamePort_, const int32& NetCThreadCnt_, const TPort& ChildBindPort_, const TPort& ClientBindPort_, const SNamePort& ClientBindNamePortPub_, const string& Title_, const int32& MaxList_) : MonitorAgentBindPort(MonitorAgentBindPort_), GameServerBindPort(GameServerBindPort_), MasterNamePort(MasterNamePort_), NetCThreadCnt(NetCThreadCnt_), ChildBindPort(ChildBindPort_), ClientBindPort(ClientBindPort_), ClientBindNamePortPub(ClientBindNamePortPub_), Title(Title_), MaxList(MaxList_)
		{
		}
		SOption(TPort&& MonitorAgentBindPort_, TPort&& GameServerBindPort_, SNamePort&& MasterNamePort_, int32&& NetCThreadCnt_, TPort&& ChildBindPort_, TPort&& ClientBindPort_, SNamePort&& ClientBindNamePortPub_, string&& Title_, int32&& MaxList_) : MonitorAgentBindPort(std::move(MonitorAgentBindPort_)), GameServerBindPort(std::move(GameServerBindPort_)), MasterNamePort(std::move(MasterNamePort_)), NetCThreadCnt(std::move(NetCThreadCnt_)), ChildBindPort(std::move(ChildBindPort_)), ClientBindPort(std::move(ClientBindPort_)), ClientBindNamePortPub(std::move(ClientBindNamePortPub_)), Title(std::move(Title_)), MaxList(std::move(MaxList_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> MonitorAgentBindPort;
			Stream_ >> GameServerBindPort;
			Stream_ >> MasterNamePort;
			Stream_ >> NetCThreadCnt;
			Stream_ >> ChildBindPort;
			Stream_ >> ClientBindPort;
			Stream_ >> ClientBindNamePortPub;
			Stream_ >> Title;
			Stream_ >> MaxList;
		}
		void operator << (const Value& Value_) override
		{
			Value_["MonitorAgentBindPort"] >> MonitorAgentBindPort;
			Value_["GameServerBindPort"] >> GameServerBindPort;
			Value_["MasterNamePort"] >> MasterNamePort;
			Value_["NetCThreadCnt"] >> NetCThreadCnt;
			Value_["ChildBindPort"] >> ChildBindPort;
			Value_["ClientBindPort"] >> ClientBindPort;
			Value_["ClientBindNamePortPub"] >> ClientBindNamePortPub;
			Value_["Title"] >> Title;
			Value_["MaxList"] >> MaxList;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << MonitorAgentBindPort;
			Stream_ << GameServerBindPort;
			Stream_ << MasterNamePort;
			Stream_ << NetCThreadCnt;
			Stream_ << ChildBindPort;
			Stream_ << ClientBindPort;
			Stream_ << ClientBindNamePortPub;
			Stream_ << Title;
			Stream_ << MaxList;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["MonitorAgentBindPort"] = MonitorAgentBindPort;
			Value_["GameServerBindPort"] = GameServerBindPort;
			Value_["MasterNamePort"] = MasterNamePort;
			Value_["NetCThreadCnt"] = NetCThreadCnt;
			Value_["ChildBindPort"] = ChildBindPort;
			Value_["ClientBindPort"] = ClientBindPort;
			Value_["ClientBindNamePortPub"] = ClientBindNamePortPub;
			Value_["Title"] = Title;
			Value_["MaxList"] = MaxList;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TPort()) + L"," + 
				GetStdName(TPort()) + L"," + 
				GetStdName(SNamePort()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TPort()) + L"," + 
				GetStdName(TPort()) + L"," + 
				GetStdName(SNamePort()) + L"," + 
				GetStdName(string()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TPort(), L"MonitorAgentBindPort") + L"," + 
				GetMemberName(TPort(), L"GameServerBindPort") + L"," + 
				GetMemberName(SNamePort(), L"MasterNamePort") + L"," + 
				GetMemberName(int32(), L"NetCThreadCnt") + L"," + 
				GetMemberName(TPort(), L"ChildBindPort") + L"," + 
				GetMemberName(TPort(), L"ClientBindPort") + L"," + 
				GetMemberName(SNamePort(), L"ClientBindNamePortPub") + L"," + 
				GetMemberName(string(), L"Title") + L"," + 
				GetMemberName(int32(), L"MaxList");
		}
	};
	struct SRankingConfigLoadDBIn : public SProto
	{
		system_clock::time_point StartTimePoint{};
		SRankingConfigLoadDBIn()
		{
		}
		SRankingConfigLoadDBIn(const system_clock::time_point& StartTimePoint_) : StartTimePoint(StartTimePoint_)
		{
		}
		SRankingConfigLoadDBIn(system_clock::time_point&& StartTimePoint_) : StartTimePoint(std::move(StartTimePoint_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> StartTimePoint;
		}
		void operator << (const Value& Value_) override
		{
			Value_["StartTimePoint"] >> StartTimePoint;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << StartTimePoint;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["StartTimePoint"] = StartTimePoint;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(system_clock::time_point(), L"StartTimePoint");
		}
	};
	struct SRankingConfigDB : public SProto
	{
		int64 Counter{};
		system_clock::time_point ExpireTimePoint{};
		SRankingConfigDB()
		{
		}
		SRankingConfigDB(const int64& Counter_, const system_clock::time_point& ExpireTimePoint_) : Counter(Counter_), ExpireTimePoint(ExpireTimePoint_)
		{
		}
		SRankingConfigDB(int64&& Counter_, system_clock::time_point&& ExpireTimePoint_) : Counter(std::move(Counter_)), ExpireTimePoint(std::move(ExpireTimePoint_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Counter;
			Stream_ >> ExpireTimePoint;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Counter"] >> Counter;
			Value_["ExpireTimePoint"] >> ExpireTimePoint;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Counter;
			Stream_ << ExpireTimePoint;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Counter"] = Counter;
			Value_["ExpireTimePoint"] = ExpireTimePoint;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int64()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int64(), L"Counter") + L"," + 
				GetMemberName(system_clock::time_point(), L"ExpireTimePoint");
		}
	};
	struct SRankingConfigLoadDBOut : public SProto
	{
		list<SRankingConfigDB> RankingConfigs{};
		SRankingConfigLoadDBOut()
		{
		}
		SRankingConfigLoadDBOut(const list<SRankingConfigDB>& RankingConfigs_) : RankingConfigs(RankingConfigs_)
		{
		}
		SRankingConfigLoadDBOut(list<SRankingConfigDB>&& RankingConfigs_) : RankingConfigs(std::move(RankingConfigs_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RankingConfigs;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RankingConfigs"] >> RankingConfigs;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RankingConfigs;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RankingConfigs"] = RankingConfigs;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(list<SRankingConfigDB>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(list<SRankingConfigDB>(), L"RankingConfigs");
		}
	};
	struct SRankingRefreshDBIn : public SProto
	{
		SRankingConfigDB Config{};
		TRankingRewards Rewards{};
		TRankingRewards RewardsSingle{};
		TRankingRewards RewardsIsland{};
		SRankingRefreshDBIn()
		{
		}
		SRankingRefreshDBIn(const SRankingConfigDB& Config_, const TRankingRewards& Rewards_, const TRankingRewards& RewardsSingle_, const TRankingRewards& RewardsIsland_) : Config(Config_), Rewards(Rewards_), RewardsSingle(RewardsSingle_), RewardsIsland(RewardsIsland_)
		{
		}
		SRankingRefreshDBIn(SRankingConfigDB&& Config_, TRankingRewards&& Rewards_, TRankingRewards&& RewardsSingle_, TRankingRewards&& RewardsIsland_) : Config(std::move(Config_)), Rewards(std::move(Rewards_)), RewardsSingle(std::move(RewardsSingle_)), RewardsIsland(std::move(RewardsIsland_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Config;
			Stream_ >> Rewards;
			Stream_ >> RewardsSingle;
			Stream_ >> RewardsIsland;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Config"] >> Config;
			Value_["Rewards"] >> Rewards;
			Value_["RewardsSingle"] >> RewardsSingle;
			Value_["RewardsIsland"] >> RewardsIsland;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Config;
			Stream_ << Rewards;
			Stream_ << RewardsSingle;
			Stream_ << RewardsIsland;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Config"] = Config;
			Value_["Rewards"] = Rewards;
			Value_["RewardsSingle"] = RewardsSingle;
			Value_["RewardsIsland"] = RewardsIsland;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRankingConfigDB()) + L"," + 
				GetStdName(TRankingRewards()) + L"," + 
				GetStdName(TRankingRewards()) + L"," + 
				GetStdName(TRankingRewards());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRankingConfigDB(), L"Config") + L"," + 
				GetMemberName(TRankingRewards(), L"Rewards") + L"," + 
				GetMemberName(TRankingRewards(), L"RewardsSingle") + L"," + 
				GetMemberName(TRankingRewards(), L"RewardsIsland");
		}
	};
	struct SRankingLoadDBIn : public SProto
	{
		int32 MaxList{};
		SRankingLoadDBIn()
		{
		}
		SRankingLoadDBIn(const int32& MaxList_) : MaxList(MaxList_)
		{
		}
		SRankingLoadDBIn(int32&& MaxList_) : MaxList(std::move(MaxList_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> MaxList;
		}
		void operator << (const Value& Value_) override
		{
			Value_["MaxList"] >> MaxList;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << MaxList;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["MaxList"] = MaxList;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"MaxList");
		}
	};
	struct SRankingLoadDBOut : public SProto
	{
		list<SRankingUser> RankingUsers{};
		SRankingLoadDBOut()
		{
		}
		SRankingLoadDBOut(const list<SRankingUser>& RankingUsers_) : RankingUsers(RankingUsers_)
		{
		}
		SRankingLoadDBOut(list<SRankingUser>&& RankingUsers_) : RankingUsers(std::move(RankingUsers_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RankingUsers;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RankingUsers"] >> RankingUsers;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RankingUsers;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RankingUsers"] = RankingUsers;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(list<SRankingUser>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(list<SRankingUser>(), L"RankingUsers");
		}
	};
	struct SRankingLoadSingleDBOut : public SProto
	{
		list<SRankingUserSingle> RankingUserSingles{};
		SRankingLoadSingleDBOut()
		{
		}
		SRankingLoadSingleDBOut(const list<SRankingUserSingle>& RankingUserSingles_) : RankingUserSingles(RankingUserSingles_)
		{
		}
		SRankingLoadSingleDBOut(list<SRankingUserSingle>&& RankingUserSingles_) : RankingUserSingles(std::move(RankingUserSingles_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RankingUserSingles;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RankingUserSingles"] >> RankingUserSingles;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RankingUserSingles;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RankingUserSingles"] = RankingUserSingles;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(list<SRankingUserSingle>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(list<SRankingUserSingle>(), L"RankingUserSingles");
		}
	};
	struct SRankingLoadIslandDBOut : public SProto
	{
		list<SRankingUserIsland> RankingUserIslands{};
		SRankingLoadIslandDBOut()
		{
		}
		SRankingLoadIslandDBOut(const list<SRankingUserIsland>& RankingUserIslands_) : RankingUserIslands(RankingUserIslands_)
		{
		}
		SRankingLoadIslandDBOut(list<SRankingUserIsland>&& RankingUserIslands_) : RankingUserIslands(std::move(RankingUserIslands_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RankingUserIslands;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RankingUserIslands"] >> RankingUserIslands;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RankingUserIslands;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RankingUserIslands"] = RankingUserIslands;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(list<SRankingUserIsland>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(list<SRankingUserIsland>(), L"RankingUserIslands");
		}
	};
	struct SRewardLoadDBIn : public SProto
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
	struct SRewardLoadDBOut : public SProto
	{
		map<TUID,int32> Rewards{};
		SRewardLoadDBOut()
		{
		}
		SRewardLoadDBOut(const map<TUID,int32>& Rewards_) : Rewards(Rewards_)
		{
		}
		SRewardLoadDBOut(map<TUID,int32>&& Rewards_) : Rewards(std::move(Rewards_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Rewards;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Rewards"] >> Rewards;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Rewards;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Rewards"] = Rewards;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(map<TUID,int32>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(map<TUID,int32>(), L"Rewards");
		}
	};
	struct SDummyDBOut : public SProto
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
	struct SRankingUpdateDBIn : public SProto
	{
		TRankingUsers Merged{};
		list<TUID> Deleted{};
		SRankingUpdateDBIn()
		{
		}
		SRankingUpdateDBIn(const TRankingUsers& Merged_, const list<TUID>& Deleted_) : Merged(Merged_), Deleted(Deleted_)
		{
		}
		SRankingUpdateDBIn(TRankingUsers&& Merged_, list<TUID>&& Deleted_) : Merged(std::move(Merged_)), Deleted(std::move(Deleted_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Merged;
			Stream_ >> Deleted;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Merged"] >> Merged;
			Value_["Deleted"] >> Deleted;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Merged;
			Stream_ << Deleted;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Merged"] = Merged;
			Value_["Deleted"] = Deleted;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TRankingUsers()) + L"," + 
				GetStdName(list<TUID>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TRankingUsers(), L"Merged") + L"," + 
				GetMemberName(list<TUID>(), L"Deleted");
		}
	};
	struct SRankingUpdateSingleDBIn : public SProto
	{
		TRankingUserSingles Merged{};
		list<TUID> Deleted{};
		SRankingUpdateSingleDBIn()
		{
		}
		SRankingUpdateSingleDBIn(const TRankingUserSingles& Merged_, const list<TUID>& Deleted_) : Merged(Merged_), Deleted(Deleted_)
		{
		}
		SRankingUpdateSingleDBIn(TRankingUserSingles&& Merged_, list<TUID>&& Deleted_) : Merged(std::move(Merged_)), Deleted(std::move(Deleted_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Merged;
			Stream_ >> Deleted;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Merged"] >> Merged;
			Value_["Deleted"] >> Deleted;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Merged;
			Stream_ << Deleted;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Merged"] = Merged;
			Value_["Deleted"] = Deleted;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TRankingUserSingles()) + L"," + 
				GetStdName(list<TUID>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TRankingUserSingles(), L"Merged") + L"," + 
				GetMemberName(list<TUID>(), L"Deleted");
		}
	};
	struct SRankingUpdateIslandDBIn : public SProto
	{
		TRankingUserIslands Merged{};
		list<TUID> Deleted{};
		SRankingUpdateIslandDBIn()
		{
		}
		SRankingUpdateIslandDBIn(const TRankingUserIslands& Merged_, const list<TUID>& Deleted_) : Merged(Merged_), Deleted(Deleted_)
		{
		}
		SRankingUpdateIslandDBIn(TRankingUserIslands&& Merged_, list<TUID>&& Deleted_) : Merged(std::move(Merged_)), Deleted(std::move(Deleted_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Merged;
			Stream_ >> Deleted;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Merged"] >> Merged;
			Value_["Deleted"] >> Deleted;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Merged;
			Stream_ << Deleted;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Merged"] = Merged;
			Value_["Deleted"] = Deleted;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TRankingUserIslands()) + L"," + 
				GetStdName(list<TUID>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TRankingUserIslands(), L"Merged") + L"," + 
				GetMemberName(list<TUID>(), L"Deleted");
		}
	};
}
