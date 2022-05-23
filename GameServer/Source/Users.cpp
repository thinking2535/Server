#include "stdafx.h"

void CUsers::login(TSessionsIt itSession_, const CKey& Key_, const SUserCreateOption& CreateOption_, const CIPInfo::SCountryCodeMinuteOffset& CountryCodeMinuteOffset_)
{
	auto itUser = _UsersUID.find(itSession_->first);
	if (itUser == _UsersUID.end())
	{
		auto ib = _UsersUID.emplace(itSession_->first, _SUserUID(false, _TUser(new CUser(itSession_))));
		if (!ib.second)
			throw 0;

		try
		{
			auto it = _Users.emplace_at(Key_.PeerNum, ib.first);
			if (!it)
				throw 0;

			(*it)->second.User->Login(CreateOption_.Language, SUserLoginInfo(Key_, CreateOption_.LoginOption, CountryCodeMinuteOffset_));
		}
		catch (...)
		{
			_UsersUID.erase(ib.first);

			throw 0;
		}
	}
	else
	{
		auto it = _Users.emplace_at(Key_.PeerNum, itUser);
		if (!it)
			throw 0;

		itUser->second.User->LoginAfterBattle(SUserLoginInfo(Key_, CreateOption_.LoginOption, CountryCodeMinuteOffset_));
	}
}
tuple<int, int> CUsers::logout(TPeerCnt PeerNum_)
{
	tuple<int, int> BattleIndexForEnd = make_tuple(-1,-1);
	auto it = _Users.get(PeerNum_);
	if (!it)
		return BattleIndexForEnd;

	BattleIndexForEnd = (*it)->second.User->Logout();

	if (!(*it)->second.InBattle)
		_UsersUID.erase(*it);

	_Users.erase(it);
	return BattleIndexForEnd;
}
void CUsers::battle_begin(TPeerCnt PeerNum_)
{
	_Users[PeerNum_]->second.InBattle = true;
}
void CUsers::battle_end(TUID UID_)
{
	auto it = _UsersUID.find(UID_);
	if (it == _UsersUID.end())
		return;

	if (it->second.User->Key())
		it->second.InBattle = false;
	else
		_UsersUID.erase(it);
}
CUser* CUsers::get(TPeerCnt PeerNum_)
{
	auto it = _Users.get(PeerNum_);
	if (!it)
		return nullptr;

	return (*it)->second.User.get();
}
CUser* CUsers::get_with_uid(TUID UID_)
{
	auto it = _UsersUID.find(UID_);
	if (it == _UsersUID.end())
		return nullptr;

	return it->second.User.get();
}
size_t CUsers::size(void) const
{
	return _Users.size();
}
CUsers::_TUsers& CUsers::get_users(void)
{
	return _Users;
}