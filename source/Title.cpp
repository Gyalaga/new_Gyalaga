#include"DxLib.h"
#include"Scene_mgr.h"
#include"Title.h"

void Title_update() {


}

void Title_draw() {
	static int title = LoadGraph("../res/img/Gyaraga.jpg"); static int namuco = LoadGraph("../res/img/NAMUCO.png");
	static int player1 = LoadGraph("../res/img/PLAYER1.png"); static int player2 = LoadGraph("../res/img/PLAYER2.png");
	static int score1 = LoadGraph("../res/img/1UP.png"); static int score2 = LoadGraph("../res/img/2UP.png");
	static int hiscore = LoadGraph("../res/img/HISCORE.png");

	DrawGraph(350, 500, title, TRUE);
	

}