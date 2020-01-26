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

void CONTROL::PlayerGet(int Px,int Py) 
{
	 A = Px;
	 S = Py;
	//DrawFormatString(850, 40, GetColor(255, 255, 255), "%d", A);//�m�F�p
	//DrawFormatString(850, 80, GetColor(255, 255, 255), "%d", S);//�m�F�p
}

//�Q�[���̑S�̐���
void CONTROL::GameControl() {
	Player_All();
	enemyMgr->Update();
	enemyMgr->Draw();
	enemyMgr->Send_Coordinate(ex, ey);
	Score_Save();
	Score_Draw();
}