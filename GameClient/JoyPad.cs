using System;

public class CJoyPad
{
    public delegate void TCallback();

    TCallback _CenterCallback;
    TCallback _LeftCallback;
    TCallback _RightCallback;
    TCallback _FlapCallback;
    bool _Left = false;
    bool _Right = false;
    bool _Flap = false;

    public CJoyPad(TCallback CenterCallback_, TCallback LeftCallback_, TCallback RightCallback_, TCallback FlapCallback_)
    {
        _CenterCallback = CenterCallback_;
        _LeftCallback = LeftCallback_;
        _RightCallback = RightCallback_;
        _FlapCallback = FlapCallback_;
    }
    public void LeftDown()
    {
        if (_Left)
            return;

        _Left = true;
        if (_Right)
            _CenterCallback();
        else
            _LeftCallback();
    }
    public void LeftUp()
    {
        if (!_Left)
            return;

        _Left = false;
        if (_Right)
            _RightCallback();
        else
            _CenterCallback();
    }
    public void RightDown()
    {
        if (_Right)
            return;

        _Right = true;
        if (_Left)
            _CenterCallback();
        else
            _RightCallback();
    }
    public void RightUp()
    {
        if (!_Right)
            return;

        _Right = false;
        if (_Left)
            _LeftCallback();
        else
            _CenterCallback();
    }
    public void FlapDown()
    {
        if (_Flap)
            return;

        _Flap = true;
        _FlapCallback();
    }
    public void FlapUp()
    {
        if (!_Flap)
            return;

        _Flap = false;
    }
}