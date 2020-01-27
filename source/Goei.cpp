#include "Goei.h"
#include "DxLib.h"
#include<math.h>
#define PI 3.1415926f
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

//エネミー管理クラスから全体の移動量を取得する
void GOEI::Load_AddMove(int addMove) {

	allMoveAmount = addMove;		//全体の移動量をゴエイクラスに適用させる

	//攻撃中ではないとき
	if (atkActive == false) {
		Overall_Move();
	}
}

//初期化処理
void GOEI::Init(int ix, int iy) {
	x			= ix;		//x座標
	y			= iy;		//y座標
	Rota_zome = 2.0;        //拡大率
	Rota_angle = 0;         //描画角度
	angle = 75;             //angleの初期値
	R = 150;                //ラジアンの初期値
	i = 0;                  //ザコの画像を切り替えるよう
	width		= 18;		//横幅
	height		= 18;		//高さ
	FLAG_X = 800;           //goeiflgで使う値
	FLAG_Y = 200;           //goeiflgで使う値
	durability	= 1;		//耐久力
	atkActive	= false;	//攻撃判定
	onAcitve	= true;		//生存判定
	goeiflg = 0;            //ザコ敵の挙動を変えるフラグ
							//0:回転移動 1:曲線移動 2:なんか 3:なんか
}

//終了処理
void GOEI::Final() {

}

//更新処理
void GOEI::Update() {

}

void GOEI::Atacck(bool atk) {

	atkActive = atk;

	if (atkActive == true) {
		//Draw_angle();

		if (FLAG_Y <= y && goeiflg == 0) {
			goeiflg = 1;
			FLAG_Y = 550;
		}
		if (FLAG_Y <= y && goeiflg == 1) {
			goeiflg = 2;
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

		if (goeiflg == 0) {
			x -= -R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			//sin(PI * sincount / 80.0f) * 2.0f;
			y -= -R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			//1.5f;
			angle += 1;
			Rota_angle -= 0.04;
		}
		if (goeiflg == 1) {

			x += 2.5;//sin(PI * sincount / 80.0f) * 2.0f;
			y += 1.5f;
		}
		if (goeiflg == 2) {

			x += R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y += R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 2;
			Rota_angle -= 0.04;
			if (angle >= 200 && goeiflg == 2) {
				goeiflg = 3;
			}
		}
		if (goeiflg == 3) {
			x -= sin(PI * sincount / 100.0f) * 2.0f;
			y += 2.5f;
			//Rota_angle += 0.01;
		}
	}
}

//描画処理
void GOEI::Draw() {
	DrawRotaGraph(x, y, Rota_zome, Rota_angle, gh[i], TRUE);
}

void GOEI::Goei_change(int interVal) {

	goei_change = interVal;

	if (goei_change == 120) {
		i = 1;
	}
	if (goei_change == 240) {
		i = 0;
	}
}

//全体の動き
void GOEI::Overall_Move() {
	x += allMoveAmount;
}

//x座標を送る処理
double GOEI::Send_X() {
	return x;
}

//y座標を送る処理
double GOEI::Send_Y() {
	return y;
}