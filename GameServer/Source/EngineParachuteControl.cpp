#include "stdafx.h"

CEngineParachuteControl::CEngineParachuteControl(FOn fOn_, SParachuteInfo& ParachuteInfo_) :
    _fOn(fOn_),
    _ParachuteInfo(ParachuteInfo_)
{
}
void CEngineParachuteControl::On(void)
{
    if (_ParachuteInfo.Velocity > 0.0f ||
        (_ParachuteInfo.Velocity == 0.0f && _ParachuteInfo.Scale >= c_ParachuteLocalScale))
        return;

    if (_ParachuteInfo.Scale < c_ParachuteLocalScale)
    {
        _ParachuteInfo.Velocity = c_Velocity;

        if (_ParachuteInfo.Scale <= 0.0f)
            _fOn(true);
    }
    else // _ParachuteInfo.Scale == c_ParachuteLocalScale
    {
        _ParachuteInfo.Velocity = 0.0f;
    }
}
void CEngineParachuteControl::Off(void)
{
    if (_ParachuteInfo.Velocity < 0.0f ||
        (_ParachuteInfo.Velocity == 0.0f && _ParachuteInfo.Scale <= 0.0f))
        return;

    if (_ParachuteInfo.Scale > 0.0f)
    {
        _ParachuteInfo.Velocity = -c_Velocity;
    }
    else // _ParachuteInfo.Scale == 0.0f
    {
        _ParachuteInfo.Velocity = 0.0f;
        _fOn(false);
    }
}
bool CEngineParachuteControl::FixedUpdate(void)
{
    if (_ParachuteInfo.Velocity == 0.0f)
        return false;

    _ParachuteInfo.Scale += (_ParachuteInfo.Velocity * CEngine::GetDeltaTime());

    if (_ParachuteInfo.Velocity > 0.0f)
    {
        if (_ParachuteInfo.Scale < c_ParachuteLocalScale)
            return true;

        _ParachuteInfo.Scale = c_ParachuteLocalScale;
        _ParachuteInfo.Velocity = 0.0f;
    }
    else
    {
        if (_ParachuteInfo.Scale > 0.0f)
            return true;

        _ParachuteInfo.Scale = 0.0f;
        _ParachuteInfo.Velocity = 0.0f;
        _fOn(false);
    }

    return true;
}
void CEngineParachuteControl::Clear(void)
{
    bool Call = (_ParachuteInfo.Scale > 0.0f || _ParachuteInfo.Velocity > 0.0f);

    _ParachuteInfo.Scale = 0.0f;
    _ParachuteInfo.Velocity = 0.0f;

    if (Call)
        _fOn(false);
}
