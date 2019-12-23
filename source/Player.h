#ifndef _Player_h_
#define _Player_h_

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

//Playerの全体管理
void Player_All();



#endif