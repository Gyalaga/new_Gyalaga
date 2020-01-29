#include "End.h"
#include "DxLib.h"

END::END(ISCENECHANGER* changer) :BASESCENE(changer) {
}

void END::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		mSceneChanger->ChangeScene(eScene_Title);
	}
}

void END::Draw() {
	DrawString(370, 300, "Thank you for playing !!", GetColor(255, 255, 255));
	DrawString(370, 400, "press the space to return to the title", GetColor(255, 255, 255));
}