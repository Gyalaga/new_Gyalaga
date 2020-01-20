#include"DxLib.h"
#include"Scene_mgr.h"
#include"Title.h"
#include"Keyborad.h"

int PLAYER1_Y = 1170;    //�u1PLAYER�v������y���W
int PLAYER2_Y = 1210;   //�u2PLAYER�v������y���W
int TITLE_Y = 900;   //�u�^�C�g�����S�v��y���W
int SCORE_Y = 800;   //�uHI-SCORE�v�̂����W
int ONEUP_Y = 800;   //�u1UP�v�̂����W
int TWOUP_Y = 800;   //�u2UP�v�̂����W
int NAMCO_Y = 1350;  //�unamco�v�̂����W

static int Select = eMenu_1PLAYER;

void Title_update() {
	if (Key_get(KEY_INPUT_DOWN) == 1) {//���L�[��������Ă�����
		Select = (Select + 1) % eMenu_Num;//�I����Ԃ��������
	}
	if (Key_get(KEY_INPUT_UP) == 1) {//��L�[��������Ă�����
		Select = (Select + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
	}
	if (Key_get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[�������ꂽ��

		switch (Select) {                            //���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
		case eMenu_1PLAYER:                           //�Q�[���I�𒆂Ȃ�
			PLAYER1_Y = 1170;
			PLAYER2_Y = 1210;
			Scene_change(eScene_GAME);       //�V�[�����Q�[����ʂɕύX
			break;
		case eMenu_2PLAYER://�ݒ�I�𒆂Ȃ�
			PLAYER1_Y = 1170;
			PLAYER2_Y = 1210;
			Scene_change(eScene_GAME);    //�V�[����ݒ��ʂɕύX
			break;
		}
	}

}

void Title_draw() {
	static int title = LoadGraph("./res/img/Gyaraga.jpg"); static int namuco = LoadGraph("./res/img/NAMUCO.png");
	static int player1 = LoadGraph("./res/img/PLAYER1.png"); static int player2 = LoadGraph("./res/img/PLAYER2.png");
	static int score1 = LoadGraph("./res/img/1UP.png"); static int score2 = LoadGraph("./res/img/2UP.png");
	static int hiscore = LoadGraph("./res/img/HISCORE.png");

	/***�^�C�g�����S***/
	DrawGraph(240, TITLE_Y, title, TRUE);
	if (TITLE_Y > 150) {
		TITLE_Y -= 2;
	}
	/*****************************/

	/***1P�X�R�A&2P�X�R�A***/
	DrawGraph(100, ONEUP_Y, score1, TRUE);
	DrawGraph(625, TWOUP_Y, score2, TRUE);
	if (ONEUP_Y > 50) {
		ONEUP_Y -= 2;
		TWOUP_Y -= 2;
	}
	/*****************************/

	/***�n�C�X�R�A***/
	DrawGraph(300, SCORE_Y, hiscore, TRUE);
	if (SCORE_Y > 50) {
		SCORE_Y -= 2;
	}
	/*****************************/

	/***1�v���C���[&2�v���C���[***/
	DrawGraph(300, PLAYER1_Y, player1, TRUE);
	DrawGraph(300, PLAYER2_Y, player2, TRUE);
	if (PLAYER1_Y > 420) {
		PLAYER1_Y -= 2;
	}
	if (PLAYER2_Y > 460) {
		PLAYER2_Y -= 2;
	}
	/*****************************/

	/***�i���R***/
	DrawGraph(150, NAMCO_Y, namuco, TRUE);
	if (NAMCO_Y > 600) {
		NAMCO_Y -= 2;
	}
	/*****************************/

	int y = 0;
	switch (Select) {
	case eMenu_1PLAYER: //1PLAYER��I�𒆂Ȃ�
		y = PLAYER1_Y;
		break;
	case eMenu_2PLAYER: //2PLAYER��I�𒆂Ȃ�
		y = PLAYER2_Y;
		break;
	}
	DrawString(250, y, "��", GetColor(255, 255, 255));
	

}