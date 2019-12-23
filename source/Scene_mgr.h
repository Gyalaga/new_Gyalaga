#ifndef _SCENE_MGR_H_
#define _SCENE_MGR_H_

typedef enum {
	eScene_MENU,  //メニュー画面
	eScene_GAME,  //ゲーム画面
	eScene_RESULT,//設定画面
}eScene;

//更新
void Scenemgr_update();

//描画
void Scenemgr_draw();

void Changescene(eScene nextScene);
#endif // !_SCENE_MGR_H_

