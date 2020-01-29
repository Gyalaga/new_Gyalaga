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
		if (allMoveAmount == ENEMY_MOVERIGHT) {
			Move_flg = 0;  //右
			Move_cnt += 1;
			Overall_Move();
		}
		else {
			Move_flg = 1;
			Move_cnt -= 1; //左
			Overall_Move();
		}
	}
}

//ダメージを受ける処理
void GOEI::Load_Damage(int damage) {
	durability -= damage;
}

//アニメーション処理
void GOEI::Load_Interval(int interval) {

	if (atkActive == false) {
		if (interval == 120) {
			moveAni = 1;
		}
		else if (interval == 240) {
			moveAni = 0;
		}
		aniOrder = moveAni;
	}
}

//初期化処理
void GOEI::Init(int ix, int iy) {
	x = ix;		//x座標
	y = iy;		//y座標
	Rota_zome = 2.0;        //拡大率
	Rota_angle = 0;         //描画角度
	angle = 75;             //angleの初期値
	R = 150;                //ラジアンの初期値
	width = 30;		//横幅
	height = 30;		//高さ
	FLAG_X = 800;           //goeiflgで使う値
	FLAG_Y = 200;           //goeiflgで使う値
	durability = 1;		//耐久力
	aniOrder = 0;			//描画する画像番号
	moveAni = 0;			//全体の動きのアニメーション
	atkActive = false;	//攻撃判定
	onAcitve = true;		//生存判定
	goeiflg = 0;            //ザコ敵の挙動を変えるフラグ
							//0:回転移動 1:曲線移動 2:なんか 3:なんか
	zigzagcnt = 0;          //ジグザグカウント
	zigzagflg = 0;          //ジグザグフラグ
	Move_flg = 0;          //最初は→  0:右 1:左
	Move_cnt = 0;

}

//終了処理
void GOEI::Final() {

}

//更新処理
void GOEI::Update() {

	//onActiveをfalseにする
	if (durability == 0 && onAcitve == true) {
		onAcitve = false;
		PlaySoundFile("./res/wav/gal_se_goei_striken.wav", DX_PLAYTYPE_BACK);
	}
}

void GOEI::Atacck(bool atk, int dorei_no, double bazin_x, double bazin_y) {

	/***エネミーマネジャーから受け取ったデータを格納***/
	atkActive = atk;           //ゴエイの攻撃フラグ
	int goei_no = dorei_no;  //動くゴエイの番号
	double x_bazin = bazin_x;  //動くゴエイの,動く前の座標
	double y_bazin = bazin_y;  //動くゴエイの,動く前の座標

	if (atkActive == true) {

		/***最初の回転***/
		if (goeiflg == 0) {
			x -= -R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			//sin(PI * sincount / 80.0f) * 2.0f;
			y -= -R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			//1.5f;
			angle += 1;
			Rota_angle -= 0.04;
		}
		/***回転をしたら、次の行動え移す為にフラグを切り替える***/
		if (FLAG_Y <= y && goeiflg == 0) {
			goeiflg = 1;
			FLAG_Y = 550;
		}
		/***一定距離まで直進したら、次の行動に移させるためフラグを切り替える***/
		if (FLAG_Y <= y && goeiflg == 1) {
			goeiflg = 2;
			angle = -90;
			R = 150;
		}
		/***斜めに***/
		if (goeiflg == 1) {
			x += 2.5;//sin(PI * sincount / 80.0f) * 2.0f;
			y += 1.5f;
		}
		/***直進後の回転***/
		if (goeiflg == 2) {

			x += R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y += R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 2;
			Rota_angle -= 0.04;
			if (angle >= 162 && goeiflg == 2) {
				goeiflg = 3;
			}
		}
		/***最後の直進***/
		if (goeiflg == 3) {
			x -= 1.5f;
			y += 2.5f;
			//Rota_angle += 0.01;
		}
		/***画面外に出たゴエイを上にワープさせる***/
		if (y >= 1100) {
			if (Move_flg == 0) { //エネミー全体が右に進んでた場合
				x_bazin = x_bazin + (10 * Move_cnt);
				x = x_bazin;
				if (goei_no == 0) {
					x = x_bazin - 10;
				}
			}
			else {              //エネミー全体が左に進んでいた場合
				x_bazin = x_bazin - (10 * Move_cnt);
				x = x_bazin;
			}
			y = -15;
			Rota_angle = 0;
			goeiflg = 4;
		}
		/***既に移動を終えたゴエイが上に戻ってきたら、初期一に戻るまで下に移動させる***/
		if (y <= y_bazin && goeiflg == 4) {
			y += 2;
			atkActive = false;

		}

		/******ジグザグの動き******/
		if (zigzagflg == 1) {
			x -= 1.5;
			y += 1.5f;
			zigzagcnt += 1;
		}
		if (zigzagcnt > 50) {
			zigzagflg = 2;
		}
		if (zigzagflg == 2) {
			x += 3;
			y += 1.5f;
		}
		if (zigzagcnt > 100) {
			zigzagflg = 3;
		}
		if (zigzagflg == 3) {
			x -= 1.5;
			y += 1.5f;
		}
		/**************************/
	}
}

//描画処理
void GOEI::Draw() {

	if (onAcitve == true) {
		int Red = GetColor(255, 0, 0);            //赤の色
		DrawFormatString(600, 500, Red, "%d", sincount);
		DrawRotaGraph(x, y, Rota_zome, Rota_angle, gh[aniOrder], TRUE);
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

//横幅を送る処理
int GOEI::Send_Width() {
	return width;
}

//高さを送る処理
int GOEI::Send_Height() {
	return height;
}

//onActiveを送る処理
bool GOEI::Send_OnActive() {
	return onAcitve;
}