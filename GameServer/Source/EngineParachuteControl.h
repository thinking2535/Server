#pragma once

//  vel     scale   on			    off             clear

//  +	    +m      n/a			    n/a             n/a
//  +	    c	    err		    	ok(v=-1)        ok(vel=0, scale=0, off)
//  +	    -0	    err		    	ok(v=0, off)    ok(vel=0, off)

//  0	    +m	    err			    ok(v=-1)        ok(scale=0, off)
//  0	    c	    n/a		    	n/a             n/a
//  0	    -0	    ok(v=1, on)		err             nothing to do

//  -	    +m	    ok(v=0)			err             ok(vel=0, scale=0, off)
//  -	    c	    ok(v=1)			err             ok(vel=0, scale=0, off)
//  -	    -0	    n/a			    n/a             n/a

class CEngineParachuteControl
{
    const float c_Velocity = 1.0f;

public:
    using FOn = function<void(bool On_)>;
private:
    FOn _fOn;
    SParachuteInfo& _ParachuteInfo;
public:
    CEngineParachuteControl(FOn fOn_, SParachuteInfo& ParachuteInfo_);
    void On(void);
    void Off(void);
    bool FixedUpdate(void);
    void Clear(void);
};
