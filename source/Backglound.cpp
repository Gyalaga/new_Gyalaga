#include"DxLib.h"
#include"Backglound.h"
#define SPEED 1

 int y = 0;

void Backgraph_draw() {

	static int siro = LoadGraph("./res/img/kuro.jpg"); static int haikei1 = LoadGraph("./res/img/bg2.png");
	static int haikei2 = LoadGraph("./res/img/bg3.png"); static int haikei3 = LoadGraph("./res/img/bg.png");
    static int bgflg = 0;    //背景画像チェンジのフラグ
	static int i = 0;        //ループ用
	static int count = 0;    //カウントの変数
	int img[3] = { haikei1,haikei2,haikei3 }; //画像配列
    

	//1枚目
	DrawGraph(0, y, img[i], TRUE);
	//2枚目
	DrawGraph(0, y - 800, img[i], TRUE);
	//3枚目
	DrawGraph(0, y - 1600, img[i], TRUE);
	//一番下までスクロールしたら、座標を初期値に戻す
	if (y == 1600) {
		y = 0;
	}
	count++;   //カウンターを加算

	if (count % 60 == 0) {
		i++;
		count = 0;
	}
	if (i == 2) {
		i = 0;
	}
	DrawGraph(800, 0, siro, TRUE);
}

void Backgraph_update() {

	y += SPEED;
	
}

void Backgraph_all() {

	Backgraph_draw();
	Backgraph_update();

}