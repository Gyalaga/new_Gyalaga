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

//エネミー管理クラスから全体の移動量を取得する
void BOSS::Load_AddMove(int addMove) {
	
	allMoveAmount = addMove;

	//攻撃中ではない場合
	if (atkActive == false) {
		Overall_Move();
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
	DrawRotaGraph(x, y, 2.0, 0, gh[0], TRUE);
}

//全体の動き
void BOSS::Overall_Move() {
	x += allMoveAmount;
}

//x座標を送る処理
double BOSS::Send_X() {
	return x;
}

//y座標を送る処理
double BOSS::Send_Y() {
	return y;
}