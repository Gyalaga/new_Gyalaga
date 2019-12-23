#ifndef _SHOT_H_

#define _SHOT_H_

#define SHOT 2
int Shot();
int Check();
typedef struct shot{
	int bullet;
	int sx[SHOT], sy[SHOT],
		sx2[SHOT], sy2[SHOT], sw = 9, sh = 12, i;
	int sf[SHOT];
	int sf2;
};

#endif 

