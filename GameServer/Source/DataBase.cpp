#include "stdafx.h"

// Coupon DB ///////////////////////////////////////////////////
void CouponDBOut(TOutObject& OutObject_)
{
	auto User = GetUser(OutObject_.Key);
	if (!User)
		return; // 유저가 없을경우 유저는 로그인 후 재 처리하면 됨

	try
	{
		SCouponUseCouponDBIn In;
		OutObject_.InStream >> In;

		int32 Code = 0;
		OutObject_.InStream >> Code;

		if (OutObject_.Ret != 0)
			throw ERet::SPError;

		if (OutObject_.SPRet != 0)
		{
			if (OutObject_.SPRet == 60000)
				User->Send(SCouponUseFailNetSc(ERet::CouponAlreadyUsed));
			else if (OutObject_.SPRet == 60001 || OutObject_.SPRet == 60002)
				User->Send(SCouponUseFailNetSc(ERet::CouponAlreadyUsed));
			else
				throw ERet::SPError;

			User->WillClose();
			return;
		}

		User->CouponUseOut(In, Code);
	}
	catch (ERet Ret_)
	{
		SendRet(OutObject_.Key, Ret_);
		WillClose(OutObject_.Key);
	}
	catch (...)
	{
		SendRet(OutObject_.Key, ERet::SPError);
		WillClose(OutObject_.Key);
	}
}

// Game DB ///////////////////////////////////////////////////
void DummyDBOut(TSessionsIt itSession_, TOutObject& OutObject_)
{
	try
	{
		if (OutObject_.Ret != 0 || OutObject_.SPRet != 0)
			throw 0;
	}
	catch (...)
	{
		SendRet(OutObject_.Key, ERet::SPError);
		WillClose(OutObject_.Key);
	}
}
void JoinDBOut(TSessionsIt itSession_, TOutObject& OutObject_)
{
	auto User = GetUser(OutObject_.Key);
	if (!User)
		return;

	try
	{
		SJoinDBIn In;
		SLoginDBOut Out;

		_DBResultProc(EProtoNetCs::Null, OutObject_, In, Out);
		User->SetJoinDBOut(Out);
	}
	catch (ERet Ret_)
	{
		SendRet(OutObject_.Key, Ret_);
		WillClose(OutObject_.Key);
	}
	catch (...)
	{
		SendRet(OutObject_.Key, ERet::SPError);
		WillClose(OutObject_.Key);
	}
}
void LoginDBOut(TSessionsIt itSession_, TOutObject& OutObject_)
{
	auto User = GetUser(OutObject_.Key);
	if (!User)
		throw 0;

	try
	{
		SLoginDBIn In;
		SLoginDBOut Out;

		_DBResultProc(EProtoNetCs::Null, OutObject_, In, Out);
		User->SetLoginDBOut(Out);
	}
	catch (ERet Ret_)
	{
		SendRet(OutObject_.Key, Ret_);
		WillClose(OutObject_.Key);
	}
	catch (const int&)
	{
		WillClose(OutObject_.Key);
	}
	catch (...)
	{
		SendRet(OutObject_.Key, ERet::SPError);
		WillClose(OutObject_.Key);
	}
}
void CheckIDDBOut(TSessionsIt itSession_, TOutObject& OutObject_)
{
	SCheckIDDBIn In;
	OutObject_.InStream >> In;

	TSessionCode SessionCode = 0;
	OutObject_.InStream >> SessionCode; // 쿼리 당시 SessionCode

	SCheckIDNetSc Out;
	OutObject_.OutStream >> Out;

	try
	{
		if (OutObject_.Ret != 0 || OutObject_.SPRet != 0)
			throw ERet::SPError;

		g_Net->SendCheck(itSession_, SessionCode, (CStream() << int32(ERet::Ok) << Out));
	}
	catch (ERet Ret_)
	{
		g_Net->SendCheck(itSession_, SessionCode, (CStream() << int32(Ret_)));
	}
}
void ChangeNickBeginDBOut(TSessionsIt itSession_, TOutObject& OutObject_)
{
	auto User = GetUser(OutObject_.Key);
	if (!User)
		return;

	try
	{
		SChangeNickBeginDBIn In;
		OutObject_.InStream >> In;

		if (OutObject_.Ret != 0 || OutObject_.SPRet != 0)
			throw ERet::SPError;

		User->ChangeNickBeginDB();
	}
	catch (...)
	{
		SendRet(OutObject_.Key, ERet::SPError);
		WillClose(OutObject_.Key);
	}
}
void ChangeNickEndDBOut(TSessionsIt itSession_, TOutObject& OutObject_)
{
	auto User = GetUser(OutObject_.Key);
	if (!User)
		return;

	try
	{
		SChangeNickEndDBIn In;
		OutObject_.InStream >> In;

		if (OutObject_.Ret != 0 || OutObject_.SPRet != 0)
			throw ERet::SPError;

		User->ChangeNickEndDB();
	}
	catch (...)
	{
		SendRet(OutObject_.Key, ERet::SPError);
		WillClose(OutObject_.Key);
	}
}
void ChangeNickEndFailDBOut(TSessionsIt itSession_, TOutObject& OutObject_)
{
	auto User = GetUser(OutObject_.Key);
	if (!User)
		return;

	try
	{
		SChangeNickEndFailDBIn In;
		OutObject_.InStream >> In;

		EGameRet GameRet;
		OutObject_.InStream >> GameRet;

		if (OutObject_.Ret != 0 || OutObject_.SPRet != 0)
			throw ERet::SPError;

		User->ChangeNickEndFailDB(GameRet);
	}
	catch (...)
	{
		SendRet(OutObject_.Key, ERet::SPError);
		WillClose(OutObject_.Key);
	}
}
