#include"DxLib.h"
#include"Scene_mgr.h"
#include"Title.h"

void Title_update() {


}

void Title_draw() {
	static int title = LoadGraph("../source/img/Gyaraga.jpg"); static int namuco = LoadGraph("../source/img/NAMUCO.png");
	static int player1 = LoadGraph("../source/img/PLAYER1.png"); static int player2 = LoadGraph("../source/img/PLAYER2.png");
	static int score1 = LoadGraph("../source/img/1UP.png"); static int score2 = LoadGraph("../source/img/2UP.png");
	static int hiscore = LoadGraph("../source/img/HISCORE.png");

	DrawGraph(350, 500, title, TRUE);
	

}