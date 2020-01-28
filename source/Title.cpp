#include "DxLib.h"
#include "SceneMgr.h"
#include "Title.h"
#include "Keyborad.h"
#include "Score.h"


TITLE::TITLE(ISCENECHANGER* changer) :BASESCENE(changer) {

}

void TITLE::Update() {

	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
		mSceneChanger->ChangeScene(eScene_Game);
	}

	if (Key_get(KEY_INPUT_DOWN) == 1) {//下キーが押されていたら
		Select = (Select + 1) % eMenu_Num;//選択状態を一つ下げる
	}
	if (Key_get(KEY_INPUT_UP) == 1) {//上キーが押されていたら
		Select = (Select + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
	}
	if (Key_get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されたら

		switch (Select) {                            //現在選択中の状態によって処理を分岐
		case eMenu_1PLAYER:                           //ゲーム選択中なら
			PLAYER1_Y = 1170;
			PLAYER2_Y = 1210;
			mSceneChanger->ChangeScene(eScene_Game);
			break;
		case eMenu_2PLAYER://設定選択中なら
			PLAYER1_Y = 1170;
			PLAYER2_Y = 1210;
			mSceneChanger->ChangeScene(eScene_Game);
			break;
		}
	}
}

void TITLE::Draw() {
	static int title = LoadGraph("./res/img/Gyaraga.jpg"); static int namuco = LoadGraph("./res/img/NAMUCO.png");
	static int player1 = LoadGraph("./res/img/PLAYER1.png"); static int player2 = LoadGraph("./res/img/PLAYER2.png");
	static int score1 = LoadGraph("./res/img/1UP.png"); static int score2 = LoadGraph("./res/img/2UP.png");
	static int hiscore = LoadGraph("./res/img/HISCORE.png");

	/*********隠しスコア*********/
	if (ONEUP_Y >= 50) {
		Score_Title();
	}
	if (ONEUP_Y > 50) {
		SetDrawScreen(DX_SCREEN_BACK);  //塗りつぶし                        
		DrawBox(800, 90, 100, 110, GetColor(0, 0, 0), TRUE);
	}
	/*****************************/
	/***タイトルロゴ***/
	DrawGraph(240, TITLE_Y, title, TRUE);
	if (TITLE_Y > 150) {
		TITLE_Y -= 2;
	}
	/*****************************/

	/***1Pスコア&2Pスコア***/
	DrawGraph(100, ONEUP_Y, score1, TRUE);
	DrawGraph(625, TWOUP_Y, score2, TRUE);
	if (ONEUP_Y > 50) {
		ONEUP_Y -= 2;
		TWOUP_Y -= 2;
	}

	if (ONEUP_Y == 50) {
		Score_Title();
	}
	/*****************************/

	/***ハイスコア***/
	DrawGraph(300, SCORE_Y, hiscore, TRUE);
	if (SCORE_Y > 50) {
		SCORE_Y -= 2;
	}
	/*****************************/

	/***1プレイヤー&2プレイヤー***/
	DrawGraph(300, PLAYER1_Y, player1, TRUE);
	DrawGraph(300, PLAYER2_Y, player2, TRUE);
	if (PLAYER1_Y > 420) {
		PLAYER1_Y -= 2;
	}
	if (PLAYER2_Y > 460) {
		PLAYER2_Y -= 2;
	}
	/*****************************/

	/***ナムコ***/
	DrawGraph(150, NAMCO_Y, namuco, TRUE);
	if (NAMCO_Y > 600) {
		NAMCO_Y -= 2;
	}
	/*****************************/

	int y = 0;
	switch (Select) {
	case eMenu_1PLAYER: //1PLAYERを選択中なら
		y = PLAYER1_Y;
		break;
	case eMenu_2PLAYER: //2PLAYERを選択中なら
		y = PLAYER2_Y;
		break;
	}
	DrawString(250, y, "■", GetColor(255, 255, 255));

}