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

typedef struct {
	int px = 550, py = 700;
	int ph = 32, pw = 32;

}PLAYER;

extern PLAYER player;

#endif 
