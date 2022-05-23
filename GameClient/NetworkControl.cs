using rso.core;
using rso.game;
using rso.gameutil;
using rso.net;
using System;
using System.Collections.Generic;
using TPeerCnt = System.UInt32;
using TUID = System.Int64;

public class CNetworkControl
{
    public rso.game.CClient Net = null;
    public CClientBinder Binder = null;

    public CNetworkControl(rso.game.CClient Net_)
    {
        Net = Net_;
        Binder = new CClientBinder(Net);
    }
    public void Dispose()
    {
        if (Net != null)
        {
            Net.Dispose();
            Net = null;
        }

        if (Binder != null)
            Binder = null;
    }
    public void Proc()
    {
        Net.Proc();
    }
    public void Create(TPeerCnt PeerNum_, string ID_, string DataPath_, CNamePort Hub_)
    {
        CStream Stream = new CStream();
        Stream.Push(new SUserCreateOption(new SUserLoginOption(EOS.iOS), ELanguage.Korean));

        Net.Create(
            PeerNum_,
            DataPath_,
            Hub_,
            ID_,
            0,
            Stream);
    }
    public bool Login(TPeerCnt PeerNum_, string ID_, string DataPath_, CNamePort Hub_)
    {
        CStream Stream = new CStream();
        Stream.Push(new SUserLoginOption(EOS.iOS));

        return Net.Login(
            PeerNum_,
            DataPath_,
            Hub_,
            ID_,
            0,
            Stream);
    }
    public void Logout()
    {
        Net.Logout();
    }
    public void Send<_TCsProto>(_TCsProto Proto_) where _TCsProto : SProto
    {
        Binder.Send(Proto_);
    }
    public TimeSpan Latency(TPeerCnt PeerNum_)
    {
        return Net.Latency(PeerNum_);
    }
}