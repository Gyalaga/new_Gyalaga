#include "Control.h"
#include "DxLib.h"
//コントロールクラスのコンストラクタ
CONTROL::CONTROL() {
	enemyMgr = new ENEMYMGR;
	hit = false;

	for (int i = 0; i < 40; i++) {
		hitCheck[i] = false;
	}

}

//コントロールクラスのデストラクタ
CONTROL::~CONTROL() {
	delete enemyMgr;
}

//ゲームの全体制御
void CONTROL::GameControl() {
    Player_All();
	Player_judgment(&px,&py, &pw, &ph, &sx, &sy, &sw, &sh, &sx2, &sy2);
	enemyMgr->Update();
	enemyMgr->Draw();
	enemyMgr->Send_Coordinate(ex, ey, eWidth, eHeight);
	Score_Save();
	Score_Draw();
	Hit_Judgment();

	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d",px,py);
	DrawFormatString(50, 540, GetColor(255, 255, 255), "%f,%f", ex[20], ey[20]);

}

//当たり判定処理
void CONTROL::Hit_Judgment() {

	for (int i = 0; i < 40; i++) {

		//もしも当たっていること
		if (hitCheck[i] == true)continue;

		if ((double)px + pw >= ex[i] && (double)px <= ex[i] + eWidth[i] && (double)py + ph >= ey[i] && (double)py <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(hit, i);
			hitCheck[i] = true;
			c.c = 1;
			return Player_hit(c.c);
		}
		if (hitCheck[i] == false && bullet.sf[0] == 1 && (double)sx + sw >= ex[i] && (double)sx <= ex[i] + eWidth[i] && (double)sy+sh  >= ey[i] && (double)sy+sh <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(hit, i);
			hitCheck[i] = true;
			bullet.sf[0] = 0;
			score += 100;
			return Score_up(score);
		}
		if (hitCheck[i] == false && bullet.sf[1] == 1 && (double)sx2 + sw >= ex[i] && (double)sx2 <= ex[i] + eWidth[i] && (double)sy2+sh >= ey[i] && (double)sy2+sh <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(hit, i);
			hitCheck[i] = true;
			bullet.sf[1] = 0;
			score += 100;
			return Score_up(score);
		}
	}
}