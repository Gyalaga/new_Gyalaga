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

	enemyMgr->Update();
	enemyMgr->Draw();
	Score_Draw();
}