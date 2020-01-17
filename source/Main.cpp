#include"DxLib.h"
#include"Scene_mgr.h"
#include"Backglound.h"
#include"ShotGV.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(1100, 800, 32);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Backgraph_all();
		Scenemgr_update();
		Scenemgr_draw();
	}
	DxLib_End();
	return 0;
}
	