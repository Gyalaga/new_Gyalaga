#include"DxLib.h"
#include"Scene_mgr.h"
#include"Title.h"

static eScene Scene = eScene_TITLE;

//çXêV
void Scenemgr_update() {
	switch (Scene) {
	case eScene_TITLE:
		Title_update();
		break;
	case eScene_GAME:
		//Game_update();
		break;
	case eScene_RESULT:
		//Result_update();
		break;
	}
}

void Scenemgr_draw() {
	switch (Scene) {
	case eScene_TITLE:
		Title_draw();
		break;
	case eScene_GAME:
		//Game_draw();
		break;
	case eScene_RESULT:
		//Result_draw();
		break;
	}
}

void Scene_change(eScene nextScene) {

	Scene = nextScene;
}