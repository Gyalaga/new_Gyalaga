#include "Control.h"
#include "Score.h"
#include "DxLib.h"
//コントロールクラスのコンストラクタ
CONTROL::CONTROL() {
	enemyMgr = new ENEMYMGR;
	flg = 0;
}

//コントロールクラスのデストラクタ
CONTROL::~CONTROL() {
	delete enemyMgr;
}

//ゲームの全体制御
void CONTROL::GameControl() {
    Player_All();
	Player_judgment(&px,&py, &pw, &ph, &sx, &sy, &sw, &sh);
	enemyMgr->Update();
	enemyMgr->Draw();
	enemyMgr->Send_Coordinate(ex, ey, eWidth, eHeight);
	Score_Save();
	Score_Draw();

	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d",px,py);
	DrawFormatString(50, 450, GetColor(255, 255, 255), "%d", flg);

	if (flg == 1) {
		DrawString(0, 0, "動きました", GetColor(255, 255, 255));
	}

}

void CONTROL::Hit_Judgment() {
	/*
	for (int i = 0; i < 40; i++) {
		if (px + 32 >= ex[i] && px <= ex[i] + eWidth[i] && py + 32 >= ex[i] && py <= ey[i] + eHeight[i]) {
			flg = 1;
		}
	}
	*/
	DrawFormatString(50, 620, GetColor(255, 255, 255), "%d,%d,%d,%d",sx, sy, sw, sh);
	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d,%d,%d",px,py,pw,ph);
}