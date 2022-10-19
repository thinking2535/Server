#pragma once

#include <functional>

using namespace std;

class CEnginePumpControl
{
public:
    using FPump = function<void()>;
    using FPumpDone = function<void()>;

private:
    FPump _fPump;
    FPumpDone _fPumpDone;
    float _PumpSpeed = 0.0f; // 1회 Pump Speed
    SPumpInfo& _PumpInfo;
    float _ScaleTo = 0.0f;
    inline void _SetScaleTo(void) { _ScaleTo = (float)(_PumpInfo.Count + 1) / c_PumpCountForBalloon; }

public:
    CEnginePumpControl(FPump fPump_, FPumpDone fPumpDone_, float PumpSpeed_, SPumpInfo& PumpInfo_);
private:
    void _Pump(void);
public:
    bool canPump();
    void pump();
    void FixedUpdate(void);
    void Clear(void);
};
