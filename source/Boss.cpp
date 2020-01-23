#include "Boss.h"
#include "DxLib.h"

//コンストラクタ
BOSS::BOSS(int getX, int getY) {
	Init(getX, getY);
}

//エネミー管理クラスから画像を読み込む
void BOSS::Load_Image(int* sGh) {

	for (int i = 0; i < 10; i++) {
		gh[i] = *(sGh + i);
	}
}

//初期化処理
void BOSS::Init(int ix, int iy) {
	x			= ix;		//x座標の初期化
	y			= iy;		//y座標の初期化
	width		= 18;		//横幅
	height		= 18;		//高さ
	durability	= 1;		//耐久力
	atkActive	= false;	//攻撃判定
	onAcitve	= true;		//生存判定
}

//終了処理
void BOSS::Final() {

}

//更新処理
void BOSS::Update() {

}

//描画処理
void BOSS::Draw() {
	DrawGraph(x, y, gh[0], TRUE);
}