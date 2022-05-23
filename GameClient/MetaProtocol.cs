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
using TPoses = System.Collections.Generic.List<rso.physics.SPoint>;
using System;
using System.Collections.Generic;
using rso.core;


using rso.physics;
public enum ECashItemType
{
	ResourcesPack,
	Max,
	Null,
}
public enum EGoodsItemType
{
	AvatarColor,
	Max,
	Null,
}
public enum ERank : Byte
{
	Unranked,
	Bronze,
	Silver,
	Gold,
	Diamond,
	Champion,
	Max,
}
public class SServerConfigMeta : SProto
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
public class SStructure : SEngineRect
{
	public SPoint LocalPosition = new SPoint();
	public SStructure()
	{
	}
	public SStructure(SStructure Obj_) : base(Obj_)
	{
		LocalPosition = Obj_.LocalPosition;
	}
	public SStructure(SEngineRect Super_, SPoint LocalPosition_) : base(Super_)
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
	public void Set(SStructure Obj_)
	{
		base.Set(Obj_);
		LocalPosition.Set(Obj_.LocalPosition);
	}
	public override string StdName()
	{
		return "float,float,float,float,float,float,float,float";
	}
	public override string MemberName()
	{
		return "X,Y,X,Y,X,Y,X,Y";
	}
}
public class SStructureMove : SProto
{
	public List<SEngineRect> Colliders = new List<SEngineRect>();
	public SPoint BeginPos = new SPoint();
	public SPoint EndPos = new SPoint();
	public Single Velocity = 0.0f;
	public Single Delay = 0.0f;
	public SStructureMove()
	{
	}
	public SStructureMove(SStructureMove Obj_)
	{
		Colliders = Obj_.Colliders;
		BeginPos = Obj_.BeginPos;
		EndPos = Obj_.EndPos;
		Velocity = Obj_.Velocity;
		Delay = Obj_.Delay;
	}
	public SStructureMove(List<SEngineRect> Colliders_, SPoint BeginPos_, SPoint EndPos_, Single Velocity_, Single Delay_)
	{
		Colliders = Colliders_;
		BeginPos = BeginPos_;
		EndPos = EndPos_;
		Velocity = Velocity_;
		Delay = Delay_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Colliders.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SEngineRect Value = new SEngineRect();
				Stream_.Pop(Value);
				Colliders.Add(Value);
			}
		}
		Stream_.Pop(BeginPos);
		Stream_.Pop(EndPos);
		Stream_.Pop(ref Velocity);
		Stream_.Pop(ref Delay);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Colliders", ref Colliders);
		Value_.Pop("BeginPos", BeginPos);
		Value_.Pop("EndPos", EndPos);
		Value_.Pop("Velocity", ref Velocity);
		Value_.Pop("Delay", ref Delay);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Colliders.Count);
		foreach(var it in Colliders)
		{
			Stream_.Push(it);
		}
		Stream_.Push(BeginPos);
		Stream_.Push(EndPos);
		Stream_.Push(Velocity);
		Stream_.Push(Delay);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Colliders", Colliders);
		Value_.Push("BeginPos", BeginPos);
		Value_.Push("EndPos", EndPos);
		Value_.Push("Velocity", Velocity);
		Value_.Push("Delay", Delay);
	}
	public void Set(SStructureMove Obj_)
	{
		Colliders = Obj_.Colliders;
		BeginPos.Set(Obj_.BeginPos);
		EndPos.Set(Obj_.EndPos);
		Velocity = Obj_.Velocity;
		Delay = Obj_.Delay;
	}
	public override string StdName()
	{
		return "{float,float,float,float,float,float},float,float,float,float,float,float";
	}
	public override string MemberName()
	{
		return "Colliders,X,Y,X,Y,Velocity,Delay";
	}
}
public class SConfigMeta : SProto
{
	public Int32 BattleDurationSec = 0;
	public Int32 BattleOneOnOneDurationSec = 0;
	public Int32 GhostDelaySec = 0;
	public Int32 InvulnerableDurationSec = 0;
	public Int32 BalloonHitPoint = 0;
	public Int32 ParachuteHitPoint = 0;
	public Int32 FirstBalloonHitPoint = 0;
	public Int32 QuestCoolMinutes = 0;
	public TResource QuestNextCostGold = 0;
	public Int32 ChangeNickFreeCount = 0;
	public TResource ChangeNickCostDia = 0;
	public TResource TutorialRewardDia = 0;
	public SConfigMeta()
	{
	}
	public SConfigMeta(SConfigMeta Obj_)
	{
		BattleDurationSec = Obj_.BattleDurationSec;
		BattleOneOnOneDurationSec = Obj_.BattleOneOnOneDurationSec;
		GhostDelaySec = Obj_.GhostDelaySec;
		InvulnerableDurationSec = Obj_.InvulnerableDurationSec;
		BalloonHitPoint = Obj_.BalloonHitPoint;
		ParachuteHitPoint = Obj_.ParachuteHitPoint;
		FirstBalloonHitPoint = Obj_.FirstBalloonHitPoint;
		QuestCoolMinutes = Obj_.QuestCoolMinutes;
		QuestNextCostGold = Obj_.QuestNextCostGold;
		ChangeNickFreeCount = Obj_.ChangeNickFreeCount;
		ChangeNickCostDia = Obj_.ChangeNickCostDia;
		TutorialRewardDia = Obj_.TutorialRewardDia;
	}
	public SConfigMeta(Int32 BattleDurationSec_, Int32 BattleOneOnOneDurationSec_, Int32 GhostDelaySec_, Int32 InvulnerableDurationSec_, Int32 BalloonHitPoint_, Int32 ParachuteHitPoint_, Int32 FirstBalloonHitPoint_, Int32 QuestCoolMinutes_, TResource QuestNextCostGold_, Int32 ChangeNickFreeCount_, TResource ChangeNickCostDia_, TResource TutorialRewardDia_)
	{
		BattleDurationSec = BattleDurationSec_;
		BattleOneOnOneDurationSec = BattleOneOnOneDurationSec_;
		GhostDelaySec = GhostDelaySec_;
		InvulnerableDurationSec = InvulnerableDurationSec_;
		BalloonHitPoint = BalloonHitPoint_;
		ParachuteHitPoint = ParachuteHitPoint_;
		FirstBalloonHitPoint = FirstBalloonHitPoint_;
		QuestCoolMinutes = QuestCoolMinutes_;
		QuestNextCostGold = QuestNextCostGold_;
		ChangeNickFreeCount = ChangeNickFreeCount_;
		ChangeNickCostDia = ChangeNickCostDia_;
		TutorialRewardDia = TutorialRewardDia_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref BattleDurationSec);
		Stream_.Pop(ref BattleOneOnOneDurationSec);
		Stream_.Pop(ref GhostDelaySec);
		Stream_.Pop(ref InvulnerableDurationSec);
		Stream_.Pop(ref BalloonHitPoint);
		Stream_.Pop(ref ParachuteHitPoint);
		Stream_.Pop(ref FirstBalloonHitPoint);
		Stream_.Pop(ref QuestCoolMinutes);
		Stream_.Pop(ref QuestNextCostGold);
		Stream_.Pop(ref ChangeNickFreeCount);
		Stream_.Pop(ref ChangeNickCostDia);
		Stream_.Pop(ref TutorialRewardDia);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("BattleDurationSec", ref BattleDurationSec);
		Value_.Pop("BattleOneOnOneDurationSec", ref BattleOneOnOneDurationSec);
		Value_.Pop("GhostDelaySec", ref GhostDelaySec);
		Value_.Pop("InvulnerableDurationSec", ref InvulnerableDurationSec);
		Value_.Pop("BalloonHitPoint", ref BalloonHitPoint);
		Value_.Pop("ParachuteHitPoint", ref ParachuteHitPoint);
		Value_.Pop("FirstBalloonHitPoint", ref FirstBalloonHitPoint);
		Value_.Pop("QuestCoolMinutes", ref QuestCoolMinutes);
		Value_.Pop("QuestNextCostGold", ref QuestNextCostGold);
		Value_.Pop("ChangeNickFreeCount", ref ChangeNickFreeCount);
		Value_.Pop("ChangeNickCostDia", ref ChangeNickCostDia);
		Value_.Pop("TutorialRewardDia", ref TutorialRewardDia);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(BattleDurationSec);
		Stream_.Push(BattleOneOnOneDurationSec);
		Stream_.Push(GhostDelaySec);
		Stream_.Push(InvulnerableDurationSec);
		Stream_.Push(BalloonHitPoint);
		Stream_.Push(ParachuteHitPoint);
		Stream_.Push(FirstBalloonHitPoint);
		Stream_.Push(QuestCoolMinutes);
		Stream_.Push(QuestNextCostGold);
		Stream_.Push(ChangeNickFreeCount);
		Stream_.Push(ChangeNickCostDia);
		Stream_.Push(TutorialRewardDia);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("BattleDurationSec", BattleDurationSec);
		Value_.Push("BattleOneOnOneDurationSec", BattleOneOnOneDurationSec);
		Value_.Push("GhostDelaySec", GhostDelaySec);
		Value_.Push("InvulnerableDurationSec", InvulnerableDurationSec);
		Value_.Push("BalloonHitPoint", BalloonHitPoint);
		Value_.Push("ParachuteHitPoint", ParachuteHitPoint);
		Value_.Push("FirstBalloonHitPoint", FirstBalloonHitPoint);
		Value_.Push("QuestCoolMinutes", QuestCoolMinutes);
		Value_.Push("QuestNextCostGold", QuestNextCostGold);
		Value_.Push("ChangeNickFreeCount", ChangeNickFreeCount);
		Value_.Push("ChangeNickCostDia", ChangeNickCostDia);
		Value_.Push("TutorialRewardDia", TutorialRewardDia);
	}
	public void Set(SConfigMeta Obj_)
	{
		BattleDurationSec = Obj_.BattleDurationSec;
		BattleOneOnOneDurationSec = Obj_.BattleOneOnOneDurationSec;
		GhostDelaySec = Obj_.GhostDelaySec;
		InvulnerableDurationSec = Obj_.InvulnerableDurationSec;
		BalloonHitPoint = Obj_.BalloonHitPoint;
		ParachuteHitPoint = Obj_.ParachuteHitPoint;
		FirstBalloonHitPoint = Obj_.FirstBalloonHitPoint;
		QuestCoolMinutes = Obj_.QuestCoolMinutes;
		QuestNextCostGold = Obj_.QuestNextCostGold;
		ChangeNickFreeCount = Obj_.ChangeNickFreeCount;
		ChangeNickCostDia = Obj_.ChangeNickCostDia;
		TutorialRewardDia = Obj_.TutorialRewardDia;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "BattleDurationSec,BattleOneOnOneDurationSec,GhostDelaySec,InvulnerableDurationSec,BalloonHitPoint,ParachuteHitPoint,FirstBalloonHitPoint,QuestCoolMinutes,QuestNextCostGold,ChangeNickFreeCount,ChangeNickCostDia,TutorialRewardDia";
	}
}
public class SForbiddenWordMeta : SProto
{
	public String Word = "";
	public SForbiddenWordMeta()
	{
	}
	public SForbiddenWordMeta(SForbiddenWordMeta Obj_)
	{
		Word = Obj_.Word;
	}
	public SForbiddenWordMeta(String Word_)
	{
		Word = Word_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Word);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Word", ref Word);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Word);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Word", Word);
	}
	public void Set(SForbiddenWordMeta Obj_)
	{
		Word = Obj_.Word;
	}
	public override string StdName()
	{
		return "wstring";
	}
	public override string MemberName()
	{
		return "Word";
	}
}
public class SShopConfigServerMeta : SProto
{
	public Int32 CostumeBundleCount = 0;
	public Int32 CostumeDurationMinute = 0;
	public Int32 DailyRewardDurationMinute = 0;
	public Int32 DailyRewardFreeCount = 0;
	public Int32 DailyRewardAdCount = 0;
	public SShopConfigServerMeta()
	{
	}
	public SShopConfigServerMeta(SShopConfigServerMeta Obj_)
	{
		CostumeBundleCount = Obj_.CostumeBundleCount;
		CostumeDurationMinute = Obj_.CostumeDurationMinute;
		DailyRewardDurationMinute = Obj_.DailyRewardDurationMinute;
		DailyRewardFreeCount = Obj_.DailyRewardFreeCount;
		DailyRewardAdCount = Obj_.DailyRewardAdCount;
	}
	public SShopConfigServerMeta(Int32 CostumeBundleCount_, Int32 CostumeDurationMinute_, Int32 DailyRewardDurationMinute_, Int32 DailyRewardFreeCount_, Int32 DailyRewardAdCount_)
	{
		CostumeBundleCount = CostumeBundleCount_;
		CostumeDurationMinute = CostumeDurationMinute_;
		DailyRewardDurationMinute = DailyRewardDurationMinute_;
		DailyRewardFreeCount = DailyRewardFreeCount_;
		DailyRewardAdCount = DailyRewardAdCount_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref CostumeBundleCount);
		Stream_.Pop(ref CostumeDurationMinute);
		Stream_.Pop(ref DailyRewardDurationMinute);
		Stream_.Pop(ref DailyRewardFreeCount);
		Stream_.Pop(ref DailyRewardAdCount);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("CostumeBundleCount", ref CostumeBundleCount);
		Value_.Pop("CostumeDurationMinute", ref CostumeDurationMinute);
		Value_.Pop("DailyRewardDurationMinute", ref DailyRewardDurationMinute);
		Value_.Pop("DailyRewardFreeCount", ref DailyRewardFreeCount);
		Value_.Pop("DailyRewardAdCount", ref DailyRewardAdCount);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(CostumeBundleCount);
		Stream_.Push(CostumeDurationMinute);
		Stream_.Push(DailyRewardDurationMinute);
		Stream_.Push(DailyRewardFreeCount);
		Stream_.Push(DailyRewardAdCount);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CostumeBundleCount", CostumeBundleCount);
		Value_.Push("CostumeDurationMinute", CostumeDurationMinute);
		Value_.Push("DailyRewardDurationMinute", DailyRewardDurationMinute);
		Value_.Push("DailyRewardFreeCount", DailyRewardFreeCount);
		Value_.Push("DailyRewardAdCount", DailyRewardAdCount);
	}
	public void Set(SShopConfigServerMeta Obj_)
	{
		CostumeBundleCount = Obj_.CostumeBundleCount;
		CostumeDurationMinute = Obj_.CostumeDurationMinute;
		DailyRewardDurationMinute = Obj_.DailyRewardDurationMinute;
		DailyRewardFreeCount = Obj_.DailyRewardFreeCount;
		DailyRewardAdCount = Obj_.DailyRewardAdCount;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "CostumeBundleCount,CostumeDurationMinute,DailyRewardDurationMinute,DailyRewardFreeCount,DailyRewardAdCount";
	}
}
public class SShopServerMeta : SProto
{
	public Int32 Code = 0;
	public EResource CostType = 0;
	public TResource CostValue = 0;
	public Int32 RewardCode = 0;
	public SShopServerMeta()
	{
	}
	public SShopServerMeta(SShopServerMeta Obj_)
	{
		Code = Obj_.Code;
		CostType = Obj_.CostType;
		CostValue = Obj_.CostValue;
		RewardCode = Obj_.RewardCode;
	}
	public SShopServerMeta(Int32 Code_, EResource CostType_, TResource CostValue_, Int32 RewardCode_)
	{
		Code = Code_;
		CostType = CostType_;
		CostValue = CostValue_;
		RewardCode = RewardCode_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			CostType = (EResource)Var;
		}
		Stream_.Pop(ref CostValue);
		Stream_.Pop(ref RewardCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
		{
			Int32 Var = 0;
			Value_.Pop("CostType", ref Var);
			CostType = (EResource)Var;
		}
		Value_.Pop("CostValue", ref CostValue);
		Value_.Pop("RewardCode", ref RewardCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
		Stream_.Push((Int32)CostType);
		Stream_.Push(CostValue);
		Stream_.Push(RewardCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
		Value_.Push("CostType", (Int32)CostType);
		Value_.Push("CostValue", CostValue);
		Value_.Push("RewardCode", RewardCode);
	}
	public void Set(SShopServerMeta Obj_)
	{
		Code = Obj_.Code;
		CostType = Obj_.CostType;
		CostValue = Obj_.CostValue;
		RewardCode = Obj_.RewardCode;
	}
	public override string StdName()
	{
		return "int32,EResource,int32,int32";
	}
	public override string MemberName()
	{
		return "Code,CostType,CostValue,RewardCode";
	}
}
public class SShopPackageServerMeta : SProto
{
	public Int32 Code = 0;
	public EResource CostType = 0;
	public TResource CostValue = 0;
	public Int32 RewardCode = 0;
	public String BeginTime = "";
	public String EndTime = "";
	public Int32 PeriodMinutesOn = 0;
	public Int32 PeriodMinutesOff = 0;
	public SShopPackageServerMeta()
	{
	}
	public SShopPackageServerMeta(SShopPackageServerMeta Obj_)
	{
		Code = Obj_.Code;
		CostType = Obj_.CostType;
		CostValue = Obj_.CostValue;
		RewardCode = Obj_.RewardCode;
		BeginTime = Obj_.BeginTime;
		EndTime = Obj_.EndTime;
		PeriodMinutesOn = Obj_.PeriodMinutesOn;
		PeriodMinutesOff = Obj_.PeriodMinutesOff;
	}
	public SShopPackageServerMeta(Int32 Code_, EResource CostType_, TResource CostValue_, Int32 RewardCode_, String BeginTime_, String EndTime_, Int32 PeriodMinutesOn_, Int32 PeriodMinutesOff_)
	{
		Code = Code_;
		CostType = CostType_;
		CostValue = CostValue_;
		RewardCode = RewardCode_;
		BeginTime = BeginTime_;
		EndTime = EndTime_;
		PeriodMinutesOn = PeriodMinutesOn_;
		PeriodMinutesOff = PeriodMinutesOff_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			CostType = (EResource)Var;
		}
		Stream_.Pop(ref CostValue);
		Stream_.Pop(ref RewardCode);
		Stream_.Pop(ref BeginTime);
		Stream_.Pop(ref EndTime);
		Stream_.Pop(ref PeriodMinutesOn);
		Stream_.Pop(ref PeriodMinutesOff);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
		{
			Int32 Var = 0;
			Value_.Pop("CostType", ref Var);
			CostType = (EResource)Var;
		}
		Value_.Pop("CostValue", ref CostValue);
		Value_.Pop("RewardCode", ref RewardCode);
		Value_.Pop("BeginTime", ref BeginTime);
		Value_.Pop("EndTime", ref EndTime);
		Value_.Pop("PeriodMinutesOn", ref PeriodMinutesOn);
		Value_.Pop("PeriodMinutesOff", ref PeriodMinutesOff);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
		Stream_.Push((Int32)CostType);
		Stream_.Push(CostValue);
		Stream_.Push(RewardCode);
		Stream_.Push(BeginTime);
		Stream_.Push(EndTime);
		Stream_.Push(PeriodMinutesOn);
		Stream_.Push(PeriodMinutesOff);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
		Value_.Push("CostType", (Int32)CostType);
		Value_.Push("CostValue", CostValue);
		Value_.Push("RewardCode", RewardCode);
		Value_.Push("BeginTime", BeginTime);
		Value_.Push("EndTime", EndTime);
		Value_.Push("PeriodMinutesOn", PeriodMinutesOn);
		Value_.Push("PeriodMinutesOff", PeriodMinutesOff);
	}
	public void Set(SShopPackageServerMeta Obj_)
	{
		Code = Obj_.Code;
		CostType = Obj_.CostType;
		CostValue = Obj_.CostValue;
		RewardCode = Obj_.RewardCode;
		BeginTime = Obj_.BeginTime;
		EndTime = Obj_.EndTime;
		PeriodMinutesOn = Obj_.PeriodMinutesOn;
		PeriodMinutesOff = Obj_.PeriodMinutesOff;
	}
	public override string StdName()
	{
		return "int32,EResource,int32,int32,wstring,wstring,int32,int32";
	}
	public override string MemberName()
	{
		return "Code,CostType,CostValue,RewardCode,BeginTime,EndTime,PeriodMinutesOn,PeriodMinutesOff";
	}
}
public class SShopDailyRewardServerMeta : SProto
{
	public Double Probability = 0.0;
	public EResource RewardType = 0;
	public TResource RewardValue = 0;
	public SShopDailyRewardServerMeta()
	{
	}
	public SShopDailyRewardServerMeta(SShopDailyRewardServerMeta Obj_)
	{
		Probability = Obj_.Probability;
		RewardType = Obj_.RewardType;
		RewardValue = Obj_.RewardValue;
	}
	public SShopDailyRewardServerMeta(Double Probability_, EResource RewardType_, TResource RewardValue_)
	{
		Probability = Probability_;
		RewardType = RewardType_;
		RewardValue = RewardValue_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Probability);
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			RewardType = (EResource)Var;
		}
		Stream_.Pop(ref RewardValue);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Probability", ref Probability);
		{
			Int32 Var = 0;
			Value_.Pop("RewardType", ref Var);
			RewardType = (EResource)Var;
		}
		Value_.Pop("RewardValue", ref RewardValue);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Probability);
		Stream_.Push((Int32)RewardType);
		Stream_.Push(RewardValue);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Probability", Probability);
		Value_.Push("RewardType", (Int32)RewardType);
		Value_.Push("RewardValue", RewardValue);
	}
	public void Set(SShopDailyRewardServerMeta Obj_)
	{
		Probability = Obj_.Probability;
		RewardType = Obj_.RewardType;
		RewardValue = Obj_.RewardValue;
	}
	public override string StdName()
	{
		return "double,EResource,int32";
	}
	public override string MemberName()
	{
		return "Probability,RewardType,RewardValue";
	}
}
public class SShopCashServerMeta : SProto
{
	public String Pid = "";
	public TResource DiaCount = 0;
	public SShopCashServerMeta()
	{
	}
	public SShopCashServerMeta(SShopCashServerMeta Obj_)
	{
		Pid = Obj_.Pid;
		DiaCount = Obj_.DiaCount;
	}
	public SShopCashServerMeta(String Pid_, TResource DiaCount_)
	{
		Pid = Pid_;
		DiaCount = DiaCount_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Pid);
		Stream_.Pop(ref DiaCount);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Pid", ref Pid);
		Value_.Pop("DiaCount", ref DiaCount);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Pid);
		Stream_.Push(DiaCount);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Pid", Pid);
		Value_.Push("DiaCount", DiaCount);
	}
	public void Set(SShopCashServerMeta Obj_)
	{
		Pid = Obj_.Pid;
		DiaCount = Obj_.DiaCount;
	}
	public override string StdName()
	{
		return "wstring,int32";
	}
	public override string MemberName()
	{
		return "Pid,DiaCount";
	}
}
public class SCharacterMeta : SProto
{
	public Int32 Code = 0;
	public EGrade Grade = 0;
	public TResource CPPrice = 0;
	public TResource CPRefund = 0;
	public Single MaxVelUp = 0.0f;
	public Single MaxVelDown = 0.0f;
	public Single MaxVelXGround = 0.0f;
	public Single MaxVelXAir = 0.0f;
	public Single FlapDeltaVelX = 0.0f;
	public Single FlapDeltaVelUp = 0.0f;
	public Single RunAcc = 0.0f;
	public Single StaminaMax = 0.0f;
	public Single StaminaPerTick = 0.0f;
	public Int32 StaminaRegenDelay = 0;
	public Single PumpSpeed = 0.0f;
	public SCharacterMeta()
	{
	}
	public SCharacterMeta(SCharacterMeta Obj_)
	{
		Code = Obj_.Code;
		Grade = Obj_.Grade;
		CPPrice = Obj_.CPPrice;
		CPRefund = Obj_.CPRefund;
		MaxVelUp = Obj_.MaxVelUp;
		MaxVelDown = Obj_.MaxVelDown;
		MaxVelXGround = Obj_.MaxVelXGround;
		MaxVelXAir = Obj_.MaxVelXAir;
		FlapDeltaVelX = Obj_.FlapDeltaVelX;
		FlapDeltaVelUp = Obj_.FlapDeltaVelUp;
		RunAcc = Obj_.RunAcc;
		StaminaMax = Obj_.StaminaMax;
		StaminaPerTick = Obj_.StaminaPerTick;
		StaminaRegenDelay = Obj_.StaminaRegenDelay;
		PumpSpeed = Obj_.PumpSpeed;
	}
	public SCharacterMeta(Int32 Code_, EGrade Grade_, TResource CPPrice_, TResource CPRefund_, Single MaxVelUp_, Single MaxVelDown_, Single MaxVelXGround_, Single MaxVelXAir_, Single FlapDeltaVelX_, Single FlapDeltaVelUp_, Single RunAcc_, Single StaminaMax_, Single StaminaPerTick_, Int32 StaminaRegenDelay_, Single PumpSpeed_)
	{
		Code = Code_;
		Grade = Grade_;
		CPPrice = CPPrice_;
		CPRefund = CPRefund_;
		MaxVelUp = MaxVelUp_;
		MaxVelDown = MaxVelDown_;
		MaxVelXGround = MaxVelXGround_;
		MaxVelXAir = MaxVelXAir_;
		FlapDeltaVelX = FlapDeltaVelX_;
		FlapDeltaVelUp = FlapDeltaVelUp_;
		RunAcc = RunAcc_;
		StaminaMax = StaminaMax_;
		StaminaPerTick = StaminaPerTick_;
		StaminaRegenDelay = StaminaRegenDelay_;
		PumpSpeed = PumpSpeed_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Grade = (EGrade)Var;
		}
		Stream_.Pop(ref CPPrice);
		Stream_.Pop(ref CPRefund);
		Stream_.Pop(ref MaxVelUp);
		Stream_.Pop(ref MaxVelDown);
		Stream_.Pop(ref MaxVelXGround);
		Stream_.Pop(ref MaxVelXAir);
		Stream_.Pop(ref FlapDeltaVelX);
		Stream_.Pop(ref FlapDeltaVelUp);
		Stream_.Pop(ref RunAcc);
		Stream_.Pop(ref StaminaMax);
		Stream_.Pop(ref StaminaPerTick);
		Stream_.Pop(ref StaminaRegenDelay);
		Stream_.Pop(ref PumpSpeed);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
		{
			Byte Var = 0;
			Value_.Pop("Grade", ref Var);
			Grade = (EGrade)Var;
		}
		Value_.Pop("CPPrice", ref CPPrice);
		Value_.Pop("CPRefund", ref CPRefund);
		Value_.Pop("MaxVelUp", ref MaxVelUp);
		Value_.Pop("MaxVelDown", ref MaxVelDown);
		Value_.Pop("MaxVelXGround", ref MaxVelXGround);
		Value_.Pop("MaxVelXAir", ref MaxVelXAir);
		Value_.Pop("FlapDeltaVelX", ref FlapDeltaVelX);
		Value_.Pop("FlapDeltaVelUp", ref FlapDeltaVelUp);
		Value_.Pop("RunAcc", ref RunAcc);
		Value_.Pop("StaminaMax", ref StaminaMax);
		Value_.Pop("StaminaPerTick", ref StaminaPerTick);
		Value_.Pop("StaminaRegenDelay", ref StaminaRegenDelay);
		Value_.Pop("PumpSpeed", ref PumpSpeed);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
		Stream_.Push((Byte)Grade);
		Stream_.Push(CPPrice);
		Stream_.Push(CPRefund);
		Stream_.Push(MaxVelUp);
		Stream_.Push(MaxVelDown);
		Stream_.Push(MaxVelXGround);
		Stream_.Push(MaxVelXAir);
		Stream_.Push(FlapDeltaVelX);
		Stream_.Push(FlapDeltaVelUp);
		Stream_.Push(RunAcc);
		Stream_.Push(StaminaMax);
		Stream_.Push(StaminaPerTick);
		Stream_.Push(StaminaRegenDelay);
		Stream_.Push(PumpSpeed);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
		Value_.Push("Grade", (Byte)Grade);
		Value_.Push("CPPrice", CPPrice);
		Value_.Push("CPRefund", CPRefund);
		Value_.Push("MaxVelUp", MaxVelUp);
		Value_.Push("MaxVelDown", MaxVelDown);
		Value_.Push("MaxVelXGround", MaxVelXGround);
		Value_.Push("MaxVelXAir", MaxVelXAir);
		Value_.Push("FlapDeltaVelX", FlapDeltaVelX);
		Value_.Push("FlapDeltaVelUp", FlapDeltaVelUp);
		Value_.Push("RunAcc", RunAcc);
		Value_.Push("StaminaMax", StaminaMax);
		Value_.Push("StaminaPerTick", StaminaPerTick);
		Value_.Push("StaminaRegenDelay", StaminaRegenDelay);
		Value_.Push("PumpSpeed", PumpSpeed);
	}
	public void Set(SCharacterMeta Obj_)
	{
		Code = Obj_.Code;
		Grade = Obj_.Grade;
		CPPrice = Obj_.CPPrice;
		CPRefund = Obj_.CPRefund;
		MaxVelUp = Obj_.MaxVelUp;
		MaxVelDown = Obj_.MaxVelDown;
		MaxVelXGround = Obj_.MaxVelXGround;
		MaxVelXAir = Obj_.MaxVelXAir;
		FlapDeltaVelX = Obj_.FlapDeltaVelX;
		FlapDeltaVelUp = Obj_.FlapDeltaVelUp;
		RunAcc = Obj_.RunAcc;
		StaminaMax = Obj_.StaminaMax;
		StaminaPerTick = Obj_.StaminaPerTick;
		StaminaRegenDelay = Obj_.StaminaRegenDelay;
		PumpSpeed = Obj_.PumpSpeed;
	}
	public override string StdName()
	{
		return "int32,EGrade,int32,int32,float,float,float,float,float,float,float,float,float,int32,float";
	}
	public override string MemberName()
	{
		return "Code,Grade,CPPrice,CPRefund,MaxVelUp,MaxVelDown,MaxVelXGround,MaxVelXAir,FlapDeltaVelX,FlapDeltaVelUp,RunAcc,StaminaMax,StaminaPerTick,StaminaRegenDelay,PumpSpeed";
	}
}
public class SCharacterServerMeta : SCharacterMeta
{
	public Boolean Default = false;
	public SCharacterServerMeta()
	{
	}
	public SCharacterServerMeta(SCharacterServerMeta Obj_) : base(Obj_)
	{
		Default = Obj_.Default;
	}
	public SCharacterServerMeta(SCharacterMeta Super_, Boolean Default_) : base(Super_)
	{
		Default = Default_;
	}
	public override void Push(CStream Stream_)
	{
		base.Push(Stream_);
		Stream_.Pop(ref Default);
	}
	public override void Push(JsonDataObject Value_)
	{
		base.Push(Value_);
		Value_.Pop("Default", ref Default);
	}
	public override void Pop(CStream Stream_)
	{
		base.Pop(Stream_);
		Stream_.Push(Default);
	}
	public override void Pop(JsonDataObject Value_)
	{
		base.Pop(Value_);
		Value_.Push("Default", Default);
	}
	public void Set(SCharacterServerMeta Obj_)
	{
		base.Set(Obj_);
		Default = Obj_.Default;
	}
	public override string StdName()
	{
		return "int32,EGrade,int32,int32,float,float,float,float,float,float,float,float,float,int32,float,bool";
	}
	public override string MemberName()
	{
		return "Code,Grade,CPPrice,CPRefund,MaxVelUp,MaxVelDown,MaxVelXGround,MaxVelXAir,FlapDeltaVelX,FlapDeltaVelUp,RunAcc,StaminaMax,StaminaPerTick,StaminaRegenDelay,PumpSpeed,Default";
	}
}
public class SCharacterGradeMeta : SProto
{
	public EGrade Grade = 0;
	public SCharacterGradeMeta()
	{
	}
	public SCharacterGradeMeta(SCharacterGradeMeta Obj_)
	{
		Grade = Obj_.Grade;
	}
	public SCharacterGradeMeta(EGrade Grade_)
	{
		Grade = Grade_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Grade = (EGrade)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Byte Var = 0;
			Value_.Pop("Grade", ref Var);
			Grade = (EGrade)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Byte)Grade);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Grade", (Byte)Grade);
	}
	public void Set(SCharacterGradeMeta Obj_)
	{
		Grade = Obj_.Grade;
	}
	public override string StdName()
	{
		return "EGrade";
	}
	public override string MemberName()
	{
		return "Grade";
	}
}
public class SPlayerPos : SProto
{
	public TPoses Poses = new TPoses();
	public SPlayerPos()
	{
	}
	public SPlayerPos(SPlayerPos Obj_)
	{
		Poses = Obj_.Poses;
	}
	public SPlayerPos(TPoses Poses_)
	{
		Poses = Poses_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Poses.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SPoint Value = new SPoint();
				Stream_.Pop(Value);
				Poses.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Poses", ref Poses);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)Poses.Count);
		foreach(var it in Poses)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Poses", Poses);
	}
	public void Set(SPlayerPos Obj_)
	{
		Poses = Obj_.Poses;
	}
	public override string StdName()
	{
		return "{float,float}";
	}
	public override string MemberName()
	{
		return "Poses";
	}
}
public class SMapMulti : SProto
{
	public String PrefabName = "";
	public Dictionary<TTeamCnt,SPlayerPos> PlayerPoses = new Dictionary<TTeamCnt,SPlayerPos>();
	public SPoint PropPosition = new SPoint();
	public List<SStructure> Structures = new List<SStructure>();
	public List<SStructureMove> StructureMoves = new List<SStructureMove>();
	public SMapMulti()
	{
	}
	public SMapMulti(SMapMulti Obj_)
	{
		PrefabName = Obj_.PrefabName;
		PlayerPoses = Obj_.PlayerPoses;
		PropPosition = Obj_.PropPosition;
		Structures = Obj_.Structures;
		StructureMoves = Obj_.StructureMoves;
	}
	public SMapMulti(String PrefabName_, Dictionary<TTeamCnt,SPlayerPos> PlayerPoses_, SPoint PropPosition_, List<SStructure> Structures_, List<SStructureMove> StructureMoves_)
	{
		PrefabName = PrefabName_;
		PlayerPoses = PlayerPoses_;
		PropPosition = PropPosition_;
		Structures = Structures_;
		StructureMoves = StructureMoves_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref PrefabName);
		{
			PlayerPoses.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				TTeamCnt Key = 0;
				Stream_.Pop(ref Key);
				SPlayerPos Value = new SPlayerPos();
				Stream_.Pop(Value);
				PlayerPoses.Add(Key, Value);
			}
		}
		Stream_.Pop(PropPosition);
		{
			Structures.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SStructure Value = new SStructure();
				Stream_.Pop(Value);
				Structures.Add(Value);
			}
		}
		{
			StructureMoves.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SStructureMove Value = new SStructureMove();
				Stream_.Pop(Value);
				StructureMoves.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("PrefabName", ref PrefabName);
		Value_.Pop("PlayerPoses", ref PlayerPoses);
		Value_.Pop("PropPosition", PropPosition);
		Value_.Pop("Structures", ref Structures);
		Value_.Pop("StructureMoves", ref StructureMoves);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(PrefabName);
		Stream_.Push((Int32)PlayerPoses.Count);
		foreach(var it in PlayerPoses)
		{
			Stream_.Push(it.Key);
			Stream_.Push(it.Value);
		}
		Stream_.Push(PropPosition);
		Stream_.Push((Int32)Structures.Count);
		foreach(var it in Structures)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)StructureMoves.Count);
		foreach(var it in StructureMoves)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("PrefabName", PrefabName);
		Value_.Push("PlayerPoses", PlayerPoses);
		Value_.Push("PropPosition", PropPosition);
		Value_.Push("Structures", Structures);
		Value_.Push("StructureMoves", StructureMoves);
	}
	public void Set(SMapMulti Obj_)
	{
		PrefabName = Obj_.PrefabName;
		PlayerPoses = Obj_.PlayerPoses;
		PropPosition.Set(Obj_.PropPosition);
		Structures = Obj_.Structures;
		StructureMoves = Obj_.StructureMoves;
	}
	public override string StdName()
	{
		return "wstring,{int8,{float,float}},float,float,{float,float,float,float,float,float,float,float},{{float,float,float,float,float,float},float,float,float,float,float,float}";
	}
	public override string MemberName()
	{
		return "PrefabName,PlayerPoses,X,Y,Structures,StructureMoves";
	}
}
public class SMapMeta : SProto
{
	public List<SMapMulti> MapOneOnOnes = new List<SMapMulti>();
	public List<SMapMulti> MapMulties = new List<SMapMulti>();
	public SMapMeta()
	{
	}
	public SMapMeta(SMapMeta Obj_)
	{
		MapOneOnOnes = Obj_.MapOneOnOnes;
		MapMulties = Obj_.MapMulties;
	}
	public SMapMeta(List<SMapMulti> MapOneOnOnes_, List<SMapMulti> MapMulties_)
	{
		MapOneOnOnes = MapOneOnOnes_;
		MapMulties = MapMulties_;
	}
	public override void Push(CStream Stream_)
	{
		{
			MapOneOnOnes.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SMapMulti Value = new SMapMulti();
				Stream_.Pop(Value);
				MapOneOnOnes.Add(Value);
			}
		}
		{
			MapMulties.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SMapMulti Value = new SMapMulti();
				Stream_.Pop(Value);
				MapMulties.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("MapOneOnOnes", ref MapOneOnOnes);
		Value_.Pop("MapMulties", ref MapMulties);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)MapOneOnOnes.Count);
		foreach(var it in MapOneOnOnes)
		{
			Stream_.Push(it);
		}
		Stream_.Push((Int32)MapMulties.Count);
		foreach(var it in MapMulties)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("MapOneOnOnes", MapOneOnOnes);
		Value_.Push("MapMulties", MapMulties);
	}
	public void Set(SMapMeta Obj_)
	{
		MapOneOnOnes = Obj_.MapOneOnOnes;
		MapMulties = Obj_.MapMulties;
	}
	public override string StdName()
	{
		return "{wstring,{int8,{float,float}},float,float,{float,float,float,float,float,float,float,float},{{float,float,float,float,float,float},float,float,float,float,float,float}},{wstring,{int8,{float,float}},float,float,{float,float,float,float,float,float,float,float},{{float,float,float,float,float,float},float,float,float,float,float,float}}";
	}
	public override string MemberName()
	{
		return "MapOneOnOnes,MapMulties";
	}
}
public class SSingleMeta : SProto
{
	public Int32 PlayCountMax = 0;
	public TResource ChargeCostGold = 0;
	public Int32 ScoreFactorWave = 0;
	public Int32 ScoreFactorTime = 0;
	public Int32 ScoreFactorGold = 0;
	public Int32 RefreshDurationMinute = 0;
	public SSingleMeta()
	{
	}
	public SSingleMeta(SSingleMeta Obj_)
	{
		PlayCountMax = Obj_.PlayCountMax;
		ChargeCostGold = Obj_.ChargeCostGold;
		ScoreFactorWave = Obj_.ScoreFactorWave;
		ScoreFactorTime = Obj_.ScoreFactorTime;
		ScoreFactorGold = Obj_.ScoreFactorGold;
		RefreshDurationMinute = Obj_.RefreshDurationMinute;
	}
	public SSingleMeta(Int32 PlayCountMax_, TResource ChargeCostGold_, Int32 ScoreFactorWave_, Int32 ScoreFactorTime_, Int32 ScoreFactorGold_, Int32 RefreshDurationMinute_)
	{
		PlayCountMax = PlayCountMax_;
		ChargeCostGold = ChargeCostGold_;
		ScoreFactorWave = ScoreFactorWave_;
		ScoreFactorTime = ScoreFactorTime_;
		ScoreFactorGold = ScoreFactorGold_;
		RefreshDurationMinute = RefreshDurationMinute_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref PlayCountMax);
		Stream_.Pop(ref ChargeCostGold);
		Stream_.Pop(ref ScoreFactorWave);
		Stream_.Pop(ref ScoreFactorTime);
		Stream_.Pop(ref ScoreFactorGold);
		Stream_.Pop(ref RefreshDurationMinute);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("PlayCountMax", ref PlayCountMax);
		Value_.Pop("ChargeCostGold", ref ChargeCostGold);
		Value_.Pop("ScoreFactorWave", ref ScoreFactorWave);
		Value_.Pop("ScoreFactorTime", ref ScoreFactorTime);
		Value_.Pop("ScoreFactorGold", ref ScoreFactorGold);
		Value_.Pop("RefreshDurationMinute", ref RefreshDurationMinute);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(PlayCountMax);
		Stream_.Push(ChargeCostGold);
		Stream_.Push(ScoreFactorWave);
		Stream_.Push(ScoreFactorTime);
		Stream_.Push(ScoreFactorGold);
		Stream_.Push(RefreshDurationMinute);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("PlayCountMax", PlayCountMax);
		Value_.Push("ChargeCostGold", ChargeCostGold);
		Value_.Push("ScoreFactorWave", ScoreFactorWave);
		Value_.Push("ScoreFactorTime", ScoreFactorTime);
		Value_.Push("ScoreFactorGold", ScoreFactorGold);
		Value_.Push("RefreshDurationMinute", RefreshDurationMinute);
	}
	public void Set(SSingleMeta Obj_)
	{
		PlayCountMax = Obj_.PlayCountMax;
		ChargeCostGold = Obj_.ChargeCostGold;
		ScoreFactorWave = Obj_.ScoreFactorWave;
		ScoreFactorTime = Obj_.ScoreFactorTime;
		ScoreFactorGold = Obj_.ScoreFactorGold;
		RefreshDurationMinute = Obj_.RefreshDurationMinute;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "PlayCountMax,ChargeCostGold,ScoreFactorWave,ScoreFactorTime,ScoreFactorGold,RefreshDurationMinute";
	}
}
public class SIslandMeta : SProto
{
	public Int32 PlayCountMax = 0;
	public TResource ChargeCostGold = 0;
	public Int32 ScoreFactorIsland = 0;
	public Int32 ScoreFactorGold = 0;
	public Int32 RefreshDurationMinute = 0;
	public SIslandMeta()
	{
	}
	public SIslandMeta(SIslandMeta Obj_)
	{
		PlayCountMax = Obj_.PlayCountMax;
		ChargeCostGold = Obj_.ChargeCostGold;
		ScoreFactorIsland = Obj_.ScoreFactorIsland;
		ScoreFactorGold = Obj_.ScoreFactorGold;
		RefreshDurationMinute = Obj_.RefreshDurationMinute;
	}
	public SIslandMeta(Int32 PlayCountMax_, TResource ChargeCostGold_, Int32 ScoreFactorIsland_, Int32 ScoreFactorGold_, Int32 RefreshDurationMinute_)
	{
		PlayCountMax = PlayCountMax_;
		ChargeCostGold = ChargeCostGold_;
		ScoreFactorIsland = ScoreFactorIsland_;
		ScoreFactorGold = ScoreFactorGold_;
		RefreshDurationMinute = RefreshDurationMinute_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref PlayCountMax);
		Stream_.Pop(ref ChargeCostGold);
		Stream_.Pop(ref ScoreFactorIsland);
		Stream_.Pop(ref ScoreFactorGold);
		Stream_.Pop(ref RefreshDurationMinute);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("PlayCountMax", ref PlayCountMax);
		Value_.Pop("ChargeCostGold", ref ChargeCostGold);
		Value_.Pop("ScoreFactorIsland", ref ScoreFactorIsland);
		Value_.Pop("ScoreFactorGold", ref ScoreFactorGold);
		Value_.Pop("RefreshDurationMinute", ref RefreshDurationMinute);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(PlayCountMax);
		Stream_.Push(ChargeCostGold);
		Stream_.Push(ScoreFactorIsland);
		Stream_.Push(ScoreFactorGold);
		Stream_.Push(RefreshDurationMinute);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("PlayCountMax", PlayCountMax);
		Value_.Push("ChargeCostGold", ChargeCostGold);
		Value_.Push("ScoreFactorIsland", ScoreFactorIsland);
		Value_.Push("ScoreFactorGold", ScoreFactorGold);
		Value_.Push("RefreshDurationMinute", RefreshDurationMinute);
	}
	public void Set(SIslandMeta Obj_)
	{
		PlayCountMax = Obj_.PlayCountMax;
		ChargeCostGold = Obj_.ChargeCostGold;
		ScoreFactorIsland = Obj_.ScoreFactorIsland;
		ScoreFactorGold = Obj_.ScoreFactorGold;
		RefreshDurationMinute = Obj_.RefreshDurationMinute;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "PlayCountMax,ChargeCostGold,ScoreFactorIsland,ScoreFactorGold,RefreshDurationMinute";
	}
}
public class SGachaMeta : SProto
{
	public EResource CostResource = 0;
	public Int32 CostValue = 0;
	public Int32 RewardCode = 0;
	public SGachaMeta()
	{
	}
	public SGachaMeta(SGachaMeta Obj_)
	{
		CostResource = Obj_.CostResource;
		CostValue = Obj_.CostValue;
		RewardCode = Obj_.RewardCode;
	}
	public SGachaMeta(EResource CostResource_, Int32 CostValue_, Int32 RewardCode_)
	{
		CostResource = CostResource_;
		CostValue = CostValue_;
		RewardCode = RewardCode_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			CostResource = (EResource)Var;
		}
		Stream_.Pop(ref CostValue);
		Stream_.Pop(ref RewardCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Int32 Var = 0;
			Value_.Pop("CostResource", ref Var);
			CostResource = (EResource)Var;
		}
		Value_.Pop("CostValue", ref CostValue);
		Value_.Pop("RewardCode", ref RewardCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)CostResource);
		Stream_.Push(CostValue);
		Stream_.Push(RewardCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("CostResource", (Int32)CostResource);
		Value_.Push("CostValue", CostValue);
		Value_.Push("RewardCode", RewardCode);
	}
	public void Set(SGachaMeta Obj_)
	{
		CostResource = Obj_.CostResource;
		CostValue = Obj_.CostValue;
		RewardCode = Obj_.RewardCode;
	}
	public override string StdName()
	{
		return "EResource,int32,int32";
	}
	public override string MemberName()
	{
		return "CostResource,CostValue,RewardCode";
	}
}
public class SGachaGradeMeta : SProto
{
	public EGrade Grade = 0;
	public Double Probability = 0.0;
	public SGachaGradeMeta()
	{
	}
	public SGachaGradeMeta(SGachaGradeMeta Obj_)
	{
		Grade = Obj_.Grade;
		Probability = Obj_.Probability;
	}
	public SGachaGradeMeta(EGrade Grade_, Double Probability_)
	{
		Grade = Grade_;
		Probability = Probability_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Grade = (EGrade)Var;
		}
		Stream_.Pop(ref Probability);
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Byte Var = 0;
			Value_.Pop("Grade", ref Var);
			Grade = (EGrade)Var;
		}
		Value_.Pop("Probability", ref Probability);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Byte)Grade);
		Stream_.Push(Probability);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Grade", (Byte)Grade);
		Value_.Push("Probability", Probability);
	}
	public void Set(SGachaGradeMeta Obj_)
	{
		Grade = Obj_.Grade;
		Probability = Obj_.Probability;
	}
	public override string StdName()
	{
		return "EGrade,double";
	}
	public override string MemberName()
	{
		return "Grade,Probability";
	}
}
public class SGachaRewardMeta : SProto
{
	public Int32 Code = 0;
	public Double Probability = 0.0;
	public Int32 CharCode = 0;
	public SGachaRewardMeta()
	{
	}
	public SGachaRewardMeta(SGachaRewardMeta Obj_)
	{
		Code = Obj_.Code;
		Probability = Obj_.Probability;
		CharCode = Obj_.CharCode;
	}
	public SGachaRewardMeta(Int32 Code_, Double Probability_, Int32 CharCode_)
	{
		Code = Code_;
		Probability = Probability_;
		CharCode = CharCode_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
		Stream_.Pop(ref Probability);
		Stream_.Pop(ref CharCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
		Value_.Pop("Probability", ref Probability);
		Value_.Pop("CharCode", ref CharCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
		Stream_.Push(Probability);
		Stream_.Push(CharCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
		Value_.Push("Probability", Probability);
		Value_.Push("CharCode", CharCode);
	}
	public void Set(SGachaRewardMeta Obj_)
	{
		Code = Obj_.Code;
		Probability = Obj_.Probability;
		CharCode = Obj_.CharCode;
	}
	public override string StdName()
	{
		return "int32,double,int32";
	}
	public override string MemberName()
	{
		return "Code,Probability,CharCode";
	}
}
public class SRewardMeta : SProto
{
	public ERewardType Type = 0;
	public Int32 Data = 0;
	public SRewardMeta()
	{
	}
	public SRewardMeta(SRewardMeta Obj_)
	{
		Type = Obj_.Type;
		Data = Obj_.Data;
	}
	public SRewardMeta(ERewardType Type_, Int32 Data_)
	{
		Type = Type_;
		Data = Data_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Type = (ERewardType)Var;
		}
		Stream_.Pop(ref Data);
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Byte Var = 0;
			Value_.Pop("Type", ref Var);
			Type = (ERewardType)Var;
		}
		Value_.Pop("Data", ref Data);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Byte)Type);
		Stream_.Push(Data);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Type", (Byte)Type);
		Value_.Push("Data", Data);
	}
	public void Set(SRewardMeta Obj_)
	{
		Type = Obj_.Type;
		Data = Obj_.Data;
	}
	public override string StdName()
	{
		return "ERewardType,int32";
	}
	public override string MemberName()
	{
		return "Type,Data";
	}
}
public class SKeyRewardMeta : SProto
{
	public Int32 Code = 0;
	public SRewardMeta Reward = new SRewardMeta();
	public SKeyRewardMeta()
	{
	}
	public SKeyRewardMeta(SKeyRewardMeta Obj_)
	{
		Code = Obj_.Code;
		Reward = Obj_.Reward;
	}
	public SKeyRewardMeta(Int32 Code_, SRewardMeta Reward_)
	{
		Code = Code_;
		Reward = Reward_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
		Stream_.Pop(Reward);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
		Value_.Pop("Reward", Reward);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
		Stream_.Push(Reward);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
		Value_.Push("Reward", Reward);
	}
	public void Set(SKeyRewardMeta Obj_)
	{
		Code = Obj_.Code;
		Reward.Set(Obj_.Reward);
	}
	public override string StdName()
	{
		return "int32,ERewardType,int32";
	}
	public override string MemberName()
	{
		return "Code,Type,Data";
	}
}
public class SRankMeta : SProto
{
	public ERank Rank = 0;
	public SRankMeta()
	{
	}
	public SRankMeta(SRankMeta Obj_)
	{
		Rank = Obj_.Rank;
	}
	public SRankMeta(ERank Rank_)
	{
		Rank = Rank_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Rank = (ERank)Var;
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Byte Var = 0;
			Value_.Pop("Rank", ref Var);
			Rank = (ERank)Var;
		}
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Byte)Rank);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Rank", (Byte)Rank);
	}
	public void Set(SRankMeta Obj_)
	{
		Rank = Obj_.Rank;
	}
	public override string StdName()
	{
		return "ERank";
	}
	public override string MemberName()
	{
		return "Rank";
	}
}
public class SRankTierMeta : SProto
{
	public ERank Rank = 0;
	public Int32 Tier = 0;
	public Int32 MinPoint = 0;
	public SRankTierMeta()
	{
	}
	public SRankTierMeta(SRankTierMeta Obj_)
	{
		Rank = Obj_.Rank;
		Tier = Obj_.Tier;
		MinPoint = Obj_.MinPoint;
	}
	public SRankTierMeta(ERank Rank_, Int32 Tier_, Int32 MinPoint_)
	{
		Rank = Rank_;
		Tier = Tier_;
		MinPoint = MinPoint_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Rank = (ERank)Var;
		}
		Stream_.Pop(ref Tier);
		Stream_.Pop(ref MinPoint);
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Byte Var = 0;
			Value_.Pop("Rank", ref Var);
			Rank = (ERank)Var;
		}
		Value_.Pop("Tier", ref Tier);
		Value_.Pop("MinPoint", ref MinPoint);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Byte)Rank);
		Stream_.Push(Tier);
		Stream_.Push(MinPoint);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Rank", (Byte)Rank);
		Value_.Push("Tier", Tier);
		Value_.Push("MinPoint", MinPoint);
	}
	public void Set(SRankTierMeta Obj_)
	{
		Rank = Obj_.Rank;
		Tier = Obj_.Tier;
		MinPoint = Obj_.MinPoint;
	}
	public override string StdName()
	{
		return "ERank,int32,int32";
	}
	public override string MemberName()
	{
		return "Rank,Tier,MinPoint";
	}
}
public class SRankRewardMeta : SProto
{
	public Int32 Point = 0;
	public Int32 RewardCode = 0;
	public SRankRewardMeta()
	{
	}
	public SRankRewardMeta(SRankRewardMeta Obj_)
	{
		Point = Obj_.Point;
		RewardCode = Obj_.RewardCode;
	}
	public SRankRewardMeta(Int32 Point_, Int32 RewardCode_)
	{
		Point = Point_;
		RewardCode = RewardCode_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Point);
		Stream_.Pop(ref RewardCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Point", ref Point);
		Value_.Pop("RewardCode", ref RewardCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Point);
		Stream_.Push(RewardCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Point", Point);
		Value_.Push("RewardCode", RewardCode);
	}
	public void Set(SRankRewardMeta Obj_)
	{
		Point = Obj_.Point;
		RewardCode = Obj_.RewardCode;
	}
	public override string StdName()
	{
		return "int32,int32";
	}
	public override string MemberName()
	{
		return "Point,RewardCode";
	}
}
public class SQuestMeta : SProto
{
	public EQuestType QuestType = 0;
	public Int32 Code = 0;
	public Int32 RequirmentCount = 0;
	public String Param = "";
	public String Operator = "";
	public TCode ConditionCharacter = 0;
	public Int32 RewardCode = 0;
	public SQuestMeta()
	{
	}
	public SQuestMeta(SQuestMeta Obj_)
	{
		QuestType = Obj_.QuestType;
		Code = Obj_.Code;
		RequirmentCount = Obj_.RequirmentCount;
		Param = Obj_.Param;
		Operator = Obj_.Operator;
		ConditionCharacter = Obj_.ConditionCharacter;
		RewardCode = Obj_.RewardCode;
	}
	public SQuestMeta(EQuestType QuestType_, Int32 Code_, Int32 RequirmentCount_, String Param_, String Operator_, TCode ConditionCharacter_, Int32 RewardCode_)
	{
		QuestType = QuestType_;
		Code = Code_;
		RequirmentCount = RequirmentCount_;
		Param = Param_;
		Operator = Operator_;
		ConditionCharacter = ConditionCharacter_;
		RewardCode = RewardCode_;
	}
	public override void Push(CStream Stream_)
	{
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			QuestType = (EQuestType)Var;
		}
		Stream_.Pop(ref Code);
		Stream_.Pop(ref RequirmentCount);
		Stream_.Pop(ref Param);
		Stream_.Pop(ref Operator);
		Stream_.Pop(ref ConditionCharacter);
		Stream_.Pop(ref RewardCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		{
			Int32 Var = 0;
			Value_.Pop("QuestType", ref Var);
			QuestType = (EQuestType)Var;
		}
		Value_.Pop("Code", ref Code);
		Value_.Pop("RequirmentCount", ref RequirmentCount);
		Value_.Pop("Param", ref Param);
		Value_.Pop("Operator", ref Operator);
		Value_.Pop("ConditionCharacter", ref ConditionCharacter);
		Value_.Pop("RewardCode", ref RewardCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push((Int32)QuestType);
		Stream_.Push(Code);
		Stream_.Push(RequirmentCount);
		Stream_.Push(Param);
		Stream_.Push(Operator);
		Stream_.Push(ConditionCharacter);
		Stream_.Push(RewardCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("QuestType", (Int32)QuestType);
		Value_.Push("Code", Code);
		Value_.Push("RequirmentCount", RequirmentCount);
		Value_.Push("Param", Param);
		Value_.Push("Operator", Operator);
		Value_.Push("ConditionCharacter", ConditionCharacter);
		Value_.Push("RewardCode", RewardCode);
	}
	public void Set(SQuestMeta Obj_)
	{
		QuestType = Obj_.QuestType;
		Code = Obj_.Code;
		RequirmentCount = Obj_.RequirmentCount;
		Param = Obj_.Param;
		Operator = Obj_.Operator;
		ConditionCharacter = Obj_.ConditionCharacter;
		RewardCode = Obj_.RewardCode;
	}
	public override string StdName()
	{
		return "EQuestType,int32,int32,wstring,wstring,int32,int32";
	}
	public override string MemberName()
	{
		return "QuestType,Code,RequirmentCount,Param,Operator,ConditionCharacter,RewardCode";
	}
}
public class SQuestDailyCompleteMeta : SProto
{
	public Int32 RequirmentCount = 0;
	public Int32 RewardCode = 0;
	public Int32 RefreshMinutes = 0;
	public SQuestDailyCompleteMeta()
	{
	}
	public SQuestDailyCompleteMeta(SQuestDailyCompleteMeta Obj_)
	{
		RequirmentCount = Obj_.RequirmentCount;
		RewardCode = Obj_.RewardCode;
		RefreshMinutes = Obj_.RefreshMinutes;
	}
	public SQuestDailyCompleteMeta(Int32 RequirmentCount_, Int32 RewardCode_, Int32 RefreshMinutes_)
	{
		RequirmentCount = RequirmentCount_;
		RewardCode = RewardCode_;
		RefreshMinutes = RefreshMinutes_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref RequirmentCount);
		Stream_.Pop(ref RewardCode);
		Stream_.Pop(ref RefreshMinutes);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("RequirmentCount", ref RequirmentCount);
		Value_.Pop("RewardCode", ref RewardCode);
		Value_.Pop("RefreshMinutes", ref RefreshMinutes);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(RequirmentCount);
		Stream_.Push(RewardCode);
		Stream_.Push(RefreshMinutes);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("RequirmentCount", RequirmentCount);
		Value_.Push("RewardCode", RewardCode);
		Value_.Push("RefreshMinutes", RefreshMinutes);
	}
	public void Set(SQuestDailyCompleteMeta Obj_)
	{
		RequirmentCount = Obj_.RequirmentCount;
		RewardCode = Obj_.RewardCode;
		RefreshMinutes = Obj_.RefreshMinutes;
	}
	public override string StdName()
	{
		return "int32,int32,int32";
	}
	public override string MemberName()
	{
		return "RequirmentCount,RewardCode,RefreshMinutes";
	}
}
public class SBattleRewardMeta : SProto
{
	public TTeamCnt TeamCount = 0;
	public Int32 TeamMemberCount = 0;
	public Int32 AddGold = 0;
	public Int32 Unranked = 0;
	public Int32 Bronze = 0;
	public Int32 Silver = 0;
	public Int32 Gold = 0;
	public Int32 Diamond = 0;
	public Int32 Champion = 0;
	public SBattleRewardMeta()
	{
	}
	public SBattleRewardMeta(SBattleRewardMeta Obj_)
	{
		TeamCount = Obj_.TeamCount;
		TeamMemberCount = Obj_.TeamMemberCount;
		AddGold = Obj_.AddGold;
		Unranked = Obj_.Unranked;
		Bronze = Obj_.Bronze;
		Silver = Obj_.Silver;
		Gold = Obj_.Gold;
		Diamond = Obj_.Diamond;
		Champion = Obj_.Champion;
	}
	public SBattleRewardMeta(TTeamCnt TeamCount_, Int32 TeamMemberCount_, Int32 AddGold_, Int32 Unranked_, Int32 Bronze_, Int32 Silver_, Int32 Gold_, Int32 Diamond_, Int32 Champion_)
	{
		TeamCount = TeamCount_;
		TeamMemberCount = TeamMemberCount_;
		AddGold = AddGold_;
		Unranked = Unranked_;
		Bronze = Bronze_;
		Silver = Silver_;
		Gold = Gold_;
		Diamond = Diamond_;
		Champion = Champion_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref TeamCount);
		Stream_.Pop(ref TeamMemberCount);
		Stream_.Pop(ref AddGold);
		Stream_.Pop(ref Unranked);
		Stream_.Pop(ref Bronze);
		Stream_.Pop(ref Silver);
		Stream_.Pop(ref Gold);
		Stream_.Pop(ref Diamond);
		Stream_.Pop(ref Champion);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("TeamCount", ref TeamCount);
		Value_.Pop("TeamMemberCount", ref TeamMemberCount);
		Value_.Pop("AddGold", ref AddGold);
		Value_.Pop("Unranked", ref Unranked);
		Value_.Pop("Bronze", ref Bronze);
		Value_.Pop("Silver", ref Silver);
		Value_.Pop("Gold", ref Gold);
		Value_.Pop("Diamond", ref Diamond);
		Value_.Pop("Champion", ref Champion);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(TeamCount);
		Stream_.Push(TeamMemberCount);
		Stream_.Push(AddGold);
		Stream_.Push(Unranked);
		Stream_.Push(Bronze);
		Stream_.Push(Silver);
		Stream_.Push(Gold);
		Stream_.Push(Diamond);
		Stream_.Push(Champion);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("TeamCount", TeamCount);
		Value_.Push("TeamMemberCount", TeamMemberCount);
		Value_.Push("AddGold", AddGold);
		Value_.Push("Unranked", Unranked);
		Value_.Push("Bronze", Bronze);
		Value_.Push("Silver", Silver);
		Value_.Push("Gold", Gold);
		Value_.Push("Diamond", Diamond);
		Value_.Push("Champion", Champion);
	}
	public void Set(SBattleRewardMeta Obj_)
	{
		TeamCount = Obj_.TeamCount;
		TeamMemberCount = Obj_.TeamMemberCount;
		AddGold = Obj_.AddGold;
		Unranked = Obj_.Unranked;
		Bronze = Obj_.Bronze;
		Silver = Obj_.Silver;
		Gold = Obj_.Gold;
		Diamond = Obj_.Diamond;
		Champion = Obj_.Champion;
	}
	public override string StdName()
	{
		return "int8,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "TeamCount,TeamMemberCount,AddGold,Unranked,Bronze,Silver,Gold,Diamond,Champion";
	}
}
public class SCouponMeta : SProto
{
	public Int32 Code = 0;
	public Int32 StartYear = 0;
	public Int32 StartMonth = 0;
	public Int32 StartDay = 0;
	public Int32 StartHour = 0;
	public Int32 EndYear = 0;
	public Int32 EndMonth = 0;
	public Int32 EndDay = 0;
	public Int32 EndHour = 0;
	public Int32 RewardCode = 0;
	public SCouponMeta()
	{
	}
	public SCouponMeta(SCouponMeta Obj_)
	{
		Code = Obj_.Code;
		StartYear = Obj_.StartYear;
		StartMonth = Obj_.StartMonth;
		StartDay = Obj_.StartDay;
		StartHour = Obj_.StartHour;
		EndYear = Obj_.EndYear;
		EndMonth = Obj_.EndMonth;
		EndDay = Obj_.EndDay;
		EndHour = Obj_.EndHour;
		RewardCode = Obj_.RewardCode;
	}
	public SCouponMeta(Int32 Code_, Int32 StartYear_, Int32 StartMonth_, Int32 StartDay_, Int32 StartHour_, Int32 EndYear_, Int32 EndMonth_, Int32 EndDay_, Int32 EndHour_, Int32 RewardCode_)
	{
		Code = Code_;
		StartYear = StartYear_;
		StartMonth = StartMonth_;
		StartDay = StartDay_;
		StartHour = StartHour_;
		EndYear = EndYear_;
		EndMonth = EndMonth_;
		EndDay = EndDay_;
		EndHour = EndHour_;
		RewardCode = RewardCode_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
		Stream_.Pop(ref StartYear);
		Stream_.Pop(ref StartMonth);
		Stream_.Pop(ref StartDay);
		Stream_.Pop(ref StartHour);
		Stream_.Pop(ref EndYear);
		Stream_.Pop(ref EndMonth);
		Stream_.Pop(ref EndDay);
		Stream_.Pop(ref EndHour);
		Stream_.Pop(ref RewardCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
		Value_.Pop("StartYear", ref StartYear);
		Value_.Pop("StartMonth", ref StartMonth);
		Value_.Pop("StartDay", ref StartDay);
		Value_.Pop("StartHour", ref StartHour);
		Value_.Pop("EndYear", ref EndYear);
		Value_.Pop("EndMonth", ref EndMonth);
		Value_.Pop("EndDay", ref EndDay);
		Value_.Pop("EndHour", ref EndHour);
		Value_.Pop("RewardCode", ref RewardCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
		Stream_.Push(StartYear);
		Stream_.Push(StartMonth);
		Stream_.Push(StartDay);
		Stream_.Push(StartHour);
		Stream_.Push(EndYear);
		Stream_.Push(EndMonth);
		Stream_.Push(EndDay);
		Stream_.Push(EndHour);
		Stream_.Push(RewardCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
		Value_.Push("StartYear", StartYear);
		Value_.Push("StartMonth", StartMonth);
		Value_.Push("StartDay", StartDay);
		Value_.Push("StartHour", StartHour);
		Value_.Push("EndYear", EndYear);
		Value_.Push("EndMonth", EndMonth);
		Value_.Push("EndDay", EndDay);
		Value_.Push("EndHour", EndHour);
		Value_.Push("RewardCode", RewardCode);
	}
	public void Set(SCouponMeta Obj_)
	{
		Code = Obj_.Code;
		StartYear = Obj_.StartYear;
		StartMonth = Obj_.StartMonth;
		StartDay = Obj_.StartDay;
		StartHour = Obj_.StartHour;
		EndYear = Obj_.EndYear;
		EndMonth = Obj_.EndMonth;
		EndDay = Obj_.EndDay;
		EndHour = Obj_.EndHour;
		RewardCode = Obj_.RewardCode;
	}
	public override string StdName()
	{
		return "int32,int32,int32,int32,int32,int32,int32,int32,int32,int32";
	}
	public override string MemberName()
	{
		return "Code,StartYear,StartMonth,StartDay,StartHour,EndYear,EndMonth,EndDay,EndHour,RewardCode";
	}
}
public class SCouponKeyMeta : SProto
{
	public String Key = "";
	public Int32 Code = 0;
	public SCouponKeyMeta()
	{
	}
	public SCouponKeyMeta(SCouponKeyMeta Obj_)
	{
		Key = Obj_.Key;
		Code = Obj_.Code;
	}
	public SCouponKeyMeta(String Key_, Int32 Code_)
	{
		Key = Key_;
		Code = Code_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Key);
		Stream_.Pop(ref Code);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Key", ref Key);
		Value_.Pop("Code", ref Code);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Key);
		Stream_.Push(Code);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Key", Key);
		Value_.Push("Code", Code);
	}
	public void Set(SCouponKeyMeta Obj_)
	{
		Key = Obj_.Key;
		Code = Obj_.Code;
	}
	public override string StdName()
	{
		return "wstring,int32";
	}
	public override string MemberName()
	{
		return "Key,Code";
	}
}
public class SCostumeMeta : SProto
{
	public Int32 Code = 0;
	public ECostumePart Part = 0;
	public Int32 CharCode = 0;
	public EResource CostType = 0;
	public TResource CostValue = 0;
	public SCostumeMeta()
	{
	}
	public SCostumeMeta(SCostumeMeta Obj_)
	{
		Code = Obj_.Code;
		Part = Obj_.Part;
		CharCode = Obj_.CharCode;
		CostType = Obj_.CostType;
		CostValue = Obj_.CostValue;
	}
	public SCostumeMeta(Int32 Code_, ECostumePart Part_, Int32 CharCode_, EResource CostType_, TResource CostValue_)
	{
		Code = Code_;
		Part = Part_;
		CharCode = CharCode_;
		CostType = CostType_;
		CostValue = CostValue_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Code);
		{
			Byte Var = 0;
			Stream_.Pop(ref Var);
			Part = (ECostumePart)Var;
		}
		Stream_.Pop(ref CharCode);
		{
			Int32 Var = 0;
			Stream_.Pop(ref Var);
			CostType = (EResource)Var;
		}
		Stream_.Pop(ref CostValue);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Code", ref Code);
		{
			Byte Var = 0;
			Value_.Pop("Part", ref Var);
			Part = (ECostumePart)Var;
		}
		Value_.Pop("CharCode", ref CharCode);
		{
			Int32 Var = 0;
			Value_.Pop("CostType", ref Var);
			CostType = (EResource)Var;
		}
		Value_.Pop("CostValue", ref CostValue);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Code);
		Stream_.Push((Byte)Part);
		Stream_.Push(CharCode);
		Stream_.Push((Int32)CostType);
		Stream_.Push(CostValue);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Code", Code);
		Value_.Push("Part", (Byte)Part);
		Value_.Push("CharCode", CharCode);
		Value_.Push("CostType", (Int32)CostType);
		Value_.Push("CostValue", CostValue);
	}
	public void Set(SCostumeMeta Obj_)
	{
		Code = Obj_.Code;
		Part = Obj_.Part;
		CharCode = Obj_.CharCode;
		CostType = Obj_.CostType;
		CostValue = Obj_.CostValue;
	}
	public override string StdName()
	{
		return "int32,ECostumePart,int32,EResource,int32";
	}
	public override string MemberName()
	{
		return "Code,Part,CharCode,CostType,CostValue";
	}
}
public class SRankingConfigMeta : SProto
{
	public Int32 PeriodMinutes = 0;
	public String BaseTime = "";
	public SRankingConfigMeta()
	{
	}
	public SRankingConfigMeta(SRankingConfigMeta Obj_)
	{
		PeriodMinutes = Obj_.PeriodMinutes;
		BaseTime = Obj_.BaseTime;
	}
	public SRankingConfigMeta(Int32 PeriodMinutes_, String BaseTime_)
	{
		PeriodMinutes = PeriodMinutes_;
		BaseTime = BaseTime_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref PeriodMinutes);
		Stream_.Pop(ref BaseTime);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("PeriodMinutes", ref PeriodMinutes);
		Value_.Pop("BaseTime", ref BaseTime);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(PeriodMinutes);
		Stream_.Push(BaseTime);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("PeriodMinutes", PeriodMinutes);
		Value_.Push("BaseTime", BaseTime);
	}
	public void Set(SRankingConfigMeta Obj_)
	{
		PeriodMinutes = Obj_.PeriodMinutes;
		BaseTime = Obj_.BaseTime;
	}
	public override string StdName()
	{
		return "int32,wstring";
	}
	public override string MemberName()
	{
		return "PeriodMinutes,BaseTime";
	}
}
public class SRankingRewardMeta : SProto
{
	public String Mode = "";
	public Int32 End = 0;
	public Int32 RewardCode = 0;
	public SRankingRewardMeta()
	{
	}
	public SRankingRewardMeta(SRankingRewardMeta Obj_)
	{
		Mode = Obj_.Mode;
		End = Obj_.End;
		RewardCode = Obj_.RewardCode;
	}
	public SRankingRewardMeta(String Mode_, Int32 End_, Int32 RewardCode_)
	{
		Mode = Mode_;
		End = End_;
		RewardCode = RewardCode_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Mode);
		Stream_.Pop(ref End);
		Stream_.Pop(ref RewardCode);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Mode", ref Mode);
		Value_.Pop("End", ref End);
		Value_.Pop("RewardCode", ref RewardCode);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Mode);
		Stream_.Push(End);
		Stream_.Push(RewardCode);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Mode", Mode);
		Value_.Push("End", End);
		Value_.Push("RewardCode", RewardCode);
	}
	public void Set(SRankingRewardMeta Obj_)
	{
		Mode = Obj_.Mode;
		End = Obj_.End;
		RewardCode = Obj_.RewardCode;
	}
	public override string StdName()
	{
		return "wstring,int32,int32";
	}
	public override string MemberName()
	{
		return "Mode,End,RewardCode";
	}
}
