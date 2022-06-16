#include "stdafx.h"

void CMultiBattle::_AddBattlePlayer(const shared_ptr<CMultiBattlePlayer>& pBattlePlayer_)
{
	_MultiBattlePlayers.emplace_back(pBattlePlayer_);
	CBattle::_AddBattlePlayer(pBattlePlayer_);
}
void CMultiBattle::_HitCallback(int32 AttackerIndex_, int32 TargetIndex_)
{
	auto& Attacker = _MultiBattlePlayers[AttackerIndex_];
	auto& Target = _MultiBattlePlayers[TargetIndex_];

	int32 AddedPoint = 0;

	if (Target->IsAlive()) // Hit Balloon
	{
		++_BattleRecord.TotalBalloonHitCount;

		if (_BattleRecord.TotalBalloonHitCount == 1)
			AddedPoint = g_MetaData->ConfigMeta.FirstBalloonHitPoint;
		else
			AddedPoint = g_MetaData->ConfigMeta.BalloonHitPoint;
	}
	else // Kill
	{
		++_BattleRecord.TotalKillCount;
		AddedPoint = g_MetaData->ConfigMeta.ParachuteHitPoint;
	}

	if (Target->IsAlive())
		Attacker->AttackBalloon(AddedPoint);
	else
		Attacker->Kill(AddedPoint);
}
void CMultiBattle::_RegenCallback(int32 PlayerIndex_)
{
}
void CMultiBattle::_IconCallback(int32 PlayerIndex_, const SMultiBattleIconNetCs& Proto_)
{
	BroadCast(SMultiBattleIconNetSc(PlayerIndex_, Proto_.Code));
}
void CMultiBattle::_FixedUpdate(int64 Tick_)
{
	for (auto& i : _MultiBattlePlayers)
		i->CheckRegen(Tick_);
}
CMultiBattle::CMultiBattle(const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_, const TMatch::element_type::TMatchedUsers& Users_, TBattlesIt itBattle_) :
	CBattle(
		make_unique<CServerEngine>(
			c_NetworkTickSync,
			0,
			c_ContactOffset,
			c_FPS,
			std::bind(&CMultiBattle::_SyncMessage, this, _1)),
		BattleType_),
	_pBattleTypeInfo(pBattleTypeInfo_)
{
	// 실력으로 정렬
	vector<CUser*> Users;
	std::transform(Users_.begin(), Users_.end(), std::back_inserter(Users), [](TPeerCnt PeerNum_) { return g_Users.get(PeerNum_); });
	std::sort(Users.begin(), Users.end(), SUserCompare());

	auto [MapIndex, Map] = g_MetaData->GetMultiMap();
	_MapIndex = MapIndex;
	_pRootObject = make_shared<CObject2D>(GetDefaultTransform(Map.PropPosition));


	// Structure /////////////////////////////////
	list<shared_ptr<CCollider2D>> StructureColliders;
	for (auto& s : Map.Structures)
		StructureColliders.emplace_back(make_shared<CRectCollider2D>(s, CEngineGlobal::c_StructureNumber, s.RectCollider2D));

	auto pCollectionCollider = make_shared<CCollectionCollider2D>(GetDefaultTransform(Map.PropPosition), CEngineGlobal::c_ContainerNumber);
	SetCollectionToCollectionCollider2D(StructureColliders, pCollectionCollider);
	_pEngine->AddObject(pCollectionCollider);


	// Moving Structures //////////////////////////
	for (auto& s : Map.StructureMoves)
	{
		list<shared_ptr<CCollider2D>> Colliders;
		for (auto& c : s.Colliders)
			Colliders.emplace_back(make_shared<CRectCollider2D>(ZeroTransform, CEngineGlobal::c_StructureNumber, c));

		auto pShuttleObject = make_shared<CShuttleObject2D>(
			GetDefaultTransform(s.BeginPos),
			s.BeginPos,
			s.EndPos,
			s.Velocity,
			s.Delay,
			SStructMove(true, 1, 0.0f));

		auto pShuttleCollider = make_shared<CCollectionCollider2D>(ZeroTransform, CEngineGlobal::c_ContainerNumber);
		SetCollectionToCollectionCollider2D(Colliders, pShuttleCollider);
		SetColliderToMovingObject2D(pShuttleCollider, pShuttleObject);

		pShuttleObject->SetParent(_pRootObject);
		_ShuttleStructures.emplace_back(pShuttleObject.get());
		_pEngine->AddMovingObject(std::move(pShuttleObject));
	}


	// Players ////////////////////////////
	_MultiBattlePlayers.reserve(Users.size()); // prevent change memory pointer
	int64 Tick = 0;

	for (int32 i = 0; i < Users.size(); ++i)
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

		auto pMeta = Users[i]->GetSelectedChar();
		auto& Pos = Map.Poses[i];

		auto pCharacter = make_unique<SCharacter>(false, 0, c_BalloonCountForRegen, SPumpInfo(), SParachuteInfo(), SStaminaInfo(Tick, pMeta->StaminaMax), CEngineGlobal::GetFaceWithPosition(Pos),
			SPoint(0.0f, c_Gravity), CEngineGlobal::GetInvulnerableEndTick(Tick), 0, 0, 0);

		auto pMultiBattlePlayer = make_shared<CMultiBattlePlayer>(
			SBattlePlayer(
				Users[i]->GetUID(),
				Users[i]->GetNick(),
				Users[i]->GetCountryCode(),
				TeamIndex,
				Users[i]->GetSelectedCharCode()),
			std::bind(&CMultiBattle::_HitCallback, this, _1, _2),
			std::bind(&CMultiBattle::_RegenCallback, this, _1),
			std::bind(&CMultiBattle::_IconCallback, this, _1, _2),
			(int32)i,
			Pos,
			pMeta,
			TeamIndex,
			std::move(pCharacter),
			itBattle_,
			Users[i]);

		pMultiBattlePlayer->pPlayerObject->SetParent(_pRootObject);
		_AddBattlePlayer(pMultiBattlePlayer);
	}

	_pEngine->fFixedUpdate = std::bind(&CMultiBattle::_FixedUpdate, this, _1);

	BroadCast(GetBattleBeginNetSc());
}
CMultiBattle::~CMultiBattle()
{
	using _TIndexPoints = pair<int32, int32>;

	vector<_TIndexPoints> IndexPoints;
	for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
		IndexPoints.emplace_back(_TIndexPoints(i, _MultiBattlePlayers[i]->BattleInfo.Point));

	std::sort(IndexPoints.begin(), IndexPoints.end(), [](const _TIndexPoints& lhs_, const _TIndexPoints& rhs_) { return (lhs_.second > rhs_.second); });


	// 개인이 전투중 얻은 Point를 팀 정보에 합산
	vector<STeamEndInfo> TeamEndInfos(_BattleType.TeamCount);
	for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
	{
		auto& TeamEndInfo = TeamEndInfos[_MultiBattlePlayers[i]->TeamIndex];
		TeamEndInfo.Point += _MultiBattlePlayers[i]->BattleInfo.Point;
	}

	// 점수 별로 정리하되 점수가 같으면 list에 추가
	using TWinTeamIndices = list<TTeamCnt>;
	map<int32, list<TTeamCnt>, greater<int32>> PointTeamIndices; // Key : 팀별점수,  Value : 팀인덱스 (팀 점수로 정렬)
	for (size_t i = 0; i < TeamEndInfos.size(); ++i)
	{
		auto& TeamEndInfo = TeamEndInfos[i];
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
			auto& TeamEndInfo = TeamEndInfos[t];
			TeamEndInfo.BattleRanking = BattleRanking;

			// 가장 잘한 팀이면(개인전, 팀전 무관) BestPlayer 선정
			if (it == PointTeamIndices.begin())
			{
				for (int32 i = 0; i < _MultiBattlePlayers.size(); ++i)
				{
					if (_MultiBattlePlayers[i]->TeamIndex != t)
						continue;

					if (_MultiBattlePlayers[i]->BattleInfo.Point > BestPoint)
					{
						BestPoint = _MultiBattlePlayers[i]->BattleInfo.Point;
						BestPlayerIndices.clear();
						BestPlayerIndices.emplace(i);
					}
					else if (_MultiBattlePlayers[i]->BattleInfo.Point == BestPoint)
					{
						BestPlayerIndices.emplace(i);
					}
				}
			}
		}

		BattleRanking += (int32)it->second.size();
	}

	TRankingUsers RankingUsersChanged;
	vector<SBattleEndPlayer> BattleEndPlayers;
	BattleEndPlayers.reserve(_MultiBattlePlayers.size());
	TDoneQuestDBs DoneQuestDBs; // 디비쿼리를 한번에 하기위해 CUser, 또는 CBattlePlayer가 담당하지 않음.

	// Calculate Point
	vector<SBattleEndInfo> BattleEndInfos; // for DB Push
	BattleEndInfos.reserve(_MultiBattlePlayers.size());
	for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
	{
		auto& Me = _MultiBattlePlayers[i];
		auto& MyTeam = TeamEndInfos[Me->TeamIndex];

		int32 AddedGold = 0;
		int32 AddedPoint = 0;

		if (MyTeam.Point > 0)
		{
			auto& BattleReward = (_pBattleTypeInfo->BattleReward)[MyTeam.BattleRanking];

			AddedGold = BattleReward.Gold;
			AddedPoint = BattleReward.Points[(size_t)g_MetaData->GetRankTier(Me->GetPoint()).Rank];
		}

		BattleEndPlayers.emplace_back(SBattleEndPlayer(AddedPoint, AddedGold, Me->BattleInfo.Point));
	}

	if (IsOneOnOne())
	{
		for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
		{
			auto& Me = _MultiBattlePlayers[i];
			auto& MyTeam = TeamEndInfos[Me->TeamIndex];
			Me->QuestDone(EQuestType::SoloPlay, 1);

			if (MyTeam.IsWin(_BattleType.TeamCount))
			{
				Me->QuestDone(EQuestType::SoloVictory, 1);
				++Me->pPlayer->GetUserDB().WinCountSolo;
			}
			else
			{
				++Me->pPlayer->GetUserDB().LoseCountSolo;
			}
		}
	}

	// Battle End
	for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
	{
		BattleEndInfos.emplace_back(_MultiBattlePlayers[i]->BattleEnd(
			BattleEndPlayers,
			TeamEndInfos,
			BestPlayerIndices.find((int32)i) != BestPlayerIndices.end(), // Is BestPlayer
			DoneQuestDBs));

		int32 CharCode = _MultiBattlePlayers[i]->CharCode;

		if (IsValidRankingInfo() && BattleEndInfos[i].Point > g_RankingInfo.UserPointMin.UserPointMin)
			RankingUsersChanged.emplace_back(
				SRankingUser(
					SRankingUserCore(
						_MultiBattlePlayers[i]->Nick,
						CharCode,
						_MultiBattlePlayers[i]->CountryCode),
					BattleEndInfos[i].UID,
					BattleEndInfos[i].Point));
	}

	DBPush(CKey(), SBattleEndDBIn(BattleEndInfos, DoneQuestDBs));

	if (g_NetRankingKey && !RankingUsersChanged.empty())
		g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateMulti, RankingUsersChanged);
}
const vector<SMultiMap>& CMultiBattle::GetMaps(void) const
{
	return g_MetaData->MapMeta.OneOnOneMaps;
}
seconds CMultiBattle::GetPlaySeconds(void) const
{
	if (IsOneOnOne())
		return seconds(g_MetaData->ConfigMeta.BattleOneOnOneDurationSec);
	else
		return seconds(g_MetaData->ConfigMeta.BattleDurationSec);
}

vector<SCharacterNet> CMultiBattle::GetCharacters(void) const
{
	vector<SCharacterNet> Characters;

	for (auto& i : _MultiBattlePlayers)
		Characters.emplace_back(i->GetCharacterNet());

	return std::move(Characters);
}
vector<SStructMovePosition> CMultiBattle::GetStructMovePositions(void) const
{
	vector<SStructMovePosition> StructMovePositions;

	for (auto& i : _ShuttleStructures)
		StructMovePositions.emplace_back(i->GetStructMovePosition());

	return std::move(StructMovePositions);
}
SMultiBattleBeginNetSc CMultiBattle::GetBattleBeginNetSc(void) const
{
	vector<SBattlePlayer> Players;
	vector<SMultiBattleInfo> BattleInfos;

	for (auto& i : _MultiBattlePlayers)
	{
		Players.emplace_back(*i);
		BattleInfos.emplace_back(i->BattleInfo);
	}

	return SMultiBattleBeginNetSc(
		SBattle(
			_BattleType,
			_MapIndex),
		std::move(Players),
		std::move(BattleInfos),
		_BattleRecord,
		std::move(GetCharacters()),
		_EndTime,
		_pEngine->GetTick(),
		std::move(GetStructMovePositions()));
}
bool CMultiBattle::Update(void)
{
	if (!CBattle::Update())
		return false;

	auto Now = system_clock::now(); // ing   CMultiBattle 에서는 now() 대신 GetTickCount() 를 쓸것.

	if (_pEngine->IsStarted())
	{
		if (Now >= _EndTime)
			return false;
	}
	else
	{
		if (Now - _BeginTime >= milliseconds(c_BattleStartDelayMilliSec))
		{
			_pEngine->Start();
			_EndTime = Now + (g_Option.EndlessGame ? hours(9999999) : GetPlaySeconds());
			BroadCast(SMultiBattleStartNetSc(_EndTime));
		}
	}

	return true;
}
void CMultiBattle::OnLine(int32 PlayerIndex_)
{
	Send(PlayerIndex_, GetBattleBeginNetSc());
	BroadCastExcept(PlayerIndex_, SMultiBattleLinkNetSc(_pEngine->GetTick(), PlayerIndex_));
}
void CMultiBattle::OffLine(int32 PlayerIndex_)
{
	BroadCastExcept(PlayerIndex_, SMultiBattleUnLinkNetSc(_pEngine->GetTick(), PlayerIndex_));
}
void CMultiBattle::Link(int32 PlayerIndex_)
{
	_pEngine->Update();
	_MultiBattlePlayers[PlayerIndex_]->Link(_pEngine->GetTick());
	_pEngine->Send();
	BroadCast(SMultiBattleLinkNetSc(_pEngine->GetTick(), PlayerIndex_));
}
void CMultiBattle::UnLink(int32 PlayerIndex_)
{
	_pEngine->Update();
	_MultiBattlePlayers[PlayerIndex_]->UnLink(_pEngine->GetTick());
	_pEngine->Send();
	BroadCast(SMultiBattleUnLinkNetSc(_pEngine->GetTick(), PlayerIndex_));
}
void CMultiBattle::_SyncMessage(int64 Tick_)
{
	BroadCast(SBattleSyncNetSc(Tick_));
}
