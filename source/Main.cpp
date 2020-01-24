#include"DxLib.h"
#include "SceneMgr.h"
#include"Backglound.h"
#include"ShotGV.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetGraphMode(1100, 800, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	SCENEMGR sceneMgr;
	sceneMgr.Init();
	//ENEMY* enemy = new ENEMY;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Backgraph_all();
		//enemy->Enemy_all();
		sceneMgr.Update();
		sceneMgr.Draw();
	}

	sceneMgr.Final();

	DxLib_End();
	return 0;
}
	