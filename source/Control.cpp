#include "Control.h"
#include "Score.h"
#include "DxLib.h"
//�R���g���[���N���X�̃R���X�g���N�^
CONTROL::CONTROL() {
	enemyMgr = new ENEMYMGR;
}

//�R���g���[���N���X�̃f�X�g���N�^
CONTROL::~CONTROL() {
	delete enemyMgr;
}

//�Q�[���̑S�̐���
void CONTROL::GameControl() {
	Player_All();
	enemyMgr->Update();
	enemyMgr->Draw();
	Score_Save();
	Score_Draw();
}