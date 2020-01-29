#include "SceneMgr.h"
#include "DxLib.h"
#include "Game.h"
#include "Title.h"
#include "End.h"
#include"Keyborad.h"

SCENEMGR::SCENEMGR() :mNextScene(eScene_None) {
	mScene = (BASESCENE*)new TITLE(this);
}

void SCENEMGR::Init() {
	mScene->Init();
}

void SCENEMGR::Final() {
	mScene->Final();
}

void SCENEMGR::Update() {
	Keyborad();
	if (mNextScene != eScene_None) {
		mScene->Final();
		delete mScene;
		switch (mNextScene) {
		case eScene_Title:
			mScene = (BASESCENE*)new TITLE(this);
			break;
		case eScene_Game:
			mScene = (BASESCENE*)new GAME(this);
			break;
		case eScene_End:
			mScene = (BASESCENE*)new END(this);
			break;
		}
		mNextScene = eScene_None;
	}
	mScene->Update();
}

void SCENEMGR::Draw() {
	mScene->Draw();
}

void SCENEMGR::ChangeScene(eScene nextScene) {
	mNextScene = nextScene;
}