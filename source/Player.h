#ifndef _Player_h_
#define _Player_h_

#define PI 3.14    // 角度求めるのに使用
/*{ 他の所でも必要な変数 }**********************************************************/
typedef struct
{
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:横幅, height:縦幅, center:中心
	int width = 32, height = 32, center = width / 2;
	//  rote:角度,image:画像,hp:体力
	int rote = 0, image[2],  hp = 3;
	//  mode:  0_通常  ,2_捕縛されそう ,3_捕縛 ,4_破壊(非表示)
	int mode = 0;
	//デュアルモードフラグ
	bool dualmode = false;
	//表示フラグ
	bool flg = true;
}PLAYER;

static PLAYER Player;            // Playerの構造体
/***********************************************************************************/

/*{ Player.cpp内だけで使う構造体 }****************************************************/
typedef struct
{
	int i = 0, j = 0;                          // i:爆破エフェクトの速さ, j:表示
	int check = 0;
	int image[13];

	int check_left_x;                               // x座標を記録
	int check_right_x;                              // x座標を記録
	bool left_flg = false;
	bool right_flg = false;
}EXPLOSION; // 爆発用の構造体

static EXPLOSION explosion;            // 爆発用の構造体

void Player_All();       //Playerの全体管理
void Player_Init();      //Playerの初期化管理
void Player_Draw();      //Playerの描画の管理
void Player_Move();      //Playerの動きの管理
void Player_Animation(); //Playerのアニメーションの管理
void Player_Shot();      //Playerの弾の全体管理
void Player_judgment();  //Playerの当たり判定の管理

#endif