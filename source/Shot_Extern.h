#ifndef _SHOT_EXTERN_H_
#define _SHOT_EXTERN_H_
#define SHOT 2
extern int Shot_init();
extern int Shot_draw();
extern int Shot_Check(int,int);

extern int shot;

typedef struct {
	int sx[SHOT], sy[SHOT],
		sx2[SHOT], sy2[SHOT],
		sw = 6, sh = 16;
	int sf[SHOT];
	int sf2;
	int bi = 0;
} BULLET;
extern BULLET bullet;

#endif 
