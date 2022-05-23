#pragma once

class CUsers
{
	using _Pairib = pair<shared_ptr<CUser>, bool>;
	using _TUser = shared_ptr<CUser>;
	struct _SUserUID
	{
		bool InBattle = false;
		_TUser User;

		_SUserUID(bool InBattle_, _TUser&& User_) :
			InBattle(InBattle_), User(std::move(User_))
		{
		}
	};
	using _TUsersUID = map<TUID, _SUserUID>;
	using _TUsers = CList<_TUsersUID::iterator>;

	_TUsersUID _UsersUID;
	_TUsers _Users;

public:
	void login(TSessionsIt itSession_, const CKey& Key_, const SUserCreateOption& CreateOption_, const CIPInfo::SCountryCodeMinuteOffset& CountryCodeMinuteOffset_);
	tuple<int, int> logout(TPeerCnt PeerNum_);
	void battle_begin(TPeerCnt PeerNum_);
	void battle_end(TUID UID_);
	CUser* get(TPeerCnt PeerNum_);
	CUser* get_with_uid(TUID UID_);
	size_t size(void) const;
	_TUsers& get_users(void);
};
