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

//onActiveをfalseにする
void ZAKO::Load_OnActive(bool setOnActive) {
	onAcitve = setOnActive;
}

//初期化処理
void ZAKO::Init(int ix,int iy) {
	x			= ix;		//x座標の初期化
	y			= iy;		//y座標の初期化
	Rota_zome   = 2.0;      //拡大率
	Rota_angle  = 0;        //描画角度
	angle       = 75;       //angleの初期値
	R           = 200;      //ラジアンの初期値
	i           = 0;        //ザコの画像を切り替えるよう
	width		= 18;		//横幅
	height		= 18;		//高さ
	FLAG_X      = 800;      //zakoflgで使う値
	FLAG_Y      = 200;      //zakoflgで使う値
	durability	= 1;		//耐久力
	atkActive	= false;	//攻撃判定
	onAcitve	= true;		//生存判定
	zakoflg     = 0;        //ザコ敵の挙動を変えるフラグ
	                        //0:回転移動 1:曲線移動 2:なんか 3:なんか
}

//終了処理
void ZAKO::Final() {

}

//更新処理
void ZAKO::Update() {

}

/******************
void ZAKO::Atacck(bool atk) {

	atkActive = atk;

	if (atkActive == true) {
		//Draw_angle();

		if (FLAG_Y <= y && zakoflg == 0) {
			zakoflg = 1;
			FLAG_Y = 550;
		}
		if (FLAG_Y <= y && zakoflg == 1) {
			zakoflg = 2;
			angle = -90;
			R = 150;
		}
		if (y >= 1120) {
			x = 350;
			y = -50;
			if (y < 120) {
				y += 2;
				x -= 2;
			}
			else {
				atkActive = false;
			}
		}

		if (zakoflg == 0) {
			x += -R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			//sin(PI * sincount / 80.0f) * 2.0f;
			y += -R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			//1.5f;
			angle += 1;
			Rota_angle -= 0.03;
		}
		if (zakoflg == 1) {

			x += 2.5;//sin(PI * sincount / 80.0f) * 2.0f;
			y += 1.5f;
		}
		if (zakoflg == 2) {

			x += R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y += R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 2;
			Rota_angle -= 0.06;
			if (angle >= 200 && zakoflg == 2) {
				zakoflg = 3;
			}
		}
		if (zakoflg == 3) {
			x -= sin(PI * sincount / 100.0f) * 2.0f;
			y += 2.5f;
			Rota_angle += 0.01;
		}
	}
}
***********/

//描画処理
void ZAKO::Draw() {

	if (onAcitve == true) {
		DrawRotaGraph(x, y, Rota_zome, Rota_angle, gh[i], TRUE);
	}

	int Red = GetColor(255, 0, 0);            //赤の色
	DrawFormatString(900, 500, Red, "%d",Rota_angle);
	
	sincount += 1;
	angle += 1;
}

void ZAKO::Zako_change(int interVal) {

	zako_change = interVal;

	if (zako_change == 120) {
		i = 1;
	}
	if (zako_change == 240){
		i = 0;
	}
}

/*****脳みそ死んだ*******

//描画の角度を変える処理
void ZAKO::Draw_angle() {

	if (angle >= 1075) {
		angle = 0;
	}
	if (angle >= 400 && angle <= 600) {
		Rota_angle = 45;
	}
    if (angle >= 700 && angle<= 900 ) {
		Rota_angle = 60;
	}
}
***********************/
//全体の動き
void ZAKO::Overall_Move() {
	
	x += allMoveAmount;
}

//x座標を送る処理
double ZAKO::Send_X() {
	return x;
}

//y座標を送る処理
double ZAKO::Send_Y() {
	return y;
}

//横幅を送る処理
int ZAKO::Send_Width() {
	return width;
}

//高さを送る処理
int ZAKO::Send_Height() {
	return height;
}