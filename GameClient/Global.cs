using rso.gameutil;
using System;

public class CGlobal
{
    public static long GameStartTicks = 0;
    public static float GetFloatTime()
    {
        return (DateTime.Now.Ticks - GameStartTicks) / 10000000.0f;
    }
    public static COptionJson<SOption> Option = null;
    public static CNetworkControl NetworkControl = null;
}