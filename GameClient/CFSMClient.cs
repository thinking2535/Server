using System;
using System.Collections.Generic;
using rso.Base;
using rso.core;
using rso.game;
using rso.gameutil;
using rso.net;
using rso.physics;
using UnityEngine;

namespace GameClientTest
{
    using TPeerCnt = UInt32;
    using TUID = Int64;
    using TIndex = System.Int64;
    using TID = System.Int32;
    using TResource = System.Int32;
    using TSlotNo = System.SByte;

    public partial class GameClientTest
    {
        public class CFSMDummy : IFSM
        {
            public void Clear()
            {
            }
            public void Proc()
            {
            }
            public void Set(TCallback Callback_)
            {
            }
        }
        class CFSMClient
        {
            TPeerCnt PeerNum;
            TUID UID = 0;
            string ID;
            public IFSM FSM;
            public CClient Client = null;

            public CFSMClient(TPeerCnt PeerNum_, string ID_, bool Auto_, int Delay_)
            {
                PeerNum = PeerNum_;
                ID = ID_;

                if (Auto_)
                    FSM = new CFSM(Delay_);
                else
                    FSM = new CFSMDummy();
            }
            public TUID GetUID()
            {
                return UID;
            }
            public void Initialize()
            {
                FSM.Set(AutoUnLinked);
            }
            public void Proc()
            {
                FSM.Proc();
            }
            public void Login(TUID UID_)
            {
                UID = UID_;
                Client = new CClient(ID, UID_);
            }
            public void LoginFail()
            {
                UID = 0;
                FSM.Set(AutoUnLinked);
            }
            public void Logout()
            {
                Client = null;
                FSM.Set(AutoUnLinked);
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////
            public void ChatNetCs(string Msg_)
            {
                CGlobal.NetworkControl.Binder.Send(PeerNum, Client.ChatNetCs(Msg_));
            }
            public void PurchaseNetCs(string PurchaseProductID_, string PurchaseToken_)
            {
                Client.PurchaseNetCs(PeerNum, PurchaseProductID_, PurchaseToken_);
                FSM.Set(AutoInTown);
            }
            public void PurchaseNetCs()
            {
                Client.PurchaseNetCs(PeerNum);
                FSM.Set(AutoInTown);
            }
            public void BuyGoodsNetCs(TID ID_)
            {
                Client.BuyGoodsNetCs(PeerNum, ID_);
                FSM.Set(AutoInTown);
            }
            public void FCMTokenSetNetCs(string Token_)
            {
                CGlobal.NetworkControl.Binder.Send(PeerNum, Client.FCMTokenSetNetCs(Token_));
            }
            public void FCMTokenUnsetNetCs()
            {
                CGlobal.NetworkControl.Binder.Send(PeerNum, Client.FCMTokenUnsetNetCs());
            }
            public void FCMCanPushAtNightNetCs(bool CanPush_)
            {
                CGlobal.NetworkControl.Binder.Send(PeerNum, Client.FCMCanPushAtNightNetCs(CanPush_));
            }
            public void ChangeLanguageNetCs(ELanguage Language_)
            {
                CGlobal.NetworkControl.Binder.Send(PeerNum, Client.ChangeLanguageNetCs(Language_));
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////
            public void RetNetSc(SRetNetSc Proto_)
            {
                if (Client == null)
                    return;

                Client.RetNetSc(Proto_);
            }
            public void MsgNetSc(SMsgNetSc Proto_) { Client.MsgNetSc(Proto_); }

            public void LoginNetSc(SLoginNetSc Proto_)
            {
                Client.LoginNetSc(Proto_);
                FSM.Set(AutoInTown);
            }
            public void LobbyNetSc(SLobbyNetSc Proto_)
            {
                Client.LobbyNetSc(Proto_);
                FSM.Set(AutoInTown);
            }
            public void ChatNetSc(SChatNetSc Proto_) { Client.ChatNetSc(Proto_); }
            public void UserExpNetSc(SUserExpNetSc Proto_) { Client.UserExpNetSc(Proto_); }
            public void ResourcesNetSc(SResourcesNetSc Proto_) { Client.ResourcesNetSc(Proto_); }
            public void PurchaseNetSc(SPurchaseNetSc Proto_) { Client.PurchaseNetSc(Proto_); }

            public void BattleJoinNetSc(SBattleJoinNetSc Proto_) { Client.BattleJoinNetSc(Proto_); }
            public void BattleOutNetSc(SBattleOutNetSc Proto_) { Client.BattleOutNetSc(Proto_); }
            public void BattleBeginNetSc(SBattleBeginNetSc Proto_) { Client.BattleBeginNetSc(Proto_); }
            public void BattleEndNetSc(SBattleEndNetSc Proto_) { Client.BattleEndNetSc(Proto_); }
            public void GachaNetSc(SGachaNetSc Proto_)
            {
            }
            public void GachaFailedNetSc(SGachaFailedNetSc Proto_)
            {
            }

            void AutoUnLinked()
            {
                try
                {
                    if (!CGlobal.NetworkControl.Login(PeerNum, ID, CGlobal.Option.Data.GetDataPath(), new CNamePort(CGlobal.Option.Data.GetServer().Hub)))
                        throw new Exception();
                }
                catch
                {
                    FSM.Set(AutoLoginFailed);
                }
            }
            void AutoLoginFailed()
            {
                CGlobal.NetworkControl.Create(PeerNum, ID, CGlobal.Option.Data.GetDataPath(), new CNamePort(CGlobal.Option.Data.GetServer().Hub));
            }
            void AutoInTown()
            {
                switch (Rand.Next() % 1)
                {
                    case 0:
                        FSM.Set(AutoInTown);
                        break;

                    default:
                        FSM.Set(AutoInTown);
                        break;
                }
            }
        }
    }
}
