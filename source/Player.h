#ifndef _Player_h_
#define _Player_h_
/*{ 他の所でも必要な変数 }**********************************************************/
typedef struct
{
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:横幅, height:縦幅, center:中心
	int width = 32, height = 32, center = width / 2;
	//  mode:  0_通常 ,1_捕縛 ,2_デュアルモード
	int mode = 0;
	//表示フラグ
	bool flg = false;
}PLAYER;

static PLAYER Player;            // Playerの構造体
/***********************************************************************************/

/*{ Player.cpp内だけで使う変数 }****************************************************/
typedef struct
{

}Animation;

static Animation ani;            // Player_Animationの構造体

void Player_All();       //Playerの全体管理
void Player_Init();      //Playerの初期化管理
void Player_Draw();      //Playerの描画の管理
void Player_Move();      //Playerの動きの管理
void Player_Animation(); //Playerのアニメーションの管理
void Player_Shot();      //Playerの弾の全体管理
void Player_judgment();  //Playerの当たり判定の管理

#endif