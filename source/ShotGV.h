#ifndef _SHOT_H_

#define _SHOT_H_

#define SHOT 2
int Shot_init();
int Shot_draw();
int Shot_Check();

int shot;

typedef struct {
	int sx[SHOT], sy[SHOT],
		sx2[SHOT], sy2[SHOT],
		sw = 9, sh = 12;
	int sf[SHOT];
	int sf2;
} BULLET;

BULLET bullet;
/*
typedef struct {
	int px = 550, py = 700;
	int ph = 32, pw = 32;

}PLAYER;

PLAYER player;
*/
#endif 

