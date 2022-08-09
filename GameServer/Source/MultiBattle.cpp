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
	if (_pEngine->GetTick() >= _EndTick && _pEngine->IsStarted())
		_pEngine->Stop();

	for (auto& i : _MultiBattlePlayers)
		i->CheckRegen(Tick_);
}
CMultiBattle::CMultiBattle(const SBattleType& BattleType_, const SBattleTypeInfo* pBattleTypeInfo_, const TMatch::element_type::TMatchedUsers& Users_, TBattlesIt itBattle_) :
	CBattle(BattleType_),
	_pBattleTypeInfo(pBattleTypeInfo_)
{
	// �Ƿ����� ����
	vector<CUser*> Users;
	std::transform(Users_.begin(), Users_.end(), std::back_inserter(Users), [](TPeerCnt PeerNum_) { return g_Users.get(PeerNum_); });
	std::sort(Users.begin(), Users.end(), [](const CUser* User0_, const CUser* User1_) { return User0_->GetPoint() < User1_->GetPoint(); });

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
		// ������ �Ƿ����� ���������Ƿ� ������׷� ���� �Ҵ��Ͽ� �������� �׻� �������� ������ ������
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
			this,
			Users[i]);

		pMultiBattlePlayer->pPlayerObject->SetParent(_pRootObject);
		_AddBattlePlayer(pMultiBattlePlayer);
	}

	_pEngine->fFixedUpdate = std::bind(&CMultiBattle::_FixedUpdate, this, _1);

	BroadCast(GetBattleBeginNetSc());
}
CMultiBattle::~CMultiBattle()
{
	auto Now = system_clock::now();

	if (_DisconnectedPlayerIndices.size() == _MultiBattlePlayers.size())
	{
		for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
			_MultiBattlePlayers[i]->BattleEndInvalid(Now);
	}
	else if (_DisconnectedPlayerIndex >= 0)
	{
		for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
		{
			if (i == _DisconnectedPlayerIndex)
				_MultiBattlePlayers[i]->BattleEndInvalidPunish();
			else
				_MultiBattlePlayers[i]->BattleEndInvalid(Now);
		}
	}
	else
	{
		// ���� ����
		// ������ 6 �̰� ������ ���� ��� : 1.0, 0.6, 0.2, -0.2, -0.6, -1.0
		// ������ 6 �̰� ������ ���� ��� : 1.0, 1.0, 0.2, -0.2, -0.6, -0.6


		// ������ ������ ���� Point�� �� ������ �ջ�
		vector<STeamBattleInfo> TeamBattleInfos(_BattleType.TeamCount); // TeamIndex�� �����ϱ����� ����
		for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
		{
			auto& TeamBattleInfo = TeamBattleInfos[_MultiBattlePlayers[i]->TeamIndex];
			TeamBattleInfo.Point += _MultiBattlePlayers[i]->BattleInfo.Point;
		}

		// ���� ���� �����ϵ� ������ ������ list�� �߰�
		map<int32, _STeamBattleInfo, greater<int32>> PointTeamIndexGroups; // Key : ��������,  Value : ���ε��� (�� ������ ����)
		for (size_t i = 0; i < TeamBattleInfos.size(); ++i)
		{
			auto& TeamBattleInfo = TeamBattleInfos[i];
			auto ib = PointTeamIndexGroups.emplace(TeamBattleInfo.Point, _STeamBattleInfo(&TeamBattleInfo));
			ib.first->second.TeamIndexGroup.emplace_back(i);
		}

		int32 BestPoint = -1;
		set<int32> BestPlayerIndices;
		int32 BattleRanking = 0;

		for (auto it = PointTeamIndexGroups.begin(); it != PointTeamIndexGroups.end(); ++it)
		{
			for (auto& TeamIndex : it->second.TeamIndexGroup)
			{
				auto& TeamBattleInfo = TeamBattleInfos[TeamIndex];
				TeamBattleInfo.Ranking = BattleRanking;

				// ���� ���� ���̸�(������, ���� ����) BestPlayer ����
				if (it == PointTeamIndexGroups.begin())
				{
					for (int32 i = 0; i < _MultiBattlePlayers.size(); ++i)
					{
						if (_MultiBattlePlayers[i]->TeamIndex != TeamIndex)
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

			BattleRanking += (int32)it->second.TeamIndexGroup.size();
		}

		TDoneQuestDBs DoneQuestDBs; // ��������� �ѹ��� �ϱ����� CUser, �Ǵ� CBattlePlayer�� ������� ����.

		bool IsDraw = PointTeamIndexGroups.size() == 1;
		if (IsDraw)
		{
			for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
			{
				auto& Me = _MultiBattlePlayers[i];

				_MultiBattlePlayers[i]->BattleEndDraw(
					Now,
					_BattleType,
					BestPlayerIndices.find((int32)i) != BestPlayerIndices.end(), // Is BestPlayer
					Me->BattleInfo.Point,
					DoneQuestDBs);
			}
		}
		else
		{
			vector<SBattleEndPlayer> BattleEndPlayers;
			BattleEndPlayers.reserve(_MultiBattlePlayers.size());

			// Calculate Point
			for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
			{
				auto& Me = _MultiBattlePlayers[i];
				auto& MyTeam = TeamBattleInfos[Me->TeamIndex];

				int32 AddedGold = 0;
				int32 AddedPoint = 0;

				if (MyTeam.Point > 0)
				{
					auto& BattleReward = (_pBattleTypeInfo->BattleReward)[MyTeam.Ranking];

					AddedGold = BattleReward.Gold;
					AddedPoint = BattleReward.Points[(size_t)g_MetaData->RankTiers.get(Me->GetPoint())->second.Rank];
				}

				BattleEndPlayers.emplace_back(SBattleEndPlayer(AddedPoint, AddedGold, Me->BattleInfo.Point));
			}

			vector<STeamRanking> OrderedTeamRankings;
			for (auto& i : PointTeamIndexGroups)
				OrderedTeamRankings.emplace_back(STeamRanking(STeamBattleInfo(i.second.pTeamBattleInfo->Ranking, i.first), i.second.TeamIndexGroup));

			auto& FirstTeamIndexGroup = OrderedTeamRankings[0].TeamIndexGroup;

			for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
			{
				auto MyTeamIndex = _MultiBattlePlayers[i]->TeamIndex;

				_MultiBattlePlayers[i]->BattleEnd(
					Now,
					_BattleType,
					BestPlayerIndices.find((int32)i) != BestPlayerIndices.end(), // Is BestPlayer
					BattleEndPlayers,
					OrderedTeamRankings,
					std::find(FirstTeamIndexGroup.begin(), FirstTeamIndexGroup.end(), MyTeamIndex) != FirstTeamIndexGroup.end(),
					DoneQuestDBs);
			}
		}

		vector<SBattleEndInfo> BattleEndInfos; // for DB Push
		BattleEndInfos.reserve(_MultiBattlePlayers.size());
		for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
			BattleEndInfos.emplace_back(_MultiBattlePlayers[i]->pPlayer->GetSBattleEndInfo());

		DBPush(CKey(), SBattleEndDBIn(BattleEndInfos, DoneQuestDBs));


		// Ranking /////////////////////////////////////
		if (!IsDraw)
		{
			TRankingUsers RankingUsersChanged;

			for (size_t i = 0; i < _MultiBattlePlayers.size(); ++i)
			{
				int32 CharCode = _MultiBattlePlayers[i]->CharCode;

				if (IsValidRankingInfo() && BattleEndInfos[i].Point > g_RankingInfo.UserPointMinArray[(size_t)ERankingType::Multi])
					RankingUsersChanged.emplace_back(
						SRankingUser(
							BattleEndInfos[i].UID,
							_MultiBattlePlayers[i]->Nick,
							CharCode,
							_MultiBattlePlayers[i]->CountryCode,
							BattleEndInfos[i].Point));
			}

			if (g_NetRankingKey && !RankingUsersChanged.empty())
				g_NetRanking->Send(g_NetRankingKey.PeerNum, (int32)EProtoRankingNetSr::UpdateMulti, SRankingUpdateMultiNetSr(std::move(RankingUsersChanged)));
		}
	}

	for (auto& i : _MultiBattlePlayers)
		i->BattleEndSession();
}
bool CMultiBattle::_CanEngineStart(void) const
{
	return _IsStarted && _DisconnectedPlayerIndices.empty();
}
const vector<SMultiMap>& CMultiBattle::GetMaps(void) const
{
	return g_MetaData->MapMeta.OneOnOneMaps;
}
int64 CMultiBattle::GetPlayTicks(void) const
{
	if (IsOneOnOneBattle(_BattleType))
		return duration_cast<t_duration>(seconds(g_MetaData->ConfigMeta.BattleOneOnOneDurationSec)).count();
	else
		return duration_cast<t_duration>(seconds(g_MetaData->ConfigMeta.BattleDurationSec)).count();
}

vector<SCharacterNet> CMultiBattle::GetCharacters(void) const
{
	vector<SCharacterNet> Characters;

	for (auto& i : _MultiBattlePlayers)
		Characters.emplace_back(i->GetCharacterNet());

	return Characters;
}
vector<SStructMovePosition> CMultiBattle::GetStructMovePositions(void) const
{
	vector<SStructMovePosition> StructMovePositions;

	for (auto& i : _ShuttleStructures)
		StructMovePositions.emplace_back(i->GetStructMovePosition());

	return StructMovePositions;
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

	map<int32, system_clock::time_point> DisconnectEndTimes;
	for (auto& i : _DisconnectedPlayerIndices)
		DisconnectEndTimes.emplace(i, _MultiBattlePlayers[i]->DisconnectEndTime);

	return SMultiBattleBeginNetSc(
		SBattle(
			_BattleType,
			_MapIndex),
		std::move(Players),
		std::move(DisconnectEndTimes),
		std::move(BattleInfos),
		_BattleRecord,
		std::move(GetCharacters()),
		_EndTick,
		_pEngine->GetTick(),
		std::move(GetStructMovePositions()));
}
bool CMultiBattle::Update(void)
{
	if (!CBattle::Update())
		return false;

	auto Now = system_clock::now(); // ing   CMultiBattle ������ now() ��� GetTickCount() �� ����.

	if (!_IsStarted)
	{
		if (Now - _BeginTime >= milliseconds(c_BattleStartDelayMilliSec))
		{
			_IsStarted = true;
			_CheckAndStartEngine();
			_EndTick = (g_Option.EndlessGame ? (numeric_limits<int64>::max)() : GetPlayTicks());
			BroadCast(SMultiBattleStartNetSc(_EndTick));
		}
	}
	else if (_pEngine->GetTick() >= _EndTick)
	{
		return false;
	}

	// ��� ��������
	if (_DisconnectedPlayerIndices.size() == _MultiBattlePlayers.size())
		return false;

	for (auto& i : _DisconnectedPlayerIndices)
	{
		if (Now >= _MultiBattlePlayers[i]->DisconnectEndTime)
		{
			_DisconnectedPlayerIndex = i;
			return false;
		}
	}

	return true;
}
void CMultiBattle::Link(int32 PlayerIndex_)
{
	_DisconnectedPlayerIndices.erase(PlayerIndex_);
	_pEngine->Update();
	_CheckAndStartEngine();
	Send(PlayerIndex_, GetBattleBeginNetSc());
	// _pEngine->Send(); �� SMultiBattleUnLinkNetSc ������ �� ȣ���Ͽ���, ���ķ� Tick�� �帣�� �ʾ����Ƿ� ���⼭ ȣ���� �ʿ� ����.

	BroadCastExcept(PlayerIndex_, SMultiBattleLinkNetSc(_pEngine->GetTick(), PlayerIndex_));
}
void CMultiBattle::UnLink(int32 PlayerIndex_)
{
	_DisconnectedPlayerIndices.emplace(PlayerIndex_);
	_pEngine->Update();

	// ���� UnLink �� �÷��̾���
	if (_DisconnectedPlayerIndices.size() == 1)
	{
		_pEngine->Send();
		_pEngine->Stop();
	}

	// ������ �������� _MultiBattlePlayers �� ���� ������� �����Ǵ� ���� �ƴϹǷ� BroadCastExcept �� ȣ���Ͽ� ���ʿ��� Send ȣ�� ���ϵ���
	BroadCastExcept(PlayerIndex_, SMultiBattleUnLinkNetSc(_pEngine->GetTick(), PlayerIndex_, _MultiBattlePlayers[PlayerIndex_]->DisconnectEndTime));
}
