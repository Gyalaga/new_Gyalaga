#include"DxLib.h"
#include"Scene_mgr.h"

static eScene Scene = eScene_MENU;

//çXêV
void Scenemgr_update() {
	switch (Scene) {
	case eScene_MENU:
		//Menu_update();
		//Menu_draw();
		break;
	case eScene_GAME:
		//Game_update();
		//Game_draw();
		break;
	case eScene_RESULT:
		//Result_update();
		//Result_draw();
		break;
	}
}