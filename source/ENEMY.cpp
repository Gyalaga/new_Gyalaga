#include"DxLib.h"
#include"Enemy5.h"
#include<math.h>
#define PI 3.1415926f

/*画像・データ*/
ENEMY::ENEMY()
{
	LoadDivGraph("./res/img/Galaga_OBJ_enemy.png", 5, 5, 10, 18, 18, enemy);
	//LoadDivGraph("./res/img/Galaga_enemy.png", 5, 5, 1, 18, 18, enemy); //画像の分割読み込み
	RECT rect[5];       //画像の矩形
	RECT hitrect;       //当たり判定用の矩形
	int enemy_x = 500;  //x座標
	int enemy_y = 500;  //y座標
	int  zoom = 2.0;  //拡大率
	int  angle = 1.0;  //描画角度
	int  width = 18;    //横幅
	int height = 18;    //高さ
	int count = 0;      //カウンタ変数
	int direction;      //現在向いている方向
						//(0:STOP 1:← 2:↖ 3:↑ 4:↗ 5:→ 6:↘ 7:↓ 8:↙ 
	bool endflag = false;
};

void ENEMY::Enemy_move() {

	static int Move_angle = 0;


}

void ENEMY::Enemy_draw() {

	if (!endflag) {
		DrawRotaGraph(enemy_x, enemy_y, zome, angle, enemy[1], TRUE);
	}         //(描画領域のx,描画領域のy,拡大率,描画角度,画像の識別,透過が有効かどうか)
}
bool ENEMY::Enemy_all() {

	Enemy_move();
	Enemy_draw();
	count++;
	return endflag;

}