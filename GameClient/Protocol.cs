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
public class SServer : SProto
{
	public SNamePort Hub = new SNamePort();
	public SNamePort RankingHub = new SNamePort();
	public SServer()
	{
	}
	public SServer(SServer Obj_)
	{
		Hub = Obj_.Hub;
		RankingHub = Obj_.RankingHub;
	}
	public SServer(SNamePort Hub_, SNamePort RankingHub_)
	{
		Hub = Hub_;
		RankingHub = RankingHub_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(Hub);
		Stream_.Pop(RankingHub);
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Hub", Hub);
		Value_.Pop("RankingHub", RankingHub);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Hub);
		Stream_.Push(RankingHub);
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Hub", Hub);
		Value_.Push("RankingHub", RankingHub);
	}
	public void Set(SServer Obj_)
	{
		Hub.Set(Obj_.Hub);
		RankingHub.Set(Obj_.RankingHub);
	}
	public override string StdName()
	{
		return "wstring,uint16,wstring,uint16";
	}
	public override string MemberName()
	{
		return "Name,Port,Name,Port";
	}
}
public class SOption : SProto
{
	public Boolean Auto = false;
	public Int32 DelayTick = 0;
	public TPeerCnt StartNum = 0;
	public TPeerCnt ClientCnt = 0;
	public String ID = "";
	public TUID UID = 0;
	public Int32 ServerNo = 0;
	public List<SServer> Servers = new List<SServer>();
	public SOption()
	{
	}
	public SOption(SOption Obj_)
	{
		Auto = Obj_.Auto;
		DelayTick = Obj_.DelayTick;
		StartNum = Obj_.StartNum;
		ClientCnt = Obj_.ClientCnt;
		ID = Obj_.ID;
		UID = Obj_.UID;
		ServerNo = Obj_.ServerNo;
		Servers = Obj_.Servers;
	}
	public SOption(Boolean Auto_, Int32 DelayTick_, TPeerCnt StartNum_, TPeerCnt ClientCnt_, String ID_, TUID UID_, Int32 ServerNo_, List<SServer> Servers_)
	{
		Auto = Auto_;
		DelayTick = DelayTick_;
		StartNum = StartNum_;
		ClientCnt = ClientCnt_;
		ID = ID_;
		UID = UID_;
		ServerNo = ServerNo_;
		Servers = Servers_;
	}
	public override void Push(CStream Stream_)
	{
		Stream_.Pop(ref Auto);
		Stream_.Pop(ref DelayTick);
		Stream_.Pop(ref StartNum);
		Stream_.Pop(ref ClientCnt);
		Stream_.Pop(ref ID);
		Stream_.Pop(ref UID);
		Stream_.Pop(ref ServerNo);
		{
			Servers.Clear();
			Int32 Cnt = 0;
			Stream_.Pop(ref Cnt);
			for(Int32 i = 0; i < Cnt; ++i)
			{
				SServer Value = new SServer();
				Stream_.Pop(Value);
				Servers.Add(Value);
			}
		}
	}
	public override void Push(JsonDataObject Value_)
	{
		Value_.Pop("Auto", ref Auto);
		Value_.Pop("DelayTick", ref DelayTick);
		Value_.Pop("StartNum", ref StartNum);
		Value_.Pop("ClientCnt", ref ClientCnt);
		Value_.Pop("ID", ref ID);
		Value_.Pop("UID", ref UID);
		Value_.Pop("ServerNo", ref ServerNo);
		Value_.Pop("Servers", ref Servers);
	}
	public override void Pop(CStream Stream_)
	{
		Stream_.Push(Auto);
		Stream_.Push(DelayTick);
		Stream_.Push(StartNum);
		Stream_.Push(ClientCnt);
		Stream_.Push(ID);
		Stream_.Push(UID);
		Stream_.Push(ServerNo);
		Stream_.Push((Int32)Servers.Count);
		foreach(var it in Servers)
		{
			Stream_.Push(it);
		}
	}
	public override void Pop(JsonDataObject Value_)
	{
		Value_.Push("Auto", Auto);
		Value_.Push("DelayTick", DelayTick);
		Value_.Push("StartNum", StartNum);
		Value_.Push("ClientCnt", ClientCnt);
		Value_.Push("ID", ID);
		Value_.Push("UID", UID);
		Value_.Push("ServerNo", ServerNo);
		Value_.Push("Servers", Servers);
	}
	public void Set(SOption Obj_)
	{
		Auto = Obj_.Auto;
		DelayTick = Obj_.DelayTick;
		StartNum = Obj_.StartNum;
		ClientCnt = Obj_.ClientCnt;
		ID = Obj_.ID;
		UID = Obj_.UID;
		ServerNo = Obj_.ServerNo;
		Servers = Obj_.Servers;
	}
	public override string StdName()
	{
		return "bool,int32,uint32,uint32,wstring,int64,int32,{wstring,uint16,wstring,uint16}";
	}
	public override string MemberName()
	{
		return "Auto,DelayTick,StartNum,ClientCnt,ID,UID,ServerNo,Servers";
	}
}
