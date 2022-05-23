#pragma once

#include <string>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <Rso/Core/Stream.h>
#include <Rso/Json/Json.h>

namespace bb
{
	using namespace std;
	using namespace core;
	using namespace json;
	enum class EGameServerProto
	{
		AmAuthInfo,
		AmReceiveAccessToken,
		AmPushMessage,
	};
	struct SAmAuthInfo : public SProto
	{
		string FCMServerKey{};
		string ReceiptPackageName{};
		string ReceiptAccessToken{};
		SAmAuthInfo()
		{
		}
		SAmAuthInfo(const string& FCMServerKey_, const string& ReceiptPackageName_, const string& ReceiptAccessToken_) : FCMServerKey(FCMServerKey_), ReceiptPackageName(ReceiptPackageName_), ReceiptAccessToken(ReceiptAccessToken_)
		{
		}
		SAmAuthInfo(string&& FCMServerKey_, string&& ReceiptPackageName_, string&& ReceiptAccessToken_) : FCMServerKey(std::move(FCMServerKey_)), ReceiptPackageName(std::move(ReceiptPackageName_)), ReceiptAccessToken(std::move(ReceiptAccessToken_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> FCMServerKey;
			Stream_ >> ReceiptPackageName;
			Stream_ >> ReceiptAccessToken;
		}
		void operator << (const Value& Value_) override
		{
			Value_["FCMServerKey"] >> FCMServerKey;
			Value_["ReceiptPackageName"] >> ReceiptPackageName;
			Value_["ReceiptAccessToken"] >> ReceiptAccessToken;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << FCMServerKey;
			Stream_ << ReceiptPackageName;
			Stream_ << ReceiptAccessToken;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["FCMServerKey"] = FCMServerKey;
			Value_["ReceiptPackageName"] = ReceiptPackageName;
			Value_["ReceiptAccessToken"] = ReceiptAccessToken;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(string()) + L"," + 
				GetStdName(string()) + L"," + 
				GetStdName(string());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(string(), L"FCMServerKey") + L"," + 
				GetMemberName(string(), L"ReceiptPackageName") + L"," + 
				GetMemberName(string(), L"ReceiptAccessToken");
		}
	};
	struct SAmReceiveAccessToken : public SProto
	{
		string Token{};
		SAmReceiveAccessToken()
		{
		}
		SAmReceiveAccessToken(const string& Token_) : Token(Token_)
		{
		}
		SAmReceiveAccessToken(string&& Token_) : Token(std::move(Token_))
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
			return 
				GetStdName(string());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(string(), L"Token");
		}
	};
	struct SGameServerHeader : public SProto
	{
		EGameServerProto Proto{};
		SGameServerHeader()
		{
		}
		SGameServerHeader(const EGameServerProto& Proto_) : Proto(Proto_)
		{
		}
		SGameServerHeader(EGameServerProto&& Proto_) : Proto(std::move(Proto_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Proto;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Proto"] >> Proto;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Proto;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Proto"] = Proto;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(EGameServerProto());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(EGameServerProto(), L"Proto");
		}
	};
}
