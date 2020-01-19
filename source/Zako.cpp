#include "Zako.h"
#include "DxLib.h"

//コンストラクタ
ZAKO::ZAKO(int getX, int getY) {
	Init(getX, getY);
}

//エネミー管理クラスから画像を読み込む
void ZAKO::Load_Image(int* sGh) {

	for (int i = 0; i < 5; i++) {
		gh[i] = *(sGh + i);
	}
}

//初期化処理
void ZAKO::Init(int ix,int iy) {
	x		= ix;	//x座標の初期化
	y		= iy;	//y座標の初期化
	width	= 18;	//横幅
	height	= 18;	//高さ
}

//終了処理
void ZAKO::Final() {

}

//更新処理
void ZAKO::Update() {

}

//描画処理
void ZAKO::Draw() {
	DrawGraph(x, y, gh[0], TRUE);
}