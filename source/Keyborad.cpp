#include "DxLib.h"
#include "Keyborad.h"

//キー入力
int Key[256];  //0:入力されてない
			   //1:入力された瞬間
			   //2:入力されている
char Keyset[256];

//キーの入力状態を更新
void Keyborad() {

	GetHitKeyStateAll(Keyset);  // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++) {

		if (Keyset[i] != 0) { //i番のキーコードに対応するキーが押されていたら
			Key[i]++;         //加算
		}
		else {                //押されていなければ
			Key[i] = 0;       //0にする
		}
	}
}

// KeyCodeのキーの入力状態を取得する

int Key_get(int KeyCode) {

	return Key[KeyCode];
}
