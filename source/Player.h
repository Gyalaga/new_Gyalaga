#ifndef _Player_h_
#define _Player_h_

#define PI 3.14    // 角度求めるのに使用
/*{ 他の所でも必要な変数 }**********************************************************/
typedef struct
{
	//x,y座標配列
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:横幅, height:縦幅, center:中心
	int width = 32, height = 32, center = width / 2;
	//  rote:角度,image:画像,hp:体力
	int L_rote = 0,R_rote=0, image[2],  hp = 3;
	//  mode:  0_通常  ,2_捕縛されそう ,3_捕縛 ,4_破壊(非表示)
	int mode = 0;
	//デュアルモードフラグ
	bool dualmode = false;

	//表示フラグ
	bool  left_flg[16] = { false,false,false,false,false,false,false,false,
						   false,false,false,false,false,false,false,false };
	bool right_flg[16] = { false,false,false,false,false,false,false,false,
						   false,false,false,false,false,false,false,false };

}PLAYER;

 PLAYER Player;    // Playerの構造体
/*************************************************************************************/

/*{ Player.cpp内だけで使う構造体 }****************************************************/
typedef struct
{
	int i = 0, j = 0;          //左の自機の i:アニメーションの速さ, j:表示
	int n = 0, c = 0;          //右の自機の n:アニメーションの速さ, c:表示

	int image[13];             //画像の配列

	int check_left_x;          //左のx座標を記録
	int check_right_x;         //右のx座標を記録
	bool L = false;            //左のx座標を記録するのに使うフラグ
	bool R = false;            //右のx座標を記録するのに使うフラグ
	bool left_flg = false;     //左のアニメーション実行用のフラグ
	bool right_flg = false;    //右のアニメーション実行用のフラグ
}EXPLOSION; //爆発用の構造体

typedef struct
{
	int i = 0, j = 0;          // i:アニメーションの速さ, j:表示

	int check_left_x;          // x座標を記録
	int check_right_x;         // x座標を記録

	bool left_flg = false;     //左のアニメーション実行用のフラグ
	bool right_flg = false;    //右のアニメーション実行用のフラグ
	bool check_flg[5] = { false,false,false,false,false}; //敵の座標に合わせるフラグ配列
}TRACTOR;   //捕まるときのアニメーション用の構造体

typedef struct
{
	bool c = false;            //処理用に使う用の変数
	bool flg_L = false;        //左の処理用に使う用の変数
	bool flg_R = false;        //右の処理用に使う用の変数
	bool flg = false;          //アニメーション実行用のフラグ
	bool ani_flg[2] = { false,false};  //敵の座標に合わせるフラグ配列
}DUAL;      //デュアルアニメーション用の構造体

static DUAL dual;              // 爆発用の構造体
static EXPLOSION explosion;    // 爆発用の構造体
static TRACTOR tractor;        //デュアルアニメーション用の構造体

void Player_All();             //Playerの全体管理
void Player_Init();            //Playerの初期化管理
void Player_Draw();            //Playerの描画の管理
void Player_Move();            //Playerの動きの管理
void Player_Animation();       //Playerのアニメーションの管理
void Player_Shot();            //Playerの弾の全体管理
void Player_judgment();        //Playerの当たり判定の管理

void Player_int();             //Playerの変数確認

#endif