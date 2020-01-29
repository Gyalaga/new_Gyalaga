#include "End.h"
#include "DxLib.h"

END::END(ISCENECHANGER* changer) :BASESCENE(changer) {
	Init();
}

void END::Init() {
	image = LoadGraph("./res/img/result_v2.png");
}

void END::Final() {
	DeleteGraph(image);
}

void END::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mSceneChanger->ChangeScene(eScene_Title);
	}
}

void END::Draw() {
	DrawGraph(0, 0, image, TRUE);
}