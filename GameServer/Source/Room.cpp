#include "stdafx.h"

CRoom::CRoom(EGameMode Mode_, CUser* User_, wstring Password_, int RoomIdx_) :
	Mode(Mode_),
	Password(Password_),
	RoomIdx(RoomIdx_),
	State(ERoomState::RoomWait)
{
	MasterUserKey = User_->GetKey();
	MasterUserID = User_->GetUID();
	MasterUser = User_->GetNick();
	Users.emplace(User_->GetUID(), User_->GetKey());
	RoomUserCount = 1;
}

CRoom::~CRoom()
{
}

bool CRoom::JoinRoom(CUser* User_)
{
	if (State == ERoomState::RoomAllReady || State == ERoomState::RoomPlay) return false;
	if (State != ERoomState::RoomEndWait)
	{
		switch (Mode)
		{
		case EGameMode::Solo:
		case EGameMode::DodgeSolo:
		case EGameMode::IslandSolo:
			if (Users.size() >= 2) return false;
			break;
		case EGameMode::SurvivalSmall:
			if (Users.size() >= 3) return false;
			break;
		case EGameMode::TeamSmall:
			if (Users.size() >= 4) return false;
			break;
		case EGameMode::Team:
		case EGameMode::Survival:
			if (Users.size() >= 6) return false;
			break;
		}
		Users.emplace(User_->GetUID(), User_->GetKey());
		RoomUserCount = Users.size();
		EndRoomWaitUser = RoomUserCount;
	}
	else
	{
		auto& user = Users.find(User_->GetUID());
		if (user == Users.end())
			Users.emplace(User_->GetUID(), User_->GetKey());
		else
			user->second = User_->GetKey();

		EndRoomWaitUser++;
	}
	switch (Mode)
	{
	case EGameMode::Solo:
	case EGameMode::DodgeSolo:
	case EGameMode::IslandSolo:
		if (EndRoomWaitUser == 2) State = ERoomState::RoomAllReady;
		break;
	case EGameMode::SurvivalSmall:
		if (EndRoomWaitUser == 3) State = ERoomState::RoomAllReady;
		break;
	case EGameMode::TeamSmall:
		if (EndRoomWaitUser == 4) State = ERoomState::RoomAllReady;
		break;
	case EGameMode::Team:
	case EGameMode::Survival:
		if (EndRoomWaitUser == 6) State = ERoomState::RoomAllReady;
		break;
	}
	if (State == ERoomState::RoomAllReady)
	{
		DelayTime = system_clock::now();
	}
	return true;
}

bool CRoom::OutRoom(CUser* User_)
{
	if (State == ERoomState::RoomAllReady || State == ERoomState::RoomPlay)
		return false;

	Users.erase(User_->GetUID());
	RoomUserCount = Users.size();
	if (Users.size() > 0)
	{
		if (User_->GetUID() == MasterUserID)
		{
			auto& NewMasterUser = Users.begin();
			MasterUserID = NewMasterUser->first;
			MasterUserKey = NewMasterUser->second;
			MasterUser = GetUser(NewMasterUser->second)->GetNick();
		}
	}
	if (State == ERoomState::RoomEndWait)
	{
		State = ERoomState::RoomWait;
	}
	return true;
}

void CRoom::ChatRoom(CUser* User_, wstring Chat_)
{
	RoomBroadCast(RoomIdx, SRoomChatNetSc(User_->GetNick(), Chat_));
}

void CRoom::StartGame()
{
	const SBattleTypeInfo* info = nullptr;
	for (auto& i : g_GameData->GetBattleTypeInfos())
	{
		if (i.first == Mode)
			info = &i.second;
	}
	if (info == nullptr) return;
	bool IsOutUser = false;
	for (auto it = Users.begin(); it != Users.end(); )
	{
		auto itCheck = it;
		++it;

		auto* User = GetUser(itCheck->second);
		if (User == nullptr)
		{
			IsOutUser = true;
			TUID UserId = itCheck->first;
			Users.erase(itCheck);
			if (UserId == MasterUserID)
			{
				auto& NewMasterUser = Users.begin();
				MasterUserID = NewMasterUser->first;
				MasterUserKey = NewMasterUser->second;
				MasterUser = GetUser(NewMasterUser->second)->GetNick();
			}
		}
	}
	if (IsOutUser)
	{
		State = ERoomState::RoomWait;
		BroadCast(SRoomChangeNetSc(RoomIdx, SRoomInfo(Mode, RoomIdx, MasterUserID, MasterUser, Password, RoomUserCount, State), true));
	}
	else
	{
		TMatch::element_type::TMatchedUsers MatchedUsers;
		for (auto& i : Users)
		{
			MatchedUsers.emplace_back(i.second.PeerNum);
		}
		if (Mode == EGameMode::IslandSolo || Mode == EGameMode::DodgeSolo)
			g_SingleBattles.emplace(info->BattleType, info, MatchedUsers, (TPeerCnt)g_SingleBattles.new_index(), RoomIdx);
		else
			g_Battles.emplace(info->BattleType, info, MatchedUsers, (TPeerCnt)g_Battles.new_index(), RoomIdx);
	}
}

void CRoom::EndGame()
{
	EndRoomWaitUser = 0;
	bool IsOutUser = false;
	std::vector<TUID> vecUID;
	for (auto it = Users.begin(); it != Users.end(); )
	{
		auto itCheck = it;
		++it;

		auto* User = GetUser(itCheck->second);
		if (User == nullptr)
		{
			IsOutUser = true;
			Users.erase(itCheck);
		}
	}

	RoomUserCount = Users.size();
	if (RoomUserCount > 0)
	{
		if (!IsOutUser)
			State = ERoomState::RoomEndWait;
		else
		{
			State = ERoomState::RoomWait;
			auto& NewMasterUser = Users.begin();
			MasterUserID = NewMasterUser->first;
			MasterUserKey = NewMasterUser->second;
			MasterUser = GetUser(NewMasterUser->second)->GetNick();
		}
	}
	else
		State = ERoomState::RoomWait;
}

bool CRoom::Proc()
{
	if (State == ERoomState::RoomAllReady)
	{
		std::chrono::seconds time = std::chrono::duration_cast<std::chrono::seconds>(system_clock::now() - DelayTime);
		if (time.count() >= 3)
		{
			State = ERoomState::RoomPlay;
			StartGame();
		}
	}
	if (State == ERoomState::RoomWait)
	{
		if (RoomUserCount <= 0)
		{
			return false;
		}
	}
	return true;
}
