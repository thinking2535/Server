#include "stdafx.h"

void MessageNetSs(TSessionsIt itSession_, CStream& Stream_)
{
	SMsgNetSc Proto;
	Stream_ >> Proto;

	auto User = g_Users.get_with_uid(itSession_->first);
	if (User)
		User->Send(Proto);
}
