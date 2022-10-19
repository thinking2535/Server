#include "stdafx.h"

CEnginePumpControl::CEnginePumpControl(FPump fPump_, FPumpDone fPumpDone_, float PumpSpeed_, SPumpInfo& PumpInfo_) :
    _fPump(fPump_),
    _fPumpDone(fPumpDone_),
    _PumpSpeed(PumpSpeed_ / c_PumpCountForBalloon),
    _PumpInfo(PumpInfo_)
{
    _SetScaleTo();
}
void CEnginePumpControl::_Pump(void)
{
    _SetScaleTo();
    _fPump();
}
bool CEnginePumpControl::canPump()
{
    return _PumpInfo.CountTo < c_PumpCountForBalloon&& _PumpInfo.CountTo - _PumpInfo.Count <= 1;
}
void CEnginePumpControl::pump()
{
    if (!CEngineGlobal::IsScaling(_PumpInfo))
        _Pump();

    ++_PumpInfo.CountTo;
}
void CEnginePumpControl::FixedUpdate(void)
{
    if (!CEngineGlobal::IsScaling(_PumpInfo))
        return;

    _PumpInfo.Scale += (_PumpSpeed * CEngine::GetDeltaTime());

    if (_PumpInfo.Scale < _ScaleTo)
        return;

    ++_PumpInfo.Count;

    if (CEngineGlobal::IsScaling(_PumpInfo))
    {
        _Pump();
        return;
    }
    else if (_PumpInfo.Count >= c_PumpCountForBalloon)
    {
        Clear();
        _fPumpDone();
    }
}
void CEnginePumpControl::Clear(void)
{
    _PumpInfo.Count = 0;
    _PumpInfo.CountTo = 0;
    _PumpInfo.Scale = 0.0f;
    _ScaleTo = 0.0f;
}
