#include "stdafx.h"
#include <GameServer/Common/MetaProtocol.h>

void FCMTokenSetNetSm(const CKey& Key_, CStream& Stream_)
{
	if (!g_FCM)
		return;

	try
	{
		SFCMTokenSetNetSm Proto;
		Stream_ >> Proto;
		g_FCM->SetUser(Proto.UID, WCSToMBS(Proto.Token), minutes(Proto.MinuteOffset));
	}
	catch (...)
	{
	}
}
void FCMTokenUnsetNetSm(const CKey& Key_, CStream& Stream_)
{
	if (!g_FCM)
		return;

	try
	{
		SFCMTokenUnsetNetSm Proto;
		Stream_ >> Proto;
		g_FCM->DelUser(Proto.UID);
	}
	catch (...)
	{
	}
}
void FCMCanPushAtNightNetSm(const CKey& Key_, CStream& Stream_)
{
	if (!g_FCM)
		return;

	try
	{
		SFCMCanPushAtNightNetSm Proto;
		Stream_ >> Proto;
		g_FCM->ChangeUser(Proto.UID, Proto.CanPush);
	}
	catch (...)
	{
	}
}
