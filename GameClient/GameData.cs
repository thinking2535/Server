using rso.core;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GameClientTest
{
    using TID = System.Int32;
    public class GameData
    {
        public ulong Checksum = 0;

        public GameData()
        {
            var stream = new CStream();

            stream.LoadFile("../../Bin/GameServer/GameServer/x64/MetaData/checksum.bin");
            stream.Pop(ref Checksum);


        }
    }
}