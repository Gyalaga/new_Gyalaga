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

void CONTROL::PlayerGet(int Px,int Py) 
{
	 A = Px;
	 S = Py;
	//DrawFormatString(850, 40, GetColor(255, 255, 255), "%d", A);//確認用
	//DrawFormatString(850, 80, GetColor(255, 255, 255), "%d", S);//確認用
}

//ゲームの全体制御
void CONTROL::GameControl() {
	Player_All();
	enemyMgr->Update();
	enemyMgr->Draw();
	enemyMgr->Send_Coordinate(ex, ey);
	Score_Save();
	Score_Draw();
}