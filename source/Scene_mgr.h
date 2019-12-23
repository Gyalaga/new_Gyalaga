#ifndef _SCENE_MGR_H_
#define _SCENE_MGR_H_

typedef enum {
	eScene_TITLE,  //タイトル画面
	eScene_GAME,  //ゲーム画面
	eScene_RESULT,//設定画面
}eScene;

//更新
void Scenemgr_update();

//描画
void Scenemgr_draw();

//引数　nextSceneのシーンに変更。
void Scene_change(eScene nextScene);
#endif // !_SCENE_MGR_H_

