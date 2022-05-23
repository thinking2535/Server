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
	struct SOption : public SProto
	{
		TPort MonitorAgentBindPort{};
		SNamePort MasterNamePort{};
		int32 NetCThreadCnt{};
		TPort ClientBindPort{};
		SNamePort ClientBindNamePortPub{};
		TPort ServerBindPort{};
		string Title{};
		int8 Debug{};
		bool EndlessGame{};
		SOption()
		{
		}
		SOption(const TPort& MonitorAgentBindPort_, const SNamePort& MasterNamePort_, const int32& NetCThreadCnt_, const TPort& ClientBindPort_, const SNamePort& ClientBindNamePortPub_, const TPort& ServerBindPort_, const string& Title_, const int8& Debug_, const bool& EndlessGame_) : MonitorAgentBindPort(MonitorAgentBindPort_), MasterNamePort(MasterNamePort_), NetCThreadCnt(NetCThreadCnt_), ClientBindPort(ClientBindPort_), ClientBindNamePortPub(ClientBindNamePortPub_), ServerBindPort(ServerBindPort_), Title(Title_), Debug(Debug_), EndlessGame(EndlessGame_)
		{
		}
		SOption(TPort&& MonitorAgentBindPort_, SNamePort&& MasterNamePort_, int32&& NetCThreadCnt_, TPort&& ClientBindPort_, SNamePort&& ClientBindNamePortPub_, TPort&& ServerBindPort_, string&& Title_, int8&& Debug_, bool&& EndlessGame_) : MonitorAgentBindPort(std::move(MonitorAgentBindPort_)), MasterNamePort(std::move(MasterNamePort_)), NetCThreadCnt(std::move(NetCThreadCnt_)), ClientBindPort(std::move(ClientBindPort_)), ClientBindNamePortPub(std::move(ClientBindNamePortPub_)), ServerBindPort(std::move(ServerBindPort_)), Title(std::move(Title_)), Debug(std::move(Debug_)), EndlessGame(std::move(EndlessGame_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> MonitorAgentBindPort;
			Stream_ >> MasterNamePort;
			Stream_ >> NetCThreadCnt;
			Stream_ >> ClientBindPort;
			Stream_ >> ClientBindNamePortPub;
			Stream_ >> ServerBindPort;
			Stream_ >> Title;
			Stream_ >> Debug;
			Stream_ >> EndlessGame;
		}
		void operator << (const Value& Value_) override
		{
			Value_["MonitorAgentBindPort"] >> MonitorAgentBindPort;
			Value_["MasterNamePort"] >> MasterNamePort;
			Value_["NetCThreadCnt"] >> NetCThreadCnt;
			Value_["ClientBindPort"] >> ClientBindPort;
			Value_["ClientBindNamePortPub"] >> ClientBindNamePortPub;
			Value_["ServerBindPort"] >> ServerBindPort;
			Value_["Title"] >> Title;
			Value_["Debug"] >> Debug;
			Value_["EndlessGame"] >> EndlessGame;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << MonitorAgentBindPort;
			Stream_ << MasterNamePort;
			Stream_ << NetCThreadCnt;
			Stream_ << ClientBindPort;
			Stream_ << ClientBindNamePortPub;
			Stream_ << ServerBindPort;
			Stream_ << Title;
			Stream_ << Debug;
			Stream_ << EndlessGame;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["MonitorAgentBindPort"] = MonitorAgentBindPort;
			Value_["MasterNamePort"] = MasterNamePort;
			Value_["NetCThreadCnt"] = NetCThreadCnt;
			Value_["ClientBindPort"] = ClientBindPort;
			Value_["ClientBindNamePortPub"] = ClientBindNamePortPub;
			Value_["ServerBindPort"] = ServerBindPort;
			Value_["Title"] = Title;
			Value_["Debug"] = Debug;
			Value_["EndlessGame"] = EndlessGame;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TPort()) + L"," + 
				GetStdName(SNamePort()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TPort()) + L"," + 
				GetStdName(SNamePort()) + L"," + 
				GetStdName(TPort()) + L"," + 
				GetStdName(string()) + L"," + 
				GetStdName(int8()) + L"," + 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TPort(), L"MonitorAgentBindPort") + L"," + 
				GetMemberName(SNamePort(), L"MasterNamePort") + L"," + 
				GetMemberName(int32(), L"NetCThreadCnt") + L"," + 
				GetMemberName(TPort(), L"ClientBindPort") + L"," + 
				GetMemberName(SNamePort(), L"ClientBindNamePortPub") + L"," + 
				GetMemberName(TPort(), L"ServerBindPort") + L"," + 
				GetMemberName(string(), L"Title") + L"," + 
				GetMemberName(int8(), L"Debug") + L"," + 
				GetMemberName(bool(), L"EndlessGame");
		}
	};
	struct SOptionRanking : public SProto
	{
		SNamePort RankingNamePort{};
		SOptionRanking()
		{
		}
		SOptionRanking(const SNamePort& RankingNamePort_) : RankingNamePort(RankingNamePort_)
		{
		}
		SOptionRanking(SNamePort&& RankingNamePort_) : RankingNamePort(std::move(RankingNamePort_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> RankingNamePort;
		}
		void operator << (const Value& Value_) override
		{
			Value_["RankingNamePort"] >> RankingNamePort;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << RankingNamePort;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["RankingNamePort"] = RankingNamePort;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SNamePort());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SNamePort(), L"RankingNamePort");
		}
	};
	struct SDBOptions : public SProto
	{
		SDBOption Game{};
		SDBOption Log{};
		SDBOptions()
		{
		}
		SDBOptions(const SDBOption& Game_, const SDBOption& Log_) : Game(Game_), Log(Log_)
		{
		}
		SDBOptions(SDBOption&& Game_, SDBOption&& Log_) : Game(std::move(Game_)), Log(std::move(Log_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Game;
			Stream_ >> Log;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Game"] >> Game;
			Value_["Log"] >> Log;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Game;
			Stream_ << Log;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Game"] = Game;
			Value_["Log"] = Log;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SDBOption()) + L"," + 
				GetStdName(SDBOption());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SDBOption(), L"Game") + L"," + 
				GetMemberName(SDBOption(), L"Log");
		}
	};
}
