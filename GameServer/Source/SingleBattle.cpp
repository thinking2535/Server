#include "stdafx.h"


CSingleBattle::CSingleBattle(const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_, const TMatch::element_type::TMatchedUsers& Users_, int32 BattleIndex_, int32 RoomIdx_) :
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

	_Players.reserve(Users.size());

	for (size_t i = 0; i < Users.size(); ++i)
	{
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

		_Players.emplace_back(
			CSingleBattlePlayer(
				SBattlePlayer(
					Users[i]->GetUID(),
					Users[i]->GetNick(),
					Users[i]->GetCountryCode(),
					TeamIndex,
					Users[i]->GetSelectedCharCode(),
					0),
				Users[i]->GetSelectedChar(),
				(int32)i,
				Users[i]));
	}

	for (int32 i = 0; i < _Players.size(); ++i)
		_Players[i].BattleBegin(SBattleInfo(BattleIndex_, i), _BattleType.GameMode);

	_UserCount = (int32)_Players.size();
}
CSingleBattle::~CSingleBattle()
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

	set<int32> BestPlayerIndices;
	int DrawPoint = 0;
	if (_TeamEndInfos.size() == 2)
	{
		if (_TeamEndInfos[0].Point == _TeamEndInfos[1].Point)
		{
			//드로우 처리.
			DrawPoint = _TeamEndInfos[0].Point;
		}
		else
		{
			BestPlayerIndices = SetBestPlayer(PointTeamIndices);
		}
	}
	else
	{
		BestPlayerIndices = SetBestPlayer(PointTeamIndices);
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

		if (MyTeam.Point > 0 && MyTeam.Point != DrawPoint)
		{
			auto& BattleReward = (_pBattleTypeInfo->BattleReward)[MyTeam.BattleRanking];

			AddedGold = BattleReward.Gold;
			AddedPoint = BattleReward.Points[(size_t)g_GameData->GetRankTier(Me.GetPoint()).Rank];
		}

		BattleEndPlayers.emplace_back(SBattleEndPlayer(AddedPoint, AddedGold, Me.Point));

		TDoneQuests DoneQuestNets;
		_BattleEndInfos[i] = _Players[i].BattleEnd(
			_pBattleTypeInfo->pGameMode.get(),
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
		_Players[i].SendSSingleBattleEndNetSc(BattleEndPlayers, _TeamBattleInfos, AllDoneQuests[i]);

	if (g_NetRankingKey && !RankingUsersChanged.empty())
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateMulti, RankingUsersChanged);

	auto& room = g_Rooms.at(_RoomIdx);
	room.EndGame();
}
set<int32> CSingleBattle::SetBestPlayer(map<int32, list<TTeamCnt>, greater<int32>> PointTeamIndices_)
{
	int32 BestPoint = -1;
	set<int32> BestPlayerIndices;

	int32 BattleRanking = 0;

	for (auto it = PointTeamIndices_.begin(); it != PointTeamIndices_.end(); ++it)
	{
		for (auto& t : it->second)
		{
			auto& TeamEndInfo = _TeamEndInfos[t];
			TeamEndInfo.BattleRanking = BattleRanking;

			// 가장 잘한 팀이면(개인전, 팀전 무관) BestPlayer 선정
			if (it == PointTeamIndices_.begin())
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
	return BestPlayerIndices;
}
bool CSingleBattle::OffLine(int32 PlayerIndex_)
{
	if (_UserCount > 0)
		--_UserCount;

	BroadCast(SSingleBattleScoreNetSc(PlayerIndex_, 0));
	_Players[PlayerIndex_].Point = 0;

	return true;
}
ERet CSingleBattle::Icon(int32 PlayerIndex_, const SSingleBattleIconNetCs& Proto_)
{
	BroadCast(SSingleBattleIconNetSc(PlayerIndex_, Proto_.Code));

	return ERet::Ok;
}
ERet CSingleBattle::Score(int32 PlayerIndex_, const SSingleBattleScoreNetCs& Proto_)
{
	BroadCast(SSingleBattleScoreNetSc(PlayerIndex_, Proto_.Score));
	_Players[PlayerIndex_].SetPoint(Proto_.Score);

	return ERet::Ok;
}
ERet CSingleBattle::Item(int32 PlayerIndex_, const SSingleBattleItemNetCs& Proto_)
{
	BroadCast(SSingleBattleItemNetSc(PlayerIndex_, Proto_.Code));

	return ERet::Ok;
}
void CSingleBattle::Link(int32 PlayerIndex_)
{
}
void CSingleBattle::UnLink(int32 PlayerIndex_)
{
}
bool CSingleBattle::Proc(void)
{
	auto Now = system_clock::now(); // ing   CBattle 에서는 now() 대신 GetTickCount() 를 쓸것.

	if (_UserCount <= 1)
		return false;

	if (_IsStarted())
	{
		if (Now >= _EndTime)
			return false;
	}
	else
	{
		if (Now - _BeginTime >= milliseconds(c_BattleStartDelayMilliSec))
		{
			_StartTime = Now;
			_EndTime = Now + (g_Option.EndlessGame ? hours(9999999) : _pBattleTypeInfo->pGameMode->GetPlaySeconds());
			BroadCast(SSingleBattleStartNetSc(_EndTime));
		}
	}

	return true;
}
