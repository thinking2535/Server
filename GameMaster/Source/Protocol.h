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
	TUID MinUID{};
	TUID MaxUID{};
	SNamePort AuthNamePort{};
	TPort ServerBindPort{};
	int32 NetCThreadCnt{};
	TPort ClientBindPort{};
	SNamePort ClientBindNamePortPub{};
	TPort MasterBindPort{};
	string Title{};
	bool EnableReceipt{};
	SOption()
	{
	}
	SOption(const TPort& MonitorAgentBindPort_, const TUID& MinUID_, const TUID& MaxUID_, const SNamePort& AuthNamePort_, const TPort& ServerBindPort_, const int32& NetCThreadCnt_, const TPort& ClientBindPort_, const SNamePort& ClientBindNamePortPub_, const TPort& MasterBindPort_, const string& Title_, const bool& EnableReceipt_) : MonitorAgentBindPort(MonitorAgentBindPort_), MinUID(MinUID_), MaxUID(MaxUID_), AuthNamePort(AuthNamePort_), ServerBindPort(ServerBindPort_), NetCThreadCnt(NetCThreadCnt_), ClientBindPort(ClientBindPort_), ClientBindNamePortPub(ClientBindNamePortPub_), MasterBindPort(MasterBindPort_), Title(Title_), EnableReceipt(EnableReceipt_)
	{
	}
	SOption(TPort&& MonitorAgentBindPort_, TUID&& MinUID_, TUID&& MaxUID_, SNamePort&& AuthNamePort_, TPort&& ServerBindPort_, int32&& NetCThreadCnt_, TPort&& ClientBindPort_, SNamePort&& ClientBindNamePortPub_, TPort&& MasterBindPort_, string&& Title_, bool&& EnableReceipt_) : MonitorAgentBindPort(std::move(MonitorAgentBindPort_)), MinUID(std::move(MinUID_)), MaxUID(std::move(MaxUID_)), AuthNamePort(std::move(AuthNamePort_)), ServerBindPort(std::move(ServerBindPort_)), NetCThreadCnt(std::move(NetCThreadCnt_)), ClientBindPort(std::move(ClientBindPort_)), ClientBindNamePortPub(std::move(ClientBindNamePortPub_)), MasterBindPort(std::move(MasterBindPort_)), Title(std::move(Title_)), EnableReceipt(std::move(EnableReceipt_))
	{
	}
	void operator << (CStream& Stream_) override
	{
		Stream_ >> MonitorAgentBindPort;
		Stream_ >> MinUID;
		Stream_ >> MaxUID;
		Stream_ >> AuthNamePort;
		Stream_ >> ServerBindPort;
		Stream_ >> NetCThreadCnt;
		Stream_ >> ClientBindPort;
		Stream_ >> ClientBindNamePortPub;
		Stream_ >> MasterBindPort;
		Stream_ >> Title;
		Stream_ >> EnableReceipt;
	}
	void operator << (const Value& Value_) override
	{
		Value_["MonitorAgentBindPort"] >> MonitorAgentBindPort;
		Value_["MinUID"] >> MinUID;
		Value_["MaxUID"] >> MaxUID;
		Value_["AuthNamePort"] >> AuthNamePort;
		Value_["ServerBindPort"] >> ServerBindPort;
		Value_["NetCThreadCnt"] >> NetCThreadCnt;
		Value_["ClientBindPort"] >> ClientBindPort;
		Value_["ClientBindNamePortPub"] >> ClientBindNamePortPub;
		Value_["MasterBindPort"] >> MasterBindPort;
		Value_["Title"] >> Title;
		Value_["EnableReceipt"] >> EnableReceipt;
	}
	void operator >> (CStream& Stream_) const override
	{
		Stream_ << MonitorAgentBindPort;
		Stream_ << MinUID;
		Stream_ << MaxUID;
		Stream_ << AuthNamePort;
		Stream_ << ServerBindPort;
		Stream_ << NetCThreadCnt;
		Stream_ << ClientBindPort;
		Stream_ << ClientBindNamePortPub;
		Stream_ << MasterBindPort;
		Stream_ << Title;
		Stream_ << EnableReceipt;
	}
	void operator >> (Value& Value_) const override
	{
		Value_["MonitorAgentBindPort"] = MonitorAgentBindPort;
		Value_["MinUID"] = MinUID;
		Value_["MaxUID"] = MaxUID;
		Value_["AuthNamePort"] = AuthNamePort;
		Value_["ServerBindPort"] = ServerBindPort;
		Value_["NetCThreadCnt"] = NetCThreadCnt;
		Value_["ClientBindPort"] = ClientBindPort;
		Value_["ClientBindNamePortPub"] = ClientBindNamePortPub;
		Value_["MasterBindPort"] = MasterBindPort;
		Value_["Title"] = Title;
		Value_["EnableReceipt"] = EnableReceipt;
	}
	static wstring StdName(void)
	{
		return 
			GetStdName(TPort()) + L"," + 
			GetStdName(TUID()) + L"," + 
			GetStdName(TUID()) + L"," + 
			GetStdName(SNamePort()) + L"," + 
			GetStdName(TPort()) + L"," + 
			GetStdName(int32()) + L"," + 
			GetStdName(TPort()) + L"," + 
			GetStdName(SNamePort()) + L"," + 
			GetStdName(TPort()) + L"," + 
			GetStdName(string()) + L"," + 
			GetStdName(bool());
	}
	static wstring MemberName(void)
	{
		return 
			GetMemberName(TPort(), L"MonitorAgentBindPort") + L"," + 
			GetMemberName(TUID(), L"MinUID") + L"," + 
			GetMemberName(TUID(), L"MaxUID") + L"," + 
			GetMemberName(SNamePort(), L"AuthNamePort") + L"," + 
			GetMemberName(TPort(), L"ServerBindPort") + L"," + 
			GetMemberName(int32(), L"NetCThreadCnt") + L"," + 
			GetMemberName(TPort(), L"ClientBindPort") + L"," + 
			GetMemberName(SNamePort(), L"ClientBindNamePortPub") + L"," + 
			GetMemberName(TPort(), L"MasterBindPort") + L"," + 
			GetMemberName(string(), L"Title") + L"," + 
			GetMemberName(bool(), L"EnableReceipt");
	}
};
