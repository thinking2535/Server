using TSize = System.Int32;
using TCheckSum = System.UInt64;
using TUID = System.Int64;
using TPeerCnt = System.UInt32;
using TLongIP = System.UInt32;
using TPort = System.UInt16;
using TPacketSeq = System.UInt64;
using TSessionCode = System.Int64;
using TVer = System.SByte;
using TCode = System.Int32;
using TIndex = System.Int64;
using TID = System.Int32;
using TLevel = System.Int32;
using THP = System.Int32;
using TSlotNo = System.SByte;
using TExp = System.Int32;
using TRank = System.Int32;
using TTeamCnt = System.SByte;
using TQuestSlotIndex = System.Byte;
using TResource = System.Int32;
using TDoneQuests = System.Collections.Generic.List<SQuestSlotIndexCount>;
using TChars = System.Collections.Generic.Dictionary<System.Int32,SCharNet>;
using TQuestDBs = System.Collections.Generic.List<SQuestDB>;
using TCostumes = System.Collections.Generic.HashSet<System.Int32>;
using TPackages = System.Collections.Generic.HashSet<System.Int32>;
using TTeamBattleInfos = System.Collections.Generic.List<STeamBattleInfo>;
using TRankingUsers = System.Collections.Generic.List<SRankingUser>;
using TRankingUserSingles = System.Collections.Generic.List<SRankingUserSingle>;
using TRankingUserIslands = System.Collections.Generic.List<SRankingUserIsland>;
using TQuestSlotIndexCodes = System.Collections.Generic.List<SQuestSlotIndexCode>;
using TRankingRewards = System.Collections.Generic.Dictionary<System.Int64,System.Int32>;
using System;
using System.Collections.Generic;
using rso.core;


using rso;
using rso.net;
using rso.game;
using rso.physics;
using rso.gameutil;
public enum EProtoNetCs
{
	Chat,
	FCMTokenSet,
	FCMTokenUnset,
	FCMCanPushAtNight,
	ChangeLanguage,
	CostumeListRequest,
	Buy,
	BuyChar,
	BuyPackage,
	BuyCostume,
	Purchase,
	DailyReward,
	SelectChar,
	SingleStart,
	SingleEnd,
	IslandStart,
	IslandEnd,
	BattleJoin,
	BattleOut,
	BattleTouch,
	BattlePush,
	BattleIcon,
	Gacha,
	RankReward,
	QuestReward,
	QuestNext,
	QuestDailyCompleteReward,
	ChangeNick,
	CouponUse,
	CostumeEquip,
	CostumeUnequip,
	TutorialReward,
	RankingRewardInfo,
	RankingReward,
	Max,
	Null,
}
public enum EProtoNetSc
{
	Ret,
	Msg,
	Login,
	Lobby,
	Chat,
	UserExp,
	Resources,
	SetPoint,
	SetChar,
	UnsetChar,
	SetCostume,
	CostumeListRequest,
	Buy,
	BuyChar,
	BuyPackage,
	BuyCostume,
	Purchase,
	DailyReward,
	DailyRewardFail,
	SingleStart,
	SingleEnd,
	IslandStart,
	IslandEnd,
	BattleJoin,
	BattleOut,
	BattleBegin,
	BattleMatching,
	BattleStart,
	BattleBeginStart,
	BattleEnd,
	BattleSync,
	BattleTouch,
	BattlePush,
	BattleIcon,
	BattleLink,
	BattleUnLink,
	Gacha,
	GachaFailed,
	QuestGot,
	QuestDone,
	QuestReward,
	QuestNext,
	QuestDailyCompleteReward,
	ChangeNick,
	ChangeNickFail,
	CouponUse,
	CouponUseFail,
	RankingRewardInfo,
	RankingReward,
	RankingRewardFail,
	Max,
}
public enum ERet
{
	Ok,
	InvalidTime,
	UserDoesNotExist,
	SameCanNotPushAtNight,
	SameCode,
	InvalidProtocol,
	InvalidLanguage,
	InvalidShopID,
	InvalidGoodsID,
	InvalidCharCode,
	ReceiptCheckFail,
	SPError,
	NotBattleJoining,
	AlreadyBattleJoining,
	AlreadyInBattle,
	AlreadyHave,
	InvalidBattleType,
	MatchInsertFail,
	BattleBeginFail,
	NotEnoughMoney,
	NoMoreNewCharacter,
	NickLengthUnderMin,
	NickLengthOverMax,
	CouponAlreadyUsed,
	CouponInvalid,
	RankingServerOffLine,
	RankingNoReward,
	RankingRewarded,
	RankingRewardFail,
	Max,
	Null,
}
public enum ELanguage : Byte
{
	English,
	Korean,
	France,
	Germany,
	Spain,
	Italia,
	ChinaCH,
	ChinaTW,
	Japan,
	Portugal,
	Russia,
	Nederland,
	Turkey,
	Finland,
	Malaysia,
	Thailand,
	Indonesia,
	Vietnam,
	India,
	Max,
}
public enum EGrade : Byte
{
	Normal,
	Rare,
	Epic,
	Max,
}
public enum EGameMode : Byte
{
	Single,
	Solo,
	Survival,
	Team,
	Max,
	Null,
}
public enum ERankingType
{
	Multi,
	Single,
	Island,
	Max,
	Null,
}
public class SUserLoginOption : SProto
{
	public EOS OS = 0;
	public SUserLoginOption()
	{
	}
	public SUserLoginOption(SUserLoginOption Obj_)
	{
		OS = Obj_.OS;
	}
	public SUserLoginOption(EOS OS_)
	{
		OS = OS_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			OS = (EOS)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Byte Var = 0;
			Value_.Pop("OS", ref Var);
			OS = (EOS)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Byte)OS);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("OS", (Byte)OS);
	}
	public void Set(SUserLoginOption Obj_)
	{
		OS = Obj_.OS;
	}
	public override string StdName()
	{
		return "rso.gameutil.EOS";
	}
	public override string MemberName()
	{
		return "OS";
	}
}
public class SUserCreateOption : SProto
{
	public SUserLoginOption LoginOption = new SUserLoginOption();
	public ELanguage Language = 0;
	public SUserCreateOption()
	{
	}
	public SUserCreateOption(SUserCreateOption Obj_)
	{
		LoginOption = Obj_.LoginOption;
		Language = Obj_.Language;
	}
	public SUserCreateOption(SUserLoginOption LoginOption_, ELanguage Language_)
	{
		LoginOption = LoginOption_;
		Language = Language_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(LoginOption);
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Language = (ELanguage)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("LoginOption", LoginOption);
		{
			Byte Var = 0;
			Value_.Pop("Language", ref Var);
			Language = (ELanguage)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(LoginOption);
		Stream_.Push((Byte)Language);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("LoginOption", LoginOption);
		Value_.Push("Language", (Byte)Language);
	}
	public void Set(SUserCreateOption Obj_)
	{
		LoginOption.Set(Obj_.LoginOption);
		Language = Obj_.Language;
	}
	public override string StdName()
	{
		return "rso.gameutil.EOS,ELanguage";
	}
	public override string MemberName()
	{
		return "OS,Language";
	}
}
public enum EResource
{
	Ticket,
	Gold,
	Dia,
	CP,
	DiaPaid,
	Max,
	Null,
}
public enum ERewardType : Byte
{
	Resource_Ticket,
	Resource_Gold,
	Resource_Dia,
	Resource_CP,
	Character,
	Costume,
	Max,
}
public enum EQuestType
{
	TeamPlay,
	TeamVictory,
	SurvivalPlay,
	SurvivalVictory,
	IngameConsecutiveKill,
	IngameBalloonPopping,
	IngameKill,
	IngameBestPlayer,
	GachaRuby,
	BlowBalloon,
	PlayNormal,
	PlayRare,
	PlayEpic,
	PlaySingle,
	SingleTime,
	SinglePlayGoldGet,
	SinglePlayScoreGet,
	PlayIsland,
	IslandCount,
	IslandGoldGet,
	IslandScoreGet,
	SurvivalPlayRanking,
	RankPointGet,
	SoloPlay,
	SoloVictory,
	Max,
	Null=-1,
}
public class SQuestSlotIndexCount : SProto
{
	public TQuestSlotIndex SlotIndex = 0;
	public Int32 Count = 0;
	public SQuestSlotIndexCount()
	{
	}
	public SQuestSlotIndexCount(SQuestSlotIndexCount Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		Count = Obj_.Count;
	}
	public SQuestSlotIndexCount(TQuestSlotIndex SlotIndex_, Int32 Count_)
	{
		SlotIndex = SlotIndex_;
		Count = Count_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref SlotIndex);
		Stream_.Pop(ref Count);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("SlotIndex", ref SlotIndex);
		Value_.Pop("Count", ref Count);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(SlotIndex);
		Stream_.Push(Count);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("SlotIndex", SlotIndex);
		Value_.Push("Count", Count);
	}
	public void Set(SQuestSlotIndexCount Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		Count = Obj_.Count;
	}
	public override string StdName()
	{
		return "uint8,int32";
	}
	public override string MemberName()
	{
		return "SlotIndex,Count";
	}
}
public class SRetNetSc : SProto
{
	public ERet Ret = 0;
	public SRetNetSc()
	{
	}
	public SRetNetSc(SRetNetSc Obj_)
	{
		Ret = Obj_.Ret;
	}
	public SRetNetSc(ERet Ret_)
	{
		Ret = Ret_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			Ret = (ERet)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Int32 Var = 0;
			Value_.Pop("Ret", ref Var);
			Ret = (ERet)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Ret);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Ret", (Int32)Ret);
	}
	public void Set(SRetNetSc Obj_)
	{
		Ret = Obj_.Ret;
	}
	public override string StdName()
	{
		return "ERet";
	}
	public override string MemberName()
	{
		return "Ret";
	}
}
public class SMsgNetSc : SProto
{
	public String Msg = "";
	public SMsgNetSc()
	{
	}
	public SMsgNetSc(SMsgNetSc Obj_)
	{
		Msg = Obj_.Msg;
	}
	public SMsgNetSc(String Msg_)
	{
		Msg = Msg_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Msg);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Msg", ref Msg);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Msg);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Msg", Msg);
	}
	public void Set(SMsgNetSc Obj_)
	{
		Msg = Obj_.Msg;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "Msg";
	}
}
public class SResourceTypeData : SProto
{
	public EResource Type = 0;
	public TResource Data = 0;
	public SResourceTypeData()
	{
	}
	public SResourceTypeData(SResourceTypeData Obj_)
	{
		Type = Obj_.Type;
		Data = Obj_.Data;
	}
	public SResourceTypeData(EResource Type_, TResource Data_)
	{
		Type = Type_;
		Data = Data_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			Type = (EResource)Var;
		}
		Stream_.Pop(ref Data);
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Int32 Var = 0;
			Value_.Pop("Type", ref Var);
			Type = (EResource)Var;
		}
		Value_.Pop("Data", ref Data);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Type);
		Stream_.Push(Data);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Type", (Int32)Type);
		Value_.Push("Data", Data);
	}
	public void Set(SResourceTypeData Obj_)
	{
		Type = Obj_.Type;
		Data = Obj_.Data;
	}
	public override string StdName()
	{
		return "EResource,int32";
	}
	public override string MemberName()
	{
		return "Type,Data";
	}
}
public class SUserCore : SProto
{
	public String Nick = "";
	public TResource[] Resources = new TResource[5];
	public SByte Debug = 0;
	public Int32 SelectedCharCode = 0;
	public Int32 SinglePlayCount = 0;
	public TimePoint SingleRefreshTime = new TimePoint();
	public Int32 IslandPlayCount = 0;
	public TimePoint IslandRefreshTime = new TimePoint();
	public TimePoint QuestDailyCompleteRefreshTime = new TimePoint();
	public Int32 ChangeNickFreeCount = 0;
	public TimePoint DailyRewardExpiredTime = new TimePoint();
	public Int32 DailyRewardCountLeft = 0;
	public SUserCore()
	{
		for (int iResources = 0; iResources < Resources.Length; ++iResources)
			Resources[iResources] = 0;
	}
	public SUserCore(SUserCore Obj_)
	{
		Nick = Obj_.Nick;
		Resources = Obj_.Resources;
		Debug = Obj_.Debug;
		SelectedCharCode = Obj_.SelectedCharCode;
		SinglePlayCount = Obj_.SinglePlayCount;
		SingleRefreshTime = Obj_.SingleRefreshTime;
		IslandPlayCount = Obj_.IslandPlayCount;
		IslandRefreshTime = Obj_.IslandRefreshTime;
		QuestDailyCompleteRefreshTime = Obj_.QuestDailyCompleteRefreshTime;
		ChangeNickFreeCount = Obj_.ChangeNickFreeCount;
		DailyRewardExpiredTime = Obj_.DailyRewardExpiredTime;
		DailyRewardCountLeft = Obj_.DailyRewardCountLeft;
	}
	public SUserCore(String Nick_, TResource[] Resources_, SByte Debug_, Int32 SelectedCharCode_, Int32 SinglePlayCount_, TimePoint SingleRefreshTime_, Int32 IslandPlayCount_, TimePoint IslandRefreshTime_, TimePoint QuestDailyCompleteRefreshTime_, Int32 ChangeNickFreeCount_, TimePoint DailyRewardExpiredTime_, Int32 DailyRewardCountLeft_)
	{
		Nick = Nick_;
		Resources = Resources_;
		Debug = Debug_;
		SelectedCharCode = SelectedCharCode_;
		SinglePlayCount = SinglePlayCount_;
		SingleRefreshTime = SingleRefreshTime_;
		IslandPlayCount = IslandPlayCount_;
		IslandRefreshTime = IslandRefreshTime_;
		QuestDailyCompleteRefreshTime = QuestDailyCompleteRefreshTime_;
		ChangeNickFreeCount = ChangeNickFreeCount_;
		DailyRewardExpiredTime = DailyRewardExpiredTime_;
		DailyRewardCountLeft = DailyRewardCountLeft_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Nick);
		for (int iResources = 0; iResources < Resources.Length; ++iResources)
			Stream_.Pop(ref Resources[iResources]);
		Stream_.Pop(ref Debug);
		Stream_.Pop(ref SelectedCharCode);
		Stream_.Pop(ref SinglePlayCount);
		Stream_.Pop(ref SingleRefreshTime);
		Stream_.Pop(ref IslandPlayCount);
		Stream_.Pop(ref IslandRefreshTime);
		Stream_.Pop(ref QuestDailyCompleteRefreshTime);
		Stream_.Pop(ref ChangeNickFreeCount);
		Stream_.Pop(ref DailyRewardExpiredTime);
		Stream_.Pop(ref DailyRewardCountLeft);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Nick", ref Nick);
		Value_.Pop("Resources", ref Resources);
		Value_.Pop("Debug", ref Debug);
		Value_.Pop("SelectedCharCode", ref SelectedCharCode);
		Value_.Pop("SinglePlayCount", ref SinglePlayCount);
		Value_.Pop("SingleRefreshTime", ref SingleRefreshTime);
		Value_.Pop("IslandPlayCount", ref IslandPlayCount);
		Value_.Pop("IslandRefreshTime", ref IslandRefreshTime);
		Value_.Pop("QuestDailyCompleteRefreshTime", ref QuestDailyCompleteRefreshTime);
		Value_.Pop("ChangeNickFreeCount", ref ChangeNickFreeCount);
		Value_.Pop("DailyRewardExpiredTime", ref DailyRewardExpiredTime);
		Value_.Pop("DailyRewardCountLeft", ref DailyRewardCountLeft);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Nick);
		foreach(var itResources in Resources)
		{
			Stream_.Push(itResources);
		}
		Stream_.Push(Debug);
		Stream_.Push(SelectedCharCode);
		Stream_.Push(SinglePlayCount);
		Stream_.Push(SingleRefreshTime);
		Stream_.Push(IslandPlayCount);
		Stream_.Push(IslandRefreshTime);
		Stream_.Push(QuestDailyCompleteRefreshTime);
		Stream_.Push(ChangeNickFreeCount);
		Stream_.Push(DailyRewardExpiredTime);
		Stream_.Push(DailyRewardCountLeft);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Nick", Nick);
		Value_.Push("Resources", Resources);
		Value_.Push("Debug", Debug);
		Value_.Push("SelectedCharCode", SelectedCharCode);
		Value_.Push("SinglePlayCount", SinglePlayCount);
		Value_.Push("SingleRefreshTime", SingleRefreshTime);
		Value_.Push("IslandPlayCount", IslandPlayCount);
		Value_.Push("IslandRefreshTime", IslandRefreshTime);
		Value_.Push("QuestDailyCompleteRefreshTime", QuestDailyCompleteRefreshTime);
		Value_.Push("ChangeNickFreeCount", ChangeNickFreeCount);
		Value_.Push("DailyRewardExpiredTime", DailyRewardExpiredTime);
		Value_.Push("DailyRewardCountLeft", DailyRewardCountLeft);
	}
	public void Set(SUserCore Obj_)
	{
		Nick = Obj_.Nick;
		Resources = Obj_.Resources;
		Debug = Obj_.Debug;
		SelectedCharCode = Obj_.SelectedCharCode;
		SinglePlayCount = Obj_.SinglePlayCount;
		SingleRefreshTime = Obj_.SingleRefreshTime;
		IslandPlayCount = Obj_.IslandPlayCount;
		IslandRefreshTime = Obj_.IslandRefreshTime;
		QuestDailyCompleteRefreshTime = Obj_.QuestDailyCompleteRefreshTime;
		ChangeNickFreeCount = Obj_.ChangeNickFreeCount;
		DailyRewardExpiredTime = Obj_.DailyRewardExpiredTime;
		DailyRewardCountLeft = Obj_.DailyRewardCountLeft;
	}
	public override string StdName()
	{
		return "wstring,int32,int32,int32,int32,int32,int8,int32,int32,time_point,int32,time_point,time_point,int32,time_point,int32";
	}
	public override string MemberName()
	{
		return "Nick,Resources,Debug,SelectedCharCode,SinglePlayCount,SingleRefreshTime,IslandPlayCount,IslandRefreshTime,QuestDailyCompleteRefreshTime,ChangeNickFreeCount,DailyRewardExpiredTime,DailyRewardCountLeft";
	}
}
public class SUserBase : SUserCore
{
	public TExp Exp = 0;
	public Boolean CanPushAtNight = false;
	public Int32 Point = 0;
	public Int32 PointBest = 0;
	public Int32 LastGotRewardRankIndex = 0;
	public Int32 WinCountSolo = 0;
	public Int32 LoseCountSolo = 0;
	public Int32 WinCountSurvival = 0;
	public Int32 LoseCountSurvival = 0;
	public Int32 WinCountMulti = 0;
	public Int32 LoseCountMulti = 0;
	public Int32 BattlePointBest = 0;
	public Int32 SinglePointBest = 0;
	public Int32 IslandPointBest = 0;
	public Int32 SingleSecondBest = 0;
	public Int32 IslandPassedCountBest = 0;
	public Int32 KillTotal = 0;
	public Int32 ChainKillTotal = 0;
	public Int32 BlowBalloonTotal = 0;
	public Int32 QuestDailyCompleteCount = 0;
	public TimePoint CostumeListExpiredTime = new TimePoint();
	public Boolean TutorialReward = false;
	public Boolean SingleStarted = false;
	public Boolean IslandStarted = false;
	public Int64 RankingRewardedCounter = 0;
	public SUserBase()
	{
	}
	public SUserBase(SUserBase Obj_) : base(Obj_)
	{
		Exp = Obj_.Exp;
		CanPushAtNight = Obj_.CanPushAtNight;
		Point = Obj_.Point;
		PointBest = Obj_.PointBest;
		LastGotRewardRankIndex = Obj_.LastGotRewardRankIndex;
		WinCountSolo = Obj_.WinCountSolo;
		LoseCountSolo = Obj_.LoseCountSolo;
		WinCountSurvival = Obj_.WinCountSurvival;
		LoseCountSurvival = Obj_.LoseCountSurvival;
		WinCountMulti = Obj_.WinCountMulti;
		LoseCountMulti = Obj_.LoseCountMulti;
		BattlePointBest = Obj_.BattlePointBest;
		SinglePointBest = Obj_.SinglePointBest;
		IslandPointBest = Obj_.IslandPointBest;
		SingleSecondBest = Obj_.SingleSecondBest;
		IslandPassedCountBest = Obj_.IslandPassedCountBest;
		KillTotal = Obj_.KillTotal;
		ChainKillTotal = Obj_.ChainKillTotal;
		BlowBalloonTotal = Obj_.BlowBalloonTotal;
		QuestDailyCompleteCount = Obj_.QuestDailyCompleteCount;
		CostumeListExpiredTime = Obj_.CostumeListExpiredTime;
		TutorialReward = Obj_.TutorialReward;
		SingleStarted = Obj_.SingleStarted;
		IslandStarted = Obj_.IslandStarted;
		RankingRewardedCounter = Obj_.RankingRewardedCounter;
	}
	public SUserBase(SUserCore Super_, TExp Exp_, Boolean CanPushAtNight_, Int32 Point_, Int32 PointBest_, Int32 LastGotRewardRankIndex_, Int32 WinCountSolo_, Int32 LoseCountSolo_, Int32 WinCountSurvival_, Int32 LoseCountSurvival_, Int32 WinCountMulti_, Int32 LoseCountMulti_, Int32 BattlePointBest_, Int32 SinglePointBest_, Int32 IslandPointBest_, Int32 SingleSecondBest_, Int32 IslandPassedCountBest_, Int32 KillTotal_, Int32 ChainKillTotal_, Int32 BlowBalloonTotal_, Int32 QuestDailyCompleteCount_, TimePoint CostumeListExpiredTime_, Boolean TutorialReward_, Boolean SingleStarted_, Boolean IslandStarted_, Int64 RankingRewardedCounter_) : base(Super_)
	{
		Exp = Exp_;
		CanPushAtNight = CanPushAtNight_;
		Point = Point_;
		PointBest = PointBest_;
		LastGotRewardRankIndex = LastGotRewardRankIndex_;
		WinCountSolo = WinCountSolo_;
		LoseCountSolo = LoseCountSolo_;
		WinCountSurvival = WinCountSurvival_;
		LoseCountSurvival = LoseCountSurvival_;
		WinCountMulti = WinCountMulti_;
		LoseCountMulti = LoseCountMulti_;
		BattlePointBest = BattlePointBest_;
		SinglePointBest = SinglePointBest_;
		IslandPointBest = IslandPointBest_;
		SingleSecondBest = SingleSecondBest_;
		IslandPassedCountBest = IslandPassedCountBest_;
		KillTotal = KillTotal_;
		ChainKillTotal = ChainKillTotal_;
		BlowBalloonTotal = BlowBalloonTotal_;
		QuestDailyCompleteCount = QuestDailyCompleteCount_;
		CostumeListExpiredTime = CostumeListExpiredTime_;
		TutorialReward = TutorialReward_;
		SingleStarted = SingleStarted_;
		IslandStarted = IslandStarted_;
		RankingRewardedCounter = RankingRewardedCounter_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref Exp);
		Stream_.Pop(ref CanPushAtNight);
		Stream_.Pop(ref Point);
		Stream_.Pop(ref PointBest);
		Stream_.Pop(ref LastGotRewardRankIndex);
		Stream_.Pop(ref WinCountSolo);
		Stream_.Pop(ref LoseCountSolo);
		Stream_.Pop(ref WinCountSurvival);
		Stream_.Pop(ref LoseCountSurvival);
		Stream_.Pop(ref WinCountMulti);
		Stream_.Pop(ref LoseCountMulti);
		Stream_.Pop(ref BattlePointBest);
		Stream_.Pop(ref SinglePointBest);
		Stream_.Pop(ref IslandPointBest);
		Stream_.Pop(ref SingleSecondBest);
		Stream_.Pop(ref IslandPassedCountBest);
		Stream_.Pop(ref KillTotal);
		Stream_.Pop(ref ChainKillTotal);
		Stream_.Pop(ref BlowBalloonTotal);
		Stream_.Pop(ref QuestDailyCompleteCount);
		Stream_.Pop(ref CostumeListExpiredTime);
		Stream_.Pop(ref TutorialReward);
		Stream_.Pop(ref SingleStarted);
		Stream_.Pop(ref IslandStarted);
		Stream_.Pop(ref RankingRewardedCounter);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("Exp", ref Exp);
		Value_.Pop("CanPushAtNight", ref CanPushAtNight);
		Value_.Pop("Point", ref Point);
		Value_.Pop("PointBest", ref PointBest);
		Value_.Pop("LastGotRewardRankIndex", ref LastGotRewardRankIndex);
		Value_.Pop("WinCountSolo", ref WinCountSolo);
		Value_.Pop("LoseCountSolo", ref LoseCountSolo);
		Value_.Pop("WinCountSurvival", ref WinCountSurvival);
		Value_.Pop("LoseCountSurvival", ref LoseCountSurvival);
		Value_.Pop("WinCountMulti", ref WinCountMulti);
		Value_.Pop("LoseCountMulti", ref LoseCountMulti);
		Value_.Pop("BattlePointBest", ref BattlePointBest);
		Value_.Pop("SinglePointBest", ref SinglePointBest);
		Value_.Pop("IslandPointBest", ref IslandPointBest);
		Value_.Pop("SingleSecondBest", ref SingleSecondBest);
		Value_.Pop("IslandPassedCountBest", ref IslandPassedCountBest);
		Value_.Pop("KillTotal", ref KillTotal);
		Value_.Pop("ChainKillTotal", ref ChainKillTotal);
		Value_.Pop("BlowBalloonTotal", ref BlowBalloonTotal);
		Value_.Pop("QuestDailyCompleteCount", ref QuestDailyCompleteCount);
		Value_.Pop("CostumeListExpiredTime", ref CostumeListExpiredTime);
		Value_.Pop("TutorialReward", ref TutorialReward);
		Value_.Pop("SingleStarted", ref SingleStarted);
		Value_.Pop("IslandStarted", ref IslandStarted);
		Value_.Pop("RankingRewardedCounter", ref RankingRewardedCounter);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(Exp);
		Stream_.Push(CanPushAtNight);
		Stream_.Push(Point);
		Stream_.Push(PointBest);
		Stream_.Push(LastGotRewardRankIndex);
		Stream_.Push(WinCountSolo);
		Stream_.Push(LoseCountSolo);
		Stream_.Push(WinCountSurvival);
		Stream_.Push(LoseCountSurvival);
		Stream_.Push(WinCountMulti);
		Stream_.Push(LoseCountMulti);
		Stream_.Push(BattlePointBest);
		Stream_.Push(SinglePointBest);
		Stream_.Push(IslandPointBest);
		Stream_.Push(SingleSecondBest);
		Stream_.Push(IslandPassedCountBest);
		Stream_.Push(KillTotal);
		Stream_.Push(ChainKillTotal);
		Stream_.Push(BlowBalloonTotal);
		Stream_.Push(QuestDailyCompleteCount);
		Stream_.Push(CostumeListExpiredTime);
		Stream_.Push(TutorialReward);
		Stream_.Push(SingleStarted);
		Stream_.Push(IslandStarted);
		Stream_.Push(RankingRewardedCounter);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("Exp", Exp);
		Value_.Push("CanPushAtNight", CanPushAtNight);
		Value_.Push("Point", Point);
		Value_.Push("PointBest", PointBest);
		Value_.Push("LastGotRewardRankIndex", LastGotRewardRankIndex);
		Value_.Push("WinCountSolo", WinCountSolo);
		Value_.Push("LoseCountSolo", LoseCountSolo);
		Value_.Push("WinCountSurvival", WinCountSurvival);
		Value_.Push("LoseCountSurvival", LoseCountSurvival);
		Value_.Push("WinCountMulti", WinCountMulti);
		Value_.Push("LoseCountMulti", LoseCountMulti);
		Value_.Push("BattlePointBest", BattlePointBest);
		Value_.Push("SinglePointBest", SinglePointBest);
		Value_.Push("IslandPointBest", IslandPointBest);
		Value_.Push("SingleSecondBest", SingleSecondBest);
		Value_.Push("IslandPassedCountBest", IslandPassedCountBest);
		Value_.Push("KillTotal", KillTotal);
		Value_.Push("ChainKillTotal", ChainKillTotal);
		Value_.Push("BlowBalloonTotal", BlowBalloonTotal);
		Value_.Push("QuestDailyCompleteCount", QuestDailyCompleteCount);
		Value_.Push("CostumeListExpiredTime", CostumeListExpiredTime);
		Value_.Push("TutorialReward", TutorialReward);
		Value_.Push("SingleStarted", SingleStarted);
		Value_.Push("IslandStarted", IslandStarted);
		Value_.Push("RankingRewardedCounter", RankingRewardedCounter);
	}
	public void Set(SUserBase Obj_)
	{
		base.Set(Obj_);
		Exp = Obj_.Exp;
		CanPushAtNight = Obj_.CanPushAtNight;
		Point = Obj_.Point;
		PointBest = Obj_.PointBest;
		LastGotRewardRankIndex = Obj_.LastGotRewardRankIndex;
		WinCountSolo = Obj_.WinCountSolo;
		LoseCountSolo = Obj_.LoseCountSolo;
		WinCountSurvival = Obj_.WinCountSurvival;
		LoseCountSurvival = Obj_.LoseCountSurvival;
		WinCountMulti = Obj_.WinCountMulti;
		LoseCountMulti = Obj_.LoseCountMulti;
		BattlePointBest = Obj_.BattlePointBest;
		SinglePointBest = Obj_.SinglePointBest;
		IslandPointBest = Obj_.IslandPointBest;
		SingleSecondBest = Obj_.SingleSecondBest;
		IslandPassedCountBest = Obj_.IslandPassedCountBest;
		KillTotal = Obj_.KillTotal;
		ChainKillTotal = Obj_.ChainKillTotal;
		BlowBalloonTotal = Obj_.BlowBalloonTotal;
		QuestDailyCompleteCount = Obj_.QuestDailyCompleteCount;
		CostumeListExpiredTime = Obj_.CostumeListExpiredTime;
		TutorialReward = Obj_.TutorialReward;
		SingleStarted = Obj_.SingleStarted;
		IslandStarted = Obj_.IslandStarted;
		RankingRewardedCounter = Obj_.RankingRewardedCounter;
	}
	public override string StdName()
	{
		return "wstring,int32,int32,int32,int32,int32,int8,int32,int32,time_point,int32,time_point,time_point,int32,time_point,int32,int32,bool,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,time_point,bool,bool,bool,int64";
	}
	public override string MemberName()
	{
		return "Nick,Resources,Debug,SelectedCharCode,SinglePlayCount,SingleRefreshTime,IslandPlayCount,IslandRefreshTime,QuestDailyCompleteRefreshTime,ChangeNickFreeCount,DailyRewardExpiredTime,DailyRewardCountLeft,Exp,CanPushAtNight,Point,PointBest,LastGotRewardRankIndex,WinCountSolo,LoseCountSolo,WinCountSurvival,LoseCountSurvival,WinCountMulti,LoseCountMulti,BattlePointBest,SinglePointBest,IslandPointBest,SingleSecondBest,IslandPassedCountBest,KillTotal,ChainKillTotal,BlowBalloonTotal,QuestDailyCompleteCount,CostumeListExpiredTime,TutorialReward,SingleStarted,IslandStarted,RankingRewardedCounter";
	}
}
public class SUserNet : SUserBase
{
	public String CountryCode = "";
	public SUserNet()
	{
	}
	public SUserNet(SUserNet Obj_) : base(Obj_)
	{
		CountryCode = Obj_.CountryCode;
	}
	public SUserNet(SUserBase Super_, String CountryCode_) : base(Super_)
	{
		CountryCode = CountryCode_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref CountryCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("CountryCode", ref CountryCode);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(CountryCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("CountryCode", CountryCode);
	}
	public void Set(SUserNet Obj_)
	{
		base.Set(Obj_);
		CountryCode = Obj_.CountryCode;
	}
	public override string StdName()
	{
		return "wstring,int32,int32,int32,int32,int32,int8,int32,int32,time_point,int32,time_point,time_point,int32,time_point,int32,int32,bool,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,time_point,bool,bool,bool,int64,wstring";
	}
	public override string MemberName()
	{
		return "Nick,Resources,Debug,SelectedCharCode,SinglePlayCount,SingleRefreshTime,IslandPlayCount,IslandRefreshTime,QuestDailyCompleteRefreshTime,ChangeNickFreeCount,DailyRewardExpiredTime,DailyRewardCountLeft,Exp,CanPushAtNight,Point,PointBest,LastGotRewardRankIndex,WinCountSolo,LoseCountSolo,WinCountSurvival,LoseCountSurvival,WinCountMulti,LoseCountMulti,BattlePointBest,SinglePointBest,IslandPointBest,SingleSecondBest,IslandPassedCountBest,KillTotal,ChainKillTotal,BlowBalloonTotal,QuestDailyCompleteCount,CostumeListExpiredTime,TutorialReward,SingleStarted,IslandStarted,RankingRewardedCounter,CountryCode";
	}
}
public enum ECostumePart : Byte
{
	Skin,
	Hat,
	Balloon,
	Max,
	Null,
}
public class SCharNet : SProto
{
	public Int32[] CostumeParts = new Int32[3];
	public SCharNet()
	{
		for (int iCostumeParts = 0; iCostumeParts < CostumeParts.Length; ++iCostumeParts)
			CostumeParts[iCostumeParts] = 0;
	}
	public SCharNet(SCharNet Obj_)
	{
		CostumeParts = Obj_.CostumeParts;
	}
	public SCharNet(Int32[] CostumeParts_)
	{
		CostumeParts = CostumeParts_;
	}
	public override void Push(CStream Stream_)
	{
		for (int iCostumeParts = 0; iCostumeParts < CostumeParts.Length; ++iCostumeParts)
			Stream_.Pop(ref CostumeParts[iCostumeParts]);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("CostumeParts", ref CostumeParts);
	}
	public override void Pop(CStream Stream_)
	{
		foreach(var itCostumeParts in CostumeParts)
		{
			Stream_.Push(itCostumeParts);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CostumeParts", CostumeParts);
	}
	public void Set(SCharNet Obj_)
	{
		CostumeParts = Obj_.CostumeParts;
	}
	public override string StdName()
	{
		return "int32,int32,int32";
	}
	public override string MemberName()
	{
		return "CostumeParts";
	}
}
public class SQuestBase : SProto
{
	public Int32 Code = 0;
	public Int32 Count = 0;
	public TimePoint CoolEndTime = new TimePoint();
	public SQuestBase()
	{
	}
	public SQuestBase(SQuestBase Obj_)
	{
		Code = Obj_.Code;
		Count = Obj_.Count;
		CoolEndTime = Obj_.CoolEndTime;
	}
	public SQuestBase(Int32 Code_, Int32 Count_, TimePoint CoolEndTime_)
	{
		Code = Code_;
		Count = Count_;
		CoolEndTime = CoolEndTime_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
		Stream_.Pop(ref Count);
		Stream_.Pop(ref CoolEndTime);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
		Value_.Pop("Count", ref Count);
		Value_.Pop("CoolEndTime", ref CoolEndTime);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
		Stream_.Push(Count);
		Stream_.Push(CoolEndTime);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
		Value_.Push("Count", Count);
		Value_.Push("CoolEndTime", CoolEndTime);
	}
	public void Set(SQuestBase Obj_)
	{
		Code = Obj_.Code;
		Count = Obj_.Count;
		CoolEndTime = Obj_.CoolEndTime;
	}
	public override string StdName()
	{
		return "int32,int32,time_point";
	}
	public override string MemberName()
	{
		return "Code,Count,CoolEndTime";
	}
}
public class SQuestDB : SQuestBase
{
	public TQuestSlotIndex SlotIndex = 0;
	public SQuestDB()
	{
	}
	public SQuestDB(SQuestDB Obj_) : base(Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
	}
	public SQuestDB(SQuestBase Super_, TQuestSlotIndex SlotIndex_) : base(Super_)
	{
		SlotIndex = SlotIndex_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref SlotIndex);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("SlotIndex", ref SlotIndex);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(SlotIndex);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("SlotIndex", SlotIndex);
	}
	public void Set(SQuestDB Obj_)
	{
		base.Set(Obj_);
		SlotIndex = Obj_.SlotIndex;
	}
	public override string StdName()
	{
		return "int32,int32,time_point,uint8";
	}
	public override string MemberName()
	{
		return "Code,Count,CoolEndTime,SlotIndex";
	}
}
public class SLoginNetSc : SProto
{
	public SUserNet User = new SUserNet();
	public TChars Chars = new TChars();
	public TimePoint ServerTime = new TimePoint();
	public TQuestDBs Quests = new TQuestDBs();
	public TPackages Packages = new TPackages();
	public TCostumes Costumes = new TCostumes();
	public TCostumes CostumeList = new TCostumes();
	public SLoginNetSc()
	{
	}
	public SLoginNetSc(SLoginNetSc Obj_)
	{
		User = Obj_.User;
		Chars = Obj_.Chars;
		ServerTime = Obj_.ServerTime;
		Quests = Obj_.Quests;
		Packages = Obj_.Packages;
		Costumes = Obj_.Costumes;
		CostumeList = Obj_.CostumeList;
	}
	public SLoginNetSc(SUserNet User_, TChars Chars_, TimePoint ServerTime_, TQuestDBs Quests_, TPackages Packages_, TCostumes Costumes_, TCostumes CostumeList_)
	{
		User = User_;
		Chars = Chars_;
		ServerTime = ServerTime_;
		Quests = Quests_;
		Packages = Packages_;
		Costumes = Costumes_;
		CostumeList = CostumeList_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(User);
		{
			Chars.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Key = 0;
				Stream_.Pop(ref Key);
				SCharNet Value = new SCharNet();
				Stream_.Pop(Value);
				Chars.Add(Key, Value);
			}
		}
		Stream_.Pop(ref ServerTime);
		{
			Quests.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SQuestDB Value = new SQuestDB();
				Stream_.Pop(Value);
				Quests.Add(Value);
			}
		}
		{
			Packages.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				Packages.Add(Value);
			}
		}
		{
			Costumes.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				Costumes.Add(Value);
			}
		}
		{
			CostumeList.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				CostumeList.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("User", User);
		Value_.Pop("Chars", ref Chars);
		Value_.Pop("ServerTime", ref ServerTime);
		Value_.Pop("Quests", ref Quests);
		Value_.Pop("Packages", ref Packages);
		Value_.Pop("Costumes", ref Costumes);
		Value_.Pop("CostumeList", ref CostumeList);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(User);
		Stream_.Push((Int32)Chars.Count);
		foreach(var it in Chars)
		{
			Stream_.Push(it.Key);
			Stream_.Push(it.Value);
		}
		Stream_.Push(ServerTime);
		Stream_.Push((Int32)Quests.Count);
		foreach(var it in Quests)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)Packages.Count);
		foreach(var it in Packages)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)Costumes.Count);
		foreach(var it in Costumes)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)CostumeList.Count);
		foreach(var it in CostumeList)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("User", User);
		Value_.Push("Chars", Chars);
		Value_.Push("ServerTime", ServerTime);
		Value_.Push("Quests", Quests);
		Value_.Push("Packages", Packages);
		Value_.Push("Costumes", Costumes);
		Value_.Push("CostumeList", CostumeList);
	}
	public void Set(SLoginNetSc Obj_)
	{
		User.Set(Obj_.User);
		Chars = Obj_.Chars;
		ServerTime = Obj_.ServerTime;
		Quests = Obj_.Quests;
		Packages = Obj_.Packages;
		Costumes = Obj_.Costumes;
		CostumeList = Obj_.CostumeList;
	}
	public override string StdName()
	{
		return "wstring,int32,int32,int32,int32,int32,int8,int32,int32,time_point,int32,time_point,time_point,int32,time_point,int32,int32,bool,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,time_point,bool,bool,bool,int64,wstring,{int32,int32,int32,int32},time_point,{int32,int32,time_point,uint8},{int32},{int32},{int32}";
	}
	public override string MemberName()
	{
		return "Nick,Resources,Debug,SelectedCharCode,SinglePlayCount,SingleRefreshTime,IslandPlayCount,IslandRefreshTime,QuestDailyCompleteRefreshTime,ChangeNickFreeCount,DailyRewardExpiredTime,DailyRewardCountLeft,Exp,CanPushAtNight,Point,PointBest,LastGotRewardRankIndex,WinCountSolo,LoseCountSolo,WinCountSurvival,LoseCountSurvival,WinCountMulti,LoseCountMulti,BattlePointBest,SinglePointBest,IslandPointBest,SingleSecondBest,IslandPassedCountBest,KillTotal,ChainKillTotal,BlowBalloonTotal,QuestDailyCompleteCount,CostumeListExpiredTime,TutorialReward,SingleStarted,IslandStarted,RankingRewardedCounter,CountryCode,Chars,ServerTime,Quests,Packages,Costumes,CostumeList";
	}
}
public class SLobbyNetSc : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SUserExpNetSc : SProto
{
	public TExp Exp = 0;
	public SUserExpNetSc()
	{
	}
	public SUserExpNetSc(SUserExpNetSc Obj_)
	{
		Exp = Obj_.Exp;
	}
	public SUserExpNetSc(TExp Exp_)
	{
		Exp = Exp_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Exp);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Exp", ref Exp);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Exp);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Exp", Exp);
	}
	public void Set(SUserExpNetSc Obj_)
	{
		Exp = Obj_.Exp;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Exp";
	}
}
public class SResourcesNetSc : SProto
{
	public TResource[] Resources = new TResource[5];
	public SResourcesNetSc()
	{
		for (int iResources = 0; iResources < Resources.Length; ++iResources)
			Resources[iResources] = 0;
	}
	public SResourcesNetSc(SResourcesNetSc Obj_)
	{
		Resources = Obj_.Resources;
	}
	public SResourcesNetSc(TResource[] Resources_)
	{
		Resources = Resources_;
	}
	public override void Push(CStream Stream_)
	{
		for (int iResources = 0; iResources < Resources.Length; ++iResources)
			Stream_.Pop(ref Resources[iResources]);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Resources", ref Resources);
	}
	public override void Pop(CStream Stream_)
	{
		foreach(var itResources in Resources)
		{
			Stream_.Push(itResources);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Resources", Resources);
	}
	public void Set(SResourcesNetSc Obj_)
	{
		Resources = Obj_.Resources;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "Resources";
	}
}
public class SSetPointNetSc : SProto
{
	public Int32 Point = 0;
	public SSetPointNetSc()
	{
	}
	public SSetPointNetSc(SSetPointNetSc Obj_)
	{
		Point = Obj_.Point;
	}
	public SSetPointNetSc(Int32 Point_)
	{
		Point = Point_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Point);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Point", ref Point);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Point);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Point", Point);
	}
	public void Set(SSetPointNetSc Obj_)
	{
		Point = Obj_.Point;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Point";
	}
}
public class SSetCharNetSc : SProto
{
	public List<Int32> CharCodes = new List<Int32>();
	public SSetCharNetSc()
	{
	}
	public SSetCharNetSc(SSetCharNetSc Obj_)
	{
		CharCodes = Obj_.CharCodes;
	}
	public SSetCharNetSc(List<Int32> CharCodes_)
	{
		CharCodes = CharCodes_;
	}
	public override void Push(CStream Stream_)
	{
		{
			CharCodes.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				CharCodes.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("CharCodes", ref CharCodes);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)CharCodes.Count);
		foreach(var it in CharCodes)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CharCodes", CharCodes);
	}
	public void Set(SSetCharNetSc Obj_)
	{
		CharCodes = Obj_.CharCodes;
	}
	public override string StdName()
	{
		return "{int32}";
	}
	public override string MemberName()
	{
		return "CharCodes";
	}
}
public class SUnsetCharNetSc : SProto
{
	public List<Int32> CharCodes = new List<Int32>();
	public SUnsetCharNetSc()
	{
	}
	public SUnsetCharNetSc(SUnsetCharNetSc Obj_)
	{
		CharCodes = Obj_.CharCodes;
	}
	public SUnsetCharNetSc(List<Int32> CharCodes_)
	{
		CharCodes = CharCodes_;
	}
	public override void Push(CStream Stream_)
	{
		{
			CharCodes.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				CharCodes.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("CharCodes", ref CharCodes);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)CharCodes.Count);
		foreach(var it in CharCodes)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CharCodes", CharCodes);
	}
	public void Set(SUnsetCharNetSc Obj_)
	{
		CharCodes = Obj_.CharCodes;
	}
	public override string StdName()
	{
		return "{int32}";
	}
	public override string MemberName()
	{
		return "CharCodes";
	}
}
public class SSetCostumeNetSc : SProto
{
	public List<Int32> Codes = new List<Int32>();
	public SSetCostumeNetSc()
	{
	}
	public SSetCostumeNetSc(SSetCostumeNetSc Obj_)
	{
		Codes = Obj_.Codes;
	}
	public SSetCostumeNetSc(List<Int32> Codes_)
	{
		Codes = Codes_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Codes.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				Codes.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Codes", ref Codes);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Codes.Count);
		foreach(var it in Codes)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Codes", Codes);
	}
	public void Set(SSetCostumeNetSc Obj_)
	{
		Codes = Obj_.Codes;
	}
	public override string StdName()
	{
		return "{int32}";
	}
	public override string MemberName()
	{
		return "Codes";
	}
}
public class SChatNetCs : SProto
{
	public String Msg = "";
	public SChatNetCs()
	{
	}
	public SChatNetCs(SChatNetCs Obj_)
	{
		Msg = Obj_.Msg;
	}
	public SChatNetCs(String Msg_)
	{
		Msg = Msg_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Msg);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Msg", ref Msg);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Msg);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Msg", Msg);
	}
	public void Set(SChatNetCs Obj_)
	{
		Msg = Obj_.Msg;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "Msg";
	}
}
public class SChatNetSc : SProto
{
	public String Msg = "";
	public SChatNetSc()
	{
	}
	public SChatNetSc(SChatNetSc Obj_)
	{
		Msg = Obj_.Msg;
	}
	public SChatNetSc(String Msg_)
	{
		Msg = Msg_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Msg);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Msg", ref Msg);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Msg);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Msg", Msg);
	}
	public void Set(SChatNetSc Obj_)
	{
		Msg = Obj_.Msg;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "Msg";
	}
}
public class SFCMTokenSetNetCs : SProto
{
	public String Token = "";
	public SFCMTokenSetNetCs()
	{
	}
	public SFCMTokenSetNetCs(SFCMTokenSetNetCs Obj_)
	{
		Token = Obj_.Token;
	}
	public SFCMTokenSetNetCs(String Token_)
	{
		Token = Token_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Token);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Token", ref Token);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Token);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Token", Token);
	}
	public void Set(SFCMTokenSetNetCs Obj_)
	{
		Token = Obj_.Token;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "Token";
	}
}
public class SFCMTokenUnsetNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SFCMCanPushAtNightNetCs : SProto
{
	public Boolean CanPush = false;
	public SFCMCanPushAtNightNetCs()
	{
	}
	public SFCMCanPushAtNightNetCs(SFCMCanPushAtNightNetCs Obj_)
	{
		CanPush = Obj_.CanPush;
	}
	public SFCMCanPushAtNightNetCs(Boolean CanPush_)
	{
		CanPush = CanPush_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref CanPush);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("CanPush", ref CanPush);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(CanPush);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CanPush", CanPush);
	}
	public void Set(SFCMCanPushAtNightNetCs Obj_)
	{
		CanPush = Obj_.CanPush;
	}
	public override string StdName()
	{
		return "bool";
	}
	public override string MemberName()
	{
		return "CanPush";
	}
}
public class SChangeLanguageNetCs : SProto
{
	public ELanguage Language = 0;
	public SChangeLanguageNetCs()
	{
	}
	public SChangeLanguageNetCs(SChangeLanguageNetCs Obj_)
	{
		Language = Obj_.Language;
	}
	public SChangeLanguageNetCs(ELanguage Language_)
	{
		Language = Language_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Language = (ELanguage)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Byte Var = 0;
			Value_.Pop("Language", ref Var);
			Language = (ELanguage)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Byte)Language);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Language", (Byte)Language);
	}
	public void Set(SChangeLanguageNetCs Obj_)
	{
		Language = Obj_.Language;
	}
	public override string StdName()
	{
		return "ELanguage";
	}
	public override string MemberName()
	{
		return "Language";
	}
}
public class SCostumeListRequestNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SCostumeListRequestNetSc : SProto
{
	public TimePoint CostumeListExpiredTime = new TimePoint();
	public TCostumes CostumeList = new TCostumes();
	public SCostumeListRequestNetSc()
	{
	}
	public SCostumeListRequestNetSc(SCostumeListRequestNetSc Obj_)
	{
		CostumeListExpiredTime = Obj_.CostumeListExpiredTime;
		CostumeList = Obj_.CostumeList;
	}
	public SCostumeListRequestNetSc(TimePoint CostumeListExpiredTime_, TCostumes CostumeList_)
	{
		CostumeListExpiredTime = CostumeListExpiredTime_;
		CostumeList = CostumeList_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref CostumeListExpiredTime);
		{
			CostumeList.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				CostumeList.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("CostumeListExpiredTime", ref CostumeListExpiredTime);
		Value_.Pop("CostumeList", ref CostumeList);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(CostumeListExpiredTime);
		Stream_.Push((Int32)CostumeList.Count);
		foreach(var it in CostumeList)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CostumeListExpiredTime", CostumeListExpiredTime);
		Value_.Push("CostumeList", CostumeList);
	}
	public void Set(SCostumeListRequestNetSc Obj_)
	{
		CostumeListExpiredTime = Obj_.CostumeListExpiredTime;
		CostumeList = Obj_.CostumeList;
	}
	public override string StdName()
	{
		return "time_point,{int32}";
	}
	public override string MemberName()
	{
		return "CostumeListExpiredTime,CostumeList";
	}
}
public class SBuyNetCs : SProto
{
	public Int32 Code = 0;
	public SBuyNetCs()
	{
	}
	public SBuyNetCs(SBuyNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public SBuyNetCs(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBuyNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SBuyNetSc : SProto
{
	public Int32 Code = 0;
	public SBuyNetSc()
	{
	}
	public SBuyNetSc(SBuyNetSc Obj_)
	{
		Code = Obj_.Code;
	}
	public SBuyNetSc(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBuyNetSc Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SBuyCharNetCs : SProto
{
	public Int32 Code = 0;
	public SBuyCharNetCs()
	{
	}
	public SBuyCharNetCs(SBuyCharNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public SBuyCharNetCs(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBuyCharNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SBuyCharNetSc : SProto
{
	public Int32 Code = 0;
	public SBuyCharNetSc()
	{
	}
	public SBuyCharNetSc(SBuyCharNetSc Obj_)
	{
		Code = Obj_.Code;
	}
	public SBuyCharNetSc(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBuyCharNetSc Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SBuyPackageNetCs : SProto
{
	public Int32 Code = 0;
	public SBuyPackageNetCs()
	{
	}
	public SBuyPackageNetCs(SBuyPackageNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public SBuyPackageNetCs(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBuyPackageNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SBuyPackageNetSc : SProto
{
	public Int32 Code = 0;
	public SBuyPackageNetSc()
	{
	}
	public SBuyPackageNetSc(SBuyPackageNetSc Obj_)
	{
		Code = Obj_.Code;
	}
	public SBuyPackageNetSc(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBuyPackageNetSc Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SBuyCostumeNetCs : SProto
{
	public Int32 Code = 0;
	public SBuyCostumeNetCs()
	{
	}
	public SBuyCostumeNetCs(SBuyCostumeNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public SBuyCostumeNetCs(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBuyCostumeNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SBuyCostumeNetSc : SProto
{
	public Int32 Code = 0;
	public SBuyCostumeNetSc()
	{
	}
	public SBuyCostumeNetSc(SBuyCostumeNetSc Obj_)
	{
		Code = Obj_.Code;
	}
	public SBuyCostumeNetSc(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBuyCostumeNetSc Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SPurchaseNetCs : SProto
{
	public String ProductID = "";
	public String PurchaseToken = "";
	public SPurchaseNetCs()
	{
	}
	public SPurchaseNetCs(SPurchaseNetCs Obj_)
	{
		ProductID = Obj_.ProductID;
		PurchaseToken = Obj_.PurchaseToken;
	}
	public SPurchaseNetCs(String ProductID_, String PurchaseToken_)
	{
		ProductID = ProductID_;
		PurchaseToken = PurchaseToken_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref ProductID);
		Stream_.Pop(ref PurchaseToken);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("ProductID", ref ProductID);
		Value_.Pop("PurchaseToken", ref PurchaseToken);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(ProductID);
		Stream_.Push(PurchaseToken);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("ProductID", ProductID);
		Value_.Push("PurchaseToken", PurchaseToken);
	}
	public void Set(SPurchaseNetCs Obj_)
	{
		ProductID = Obj_.ProductID;
		PurchaseToken = Obj_.PurchaseToken;
	}
	public override string StdName()
	{
		return "wstring,wstring";
	}
	public override string MemberName()
	{
		return "ProductID,PurchaseToken";
	}
}
public class SPurchaseNetSc : SProto
{
	public String ProductID = "";
	public TResource DiaPaidAdded = 0;
	public SPurchaseNetSc()
	{
	}
	public SPurchaseNetSc(SPurchaseNetSc Obj_)
	{
		ProductID = Obj_.ProductID;
		DiaPaidAdded = Obj_.DiaPaidAdded;
	}
	public SPurchaseNetSc(String ProductID_, TResource DiaPaidAdded_)
	{
		ProductID = ProductID_;
		DiaPaidAdded = DiaPaidAdded_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref ProductID);
		Stream_.Pop(ref DiaPaidAdded);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("ProductID", ref ProductID);
		Value_.Pop("DiaPaidAdded", ref DiaPaidAdded);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(ProductID);
		Stream_.Push(DiaPaidAdded);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("ProductID", ProductID);
		Value_.Push("DiaPaidAdded", DiaPaidAdded);
	}
	public void Set(SPurchaseNetSc Obj_)
	{
		ProductID = Obj_.ProductID;
		DiaPaidAdded = Obj_.DiaPaidAdded;
	}
	public override string StdName()
	{
		return "wstring,int32";
	}
	public override string MemberName()
	{
		return "ProductID,DiaPaidAdded";
	}
}
public class SDailyRewardNetCs : SProto
{
	public Boolean IsWatchedAd = false;
	public SDailyRewardNetCs()
	{
	}
	public SDailyRewardNetCs(SDailyRewardNetCs Obj_)
	{
		IsWatchedAd = Obj_.IsWatchedAd;
	}
	public SDailyRewardNetCs(Boolean IsWatchedAd_)
	{
		IsWatchedAd = IsWatchedAd_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref IsWatchedAd);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("IsWatchedAd", ref IsWatchedAd);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(IsWatchedAd);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("IsWatchedAd", IsWatchedAd);
	}
	public void Set(SDailyRewardNetCs Obj_)
	{
		IsWatchedAd = Obj_.IsWatchedAd;
	}
	public override string StdName()
	{
		return "bool";
	}
	public override string MemberName()
	{
		return "IsWatchedAd";
	}
}
public class SDailyRewardNetSc : SProto
{
	public SResourceTypeData Reward = new SResourceTypeData();
	public TimePoint ExpiredTime = new TimePoint();
	public Int32 CountLeft = 0;
	public SDailyRewardNetSc()
	{
	}
	public SDailyRewardNetSc(SDailyRewardNetSc Obj_)
	{
		Reward = Obj_.Reward;
		ExpiredTime = Obj_.ExpiredTime;
		CountLeft = Obj_.CountLeft;
	}
	public SDailyRewardNetSc(SResourceTypeData Reward_, TimePoint ExpiredTime_, Int32 CountLeft_)
	{
		Reward = Reward_;
		ExpiredTime = ExpiredTime_;
		CountLeft = CountLeft_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(Reward);
		Stream_.Pop(ref ExpiredTime);
		Stream_.Pop(ref CountLeft);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Reward", Reward);
		Value_.Pop("ExpiredTime", ref ExpiredTime);
		Value_.Pop("CountLeft", ref CountLeft);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Reward);
		Stream_.Push(ExpiredTime);
		Stream_.Push(CountLeft);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Reward", Reward);
		Value_.Push("ExpiredTime", ExpiredTime);
		Value_.Push("CountLeft", CountLeft);
	}
	public void Set(SDailyRewardNetSc Obj_)
	{
		Reward.Set(Obj_.Reward);
		ExpiredTime = Obj_.ExpiredTime;
		CountLeft = Obj_.CountLeft;
	}
	public override string StdName()
	{
		return "EResource,int32,time_point,int32";
	}
	public override string MemberName()
	{
		return "Type,Data,ExpiredTime,CountLeft";
	}
}
public class SDailyRewardFailNetSc : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SSelectCharNetCs : SProto
{
	public Int32 Code = 0;
	public SSelectCharNetCs()
	{
	}
	public SSelectCharNetCs(SSelectCharNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public SSelectCharNetCs(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SSelectCharNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SSingleStartNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SSingleStartNetSc : SProto
{
	public TResource GoldCost = 0;
	public Int32 PlayCount = 0;
	public TimePoint RefreshTime = new TimePoint();
	public TDoneQuests DoneQuests = new TDoneQuests();
	public SSingleStartNetSc()
	{
	}
	public SSingleStartNetSc(SSingleStartNetSc Obj_)
	{
		GoldCost = Obj_.GoldCost;
		PlayCount = Obj_.PlayCount;
		RefreshTime = Obj_.RefreshTime;
		DoneQuests = Obj_.DoneQuests;
	}
	public SSingleStartNetSc(TResource GoldCost_, Int32 PlayCount_, TimePoint RefreshTime_, TDoneQuests DoneQuests_)
	{
		GoldCost = GoldCost_;
		PlayCount = PlayCount_;
		RefreshTime = RefreshTime_;
		DoneQuests = DoneQuests_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref GoldCost);
		Stream_.Pop(ref PlayCount);
		Stream_.Pop(ref RefreshTime);
		{
			DoneQuests.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SQuestSlotIndexCount Value = new SQuestSlotIndexCount();
				Stream_.Pop(Value);
				DoneQuests.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("GoldCost", ref GoldCost);
		Value_.Pop("PlayCount", ref PlayCount);
		Value_.Pop("RefreshTime", ref RefreshTime);
		Value_.Pop("DoneQuests", ref DoneQuests);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(GoldCost);
		Stream_.Push(PlayCount);
		Stream_.Push(RefreshTime);
		Stream_.Push((Int32)DoneQuests.Count);
		foreach(var it in DoneQuests)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("GoldCost", GoldCost);
		Value_.Push("PlayCount", PlayCount);
		Value_.Push("RefreshTime", RefreshTime);
		Value_.Push("DoneQuests", DoneQuests);
	}
	public void Set(SSingleStartNetSc Obj_)
	{
		GoldCost = Obj_.GoldCost;
		PlayCount = Obj_.PlayCount;
		RefreshTime = Obj_.RefreshTime;
		DoneQuests = Obj_.DoneQuests;
	}
	public override string StdName()
	{
		return "int32,int32,time_point,{uint8,int32}";
	}
	public override string MemberName()
	{
		return "GoldCost,PlayCount,RefreshTime,DoneQuests";
	}
}
public class SSingleEndNetCs : SProto
{
	public Int32 Wave = 0;
	public Int32 Second = 0;
	public TResource Gold = 0;
	public TResource GoldAdded = 0;
	public TResource DiaAdded = 0;
	public SSingleEndNetCs()
	{
	}
	public SSingleEndNetCs(SSingleEndNetCs Obj_)
	{
		Wave = Obj_.Wave;
		Second = Obj_.Second;
		Gold = Obj_.Gold;
		GoldAdded = Obj_.GoldAdded;
		DiaAdded = Obj_.DiaAdded;
	}
	public SSingleEndNetCs(Int32 Wave_, Int32 Second_, TResource Gold_, TResource GoldAdded_, TResource DiaAdded_)
	{
		Wave = Wave_;
		Second = Second_;
		Gold = Gold_;
		GoldAdded = GoldAdded_;
		DiaAdded = DiaAdded_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Wave);
		Stream_.Pop(ref Second);
		Stream_.Pop(ref Gold);
		Stream_.Pop(ref GoldAdded);
		Stream_.Pop(ref DiaAdded);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Wave", ref Wave);
		Value_.Pop("Second", ref Second);
		Value_.Pop("Gold", ref Gold);
		Value_.Pop("GoldAdded", ref GoldAdded);
		Value_.Pop("DiaAdded", ref DiaAdded);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Wave);
		Stream_.Push(Second);
		Stream_.Push(Gold);
		Stream_.Push(GoldAdded);
		Stream_.Push(DiaAdded);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Wave", Wave);
		Value_.Push("Second", Second);
		Value_.Push("Gold", Gold);
		Value_.Push("GoldAdded", GoldAdded);
		Value_.Push("DiaAdded", DiaAdded);
	}
	public void Set(SSingleEndNetCs Obj_)
	{
		Wave = Obj_.Wave;
		Second = Obj_.Second;
		Gold = Obj_.Gold;
		GoldAdded = Obj_.GoldAdded;
		DiaAdded = Obj_.DiaAdded;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "Wave,Second,Gold,GoldAdded,DiaAdded";
	}
}
public class SSingleEndNetSc : SProto
{
	public TDoneQuests DoneQuests = new TDoneQuests();
	public SSingleEndNetSc()
	{
	}
	public SSingleEndNetSc(SSingleEndNetSc Obj_)
	{
		DoneQuests = Obj_.DoneQuests;
	}
	public SSingleEndNetSc(TDoneQuests DoneQuests_)
	{
		DoneQuests = DoneQuests_;
	}
	public override void Push(CStream Stream_)
	{
		{
			DoneQuests.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SQuestSlotIndexCount Value = new SQuestSlotIndexCount();
				Stream_.Pop(Value);
				DoneQuests.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("DoneQuests", ref DoneQuests);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)DoneQuests.Count);
		foreach(var it in DoneQuests)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("DoneQuests", DoneQuests);
	}
	public void Set(SSingleEndNetSc Obj_)
	{
		DoneQuests = Obj_.DoneQuests;
	}
	public override string StdName()
	{
		return "{uint8,int32}";
	}
	public override string MemberName()
	{
		return "DoneQuests";
	}
}
public class SIslandStartNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SIslandStartNetSc : SProto
{
	public TResource GoldCost = 0;
	public Int32 PlayCount = 0;
	public TimePoint RefreshTime = new TimePoint();
	public TDoneQuests DoneQuests = new TDoneQuests();
	public SIslandStartNetSc()
	{
	}
	public SIslandStartNetSc(SIslandStartNetSc Obj_)
	{
		GoldCost = Obj_.GoldCost;
		PlayCount = Obj_.PlayCount;
		RefreshTime = Obj_.RefreshTime;
		DoneQuests = Obj_.DoneQuests;
	}
	public SIslandStartNetSc(TResource GoldCost_, Int32 PlayCount_, TimePoint RefreshTime_, TDoneQuests DoneQuests_)
	{
		GoldCost = GoldCost_;
		PlayCount = PlayCount_;
		RefreshTime = RefreshTime_;
		DoneQuests = DoneQuests_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref GoldCost);
		Stream_.Pop(ref PlayCount);
		Stream_.Pop(ref RefreshTime);
		{
			DoneQuests.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SQuestSlotIndexCount Value = new SQuestSlotIndexCount();
				Stream_.Pop(Value);
				DoneQuests.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("GoldCost", ref GoldCost);
		Value_.Pop("PlayCount", ref PlayCount);
		Value_.Pop("RefreshTime", ref RefreshTime);
		Value_.Pop("DoneQuests", ref DoneQuests);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(GoldCost);
		Stream_.Push(PlayCount);
		Stream_.Push(RefreshTime);
		Stream_.Push((Int32)DoneQuests.Count);
		foreach(var it in DoneQuests)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("GoldCost", GoldCost);
		Value_.Push("PlayCount", PlayCount);
		Value_.Push("RefreshTime", RefreshTime);
		Value_.Push("DoneQuests", DoneQuests);
	}
	public void Set(SIslandStartNetSc Obj_)
	{
		GoldCost = Obj_.GoldCost;
		PlayCount = Obj_.PlayCount;
		RefreshTime = Obj_.RefreshTime;
		DoneQuests = Obj_.DoneQuests;
	}
	public override string StdName()
	{
		return "int32,int32,time_point,{uint8,int32}";
	}
	public override string MemberName()
	{
		return "GoldCost,PlayCount,RefreshTime,DoneQuests";
	}
}
public class SIslandEndNetCs : SProto
{
	public Int32 PassedIslandCount = 0;
	public TResource Gold = 0;
	public TResource GoldAdded = 0;
	public TResource DiaAdded = 0;
	public SIslandEndNetCs()
	{
	}
	public SIslandEndNetCs(SIslandEndNetCs Obj_)
	{
		PassedIslandCount = Obj_.PassedIslandCount;
		Gold = Obj_.Gold;
		GoldAdded = Obj_.GoldAdded;
		DiaAdded = Obj_.DiaAdded;
	}
	public SIslandEndNetCs(Int32 PassedIslandCount_, TResource Gold_, TResource GoldAdded_, TResource DiaAdded_)
	{
		PassedIslandCount = PassedIslandCount_;
		Gold = Gold_;
		GoldAdded = GoldAdded_;
		DiaAdded = DiaAdded_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref PassedIslandCount);
		Stream_.Pop(ref Gold);
		Stream_.Pop(ref GoldAdded);
		Stream_.Pop(ref DiaAdded);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("PassedIslandCount", ref PassedIslandCount);
		Value_.Pop("Gold", ref Gold);
		Value_.Pop("GoldAdded", ref GoldAdded);
		Value_.Pop("DiaAdded", ref DiaAdded);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(PassedIslandCount);
		Stream_.Push(Gold);
		Stream_.Push(GoldAdded);
		Stream_.Push(DiaAdded);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("PassedIslandCount", PassedIslandCount);
		Value_.Push("Gold", Gold);
		Value_.Push("GoldAdded", GoldAdded);
		Value_.Push("DiaAdded", DiaAdded);
	}
	public void Set(SIslandEndNetCs Obj_)
	{
		PassedIslandCount = Obj_.PassedIslandCount;
		Gold = Obj_.Gold;
		GoldAdded = Obj_.GoldAdded;
		DiaAdded = Obj_.DiaAdded;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "PassedIslandCount,Gold,GoldAdded,DiaAdded";
	}
}
public class SIslandEndNetSc : SProto
{
	public TDoneQuests DoneQuests = new TDoneQuests();
	public SIslandEndNetSc()
	{
	}
	public SIslandEndNetSc(SIslandEndNetSc Obj_)
	{
		DoneQuests = Obj_.DoneQuests;
	}
	public SIslandEndNetSc(TDoneQuests DoneQuests_)
	{
		DoneQuests = DoneQuests_;
	}
	public override void Push(CStream Stream_)
	{
		{
			DoneQuests.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SQuestSlotIndexCount Value = new SQuestSlotIndexCount();
				Stream_.Pop(Value);
				DoneQuests.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("DoneQuests", ref DoneQuests);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)DoneQuests.Count);
		foreach(var it in DoneQuests)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("DoneQuests", DoneQuests);
	}
	public void Set(SIslandEndNetSc Obj_)
	{
		DoneQuests = Obj_.DoneQuests;
	}
	public override string StdName()
	{
		return "{uint8,int32}";
	}
	public override string MemberName()
	{
		return "DoneQuests";
	}
}
public class SBattleType : SProto
{
	public SByte MemberCount = 0;
	public TTeamCnt TeamCount = 0;
	public SBattleType()
	{
	}
	public SBattleType(SBattleType Obj_)
	{
		MemberCount = Obj_.MemberCount;
		TeamCount = Obj_.TeamCount;
	}
	public SBattleType(SByte MemberCount_, TTeamCnt TeamCount_)
	{
		MemberCount = MemberCount_;
		TeamCount = TeamCount_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref MemberCount);
		Stream_.Pop(ref TeamCount);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("MemberCount", ref MemberCount);
		Value_.Pop("TeamCount", ref TeamCount);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(MemberCount);
		Stream_.Push(TeamCount);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("MemberCount", MemberCount);
		Value_.Push("TeamCount", TeamCount);
	}
	public void Set(SBattleType Obj_)
	{
		MemberCount = Obj_.MemberCount;
		TeamCount = Obj_.TeamCount;
	}
	public override string StdName()
	{
		return "int8,int8";
	}
	public override string MemberName()
	{
		return "MemberCount,TeamCount";
	}
}
public class SBattleRecord : SProto
{
	public Int32 TotalKillCount = 0;
	public Int32 TotalBalloonHitCount = 0;
	public SBattleRecord()
	{
	}
	public SBattleRecord(SBattleRecord Obj_)
	{
		TotalKillCount = Obj_.TotalKillCount;
		TotalBalloonHitCount = Obj_.TotalBalloonHitCount;
	}
	public SBattleRecord(Int32 TotalKillCount_, Int32 TotalBalloonHitCount_)
	{
		TotalKillCount = TotalKillCount_;
		TotalBalloonHitCount = TotalBalloonHitCount_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref TotalKillCount);
		Stream_.Pop(ref TotalBalloonHitCount);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("TotalKillCount", ref TotalKillCount);
		Value_.Pop("TotalBalloonHitCount", ref TotalBalloonHitCount);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(TotalKillCount);
		Stream_.Push(TotalBalloonHitCount);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("TotalKillCount", TotalKillCount);
		Value_.Push("TotalBalloonHitCount", TotalBalloonHitCount);
	}
	public void Set(SBattleRecord Obj_)
	{
		TotalKillCount = Obj_.TotalKillCount;
		TotalBalloonHitCount = Obj_.TotalBalloonHitCount;
	}
	public override string StdName()
	{
		return "int32,int32";
	}
	public override string MemberName()
	{
		return "TotalKillCount,TotalBalloonHitCount";
	}
}
public class SBattleJoinNetCs : SProto
{
	public SBattleType BattleType = new SBattleType();
	public SBattleJoinNetCs()
	{
	}
	public SBattleJoinNetCs(SBattleJoinNetCs Obj_)
	{
		BattleType = Obj_.BattleType;
	}
	public SBattleJoinNetCs(SBattleType BattleType_)
	{
		BattleType = BattleType_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(BattleType);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("BattleType", BattleType);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(BattleType);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("BattleType", BattleType);
	}
	public void Set(SBattleJoinNetCs Obj_)
	{
		BattleType.Set(Obj_.BattleType);
	}
	public override string StdName()
	{
		return "int8,int8";
	}
	public override string MemberName()
	{
		return "MemberCount,TeamCount";
	}
}
public class SBattleJoinNetSc : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SBattleOutNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SBattleOutNetSc : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SPumpInfo : SProto
{
	public SByte Count = 0;
	public SByte CountTo = 0;
	public Single Scale = 0.0f;
	public SPumpInfo()
	{
	}
	public SPumpInfo(SPumpInfo Obj_)
	{
		Count = Obj_.Count;
		CountTo = Obj_.CountTo;
		Scale = Obj_.Scale;
	}
	public SPumpInfo(SByte Count_, SByte CountTo_, Single Scale_)
	{
		Count = Count_;
		CountTo = CountTo_;
		Scale = Scale_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Count);
		Stream_.Pop(ref CountTo);
		Stream_.Pop(ref Scale);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Count", ref Count);
		Value_.Pop("CountTo", ref CountTo);
		Value_.Pop("Scale", ref Scale);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Count);
		Stream_.Push(CountTo);
		Stream_.Push(Scale);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Count", Count);
		Value_.Push("CountTo", CountTo);
		Value_.Push("Scale", Scale);
	}
	public void Set(SPumpInfo Obj_)
	{
		Count = Obj_.Count;
		CountTo = Obj_.CountTo;
		Scale = Obj_.Scale;
	}
	public override string StdName()
	{
		return "int8,int8,float";
	}
	public override string MemberName()
	{
		return "Count,CountTo,Scale";
	}
}
public class SParachuteInfo : SProto
{
	public Single Scale = 0.0f;
	public Single Velocity = 0.0f;
	public SParachuteInfo()
	{
	}
	public SParachuteInfo(SParachuteInfo Obj_)
	{
		Scale = Obj_.Scale;
		Velocity = Obj_.Velocity;
	}
	public SParachuteInfo(Single Scale_, Single Velocity_)
	{
		Scale = Scale_;
		Velocity = Velocity_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Scale);
		Stream_.Pop(ref Velocity);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Scale", ref Scale);
		Value_.Pop("Velocity", ref Velocity);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Scale);
		Stream_.Push(Velocity);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Scale", Scale);
		Value_.Push("Velocity", Velocity);
	}
	public void Set(SParachuteInfo Obj_)
	{
		Scale = Obj_.Scale;
		Velocity = Obj_.Velocity;
	}
	public override string StdName()
	{
		return "float,float";
	}
	public override string MemberName()
	{
		return "Scale,Velocity";
	}
}
public class SStaminaInfo : SProto
{
	public Int64 LastUsedTick = 0;
	public Single Stamina = 0.0f;
	public SStaminaInfo()
	{
	}
	public SStaminaInfo(SStaminaInfo Obj_)
	{
		LastUsedTick = Obj_.LastUsedTick;
		Stamina = Obj_.Stamina;
	}
	public SStaminaInfo(Int64 LastUsedTick_, Single Stamina_)
	{
		LastUsedTick = LastUsedTick_;
		Stamina = Stamina_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref LastUsedTick);
		Stream_.Pop(ref Stamina);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("LastUsedTick", ref LastUsedTick);
		Value_.Pop("Stamina", ref Stamina);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(LastUsedTick);
		Stream_.Push(Stamina);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("LastUsedTick", LastUsedTick);
		Value_.Push("Stamina", Stamina);
	}
	public void Set(SStaminaInfo Obj_)
	{
		LastUsedTick = Obj_.LastUsedTick;
		Stamina = Obj_.Stamina;
	}
	public override string StdName()
	{
		return "int64,float";
	}
	public override string MemberName()
	{
		return "LastUsedTick,Stamina";
	}
}
public class SStructMove : SProto
{
	public Boolean IsMoving = false;
	public Int32 Direction = 0;
	public Single StoppedDuration = 0.0f;
	public SStructMove()
	{
	}
	public SStructMove(SStructMove Obj_)
	{
		IsMoving = Obj_.IsMoving;
		Direction = Obj_.Direction;
		StoppedDuration = Obj_.StoppedDuration;
	}
	public SStructMove(Boolean IsMoving_, Int32 Direction_, Single StoppedDuration_)
	{
		IsMoving = IsMoving_;
		Direction = Direction_;
		StoppedDuration = StoppedDuration_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref IsMoving);
		Stream_.Pop(ref Direction);
		Stream_.Pop(ref StoppedDuration);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("IsMoving", ref IsMoving);
		Value_.Pop("Direction", ref Direction);
		Value_.Pop("StoppedDuration", ref StoppedDuration);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(IsMoving);
		Stream_.Push(Direction);
		Stream_.Push(StoppedDuration);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("IsMoving", IsMoving);
		Value_.Push("Direction", Direction);
		Value_.Push("StoppedDuration", StoppedDuration);
	}
	public void Set(SStructMove Obj_)
	{
		IsMoving = Obj_.IsMoving;
		Direction = Obj_.Direction;
		StoppedDuration = Obj_.StoppedDuration;
	}
	public override string StdName()
	{
		return "bool,int32,float";
	}
	public override string MemberName()
	{
		return "IsMoving,Direction,StoppedDuration";
	}
}
public class SStructMovePosition : SStructMove
{
	public SPoint LocalPosition = new SPoint();
	public SStructMovePosition()
	{
	}
	public SStructMovePosition(SStructMovePosition Obj_) : base(Obj_)
	{
		LocalPosition = Obj_.LocalPosition;
	}
	public SStructMovePosition(SStructMove Super_, SPoint LocalPosition_) : base(Super_)
	{
		LocalPosition = LocalPosition_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(LocalPosition);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("LocalPosition", LocalPosition);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(LocalPosition);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("LocalPosition", LocalPosition);
	}
	public void Set(SStructMovePosition Obj_)
	{
		base.Set(Obj_);
		LocalPosition.Set(Obj_.LocalPosition);
	}
	public override string StdName()
	{
		return "bool,int32,float,float,float";
	}
	public override string MemberName()
	{
		return "IsMoving,Direction,StoppedDuration,X,Y";
	}
}
public class SBattlePlayer : SProto
{
	public TUID UID = 0;
	public String Nick = "";
	public String CountryCode = "";
	public TTeamCnt TeamIndex = 0;
	public Int32 CharCode = 0;
	public Int32 Point = 0;
	public TCostumes Costumes = new TCostumes();
	public SBattlePlayer()
	{
	}
	public SBattlePlayer(SBattlePlayer Obj_)
	{
		UID = Obj_.UID;
		Nick = Obj_.Nick;
		CountryCode = Obj_.CountryCode;
		TeamIndex = Obj_.TeamIndex;
		CharCode = Obj_.CharCode;
		Point = Obj_.Point;
		Costumes = Obj_.Costumes;
	}
	public SBattlePlayer(TUID UID_, String Nick_, String CountryCode_, TTeamCnt TeamIndex_, Int32 CharCode_, Int32 Point_, TCostumes Costumes_)
	{
		UID = UID_;
		Nick = Nick_;
		CountryCode = CountryCode_;
		TeamIndex = TeamIndex_;
		CharCode = CharCode_;
		Point = Point_;
		Costumes = Costumes_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref UID);
		Stream_.Pop(ref Nick);
		Stream_.Pop(ref CountryCode);
		Stream_.Pop(ref TeamIndex);
		Stream_.Pop(ref CharCode);
		Stream_.Pop(ref Point);
		{
			Costumes.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				Costumes.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("UID", ref UID);
		Value_.Pop("Nick", ref Nick);
		Value_.Pop("CountryCode", ref CountryCode);
		Value_.Pop("TeamIndex", ref TeamIndex);
		Value_.Pop("CharCode", ref CharCode);
		Value_.Pop("Point", ref Point);
		Value_.Pop("Costumes", ref Costumes);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(UID);
		Stream_.Push(Nick);
		Stream_.Push(CountryCode);
		Stream_.Push(TeamIndex);
		Stream_.Push(CharCode);
		Stream_.Push(Point);
		Stream_.Push((Int32)Costumes.Count);
		foreach(var it in Costumes)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("UID", UID);
		Value_.Push("Nick", Nick);
		Value_.Push("CountryCode", CountryCode);
		Value_.Push("TeamIndex", TeamIndex);
		Value_.Push("CharCode", CharCode);
		Value_.Push("Point", Point);
		Value_.Push("Costumes", Costumes);
	}
	public void Set(SBattlePlayer Obj_)
	{
		UID = Obj_.UID;
		Nick = Obj_.Nick;
		CountryCode = Obj_.CountryCode;
		TeamIndex = Obj_.TeamIndex;
		CharCode = Obj_.CharCode;
		Point = Obj_.Point;
		Costumes = Obj_.Costumes;
	}
	public override string StdName()
	{
		return "int64,wstring,wstring,int8,int32,int32,{int32}";
	}
	public override string MemberName()
	{
		return "UID,Nick,CountryCode,TeamIndex,CharCode,Point,Costumes";
	}
}
public class SCharacter : SProto
{
	public Boolean IsGround = false;
	public SByte Dir = 0;
	public SByte BalloonCount = 0;
	public SPumpInfo PumpInfo = new SPumpInfo();
	public SParachuteInfo ParachuteInfo = new SParachuteInfo();
	public SStaminaInfo StaminaInfo = new SStaminaInfo();
	public SByte Face = 0;
	public SPoint Pos = new SPoint();
	public SPoint Vel = new SPoint();
	public SPoint Acc = new SPoint();
	public Int64 InvulnerableEndTick = 0;
	public Int32 ChainKillCount = 0;
	public Int64 LastKillTick = 0;
	public Int64 RegenTick = 0;
	public SCharacter()
	{
	}
	public SCharacter(SCharacter Obj_)
	{
		IsGround = Obj_.IsGround;
		Dir = Obj_.Dir;
		BalloonCount = Obj_.BalloonCount;
		PumpInfo = Obj_.PumpInfo;
		ParachuteInfo = Obj_.ParachuteInfo;
		StaminaInfo = Obj_.StaminaInfo;
		Face = Obj_.Face;
		Pos = Obj_.Pos;
		Vel = Obj_.Vel;
		Acc = Obj_.Acc;
		InvulnerableEndTick = Obj_.InvulnerableEndTick;
		ChainKillCount = Obj_.ChainKillCount;
		LastKillTick = Obj_.LastKillTick;
		RegenTick = Obj_.RegenTick;
	}
	public SCharacter(Boolean IsGround_, SByte Dir_, SByte BalloonCount_, SPumpInfo PumpInfo_, SParachuteInfo ParachuteInfo_, SStaminaInfo StaminaInfo_, SByte Face_, SPoint Pos_, SPoint Vel_, SPoint Acc_, Int64 InvulnerableEndTick_, Int32 ChainKillCount_, Int64 LastKillTick_, Int64 RegenTick_)
	{
		IsGround = IsGround_;
		Dir = Dir_;
		BalloonCount = BalloonCount_;
		PumpInfo = PumpInfo_;
		ParachuteInfo = ParachuteInfo_;
		StaminaInfo = StaminaInfo_;
		Face = Face_;
		Pos = Pos_;
		Vel = Vel_;
		Acc = Acc_;
		InvulnerableEndTick = InvulnerableEndTick_;
		ChainKillCount = ChainKillCount_;
		LastKillTick = LastKillTick_;
		RegenTick = RegenTick_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref IsGround);
		Stream_.Pop(ref Dir);
		Stream_.Pop(ref BalloonCount);
		Stream_.Pop(PumpInfo);
		Stream_.Pop(ParachuteInfo);
		Stream_.Pop(StaminaInfo);
		Stream_.Pop(ref Face);
		Stream_.Pop(Pos);
		Stream_.Pop(Vel);
		Stream_.Pop(Acc);
		Stream_.Pop(ref InvulnerableEndTick);
		Stream_.Pop(ref ChainKillCount);
		Stream_.Pop(ref LastKillTick);
		Stream_.Pop(ref RegenTick);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("IsGround", ref IsGround);
		Value_.Pop("Dir", ref Dir);
		Value_.Pop("BalloonCount", ref BalloonCount);
		Value_.Pop("PumpInfo", PumpInfo);
		Value_.Pop("ParachuteInfo", ParachuteInfo);
		Value_.Pop("StaminaInfo", StaminaInfo);
		Value_.Pop("Face", ref Face);
		Value_.Pop("Pos", Pos);
		Value_.Pop("Vel", Vel);
		Value_.Pop("Acc", Acc);
		Value_.Pop("InvulnerableEndTick", ref InvulnerableEndTick);
		Value_.Pop("ChainKillCount", ref ChainKillCount);
		Value_.Pop("LastKillTick", ref LastKillTick);
		Value_.Pop("RegenTick", ref RegenTick);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(IsGround);
		Stream_.Push(Dir);
		Stream_.Push(BalloonCount);
		Stream_.Push(PumpInfo);
		Stream_.Push(ParachuteInfo);
		Stream_.Push(StaminaInfo);
		Stream_.Push(Face);
		Stream_.Push(Pos);
		Stream_.Push(Vel);
		Stream_.Push(Acc);
		Stream_.Push(InvulnerableEndTick);
		Stream_.Push(ChainKillCount);
		Stream_.Push(LastKillTick);
		Stream_.Push(RegenTick);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("IsGround", IsGround);
		Value_.Push("Dir", Dir);
		Value_.Push("BalloonCount", BalloonCount);
		Value_.Push("PumpInfo", PumpInfo);
		Value_.Push("ParachuteInfo", ParachuteInfo);
		Value_.Push("StaminaInfo", StaminaInfo);
		Value_.Push("Face", Face);
		Value_.Push("Pos", Pos);
		Value_.Push("Vel", Vel);
		Value_.Push("Acc", Acc);
		Value_.Push("InvulnerableEndTick", InvulnerableEndTick);
		Value_.Push("ChainKillCount", ChainKillCount);
		Value_.Push("LastKillTick", LastKillTick);
		Value_.Push("RegenTick", RegenTick);
	}
	public void Set(SCharacter Obj_)
	{
		IsGround = Obj_.IsGround;
		Dir = Obj_.Dir;
		BalloonCount = Obj_.BalloonCount;
		PumpInfo.Set(Obj_.PumpInfo);
		ParachuteInfo.Set(Obj_.ParachuteInfo);
		StaminaInfo.Set(Obj_.StaminaInfo);
		Face = Obj_.Face;
		Pos.Set(Obj_.Pos);
		Vel.Set(Obj_.Vel);
		Acc.Set(Obj_.Acc);
		InvulnerableEndTick = Obj_.InvulnerableEndTick;
		ChainKillCount = Obj_.ChainKillCount;
		LastKillTick = Obj_.LastKillTick;
		RegenTick = Obj_.RegenTick;
	}
	public override string StdName()
	{
		return "bool,int8,int8,int8,int8,float,float,float,int64,float,int8,float,float,float,float,float,float,int64,int32,int64,int64";
	}
	public override string MemberName()
	{
		return "IsGround,Dir,BalloonCount,Count,CountTo,Scale,Scale,Velocity,LastUsedTick,Stamina,Face,X,Y,X,Y,X,Y,InvulnerableEndTick,ChainKillCount,LastKillTick,RegenTick";
	}
}
public class STeamBattleInfo : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SBattle : SProto
{
	public SBattleType BattleType = new SBattleType();
	public Int32 MapIndex = 0;
	public SBattle()
	{
	}
	public SBattle(SBattle Obj_)
	{
		BattleType = Obj_.BattleType;
		MapIndex = Obj_.MapIndex;
	}
	public SBattle(SBattleType BattleType_, Int32 MapIndex_)
	{
		BattleType = BattleType_;
		MapIndex = MapIndex_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(BattleType);
		Stream_.Pop(ref MapIndex);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("BattleType", BattleType);
		Value_.Pop("MapIndex", ref MapIndex);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(BattleType);
		Stream_.Push(MapIndex);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("BattleType", BattleType);
		Value_.Push("MapIndex", MapIndex);
	}
	public void Set(SBattle Obj_)
	{
		BattleType.Set(Obj_.BattleType);
		MapIndex = Obj_.MapIndex;
	}
	public override string StdName()
	{
		return "int8,int8,int32";
	}
	public override string MemberName()
	{
		return "MemberCount,TeamCount,MapIndex";
	}
}
public class SBattleBeginNetSc : SBattle
{
	public List<SBattlePlayer> Players = new List<SBattlePlayer>();
	public SBattleBeginNetSc()
	{
	}
	public SBattleBeginNetSc(SBattleBeginNetSc Obj_) : base(Obj_)
	{
		Players = Obj_.Players;
	}
	public SBattleBeginNetSc(SBattle Super_, List<SBattlePlayer> Players_) : base(Super_)
	{
		Players = Players_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		{
			Players.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SBattlePlayer Value = new SBattlePlayer();
				Stream_.Pop(Value);
				Players.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("Players", ref Players);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push((Int32)Players.Count);
		foreach(var it in Players)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("Players", Players);
	}
	public void Set(SBattleBeginNetSc Obj_)
	{
		base.Set(Obj_);
		Players = Obj_.Players;
	}
	public override string StdName()
	{
		return "int8,int8,int32,{int64,wstring,wstring,int8,int32,int32,{int32}}";
	}
	public override string MemberName()
	{
		return "MemberCount,TeamCount,MapIndex,Players";
	}
}
public class SBattleMatchingNetSc : SProto
{
	public Int32 UserCount = 0;
	public SBattleMatchingNetSc()
	{
	}
	public SBattleMatchingNetSc(SBattleMatchingNetSc Obj_)
	{
		UserCount = Obj_.UserCount;
	}
	public SBattleMatchingNetSc(Int32 UserCount_)
	{
		UserCount = UserCount_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref UserCount);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("UserCount", ref UserCount);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(UserCount);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("UserCount", UserCount);
	}
	public void Set(SBattleMatchingNetSc Obj_)
	{
		UserCount = Obj_.UserCount;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "UserCount";
	}
}
public class SBattleStartNetSc : SProto
{
	public TimePoint EndTime = new TimePoint();
	public SBattleStartNetSc()
	{
	}
	public SBattleStartNetSc(SBattleStartNetSc Obj_)
	{
		EndTime = Obj_.EndTime;
	}
	public SBattleStartNetSc(TimePoint EndTime_)
	{
		EndTime = EndTime_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref EndTime);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("EndTime", ref EndTime);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(EndTime);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("EndTime", EndTime);
	}
	public void Set(SBattleStartNetSc Obj_)
	{
		EndTime = Obj_.EndTime;
	}
	public override string StdName()
	{
		return "time_point";
	}
	public override string MemberName()
	{
		return "EndTime";
	}
}
public class SBattleBeginStartNetSc : SBattleBeginNetSc
{
	public SBattleRecord Record = new SBattleRecord();
	public List<SCharacter> Characters = new List<SCharacter>();
	public TimePoint EndTime = new TimePoint();
	public Int64 Tick = 0;
	public List<SStructMovePosition> StructMovePositions = new List<SStructMovePosition>();
	public SBattleBeginStartNetSc()
	{
	}
	public SBattleBeginStartNetSc(SBattleBeginStartNetSc Obj_) : base(Obj_)
	{
		Record = Obj_.Record;
		Characters = Obj_.Characters;
		EndTime = Obj_.EndTime;
		Tick = Obj_.Tick;
		StructMovePositions = Obj_.StructMovePositions;
	}
	public SBattleBeginStartNetSc(SBattleBeginNetSc Super_, SBattleRecord Record_, List<SCharacter> Characters_, TimePoint EndTime_, Int64 Tick_, List<SStructMovePosition> StructMovePositions_) : base(Super_)
	{
		Record = Record_;
		Characters = Characters_;
		EndTime = EndTime_;
		Tick = Tick_;
		StructMovePositions = StructMovePositions_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(Record);
		{
			Characters.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SCharacter Value = new SCharacter();
				Stream_.Pop(Value);
				Characters.Add(Value);
			}
		}
		Stream_.Pop(ref EndTime);
		Stream_.Pop(ref Tick);
		{
			StructMovePositions.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SStructMovePosition Value = new SStructMovePosition();
				Stream_.Pop(Value);
				StructMovePositions.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("Record", Record);
		Value_.Pop("Characters", ref Characters);
		Value_.Pop("EndTime", ref EndTime);
		Value_.Pop("Tick", ref Tick);
		Value_.Pop("StructMovePositions", ref StructMovePositions);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(Record);
		Stream_.Push((Int32)Characters.Count);
		foreach(var it in Characters)
		{
			Stream_.Push(it);
		}
		Stream_.Push(EndTime);
		Stream_.Push(Tick);
		Stream_.Push((Int32)StructMovePositions.Count);
		foreach(var it in StructMovePositions)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("Record", Record);
		Value_.Push("Characters", Characters);
		Value_.Push("EndTime", EndTime);
		Value_.Push("Tick", Tick);
		Value_.Push("StructMovePositions", StructMovePositions);
	}
	public void Set(SBattleBeginStartNetSc Obj_)
	{
		base.Set(Obj_);
		Record.Set(Obj_.Record);
		Characters = Obj_.Characters;
		EndTime = Obj_.EndTime;
		Tick = Obj_.Tick;
		StructMovePositions = Obj_.StructMovePositions;
	}
	public override string StdName()
	{
		return "int8,int8,int32,{int64,wstring,wstring,int8,int32,int32,{int32}},int32,int32,{bool,int8,int8,int8,int8,float,float,float,int64,float,int8,float,float,float,float,float,float,int64,int32,int64,int64},time_point,int64,{bool,int32,float,float,float}";
	}
	public override string MemberName()
	{
		return "MemberCount,TeamCount,MapIndex,Players,TotalKillCount,TotalBalloonHitCount,Characters,EndTime,Tick,StructMovePositions";
	}
}
public class SBattleEndPlayer : SProto
{
	public Int32 AddedPoint = 0;
	public Int32 AddedGold = 0;
	public Int32 BattlePoint = 0;
	public SBattleEndPlayer()
	{
	}
	public SBattleEndPlayer(SBattleEndPlayer Obj_)
	{
		AddedPoint = Obj_.AddedPoint;
		AddedGold = Obj_.AddedGold;
		BattlePoint = Obj_.BattlePoint;
	}
	public SBattleEndPlayer(Int32 AddedPoint_, Int32 AddedGold_, Int32 BattlePoint_)
	{
		AddedPoint = AddedPoint_;
		AddedGold = AddedGold_;
		BattlePoint = BattlePoint_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref AddedPoint);
		Stream_.Pop(ref AddedGold);
		Stream_.Pop(ref BattlePoint);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("AddedPoint", ref AddedPoint);
		Value_.Pop("AddedGold", ref AddedGold);
		Value_.Pop("BattlePoint", ref BattlePoint);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(AddedPoint);
		Stream_.Push(AddedGold);
		Stream_.Push(BattlePoint);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("AddedPoint", AddedPoint);
		Value_.Push("AddedGold", AddedGold);
		Value_.Push("BattlePoint", BattlePoint);
	}
	public void Set(SBattleEndPlayer Obj_)
	{
		AddedPoint = Obj_.AddedPoint;
		AddedGold = Obj_.AddedGold;
		BattlePoint = Obj_.BattlePoint;
	}
	public override string StdName()
	{
		return "int32,int32,int32";
	}
	public override string MemberName()
	{
		return "AddedPoint,AddedGold,BattlePoint";
	}
}
public class SBattleEndNetSc : SProto
{
	public List<SBattleEndPlayer> BattleEndPlayers = new List<SBattleEndPlayer>();
	public TTeamBattleInfos TeamBattleInfos = new TTeamBattleInfos();
	public TDoneQuests DoneQuests = new TDoneQuests();
	public SBattleEndNetSc()
	{
	}
	public SBattleEndNetSc(SBattleEndNetSc Obj_)
	{
		BattleEndPlayers = Obj_.BattleEndPlayers;
		TeamBattleInfos = Obj_.TeamBattleInfos;
		DoneQuests = Obj_.DoneQuests;
	}
	public SBattleEndNetSc(List<SBattleEndPlayer> BattleEndPlayers_, TTeamBattleInfos TeamBattleInfos_, TDoneQuests DoneQuests_)
	{
		BattleEndPlayers = BattleEndPlayers_;
		TeamBattleInfos = TeamBattleInfos_;
		DoneQuests = DoneQuests_;
	}
	public override void Push(CStream Stream_)
	{
		{
			BattleEndPlayers.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SBattleEndPlayer Value = new SBattleEndPlayer();
				Stream_.Pop(Value);
				BattleEndPlayers.Add(Value);
			}
		}
		{
			TeamBattleInfos.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				STeamBattleInfo Value = new STeamBattleInfo();
				Stream_.Pop(Value);
				TeamBattleInfos.Add(Value);
			}
		}
		{
			DoneQuests.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SQuestSlotIndexCount Value = new SQuestSlotIndexCount();
				Stream_.Pop(Value);
				DoneQuests.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("BattleEndPlayers", ref BattleEndPlayers);
		Value_.Pop("TeamBattleInfos", ref TeamBattleInfos);
		Value_.Pop("DoneQuests", ref DoneQuests);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)BattleEndPlayers.Count);
		foreach(var it in BattleEndPlayers)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)TeamBattleInfos.Count);
		foreach(var it in TeamBattleInfos)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)DoneQuests.Count);
		foreach(var it in DoneQuests)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("BattleEndPlayers", BattleEndPlayers);
		Value_.Push("TeamBattleInfos", TeamBattleInfos);
		Value_.Push("DoneQuests", DoneQuests);
	}
	public void Set(SBattleEndNetSc Obj_)
	{
		BattleEndPlayers = Obj_.BattleEndPlayers;
		TeamBattleInfos = Obj_.TeamBattleInfos;
		DoneQuests = Obj_.DoneQuests;
	}
	public override string StdName()
	{
		return "{int32,int32,int32},{},{uint8,int32}";
	}
	public override string MemberName()
	{
		return "BattleEndPlayers,TeamBattleInfos,DoneQuests";
	}
}
public class SBattleSyncNetSc : SProto
{
	public Int64 Tick = 0;
	public SBattleSyncNetSc()
	{
	}
	public SBattleSyncNetSc(SBattleSyncNetSc Obj_)
	{
		Tick = Obj_.Tick;
	}
	public SBattleSyncNetSc(Int64 Tick_)
	{
		Tick = Tick_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Tick);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Tick", ref Tick);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Tick);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Tick", Tick);
	}
	public void Set(SBattleSyncNetSc Obj_)
	{
		Tick = Obj_.Tick;
	}
	public override string StdName()
	{
		return "int64";
	}
	public override string MemberName()
	{
		return "Tick";
	}
}
public class SBattleTouchNetCs : SProto
{
	public SByte Dir = 0;
	public SBattleTouchNetCs()
	{
	}
	public SBattleTouchNetCs(SBattleTouchNetCs Obj_)
	{
		Dir = Obj_.Dir;
	}
	public SBattleTouchNetCs(SByte Dir_)
	{
		Dir = Dir_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Dir);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Dir", ref Dir);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Dir);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Dir", Dir);
	}
	public void Set(SBattleTouchNetCs Obj_)
	{
		Dir = Obj_.Dir;
	}
	public override string StdName()
	{
		return "int8";
	}
	public override string MemberName()
	{
		return "Dir";
	}
}
public class SBattleTouchNetSc : SProto
{
	public Int64 Tick = 0;
	public Int32 PlayerIndex = 0;
	public SByte Dir = 0;
	public SBattleTouchNetSc()
	{
	}
	public SBattleTouchNetSc(SBattleTouchNetSc Obj_)
	{
		Tick = Obj_.Tick;
		PlayerIndex = Obj_.PlayerIndex;
		Dir = Obj_.Dir;
	}
	public SBattleTouchNetSc(Int64 Tick_, Int32 PlayerIndex_, SByte Dir_)
	{
		Tick = Tick_;
		PlayerIndex = PlayerIndex_;
		Dir = Dir_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Tick);
		Stream_.Pop(ref PlayerIndex);
		Stream_.Pop(ref Dir);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Tick", ref Tick);
		Value_.Pop("PlayerIndex", ref PlayerIndex);
		Value_.Pop("Dir", ref Dir);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Tick);
		Stream_.Push(PlayerIndex);
		Stream_.Push(Dir);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Tick", Tick);
		Value_.Push("PlayerIndex", PlayerIndex);
		Value_.Push("Dir", Dir);
	}
	public void Set(SBattleTouchNetSc Obj_)
	{
		Tick = Obj_.Tick;
		PlayerIndex = Obj_.PlayerIndex;
		Dir = Obj_.Dir;
	}
	public override string StdName()
	{
		return "int64,int32,int8";
	}
	public override string MemberName()
	{
		return "Tick,PlayerIndex,Dir";
	}
}
public class SBattlePushNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SBattlePushNetSc : SProto
{
	public Int64 Tick = 0;
	public Int32 PlayerIndex = 0;
	public SBattlePushNetSc()
	{
	}
	public SBattlePushNetSc(SBattlePushNetSc Obj_)
	{
		Tick = Obj_.Tick;
		PlayerIndex = Obj_.PlayerIndex;
	}
	public SBattlePushNetSc(Int64 Tick_, Int32 PlayerIndex_)
	{
		Tick = Tick_;
		PlayerIndex = PlayerIndex_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Tick);
		Stream_.Pop(ref PlayerIndex);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Tick", ref Tick);
		Value_.Pop("PlayerIndex", ref PlayerIndex);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Tick);
		Stream_.Push(PlayerIndex);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Tick", Tick);
		Value_.Push("PlayerIndex", PlayerIndex);
	}
	public void Set(SBattlePushNetSc Obj_)
	{
		Tick = Obj_.Tick;
		PlayerIndex = Obj_.PlayerIndex;
	}
	public override string StdName()
	{
		return "int64,int32";
	}
	public override string MemberName()
	{
		return "Tick,PlayerIndex";
	}
}
public class SBattleIconNetCs : SProto
{
	public Int32 Code = 0;
	public SBattleIconNetCs()
	{
	}
	public SBattleIconNetCs(SBattleIconNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public SBattleIconNetCs(Int32 Code_)
	{
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
	}
	public void Set(SBattleIconNetCs Obj_)
	{
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "Code";
	}
}
public class SBattleIconNetSc : SProto
{
	public Int32 PlayerIndex = 0;
	public Int32 Code = 0;
	public SBattleIconNetSc()
	{
	}
	public SBattleIconNetSc(SBattleIconNetSc Obj_)
	{
		PlayerIndex = Obj_.PlayerIndex;
		Code = Obj_.Code;
	}
	public SBattleIconNetSc(Int32 PlayerIndex_, Int32 Code_)
	{
		PlayerIndex = PlayerIndex_;
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref PlayerIndex);
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("PlayerIndex", ref PlayerIndex);
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(PlayerIndex);
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("PlayerIndex", PlayerIndex);
		Value_.Push("Code", Code);
	}
	public void Set(SBattleIconNetSc Obj_)
	{
		PlayerIndex = Obj_.PlayerIndex;
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "int32,int32";
	}
	public override string MemberName()
	{
		return "PlayerIndex,Code";
	}
}
public class SBattleLinkNetSc : SProto
{
	public Int64 Tick = 0;
	public Int32 PlayerIndex = 0;
	public SBattleLinkNetSc()
	{
	}
	public SBattleLinkNetSc(SBattleLinkNetSc Obj_)
	{
		Tick = Obj_.Tick;
		PlayerIndex = Obj_.PlayerIndex;
	}
	public SBattleLinkNetSc(Int64 Tick_, Int32 PlayerIndex_)
	{
		Tick = Tick_;
		PlayerIndex = PlayerIndex_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Tick);
		Stream_.Pop(ref PlayerIndex);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Tick", ref Tick);
		Value_.Pop("PlayerIndex", ref PlayerIndex);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Tick);
		Stream_.Push(PlayerIndex);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Tick", Tick);
		Value_.Push("PlayerIndex", PlayerIndex);
	}
	public void Set(SBattleLinkNetSc Obj_)
	{
		Tick = Obj_.Tick;
		PlayerIndex = Obj_.PlayerIndex;
	}
	public override string StdName()
	{
		return "int64,int32";
	}
	public override string MemberName()
	{
		return "Tick,PlayerIndex";
	}
}
public class SBattleUnLinkNetSc : SProto
{
	public Int64 Tick = 0;
	public Int32 PlayerIndex = 0;
	public SBattleUnLinkNetSc()
	{
	}
	public SBattleUnLinkNetSc(SBattleUnLinkNetSc Obj_)
	{
		Tick = Obj_.Tick;
		PlayerIndex = Obj_.PlayerIndex;
	}
	public SBattleUnLinkNetSc(Int64 Tick_, Int32 PlayerIndex_)
	{
		Tick = Tick_;
		PlayerIndex = PlayerIndex_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Tick);
		Stream_.Pop(ref PlayerIndex);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Tick", ref Tick);
		Value_.Pop("PlayerIndex", ref PlayerIndex);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Tick);
		Stream_.Push(PlayerIndex);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Tick", Tick);
		Value_.Push("PlayerIndex", PlayerIndex);
	}
	public void Set(SBattleUnLinkNetSc Obj_)
	{
		Tick = Obj_.Tick;
		PlayerIndex = Obj_.PlayerIndex;
	}
	public override string StdName()
	{
		return "int64,int32";
	}
	public override string MemberName()
	{
		return "Tick,PlayerIndex";
	}
}
public class SRankingUserCore : SProto
{
	public String Nick = "";
	public Int32 CharCode = 0;
	public String CountryCode = "";
	public SRankingUserCore()
	{
	}
	public SRankingUserCore(SRankingUserCore Obj_)
	{
		Nick = Obj_.Nick;
		CharCode = Obj_.CharCode;
		CountryCode = Obj_.CountryCode;
	}
	public SRankingUserCore(String Nick_, Int32 CharCode_, String CountryCode_)
	{
		Nick = Nick_;
		CharCode = CharCode_;
		CountryCode = CountryCode_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Nick);
		Stream_.Pop(ref CharCode);
		Stream_.Pop(ref CountryCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Nick", ref Nick);
		Value_.Pop("CharCode", ref CharCode);
		Value_.Pop("CountryCode", ref CountryCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Nick);
		Stream_.Push(CharCode);
		Stream_.Push(CountryCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Nick", Nick);
		Value_.Push("CharCode", CharCode);
		Value_.Push("CountryCode", CountryCode);
	}
	public void Set(SRankingUserCore Obj_)
	{
		Nick = Obj_.Nick;
		CharCode = Obj_.CharCode;
		CountryCode = Obj_.CountryCode;
	}
	public override string StdName()
	{
		return "wstring,int32,wstring";
	}
	public override string MemberName()
	{
		return "Nick,CharCode,CountryCode";
	}
}
public class SRankingUser : SRankingUserCore
{
	public TUID UID = 0;
	public Int32 Point = 0;
	public SRankingUser()
	{
	}
	public SRankingUser(SRankingUser Obj_) : base(Obj_)
	{
		UID = Obj_.UID;
		Point = Obj_.Point;
	}
	public SRankingUser(SRankingUserCore Super_, TUID UID_, Int32 Point_) : base(Super_)
	{
		UID = UID_;
		Point = Point_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref UID);
		Stream_.Pop(ref Point);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("UID", ref UID);
		Value_.Pop("Point", ref Point);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(UID);
		Stream_.Push(Point);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("UID", UID);
		Value_.Push("Point", Point);
	}
	public void Set(SRankingUser Obj_)
	{
		base.Set(Obj_);
		UID = Obj_.UID;
		Point = Obj_.Point;
	}
	public override string StdName()
	{
		return "wstring,int32,wstring,int64,int32";
	}
	public override string MemberName()
	{
		return "Nick,CharCode,CountryCode,UID,Point";
	}
}
public class SRankingUserSingleCore : SRankingUserCore
{
	public Int32 Wave = 0;
	public Int32 Second = 0;
	public Int32 Gold = 0;
	public SRankingUserSingleCore()
	{
	}
	public SRankingUserSingleCore(SRankingUserSingleCore Obj_) : base(Obj_)
	{
		Wave = Obj_.Wave;
		Second = Obj_.Second;
		Gold = Obj_.Gold;
	}
	public SRankingUserSingleCore(SRankingUserCore Super_, Int32 Wave_, Int32 Second_, Int32 Gold_) : base(Super_)
	{
		Wave = Wave_;
		Second = Second_;
		Gold = Gold_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref Wave);
		Stream_.Pop(ref Second);
		Stream_.Pop(ref Gold);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("Wave", ref Wave);
		Value_.Pop("Second", ref Second);
		Value_.Pop("Gold", ref Gold);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(Wave);
		Stream_.Push(Second);
		Stream_.Push(Gold);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("Wave", Wave);
		Value_.Push("Second", Second);
		Value_.Push("Gold", Gold);
	}
	public void Set(SRankingUserSingleCore Obj_)
	{
		base.Set(Obj_);
		Wave = Obj_.Wave;
		Second = Obj_.Second;
		Gold = Obj_.Gold;
	}
	public override string StdName()
	{
		return "wstring,int32,wstring,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "Nick,CharCode,CountryCode,Wave,Second,Gold";
	}
}
public class SRankingUserSingle : SRankingUserSingleCore
{
	public TUID UID = 0;
	public Int32 Point = 0;
	public SRankingUserSingle()
	{
	}
	public SRankingUserSingle(SRankingUserSingle Obj_) : base(Obj_)
	{
		UID = Obj_.UID;
		Point = Obj_.Point;
	}
	public SRankingUserSingle(SRankingUserSingleCore Super_, TUID UID_, Int32 Point_) : base(Super_)
	{
		UID = UID_;
		Point = Point_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref UID);
		Stream_.Pop(ref Point);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("UID", ref UID);
		Value_.Pop("Point", ref Point);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(UID);
		Stream_.Push(Point);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("UID", UID);
		Value_.Push("Point", Point);
	}
	public void Set(SRankingUserSingle Obj_)
	{
		base.Set(Obj_);
		UID = Obj_.UID;
		Point = Obj_.Point;
	}
	public override string StdName()
	{
		return "wstring,int32,wstring,int32,int32,int32,int64,int32";
	}
	public override string MemberName()
	{
		return "Nick,CharCode,CountryCode,Wave,Second,Gold,UID,Point";
	}
}
public class SRankingUserIslandCore : SRankingUserCore
{
	public Int32 PassedIslandCount = 0;
	public Int32 Gold = 0;
	public SRankingUserIslandCore()
	{
	}
	public SRankingUserIslandCore(SRankingUserIslandCore Obj_) : base(Obj_)
	{
		PassedIslandCount = Obj_.PassedIslandCount;
		Gold = Obj_.Gold;
	}
	public SRankingUserIslandCore(SRankingUserCore Super_, Int32 PassedIslandCount_, Int32 Gold_) : base(Super_)
	{
		PassedIslandCount = PassedIslandCount_;
		Gold = Gold_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref PassedIslandCount);
		Stream_.Pop(ref Gold);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("PassedIslandCount", ref PassedIslandCount);
		Value_.Pop("Gold", ref Gold);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(PassedIslandCount);
		Stream_.Push(Gold);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("PassedIslandCount", PassedIslandCount);
		Value_.Push("Gold", Gold);
	}
	public void Set(SRankingUserIslandCore Obj_)
	{
		base.Set(Obj_);
		PassedIslandCount = Obj_.PassedIslandCount;
		Gold = Obj_.Gold;
	}
	public override string StdName()
	{
		return "wstring,int32,wstring,int32,int32";
	}
	public override string MemberName()
	{
		return "Nick,CharCode,CountryCode,PassedIslandCount,Gold";
	}
}
public class SRankingUserIsland : SRankingUserIslandCore
{
	public TUID UID = 0;
	public Int32 Point = 0;
	public SRankingUserIsland()
	{
	}
	public SRankingUserIsland(SRankingUserIsland Obj_) : base(Obj_)
	{
		UID = Obj_.UID;
		Point = Obj_.Point;
	}
	public SRankingUserIsland(SRankingUserIslandCore Super_, TUID UID_, Int32 Point_) : base(Super_)
	{
		UID = UID_;
		Point = Point_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref UID);
		Stream_.Pop(ref Point);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("UID", ref UID);
		Value_.Pop("Point", ref Point);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(UID);
		Stream_.Push(Point);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("UID", UID);
		Value_.Push("Point", Point);
	}
	public void Set(SRankingUserIsland Obj_)
	{
		base.Set(Obj_);
		UID = Obj_.UID;
		Point = Obj_.Point;
	}
	public override string StdName()
	{
		return "wstring,int32,wstring,int32,int32,int64,int32";
	}
	public override string MemberName()
	{
		return "Nick,CharCode,CountryCode,PassedIslandCount,Gold,UID,Point";
	}
}
public class SRanking : SProto
{
	public TRankingUsers RankingUsers = new TRankingUsers();
	public TRankingUserSingles RankingUserSingles = new TRankingUserSingles();
	public TRankingUserIslands RankingUserIslands = new TRankingUserIslands();
	public SRanking()
	{
	}
	public SRanking(SRanking Obj_)
	{
		RankingUsers = Obj_.RankingUsers;
		RankingUserSingles = Obj_.RankingUserSingles;
		RankingUserIslands = Obj_.RankingUserIslands;
	}
	public SRanking(TRankingUsers RankingUsers_, TRankingUserSingles RankingUserSingles_, TRankingUserIslands RankingUserIslands_)
	{
		RankingUsers = RankingUsers_;
		RankingUserSingles = RankingUserSingles_;
		RankingUserIslands = RankingUserIslands_;
	}
	public override void Push(CStream Stream_)
	{
		{
			RankingUsers.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SRankingUser Value = new SRankingUser();
				Stream_.Pop(Value);
				RankingUsers.Add(Value);
			}
		}
		{
			RankingUserSingles.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SRankingUserSingle Value = new SRankingUserSingle();
				Stream_.Pop(Value);
				RankingUserSingles.Add(Value);
			}
		}
		{
			RankingUserIslands.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SRankingUserIsland Value = new SRankingUserIsland();
				Stream_.Pop(Value);
				RankingUserIslands.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("RankingUsers", ref RankingUsers);
		Value_.Pop("RankingUserSingles", ref RankingUserSingles);
		Value_.Pop("RankingUserIslands", ref RankingUserIslands);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)RankingUsers.Count);
		foreach(var it in RankingUsers)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)RankingUserSingles.Count);
		foreach(var it in RankingUserSingles)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)RankingUserIslands.Count);
		foreach(var it in RankingUserIslands)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("RankingUsers", RankingUsers);
		Value_.Push("RankingUserSingles", RankingUserSingles);
		Value_.Push("RankingUserIslands", RankingUserIslands);
	}
	public void Set(SRanking Obj_)
	{
		RankingUsers = Obj_.RankingUsers;
		RankingUserSingles = Obj_.RankingUserSingles;
		RankingUserIslands = Obj_.RankingUserIslands;
	}
	public override string StdName()
	{
		return "{wstring,int32,wstring,int64,int32},{wstring,int32,wstring,int32,int32,int32,int64,int32},{wstring,int32,wstring,int32,int32,int64,int32}";
	}
	public override string MemberName()
	{
		return "RankingUsers,RankingUserSingles,RankingUserIslands";
	}
}
public class SRankingUserPointMin : SProto
{
	public Int32 UserPointMin = 0;
	public Int32 UserPointMinSingle = 0;
	public Int32 UserPointMinIsland = 0;
	public SRankingUserPointMin()
	{
	}
	public SRankingUserPointMin(SRankingUserPointMin Obj_)
	{
		UserPointMin = Obj_.UserPointMin;
		UserPointMinSingle = Obj_.UserPointMinSingle;
		UserPointMinIsland = Obj_.UserPointMinIsland;
	}
	public SRankingUserPointMin(Int32 UserPointMin_, Int32 UserPointMinSingle_, Int32 UserPointMinIsland_)
	{
		UserPointMin = UserPointMin_;
		UserPointMinSingle = UserPointMinSingle_;
		UserPointMinIsland = UserPointMinIsland_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref UserPointMin);
		Stream_.Pop(ref UserPointMinSingle);
		Stream_.Pop(ref UserPointMinIsland);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("UserPointMin", ref UserPointMin);
		Value_.Pop("UserPointMinSingle", ref UserPointMinSingle);
		Value_.Pop("UserPointMinIsland", ref UserPointMinIsland);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(UserPointMin);
		Stream_.Push(UserPointMinSingle);
		Stream_.Push(UserPointMinIsland);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("UserPointMin", UserPointMin);
		Value_.Push("UserPointMinSingle", UserPointMinSingle);
		Value_.Push("UserPointMinIsland", UserPointMinIsland);
	}
	public void Set(SRankingUserPointMin Obj_)
	{
		UserPointMin = Obj_.UserPointMin;
		UserPointMinSingle = Obj_.UserPointMinSingle;
		UserPointMinIsland = Obj_.UserPointMinIsland;
	}
	public override string StdName()
	{
		return "int32,int32,int32";
	}
	public override string MemberName()
	{
		return "UserPointMin,UserPointMinSingle,UserPointMinIsland";
	}
}
public enum EProtoRankingNetCs
{
	RequestRanking,
	Max,
}
public enum EProtoRankingNetSc
{
	RequestRanking,
	Max,
}
public class SGachaNetCs : SProto
{
	public Int32 GachaIndex = 0;
	public SGachaNetCs()
	{
	}
	public SGachaNetCs(SGachaNetCs Obj_)
	{
		GachaIndex = Obj_.GachaIndex;
	}
	public SGachaNetCs(Int32 GachaIndex_)
	{
		GachaIndex = GachaIndex_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref GachaIndex);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("GachaIndex", ref GachaIndex);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(GachaIndex);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("GachaIndex", GachaIndex);
	}
	public void Set(SGachaNetCs Obj_)
	{
		GachaIndex = Obj_.GachaIndex;
	}
	public override string StdName()
	{
		return "int32";
	}
	public override string MemberName()
	{
		return "GachaIndex";
	}
}
public class SGachaNetSc : SProto
{
	public TResource[] Cost = new TResource[5];
	public Int32 Index = 0;
	public Int32 CharCode = 0;
	public SGachaNetSc()
	{
		for (int iCost = 0; iCost < Cost.Length; ++iCost)
			Cost[iCost] = 0;
	}
	public SGachaNetSc(SGachaNetSc Obj_)
	{
		Cost = Obj_.Cost;
		Index = Obj_.Index;
		CharCode = Obj_.CharCode;
	}
	public SGachaNetSc(TResource[] Cost_, Int32 Index_, Int32 CharCode_)
	{
		Cost = Cost_;
		Index = Index_;
		CharCode = CharCode_;
	}
	public override void Push(CStream Stream_)
	{
		for (int iCost = 0; iCost < Cost.Length; ++iCost)
			Stream_.Pop(ref Cost[iCost]);
		Stream_.Pop(ref Index);
		Stream_.Pop(ref CharCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Cost", ref Cost);
		Value_.Pop("Index", ref Index);
		Value_.Pop("CharCode", ref CharCode);
	}
	public override void Pop(CStream Stream_)
	{
		foreach(var itCost in Cost)
		{
			Stream_.Push(itCost);
		}
		Stream_.Push(Index);
		Stream_.Push(CharCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Cost", Cost);
		Value_.Push("Index", Index);
		Value_.Push("CharCode", CharCode);
	}
	public void Set(SGachaNetSc Obj_)
	{
		Cost = Obj_.Cost;
		Index = Obj_.Index;
		CharCode = Obj_.CharCode;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "Cost,Index,CharCode";
	}
}
public class SGachaFailedNetSc : SGachaNetSc
{
	public TResource[] Refund = new TResource[5];
	public SGachaFailedNetSc()
	{
		for (int iRefund = 0; iRefund < Refund.Length; ++iRefund)
			Refund[iRefund] = 0;
	}
	public SGachaFailedNetSc(SGachaFailedNetSc Obj_) : base(Obj_)
	{
		Refund = Obj_.Refund;
	}
	public SGachaFailedNetSc(SGachaNetSc Super_, TResource[] Refund_) : base(Super_)
	{
		Refund = Refund_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		for (int iRefund = 0; iRefund < Refund.Length; ++iRefund)
			Stream_.Pop(ref Refund[iRefund]);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("Refund", ref Refund);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		foreach(var itRefund in Refund)
		{
			Stream_.Push(itRefund);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("Refund", Refund);
	}
	public void Set(SGachaFailedNetSc Obj_)
	{
		base.Set(Obj_);
		Refund = Obj_.Refund;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "Cost,Index,CharCode,Refund";
	}
}
public class SRankRewardNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SQuestSlotIndexCode : SProto
{
	public TQuestSlotIndex SlotIndex = 0;
	public Int32 Code = 0;
	public SQuestSlotIndexCode()
	{
	}
	public SQuestSlotIndexCode(SQuestSlotIndexCode Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		Code = Obj_.Code;
	}
	public SQuestSlotIndexCode(TQuestSlotIndex SlotIndex_, Int32 Code_)
	{
		SlotIndex = SlotIndex_;
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref SlotIndex);
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("SlotIndex", ref SlotIndex);
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(SlotIndex);
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("SlotIndex", SlotIndex);
		Value_.Push("Code", Code);
	}
	public void Set(SQuestSlotIndexCode Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "uint8,int32";
	}
	public override string MemberName()
	{
		return "SlotIndex,Code";
	}
}
public class SQuestGotNetSc : SProto
{
	public TQuestSlotIndexCodes Quests = new TQuestSlotIndexCodes();
	public SQuestGotNetSc()
	{
	}
	public SQuestGotNetSc(SQuestGotNetSc Obj_)
	{
		Quests = Obj_.Quests;
	}
	public SQuestGotNetSc(TQuestSlotIndexCodes Quests_)
	{
		Quests = Quests_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Quests.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SQuestSlotIndexCode Value = new SQuestSlotIndexCode();
				Stream_.Pop(Value);
				Quests.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Quests", ref Quests);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Quests.Count);
		foreach(var it in Quests)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Quests", Quests);
	}
	public void Set(SQuestGotNetSc Obj_)
	{
		Quests = Obj_.Quests;
	}
	public override string StdName()
	{
		return "{uint8,int32}";
	}
	public override string MemberName()
	{
		return "Quests";
	}
}
public class SQuestDoneNetSc : SProto
{
	public TQuestSlotIndex SlotIndex = 0;
	public Int32 Count = 0;
	public SQuestDoneNetSc()
	{
	}
	public SQuestDoneNetSc(SQuestDoneNetSc Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		Count = Obj_.Count;
	}
	public SQuestDoneNetSc(TQuestSlotIndex SlotIndex_, Int32 Count_)
	{
		SlotIndex = SlotIndex_;
		Count = Count_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref SlotIndex);
		Stream_.Pop(ref Count);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("SlotIndex", ref SlotIndex);
		Value_.Pop("Count", ref Count);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(SlotIndex);
		Stream_.Push(Count);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("SlotIndex", SlotIndex);
		Value_.Push("Count", Count);
	}
	public void Set(SQuestDoneNetSc Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		Count = Obj_.Count;
	}
	public override string StdName()
	{
		return "uint8,int32";
	}
	public override string MemberName()
	{
		return "SlotIndex,Count";
	}
}
public class SQuestRewardNetCs : SProto
{
	public TQuestSlotIndex SlotIndex = 0;
	public SQuestRewardNetCs()
	{
	}
	public SQuestRewardNetCs(SQuestRewardNetCs Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
	}
	public SQuestRewardNetCs(TQuestSlotIndex SlotIndex_)
	{
		SlotIndex = SlotIndex_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref SlotIndex);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("SlotIndex", ref SlotIndex);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(SlotIndex);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("SlotIndex", SlotIndex);
	}
	public void Set(SQuestRewardNetCs Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
	}
	public override string StdName()
	{
		return "uint8";
	}
	public override string MemberName()
	{
		return "SlotIndex";
	}
}
public class SQuestRewardNetSc : SProto
{
	public TQuestSlotIndex SlotIndex = 0;
	public TimePoint CoolEndTime = new TimePoint();
	public Int32 DailyCompleteCount = 0;
	public TimePoint DailyCompleteRefreshTime = new TimePoint();
	public SQuestRewardNetSc()
	{
	}
	public SQuestRewardNetSc(SQuestRewardNetSc Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		CoolEndTime = Obj_.CoolEndTime;
		DailyCompleteCount = Obj_.DailyCompleteCount;
		DailyCompleteRefreshTime = Obj_.DailyCompleteRefreshTime;
	}
	public SQuestRewardNetSc(TQuestSlotIndex SlotIndex_, TimePoint CoolEndTime_, Int32 DailyCompleteCount_, TimePoint DailyCompleteRefreshTime_)
	{
		SlotIndex = SlotIndex_;
		CoolEndTime = CoolEndTime_;
		DailyCompleteCount = DailyCompleteCount_;
		DailyCompleteRefreshTime = DailyCompleteRefreshTime_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref SlotIndex);
		Stream_.Pop(ref CoolEndTime);
		Stream_.Pop(ref DailyCompleteCount);
		Stream_.Pop(ref DailyCompleteRefreshTime);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("SlotIndex", ref SlotIndex);
		Value_.Pop("CoolEndTime", ref CoolEndTime);
		Value_.Pop("DailyCompleteCount", ref DailyCompleteCount);
		Value_.Pop("DailyCompleteRefreshTime", ref DailyCompleteRefreshTime);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(SlotIndex);
		Stream_.Push(CoolEndTime);
		Stream_.Push(DailyCompleteCount);
		Stream_.Push(DailyCompleteRefreshTime);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("SlotIndex", SlotIndex);
		Value_.Push("CoolEndTime", CoolEndTime);
		Value_.Push("DailyCompleteCount", DailyCompleteCount);
		Value_.Push("DailyCompleteRefreshTime", DailyCompleteRefreshTime);
	}
	public void Set(SQuestRewardNetSc Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		CoolEndTime = Obj_.CoolEndTime;
		DailyCompleteCount = Obj_.DailyCompleteCount;
		DailyCompleteRefreshTime = Obj_.DailyCompleteRefreshTime;
	}
	public override string StdName()
	{
		return "uint8,time_point,int32,time_point";
	}
	public override string MemberName()
	{
		return "SlotIndex,CoolEndTime,DailyCompleteCount,DailyCompleteRefreshTime";
	}
}
public class SQuestNextNetCs : SProto
{
	public TQuestSlotIndex SlotIndex = 0;
	public SQuestNextNetCs()
	{
	}
	public SQuestNextNetCs(SQuestNextNetCs Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
	}
	public SQuestNextNetCs(TQuestSlotIndex SlotIndex_)
	{
		SlotIndex = SlotIndex_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref SlotIndex);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("SlotIndex", ref SlotIndex);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(SlotIndex);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("SlotIndex", SlotIndex);
	}
	public void Set(SQuestNextNetCs Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
	}
	public override string StdName()
	{
		return "uint8";
	}
	public override string MemberName()
	{
		return "SlotIndex";
	}
}
public class SQuestNextNetSc : SProto
{
	public TQuestSlotIndex SlotIndex = 0;
	public Int32 NewCode = 0;
	public SQuestNextNetSc()
	{
	}
	public SQuestNextNetSc(SQuestNextNetSc Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		NewCode = Obj_.NewCode;
	}
	public SQuestNextNetSc(TQuestSlotIndex SlotIndex_, Int32 NewCode_)
	{
		SlotIndex = SlotIndex_;
		NewCode = NewCode_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref SlotIndex);
		Stream_.Pop(ref NewCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("SlotIndex", ref SlotIndex);
		Value_.Pop("NewCode", ref NewCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(SlotIndex);
		Stream_.Push(NewCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("SlotIndex", SlotIndex);
		Value_.Push("NewCode", NewCode);
	}
	public void Set(SQuestNextNetSc Obj_)
	{
		SlotIndex = Obj_.SlotIndex;
		NewCode = Obj_.NewCode;
	}
	public override string StdName()
	{
		return "uint8,int32";
	}
	public override string MemberName()
	{
		return "SlotIndex,NewCode";
	}
}
public class SQuestDailyCompleteRewardNetCs : SProto
{
	public Boolean WatchAd = false;
	public SQuestDailyCompleteRewardNetCs()
	{
	}
	public SQuestDailyCompleteRewardNetCs(SQuestDailyCompleteRewardNetCs Obj_)
	{
		WatchAd = Obj_.WatchAd;
	}
	public SQuestDailyCompleteRewardNetCs(Boolean WatchAd_)
	{
		WatchAd = WatchAd_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref WatchAd);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("WatchAd", ref WatchAd);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(WatchAd);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("WatchAd", WatchAd);
	}
	public void Set(SQuestDailyCompleteRewardNetCs Obj_)
	{
		WatchAd = Obj_.WatchAd;
	}
	public override string StdName()
	{
		return "bool";
	}
	public override string MemberName()
	{
		return "WatchAd";
	}
}
public class SQuestDailyCompleteRewardNetSc : SProto
{
	public Boolean WatchAd = false;
	public TimePoint RefreshTime = new TimePoint();
	public SQuestDailyCompleteRewardNetSc()
	{
	}
	public SQuestDailyCompleteRewardNetSc(SQuestDailyCompleteRewardNetSc Obj_)
	{
		WatchAd = Obj_.WatchAd;
		RefreshTime = Obj_.RefreshTime;
	}
	public SQuestDailyCompleteRewardNetSc(Boolean WatchAd_, TimePoint RefreshTime_)
	{
		WatchAd = WatchAd_;
		RefreshTime = RefreshTime_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref WatchAd);
		Stream_.Pop(ref RefreshTime);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("WatchAd", ref WatchAd);
		Value_.Pop("RefreshTime", ref RefreshTime);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(WatchAd);
		Stream_.Push(RefreshTime);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("WatchAd", WatchAd);
		Value_.Push("RefreshTime", RefreshTime);
	}
	public void Set(SQuestDailyCompleteRewardNetSc Obj_)
	{
		WatchAd = Obj_.WatchAd;
		RefreshTime = Obj_.RefreshTime;
	}
	public override string StdName()
	{
		return "bool,time_point";
	}
	public override string MemberName()
	{
		return "WatchAd,RefreshTime";
	}
}
public class SChangeNickNetCs : SProto
{
	public String Nick = "";
	public SChangeNickNetCs()
	{
	}
	public SChangeNickNetCs(SChangeNickNetCs Obj_)
	{
		Nick = Obj_.Nick;
	}
	public SChangeNickNetCs(String Nick_)
	{
		Nick = Nick_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Nick);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Nick", ref Nick);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Nick);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Nick", Nick);
	}
	public void Set(SChangeNickNetCs Obj_)
	{
		Nick = Obj_.Nick;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "Nick";
	}
}
public class SChangeNickNetSc : SProto
{
	public String Nick = "";
	public SChangeNickNetSc()
	{
	}
	public SChangeNickNetSc(SChangeNickNetSc Obj_)
	{
		Nick = Obj_.Nick;
	}
	public SChangeNickNetSc(String Nick_)
	{
		Nick = Nick_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Nick);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Nick", ref Nick);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Nick);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Nick", Nick);
	}
	public void Set(SChangeNickNetSc Obj_)
	{
		Nick = Obj_.Nick;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "Nick";
	}
}
public class SChangeNickFailNetSc : SProto
{
	public String ForbiddenWord = "";
	public SChangeNickFailNetSc()
	{
	}
	public SChangeNickFailNetSc(SChangeNickFailNetSc Obj_)
	{
		ForbiddenWord = Obj_.ForbiddenWord;
	}
	public SChangeNickFailNetSc(String ForbiddenWord_)
	{
		ForbiddenWord = ForbiddenWord_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref ForbiddenWord);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("ForbiddenWord", ref ForbiddenWord);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(ForbiddenWord);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("ForbiddenWord", ForbiddenWord);
	}
	public void Set(SChangeNickFailNetSc Obj_)
	{
		ForbiddenWord = Obj_.ForbiddenWord;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "ForbiddenWord";
	}
}
public class SNickPoint : SProto
{
	public String Nick = "";
	public Int32 Point = 0;
	public SNickPoint()
	{
	}
	public SNickPoint(SNickPoint Obj_)
	{
		Nick = Obj_.Nick;
		Point = Obj_.Point;
	}
	public SNickPoint(String Nick_, Int32 Point_)
	{
		Nick = Nick_;
		Point = Point_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Nick);
		Stream_.Pop(ref Point);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Nick", ref Nick);
		Value_.Pop("Point", ref Point);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Nick);
		Stream_.Push(Point);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Nick", Nick);
		Value_.Push("Point", Point);
	}
	public void Set(SNickPoint Obj_)
	{
		Nick = Obj_.Nick;
		Point = Obj_.Point;
	}
	public override string StdName()
	{
		return "wstring,int32";
	}
	public override string MemberName()
	{
		return "Nick,Point";
	}
}
public class SCheckIDNetSc : SProto
{
	public List<SNickPoint> Datas = new List<SNickPoint>();
	public SCheckIDNetSc()
	{
	}
	public SCheckIDNetSc(SCheckIDNetSc Obj_)
	{
		Datas = Obj_.Datas;
	}
	public SCheckIDNetSc(List<SNickPoint> Datas_)
	{
		Datas = Datas_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Datas.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SNickPoint Value = new SNickPoint();
				Stream_.Pop(Value);
				Datas.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Datas", ref Datas);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Datas.Count);
		foreach(var it in Datas)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Datas", Datas);
	}
	public void Set(SCheckIDNetSc Obj_)
	{
		Datas = Obj_.Datas;
	}
	public override string StdName()
	{
		return "{wstring,int32}";
	}
	public override string MemberName()
	{
		return "Datas";
	}
}
public class SCouponUseNetCs : SProto
{
	public String Key = "";
	public SCouponUseNetCs()
	{
	}
	public SCouponUseNetCs(SCouponUseNetCs Obj_)
	{
		Key = Obj_.Key;
	}
	public SCouponUseNetCs(String Key_)
	{
		Key = Key_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Key);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Key", ref Key);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Key);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Key", Key);
	}
	public void Set(SCouponUseNetCs Obj_)
	{
		Key = Obj_.Key;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "Key";
	}
}
public class SRewardDB : SProto
{
	public TUID UID = 0;
	public TResource[] ResourcesLeft = new TResource[5];
	public List<Int32> CharsAdded = new List<Int32>();
	public List<Int32> CostumeAdded = new List<Int32>();
	public SRewardDB()
	{
		for (int iResourcesLeft = 0; iResourcesLeft < ResourcesLeft.Length; ++iResourcesLeft)
			ResourcesLeft[iResourcesLeft] = 0;
	}
	public SRewardDB(SRewardDB Obj_)
	{
		UID = Obj_.UID;
		ResourcesLeft = Obj_.ResourcesLeft;
		CharsAdded = Obj_.CharsAdded;
		CostumeAdded = Obj_.CostumeAdded;
	}
	public SRewardDB(TUID UID_, TResource[] ResourcesLeft_, List<Int32> CharsAdded_, List<Int32> CostumeAdded_)
	{
		UID = UID_;
		ResourcesLeft = ResourcesLeft_;
		CharsAdded = CharsAdded_;
		CostumeAdded = CostumeAdded_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref UID);
		for (int iResourcesLeft = 0; iResourcesLeft < ResourcesLeft.Length; ++iResourcesLeft)
			Stream_.Pop(ref ResourcesLeft[iResourcesLeft]);
		{
			CharsAdded.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				CharsAdded.Add(Value);
			}
		}
		{
			CostumeAdded.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				Int32 Value = 0;
				Stream_.Pop(ref Value);
				CostumeAdded.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("UID", ref UID);
		Value_.Pop("ResourcesLeft", ref ResourcesLeft);
		Value_.Pop("CharsAdded", ref CharsAdded);
		Value_.Pop("CostumeAdded", ref CostumeAdded);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(UID);
		foreach(var itResourcesLeft in ResourcesLeft)
		{
			Stream_.Push(itResourcesLeft);
		}
		Stream_.Push((Int32)CharsAdded.Count);
		foreach(var it in CharsAdded)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)CostumeAdded.Count);
		foreach(var it in CostumeAdded)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("UID", UID);
		Value_.Push("ResourcesLeft", ResourcesLeft);
		Value_.Push("CharsAdded", CharsAdded);
		Value_.Push("CostumeAdded", CostumeAdded);
	}
	public void Set(SRewardDB Obj_)
	{
		UID = Obj_.UID;
		ResourcesLeft = Obj_.ResourcesLeft;
		CharsAdded = Obj_.CharsAdded;
		CostumeAdded = Obj_.CostumeAdded;
	}
	public override string StdName()
	{
		return "int64,int32,int32,int32,int32,int32,{int32},{int32}";
	}
	public override string MemberName()
	{
		return "UID,ResourcesLeft,CharsAdded,CostumeAdded";
	}
}
public class SCouponUseNetSc : SRewardDB
{
	public SCouponUseNetSc()
	{
	}
	public SCouponUseNetSc(SCouponUseNetSc Obj_) : base(Obj_)
	{
	}
	public SCouponUseNetSc(SRewardDB Super_) : base(Super_)
	{
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
	}
	public void Set(SCouponUseNetSc Obj_)
	{
		base.Set(Obj_);
	}
	public override string StdName()
	{
		return "int64,int32,int32,int32,int32,int32,{int32},{int32}";
	}
	public override string MemberName()
	{
		return "UID,ResourcesLeft,CharsAdded,CostumeAdded";
	}
}
public class SCouponUseFailNetSc : SProto
{
	public ERet Ret = 0;
	public SCouponUseFailNetSc()
	{
	}
	public SCouponUseFailNetSc(SCouponUseFailNetSc Obj_)
	{
		Ret = Obj_.Ret;
	}
	public SCouponUseFailNetSc(ERet Ret_)
	{
		Ret = Ret_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			Ret = (ERet)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Int32 Var = 0;
			Value_.Pop("Ret", ref Var);
			Ret = (ERet)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Ret);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Ret", (Int32)Ret);
	}
	public void Set(SCouponUseFailNetSc Obj_)
	{
		Ret = Obj_.Ret;
	}
	public override string StdName()
	{
		return "ERet";
	}
	public override string MemberName()
	{
		return "Ret";
	}
}
public class SCostumeEquipNetCs : SProto
{
	public Int32 CostumeCode = 0;
	public Int32 CharCode = 0;
	public SCostumeEquipNetCs()
	{
	}
	public SCostumeEquipNetCs(SCostumeEquipNetCs Obj_)
	{
		CostumeCode = Obj_.CostumeCode;
		CharCode = Obj_.CharCode;
	}
	public SCostumeEquipNetCs(Int32 CostumeCode_, Int32 CharCode_)
	{
		CostumeCode = CostumeCode_;
		CharCode = CharCode_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref CostumeCode);
		Stream_.Pop(ref CharCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("CostumeCode", ref CostumeCode);
		Value_.Pop("CharCode", ref CharCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(CostumeCode);
		Stream_.Push(CharCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CostumeCode", CostumeCode);
		Value_.Push("CharCode", CharCode);
	}
	public void Set(SCostumeEquipNetCs Obj_)
	{
		CostumeCode = Obj_.CostumeCode;
		CharCode = Obj_.CharCode;
	}
	public override string StdName()
	{
		return "int32,int32";
	}
	public override string MemberName()
	{
		return "CostumeCode,CharCode";
	}
}
public class SCostumeUnequipNetCs : SProto
{
	public Int32 CharCode = 0;
	public ECostumePart Part = 0;
	public SCostumeUnequipNetCs()
	{
	}
	public SCostumeUnequipNetCs(SCostumeUnequipNetCs Obj_)
	{
		CharCode = Obj_.CharCode;
		Part = Obj_.Part;
	}
	public SCostumeUnequipNetCs(Int32 CharCode_, ECostumePart Part_)
	{
		CharCode = CharCode_;
		Part = Part_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref CharCode);
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Part = (ECostumePart)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("CharCode", ref CharCode);
		{
			Byte Var = 0;
			Value_.Pop("Part", ref Var);
			Part = (ECostumePart)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(CharCode);
		Stream_.Push((Byte)Part);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CharCode", CharCode);
		Value_.Push("Part", (Byte)Part);
	}
	public void Set(SCostumeUnequipNetCs Obj_)
	{
		CharCode = Obj_.CharCode;
		Part = Obj_.Part;
	}
	public override string StdName()
	{
		return "int32,ECostumePart";
	}
	public override string MemberName()
	{
		return "CharCode,Part";
	}
}
public class STutorialRewardNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SRankingRewardInfoNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SRankingRewardInfoNetSc : SProto
{
	public Int64 Counter = 0;
	public Int32 Ranking = 0;
	public Int32 RankingSingle = 0;
	public Int32 RankingIsland = 0;
	public SRankingRewardInfoNetSc()
	{
	}
	public SRankingRewardInfoNetSc(SRankingRewardInfoNetSc Obj_)
	{
		Counter = Obj_.Counter;
		Ranking = Obj_.Ranking;
		RankingSingle = Obj_.RankingSingle;
		RankingIsland = Obj_.RankingIsland;
	}
	public SRankingRewardInfoNetSc(Int64 Counter_, Int32 Ranking_, Int32 RankingSingle_, Int32 RankingIsland_)
	{
		Counter = Counter_;
		Ranking = Ranking_;
		RankingSingle = RankingSingle_;
		RankingIsland = RankingIsland_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Counter);
		Stream_.Pop(ref Ranking);
		Stream_.Pop(ref RankingSingle);
		Stream_.Pop(ref RankingIsland);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Counter", ref Counter);
		Value_.Pop("Ranking", ref Ranking);
		Value_.Pop("RankingSingle", ref RankingSingle);
		Value_.Pop("RankingIsland", ref RankingIsland);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Counter);
		Stream_.Push(Ranking);
		Stream_.Push(RankingSingle);
		Stream_.Push(RankingIsland);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Counter", Counter);
		Value_.Push("Ranking", Ranking);
		Value_.Push("RankingSingle", RankingSingle);
		Value_.Push("RankingIsland", RankingIsland);
	}
	public void Set(SRankingRewardInfoNetSc Obj_)
	{
		Counter = Obj_.Counter;
		Ranking = Obj_.Ranking;
		RankingSingle = Obj_.RankingSingle;
		RankingIsland = Obj_.RankingIsland;
	}
	public override string StdName()
	{
		return "int64,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "Counter,Ranking,RankingSingle,RankingIsland";
	}
}
public class SRankingRewardNetCs : SProto
{
	public override void Push(CStream Stream_)
	{
	}
	public override void Push(JsonDataObject Value_)
	{
	}
	public override void Pop(CStream Stream_)
	{
	}
	public override void Pop(JsonDataObject Value_)
	{
	}
	public override string StdName()
	{
		return "";
	}
	public override string MemberName()
	{
		return "";
	}
}
public class SRankingRewardNetSc : SProto
{
	public Int64 Counter = 0;
	public Int32 RewardCode = 0;
	public Int32 RewardCodeSingle = 0;
	public Int32 RewardCodeIsland = 0;
	public SRankingRewardNetSc()
	{
	}
	public SRankingRewardNetSc(SRankingRewardNetSc Obj_)
	{
		Counter = Obj_.Counter;
		RewardCode = Obj_.RewardCode;
		RewardCodeSingle = Obj_.RewardCodeSingle;
		RewardCodeIsland = Obj_.RewardCodeIsland;
	}
	public SRankingRewardNetSc(Int64 Counter_, Int32 RewardCode_, Int32 RewardCodeSingle_, Int32 RewardCodeIsland_)
	{
		Counter = Counter_;
		RewardCode = RewardCode_;
		RewardCodeSingle = RewardCodeSingle_;
		RewardCodeIsland = RewardCodeIsland_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Counter);
		Stream_.Pop(ref RewardCode);
		Stream_.Pop(ref RewardCodeSingle);
		Stream_.Pop(ref RewardCodeIsland);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Counter", ref Counter);
		Value_.Pop("RewardCode", ref RewardCode);
		Value_.Pop("RewardCodeSingle", ref RewardCodeSingle);
		Value_.Pop("RewardCodeIsland", ref RewardCodeIsland);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Counter);
		Stream_.Push(RewardCode);
		Stream_.Push(RewardCodeSingle);
		Stream_.Push(RewardCodeIsland);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Counter", Counter);
		Value_.Push("RewardCode", RewardCode);
		Value_.Push("RewardCodeSingle", RewardCodeSingle);
		Value_.Push("RewardCodeIsland", RewardCodeIsland);
	}
	public void Set(SRankingRewardNetSc Obj_)
	{
		Counter = Obj_.Counter;
		RewardCode = Obj_.RewardCode;
		RewardCodeSingle = Obj_.RewardCodeSingle;
		RewardCodeIsland = Obj_.RewardCodeIsland;
	}
	public override string StdName()
	{
		return "int64,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "Counter,RewardCode,RewardCodeSingle,RewardCodeIsland";
	}
}
public class SRankingRewardFailNetSc : SProto
{
	public ERet Ret = 0;
	public SRankingRewardFailNetSc()
	{
	}
	public SRankingRewardFailNetSc(SRankingRewardFailNetSc Obj_)
	{
		Ret = Obj_.Ret;
	}
	public SRankingRewardFailNetSc(ERet Ret_)
	{
		Ret = Ret_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			Ret = (ERet)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Int32 Var = 0;
			Value_.Pop("Ret", ref Var);
			Ret = (ERet)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Ret);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Ret", (Int32)Ret);
	}
	public void Set(SRankingRewardFailNetSc Obj_)
	{
		Ret = Obj_.Ret;
	}
	public override string StdName()
	{
		return "ERet";
	}
	public override string MemberName()
	{
		return "Ret";
	}
}
public partial class global
{
	public const Single c_2_ScreenWidth = c_ScreenWidth*2.0f;
	public const Single c_AccExt = c_Factor;
	public const Single c_AirResistance = 1.0f;
	public const SByte c_BalloonCountForPump = 1;
	public const SByte c_BalloonCountForRegen = 2;
	public const Single c_BalloonHeight = 0.27f;
	public const Single c_BalloonLocalScale = 0.5f;
	public const Single c_BalloonOffsetY = 0.5f;
	public const Single c_BalloonWidth = 0.2f;
	public const Int64 c_BattleStartDelayMilliSec = 2000;
	public const Int64 c_ChainKillDelayTickCount = 50000000;
	public const Single c_ContactOffset = 0.0001f;
	public const Single c_DefaultVel = c_Factor*0.22f;
	public const Single c_DeltaTime = 1.0f/c_FPS;
	public const Single c_DieUpVel = 0.7f;
	public const Int32 c_FPS = 60;
	public const Single c_Factor = c_ScreenWidth*0.75f;
	public const Single c_FlapOnAcc = c_Factor*0.25f;
	public const Single c_GameHeight = 3.5f;
	public const Single c_GhostSpeed = 3.0f;
	public const Single c_Gravity = -c_FlapOnAcc;
	public const Single c_GravityDeadRatio = 2.0f;
	public const Single c_GravityParachuteRatio = 0.5f;
	public const Single c_GroundResistance = 0.1f;
	public const Int32 c_MaxPlayer = 6;
	public const Single c_MaxVelDeadY = c_DefaultVel*2.0f;
	public const Single c_MaxVelParachuteX = c_DefaultVel*1.2f;
	public const Single c_MaxVelParachuteY = c_DefaultVel*0.5f;
	public const Int64 c_NetworkTickBuffer = c_NetworkTickSync+500000;
	public const Int64 c_NetworkTickSync = 500000;
	public const Int32 c_NickLengthMax = 8;
	public const Int32 c_NickLengthMin = 2;
	public const Single c_OnePumpDuration = 0.4f;
	public const Single c_ParachuteAccX = c_FlapOnAcc;
	public const Single c_ParachuteHeight = 0.25f;
	public const Single c_ParachuteLocalScale = 0.5f;
	public const Single c_ParachuteOffsetY = 0.37f;
	public const Single c_ParachuteWidth = 0.45f;
	public const Single c_PlayerHeight = 0.150337f;
	public const Single c_PlayerOffsetY = c_PlayerHeight*0.5f;
	public const Single c_PlayerWidth = 0.1258713f;
	public const SByte c_PumpCountForBalloon = 6;
	public const Int32 c_QuestCnt_Max = 5;
	public const Int64 c_RegenDelayTickCount = 20000000;
	public const Single c_ScreenCenterX = 3.448f;
	public const Single c_ScreenCenterY = c_ScreenHeight*0.5f;
	public const Single c_ScreenHeight = 3.5f;
	public const Single c_ScreenHeight_2 = c_ScreenHeight*0.5f;
	public const Single c_ScreenWidth = 3.448f;
	public const Single c_ScreenWidth_2 = c_ScreenWidth*0.5f;
	public const Int64 c_UnitTick = 10000000/c_FPS;
	public const TVer c_Ver_Main = 24;
}
