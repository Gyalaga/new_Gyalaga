#include "DxLib.h"
#include"Shot_Extern.h"
int Shot_Check() {
	int i;
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		for (i = 0; i < SHOT; i++) {
			if (bullet.sf2 == 0) {
				if (bullet.sf[i] == 0) {
					bullet.sf[i] = 1;
					bullet.sx[i] = (player.pw - bullet.sw) / 2 + player.px;
					bullet.sy[i] = (player.ph - bullet.sh) / 2 + player.py;
					break;
				}
			}
		}
		bullet.sf2 = 1;
	}

	else { bullet.sf2 = 0; }

	for (i = 0; i < SHOT; i++) {
		if (bullet.sf[i] == 1) {
			bullet.sy[i] -= 10;
			if (bullet.sy[i] < -50) {
				bullet.sf[i] = 0;
			}
		}
	}
	return 0;
}

int Shot_draw() {
	int i;
	for (i = 0; i < SHOT; i++) {
		if (bullet.sf[i] == 1) {
			DrawGraph(bullet.sx[i], bullet.sy[i], shot, TRUE);
		}
	}
	return 0;
}