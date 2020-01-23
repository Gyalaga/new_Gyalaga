#include "Goei.h"
#include "DxLib.h"

//コンストラクタ
GOEI::GOEI(int getX, int getY) {
	Init(getX, getY);
}

//エネミー管理クラスから画像を読み込む
void GOEI::Load_Image(int* sGh) {
	
	for (int i = 0; i < 5; i++) {
		gh[i] = *(sGh + i);
	}
}

//初期化処理
void GOEI::Init(int ix, int iy) {
	x			= ix;		//x座標
	y			= iy;		//y座標
	width		= 18;		//横幅
	height		= 18;		//高さ
	durability	= 1;		//耐久力
	atkActive	= false;	//攻撃判定
	onAcitve	= true;		//生存判定
}

//終了処理
void GOEI::Final() {

}

//更新処理
void GOEI::Update() {

}

//描画処理
void GOEI::Draw() {
	DrawGraph(x, y, gh[0], TRUE);
}