#include"DxLib.h"
#include"Scene_mgr.h"
#include"Title.h"
#include"Keyborad.h"

int PLAYER1_Y = 1170;    //「1PLAYER」文字のy座標
int PLAYER2_Y = 1210;   //「2PLAYER」文字のy座標
int TITLE_Y = 900;   //「タイトルロゴ」のy座標
int SCORE_Y = 800;   //「HI-SCORE」のｙ座標
int ONEUP_Y = 800;   //「1UP」のｙ座標
int TWOUP_Y = 800;   //「2UP」のｙ座標
int NAMCO_Y = 1350;  //「namco」のｙ座標

static int Select = eMenu_1PLAYER;

void Title_update() {
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
			Scene_change(eScene_GAME);       //シーンをゲーム画面に変更
			break;
		case eMenu_2PLAYER://設定選択中なら
			PLAYER1_Y = 1170;
			PLAYER2_Y = 1210;
			Scene_change(eScene_GAME);    //シーンを設定画面に変更
			break;
		}
	}

}

void Title_draw() {
	static int title = LoadGraph("./res/img/Gyaraga.jpg"); static int namuco = LoadGraph("./res/img/NAMUCO.png");
	static int player1 = LoadGraph("./res/img/PLAYER1.png"); static int player2 = LoadGraph("./res/img/PLAYER2.png");
	static int score1 = LoadGraph("./res/img/1UP.png"); static int score2 = LoadGraph("./res/img/2UP.png");
	static int hiscore = LoadGraph("./res/img/HISCORE.png");

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