#include "DxLib.h"
#include"Shot_Extern.h"

int Shot_init() {
	int i;
	shot = LoadGraph("bullet.png");

	//弾が画面上に存在しているか保持する変数に
	//「存在していない」を意味する0を代入しておく

	for (i = 0; i < SHOT; i++) {
		bullet.sf[i] = 0;
	}

	//ショットボタンを前のフレームで押されたかどうかを保持する
	//変数に0（押されていない）を代入

	bullet.sf2 = 0;
	return 0;
}