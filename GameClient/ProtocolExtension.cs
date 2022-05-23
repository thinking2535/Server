using rso.net;

public static class ProtocolExtension
{
    public static SServer GetServer(this SOption Option_)
    {
        return Option_.Servers[Option_.ServerNo];
    }
    public static string GetDataPath(this SOption Option_)
    {
        var Server = GetServer(Option_);
        var NamePort = new CNamePort(Server.Hub);

        return NamePort.GetIPAddresses()[0].ToString() + "_" + NamePort.Port.ToString() + "_" + Option_.ID + "/";
    }
}