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

//onActiveをfalseにする
void BOSS::Load_OnActive(bool setOnActive) {
	onAcitve = setOnActive;
}

//atkActiveをtrueにする
void BOSS::Load_AtkActive(bool setAtkActive) {
	atkActive = setAtkActive;
}

//初期化処理
void BOSS::Init(int ix, int iy) {

	int initAni[29] = { 0,1,2,3,4,5,6,7,8,9,10,11,10,11,10,11,10,11,10,9,8,7,6,5,4,3,2,1,0 };

	LoadDivGraph("./res/img/Galaga_OBJ_effect.png", 12, 5, 3, 51, 83, tGh);    // 画像の分割読み込み

	for (int i = 0; i < 29; i++) {
		ani[i] = initAni[i];
	}

	x = ix;					//x座標の初期化
	y = iy;					//y座標の初期化
	width = 30;				//横幅
	height = 30;			//高さ
	durability = 2;			//耐久力
	atkActive = false;		//攻撃判定
	onAcitve = true;		//生存判定
	beamCnt = 0;			//トラクタービームカウント
	beamOrder = 0;			//表示する場所指定
	bcnt = 0;				//アニメーション用フラグ
	tractorFlg = false;		//トラクタービームが発射してるか判定
}

//終了処理
void BOSS::Final() {

}

//トラクタービーム発射処理
void BOSS::Tractor_Beam() {

	beamCnt++;

	if (beamCnt > 100)beamCnt = 100;

	if (beamCnt == 100) {

		bcnt++;

		if (bcnt >= 10)beamOrder++, bcnt = 0;

		if (beamOrder >= 27)beamOrder = 0, beamCnt = 0;

	}
}

void BOSS::Tractor_Move() {
	if (y < (double)600 + height)y++;
}

//更新処理
void BOSS::Update() {

	if (atkActive == true) {
		tractorFlg = true;
	}

	if (tractorFlg == true) {
		Tractor_Beam();
		Tractor_Move();
	}
}

//描画処理
void BOSS::Draw() {

	if (onAcitve == true) {
		DrawRotaGraph(x, y, 2.0, 0, gh[0], TRUE);
		DrawGraph(x - (double)13 * 2, y - 5, tGh[ani[beamOrder]], TRUE); // 画像を表示
	}
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

int BOSS::Send_Width() {
	return width;
}

int BOSS::Send_Height() {
	return height;
}