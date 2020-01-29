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

//ダメージを受ける処理
void BOSS::Load_Damage(int damage) {
	durability -= damage;

	if (durability == 1) {
		changeMode = true;
	}
}

//アニメーション処理
void BOSS::Load_Interval(int interval) {

	if (atkActive == false) {

		if (durability == 2) {
			if (interval == 120) {
				moveAni = 1;
			}
			else if (interval == 240) {
				moveAni = 0;
			}
		}
		else if (durability == 1) {
			if (interval == 120) {
				moveAni = 6;
			}
			else if (interval == 240) {
				moveAni = 5;
			}
		}
		aniOrder = moveAni;
	}
}

//atkActiveをtrueにする
void BOSS::Load_AtkActive(bool setAtkActive) {

	if (onAcitve == true) {
		atkActive = setAtkActive;
	}
}

//初期化処理
void BOSS::Init(int ix, int iy) {

	int initAni[29] = { 0,1,2,3,4,5,6,7,8,9,10,11,10,11,10,11,10,11,10,9,8,7,6,5,4,3,2,1,0 };

	LoadDivGraph("./res/img/Galaga_OBJ_effect.png", 12, 5, 3, 51, 83, tGh);    // 画像の分割読み込み

	for (int i = 0; i < 29; i++) {
		tractorAni[i] = initAni[i];
	}

	x = ix;					//x座標の初期化
	y = iy;					//y座標の初期化
	width = 30;				//横幅
	height = 30;			//高さ
	aniOrder = 0;			//描画する画像番号
	moveAni = 0;			//全体の動きのアニメーション
	durability = 2;			//耐久力
	atkActive = false;		//攻撃判定
	onAcitve = true;		//生存判定
	beamCnt = 0;			//トラクタービームカウント
	beamOrder = 0;			//表示する場所指定
	bcnt = 0;				//アニメーション用フラグ
	tractorFlg = false;		//トラクタービームが発射してるか判定
	changeMode = false;		//第二形態用
	biimflg = false;        //当たり判定用
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
		if (tractorAni[beamOrder] >= 8)
		{
			biimflg = true;
		}
		else
		{
			biimflg = false;
		}
		if (beamOrder >= 27)beamOrder = 0, beamCnt = 0;

	}
}

void BOSS::Tractor_Move() {
	if (y < (double)600 + height)y++;
}

//更新処理
void BOSS::Update() {

	if (durability == 1 && changeMode == true) {

		if (aniOrder == 0) {
			aniOrder = 5;
		}
		else if (aniOrder == 1) {
			aniOrder = 6;
		}

		changeMode = false;
	}

	//onActiveをfalseにする
	if (durability == 0 && onAcitve == true) {
		onAcitve = false;
		atkActive = false;
		tractorFlg = false;
		PlaySoundFile("./res/wav/gal_se_boss_striken_2.wav", DX_PLAYTYPE_BACK);
	}

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
		DrawRotaGraph(x, y, 2.0, 0, gh[aniOrder], TRUE);
	}
	if (tractorFlg == true) {
		DrawGraph(x - (double)13 * 2, y - 5, tGh[tractorAni[beamOrder]], TRUE); // 画像を表示
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

//横幅を送る処理
int BOSS::Send_Width() {
	return width;
}

//高さを送る処理
int BOSS::Send_Height() {
	return height;
}

//onActiveを送る処理
bool BOSS::Send_OnActive() {
	return onAcitve;
}
//biimflgを送る処理
bool BOSS::Yes_OnActive() {
	return biimflg;
}