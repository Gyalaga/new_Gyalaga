#include "Control.h"
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
	enemyMgr->Update();
	enemyMgr->Draw();
}