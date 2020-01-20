#include"DxLib.h"
#include"Scene_mgr.h"
#include"Title.h"
#include"Game.h"
#include"Keyborad.h"
static eScene Scene = eScene_TITLE;
//static GAME* game = new GAME;	//ゲームクラスの生成
GAME* game;	//ゲームクラスの生成

//更新
void Scenemgr_update() {
	Keyborad();
	switch (Scene) {
	case eScene_TITLE:
		Title_update();
		break;
	case eScene_GAME:
		game->Update();
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
		game->Draw();
		break;
	case eScene_RESULT:
		//Result_draw();
		break;
	}
}

void Scene_change(eScene nextScene) {

	Scene = nextScene;

	if (nextScene != eScene_GAME && game!=NULL)delete game;
	else game = new GAME;
}