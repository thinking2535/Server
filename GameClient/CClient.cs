using System;
using System.Collections.Generic;
using System.Windows.Forms;
using rso.core;
using rso.gameutil;
using rso.physics;

namespace GameClientTest
{
    using TPeerCnt = UInt32;
    using TLongIP = UInt32;
    using TUID = Int64;
    using TRUID = UInt64;
    using TIndex = Int64;
    using TCode = Int32;
    using TBID = Int32;
    using TItemRoomIndex = UInt64;
    using TMineRoomIndex = UInt64;
    using TResource = System.Int32;
    using TID = System.Int32;
    using TSlotNo = System.SByte;
    using TIndexForce = System.Collections.Generic.List<System.Int64>;

    public partial class GameClientTest
    {
        public class SPosTime
        {
            public SPoint Pos = null;
            public float Time = 0.0f;

            public SPosTime(SPoint Pos_, float Time_)
            {
                Pos = Pos_;
                Time = Time_;
            }
        }
        public class CClient
        {
            public string ID = "";
            public TUID UID = 0;

            public SLoginNetSc Login;
            public int PlayerIndex = -1;
            public SBattleBeginNetSc BattleBegin = null;
            public SObjectStraight Ghost = null;

            void Send<TProto>(TPeerCnt PeerNum_, TProto Proto_) where TProto : SProto
            {
                _LogFunc(Proto_.ToString());
                CGlobal.NetworkControl.Binder.Send(PeerNum_, Proto_);
            }
            public CClient(string ID_, TUID UID_)
            {
                ID = ID_;
                UID = UID_;
            }
            public static int GetRandomInt32(int Max_)
            {
                return (Rand.Next() % Max_);
            }
            public static bool GetRandomBoolean()
            {
                return (Rand.Next() % 2 == 0 ? true : false);
            }
            public void PurchaseNetCs(TPeerCnt PeerNum_, string PurchaseProductID_, string PurchaseToken_)
            {
                Send(PeerNum_, new SPurchaseNetCs(PurchaseProductID_, PurchaseToken_));
            }
            public void PurchaseNetCs(TPeerCnt PeerNum_)
            {
                Send(PeerNum_, new SPurchaseNetCs("", ""));
            }
            public void BuyGoodsNetCs(TPeerCnt PeerNum_, TID ID_)
            {
                Send(PeerNum_, new SBuyNetCs(ID_));
            }
            public SFCMTokenSetNetCs FCMTokenSetNetCs(string Token_)
            {
                return new SFCMTokenSetNetCs(Token_);
            }
            public SFCMTokenUnsetNetCs FCMTokenUnsetNetCs()
            {
                return new SFCMTokenUnsetNetCs();
            }
            public SFCMCanPushAtNightNetCs FCMCanPushAtNightNetCs(bool CanPush_)
            {
                return new SFCMCanPushAtNightNetCs(CanPush_);
            }
            public SChangeLanguageNetCs ChangeLanguageNetCs(ELanguage Language_)
            {
                return new SChangeLanguageNetCs(Language_);
            }
            public void RetNetSc(SRetNetSc Proto_) { }
            public void MsgNetSc(SMsgNetSc Proto_) { }
            public void LoginNetSc(SLoginNetSc Proto_)
            {
                Login = Proto_;
            }
            public void LobbyNetSc(SLobbyNetSc Proto_)
            {
            }
            public SChatNetCs ChatNetCs(string Msg_)
            {
                return new SChatNetCs(Msg_);
            }
            public void ChatNetSc(SChatNetSc Proto_) { }
            public void UserExpNetSc(SUserExpNetSc Proto_) { }
            public void ResourcesNetSc(SResourcesNetSc Proto_) { }
            public void PurchaseNetSc(SPurchaseNetSc Proto_) { }
            public void BattleJoinNetSc(SBattleJoinNetSc Proto_) { }
            public void BattleOutNetSc(SBattleOutNetSc Proto_) { }
            public void BattleBeginNetSc(SBattleBeginNetSc Proto_)
            {
                for (int i = 0; i < Proto_.Players.Count; ++i)
                {
                    if (_Clients[0].Client.UID == Proto_.Players[i].UID)
                    {
                        _Clients[0].Client.PlayerIndex = i;
                        break;
                    }
                }

                BattleBegin = Proto_;
                CGlobal.GameStartTicks = DateTime.Now.Ticks;
            }
            public void BattleEndNetSc(SBattleEndNetSc Proto_)
            {
                _Clients[0].Client.BattleBegin = null;
                _Clients[0].Client.Ghost = null;
            }
        }
    }
}
