#pragma once

template<typename _TIn, typename _TOut>
void _DBResultProc(EProtoNetCs CsProto_, TOutObject& OutObject_, _TIn& In_, _TOut& Out_)
{
	OutObject_.InStream >> In_;
	OutObject_.OutStream >> Out_;

	if (OutObject_.Ret != 0 || OutObject_.SPRet != 0)
		throw ERet::SPError;
}

void CouponDBOut(TOutObject& OutObject_);

void DummyDBOut(TSessionsIt itSession_, TOutObject& OutObject_);
void JoinDBOut(TSessionsIt itSession_, TOutObject& OutObject_);
void LoginDBOut(TSessionsIt itSession_, TOutObject& OutObject_);
void CheckIDDBOut(TSessionsIt itSession_, TOutObject& OutObject_);
void PurchaseDBOut(TSessionsIt itSession_, TOutObject& OutObject_);
void ChangeNickBeginDBOut(TSessionsIt itSession_, TOutObject& OutObject_);
void ChangeNickEndDBOut(TSessionsIt itSession_, TOutObject& OutObject_);
void ChangeNickEndFailDBOut(TSessionsIt itSession_, TOutObject& OutObject_);
