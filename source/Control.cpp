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
	Player_judgment(&px,&py, &pw, &ph, &sx, &sy, &sw, &sh);
	enemyMgr->Update();
	enemyMgr->Draw();
	enemyMgr->Send_Coordinate(ex, ey);
	Score_Save();
	Score_Draw();
	DrawFormatString(50, 620, GetColor(255, 255, 255), "%d,%d,%d,%d",sx, sy, sw, sh);
	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d,%d,%d",px,py,pw,ph);
}