#include "stdafx.h"
#include <Rso/Game/Base.h>
#include "CheatCommand.h"
#include <Rso/Win/ConsoleCtrlHandler.h>

using namespace rso;
using namespace win;

CConsoleCtrlHandler g_ConsoleCtrlHandler;

void DBCallback(TSessionsIt itSession_, TOutObject& OutObject_)
{
	try
	{
		g_BinderDB[OutObject_.SPNum](itSession_, OutObject_);
	}
	catch (...)
	{
	}
}

void LinkAgent(const CKey& Key_)
{
	LOG(L"LinkAgent Key[%d]", Key_.PeerNum);
}
void UnLinkAgent(const CKey& Key_, ENetRet NetRet_)
{
	LOG(L"UnLinkAgent Key[%d]", Key_.PeerNum);
}

void CallbackUserProto(const CKey& ClientKey_, CStream& Stream_)
{
}
void CallbackStop(const wstring& Message_, const seconds& SecondLeft_)
{
	LOG(L"CallbackStop Message[%s] SecondLeft[%d]", Message_, SecondLeft_.count());

	g_Net->SetOpened(false);
	g_Monitor->SetStat(SKeyData(L"Opened", L"false"));
	BroadCast(SMsgNetSc(Message_));
	g_Timers.emplace(SecondLeft_, Message_);
}
void CallbackMessage(const wstring& Message_)
{
	BroadCast(SMsgNetSc(Message_));
}

void Check(TSessionsIt itSession_, TSessionCode SessionCode_)
{
	DBPush(itSession_, CKey(), SCheckIDDBIn(itSession_->first), SessionCode_);
	DLOG(L"Check UID : %d", itSession_->first);
}
void LinkM(const CKey& Key_)
{
	g_MasterKey = Key_;
	LOG(L"LinkM PeerNum:%d", Key_.PeerNum);
}
void LinkFailM(TPeerCnt PeerNum_, ENetRet NetRet_)
{
	LOG(L"LinkFailM PeerNum:%d NetRet:%d", PeerNum_, (int32)NetRet_);
}
void UnLinkM(const CKey& Key_, ENetRet NetRet_)
{
	g_MasterKey = CKey();

	LOG(L"UnLinkM PeerNum:%d NetRet:%d", Key_.PeerNum, (int32)NetRet_);
}
void RecvM(const CKey& Key_, CStream& Stream_)
{
	DLOG(L"RecvM PeerNum:%d", Key_.PeerNum);

	int32 ProtoNum = 0;
	Stream_ >> ProtoNum;

	auto itRecv = g_BinderRecvM.get(ProtoNum);
	if (!itRecv)
		THROWEX();

	(*itRecv)(Key_, Stream_);
}
void LinkC(TSessionsIt itSession_, const CKey& Key_, bool Create_, CStream& Stream_)
{
	DLOG(L"LinkC PeerNum[%d] UID[%d]", Key_.PeerNum, itSession_->first);

	SUserCreateOption CreateOption(SUserLoginOption(EOS::Android), ELanguage::English);

	if (Create_)
	{
		Stream_ >> CreateOption;

		if ((int32)CreateOption.LoginOption.OS < 0 || CreateOption.LoginOption.OS >= EOS::Max)
			throw 0;

		if ((int32)CreateOption.Language < 0 || CreateOption.Language >= ELanguage::Max)
			throw 0;
	}
	else
	{
		Stream_ >> CreateOption.LoginOption;

		if ((int32)CreateOption.LoginOption.OS < 0 || CreateOption.LoginOption.OS >= EOS::Max)
			throw 0;
	}

	auto NamePort = g_Net->GetNamePort(Key_.PeerNum);
	g_Users.login(itSession_, Key_, CreateOption, g_IPInfo.Get(u16string_to_u8string(NamePort.Name)));
}
void UnLinkC(TSessionsIt itSession_, const CKey& Key_, ENetRet NetRet_)
{
	// 전투 타입 얼마 안되니 그냥 돌면서 다 지워
	for (auto& i : g_Matches)
		i.second->erase(Key_.PeerNum);

	g_Users.logout(Key_.PeerNum);

	DLOG(L"UnLinkC PeerNum:%d NetRet:%d", Key_.PeerNum, int32(NetRet_));
}
void RecvC(TSessionsIt itSession_, const CKey& Key_, CStream& Stream_)
{
	if (!g_Net->GetOpened())
		return;

	auto User = GetUser(Key_);
	if (!User)
		return;

	if (!User->IsDataLoaded())
		return g_Net->Close(Key_.PeerNum);

	if (User->IsBusy())
		return g_Net->Close(Key_.PeerNum);

	int32 ProtoNum = 0;
	Stream_ >> ProtoNum;

	DLOG(L"RecvC UID:%d PeerNum:%d ProtoNum:%d", User->GetUID(), Key_.PeerNum, ProtoNum);

	auto itRecv = g_BinderRecvC.get(ProtoNum);
	if (!itRecv)
		return g_Net->Close(Key_.PeerNum);

	if ((EProtoNetCs)ProtoNum != EProtoNetCs::FCMTokenSet &&
		(EProtoNetCs)ProtoNum != EProtoNetCs::FCMTokenUnset)
	{
		// switch 문으로 하지 않은 이유는 유저의 상태가 여러 상태 변수을의 조함으로 얻어지고 이를 함수화 하여 swith 문으로 처리한다 할지라도
		// 그 함수 내에서 조건문에 의한 처리가 불가피 하다고 판단되어 그냥 이대로 처리
		//if (User->IsInBattleSingle()) // 싱글 전투 상태
		//{
		//	if ((EProtoNetCs)ProtoNum != EProtoNetCs::BattleSingleUnitDrop &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleSingleClanUnitDrop &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleSingleAvatarDrop &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleSingleAvatarCoolTime &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleSingleEnd &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::TutorialComplete)
		//		return User->SendRet(ERet::InBattleSingle);
		//}
		//else if (User->IsScouting()) // 정찰시작 부터 전산완료 전 까지의 상태
		//{
		//	if (User->GetWaitTargetDB())
		//		return User->SendRet(ERet::InScouting);

		//	auto Target = User->GetTarget();
		//	if (!Target || !Target->GetIsNeedToFinish())
		//		return User->SendRet(ERet::InScouting);

		//	if ((EProtoNetCs)ProtoNum != EProtoNetCs::BattleFinish)
		//		return User->SendRet(ERet::InScouting);
		//}
		//else if (User->IsInBattle()) // 멀티 전투 상태
		//{
		//	if ((EProtoNetCs)ProtoNum != EProtoNetCs::BattleScout &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleScoutTarget &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleRevenge &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleCheckPoint &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleUnitDrop &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleAvatarAction &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleClanUnitDrop &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::BattleEnd &&
		//		(EProtoNetCs)ProtoNum != EProtoNetCs::TutorialComplete)
		//		return User->SendRet(ERet::InScout);
		//}
		//else if (User->IsScouted()) // 멀티 피격 상태
		//{
		//	return User->SendRet(ERet::InScouted);
		//}
		//else if (User->GetIsNeedToFinish()) // 전투중이 아닌 미정산 상태
		//{
		//	if ((EProtoNetCs)ProtoNum != EProtoNetCs::BattleFinish)
		//		return User->SendRet(ERet::NeedToBattleFinish);
		//}
	}

	try
	{
		auto Ret = (*itRecv)(User, Stream_);
		if (Ret != ERet::Ok)
			User->SendRet(Ret);
	}
	catch (...)
	{
		if (User->Key())
			g_Net->Close(User->Key());
	}
}
void RecvSessionHold(TSessionsIt itSession_, CStream& Stream_)
{
	int32 ProtoNum = 0;
	Stream_ >> ProtoNum;

	DLOG(L"RecvSessionHold UID[%d] ProtoNum[%d]", itSession_->first, ProtoNum);

	auto itRecv = g_BinderRecvSessionHold.get(ProtoNum);
	if (!itRecv)
		throw 0;

	try
	{
		(*itRecv)(itSession_, Stream_);
	}
	catch (...)
	{
	}
}
void RecvSendToServer(TSessionsIt itSession_, CStream& Stream_)
{
	int32 ProtoNum = 0;
	Stream_ >> ProtoNum;

	DLOG(L"RecvSendToServer UID[%d] ProtoNum[%d]", itSession_->first, ProtoNum);

	auto itRecv = g_BinderRecvSs.get(ProtoNum);
	if (!itRecv)
		throw 0;

	try
	{
		(*itRecv)(itSession_, Stream_);
	}
	catch (...)
	{
	}
}
void RecvPunish(TUID UID_, const TTime& EndTime_)
{
	LOG(L"RecvPunish UID[%d]", UID_);

	auto User = g_Users.get_with_uid(UID_);
	if (!User)
		return;

	User->SendMsg(L"You've been punished.");
	WillClose(User->Key().PeerNum);
}

void ChangeNick(const CKey& ClientKey_, EGameRet GameRet_)
{
	auto User = GetUser(ClientKey_);
	if (!User)
		return;

	User->ChangeNickResult(GameRet_);
}

void Matching(TPeerCnt PeerNum_, size_t Count_)
{
	Send(PeerNum_, SMultiBattleMatchingNetSc((int32)Count_));
}
void Matched(const TMatch::element_type::TMatchedUsers& Users_, const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_)
{
	try
	{
		auto itBattle = g_Battles.emplace(nullptr);
		itBattle->reset(new CMultiBattle(BattleType_, pBattleTypeInfo_, Users_, itBattle));
	}
	catch (const ERet& Ret_)
	{
		for (auto& i : Users_)
			Send(i, SRetNetSc(Ret_));
	}
	catch (...)
	{
		for (auto& i : Users_)
			Send(i, SRetNetSc(ERet::BattleBeginFail));
	}
}

void LinkR(const CKey& Key_)
{
	g_NetRankingKey = Key_;
	LOG(L"LinkR PeerNum:%d", Key_.PeerNum);
}
void LinkFailR(TPeerCnt PeerNum_, ENetRet NetRet_)
{
	LOG(L"LinkFailR PeerNum:%d NetRet:%d", PeerNum_, (int32)NetRet_);
}
void UnLinkR(const CKey& Key_, ENetRet NetRet_)
{
	new (&g_NetRankingKey) CKey();
	new (&g_RankingInfo) SRankingRankingInfoNetRs();
	LOG(L"UnLinkR PeerNum:%d NetRet:%d", Key_.PeerNum, (int32)NetRet_);
}
void RecvR(const CKey& Key_, CStream& Stream_)
{
	int32 ProtoNum = 0;
	Stream_ >> ProtoNum;

	DLOG(L"RecvR PeerNum:%d ProtoNum:%d", Key_.PeerNum, ProtoNum);

	auto itRecv = g_BinderRecvR.get(ProtoNum);
	if (!itRecv)
		return g_Net->Close(Key_.PeerNum);

	(*itRecv)(Key_, Stream_);
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		time_t TimeT = 0;
		time(&TimeT);
		srand((unsigned int)TimeT);
		wcout.imbue(std::locale("korean"));

		LOG(L"Initializing GameData");
		g_MetaData.reset(new TMetaData::element_type());

		LOG(L"Initializing Cheat Command");
		g_Command.Insert(L"/help", TCommand::SCommandInfo(L"print command list", L"", CommandHelp));
		g_Command.Insert(L"/setuserlevel", TCommand::SCommandInfo(L"", L"level", CommandSetUserLevel));
		g_Command.Insert(L"/addresources", TCommand::SCommandInfo(L"", L"gold star dia", CommandAddResources));
		g_Command.Insert(L"/setresources", TCommand::SCommandInfo(L"", L"gold star dia", CommandSetResources));
		g_Command.Insert(L"/setmapindex", TCommand::SCommandInfo(L"", L"mapindex (-1 : random)", CommandSetMapIndex));
		g_Command.Insert(L"/setpoint", TCommand::SCommandInfo(L"", L"point", CommandSetPoint));
		g_Command.Insert(L"/setchar", TCommand::SCommandInfo(L"", L"charcode (empty : all)", CommandSetChar));
		g_Command.Insert(L"/unsetchar", TCommand::SCommandInfo(L"", L"charcode (empty : all)", CommandUnsetChar));
		g_Command.Insert(L"/questcomplete", TCommand::SCommandInfo(L"", L"slotindex data", CommandQuestComplete));
		g_Command.Insert(L"/questset", TCommand::SCommandInfo(L"", L"slotindex code", CommandQuestSet));

		LOG(L"Initializing Option Files");
		COptionJson<SOption> Option(L"Option.ini", false);
		LOG(L"Initializing Option Files");
		COptionJson<SOptionRanking> OptionRanking(L"OptionRanking.ini", false);
		LOG(L"Initializing OptionRanking Files");
		COptionJson<SDBOptions> DBOptions(L"DBOptions.ini", false);
		LOG(L"Initializing DBOptions Files");

		SVersion Version(c_Ver_Main, g_MetaData->CheckSumMeta);
		LOG(L"CheckSum : %d", g_MetaData->CheckSumMeta);

		g_Option = *Option;

		wstring ProcName(MBSToWCS(
			Option->Title +
			" NetVer:" + WCSToMBS(StringFormat(L"%d", int32(Version.Main))) + 
			" DataVer:" + to_string(g_MetaData->CheckSumMeta) +
			" ClientBindPort:" + to_string(Option->ClientBindPort)));
		SetConsoleTitle(ProcName.c_str());

		LOG(L"Initializing Match");

		for (auto& i : g_MetaData->GetBattleTypeInfos())
		{
			auto AllMemberCount = GetAllMemberCount(i.first);
			ASSERTION(AllMemberCount <= c_MaxPlayer && i.first.TeamCount > 1);
			g_Matches.emplace(i.first, new TMatch::element_type(AllMemberCount, Matching, Matched, seconds(5), g_MetaData->GetMaxRewardPoint(), i.first, &i.second));
		}

		LOG(L"Initializing BulkCopyConnect");
		g_BulkCopyConnect.reset(new TBulkCopyConnect::element_type(DBOptions->Log, L"tConnect", L"000000"));

		LOG(L"Initializing Monitor");
		g_Monitor.reset(
			new TMonitor::element_type(
				EAddressFamily::INET,
				LinkAgent, UnLinkAgent,
				CallbackUserProto,
				CallbackStop,
				CallbackMessage,
				ProcName,
				CNamePort(Option->MonitorAgentBindPort),
				wstring(L"{}")
			)
		);

		LOG(L"Initializing Server");
		g_Net.reset(new TNet::element_type(
			EAddressFamily::INET,
			Check, LinkM, LinkFailM, UnLinkM, RecvM, LinkC, UnLinkC, RecvC,
			RecvSessionHold, RecvSendToServer, RecvPunish,
			ChangeNick, DBCallback,
			Version,
			DBOptions->Game,
			CNamePort(Option->MasterNamePort),
			Option->NetCThreadCnt,
			CNamePort(Option->ClientBindPort),
			CNamePort(Option->ClientBindNamePortPub),
			Option->ServerBindPort,
			false));

		g_NetRanking.reset(new TNetRanking::element_type(
			LinkR, LinkFailR, UnLinkR, RecvR,
			false, 1024000, 1024000,
			milliseconds(), milliseconds(), 1, 5,
			milliseconds(5000)));

		LOG(L"Binding DataBase Recv");

		// Game DB //////////////////////////////////////
		DBAddCmd<SJoinDBIn, SLoginDBOut>(L"dbo.spJoin", true, JoinDBOut);
		DBAddCmd<SLoginDBIn, SLoginDBOut>(L"dbo.spLogin", true, LoginDBOut);
		DBAddCmd<SLogoutDBIn, SDummyDBOut>(L"dbo.spLogout", true, DummyDBOut);
		DBAddCmd<SSetUserExpDBIn, SDummyDBOut>(L"dbo.spSetUserExp", true, DummyDBOut);
		DBAddCmd<SSetResourcesDBIn, SDummyDBOut>(L"dbo.spSetResources", true, DummyDBOut);
		DBAddCmd<SSetPointDBIn, SDummyDBOut>(L"dbo.spSetPoint", true, DummyDBOut);
		DBAddCmd<SSetCharDBIn, SDummyDBOut>(L"dbo.spSetChar", true, DummyDBOut);
		DBAddCmd<SUnsetCharDBIn, SDummyDBOut>(L"dbo.spUnsetChar", true, DummyDBOut);
		DBAddCmd<SCanPushAtNightDBIn, SDummyDBOut>(L"dbo.spCanPushAtNight", true, DummyDBOut);
		DBAddCmd<SChangeLanguageDBIn, SDummyDBOut>(L"dbo.spChangeLanguage", true, DummyDBOut);
		DBAddCmd<SBuyDBIn, SDummyDBOut>(L"dbo.spBuy", true, DummyDBOut);
		DBAddCmd<SBuyCharDBIn, SDummyDBOut>(L"dbo.spBuyChar", true, DummyDBOut);
		DBAddCmd<SBuyPackageDBIn, SDummyDBOut>(L"dbo.spBuyPackage", true, DummyDBOut);
		DBAddCmd<SPurchaseDBIn, SDummyDBOut>(L"dbo.spPurchase", true, PurchaseDBOut);
		DBAddCmd<SDailyRewardDBIn, SDummyDBOut>(L"dbo.spDailyReward", true, DummyDBOut);
		DBAddCmd<SSelectCharDBIn, SDummyDBOut>(L"dbo.spSelectChar", true, DummyDBOut);
		DBAddCmd<SIslandStartDBIn, SDummyDBOut>(L"dbo.spIslandStart", true, DummyDBOut);
		DBAddCmd<SIslandEndDBIn, SDummyDBOut>(L"dbo.spIslandEnd", true, DummyDBOut);
		DBAddCmd<SBattleEndDBIn, SDummyDBOut>(L"dbo.spBattleEnd", true, DummyDBOut);
		DBAddCmd<SArrowDodgeBattleStartDBIn, SDummyDBOut>(L"dbo.spArrowDodgeBattleStart", true, DummyDBOut);
		DBAddCmd<SArrowDodgeBattleEndDBIn, SDummyDBOut>(L"dbo.spArrowDodgeBattleEnd", true, DummyDBOut);
		DBAddCmd<SGachaDBIn, SDummyDBOut>(L"dbo.spGacha", true, DummyDBOut);
		DBAddCmd<SRankRewardDBIn, SDummyDBOut>(L"dbo.spRankReward", true, DummyDBOut);
		DBAddCmd<SQuestNewDBIn, SDummyDBOut>(L"dbo.spQuestNew", true, DummyDBOut);
		DBAddCmd<SQuestDelDBIn, SDummyDBOut>(L"dbo.spQuestDel", true, DummyDBOut);
		DBAddCmd<SQuestDoneDBIn, SDummyDBOut>(L"dbo.spQuestDone", true, DummyDBOut);
		DBAddCmd<SQuestRewardDBIn, SDummyDBOut>(L"dbo.spQuestReward", true, DummyDBOut);
		DBAddCmd<SQuestNextDBIn, SDummyDBOut>(L"dbo.spQuestNext", true, DummyDBOut);
		DBAddCmd<SQuestDailyCompleteRewardDBIn, SDummyDBOut>(L"dbo.spQuestDailyCompleteReward", true, DummyDBOut);
		DBAddCmd<SChangeNickBeginDBIn, SDummyDBOut>(L"dbo.spChangeNickBegin", true, ChangeNickBeginDBOut);
		DBAddCmd<SChangeNickEndDBIn, SDummyDBOut>(L"dbo.spChangeNickEnd", true, ChangeNickEndDBOut);
		DBAddCmd<SChangeNickEndFailDBIn, SDummyDBOut>(L"dbo.spChangeNickEndFail", true, ChangeNickEndFailDBOut);
		DBAddCmd<SCheckIDDBIn, SCheckIDNetSc>(L"dbo.spCheckID", true, CheckIDDBOut);
		DBAddCmd<SCouponUseDBIn, SDummyDBOut>(L"dbo.spCouponUse", true, DummyDBOut);
		DBAddCmd<STutorialRewardDBIn, SDummyDBOut>(L"dbo.spTutorialReward", true, DummyDBOut);
		DBAddCmd<SRankingRewardDBIn, SDummyDBOut>(L"dbo.spRankingReward", true, DummyDBOut);

		// Coupon DB /////////////////////////////////////////
		COptionJson<SDBOption> CouponDBOption(L"CouponDBOption.ini", false);
		g_pCouponDB = std::make_unique<TCouponSP>(*CouponDBOption, CouponDBOut);
		g_pCouponDB->AddCmd<SCouponUseCouponDBIn, SDummyDBOut>(0, L"dbo.spCouponUse", true);
		g_pCouponDB->Start(5);


		LOG(L"Binding Network Recv");
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::Chat, ChatNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::FCMTokenSet, FCMTokenSetNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::FCMTokenUnset, FCMTokenUnsetNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::FCMCanPushAtNight, FCMCanPushAtNightNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::ChangeLanguage, FCMCanPushAtNightNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::Buy, BuyNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::BuyChar, BuyCharNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::BuyPackage, BuyPackageNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::Purchase, PurchaseNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::DailyReward, DailyRewardNetCs);

		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::SelectChar, SelectCharNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::IslandStart, IslandStartNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::IslandEnd, IslandEndNetCs);

		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::BattleTouch, BattleTouchNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::BattlePush, BattlePushNetCs);

		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::MultiBattleJoin, MultiBattleJoinNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::MultiBattleOut, MultiBattleOutNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::MultiBattleIcon, MultiBattleIconNetCs);

		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::ArrowDodgeBattleJoin, ArrowDodgeBattleJoinNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::ArrowDodgeBattleEndForce, ArrowDodgeBattleEndForceNetCs);

		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::Gacha, GachaNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::GachaX10, GachaX10NetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::RankReward, RankRewardNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::QuestReward, QuestRewardNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::QuestNext, QuestNextNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::QuestDailyCompleteReward, QuestDailyCompleteRewardNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::ChangeNick, ChangeNickNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::CouponUse, CouponUseNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::TutorialReward, TutorialRewardNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::RankingRewardInfo, RankingRewardInfoNetCs);
		g_BinderRecvC.emplace_at((size_t)EProtoNetCs::RankingReward, RankingRewardNetCs);

		g_BinderRecvM.emplace_at((size_t)EProtoNetMs::ReceiptInitialize, ReceiptInitializeNetMs);
		g_BinderRecvM.emplace_at((size_t)EProtoNetMs::ReceiptAccessToken, ReceiptAccessTokenNetMs);

		// Ss Binding
		g_BinderRecvSs.emplace_at((size_t)EProtoNetSs::Message, MessageNetSs);

		// Ranking Binding
		g_BinderRecvR.emplace_at((size_t)EProtoRankingNetRs::RankingInfo, RankingInfoNetRs);
		g_BinderRecvR.emplace_at((size_t)EProtoRankingNetRs::UserPointMin, UserPointMinNetRs);


		LOG(L"Starting Network");
		g_Net->Start();

		while (!g_ReceiptCheck)
		{
			if (g_ConsoleCtrlHandler.GetExit())
				THROWEXA(L"ConsoleCtrlHandler Exit");

			g_Net->Proc();
			g_Monitor->Proc();
			g_Timers.Proc();
			this_thread::sleep_for(milliseconds(500));
		}

		LOG(L"Initialized");

		if (!g_NetRanking->Connect(CNamePort(OptionRanking->RankingNamePort)))
			THROWEX();

		while (!g_ConsoleCtrlHandler.GetExit())
		{
			g_Monitor->Proc();
			g_Net->Proc();
			g_NetRanking->Proc();
			g_ReceiptCheck->Proc();
			g_pCouponDB->Proc();

			for (auto it = g_Battles.begin(); it != g_Battles.end(); )
			{
				auto itCheck = it;
				++it;

				if (!(*itCheck)->Update())
					g_Battles.erase(itCheck);
			}

			if (g_TimerPeriod.CheckAndNextLoose())
			{
				if (g_Net->GetPeerCnt() != g_CCUSended)
				{
					g_CCUSended = g_Net->GetPeerCnt();
					g_Monitor->SetStat(SKeyData(L"CCU", to_wstring(g_CCUSended)));
				}

				if (g_CCULogPeriod.CheckAndNextLoose())
					LOG(L"CCU [%d]", g_CCUSended);

				g_Timers.Proc();

				for (auto& i : g_Matches)
					i.second->Proc();
			}

			this_thread::sleep_for(milliseconds(1));
		}
	}
	catch (const SException& Exception_)
	{
		cout << Exception_.what() << endl;
		LOG(L"SException %s", Exception_.what());
	}

	return 0;
}
