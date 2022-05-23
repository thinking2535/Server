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
using namespace rso;
using namespace net;
using namespace mssql;
struct SOption : public SProto
{
	TPort MonitorAgentBindPort{};
	TPort MasterBindPort{};
	int32 NetCThreadCnt{};
	TPort ClientBindPort{};
	string Title{};
	string FCMServerKey{};
	SOption()
	{
	}
	SOption(const TPort& MonitorAgentBindPort_, const TPort& MasterBindPort_, const int32& NetCThreadCnt_, const TPort& ClientBindPort_, const string& Title_, const string& FCMServerKey_) : MonitorAgentBindPort(MonitorAgentBindPort_), MasterBindPort(MasterBindPort_), NetCThreadCnt(NetCThreadCnt_), ClientBindPort(ClientBindPort_), Title(Title_), FCMServerKey(FCMServerKey_)
	{
	}
	SOption(TPort&& MonitorAgentBindPort_, TPort&& MasterBindPort_, int32&& NetCThreadCnt_, TPort&& ClientBindPort_, string&& Title_, string&& FCMServerKey_) : MonitorAgentBindPort(std::move(MonitorAgentBindPort_)), MasterBindPort(std::move(MasterBindPort_)), NetCThreadCnt(std::move(NetCThreadCnt_)), ClientBindPort(std::move(ClientBindPort_)), Title(std::move(Title_)), FCMServerKey(std::move(FCMServerKey_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> MonitorAgentBindPort;
		Stream_ >> MasterBindPort;
		Stream_ >> NetCThreadCnt;
		Stream_ >> ClientBindPort;
		Stream_ >> Title;
		Stream_ >> FCMServerKey;
	}
	void operator << (const Value& Value_) override
	{
		Value_["MonitorAgentBindPort"] >> MonitorAgentBindPort;
		Value_["MasterBindPort"] >> MasterBindPort;
		Value_["NetCThreadCnt"] >> NetCThreadCnt;
		Value_["ClientBindPort"] >> ClientBindPort;
		Value_["Title"] >> Title;
		Value_["FCMServerKey"] >> FCMServerKey;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << MonitorAgentBindPort;
		Stream_ << MasterBindPort;
		Stream_ << NetCThreadCnt;
		Stream_ << ClientBindPort;
		Stream_ << Title;
		Stream_ << FCMServerKey;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["MonitorAgentBindPort"] = MonitorAgentBindPort;
		Value_["MasterBindPort"] = MasterBindPort;
		Value_["NetCThreadCnt"] = NetCThreadCnt;
		Value_["ClientBindPort"] = ClientBindPort;
		Value_["Title"] = Title;
		Value_["FCMServerKey"] = FCMServerKey;
	}
	static wstring StdName(void)
	{
		return 
			GetStdName(TPort()) + L"," + 
			GetStdName(TPort()) + L"," + 
			GetStdName(int32()) + L"," + 
			GetStdName(TPort()) + L"," + 
			GetStdName(string()) + L"," + 
			GetStdName(string());
	}
	static wstring MemberName(void)
	{
		return 
			GetMemberName(TPort(), L"MonitorAgentBindPort") + L"," + 
			GetMemberName(TPort(), L"MasterBindPort") + L"," + 
			GetMemberName(int32(), L"NetCThreadCnt") + L"," + 
			GetMemberName(TPort(), L"ClientBindPort") + L"," + 
			GetMemberName(string(), L"Title") + L"," + 
			GetMemberName(string(), L"FCMServerKey");
	}
};
