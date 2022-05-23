#include "stdafx.h"

void CBattle::_HitCallback(int32 AttackerIndex_, int32 TargetIndex_, int32 AddedPoint_)
{
	auto& Attacker = _Players[AttackerIndex_];
	auto& Target = _Players[TargetIndex_];

	if (Target.IsAlive())
		Attacker.AttackBalloon(AddedPoint_);
	else
		Attacker.Kill(AddedPoint_);
}
void CBattle::_RegenCallback(int32 PlayerIndex_, const SCharacter& Character_)
{
}
void CBattle::_GetItemCallback(int32 PlayerIndex_, int32 ItemCode_)
{
}
CBattle::CBattle(const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_, const TMatch::element_type::TMatchedUsers& Users_, int32 BattleIndex_, int32 RoomIdx_) :
	_BattleType(BattleType_),
	_pBattleTypeInfo(pBattleTypeInfo_),
	_TeamBattleInfos(BattleType_.TeamCount),
	_TeamEndInfos(BattleType_.TeamCount),
	_BattleEndInfos(BattleType_.TeamCount* BattleType_.MemberCount),
	_RoomIdx(RoomIdx_)
{
	// 실력으로 정렬
	vector<CUser*> Users;
	std::transform(Users_.begin(), Users_.end(), std::back_inserter(Users), [](TPeerCnt PeerNum_) { return g_Users.get(PeerNum_); });
	std::sort(Users.begin(), Users.end(), SUserCompare());

	auto [MapIndex, Map] = g_GameData->GetMultiMap(pBattleTypeInfo_->pGameMode.get());

	_MapIndex = MapIndex;

	vector<const SCharacterMeta*> Metas;
	vector<int8> TeamIndices;
	vector<unique_ptr<SCharacter>> Characters;

	Metas.reserve(Users.size());
	TeamIndices.reserve(Users.size());
	Characters.reserve(Users.size());

	_Players.reserve(Users.size());

	for (size_t i = 0; i < Users.size(); ++i)
	{
		// 유저를 실력으로 정렬했으므로 지그재그로 팀을 할당하여 나중팀이 항상 강해지는 문제가 없도록
//		i		i / TeamCount % 2	i % TeamCount	(Users.size()-i-1)%TeamCount	TeamIndex
//		0		0					0				2								0
//		1		0					1				1								1
//		2		0					2				0								2
//		3		1					0				2								2
//		4		1					1				1								1
//		5		1					2				0								0
//		6		0					0				2								0
//		7		0					1				1								1
//		8		0					2				0								2

		TTeamCnt TeamIndex = 0;
		switch (i / BattleType_.TeamCount % 2)
		{
		case 0:
			TeamIndex = i % BattleType_.TeamCount;
			break;
		case 1:
			TeamIndex = (Users.size() - i - 1) % BattleType_.TeamCount;
			break;
		}

		int64 Tick = 0;

		auto pMeta = Users[i]->GetSelectedChar();
		auto Pos = Map.Poses[i];
		auto pCharacterPtr = make_unique<SCharacter>(false, 0, c_BalloonCountForRegen, SPumpInfo(), SParachuteInfo(), SStaminaInfo(Tick, pMeta->StaminaMax), CEngineGlobal::GetFace(Pos),
			SPoint(0.0f, c_Gravity), CEngineGlobal::GetInvulnerableEndTick(Tick), 0, 0, 0);
		auto pCharacter = pCharacterPtr.get();

		Metas.emplace_back(pMeta);
		TeamIndices.emplace_back(TeamIndex);
		Characters.emplace_back(std::move(pCharacterPtr));

		_Players.emplace_back(
			CBattlePlayer(
				SBattlePlayer(
					Users[i]->GetUID(),
					Users[i]->GetNick(),
					Users[i]->GetCountryCode(),
					TeamIndex,
					Users[i]->GetSelectedCharCode(),
					0),
				Users[i]->GetSelectedChar(),
				pCharacter,
				(int32)i,
				Users[i]));
	}

	vector<CBattlePlayer*> BattlePlayers;

	for (auto& i : _Players)
		BattlePlayers.emplace_back(&i);

	for (int32 i = 0; i < _Players.size(); ++i)
		_Players[i].BattleBegin(SBattleInfo(BattleIndex_, i));

	_UserCount = (int32)_Players.size();


	_pEngine.reset(new CPhysicsEngine(
		pBattleTypeInfo_->pGameMode.get(),
		std::bind(&CBattle::_HitCallback, this, _1, _2, _3),
		std::bind(&CBattle::_RegenCallback, this, _1, _2),
		std::bind(&CBattle::_GetItemCallback, this, _1, _2),
		0,
		SBattleRecord(),
		Map.PropPosition,
		Map.Structures,
		Map.StructureMoves,
		Map.Poses,
		Metas,
		TeamIndices,
		std::move(Characters),
		BattlePlayers,
		std::bind(&CBattle::_SyncMessage, this, _1)));

	BroadCast(GetBattleBeginNetSc());
}
CBattle::~CBattle()
{
	using _TIndexPoints = pair<int32, int32>;

	vector<_TIndexPoints> IndexPoints;
	for (size_t i = 0; i < _Players.size(); ++i)
		IndexPoints.emplace_back(_TIndexPoints(i, _Players[i].Point));

	std::sort(IndexPoints.begin(), IndexPoints.end(), [](const _TIndexPoints& lhs_, const _TIndexPoints& rhs_) { return (lhs_.second > rhs_.second); });

	// 개인이 전투중 얻은 Point를 팀 정보에 합산
	for (size_t i = 0; i < _Players.size(); ++i)
	{
		auto& TeamEndInfo = _TeamEndInfos[_Players[i].TeamIndex];
		TeamEndInfo.Point += _Players[i].Point;
	}

	// 점수 별로 정리하되 점수가 같으면 list에 추가
	using TWinTeamIndices = list<TTeamCnt>;
	map<int32, list<TTeamCnt>, greater<int32>> PointTeamIndices; // Key : 팀별점수,  Value : 팀인덱스 (팀 점수로 정렬)
	for (size_t i = 0; i < _TeamEndInfos.size(); ++i)
	{
		auto& TeamEndInfo = _TeamEndInfos[i];
		auto ib = PointTeamIndices.emplace(TeamEndInfo.Point, TWinTeamIndices());
		ib.first->second.emplace_back(i);
	}

	// 팀수가 6 이고 동점이 없을 경우 : 1.0, 0.6, 0.2, -0.2, -0.6, -1.0
	// 팀수가 6 이고 동점이 있을 경우 : 1.0, 1.0, 0.2, -0.2, -0.6, -0.6

	int32 BestPoint = -1;
	set<int32> BestPlayerIndices;

	int32 BattleRanking = 0;

	for (auto it = PointTeamIndices.begin(); it != PointTeamIndices.end(); ++it)
	{
		for (auto& t : it->second)
		{
			auto& TeamEndInfo = _TeamEndInfos[t];
			TeamEndInfo.BattleRanking = BattleRanking;

			// 가장 잘한 팀이면(개인전, 팀전 무관) BestPlayer 선정
			if (it == PointTeamIndices.begin())
			{
				for (int32 i = 0; i < _Players.size(); ++i)
				{
					if (_Players[i].TeamIndex != t)
						continue;

					if (_Players[i].Point > BestPoint)
					{
						BestPoint = _Players[i].Point;
						BestPlayerIndices.clear();
						BestPlayerIndices.emplace(i);
					}
					else if (_Players[i].Point == BestPoint)
					{
						BestPlayerIndices.emplace(i);
					}
				}
			}
		}

		BattleRanking += (int32)it->second.size();
	}

	TRankingUsers RankingUsersChanged;
	list<SBattleEndPlayer> BattleEndPlayers;
	TDoneQuestDBs DoneQuestDBs;
	vector<TDoneQuests> AllDoneQuests;

	for (size_t i = 0; i < _Players.size(); ++i)
	{
		auto& Me = _Players[i];

		if (Me.IsBot())
			continue;

		auto& MyTeam = _TeamEndInfos[Me.TeamIndex];

		int32 AddedGold = 0;
		int32 AddedPoint = 0;

		if (MyTeam.Point > 0)
		{
			auto& BattleReward = (_pBattleTypeInfo->BattleReward)[MyTeam.BattleRanking];

			AddedGold = BattleReward.Gold;
			AddedPoint = BattleReward.Points[(size_t)g_GameData->GetRankTier(Me.GetPoint()).Rank];
		}

		BattleEndPlayers.emplace_back(SBattleEndPlayer(AddedPoint, AddedGold, Me.Point));

		TDoneQuests DoneQuestNets;
		_BattleEndInfos[i] = _Players[i].BattleEnd(
			_pEngine->GetGameMode(),
			BattleEndPlayers.back(),
			MyTeam,
			BestPlayerIndices.find((int32)i) != BestPlayerIndices.end(), // Is BestPlayer
			DoneQuestDBs,
			DoneQuestNets);
		AllDoneQuests.emplace_back(std::move(DoneQuestNets));

		int32 CharCode = _Players[i].CharCode;

		if (IsValidRankingInfo() && _BattleEndInfos[i].Point > g_RankingInfo.UserPointMin.UserPointMin)
			RankingUsersChanged.emplace_back(SRankingUser(SRankingUserCore(_Players[i].Nick, CharCode, _Players[i].CountryCode), _BattleEndInfos[i].UID, _BattleEndInfos[i].Point));
	}

	DBPush(CKey(), SBattleEndDBIn(_BattleEndInfos, DoneQuestDBs));

	for (size_t i = 0; i < _Players.size(); ++i)
		_Players[i].SendSBattleEndNetSc(BattleEndPlayers, _TeamBattleInfos, AllDoneQuests[i]);

	if (g_NetRankingKey && !RankingUsersChanged.empty())
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateMulti, RankingUsersChanged);

	auto& room = g_Rooms.at(_RoomIdx);
	room.EndGame();
}
SBattleBeginNetSc CBattle::GetBattleBeginNetSc(void) const
{
	vector<SBattlePlayer> Players;

	for (auto& i : _Players)
		Players.emplace_back(i);

	return SBattleBeginNetSc(
		SBattle(
			_BattleType,
			_MapIndex),
		std::move(Players),
		_pEngine->GetBattleRecord(),
		std::move(_pEngine->GetCharacters()),
		_EndTime,
		_pEngine->GetTick(),
		std::move(_pEngine->GetStructMovePositions()));
}
void CBattle::OnLine(int32 PlayerIndex_)
{
	if (_UserCount < _Players.size())
		++_UserCount;

	Send(PlayerIndex_, GetBattleBeginNetSc());
	BroadCastExcept(PlayerIndex_, SBattleLinkNetSc(_pEngine->GetTick(), PlayerIndex_));
}
bool CBattle::OffLine(int32 PlayerIndex_)
{
	if (_UserCount > 0)
		--_UserCount;

	BroadCastExcept(PlayerIndex_, SBattleUnLinkNetSc(_pEngine->GetTick(), PlayerIndex_));

	if (_UserCount == 0)
		return true;

	return false;
}
ERet CBattle::Touch(int32 PlayerIndex_, const SBattleTouchNetCs& Proto_)
{
	if (!_IsStarted())
		return ERet::InvalidProtocol;

	if (!_pEngine->Touch(PlayerIndex_, Proto_.Dir))
		return ERet::Ok;

	BroadCast(SBattleTouchNetSc(_pEngine->GetTick(), PlayerIndex_, Proto_.Dir));

	return ERet::Ok;
}
ERet CBattle::Push(int32 PlayerIndex_, const SBattlePushNetCs& Proto_)
{
	if (!_IsStarted())
		return ERet::InvalidProtocol;

	if (!_pEngine->Push(PlayerIndex_))
		return ERet::Ok;

	BroadCast(SBattlePushNetSc(_pEngine->GetTick(), PlayerIndex_));

	return ERet::Ok;
}
ERet CBattle::Icon(int32 PlayerIndex_, const SBattleIconNetCs& Proto_)
{
	BroadCast(SBattleIconNetSc(PlayerIndex_, Proto_.Code));

	return ERet::Ok;
}
void CBattle::Link(int32 PlayerIndex_)
{
	_pEngine->Link(PlayerIndex_);
	BroadCast(SBattleLinkNetSc(_pEngine->GetTick(), PlayerIndex_));
}
void CBattle::UnLink(int32 PlayerIndex_)
{
	_pEngine->UnLink(PlayerIndex_);
	BroadCast(SBattleUnLinkNetSc(_pEngine->GetTick(), PlayerIndex_));
}
bool CBattle::Proc(void)
{
	auto Now = system_clock::now(); // ing   CBattle 에서는 now() 대신 GetTickCount() 를 쓸것.

	_pEngine->Update();

	if (_IsStarted())
	{
		if (Now >= _EndTime)
			return false;
	}
	else
	{
		if (Now - _BeginTime >= milliseconds(c_BattleStartDelayMilliSec))
		{
			_EndTime = Now + (g_Option.EndlessGame ? hours(9999999) : _pBattleTypeInfo->pGameMode->GetPlaySeconds());
			BroadCast(SBattleStartNetSc(_EndTime));
		}
	}

	return true;
}
void CBattle::_SyncMessage(int64 Tick_)
{
	BroadCast(SBattleSyncNetSc(Tick_));
}