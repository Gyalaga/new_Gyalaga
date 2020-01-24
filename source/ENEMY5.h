#pragma once
#include <windows.h>

/*画像・データ*/
class ENEMY {
private:
	int  enemy[5];           //画像配列
	RECT rect[5];            //画像の矩形
	double enemy_x, enemy_y; //エネミー座標
	int zome;                //拡大率
	double angle;            //描画角度
	int width, height;       //キャラクタの幅と高さ
	int count;               //カウンタ変数
	int direction;           //現在向いている方向
							 //(0:STOP 1:← 2:↖ 3:↑ 4:↗ 5:→ 6:↘ 7:↓ 8:↙ 
	bool endflag;
public:
	void Enemy_move();
	void Enemy_draw();
	bool Enemy_all();
	ENEMY();
};
