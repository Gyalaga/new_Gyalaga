#include "DxLib.h"
#include"Shot_Extern.h"
int Shot_Check(int px,int py) {

	//スペースキーを押されたときに弾をプレイヤーの中心座標にセットする
	if (CheckHitKey(KEY_INPUT_SPACE)) {

		//画面上に出てない弾があるか、弾の数だけくり返し調べる
		for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) { 

			//前のフレームでスペースキーを押したかが
			//保存されている変数が0だったら弾を発射
			if (bullet.sf2 == 0) { 

				//弾が画面上に出てない場合はその弾を画面に出す
				if (bullet.sf[bullet.bi] == 0) { 

					//弾は存在するので、存在状態を保持する変数に1を代入する
					bullet.sf[bullet.bi] = 1;

					//弾の位置を自機の中心にする
					bullet.sx[bullet.bi] = px;
					bullet.sy[bullet.bi] = py;
					PlaySoundFile("./res/wav/gal_se_fighter_shot.wav", DX_PLAYTYPE_BACK);
					break;//弾を1つ出したのでループから抜け出す
				}
			}
		}
		//前のフレームでショットボタンを押されていたかを
		//保持する変数に1（押されていた）を代入する
		bullet.sf2 = 1;
	}

	/*前のフレームでスペースキーを押されていなかった場合は
	  スペースキーを押されていたかを
	  保持する変数に0（押されていない）を代入する*/
	else { bullet.sf2 = 0; }

	
	return 0;
}

int Shot_draw() {

	//弾の数だけ弾を動かす処理
	for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {

		//弾が存在するときに行う
		if (bullet.sf[bullet.bi] == 1) {

			//弾[i]の座標を10ドットずつ動かす
			bullet.sy[bullet.bi] -= 10;

			//画面外に出た時存在を保持している変数を0(存在しない)にする
			if (bullet.sy[bullet.bi] < -50) {
				bullet.sf[bullet.bi] = 0;
			}
		}
	}

	//弾の数だけ描画する
	for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {
		if (bullet.sf[bullet.bi] == 1) {
			DrawRotaGraph(bullet.sx[bullet.bi], bullet.sy[bullet.bi],2,0, shot, TRUE);
		}
	}
	return 0;
}