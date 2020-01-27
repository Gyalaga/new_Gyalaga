#include "DxLib.h"
#include"Shot_Extern.h"

int Shot_init() {
	shot = LoadGraph("./res/img/bullet.png");

	//弾が画面上に存在しているか保持する変数に
	//「存在していない」を意味する0を代入しておく

	for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {
		bullet.sf[bullet.bi] = 0;
	}

	//ショットボタンを前のフレームで押されたかどうかを保持する
	//変数に0（押されていない）を代入

	bullet.sf2 = 0;
	return 0;
}