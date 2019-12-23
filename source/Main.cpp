#include"DxLib.h"
#include"Scene_mgr.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetGraphMode(1100, 800, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Scenemgr_update();
		Scenemgr_draw();
	}
	DxLib_End();
	return 0;
}
	