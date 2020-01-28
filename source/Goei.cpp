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
			Move_cnt += 1;
		}
		else {
			Move_cnt -= 1;
		}
		Overall_Move();
	}
}

	//初期化処理
	void GOEI::Init(int ix, int iy){
		x                 = ix;		     //x座標
		y                 = iy;		     //y座標
		Rota_zome         = 2.0;         //拡大率
		Rota_angle        = 0;           //描画角度
		angle             = 75;          //angleの初期値
		R                 = 150;         //ラジアンの初期値
		i                 = 0;           //ループ用
		goei_change       = 0;           //ゴエイの画像を切り替える
		goei_gh           = 0;           // 0;開脚 1:閉脚
		width             = 18;		     //横幅
		height            = 18;		     //高さ
		FLAG_X            = 800;         //goeiflgで使う値
		FLAG_Y            = 200;         //goeiflgで使う値
		Move              = 0;           //エネミーの移動方向 0:→ 1:←
		Move_cnt          = 0;
		Move_RIGHT_cnt    = -1;           //エネミが―右に動いた回数
		Move_LEFT_cnt     = 1;           //エネミが―左に動いた回数 
		Move_flg          = true;        // true:起動 false:なし 一度だけ動かしたい処理なので、1にしたら戻らない
		durability        = 1;		     //耐久力
		onAcitve          = true;        //生存判定
		atkActive         = false;       //エネミーが攻撃してるかどうかの判定
		goeiflg           = 0;           //ゴエイの挙動を変えるフラグ
								         //0:回転移動 1:直進 2:回転 3:直進 4:何もなし
	}

//終了処理
void GOEI::Final() {

}

//更新処理
void GOEI::Update() {

}


void GOEI::Atacck(bool atk,int dorei,int pataan,double bazin_x,double bazin_y) {//int goei_Move,int cnt_Move

	/***エネミマネージャーから、ゴエイの状態を受け取る***/
	atkActive        = atk;         //攻撃のフラグを入れる
	int goei_no      = dorei;       //ゴエイの番号
	int goei_type    = 0;           //攻撃のパターンを入れる
	
	/***動かす前に受け取った初期座標を保存しておく***/
	double x_bazin = bazin_x;    
	double y_bazin = bazin_y;

	/***パターン１：左側への動き***/
	if (atkActive == true && goei_type == 0) {

		
		/***最初の回転***/
		if (goeiflg == 0) {
			x -= -R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y -= -R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
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
		/***斜めに直進***/
		if (goeiflg == 1) {

			x += 2.0;//sin(PI * sincount / 80.0f) * 2.0f;
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
			x -= 1.5f; sin(PI * sincount / 100.0f) * 2.0f;
			y += 2.5f;
		}
		/***画面外に出たゴエイを上にワープさせる***/
		if (y > 1100) {
			if (Move == 0) {
				x_bazin = x_bazin + (10 * Move_cnt);
			}
			else {
				x_bazin = x_bazin - (10 * Move_cnt);
	
			}
			x = x_bazin;
			if (goei_no == 0) {
				x = x_bazin + 10;
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

	}

     /***パターン２：右側への動き***/
	if (atkActive == true && goei_type == 1 ) {
		
		/***最初の回転***/
		if (goeiflg == 0) {
			R = -150;
			x += R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y -= R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 1;
			Rota_angle += 0.04;
		}
		/***回転をしたら、次の行動え移す為にフラグを切り替える***/
		if (FLAG_Y <= y && goeiflg == 0) {
			goeiflg = 1;
			FLAG_Y = 550;
		}
		/***斜めに直進***/
		if (goeiflg == 1) {

			x -= 2.0;
			y += 1.5f;
		}
		/***一定距離まで直進したら、次の行動に移させるためフラグを切り替える***/
		if (FLAG_Y <= y && goeiflg == 1) {
			goeiflg = 2;
			angle = -90;
			R = 150;
		}
		/***直進後の回転***/
		if (goeiflg == 2) {

			x -= R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y += R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 2;
			Rota_angle += 0.04;
			if (angle >= 162 && goeiflg == 2) {
				goeiflg = 3;
			}
		}
		/***最後の直進***/
		if (goeiflg == 3) {
			x += 1.5;
			y += 2.5f;	
		}
		/***画面外に出たゴエイを上にワープさせる***/
		if (y > 1100) {
			if (Move == 0) {
				x_bazin = x_bazin + (10 * Move_cnt);
			}
			else {
				x_bazin = x_bazin - (10 * Move_cnt);

			}
			x = x_bazin;
			if (goei_no == 0) {
				x = x_bazin + 10;
			}
			y = -15;
			Rota_angle = 0;
			goeiflg = 4;
		}
		/***既に移動を終えたゴエイが上に戻ってきたら、初期一に戻るまで下に移動させる***/
		if (y <= y_bazin && goeiflg == 4) {
			y += 2;

		}
		if (y == 20 && goeiflg == 3) {
			atkActive = false;

		}
	}	
}

//描画処理
void GOEI::Draw() {
	DrawRotaGraph(x, y, Rota_zome, Rota_angle, gh[i], TRUE);
	int Red = GetColor(255, 0, 0);            //赤の色
	int aaa = 0;

}

void GOEI::Goei_change(int interVal) {

	goei_change = interVal;

	if (goei_change == 125) {
		i = 1;
	}
	if (goei_change == 250) {
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