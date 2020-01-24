#include "Zako.h"
#include "DxLib.h"
#include<math.h>
#define PI 3.1415926f
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
	Roto_x      = 2.0;      //Roto_x座標の初期値
	Roto_y      = 0;      //Roto_y座標の初期値
	angle       = 0;        //angleの初期値
	R           = 200;      //ラジアンの初期値
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

void ZAKO::Atacck(bool atk) {

	atkActive = atk;

	if (atkActive == true) {
		x += sin(PI * sincount / 400.0f) * 3.5f;
		y += 2.5f;
	}
}

//描画処理
void ZAKO::Draw() {
	DrawRotaGraph(x, y, Roto_x,Roto_y,gh[0], TRUE);
	sincount += 1;
	angle += 1;
	//DrawGraph(Move_x, Move_y, gh[1], TRUE);
}

//全体の動き
void ZAKO::Overall_Move() {
	
	x += allMoveAmount;
}