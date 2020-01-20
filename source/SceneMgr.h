#ifndef _SCENEMGR_H_
#define _SCENEMGR_H_

#include "ISceneChanger.h"
#include "BaseScene.h"

static int key[256];

class SCENEMGR :public ISCENECHANGER, TASK {
private:
	BASESCENE* mScene;
	eScene mNextScene;
public:
	SCENEMGR();
	void Init();
	void Final();
	void Update();
	void Draw();

	void ChangeScene(eScene nextScene);
};

#endif // !_SCENEMGR_H_