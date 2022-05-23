namespace GameClientTest
{
    partial class GameClientTest
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.TimerNet = new System.Windows.Forms.Timer(this.components);
            this.btnDisconnect = new System.Windows.Forms.Button();
            this.txtLog = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.tbID = new System.Windows.Forms.TextBox();
            this.btnLogin = new System.Windows.Forms.Button();
            this.button15 = new System.Windows.Forms.Button();
            this.label13 = new System.Windows.Forms.Label();
            this.tbChat_Msg = new System.Windows.Forms.TextBox();
            this.btnLatency = new System.Windows.Forms.Button();
            this.btnCreate = new System.Windows.Forms.Button();
            this.button74 = new System.Windows.Forms.Button();
            this.button76 = new System.Windows.Forms.Button();
            this.label37 = new System.Windows.Forms.Label();
            this.tbFCMToken = new System.Windows.Forms.TextBox();
            this.label43 = new System.Windows.Forms.Label();
            this.tbLang = new System.Windows.Forms.TextBox();
            this.label45 = new System.Windows.Forms.Label();
            this.tbLanguage = new System.Windows.Forms.TextBox();
            this.button39 = new System.Windows.Forms.Button();
            this.cbServer = new System.Windows.Forms.ComboBox();
            this.label74 = new System.Windows.Forms.Label();
            this.label87 = new System.Windows.Forms.Label();
            this.tbPurchaseProductID = new System.Windows.Forms.TextBox();
            this.button82 = new System.Windows.Forms.Button();
            this.label88 = new System.Windows.Forms.Label();
            this.tbPurchaseToken = new System.Windows.Forms.TextBox();
            this.button83 = new System.Windows.Forms.Button();
            this.label89 = new System.Windows.Forms.Label();
            this.tbGoodsID = new System.Windows.Forms.TextBox();
            this.button84 = new System.Windows.Forms.Button();
            this.button97 = new System.Windows.Forms.Button();
            this.tbCanPushAtNight = new System.Windows.Forms.TextBox();
            this.pbBattle = new System.Windows.Forms.PictureBox();
            this.btnBattleJoin = new System.Windows.Forms.Button();
            this.btnBattleOut = new System.Windows.Forms.Button();
            this.tbMemberCnt = new System.Windows.Forms.TextBox();
            this.tbTeamCnt = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnSelectChar = new System.Windows.Forms.Button();
            this.tbCharCode = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btnRankingConnect = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.tbGachaIndex = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.tbChangeNick = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pbBattle)).BeginInit();
            this.SuspendLayout();
            // 
            // TimerNet
            // 
            this.TimerNet.Interval = 1;
            this.TimerNet.Tick += new System.EventHandler(this.TimerNet_Tick);
            // 
            // btnDisconnect
            // 
            this.btnDisconnect.Enabled = false;
            this.btnDisconnect.Location = new System.Drawing.Point(1346, 7);
            this.btnDisconnect.Name = "btnDisconnect";
            this.btnDisconnect.Size = new System.Drawing.Size(89, 21);
            this.btnDisconnect.TabIndex = 13;
            this.btnDisconnect.Text = "Disconnect";
            this.btnDisconnect.UseVisualStyleBackColor = true;
            this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // txtLog
            // 
            this.txtLog.Location = new System.Drawing.Point(1006, 36);
            this.txtLog.Multiline = true;
            this.txtLog.Name = "txtLog";
            this.txtLog.ReadOnly = true;
            this.txtLog.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtLog.Size = new System.Drawing.Size(471, 800);
            this.txtLog.TabIndex = 22;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(1024, 9);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(16, 12);
            this.label5.TabIndex = 33;
            this.label5.Text = "ID";
            // 
            // tbID
            // 
            this.tbID.Location = new System.Drawing.Point(1047, 5);
            this.tbID.Name = "tbID";
            this.tbID.Size = new System.Drawing.Size(57, 21);
            this.tbID.TabIndex = 32;
            this.tbID.TextChanged += new System.EventHandler(this.TbID_TextChanged);
            // 
            // btnLogin
            // 
            this.btnLogin.Location = new System.Drawing.Point(1285, 7);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(55, 21);
            this.btnLogin.TabIndex = 52;
            this.btnLogin.Text = "Login";
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.btnLoginUID_Click);
            // 
            // button15
            // 
            this.button15.Location = new System.Drawing.Point(13, 210);
            this.button15.Name = "button15";
            this.button15.Size = new System.Drawing.Size(215, 23);
            this.button15.TabIndex = 85;
            this.button15.Text = "CsChat";
            this.button15.UseVisualStyleBackColor = true;
            this.button15.Click += new System.EventHandler(this.button15_Click);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(238, 216);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(30, 12);
            this.label13.TabIndex = 87;
            this.label13.Text = "Msg";
            // 
            // tbChat_Msg
            // 
            this.tbChat_Msg.Location = new System.Drawing.Point(280, 213);
            this.tbChat_Msg.Name = "tbChat_Msg";
            this.tbChat_Msg.Size = new System.Drawing.Size(129, 21);
            this.tbChat_Msg.TabIndex = 86;
            // 
            // btnLatency
            // 
            this.btnLatency.Enabled = false;
            this.btnLatency.Location = new System.Drawing.Point(908, 5);
            this.btnLatency.Name = "btnLatency";
            this.btnLatency.Size = new System.Drawing.Size(71, 23);
            this.btnLatency.TabIndex = 109;
            this.btnLatency.Text = "Latency";
            this.btnLatency.UseVisualStyleBackColor = true;
            this.btnLatency.Click += new System.EventHandler(this.button20_Click);
            // 
            // btnCreate
            // 
            this.btnCreate.Location = new System.Drawing.Point(1208, 7);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(71, 21);
            this.btnCreate.TabIndex = 326;
            this.btnCreate.Text = "Create";
            this.btnCreate.UseVisualStyleBackColor = true;
            this.btnCreate.Click += new System.EventHandler(this.button75_Click);
            // 
            // button74
            // 
            this.button74.Location = new System.Drawing.Point(13, 36);
            this.button74.Name = "button74";
            this.button74.Size = new System.Drawing.Size(215, 23);
            this.button74.TabIndex = 362;
            this.button74.Text = "FCMTokenSet";
            this.button74.UseVisualStyleBackColor = true;
            this.button74.Click += new System.EventHandler(this.button74_Click_1);
            // 
            // button76
            // 
            this.button76.Location = new System.Drawing.Point(13, 65);
            this.button76.Name = "button76";
            this.button76.Size = new System.Drawing.Size(215, 23);
            this.button76.TabIndex = 363;
            this.button76.Text = "FCMTokenUnset";
            this.button76.UseVisualStyleBackColor = true;
            this.button76.Click += new System.EventHandler(this.button76_Click);
            // 
            // label37
            // 
            this.label37.AutoSize = true;
            this.label37.Location = new System.Drawing.Point(241, 44);
            this.label37.Name = "label37";
            this.label37.Size = new System.Drawing.Size(40, 12);
            this.label37.TabIndex = 365;
            this.label37.Text = "Token";
            // 
            // tbFCMToken
            // 
            this.tbFCMToken.Location = new System.Drawing.Point(283, 41);
            this.tbFCMToken.Name = "tbFCMToken";
            this.tbFCMToken.Size = new System.Drawing.Size(32, 21);
            this.tbFCMToken.TabIndex = 364;
            this.tbFCMToken.Text = "0";
            // 
            // label43
            // 
            this.label43.AutoSize = true;
            this.label43.Location = new System.Drawing.Point(1110, 9);
            this.label43.Name = "label43";
            this.label43.Size = new System.Drawing.Size(33, 12);
            this.label43.TabIndex = 388;
            this.label43.Text = "Lang";
            // 
            // tbLang
            // 
            this.tbLang.Location = new System.Drawing.Point(1149, 6);
            this.tbLang.Name = "tbLang";
            this.tbLang.Size = new System.Drawing.Size(53, 21);
            this.tbLang.TabIndex = 387;
            this.tbLang.Text = "0";
            // 
            // label45
            // 
            this.label45.AutoSize = true;
            this.label45.Location = new System.Drawing.Point(238, 102);
            this.label45.Name = "label45";
            this.label45.Size = new System.Drawing.Size(61, 12);
            this.label45.TabIndex = 391;
            this.label45.Text = "Language";
            // 
            // tbLanguage
            // 
            this.tbLanguage.Location = new System.Drawing.Point(303, 99);
            this.tbLanguage.Name = "tbLanguage";
            this.tbLanguage.Size = new System.Drawing.Size(32, 21);
            this.tbLanguage.TabIndex = 390;
            this.tbLanguage.Text = "0";
            // 
            // button39
            // 
            this.button39.Location = new System.Drawing.Point(13, 94);
            this.button39.Name = "button39";
            this.button39.Size = new System.Drawing.Size(215, 23);
            this.button39.TabIndex = 389;
            this.button39.Text = "ChangeLanguage";
            this.button39.UseVisualStyleBackColor = true;
            this.button39.Click += new System.EventHandler(this.button39_Click);
            // 
            // cbServer
            // 
            this.cbServer.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbServer.FormattingEnabled = true;
            this.cbServer.Location = new System.Drawing.Point(564, 7);
            this.cbServer.Name = "cbServer";
            this.cbServer.Size = new System.Drawing.Size(338, 20);
            this.cbServer.TabIndex = 393;
            this.cbServer.SelectedIndexChanged += new System.EventHandler(this.CbServer_SelectedIndexChanged);
            // 
            // label74
            // 
            this.label74.AutoSize = true;
            this.label74.Location = new System.Drawing.Point(517, 11);
            this.label74.Name = "label74";
            this.label74.Size = new System.Drawing.Size(41, 12);
            this.label74.TabIndex = 394;
            this.label74.Text = "Server";
            // 
            // label87
            // 
            this.label87.AutoSize = true;
            this.label87.Location = new System.Drawing.Point(111, 245);
            this.label87.Name = "label87";
            this.label87.Size = new System.Drawing.Size(59, 12);
            this.label87.TabIndex = 416;
            this.label87.Text = "ProductID";
            // 
            // tbPurchaseProductID
            // 
            this.tbPurchaseProductID.Location = new System.Drawing.Point(211, 241);
            this.tbPurchaseProductID.Name = "tbPurchaseProductID";
            this.tbPurchaseProductID.Size = new System.Drawing.Size(198, 21);
            this.tbPurchaseProductID.TabIndex = 415;
            this.tbPurchaseProductID.Text = "0";
            // 
            // button82
            // 
            this.button82.Location = new System.Drawing.Point(13, 239);
            this.button82.Name = "button82";
            this.button82.Size = new System.Drawing.Size(92, 23);
            this.button82.TabIndex = 414;
            this.button82.Text = "CsPurchase";
            this.button82.UseVisualStyleBackColor = true;
            this.button82.Click += new System.EventHandler(this.Button82_Click);
            // 
            // label88
            // 
            this.label88.AutoSize = true;
            this.label88.Location = new System.Drawing.Point(111, 273);
            this.label88.Name = "label88";
            this.label88.Size = new System.Drawing.Size(94, 12);
            this.label88.TabIndex = 418;
            this.label88.Text = "PurchaseToken";
            // 
            // tbPurchaseToken
            // 
            this.tbPurchaseToken.Location = new System.Drawing.Point(211, 268);
            this.tbPurchaseToken.Name = "tbPurchaseToken";
            this.tbPurchaseToken.Size = new System.Drawing.Size(198, 21);
            this.tbPurchaseToken.TabIndex = 417;
            // 
            // button83
            // 
            this.button83.Location = new System.Drawing.Point(13, 4);
            this.button83.Name = "button83";
            this.button83.Size = new System.Drawing.Size(215, 23);
            this.button83.TabIndex = 419;
            this.button83.Text = "ClearLog";
            this.button83.UseVisualStyleBackColor = true;
            this.button83.Click += new System.EventHandler(this.Button83_Click);
            // 
            // label89
            // 
            this.label89.AutoSize = true;
            this.label89.Location = new System.Drawing.Point(111, 299);
            this.label89.Name = "label89";
            this.label89.Size = new System.Drawing.Size(16, 12);
            this.label89.TabIndex = 423;
            this.label89.Text = "ID";
            // 
            // tbGoodsID
            // 
            this.tbGoodsID.Location = new System.Drawing.Point(211, 295);
            this.tbGoodsID.Name = "tbGoodsID";
            this.tbGoodsID.Size = new System.Drawing.Size(195, 21);
            this.tbGoodsID.TabIndex = 422;
            this.tbGoodsID.Text = "0";
            // 
            // button84
            // 
            this.button84.Location = new System.Drawing.Point(13, 294);
            this.button84.Name = "button84";
            this.button84.Size = new System.Drawing.Size(92, 23);
            this.button84.TabIndex = 421;
            this.button84.Text = "BuyGoods";
            this.button84.UseVisualStyleBackColor = true;
            this.button84.Click += new System.EventHandler(this.Button84_Click);
            // 
            // button97
            // 
            this.button97.Location = new System.Drawing.Point(12, 123);
            this.button97.Name = "button97";
            this.button97.Size = new System.Drawing.Size(114, 23);
            this.button97.TabIndex = 479;
            this.button97.Text = "CanPushAtNight";
            this.button97.UseVisualStyleBackColor = true;
            this.button97.Click += new System.EventHandler(this.button97_Click);
            // 
            // tbCanPushAtNight
            // 
            this.tbCanPushAtNight.Location = new System.Drawing.Point(132, 125);
            this.tbCanPushAtNight.Name = "tbCanPushAtNight";
            this.tbCanPushAtNight.Size = new System.Drawing.Size(45, 21);
            this.tbCanPushAtNight.TabIndex = 480;
            this.tbCanPushAtNight.Text = "0";
            // 
            // pbBattle
            // 
            this.pbBattle.Location = new System.Drawing.Point(415, 36);
            this.pbBattle.Name = "pbBattle";
            this.pbBattle.Size = new System.Drawing.Size(518, 562);
            this.pbBattle.TabIndex = 481;
            this.pbBattle.TabStop = false;
            this.pbBattle.Paint += new System.Windows.Forms.PaintEventHandler(this.pbBattle_Paint);
            // 
            // btnBattleJoin
            // 
            this.btnBattleJoin.Location = new System.Drawing.Point(12, 323);
            this.btnBattleJoin.Name = "btnBattleJoin";
            this.btnBattleJoin.Size = new System.Drawing.Size(216, 23);
            this.btnBattleJoin.TabIndex = 482;
            this.btnBattleJoin.Text = "BattleJoin";
            this.btnBattleJoin.UseVisualStyleBackColor = true;
            this.btnBattleJoin.Click += new System.EventHandler(this.btnBattleJoin_Click);
            // 
            // btnBattleOut
            // 
            this.btnBattleOut.Location = new System.Drawing.Point(12, 352);
            this.btnBattleOut.Name = "btnBattleOut";
            this.btnBattleOut.Size = new System.Drawing.Size(216, 23);
            this.btnBattleOut.TabIndex = 483;
            this.btnBattleOut.Text = "BattleOut";
            this.btnBattleOut.UseVisualStyleBackColor = true;
            this.btnBattleOut.Click += new System.EventHandler(this.btnBattleOut_Click);
            // 
            // tbMemberCnt
            // 
            this.tbMemberCnt.Location = new System.Drawing.Point(326, 325);
            this.tbMemberCnt.Name = "tbMemberCnt";
            this.tbMemberCnt.Size = new System.Drawing.Size(35, 21);
            this.tbMemberCnt.TabIndex = 484;
            this.tbMemberCnt.Text = "1";
            // 
            // tbTeamCnt
            // 
            this.tbTeamCnt.Location = new System.Drawing.Point(367, 325);
            this.tbTeamCnt.Name = "tbTeamCnt";
            this.tbTeamCnt.Size = new System.Drawing.Size(39, 21);
            this.tbTeamCnt.TabIndex = 485;
            this.tbTeamCnt.Text = "2";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(234, 328);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(86, 12);
            this.label1.TabIndex = 486;
            this.label1.Text = "MemTeamCnt";
            // 
            // btnSelectChar
            // 
            this.btnSelectChar.Location = new System.Drawing.Point(12, 381);
            this.btnSelectChar.Name = "btnSelectChar";
            this.btnSelectChar.Size = new System.Drawing.Size(216, 23);
            this.btnSelectChar.TabIndex = 487;
            this.btnSelectChar.Text = "SelectChar";
            this.btnSelectChar.UseVisualStyleBackColor = true;
            this.btnSelectChar.Click += new System.EventHandler(this.btnSelectChar_Click);
            // 
            // tbCharCode
            // 
            this.tbCharCode.Location = new System.Drawing.Point(302, 383);
            this.tbCharCode.Name = "tbCharCode";
            this.tbCharCode.Size = new System.Drawing.Size(35, 21);
            this.tbCharCode.TabIndex = 488;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(234, 386);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(62, 12);
            this.label2.TabIndex = 489;
            this.label2.Text = "CharCode";
            // 
            // btnRankingConnect
            // 
            this.btnRankingConnect.Location = new System.Drawing.Point(13, 410);
            this.btnRankingConnect.Name = "btnRankingConnect";
            this.btnRankingConnect.Size = new System.Drawing.Size(216, 23);
            this.btnRankingConnect.TabIndex = 491;
            this.btnRankingConnect.Text = "RankingConnect";
            this.btnRankingConnect.UseVisualStyleBackColor = true;
            this.btnRankingConnect.Click += new System.EventHandler(this.btnRankingConnect_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(235, 444);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 12);
            this.label3.TabIndex = 494;
            this.label3.Text = "Index";
            // 
            // tbGachaIndex
            // 
            this.tbGachaIndex.Location = new System.Drawing.Point(303, 441);
            this.tbGachaIndex.Name = "tbGachaIndex";
            this.tbGachaIndex.Size = new System.Drawing.Size(35, 21);
            this.tbGachaIndex.TabIndex = 493;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(13, 439);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(216, 23);
            this.button1.TabIndex = 492;
            this.button1.Text = "Gacha";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(13, 468);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(216, 23);
            this.button2.TabIndex = 495;
            this.button2.Text = "RankReward";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(12, 497);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(216, 23);
            this.button3.TabIndex = 496;
            this.button3.Text = "ChangeNick";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // tbChangeNick
            // 
            this.tbChangeNick.Location = new System.Drawing.Point(300, 499);
            this.tbChangeNick.Name = "tbChangeNick";
            this.tbChangeNick.Size = new System.Drawing.Size(109, 21);
            this.tbChangeNick.TabIndex = 497;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(238, 502);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(36, 12);
            this.label4.TabIndex = 498;
            this.label4.Text = "Index";
            // 
            // GameClientTest
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1507, 845);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.tbChangeNick);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.tbGachaIndex);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnRankingConnect);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.tbCharCode);
            this.Controls.Add(this.btnSelectChar);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbTeamCnt);
            this.Controls.Add(this.tbMemberCnt);
            this.Controls.Add(this.btnBattleOut);
            this.Controls.Add(this.btnBattleJoin);
            this.Controls.Add(this.pbBattle);
            this.Controls.Add(this.tbCanPushAtNight);
            this.Controls.Add(this.button97);
            this.Controls.Add(this.label89);
            this.Controls.Add(this.tbGoodsID);
            this.Controls.Add(this.button84);
            this.Controls.Add(this.button83);
            this.Controls.Add(this.label88);
            this.Controls.Add(this.tbPurchaseToken);
            this.Controls.Add(this.label87);
            this.Controls.Add(this.tbPurchaseProductID);
            this.Controls.Add(this.button82);
            this.Controls.Add(this.label74);
            this.Controls.Add(this.cbServer);
            this.Controls.Add(this.label45);
            this.Controls.Add(this.tbLanguage);
            this.Controls.Add(this.button39);
            this.Controls.Add(this.label43);
            this.Controls.Add(this.tbLang);
            this.Controls.Add(this.label37);
            this.Controls.Add(this.tbFCMToken);
            this.Controls.Add(this.button76);
            this.Controls.Add(this.button74);
            this.Controls.Add(this.btnCreate);
            this.Controls.Add(this.btnLatency);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.tbChat_Msg);
            this.Controls.Add(this.button15);
            this.Controls.Add(this.btnLogin);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.tbID);
            this.Controls.Add(this.txtLog);
            this.Controls.Add(this.btnDisconnect);
            this.KeyPreview = true;
            this.Name = "GameClientTest";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.GalaxyClient_FormClosing);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.GameClientTest_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.GameClientTest_KeyUp);
            ((System.ComponentModel.ISupportInitialize)(this.pbBattle)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer TimerNet;
        private System.Windows.Forms.Button btnDisconnect;
        private System.Windows.Forms.TextBox txtLog;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox tbID;
        private System.Windows.Forms.Button btnLogin;
        private System.Windows.Forms.Button button15;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox tbChat_Msg;
        private System.Windows.Forms.Button btnLatency;
        private System.Windows.Forms.Button btnCreate;
        private System.Windows.Forms.Button button74;
        private System.Windows.Forms.Button button76;
        private System.Windows.Forms.Label label37;
        private System.Windows.Forms.TextBox tbFCMToken;
        private System.Windows.Forms.Label label43;
        private System.Windows.Forms.TextBox tbLang;
        private System.Windows.Forms.Label label45;
        private System.Windows.Forms.TextBox tbLanguage;
        private System.Windows.Forms.Button button39;
        private System.Windows.Forms.ComboBox cbServer;
        private System.Windows.Forms.Label label74;
        private System.Windows.Forms.Label label87;
        private System.Windows.Forms.TextBox tbPurchaseProductID;
        private System.Windows.Forms.Button button82;
        private System.Windows.Forms.Label label88;
        private System.Windows.Forms.TextBox tbPurchaseToken;
        private System.Windows.Forms.Button button83;
        private System.Windows.Forms.Label label89;
        private System.Windows.Forms.TextBox tbGoodsID;
        private System.Windows.Forms.Button button84;
        private System.Windows.Forms.Button button97;
        private System.Windows.Forms.TextBox tbCanPushAtNight;
        private System.Windows.Forms.PictureBox pbBattle;
        private System.Windows.Forms.Button btnBattleJoin;
        private System.Windows.Forms.Button btnBattleOut;
        private System.Windows.Forms.TextBox tbMemberCnt;
        private System.Windows.Forms.TextBox tbTeamCnt;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnSelectChar;
        private System.Windows.Forms.TextBox tbCharCode;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnRankingConnect;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tbGachaIndex;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.TextBox tbChangeNick;
        private System.Windows.Forms.Label label4;
    }
}

