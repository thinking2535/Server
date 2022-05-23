using System;
using System.Windows.Forms;
using rso.core;
using rso.net;
using rso.game;
using rso.gameutil;

namespace GameClientTest
{
    using TPeerCnt = UInt32;
    using TUID = Int64;
    using TSlotNo = System.SByte;
    using TID = System.Int32;
    using TIndex = System.Int64;
    using TResource = System.Int32;
    using TIndexForce = System.Collections.Generic.List<System.Int64>;
    using TLevel = System.Int32;
    using System.Drawing;
    using System.Collections.Generic;
    using rso.physics;

    public partial class GameClientTest : Form
    {
        delegate void TLogFunc(string Msg_);
        delegate void TRecvFunc(SProto Proto_);

        public static Random Rand = new Random(DateTime.Now.Second);
        static GameData _GameData = new GameData();
        static rso.balance.CClient _NetRanking = null;
        static TLogFunc _LogFunc;
        static CFSMClient[] _Clients;
        CJoyPad _JoyPad = null;
        //List<SRect> _Objects = new List<SRect>();
        float _Ratio = 0.0f;
        int _YFlipOffset = 0;

//        void _CollideCallbackMove()
//        {
//            CGlobal.NetworkControl.Binder.Send(new SBattleMoveNetCs(_GetCharacter().Move));
//        }
//        void _CollideCallbackHit(int PlayerIndex_)
//        {
////            CGlobal.NetworkControl.Binder.Send(new SBattleBouncePlayerNetCs(_GetCharacter().Move, PlayerIndex_, false));
//        }
//        void _CollideCallbackFly()
//        {
//        }
//        void _CollideCallbackMove2()
//        {
//            var Char = _GetCharacter();
//            CGlobal.NetworkControl.Binder.Send(new SBattleMove2NetCs(Char.Move, 0));
//        }
        SBattlePlayer _GetBattlePlayer()
        {
            return _Clients[0].Client.BattleBegin.Players[_Clients[0].Client.PlayerIndex];
        }

        void JoyPadCenter()
        {
            //var Player = _GetBattlePlayer();
            //if (!Player.Alive)
            //    return;

            //var FloatTime = CGlobal.GetFloatTime();
            //Player.Character.Reset(Player.Character.Update(FloatTime), new SPoint(), FloatTime);
            //Player.Character.Center();
            //if (Player.Character.IsGround || Player.Character.IsAirMovable())
            //    CGlobal.NetworkControl.Binder.Send(new SBattleMoveNetCs(Player.Character.Move, 0));
        }
        void JoyPadLeft()
        {
            //var Player = _GetBattlePlayer();
            //if (!Player.Alive)
            //    return;

            //var OldFace = Player.Character.Face;
            //var FloatTime = CGlobal.GetFloatTime();
            //Player.Character.Reset(Player.Character.Update(FloatTime), new SPoint(), FloatTime);
            //Player.Character.LeftRight(-1);

            //if (Player.Character.IsGround || Player.Character.IsAirMovable())
            //    CGlobal.NetworkControl.Binder.Send(new SBattleMoveNetCs(Player.Character.Move, -1));
            //else if (OldFace != Player.Character.Face)
            //    CGlobal.NetworkControl.Binder.Send(new SBattleTurnNetCs(Player.Character.Face));
        }
        void JoyPadRight()
        {
            //var Player = _GetBattlePlayer();
            //if (!Player.Alive)
            //    return;

            //var OldFace = Player.Character.Face;
            //var FloatTime = CGlobal.GetFloatTime();
            //Player.Character.Reset(Player.Character.Update(FloatTime), new SPoint(), FloatTime);
            //Player.Character.LeftRight(1);

            //if (Player.Character.IsGround || Player.Character.IsAirMovable())
            //    CGlobal.NetworkControl.Binder.Send(new SBattleMoveNetCs(Player.Character.Move, 1));
            //else if (OldFace != Player.Character.Face)
            //    CGlobal.NetworkControl.Binder.Send(new SBattleTurnNetCs(Player.Character.Face));
        }
        void JoyPadFlap()
        {
            //var Player = _GetBattlePlayer();
            //if (!Player.Alive)
            //    return;

            //if (!Player.Character.CanFlap())
            //    return;

            //var FloatTime = CGlobal.GetFloatTime();
            //Player.Character.Reset(Player.Character.Update(FloatTime), new SPoint(), FloatTime);
            //Player.Character.IsGround = false;
            //CGlobal.NetworkControl.Binder.Send(new SBattleMove2NetCs(Player.Character.Move, 0));
        }
        void NewNetwork()
        {
            Log(_GameData.Checksum.ToString());

            // Load Data Checksum
            var Server = CGlobal.Option.Data.GetServer();

            // Game Network ////////////////////////////////////////////////////////////////////////////////
            CGlobal.NetworkControl = new CNetworkControl(new rso.game.CClient(
                LinkS, LinkFailS, UnLinkS, RecvS, LinkSoftS, UnLinkSoftS, Check, CheckFail,
                new SVersion(global.c_Ver_Main, _GameData.Checksum)));

            CGlobal.NetworkControl.Binder.AddSendProto<SChatNetCs>((int)EProtoNetCs.Chat);
            CGlobal.NetworkControl.Binder.AddSendProto<SFCMTokenSetNetCs>((int)EProtoNetCs.FCMTokenSet);
            CGlobal.NetworkControl.Binder.AddSendProto<SFCMTokenUnsetNetCs>((int)EProtoNetCs.FCMTokenUnset);
            CGlobal.NetworkControl.Binder.AddSendProto<SFCMCanPushAtNightNetCs>((int)EProtoNetCs.FCMCanPushAtNight);
            CGlobal.NetworkControl.Binder.AddSendProto<SChangeLanguageNetCs>((int)EProtoNetCs.ChangeLanguage);
            CGlobal.NetworkControl.Binder.AddSendProto<SBuyNetCs>((int)EProtoNetCs.Buy);
            CGlobal.NetworkControl.Binder.AddSendProto<SPurchaseNetCs>((int)EProtoNetCs.Purchase);
            CGlobal.NetworkControl.Binder.AddSendProto<SSelectCharNetCs>((int)EProtoNetCs.SelectChar);
            CGlobal.NetworkControl.Binder.AddSendProto<SBattleJoinNetCs>((int)EProtoNetCs.BattleJoin);
            CGlobal.NetworkControl.Binder.AddSendProto<SBattleOutNetCs>((int)EProtoNetCs.BattleOut);
            CGlobal.NetworkControl.Binder.AddSendProto<SGachaNetCs>((int)EProtoNetCs.Gacha);
            CGlobal.NetworkControl.Binder.AddSendProto<SRankRewardNetCs>((int)EProtoNetCs.RankReward);
            CGlobal.NetworkControl.Binder.AddSendProto<SChangeNickNetCs>((int)EProtoNetCs.ChangeNick);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.Ret, RetNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.Msg, MsgNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.Login, LoginNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.Lobby, LobbyNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.Chat, ChatNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.UserExp, UserExpNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.Resources, ResourcesNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.Purchase, PurchaseNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.BattleJoin, BattleJoinNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.BattleOut, BattleOutNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.BattleBegin, BattleBeginNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.BattleEnd, BattleEndNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.Gacha, GachaNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.GachaFailed, GachaFailedNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.ChangeNick, ChangeNickNetSc);
            CGlobal.NetworkControl.Binder.AddRecvProto((int)EProtoNetSc.ChangeNickFail, ChangeNickFailNetSc);

            _NetRanking = new rso.balance.CClient(LinkR, LinkFailR, UnLinkR, RecvR);
        }
        void Linked()
        {
            if (CGlobal.Option.Data.Auto)
                return;

            btnLatency.Enabled = true;
        }
        void UnLinked()
        {
            if (CGlobal.Option.Data.Auto)
                return;

            cbServer.Enabled = true;
            btnCreate.Enabled = true;
            btnLogin.Enabled = true;
            btnDisconnect.Enabled = false;
            btnLatency.Enabled = false;
        }
        void Linking()
        {
            if (CGlobal.Option.Data.Auto)
                return;

            cbServer.Enabled = false;
            btnCreate.Enabled = false;
            btnLogin.Enabled = false;
            btnDisconnect.Enabled = true;
            btnLatency.Enabled = true;
        }
        void UnLinking()
        {
            if (CGlobal.Option.Data.Auto)
                return;

            btnDisconnect.Enabled = false;
            btnLatency.Enabled = false;
        }
        void LinkS(CKey Key_, TUID UID_)
        {
            _Clients[Key_.PeerNum].Login(UID_);
            Linked();
            Log("LinkS PeerNum : " + Key_.PeerNum + " UID : " + UID_);
        }
        void LinkFailS(TPeerCnt PeerNum_, EGameRet GameRet_)
        {
            _Clients[PeerNum_].LoginFail();
            UnLinked();
            Log("LinkFailS PeerNum:" + PeerNum_ + " GameRet:" + GameRet_.ToString());
        }
        void UnLinkS(CKey Key_, EGameRet GameRet_)
        {
//            _Objects.Clear();
            _Clients[Key_.PeerNum].Logout();
            // AcceptButton = btnLoginCreate; 엔터 실행 버튼 설정
            UnLinked();
            Log("UnLinkS GameRet:" + GameRet_.ToString());
        }
        void RecvS(CKey Key_, CStream Stream_)
        {
            Log("RecvS GameRet:");

            int ProtoNum = 0;
            Stream_.Pop(ref ProtoNum);
            CGlobal.NetworkControl.Binder.Recv(Key_, ProtoNum, Stream_);
        }
        void LinkSoftS(CKey Key_, CNamePort IPPort_)
        {
            Log("LinkSoftS");
        }
        void UnLinkSoftS(CKey Key_, EGameRet GameRet_)
        {
            Log("UnLinkSoftS PeerNum:" + Key_.PeerNum + " GameRet:" + GameRet_.ToString());
        }
        void Check(long UID_, CStream Stream_)
        {
            Log("Check UID : " + UID_);
        }
        void CheckFail(uint PeerNum_, EGameRet GameRet_)
        {
            Log("Check PeerNum : " + PeerNum_);
        }

        void LinkR(CKey Key_, CNamePort IPPort_)
        {
            Log("LinkR PeerNum : " + Key_.PeerNum);
        }
        void LinkFailR(TPeerCnt PeerNum_, ENetRet NetRet_)
        {
            Log("LinkFailR PeerNum:" + PeerNum_ + " NetRet:" + NetRet_.ToString());
        }
        void UnLinkR(CKey Key_, ENetRet NetRet_)
        {
            Log("UnLinkR NetRet:" + NetRet_.ToString());
        }
        void RecvR(CKey Key_, CStream Stream_)
        {
            Log("RecvR GameRet:");
        }

        Rectangle _GetRectangle(SRect Rect_)
        {
            var Rect = Rect_.GetMulti(new SPoint(_Ratio, _Ratio));
            return new Rectangle((int)Rect.Left, (int)(_YFlipOffset - Rect.Top), (int)Rect.Width(), (int)Rect.Height());
        }
        //void _DrawObject(Graphics Graphics_, SRect Object_)
        //{
        //    Graphics_.DrawRectangle(Pens.Green, _GetRectangle(Object_));
        //}
        void _DrawPlayerCore(Graphics Graphics_, Pen BodyColor_, SPoint Pos_, sbyte Face_)
        {
            var PlayerRect = Pos_.GetBodyRect();
            var DrawRect = _GetRectangle(PlayerRect);

            // Body
            Graphics_.DrawRectangle(BodyColor_, DrawRect);
            // Face
            Graphics_.DrawLine(BodyColor_, (DrawRect.Left + DrawRect.Right) / 2, (DrawRect.Top + DrawRect.Bottom) / 2, (DrawRect.Left + DrawRect.Right) / 2 + Face_ * (DrawRect.Width / 2), (DrawRect.Top + DrawRect.Bottom) / 2);
        }
        void _DrawPlayer(Graphics Graphics_, Pen BodyColor_, SPoint Pos_, sbyte Face_)
        {
            _DrawPlayerCore(Graphics_, BodyColor_, Pos_, Face_);
            _DrawPlayerCore(Graphics_, BodyColor_, new SPoint(Pos_.X + global.c_ScreenWidth, Pos_.Y), Face_);
        }
        public GameClientTest()
        {
            InitializeComponent();

            _Ratio = pbBattle.Width / global.c_ScreenWidth;
            _YFlipOffset = pbBattle.Height - 70;
            _JoyPad = new CJoyPad(JoyPadCenter, JoyPadLeft, JoyPadRight, JoyPadFlap);
            this.DoubleBuffered = true;
            //this.SetStyle(ControlStyles.DoubleBuffer, true);
            //this.SetStyle(ControlStyles.AllPaintingInWmPaint, true);
            //this.SetStyle(ControlStyles.UserPaint, true);
            //this.UpdateStyles();

            _LogFunc = Log;
            CGlobal.Option = new COptionJson<SOption>("Option.ini", true);

            foreach (var i in CGlobal.Option.Data.Servers)
                cbServer.Items.Add("[Game]" + i.Hub.Name + ":" + i.Hub.Port.ToString());

            cbServer.SelectedIndex = CGlobal.Option.Data.ServerNo;

            tbID.Text = CGlobal.Option.Data.ID;

            try
            {
                if (CGlobal.Option.Data.Auto)
                {
                    _Clients = new CFSMClient[CGlobal.Option.Data.ClientCnt];
                    for (TPeerCnt i = 0; i < CGlobal.Option.Data.ClientCnt; ++i)
                    {
                        _Clients[i] = new CFSMClient(i, CGlobal.Option.Data.ID + (CGlobal.Option.Data.StartNum + i).ToString(), true, CGlobal.Option.Data.DelayTick);
                        _Clients[i].Initialize();
                    }

                    cbServer.Enabled = false;
                    btnCreate.Enabled = false;
                    btnLogin.Enabled = false;
                    btnDisconnect.Enabled = false;
                    btnLatency.Enabled = false;
                }
                else
                {
                    _Clients = new CFSMClient[1];
                    _Clients[0] = new CFSMClient(0, tbID.Text, false, CGlobal.Option.Data.DelayTick);
                    _Clients[0].Initialize();
                }

                TimerNet.Enabled = true;
            }
            catch (Exception Exception_)
            {
                Log(Exception_.ToString());
                return;
            }
        }
        public void Log(String Msg_)
        {
            txtLog.AppendText(Msg_.Replace("\n", "\r\n") + "\r\n");
        }
        void LogProto(SProto Proto_)
        {
            //if (CGlobal.Option.Data.Auto)
            //    return;

            Log("<" + Proto_.ToString() + ">");

            if (CGlobal.Option.Data.Auto)
                return;

            Log(Proto_.ToJsonString());
        }
        TProto PopStream<TProto>(CStream Stream_) where TProto : SProto, new()
        {
            var Proto = new TProto();
            Proto.Push(Stream_);
            LogProto(Proto);
            return Proto;
        }
        public void RetNetSc(SKey Key_, CStream Stream_)
        {
            var Proto = PopStream<SRetNetSc>(Stream_);
            _Clients[Key_.PeerNum].RetNetSc(Proto);
            Log(Proto.Ret.ToString());
        }
        public void MsgNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].MsgNetSc(PopStream<SMsgNetSc>(Stream_));
        }
        public void LoginNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].LoginNetSc(PopStream<SLoginNetSc>(Stream_));
        }
        public void LobbyNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].LobbyNetSc(PopStream<SLobbyNetSc>(Stream_));
        }
        public void ChatNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].ChatNetSc(PopStream<SChatNetSc>(Stream_));
        }
        public void UserExpNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].UserExpNetSc(PopStream<SUserExpNetSc>(Stream_));
        }
        public void ResourcesNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].ResourcesNetSc(PopStream<SResourcesNetSc>(Stream_));
        }
        public void PurchaseNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].PurchaseNetSc(PopStream<SPurchaseNetSc>(Stream_));
        }

        public void BattleJoinNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].BattleJoinNetSc(PopStream<SBattleJoinNetSc>(Stream_));
        }
        public void BattleOutNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].BattleOutNetSc(PopStream<SBattleOutNetSc>(Stream_));
        }
        public void BattleBeginNetSc(SKey Key_, CStream Stream_)
        {
            var Proto = PopStream<SBattleBeginNetSc>(Stream_);
            _Clients[Key_.PeerNum].BattleBeginNetSc(Proto);

            //var Rect = new SRect(global.c_ScreenWidth_2, global.c_ScreenWidth_2 + global.c_ScreenWidth, -0.5f, 0.0f); // Land
            //var Rect = new SRect(0.0f, global.c_ScreenWidth, 0.0f, 0.3f); // Land
            //_Objects.Add(new SRect(Rect));

            for (int i = 0; i < Proto.Players.Count; ++i)
            {
                if (Proto.Players[i].UID == _Clients[0].GetUID())
                    continue;

//                _CollideMgr.AddPlayer(i, Proto.Players[i].Character);
            }
        }
        public void BattleEndNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].BattleEndNetSc(PopStream<SBattleEndNetSc>(Stream_));
        }
        public void GachaNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].GachaNetSc(PopStream<SGachaNetSc>(Stream_));
        }
        public void GachaFailedNetSc(SKey Key_, CStream Stream_)
        {
            _Clients[Key_.PeerNum].GachaFailedNetSc(PopStream<SGachaFailedNetSc>(Stream_));
        }
        public void ChangeNickNetSc(SKey Key_, CStream Stream_)
        {
            var Proto = PopStream<SChangeNickNetSc>(Stream_);
        }
        public void ChangeNickFailNetSc(SKey Key_, CStream Stream_)
        {
            var Proto = PopStream<SChangeNickFailNetSc>(Stream_);
        }

        private void TimerNet_Tick(object sender, EventArgs e)
        {
            if (CGlobal.NetworkControl != null)
                CGlobal.NetworkControl.Proc();

            if (_NetRanking != null)
                _NetRanking.Proc();

            //if (_Clients[0].Client != null && _Clients[0].Client.BattleBegin != null)
            //    _CollideMgr.Proc(CGlobal.GetDoubleTime());

            foreach (var i in _Clients)
                i.Proc();

            pbBattle.Invalidate();
        }
        private void button75_Click(object sender, EventArgs e)
        {
            var Server = CGlobal.Option.Data.GetServer();
            var Hub = new CNamePort(Server.Hub);

            CGlobal.NetworkControl.Create(0, tbID.Text, CGlobal.Option.Data.GetDataPath(), Hub);
            Linking();
        }
        private void btnLoginUID_Click(object sender, EventArgs e)
        {
            var Server = CGlobal.Option.Data.GetServer();
            var Hub = new CNamePort(Server.Hub);

            if (!CGlobal.NetworkControl.Login(0, tbID.Text, CGlobal.Option.Data.GetDataPath(), Hub))
                return;

            Linking();
        }

        private void btnDisconnect_Click(object sender, EventArgs e)
        {
            CGlobal.NetworkControl.Logout();
            UnLinking();
        }
        private void GalaxyClient_FormClosing(object sender, FormClosingEventArgs e)
        {
            CGlobal.Option.Save();

            if (CGlobal.NetworkControl != null)
            {
                CGlobal.NetworkControl.Dispose();
                CGlobal.NetworkControl = null;
            }
        }
        private void button15_Click(object sender, EventArgs e)
        {
            _Clients[0].ChatNetCs(tbChat_Msg.Text);
        }
        private void button20_Click(object sender, EventArgs e)
        {
            Log("Latency:" + CGlobal.NetworkControl.Latency(0));
        }
        private void button74_Click_1(object sender, EventArgs e)
        {
            _Clients[0].FCMTokenSetNetCs(tbFCMToken.Text);
        }
        private void button76_Click(object sender, EventArgs e)
        {
            _Clients[0].FCMTokenUnsetNetCs();
        }
        private void button97_Click(object sender, EventArgs e)
        {
            _Clients[0].FCMCanPushAtNightNetCs(int.Parse(tbCanPushAtNight.Text) == 1);
        }
        private void button39_Click(object sender, EventArgs e)
        {
            _Clients[0].ChangeLanguageNetCs((ELanguage)byte.Parse(tbLanguage.Text));
        }

        private void CbServer_SelectedIndexChanged(object sender, EventArgs e)
        {
            CGlobal.Option.Data.ServerNo = cbServer.SelectedIndex;
            NewNetwork();
        }
        private void TbID_TextChanged(object sender, EventArgs e)
        {
            CGlobal.Option.Data.ID = tbID.Text;
        }
        private void Button82_Click(object sender, EventArgs e)
        {
            _Clients[0].PurchaseNetCs(tbPurchaseProductID.Text, tbPurchaseToken.Text);
        }

        private void Button83_Click(object sender, EventArgs e)
        {
            txtLog.Clear();
        }

        private void Button84_Click(object sender, EventArgs e)
        {
            _Clients[0].BuyGoodsNetCs(TID.Parse(tbGoodsID.Text));
        }
        private void pbBattle_Paint(object sender, PaintEventArgs e)
        {
            if (CGlobal.Option.Data.Auto) // 스트레스 테스트 중이면
                return;

            if (_Clients[0].Client == null || _Clients[0].Client.BattleBegin == null)
                return;

            //foreach (var Obj in _Objects)
            //    _DrawObject(e.Graphics, Obj);

            var FloatTime = CGlobal.GetFloatTime();
            for (int i = 0; i < _Clients[0].Client.BattleBegin.Players.Count; ++i)
            {
            }

            // Draw Ghost
            if (_Clients[0].Client.Ghost != null)
            {
                var PlayerRect = _Clients[0].Client.Ghost.GetCurPos(CGlobal.GetFloatTime()).GetBodyRect();
                var DrawRect = _GetRectangle(PlayerRect);
                e.Graphics.DrawRectangle(Pens.DarkGoldenrod, DrawRect);
            }

            // Draw WhaleRect
            //var WhaleRect = new SRect(-(global.c_ScreenWidth_2 * 0.5), global.c_ScreenWidth_2 * 0.5, 0.0f, global.c_ScreenHeight * 0.2);
            //e.Graphics.DrawRectangle(Pens.Blue, _GetRectangle(WhaleRect));
        }

        private void GameClientTest_KeyDown(object sender, KeyEventArgs e)
        {
            if (CGlobal.Option.Data.Auto)
                return;

            switch (e.KeyCode)
            {
                case Keys.Insert:
                    _JoyPad.FlapDown();
                    break;

                case Keys.Left:
                    _JoyPad.LeftDown();
                    break;

                case Keys.Right:
                    _JoyPad.RightDown();
                    break;

                case Keys.Home: // Fly
                    {
                        var Player = _GetBattlePlayer();
                        if (!Player.IsAlive())
                            return;

                        //var FloatTime = CGlobal.GetFloatTime();
                        //Player.Character.Reset(Player.Character.Update(FloatTime), new SPoint(), FloatTime);
                        //Player.Character.IsGround = false;
                        //CGlobal.NetworkControl.Binder.Send(new SBattleMove2NetCs(Player.Character.Move, 0));
                    }
                    break;

                case Keys.End: // Land
                    {
                        var Player = _GetBattlePlayer();
                        if (!Player.IsAlive())
                            return;

                        //var FloatTime = CGlobal.GetFloatTime();
                        //Player.Character.Reset(Player.Character.Update(FloatTime), new SPoint(), FloatTime);
                        //Player.Character.IsGround = true;
                        //CGlobal.NetworkControl.Binder.Send(new SBattleMove2NetCs(Player.Character.Move, 0));
                    }
                    break;

                case Keys.PageUp:
                    {
                        var Player = _GetBattlePlayer();
                        if (!Player.IsAlive())
                            return;

//                        Player.Character.Pump();
                    }
                    break;

                case Keys.PageDown:
                    {
                        var Player = _GetBattlePlayer();
                        if (!Player.IsAlive())
                            return;

//                        CGlobal.NetworkControl.Binder.Send(new SBattleHitNetCs(Player.Character.Move, 0, 0));
                    }
                    break;
            }

            pbBattle.Invalidate();
        }

        private void GameClientTest_KeyUp(object sender, KeyEventArgs e)
        {
            if (CGlobal.Option.Data.Auto)
                return;

            switch (e.KeyCode)
            {
                case Keys.Insert:
                    _JoyPad.FlapUp();
                    break;

                case Keys.Left:
                    _JoyPad.LeftUp();
                    break;

                case Keys.Right:
                    _JoyPad.RightUp();
                    break;
            }

            pbBattle.Invalidate();
        }

        private void btnBattleJoin_Click(object sender, EventArgs e)
        {
            CGlobal.NetworkControl.Binder.Send(new SBattleJoinNetCs(new SBattleType(sbyte.Parse(tbMemberCnt.Text), sbyte.Parse(tbTeamCnt.Text))));
        }

        private void btnBattleOut_Click(object sender, EventArgs e)
        {
            CGlobal.NetworkControl.Binder.Send(new SBattleOutNetCs());
        }

        private void btnSelectChar_Click(object sender, EventArgs e)
        {
            CGlobal.NetworkControl.Binder.Send(new SSelectCharNetCs(int.Parse(tbCharCode.Text)));
        }

        private void btnRankingConnect_Click(object sender, EventArgs e)
        {
            if (_NetRanking.IsConnected(0))
                return;

            var Server = CGlobal.Option.Data.GetServer();
            var NamePort = new CNamePort(Server.Hub);

            _NetRanking.Connect(0, CGlobal.Option.Data.GetDataPath(), NamePort);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            CGlobal.NetworkControl.Binder.Send(new SGachaNetCs(int.Parse(tbGachaIndex.Text)));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            CGlobal.NetworkControl.Binder.Send(new SRankRewardNetCs());
        }

        private void button3_Click(object sender, EventArgs e)
        {
            CGlobal.NetworkControl.Binder.Send(new SChangeNickNetCs(tbChangeNick.Text));
        }
    }
}
