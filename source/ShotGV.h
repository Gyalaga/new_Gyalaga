//グローバル変数としての宣言
#ifndef _SHOTGV_H_
#define _SHOTGV_H_

#define SHOT 2 //弾の最大数
int Shot_init(); //弾の初期化処理
int Shot_draw(); //弾の描画処理
int Shot_Check(int,int); //スペースが押された時の処理

int shot; //弾の画像用変数

//弾の構造体
typedef struct {
	int sx[SHOT], sy[SHOT],
		sx2[SHOT], sy2[SHOT],
		sw = 6, sh = 16;
	int sf[SHOT];
	int sf2;
	int bi = 0;
} BULLET;

 BULLET bullet;



#endif 

