#pragma once

#include <string>
#include <array>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <Rso/Core/Stream.h>
#include <Rso/Json/Json.h>

#include <GameServer/Common/ServerToServerProtocol.h>
namespace bb
{
	enum class EProtoDB
	{
		Join,
		Login,
		Logout,
		SetResources,
		SetUserExp,
		SetPoint,
		SetChar,
		UnsetChar,
		CanPushAtNight,
		ChangeLanguage,
		Buy,
		BuyChar,
		BuyPackage,
		DailyReward,
		SelectChar,
		BattleEnd,
		UpdateInvalidDisconnectInfo,
		UpdateMatchBlockEndTime,
		ArrowDodgeBattleStart,
		ArrowDodgeBattleEnd,
		FlyAwayBattleStart,
		FlyAwayBattleEnd,
		Gacha,
		RankReward,
		QuestNew,
		QuestDel,
		QuestDone,
		QuestReward,
		QuestNext,
		QuestDailyCompleteReward,
		ChangeNickBegin,
		ChangeNickEnd,
		ChangeNickEndFail,
		CouponUse,
		TutorialReward,
		RankingReward,
		CheckID,
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
	struct SJoinDB : public SUserCore
	{
		SJoinDB()
		{
		}
		SJoinDB(const SUserCore& Super_) : SUserCore(Super_)
		{
		}
		SJoinDB(SUserCore&& Super_) : SUserCore(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SUserCore::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			SUserCore::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			SUserCore::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			SUserCore::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SUserCore());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SUserCore(), L"");
		}
	};
	struct SJoinDBIn : public SProto
	{
		TUID UID{};
		SJoinDB Info{};
		system_clock::time_point InsertedTimePoint{};
		ELanguage Language{};
		EOS OS{};
		string CountryCode{};
		vector<int32> CharCodes{};
		SJoinDBIn()
		{
		}
		SJoinDBIn(const TUID& UID_, const SJoinDB& Info_, const system_clock::time_point& InsertedTimePoint_, const ELanguage& Language_, const EOS& OS_, const string& CountryCode_, const vector<int32>& CharCodes_) : UID(UID_), Info(Info_), InsertedTimePoint(InsertedTimePoint_), Language(Language_), OS(OS_), CountryCode(CountryCode_), CharCodes(CharCodes_)
		{
		}
		SJoinDBIn(TUID&& UID_, SJoinDB&& Info_, system_clock::time_point&& InsertedTimePoint_, ELanguage&& Language_, EOS&& OS_, string&& CountryCode_, vector<int32>&& CharCodes_) : UID(std::move(UID_)), Info(std::move(Info_)), InsertedTimePoint(std::move(InsertedTimePoint_)), Language(std::move(Language_)), OS(std::move(OS_)), CountryCode(std::move(CountryCode_)), CharCodes(std::move(CharCodes_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Info;
			Stream_ >> InsertedTimePoint;
			Stream_ >> Language;
			Stream_ >> OS;
			Stream_ >> CountryCode;
			Stream_ >> CharCodes;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Info"] >> Info;
			Value_["InsertedTimePoint"] >> InsertedTimePoint;
			Value_["Language"] >> Language;
			Value_["OS"] >> OS;
			Value_["CountryCode"] >> CountryCode;
			Value_["CharCodes"] >> CharCodes;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Info;
			Stream_ << InsertedTimePoint;
			Stream_ << Language;
			Stream_ << OS;
			Stream_ << CountryCode;
			Stream_ << CharCodes;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Info"] = Info;
			Value_["InsertedTimePoint"] = InsertedTimePoint;
			Value_["Language"] = Language;
			Value_["OS"] = OS;
			Value_["CountryCode"] = CountryCode;
			Value_["CharCodes"] = CharCodes;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(SJoinDB()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(ELanguage()) + L"," + 
				GetStdName(EOS()) + L"," + 
				GetStdName(string()) + L"," + 
				GetStdName(vector<int32>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(SJoinDB(), L"Info") + L"," + 
				GetMemberName(system_clock::time_point(), L"InsertedTimePoint") + L"," + 
				GetMemberName(ELanguage(), L"Language") + L"," + 
				GetMemberName(EOS(), L"OS") + L"," + 
				GetMemberName(string(), L"CountryCode") + L"," + 
				GetMemberName(vector<int32>(), L"CharCodes");
		}
	};
	struct SLoginDBIn : public SProto
	{
		TUID UID{};
		EOS OS{};
		string CountryCode{};
		SLoginDBIn()
		{
		}
		SLoginDBIn(const TUID& UID_, const EOS& OS_, const string& CountryCode_) : UID(UID_), OS(OS_), CountryCode(CountryCode_)
		{
		}
		SLoginDBIn(TUID&& UID_, EOS&& OS_, string&& CountryCode_) : UID(std::move(UID_)), OS(std::move(OS_)), CountryCode(std::move(CountryCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> OS;
			Stream_ >> CountryCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["OS"] >> OS;
			Value_["CountryCode"] >> CountryCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << OS;
			Stream_ << CountryCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["OS"] = OS;
			Value_["CountryCode"] = CountryCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(EOS()) + L"," + 
				GetStdName(string());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(EOS(), L"OS") + L"," + 
				GetMemberName(string(), L"CountryCode");
		}
	};
	struct SUserDB : public SUserBase
	{
		ELanguage Language{};
		SUserDB()
		{
		}
		SUserDB(const SUserBase& Super_, const ELanguage& Language_) : SUserBase(Super_), Language(Language_)
		{
		}
		SUserDB(SUserBase&& Super_, ELanguage&& Language_) : SUserBase(std::move(Super_)), Language(std::move(Language_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SUserBase::operator << (Stream_);
			Stream_ >> Language;
		}
		void operator << (const Value& Value_) override
		{
			SUserBase::operator << (Value_);
			Value_["Language"] >> Language;
		}
		void operator >> (CStream& Stream_) const override
		{
			SUserBase::operator >> (Stream_);
			Stream_ << Language;
		}
		void operator >> (Value& Value_) const override
		{
			SUserBase::operator >> (Value_);
			Value_["Language"] = Language;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SUserBase()) + L"," + 
				GetStdName(ELanguage());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SUserBase(), L"") + L"," + 
				GetMemberName(ELanguage(), L"Language");
		}
	};
	struct SLoginDBOut : public SProto
	{
		list<SUserDB> Users{};
		TChars Chars{};
		TQuestDBs Quests{};
		set<wstring> Coupons{};
		TPackages Packages{};
		SLoginDBOut()
		{
		}
		SLoginDBOut(const list<SUserDB>& Users_, const TChars& Chars_, const TQuestDBs& Quests_, const set<wstring>& Coupons_, const TPackages& Packages_) : Users(Users_), Chars(Chars_), Quests(Quests_), Coupons(Coupons_), Packages(Packages_)
		{
		}
		SLoginDBOut(list<SUserDB>&& Users_, TChars&& Chars_, TQuestDBs&& Quests_, set<wstring>&& Coupons_, TPackages&& Packages_) : Users(std::move(Users_)), Chars(std::move(Chars_)), Quests(std::move(Quests_)), Coupons(std::move(Coupons_)), Packages(std::move(Packages_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Users;
			Stream_ >> Chars;
			Stream_ >> Quests;
			Stream_ >> Coupons;
			Stream_ >> Packages;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Users"] >> Users;
			Value_["Chars"] >> Chars;
			Value_["Quests"] >> Quests;
			Value_["Coupons"] >> Coupons;
			Value_["Packages"] >> Packages;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Users;
			Stream_ << Chars;
			Stream_ << Quests;
			Stream_ << Coupons;
			Stream_ << Packages;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Users"] = Users;
			Value_["Chars"] = Chars;
			Value_["Quests"] = Quests;
			Value_["Coupons"] = Coupons;
			Value_["Packages"] = Packages;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(list<SUserDB>()) + L"," + 
				GetStdName(TChars()) + L"," + 
				GetStdName(TQuestDBs()) + L"," + 
				GetStdName(set<wstring>()) + L"," + 
				GetStdName(TPackages());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(list<SUserDB>(), L"Users") + L"," + 
				GetMemberName(TChars(), L"Chars") + L"," + 
				GetMemberName(TQuestDBs(), L"Quests") + L"," + 
				GetMemberName(set<wstring>(), L"Coupons") + L"," + 
				GetMemberName(TPackages(), L"Packages");
		}
	};
	struct SLogoutDBIn : public SProto
	{
		TUID UID{};
		system_clock::time_point LogoutTime{};
		SLogoutDBIn()
		{
		}
		SLogoutDBIn(const TUID& UID_, const system_clock::time_point& LogoutTime_) : UID(UID_), LogoutTime(LogoutTime_)
		{
		}
		SLogoutDBIn(TUID&& UID_, system_clock::time_point&& LogoutTime_) : UID(std::move(UID_)), LogoutTime(std::move(LogoutTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> LogoutTime;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["LogoutTime"] >> LogoutTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << LogoutTime;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["LogoutTime"] = LogoutTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(system_clock::time_point(), L"LogoutTime");
		}
	};
	struct SUIDQuestSlotIndexCount : public SQuestSlotIndexCount
	{
		TUID UID{};
		SUIDQuestSlotIndexCount()
		{
		}
		SUIDQuestSlotIndexCount(const SQuestSlotIndexCount& Super_, const TUID& UID_) : SQuestSlotIndexCount(Super_), UID(UID_)
		{
		}
		SUIDQuestSlotIndexCount(SQuestSlotIndexCount&& Super_, TUID&& UID_) : SQuestSlotIndexCount(std::move(Super_)), UID(std::move(UID_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SQuestSlotIndexCount::operator << (Stream_);
			Stream_ >> UID;
		}
		void operator << (const Value& Value_) override
		{
			SQuestSlotIndexCount::operator << (Value_);
			Value_["UID"] >> UID;
		}
		void operator >> (CStream& Stream_) const override
		{
			SQuestSlotIndexCount::operator >> (Stream_);
			Stream_ << UID;
		}
		void operator >> (Value& Value_) const override
		{
			SQuestSlotIndexCount::operator >> (Value_);
			Value_["UID"] = UID;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SQuestSlotIndexCount()) + L"," + 
				GetStdName(TUID());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SQuestSlotIndexCount(), L"") + L"," + 
				GetMemberName(TUID(), L"UID");
		}
	};
	using TDoneQuestDBs = list<SUIDQuestSlotIndexCount>;
	struct SSetResourcesDBIn : public SProto
	{
		TUID UID{};
		TResources Resources{};
		SSetResourcesDBIn()
		{
		}
		SSetResourcesDBIn(const TUID& UID_, const TResources& Resources_) : UID(UID_), Resources(Resources_)
		{
		}
		SSetResourcesDBIn(TUID&& UID_, TResources&& Resources_) : UID(std::move(UID_)), Resources(std::move(Resources_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Resources;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Resources"] >> Resources;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Resources;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Resources"] = Resources;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"Resources");
		}
	};
	struct SSetUserExpDBIn : public SProto
	{
		TUID UID{};
		TExp Exp{};
		SSetUserExpDBIn()
		{
		}
		SSetUserExpDBIn(const TUID& UID_, const TExp& Exp_) : UID(UID_), Exp(Exp_)
		{
		}
		SSetUserExpDBIn(TUID&& UID_, TExp&& Exp_) : UID(std::move(UID_)), Exp(std::move(Exp_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Exp;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Exp"] >> Exp;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Exp;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Exp"] = Exp;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TExp());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TExp(), L"Exp");
		}
	};
	struct SSetPointDBIn : public SProto
	{
		TUID UID{};
		int32 Point{};
		int32 PointBest{};
		SSetPointDBIn()
		{
		}
		SSetPointDBIn(const TUID& UID_, const int32& Point_, const int32& PointBest_) : UID(UID_), Point(Point_), PointBest(PointBest_)
		{
		}
		SSetPointDBIn(TUID&& UID_, int32&& Point_, int32&& PointBest_) : UID(std::move(UID_)), Point(std::move(Point_)), PointBest(std::move(PointBest_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Point;
			Stream_ >> PointBest;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Point"] >> Point;
			Value_["PointBest"] >> PointBest;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Point;
			Stream_ << PointBest;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Point"] = Point;
			Value_["PointBest"] = PointBest;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(int32(), L"Point") + L"," + 
				GetMemberName(int32(), L"PointBest");
		}
	};
	struct SSetCharDBIn : public SProto
	{
		TUID UID{};
		list<int32> CharCodes{};
		SSetCharDBIn()
		{
		}
		SSetCharDBIn(const TUID& UID_, const list<int32>& CharCodes_) : UID(UID_), CharCodes(CharCodes_)
		{
		}
		SSetCharDBIn(TUID&& UID_, list<int32>&& CharCodes_) : UID(std::move(UID_)), CharCodes(std::move(CharCodes_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> CharCodes;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["CharCodes"] >> CharCodes;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << CharCodes;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["CharCodes"] = CharCodes;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(list<int32>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(list<int32>(), L"CharCodes");
		}
	};
	struct SUnsetCharDBIn : public SProto
	{
		TUID UID{};
		list<int32> CharCodes{};
		SUnsetCharDBIn()
		{
		}
		SUnsetCharDBIn(const TUID& UID_, const list<int32>& CharCodes_) : UID(UID_), CharCodes(CharCodes_)
		{
		}
		SUnsetCharDBIn(TUID&& UID_, list<int32>&& CharCodes_) : UID(std::move(UID_)), CharCodes(std::move(CharCodes_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> CharCodes;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["CharCodes"] >> CharCodes;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << CharCodes;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["CharCodes"] = CharCodes;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(list<int32>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(list<int32>(), L"CharCodes");
		}
	};
	struct SCanPushAtNightDBIn : public SProto
	{
		TUID UID{};
		bool CanPushAtNight{};
		SCanPushAtNightDBIn()
		{
		}
		SCanPushAtNightDBIn(const TUID& UID_, const bool& CanPushAtNight_) : UID(UID_), CanPushAtNight(CanPushAtNight_)
		{
		}
		SCanPushAtNightDBIn(TUID&& UID_, bool&& CanPushAtNight_) : UID(std::move(UID_)), CanPushAtNight(std::move(CanPushAtNight_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> CanPushAtNight;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["CanPushAtNight"] >> CanPushAtNight;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << CanPushAtNight;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["CanPushAtNight"] = CanPushAtNight;
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
				GetMemberName(bool(), L"CanPushAtNight");
		}
	};
	struct SChangeLanguageDBIn : public SProto
	{
		TUID UID{};
		ELanguage Language{};
		SChangeLanguageDBIn()
		{
		}
		SChangeLanguageDBIn(const TUID& UID_, const ELanguage& Language_) : UID(UID_), Language(Language_)
		{
		}
		SChangeLanguageDBIn(TUID&& UID_, ELanguage&& Language_) : UID(std::move(UID_)), Language(std::move(Language_))
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
	struct SBuyDBIn : public SRewardDB
	{
		SBuyDBIn()
		{
		}
		SBuyDBIn(const SRewardDB& Super_) : SRewardDB(Super_)
		{
		}
		SBuyDBIn(SRewardDB&& Super_) : SRewardDB(std::move(Super_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"");
		}
	};
	struct SBuyCharDBIn : public SProto
	{
		TUID UID{};
		TResources ResourcesLeft{};
		int32 CharCode{};
		SBuyCharDBIn()
		{
		}
		SBuyCharDBIn(const TUID& UID_, const TResources& ResourcesLeft_, const int32& CharCode_) : UID(UID_), ResourcesLeft(ResourcesLeft_), CharCode(CharCode_)
		{
		}
		SBuyCharDBIn(TUID&& UID_, TResources&& ResourcesLeft_, int32&& CharCode_) : UID(std::move(UID_)), ResourcesLeft(std::move(ResourcesLeft_)), CharCode(std::move(CharCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> ResourcesLeft;
			Stream_ >> CharCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["CharCode"] >> CharCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << ResourcesLeft;
			Stream_ << CharCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["CharCode"] = CharCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(int32(), L"CharCode");
		}
	};
	struct SBuyPackageDBIn : public SRewardDB
	{
		int32 Code{};
		SBuyPackageDBIn()
		{
		}
		SBuyPackageDBIn(const SRewardDB& Super_, const int32& Code_) : SRewardDB(Super_), Code(Code_)
		{
		}
		SBuyPackageDBIn(SRewardDB&& Super_, int32&& Code_) : SRewardDB(std::move(Super_)), Code(std::move(Code_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> Code;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["Code"] >> Code;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << Code;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["Code"] = Code;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(int32(), L"Code");
		}
	};
	struct SDailyRewardDBIn : public SProto
	{
		TUID UID{};
		TResources ResourcesLeft{};
		system_clock::time_point ExpiredTime{};
		int32 CountLeft{};
		SDailyRewardDBIn()
		{
		}
		SDailyRewardDBIn(const TUID& UID_, const TResources& ResourcesLeft_, const system_clock::time_point& ExpiredTime_, const int32& CountLeft_) : UID(UID_), ResourcesLeft(ResourcesLeft_), ExpiredTime(ExpiredTime_), CountLeft(CountLeft_)
		{
		}
		SDailyRewardDBIn(TUID&& UID_, TResources&& ResourcesLeft_, system_clock::time_point&& ExpiredTime_, int32&& CountLeft_) : UID(std::move(UID_)), ResourcesLeft(std::move(ResourcesLeft_)), ExpiredTime(std::move(ExpiredTime_)), CountLeft(std::move(CountLeft_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> ResourcesLeft;
			Stream_ >> ExpiredTime;
			Stream_ >> CountLeft;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["ExpiredTime"] >> ExpiredTime;
			Value_["CountLeft"] >> CountLeft;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << ResourcesLeft;
			Stream_ << ExpiredTime;
			Stream_ << CountLeft;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["ExpiredTime"] = ExpiredTime;
			Value_["CountLeft"] = CountLeft;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(system_clock::time_point(), L"ExpiredTime") + L"," + 
				GetMemberName(int32(), L"CountLeft");
		}
	};
	struct SConnectDBIn : public SProto
	{
		system_clock::time_point TimePointLogin{};
		system_clock::time_point TimePointLogout{};
		TUID UID{};
		EOS OS{};
		string CountryCode{};
		bool NewRegistered{};
		SConnectDBIn()
		{
		}
		SConnectDBIn(const system_clock::time_point& TimePointLogin_, const system_clock::time_point& TimePointLogout_, const TUID& UID_, const EOS& OS_, const string& CountryCode_, const bool& NewRegistered_) : TimePointLogin(TimePointLogin_), TimePointLogout(TimePointLogout_), UID(UID_), OS(OS_), CountryCode(CountryCode_), NewRegistered(NewRegistered_)
		{
		}
		SConnectDBIn(system_clock::time_point&& TimePointLogin_, system_clock::time_point&& TimePointLogout_, TUID&& UID_, EOS&& OS_, string&& CountryCode_, bool&& NewRegistered_) : TimePointLogin(std::move(TimePointLogin_)), TimePointLogout(std::move(TimePointLogout_)), UID(std::move(UID_)), OS(std::move(OS_)), CountryCode(std::move(CountryCode_)), NewRegistered(std::move(NewRegistered_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> TimePointLogin;
			Stream_ >> TimePointLogout;
			Stream_ >> UID;
			Stream_ >> OS;
			Stream_ >> CountryCode;
			Stream_ >> NewRegistered;
		}
		void operator << (const Value& Value_) override
		{
			Value_["TimePointLogin"] >> TimePointLogin;
			Value_["TimePointLogout"] >> TimePointLogout;
			Value_["UID"] >> UID;
			Value_["OS"] >> OS;
			Value_["CountryCode"] >> CountryCode;
			Value_["NewRegistered"] >> NewRegistered;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << TimePointLogin;
			Stream_ << TimePointLogout;
			Stream_ << UID;
			Stream_ << OS;
			Stream_ << CountryCode;
			Stream_ << NewRegistered;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["TimePointLogin"] = TimePointLogin;
			Value_["TimePointLogout"] = TimePointLogout;
			Value_["UID"] = UID;
			Value_["OS"] = OS;
			Value_["CountryCode"] = CountryCode;
			Value_["NewRegistered"] = NewRegistered;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(TUID()) + L"," + 
				GetStdName(EOS()) + L"," + 
				GetStdName(string()) + L"," + 
				GetStdName(bool());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(system_clock::time_point(), L"TimePointLogin") + L"," + 
				GetMemberName(system_clock::time_point(), L"TimePointLogout") + L"," + 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(EOS(), L"OS") + L"," + 
				GetMemberName(string(), L"CountryCode") + L"," + 
				GetMemberName(bool(), L"NewRegistered");
		}
	};
	struct SSelectCharDBIn : public SProto
	{
		TUID UID{};
		int32 CharCode{};
		SSelectCharDBIn()
		{
		}
		SSelectCharDBIn(const TUID& UID_, const int32& CharCode_) : UID(UID_), CharCode(CharCode_)
		{
		}
		SSelectCharDBIn(TUID&& UID_, int32&& CharCode_) : UID(std::move(UID_)), CharCode(std::move(CharCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> CharCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["CharCode"] >> CharCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << CharCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["CharCode"] = CharCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(int32(), L"CharCode");
		}
	};
	struct SBattleEndInfo : public SProto
	{
		TUID UID{};
		TResources Resources{};
		int32 Point{};
		int32 PointBest{};
		int32 WinCountSolo{};
		int32 LoseCountSolo{};
		int32 WinCountMulti{};
		int32 LoseCountMulti{};
		int32 BattlePointBest{};
		int32 KillTotal{};
		int32 ChainKillTotal{};
		int32 BlowBalloonTotal{};
		SBattleEndInfo()
		{
		}
		SBattleEndInfo(const TUID& UID_, const TResources& Resources_, const int32& Point_, const int32& PointBest_, const int32& WinCountSolo_, const int32& LoseCountSolo_, const int32& WinCountMulti_, const int32& LoseCountMulti_, const int32& BattlePointBest_, const int32& KillTotal_, const int32& ChainKillTotal_, const int32& BlowBalloonTotal_) : UID(UID_), Resources(Resources_), Point(Point_), PointBest(PointBest_), WinCountSolo(WinCountSolo_), LoseCountSolo(LoseCountSolo_), WinCountMulti(WinCountMulti_), LoseCountMulti(LoseCountMulti_), BattlePointBest(BattlePointBest_), KillTotal(KillTotal_), ChainKillTotal(ChainKillTotal_), BlowBalloonTotal(BlowBalloonTotal_)
		{
		}
		SBattleEndInfo(TUID&& UID_, TResources&& Resources_, int32&& Point_, int32&& PointBest_, int32&& WinCountSolo_, int32&& LoseCountSolo_, int32&& WinCountMulti_, int32&& LoseCountMulti_, int32&& BattlePointBest_, int32&& KillTotal_, int32&& ChainKillTotal_, int32&& BlowBalloonTotal_) : UID(std::move(UID_)), Resources(std::move(Resources_)), Point(std::move(Point_)), PointBest(std::move(PointBest_)), WinCountSolo(std::move(WinCountSolo_)), LoseCountSolo(std::move(LoseCountSolo_)), WinCountMulti(std::move(WinCountMulti_)), LoseCountMulti(std::move(LoseCountMulti_)), BattlePointBest(std::move(BattlePointBest_)), KillTotal(std::move(KillTotal_)), ChainKillTotal(std::move(ChainKillTotal_)), BlowBalloonTotal(std::move(BlowBalloonTotal_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Resources;
			Stream_ >> Point;
			Stream_ >> PointBest;
			Stream_ >> WinCountSolo;
			Stream_ >> LoseCountSolo;
			Stream_ >> WinCountMulti;
			Stream_ >> LoseCountMulti;
			Stream_ >> BattlePointBest;
			Stream_ >> KillTotal;
			Stream_ >> ChainKillTotal;
			Stream_ >> BlowBalloonTotal;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Resources"] >> Resources;
			Value_["Point"] >> Point;
			Value_["PointBest"] >> PointBest;
			Value_["WinCountSolo"] >> WinCountSolo;
			Value_["LoseCountSolo"] >> LoseCountSolo;
			Value_["WinCountMulti"] >> WinCountMulti;
			Value_["LoseCountMulti"] >> LoseCountMulti;
			Value_["BattlePointBest"] >> BattlePointBest;
			Value_["KillTotal"] >> KillTotal;
			Value_["ChainKillTotal"] >> ChainKillTotal;
			Value_["BlowBalloonTotal"] >> BlowBalloonTotal;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Resources;
			Stream_ << Point;
			Stream_ << PointBest;
			Stream_ << WinCountSolo;
			Stream_ << LoseCountSolo;
			Stream_ << WinCountMulti;
			Stream_ << LoseCountMulti;
			Stream_ << BattlePointBest;
			Stream_ << KillTotal;
			Stream_ << ChainKillTotal;
			Stream_ << BlowBalloonTotal;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Resources"] = Resources;
			Value_["Point"] = Point;
			Value_["PointBest"] = PointBest;
			Value_["WinCountSolo"] = WinCountSolo;
			Value_["LoseCountSolo"] = LoseCountSolo;
			Value_["WinCountMulti"] = WinCountMulti;
			Value_["LoseCountMulti"] = LoseCountMulti;
			Value_["BattlePointBest"] = BattlePointBest;
			Value_["KillTotal"] = KillTotal;
			Value_["ChainKillTotal"] = ChainKillTotal;
			Value_["BlowBalloonTotal"] = BlowBalloonTotal;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"Resources") + L"," + 
				GetMemberName(int32(), L"Point") + L"," + 
				GetMemberName(int32(), L"PointBest") + L"," + 
				GetMemberName(int32(), L"WinCountSolo") + L"," + 
				GetMemberName(int32(), L"LoseCountSolo") + L"," + 
				GetMemberName(int32(), L"WinCountMulti") + L"," + 
				GetMemberName(int32(), L"LoseCountMulti") + L"," + 
				GetMemberName(int32(), L"BattlePointBest") + L"," + 
				GetMemberName(int32(), L"KillTotal") + L"," + 
				GetMemberName(int32(), L"ChainKillTotal") + L"," + 
				GetMemberName(int32(), L"BlowBalloonTotal");
		}
	};
	struct SBattleEndDBIn : public SProto
	{
		vector<SBattleEndInfo> BattleEndInfos{};
		TDoneQuestDBs DoneQuests{};
		SBattleEndDBIn()
		{
		}
		SBattleEndDBIn(const vector<SBattleEndInfo>& BattleEndInfos_, const TDoneQuestDBs& DoneQuests_) : BattleEndInfos(BattleEndInfos_), DoneQuests(DoneQuests_)
		{
		}
		SBattleEndDBIn(vector<SBattleEndInfo>&& BattleEndInfos_, TDoneQuestDBs&& DoneQuests_) : BattleEndInfos(std::move(BattleEndInfos_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> BattleEndInfos;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["BattleEndInfos"] >> BattleEndInfos;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << BattleEndInfos;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["BattleEndInfos"] = BattleEndInfos;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(vector<SBattleEndInfo>()) + L"," + 
				GetStdName(TDoneQuestDBs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(vector<SBattleEndInfo>(), L"BattleEndInfos") + L"," + 
				GetMemberName(TDoneQuestDBs(), L"DoneQuests");
		}
	};
	struct SUpdateInvalidDisconnectInfoDBIn : public SProto
	{
		TUID UID{};
		SInvalidDisconnectInfo Info{};
		SUpdateInvalidDisconnectInfoDBIn()
		{
		}
		SUpdateInvalidDisconnectInfoDBIn(const TUID& UID_, const SInvalidDisconnectInfo& Info_) : UID(UID_), Info(Info_)
		{
		}
		SUpdateInvalidDisconnectInfoDBIn(TUID&& UID_, SInvalidDisconnectInfo&& Info_) : UID(std::move(UID_)), Info(std::move(Info_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Info;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Info"] >> Info;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Info;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Info"] = Info;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(SInvalidDisconnectInfo());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(SInvalidDisconnectInfo(), L"Info");
		}
	};
	struct SUpdateMatchBlockEndTimeDBIn : public SProto
	{
		TUID UID{};
		system_clock::time_point MatchBlockEndTime{};
		SUpdateMatchBlockEndTimeDBIn()
		{
		}
		SUpdateMatchBlockEndTimeDBIn(const TUID& UID_, const system_clock::time_point& MatchBlockEndTime_) : UID(UID_), MatchBlockEndTime(MatchBlockEndTime_)
		{
		}
		SUpdateMatchBlockEndTimeDBIn(TUID&& UID_, system_clock::time_point&& MatchBlockEndTime_) : UID(std::move(UID_)), MatchBlockEndTime(std::move(MatchBlockEndTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> MatchBlockEndTime;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["MatchBlockEndTime"] >> MatchBlockEndTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << MatchBlockEndTime;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["MatchBlockEndTime"] = MatchBlockEndTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(system_clock::time_point(), L"MatchBlockEndTime");
		}
	};
	struct SArrowDodgeBattleStartDBIn : public SProto
	{
		TUID UID{};
		TResources Resources{};
		int32 Count{};
		system_clock::time_point RefreshTime{};
		TDoneQuestDBs DoneQuests{};
		SArrowDodgeBattleStartDBIn()
		{
		}
		SArrowDodgeBattleStartDBIn(const TUID& UID_, const TResources& Resources_, const int32& Count_, const system_clock::time_point& RefreshTime_, const TDoneQuestDBs& DoneQuests_) : UID(UID_), Resources(Resources_), Count(Count_), RefreshTime(RefreshTime_), DoneQuests(DoneQuests_)
		{
		}
		SArrowDodgeBattleStartDBIn(TUID&& UID_, TResources&& Resources_, int32&& Count_, system_clock::time_point&& RefreshTime_, TDoneQuestDBs&& DoneQuests_) : UID(std::move(UID_)), Resources(std::move(Resources_)), Count(std::move(Count_)), RefreshTime(std::move(RefreshTime_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Resources;
			Stream_ >> Count;
			Stream_ >> RefreshTime;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Resources"] >> Resources;
			Value_["Count"] >> Count;
			Value_["RefreshTime"] >> RefreshTime;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Resources;
			Stream_ << Count;
			Stream_ << RefreshTime;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Resources"] = Resources;
			Value_["Count"] = Count;
			Value_["RefreshTime"] = RefreshTime;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(TDoneQuestDBs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"Resources") + L"," + 
				GetMemberName(int32(), L"Count") + L"," + 
				GetMemberName(system_clock::time_point(), L"RefreshTime") + L"," + 
				GetMemberName(TDoneQuestDBs(), L"DoneQuests");
		}
	};
	struct SArrowDodgeBattleEndDBIn : public SProto
	{
		TUID UID{};
		TResources Resources{};
		int32 PointBest{};
		int64 BestTick{};
		TDoneQuestDBs DoneQuests{};
		SArrowDodgeBattleEndDBIn()
		{
		}
		SArrowDodgeBattleEndDBIn(const TUID& UID_, const TResources& Resources_, const int32& PointBest_, const int64& BestTick_, const TDoneQuestDBs& DoneQuests_) : UID(UID_), Resources(Resources_), PointBest(PointBest_), BestTick(BestTick_), DoneQuests(DoneQuests_)
		{
		}
		SArrowDodgeBattleEndDBIn(TUID&& UID_, TResources&& Resources_, int32&& PointBest_, int64&& BestTick_, TDoneQuestDBs&& DoneQuests_) : UID(std::move(UID_)), Resources(std::move(Resources_)), PointBest(std::move(PointBest_)), BestTick(std::move(BestTick_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Resources;
			Stream_ >> PointBest;
			Stream_ >> BestTick;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Resources"] >> Resources;
			Value_["PointBest"] >> PointBest;
			Value_["BestTick"] >> BestTick;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Resources;
			Stream_ << PointBest;
			Stream_ << BestTick;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Resources"] = Resources;
			Value_["PointBest"] = PointBest;
			Value_["BestTick"] = BestTick;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int64()) + L"," + 
				GetStdName(TDoneQuestDBs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"Resources") + L"," + 
				GetMemberName(int32(), L"PointBest") + L"," + 
				GetMemberName(int64(), L"BestTick") + L"," + 
				GetMemberName(TDoneQuestDBs(), L"DoneQuests");
		}
	};
	struct SFlyAwayBattleStartDBIn : public SProto
	{
		TUID UID{};
		TResources Resources{};
		int32 Count{};
		system_clock::time_point RefreshTime{};
		TDoneQuestDBs DoneQuests{};
		SFlyAwayBattleStartDBIn()
		{
		}
		SFlyAwayBattleStartDBIn(const TUID& UID_, const TResources& Resources_, const int32& Count_, const system_clock::time_point& RefreshTime_, const TDoneQuestDBs& DoneQuests_) : UID(UID_), Resources(Resources_), Count(Count_), RefreshTime(RefreshTime_), DoneQuests(DoneQuests_)
		{
		}
		SFlyAwayBattleStartDBIn(TUID&& UID_, TResources&& Resources_, int32&& Count_, system_clock::time_point&& RefreshTime_, TDoneQuestDBs&& DoneQuests_) : UID(std::move(UID_)), Resources(std::move(Resources_)), Count(std::move(Count_)), RefreshTime(std::move(RefreshTime_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Resources;
			Stream_ >> Count;
			Stream_ >> RefreshTime;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Resources"] >> Resources;
			Value_["Count"] >> Count;
			Value_["RefreshTime"] >> RefreshTime;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Resources;
			Stream_ << Count;
			Stream_ << RefreshTime;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Resources"] = Resources;
			Value_["Count"] = Count;
			Value_["RefreshTime"] = RefreshTime;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(TDoneQuestDBs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"Resources") + L"," + 
				GetMemberName(int32(), L"Count") + L"," + 
				GetMemberName(system_clock::time_point(), L"RefreshTime") + L"," + 
				GetMemberName(TDoneQuestDBs(), L"DoneQuests");
		}
	};
	struct SFlyAwayBattleEndDBIn : public SProto
	{
		TUID UID{};
		TResources Resources{};
		int32 PointBest{};
		int32 PassedCountBest{};
		TDoneQuestDBs DoneQuests{};
		SFlyAwayBattleEndDBIn()
		{
		}
		SFlyAwayBattleEndDBIn(const TUID& UID_, const TResources& Resources_, const int32& PointBest_, const int32& PassedCountBest_, const TDoneQuestDBs& DoneQuests_) : UID(UID_), Resources(Resources_), PointBest(PointBest_), PassedCountBest(PassedCountBest_), DoneQuests(DoneQuests_)
		{
		}
		SFlyAwayBattleEndDBIn(TUID&& UID_, TResources&& Resources_, int32&& PointBest_, int32&& PassedCountBest_, TDoneQuestDBs&& DoneQuests_) : UID(std::move(UID_)), Resources(std::move(Resources_)), PointBest(std::move(PointBest_)), PassedCountBest(std::move(PassedCountBest_)), DoneQuests(std::move(DoneQuests_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Resources;
			Stream_ >> PointBest;
			Stream_ >> PassedCountBest;
			Stream_ >> DoneQuests;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Resources"] >> Resources;
			Value_["PointBest"] >> PointBest;
			Value_["PassedCountBest"] >> PassedCountBest;
			Value_["DoneQuests"] >> DoneQuests;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Resources;
			Stream_ << PointBest;
			Stream_ << PassedCountBest;
			Stream_ << DoneQuests;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Resources"] = Resources;
			Value_["PointBest"] = PointBest;
			Value_["PassedCountBest"] = PassedCountBest;
			Value_["DoneQuests"] = DoneQuests;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(TDoneQuestDBs());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"Resources") + L"," + 
				GetMemberName(int32(), L"PointBest") + L"," + 
				GetMemberName(int32(), L"PassedCountBest") + L"," + 
				GetMemberName(TDoneQuestDBs(), L"DoneQuests");
		}
	};
	struct SGachaGuarantee : public SProto
	{
		int32 GachaIndex{};
		int32 Count{};
		SGachaGuarantee()
		{
		}
		SGachaGuarantee(const int32& GachaIndex_, const int32& Count_) : GachaIndex(GachaIndex_), Count(Count_)
		{
		}
		SGachaGuarantee(int32&& GachaIndex_, int32&& Count_) : GachaIndex(std::move(GachaIndex_)), Count(std::move(Count_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> GachaIndex;
			Stream_ >> Count;
		}
		void operator << (const Value& Value_) override
		{
			Value_["GachaIndex"] >> GachaIndex;
			Value_["Count"] >> Count;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << GachaIndex;
			Stream_ << Count;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["GachaIndex"] = GachaIndex;
			Value_["Count"] = Count;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(int32()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(int32(), L"GachaIndex") + L"," + 
				GetMemberName(int32(), L"Count");
		}
	};
	struct SGachaDBIn : public SProto
	{
		TUID UID{};
		TResources ResourcesLeft{};
		list<int32> CharsGot{};
		SGachaDBIn()
		{
		}
		SGachaDBIn(const TUID& UID_, const TResources& ResourcesLeft_, const list<int32>& CharsGot_) : UID(UID_), ResourcesLeft(ResourcesLeft_), CharsGot(CharsGot_)
		{
		}
		SGachaDBIn(TUID&& UID_, TResources&& ResourcesLeft_, list<int32>&& CharsGot_) : UID(std::move(UID_)), ResourcesLeft(std::move(ResourcesLeft_)), CharsGot(std::move(CharsGot_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> ResourcesLeft;
			Stream_ >> CharsGot;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["ResourcesLeft"] >> ResourcesLeft;
			Value_["CharsGot"] >> CharsGot;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << ResourcesLeft;
			Stream_ << CharsGot;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["ResourcesLeft"] = ResourcesLeft;
			Value_["CharsGot"] = CharsGot;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(list<int32>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"ResourcesLeft") + L"," + 
				GetMemberName(list<int32>(), L"CharsGot");
		}
	};
	struct SRankRewardDBIn : public SRewardDB
	{
		int32 LastGotRewardRankIndex{};
		SRankRewardDBIn()
		{
		}
		SRankRewardDBIn(const SRewardDB& Super_, const int32& LastGotRewardRankIndex_) : SRewardDB(Super_), LastGotRewardRankIndex(LastGotRewardRankIndex_)
		{
		}
		SRankRewardDBIn(SRewardDB&& Super_, int32&& LastGotRewardRankIndex_) : SRewardDB(std::move(Super_)), LastGotRewardRankIndex(std::move(LastGotRewardRankIndex_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> LastGotRewardRankIndex;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["LastGotRewardRankIndex"] >> LastGotRewardRankIndex;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << LastGotRewardRankIndex;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["LastGotRewardRankIndex"] = LastGotRewardRankIndex;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(int32(), L"LastGotRewardRankIndex");
		}
	};
	struct SQuestNewDBIn : public SProto
	{
		TUID UID{};
		TQuestSlotIndexCodes SlotIndexCodes{};
		SQuestNewDBIn()
		{
		}
		SQuestNewDBIn(const TUID& UID_, const TQuestSlotIndexCodes& SlotIndexCodes_) : UID(UID_), SlotIndexCodes(SlotIndexCodes_)
		{
		}
		SQuestNewDBIn(TUID&& UID_, TQuestSlotIndexCodes&& SlotIndexCodes_) : UID(std::move(UID_)), SlotIndexCodes(std::move(SlotIndexCodes_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> SlotIndexCodes;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["SlotIndexCodes"] >> SlotIndexCodes;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << SlotIndexCodes;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["SlotIndexCodes"] = SlotIndexCodes;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TQuestSlotIndexCodes());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TQuestSlotIndexCodes(), L"SlotIndexCodes");
		}
	};
	struct SQuestDelDBIn : public SProto
	{
		TUID UID{};
		list<TQuestSlotIndex> SlotIndices{};
		SQuestDelDBIn()
		{
		}
		SQuestDelDBIn(const TUID& UID_, const list<TQuestSlotIndex>& SlotIndices_) : UID(UID_), SlotIndices(SlotIndices_)
		{
		}
		SQuestDelDBIn(TUID&& UID_, list<TQuestSlotIndex>&& SlotIndices_) : UID(std::move(UID_)), SlotIndices(std::move(SlotIndices_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> SlotIndices;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["SlotIndices"] >> SlotIndices;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << SlotIndices;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["SlotIndices"] = SlotIndices;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(list<TQuestSlotIndex>());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(list<TQuestSlotIndex>(), L"SlotIndices");
		}
	};
	struct SQuestDoneDBIn : public SProto
	{
		TUID UID{};
		TQuestSlotIndex SlotIndex{};
		int32 Count{};
		SQuestDoneDBIn()
		{
		}
		SQuestDoneDBIn(const TUID& UID_, const TQuestSlotIndex& SlotIndex_, const int32& Count_) : UID(UID_), SlotIndex(SlotIndex_), Count(Count_)
		{
		}
		SQuestDoneDBIn(TUID&& UID_, TQuestSlotIndex&& SlotIndex_, int32&& Count_) : UID(std::move(UID_)), SlotIndex(std::move(SlotIndex_)), Count(std::move(Count_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> SlotIndex;
			Stream_ >> Count;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["SlotIndex"] >> SlotIndex;
			Value_["Count"] >> Count;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << SlotIndex;
			Stream_ << Count;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["SlotIndex"] = SlotIndex;
			Value_["Count"] = Count;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(int32(), L"Count");
		}
	};
	struct SQuestRewardDBIn : public SRewardDB
	{
		TQuestSlotIndex SlotIndex{};
		system_clock::time_point CoolEndTime{};
		int32 DailyCompleteCount{};
		system_clock::time_point DailyCompleteRefreshTime{};
		SQuestRewardDBIn()
		{
		}
		SQuestRewardDBIn(const SRewardDB& Super_, const TQuestSlotIndex& SlotIndex_, const system_clock::time_point& CoolEndTime_, const int32& DailyCompleteCount_, const system_clock::time_point& DailyCompleteRefreshTime_) : SRewardDB(Super_), SlotIndex(SlotIndex_), CoolEndTime(CoolEndTime_), DailyCompleteCount(DailyCompleteCount_), DailyCompleteRefreshTime(DailyCompleteRefreshTime_)
		{
		}
		SQuestRewardDBIn(SRewardDB&& Super_, TQuestSlotIndex&& SlotIndex_, system_clock::time_point&& CoolEndTime_, int32&& DailyCompleteCount_, system_clock::time_point&& DailyCompleteRefreshTime_) : SRewardDB(std::move(Super_)), SlotIndex(std::move(SlotIndex_)), CoolEndTime(std::move(CoolEndTime_)), DailyCompleteCount(std::move(DailyCompleteCount_)), DailyCompleteRefreshTime(std::move(DailyCompleteRefreshTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> SlotIndex;
			Stream_ >> CoolEndTime;
			Stream_ >> DailyCompleteCount;
			Stream_ >> DailyCompleteRefreshTime;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["SlotIndex"] >> SlotIndex;
			Value_["CoolEndTime"] >> CoolEndTime;
			Value_["DailyCompleteCount"] >> DailyCompleteCount;
			Value_["DailyCompleteRefreshTime"] >> DailyCompleteRefreshTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << SlotIndex;
			Stream_ << CoolEndTime;
			Stream_ << DailyCompleteCount;
			Stream_ << DailyCompleteRefreshTime;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["SlotIndex"] = SlotIndex;
			Value_["CoolEndTime"] = CoolEndTime;
			Value_["DailyCompleteCount"] = DailyCompleteCount;
			Value_["DailyCompleteRefreshTime"] = DailyCompleteRefreshTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(system_clock::time_point()) + L"," + 
				GetStdName(int32()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(system_clock::time_point(), L"CoolEndTime") + L"," + 
				GetMemberName(int32(), L"DailyCompleteCount") + L"," + 
				GetMemberName(system_clock::time_point(), L"DailyCompleteRefreshTime");
		}
	};
	struct SQuestNextDBIn : public SProto
	{
		TUID UID{};
		TQuestSlotIndex SlotIndex{};
		int32 NewQuestCode{};
		SQuestNextDBIn()
		{
		}
		SQuestNextDBIn(const TUID& UID_, const TQuestSlotIndex& SlotIndex_, const int32& NewQuestCode_) : UID(UID_), SlotIndex(SlotIndex_), NewQuestCode(NewQuestCode_)
		{
		}
		SQuestNextDBIn(TUID&& UID_, TQuestSlotIndex&& SlotIndex_, int32&& NewQuestCode_) : UID(std::move(UID_)), SlotIndex(std::move(SlotIndex_)), NewQuestCode(std::move(NewQuestCode_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> SlotIndex;
			Stream_ >> NewQuestCode;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["SlotIndex"] >> SlotIndex;
			Value_["NewQuestCode"] >> NewQuestCode;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << SlotIndex;
			Stream_ << NewQuestCode;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["SlotIndex"] = SlotIndex;
			Value_["NewQuestCode"] = NewQuestCode;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TQuestSlotIndex()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TQuestSlotIndex(), L"SlotIndex") + L"," + 
				GetMemberName(int32(), L"NewQuestCode");
		}
	};
	struct SQuestDailyCompleteRewardDBIn : public SRewardDB
	{
		system_clock::time_point RefreshTime{};
		SQuestDailyCompleteRewardDBIn()
		{
		}
		SQuestDailyCompleteRewardDBIn(const SRewardDB& Super_, const system_clock::time_point& RefreshTime_) : SRewardDB(Super_), RefreshTime(RefreshTime_)
		{
		}
		SQuestDailyCompleteRewardDBIn(SRewardDB&& Super_, system_clock::time_point&& RefreshTime_) : SRewardDB(std::move(Super_)), RefreshTime(std::move(RefreshTime_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> RefreshTime;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["RefreshTime"] >> RefreshTime;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << RefreshTime;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["RefreshTime"] = RefreshTime;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(system_clock::time_point());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(system_clock::time_point(), L"RefreshTime");
		}
	};
	struct SChangeNickBeginDBIn : public SProto
	{
		TUID UID{};
		TNick NewNick{};
		SChangeNickBeginDBIn()
		{
		}
		SChangeNickBeginDBIn(const TUID& UID_, const TNick& NewNick_) : UID(UID_), NewNick(NewNick_)
		{
		}
		SChangeNickBeginDBIn(TUID&& UID_, TNick&& NewNick_) : UID(std::move(UID_)), NewNick(std::move(NewNick_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> NewNick;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["NewNick"] >> NewNick;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << NewNick;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["NewNick"] = NewNick;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TNick());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TNick(), L"NewNick");
		}
	};
	struct SChangeNickEndDBIn : public SProto
	{
		TUID UID{};
		TResources Resources{};
		int32 FreeCount{};
		SChangeNickEndDBIn()
		{
		}
		SChangeNickEndDBIn(const TUID& UID_, const TResources& Resources_, const int32& FreeCount_) : UID(UID_), Resources(Resources_), FreeCount(FreeCount_)
		{
		}
		SChangeNickEndDBIn(TUID&& UID_, TResources&& Resources_, int32&& FreeCount_) : UID(std::move(UID_)), Resources(std::move(Resources_)), FreeCount(std::move(FreeCount_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Resources;
			Stream_ >> FreeCount;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Resources"] >> Resources;
			Value_["FreeCount"] >> FreeCount;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Resources;
			Stream_ << FreeCount;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Resources"] = Resources;
			Value_["FreeCount"] = FreeCount;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources()) + L"," + 
				GetStdName(int32());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"Resources") + L"," + 
				GetMemberName(int32(), L"FreeCount");
		}
	};
	struct SChangeNickEndFailDBIn : public SProto
	{
		TUID UID{};
		SChangeNickEndFailDBIn()
		{
		}
		SChangeNickEndFailDBIn(const TUID& UID_) : UID(UID_)
		{
		}
		SChangeNickEndFailDBIn(TUID&& UID_) : UID(std::move(UID_))
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
	struct SCouponUseDBIn : public SRewardDB
	{
		wstring Key{};
		SCouponUseDBIn()
		{
		}
		SCouponUseDBIn(const SRewardDB& Super_, const wstring& Key_) : SRewardDB(Super_), Key(Key_)
		{
		}
		SCouponUseDBIn(SRewardDB&& Super_, wstring&& Key_) : SRewardDB(std::move(Super_)), Key(std::move(Key_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> Key;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["Key"] >> Key;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << Key;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["Key"] = Key;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(wstring());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(wstring(), L"Key");
		}
	};
	struct SCheckIDDBIn : public SProto
	{
		TUID UID{};
		SCheckIDDBIn()
		{
		}
		SCheckIDDBIn(const TUID& UID_) : UID(UID_)
		{
		}
		SCheckIDDBIn(TUID&& UID_) : UID(std::move(UID_))
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
	struct SCouponUseCouponDBIn : public SProto
	{
		wstring Key{};
		TUID UID{};
		SCouponUseCouponDBIn()
		{
		}
		SCouponUseCouponDBIn(const wstring& Key_, const TUID& UID_) : Key(Key_), UID(UID_)
		{
		}
		SCouponUseCouponDBIn(wstring&& Key_, TUID&& UID_) : Key(std::move(Key_)), UID(std::move(UID_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> Key;
			Stream_ >> UID;
		}
		void operator << (const Value& Value_) override
		{
			Value_["Key"] >> Key;
			Value_["UID"] >> UID;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << Key;
			Stream_ << UID;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["Key"] = Key;
			Value_["UID"] = UID;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(wstring()) + L"," + 
				GetStdName(TUID());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(wstring(), L"Key") + L"," + 
				GetMemberName(TUID(), L"UID");
		}
	};
	struct STutorialRewardDBIn : public SProto
	{
		TUID UID{};
		TResources Resources{};
		STutorialRewardDBIn()
		{
		}
		STutorialRewardDBIn(const TUID& UID_, const TResources& Resources_) : UID(UID_), Resources(Resources_)
		{
		}
		STutorialRewardDBIn(TUID&& UID_, TResources&& Resources_) : UID(std::move(UID_)), Resources(std::move(Resources_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			Stream_ >> UID;
			Stream_ >> Resources;
		}
		void operator << (const Value& Value_) override
		{
			Value_["UID"] >> UID;
			Value_["Resources"] >> Resources;
		}
		void operator >> (CStream& Stream_) const override
		{
			Stream_ << UID;
			Stream_ << Resources;
		}
		void operator >> (Value& Value_) const override
		{
			Value_["UID"] = UID;
			Value_["Resources"] = Resources;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(TUID()) + L"," + 
				GetStdName(TResources());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(TUID(), L"UID") + L"," + 
				GetMemberName(TResources(), L"Resources");
		}
	};
	struct SRankingRewardDBIn : public SRewardDB
	{
		int64 RankingRewardedCounter{};
		SRankingRewardDBIn()
		{
		}
		SRankingRewardDBIn(const SRewardDB& Super_, const int64& RankingRewardedCounter_) : SRewardDB(Super_), RankingRewardedCounter(RankingRewardedCounter_)
		{
		}
		SRankingRewardDBIn(SRewardDB&& Super_, int64&& RankingRewardedCounter_) : SRewardDB(std::move(Super_)), RankingRewardedCounter(std::move(RankingRewardedCounter_))
		{
		}
		void operator << (CStream& Stream_) override
		{
			SRewardDB::operator << (Stream_);
			Stream_ >> RankingRewardedCounter;
		}
		void operator << (const Value& Value_) override
		{
			SRewardDB::operator << (Value_);
			Value_["RankingRewardedCounter"] >> RankingRewardedCounter;
		}
		void operator >> (CStream& Stream_) const override
		{
			SRewardDB::operator >> (Stream_);
			Stream_ << RankingRewardedCounter;
		}
		void operator >> (Value& Value_) const override
		{
			SRewardDB::operator >> (Value_);
			Value_["RankingRewardedCounter"] = RankingRewardedCounter;
		}
		static wstring StdName(void)
		{
			return 
				GetStdName(SRewardDB()) + L"," + 
				GetStdName(int64());
		}
		static wstring MemberName(void)
		{
			return 
				GetMemberName(SRewardDB(), L"") + L"," + 
				GetMemberName(int64(), L"RankingRewardedCounter");
		}
	};
}
