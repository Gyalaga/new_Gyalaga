#include"DxLib.h"
#include"Backglound.h"
#define SPEED 1

 int y = 0;

void Backgraph_draw() {

	static int siro = LoadGraph("./res/img/kuro.jpg"); static int haikei1 = LoadGraph("./res/img/bg2.png");
	static int haikei2 = LoadGraph("./res/img/bg3.png"); static int haikei3 = LoadGraph("./res/img/bg.png");
    static int bgflg = 0;    //�w�i�摜�`�F���W�̃t���O
	static int i = 0;        //���[�v�p
	static int count = 0;    //�J�E���g�̕ϐ�
	int img[3] = { haikei1,haikei2,haikei3 }; //�摜�z��
    

	//1����
	DrawGraph(0, y, img[i], TRUE);
	//2����
	DrawGraph(0, y - 800, img[i], TRUE);
	//3����
	DrawGraph(0, y - 1600, img[i], TRUE);
	//��ԉ��܂ŃX�N���[��������A���W�������l�ɖ߂�
	if (y == 1600) {
		y = 0;
	}
	count++;   //�J�E���^�[�����Z

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