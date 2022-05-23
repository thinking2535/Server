#pragma once

class CRoom
{
public:
	EGameMode Mode;
	map<TUID, CKey> Users;
	CKey MasterUserKey;
	TUID MasterUserID;
	u16string MasterUser;
	wstring Password;
	int RoomIdx;
	TTime DelayTime;
	ERoomState State = ERoomState::RoomWait;
	int EndRoomWaitUser = 0;
	int RoomUserCount = 0;

	CRoom(EGameMode Mode_, CUser* User_, wstring Password_, int RoomIdx_);
	~CRoom();

	template<typename _TProto>
	void RoomSend(const _TProto& Proto_)
	{
		for (auto& i : Users)
		{
			GetUser(i.second)->Send(Proto_);
		}
	}

	bool JoinRoom(CUser* User_);
	bool OutRoom(CUser* User_);
	void ChatRoom(CUser* User_, wstring Chat_);
	void StartGame();
	void EndGame();
	bool Proc();
};
