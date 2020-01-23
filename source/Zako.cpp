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

//エネミー管理クラスから全体の移動量を取得する
void ZAKO::Load_AddMove(int addMove) {

	allMoveAmount = addMove;	//全体の移動量をザコクラスに適用させる

	//攻撃中ではない場合
	if (atkActive == false) {
		Overall_Move();
	}

}

//初期化処理
void ZAKO::Init(int ix,int iy) {
	x			= ix;		//x座標の初期化
	y			= iy;		//y座標の初期化
	width		= 18;		//横幅
	height		= 18;		//高さ
	durability	= 1;		//耐久力
	atkActive	= false;	//攻撃判定
	onAcitve	= true;		//生存判定
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
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%d", allMoveAmount);
}

//全体の動き
void ZAKO::Overall_Move() {
	
	x += allMoveAmount;
}