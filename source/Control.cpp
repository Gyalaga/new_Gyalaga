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
	Player_judgment(&px,&py, &pw, &ph, &sx, &sy, &sw, &sh, &sx2, &sy2,&hf);
	enemyMgr->Update();
	enemyMgr->Draw();
	enemyMgr->Send_Coordinate(ex, ey, eWidth, eHeight);
	Score_Save();
	Score_Draw();
	Hit_Judgment();
	DrawFormatString(0, 160, GetColor(255, 255, 255), "%d", c.c);
	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d",px,py);
	DrawFormatString(50, 540, GetColor(255, 255, 255), "%f,%f", ex[20], ey[20]);

}

//当たり判定処理
void CONTROL::Hit_Judgment() {
	for (int i = 0; i < 40; i++) {
		if (CheckHitKey(KEY_INPUT_Q))hitCheck[i] = false;       //確認用
		//もしも当たっていること
		if (hitCheck[i] == true)continue;

		if (hf == 0 && hitCheck[i] == false && (double)px + pw >= ex[i] && (double)px <= ex[i] + eWidth[i] && (double)py + ph >= ey[i] && (double)py <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(hit, i);
			hitCheck[i] = true;
			c.c = 1;
			Player_hit(c.c);
			hf = 1;
			Player_hitflg(hf);
		}
		if (hitCheck[i] == false && bullet.sf[0] == 1 && (double)sx + sw >= ex[i] && (double)sx <= ex[i] + eWidth[i] && (double)sy+sh  >= ey[i] && (double)sy+sh <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(hit, i);
			hitCheck[i] = true;
			bullet.sf[0] = 0;
			score += 100;
		    Score_up(score);
		}
		if (hitCheck[i] == false && bullet.sf[1] == 1 && (double)sx2 + sw >= ex[i] && (double)sx2 <= ex[i] + eWidth[i] && (double)sy2+sh >= ey[i] && (double)sy2+sh <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(hit, i);
			hitCheck[i] = true;
			bullet.sf[1] = 0;
			score += 100;
			Score_up(score);
		}
		DrawFormatString(50, 640, GetColor(255, 255, 255), "%d", hf);
	}
}