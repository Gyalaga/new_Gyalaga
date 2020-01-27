#include "Control.h"
#include "Score.h"
#include "DxLib.h"
//コントロールクラスのコンストラクタ
CONTROL::CONTROL() {
	enemyMgr = new ENEMYMGR;
}

//コントロールクラスのデストラクタ
CONTROL::~CONTROL() {
	delete enemyMgr;
}

//ゲームの全体制御
void CONTROL::GameControl() {
    Player_All();
	Player_judgment(&px,&py);
	enemyMgr->Update();
	enemyMgr->Draw();
	enemyMgr->Send_Coordinate(ex, ey);
	Score_Save();
	Score_Draw();
	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d",px,py);
}