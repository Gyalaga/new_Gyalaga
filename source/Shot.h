#ifndef _SHOT_H_

#define _SHOT_H_

#define SHOT 2
int Shot_init();
int Shot_draw();
int Shot_Check();
typedef struct shot {
	int i;
	int bullet;
	int sx[SHOT], sy[SHOT],
		sx2[SHOT], sy2[SHOT], sw = 6, sh = 16, i;
	int sf[SHOT];
	int sf2;
};

#endif 

