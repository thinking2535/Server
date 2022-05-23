#include "stdafx.h"

void CPhysicsEngine::_HitCallback(const CEnginePlayer& Attacker_, const CEnginePlayer& Target_)
{
	int32 AddedPoint = 0;

	if (Target_.IsAlive()) // Hit Balloon
	{
		++_BattleRecord.TotalBalloonHitCount;

		if (_BattleRecord.TotalBalloonHitCount == 1)
			AddedPoint = g_GameData->ConfigMeta.FirstBalloonHitPoint;
		else
			AddedPoint = g_GameData->ConfigMeta.BalloonHitPoint;
	}
	else // Kill
	{
		++_BattleRecord.TotalKillCount;
		AddedPoint = g_GameData->ConfigMeta.ParachuteHitPoint;
	}

	_fHit(Attacker_.GetPlayerIndex(), Target_.GetPlayerIndex(), AddedPoint);
}
void CPhysicsEngine::_RegenCallback(const CEnginePlayer& Player_)
{
	_fRegen(Player_.GetPlayerIndex(), *Player_.Character());
}
void CPhysicsEngine::_GetItemCallback(const CEnginePlayer& Player_, int32 ItemCode_)
{
	_fGetItem(Player_.GetPlayerIndex(), ItemCode_);
}
CPhysicsEngine::CPhysicsEngine(
	const CEngineGameMode* pGameMode_,
	FHit fHit_,
	FRegen fRegen_,
	FGetItem fGetItem_,
	int64 CurTick_,
	SBattleRecord BattleRecord_,
	const SPoint& PropPosition_,
	const list<SStructure>& Structures_,
	const list<SStructureMove>& StructureMoves_,
	const TPoses& PlayerPoses_,
	const vector<const SCharacterMeta*>& Metas_,
	const vector<int8>& TeamIndices_,
	vector<unique_ptr<SCharacter>>&& Characters_,
	vector<CBattlePlayer*> BattlePlayers_,
	CServerEngine::FSyncMessage fSyncMessage_) :
		_pGameMode(pGameMode_),
		_fHit(fHit_),
		_fRegen(fRegen_),
		_fGetItem(fGetItem_),
		_BattleRecord(BattleRecord_),
		_PlayerPoses(PlayerPoses_)
{
	list<unique_ptr<CCollider2D>> StructureColliders;
	for (auto& s : Structures_)
		StructureColliders.emplace_back(make_unique<CRectCollider2D>(s.LocalPosition, CEngineGlobal::c_StructureNumber, s));


	_pRootObject = make_unique<CObject2D>(PropPosition_);

	// Moving Structures //////////////////////////
	list<unique_ptr<CMovingObject2D>> MovingStructures;

	for (auto& s : StructureMoves_)
	{
		list<unique_ptr<CCollider2D>> Colliders;
		for (auto& c : s.Colliders)
			Colliders.emplace_back(make_unique<CRectCollider2D>(SPoint(), CEngineGlobal::c_StructureNumber, c));

		auto pShuttleObject = make_unique<CShuttleObject2D>(
			s.BeginPos,
			make_unique<CCollectionCollider2D>(SPoint(), CEngineGlobal::c_ContainerNumber, std::move(Colliders)),
			s.BeginPos,
			s.EndPos,
			s.Velocity,
			s.Delay,
			SStructMove(true, 1, 0.0f));
		pShuttleObject->SetParent(_pRootObject.get());
		_ShuttleStructures.emplace_back(pShuttleObject.get());
		MovingStructures.emplace_back(std::move(pShuttleObject));
	}


	// Players ////////////////////////////
	vector<unique_ptr<CPlayerObject2D>> Players;
	Players.reserve(Metas_.size());
	for (int32 i = 0; i < Metas_.size(); ++i)
	{
		auto pMeta = Metas_[i];
		auto TeamIndex = TeamIndices_[i];
		auto pCharacter = std::move(Characters_[i]);

		auto pPlayer = CEngineGlobal::GetEnginePlayer(
			std::bind(&CPhysicsEngine::_HitCallback, this, _1, _2),
			std::bind(&CPhysicsEngine::_RegenCallback, this, _1),
			std::bind(&CPhysicsEngine::_GetItemCallback, this, _1, _2),
			i,
			_PlayerPoses[i],
			pMeta,
			TeamIndex,
			std::move(pCharacter),
			BattlePlayers_[i]
		);

		_EnginePlayers.emplace_back(pPlayer.get());
		Players.emplace_back(std::move(pPlayer));
	}

	// Engine ////////////////////////////
	_pEngine = make_unique<CServerEngine>(
		c_NetworkTickSync,
		CurTick_,
		c_ContactOffset,
		c_FPS,
		make_unique<CCollectionCollider2D>(PropPosition_, CEngineGlobal::c_ContainerNumber, std::move(StructureColliders)),
		std::move(MovingStructures),
		std::move(Players),
		fSyncMessage_);

	_pEngine->OnFixedUpdate = std::bind(&CPhysicsEngine::_FixedUpdate, this, _1);
}
vector<SCharacterNet> CPhysicsEngine::GetCharacters(void) const
{
	vector<SCharacterNet> Characters;

	for (auto& i : _EnginePlayers)
		Characters.emplace_back(i->GetCharacterNet());

	return std::move(Characters);
}
vector<SStructMovePosition> CPhysicsEngine::GetStructMovePositions(void) const
{
	vector<SStructMovePosition> StructMovePositions;

	for (auto& i : _ShuttleStructures)
		StructMovePositions.emplace_back(i->GetStructMovePosition());

	return std::move(StructMovePositions);
}

bool CPhysicsEngine::Touch(int32 PlayerIndex_, int8 Dir_)
{
	_pEngine->Update();
	if (!_EnginePlayers[PlayerIndex_]->Touch(Dir_))
		return false;

	_pEngine->Send();
	return true;
}
bool CPhysicsEngine::Push(int32 PlayerIndex_)
{
	_pEngine->Update();
	if (!_EnginePlayers[PlayerIndex_]->Push(_pEngine->GetTick()))
		return false;

	_pEngine->Send();
	return true;
}
void CPhysicsEngine::Link(int32 PlayerIndex_)
{
	_pEngine->Update();
	_EnginePlayers[PlayerIndex_]->Link(_pEngine->GetTick());
	_pEngine->Send();
}
void CPhysicsEngine::UnLink(int32 PlayerIndex_)
{
	_pEngine->Update();
	_EnginePlayers[PlayerIndex_]->UnLink(_pEngine->GetTick());
	_pEngine->Send();
}
void CPhysicsEngine::Update(void)
{
	_pEngine->UpdateAndSyncMessage();
}
void CPhysicsEngine::_FixedUpdate(int64 Tick_)
{
	for (auto& i : _EnginePlayers)
	{
		i->CheckRegen(Tick_);
		_pGameMode->FixPos(i->LocalPosition);
	}
}

