#ifndef _SHOT_EXTERN_H_
#define _SHOT_EXTERN_H_
#define SHOT 2
extern int Shot_init();
extern int Shot_draw();
extern int Shot_Check();

extern int shot;

typedef struct {
	int sx[SHOT], sy[SHOT],
		sx2[SHOT], sy2[SHOT],
		sw = 9, sh = 12;
	int sf[SHOT];
	int sf2;
} BULLET;
extern BULLET bullet;

typedef struct
{
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:横幅, height:縦幅, center:中心
	int width = 32, height = 32, center = width / 2;
	//  rote:角度,image:画像,hp:体力
	int rote = 0, image[2], hp = 3;
	//  mode:  0_通常  ,2_捕縛されそう ,3_捕縛 ,4_破壊(非表示)
	int mode = 0;
	//デュアルモードフラグ
	bool dualmode = false;
	//表示フラグ
	bool flg = true;
}PLAYER;

extern PLAYER Player;

#endif 
