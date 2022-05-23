#pragma once

#include <string>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <Rso/Core/Stream.h>
#include <Rso/Json/Json.h>

#include <Rso/Game/Protocol.h>
#include <GameServer/Common/NetProtocol.h>
namespace bb
{
	using namespace rso;
	using namespace game;
	enum class EProtoNetSm
	{
		FCMTokenSet,
		FCMTokenUnset,
		FCMCanPushAtNight,
		ChangeLanguage,
		Max,
		Null,
	};
	enum class EProtoNetMs
	{
		ReceiptInitialize,
		ReceiptAccessToken,
		Max,
		Null,
	};
	struct SReceiptInitializeNetMs : public SProto
	{
		string PackageName{};
		string AccessToken{};
		SReceiptInitializeNetMs()
		{
		}
		SReceiptInitializeNetMs(const string& PackageName_, const string& AccessToken_) : PackageName(PackageName_), AccessToken(AccessToken_)
		{
		}
		SReceiptInitializeNetMs(string&& PackageName_, string&& AccessToken_) : PackageName(std::move(PackageName_)), AccessToken(std::move(AccessToken_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> PackageName;
			Stream_ >> AccessToken;
		}
		void operator << (const Value& Value_) override
		{
			Value_["PackageName"] >> PackageName;
			Value_["AccessToken"] >> AccessToken;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << PackageName;
			Stream_ << AccessToken;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["PackageName"] = PackageName;
			Value_["AccessToken"] = AccessToken;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(string()) + L"," + 
				GetStdName(string());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(string(), L"PackageName") + L"," + 
				GetMemberName(string(), L"AccessToken");
		}
	};
	struct SReceiptAccessTokenNetMs : public SProto
	{
		string Token{};
		SReceiptAccessTokenNetMs()
		{
		}
		SReceiptAccessTokenNetMs(const string& Token_) : Token(Token_)
		{
		}
		SReceiptAccessTokenNetMs(string&& Token_) : Token(std::move(Token_))
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
	struct SFCMTokenSetNetSm : public SProto
	{
		TUID UID{};
		wstring Token{};
		int32 MinuteOffset{};
		SFCMTokenSetNetSm()
		{
		}
		SFCMTokenSetNetSm(const TUID& UID_, const wstring& Token_, const int32& MinuteOffset_) : UID(UID_), Token(Token_), MinuteOffset(MinuteOffset_)
		{
		}
		SFCMTokenSetNetSm(TUID&& UID_, wstring&& Token_, int32&& MinuteOffset_) : UID(std::move(UID_)), Token(std::move(Token_)), MinuteOffset(std::move(MinuteOffset_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Token;
			Stream_ >> MinuteOffset;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Token"] >> Token;
			Value_["MinuteOffset"] >> MinuteOffset;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Token;
			Stream_ << MinuteOffset;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Token"] = Token;
			Value_["MinuteOffset"] = MinuteOffset;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(wstring()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(wstring(), L"Token") + L"," + 
				GetMemberName(int32(), L"MinuteOffset");
		}
	};
	struct SFCMTokenUnsetNetSm : public SProto
	{
		TUID UID{};
		SFCMTokenUnsetNetSm()
		{
		}
		SFCMTokenUnsetNetSm(const TUID& UID_) : UID(UID_)
		{
		}
		SFCMTokenUnsetNetSm(TUID&& UID_) : UID(std::move(UID_))
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
			return 
				GetStdName(TUID());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID");
		}
	};
	struct SFCMCanPushAtNightNetSm : public SProto
	{
		TUID UID{};
		bool CanPush{};
		SFCMCanPushAtNightNetSm()
		{
		}
		SFCMCanPushAtNightNetSm(const TUID& UID_, const bool& CanPush_) : UID(UID_), CanPush(CanPush_)
		{
		}
		SFCMCanPushAtNightNetSm(TUID&& UID_, bool&& CanPush_) : UID(std::move(UID_)), CanPush(std::move(CanPush_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> CanPush;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["CanPush"] >> CanPush;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << CanPush;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["CanPush"] = CanPush;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(bool(), L"CanPush");
		}
	};
	struct SChangeLanguageNetSm : public SProto
	{
		TUID UID{};
		ELanguage Language{};
		SChangeLanguageNetSm()
		{
		}
		SChangeLanguageNetSm(const TUID& UID_, const ELanguage& Language_) : UID(UID_), Language(Language_)
		{
		}
		SChangeLanguageNetSm(TUID&& UID_, ELanguage&& Language_) : UID(std::move(UID_)), Language(std::move(Language_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Language;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Language"] >> Language;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Language;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Language"] = Language;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(ELanguage());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(ELanguage(), L"Language");
		}
	};
}
