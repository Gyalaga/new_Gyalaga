#include "DxLib.h"
#include"Shot_Extern.h"
int Shot_Check(int px,int py) {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {
			if (bullet.sf2 == 0) {
				if (bullet.sf[bullet.bi] == 0) {
					bullet.sf[bullet.bi] = 1;
					bullet.sx[bullet.bi] = px;
					bullet.sy[bullet.bi] = py;

					break;
				}
			}
		}
		bullet.sf2 = 1;
	}

	else { bullet.sf2 = 0; }

	for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {
		if (bullet.sf[bullet.bi] == 1) {
			bullet.sy[bullet.bi] -= 10;
			if (bullet.sy[bullet.bi] < -50) {
				bullet.sf[bullet.bi] = 0;
			}
		}
	}
	return 0;
}

int Shot_draw() {
	for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {
		if (bullet.sf[bullet.bi] == 1) {
			DrawRotaGraph(bullet.sx[bullet.bi], bullet.sy[bullet.bi],2,0, shot, TRUE);
		}
	}
	return 0;
}