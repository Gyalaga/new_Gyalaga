#include "Control.h"
#include "Score.h"
#include "DxLib.h"
//�R���g���[���N���X�̃R���X�g���N�^
CONTROL::CONTROL() {
	enemyMgr = new ENEMYMGR;
	hit = false;
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
	enemyMgr->Send_Coordinate(ex, ey, eWidth, eHeight);
	Score_Save();
	Score_Draw();
	Hit_Judgment();

	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d",px,py);
	DrawFormatString(50, 540, GetColor(255, 255, 255), "%f,%f", ex[20], ey[20]);

}

void CONTROL::Hit_Judgment() {

	for (int i = 0; i < 40; i++) {
		if ((double)px + pw >= ex[i] && (double)px <= ex[i] + eWidth[i] && (double)py + ph >= ey[i] && (double)py <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(hit, i);
		}
		if ((double)sx + sw >= ex[i] && (double)sx <= ex[i] + eWidth[i] && (double)sy + sh >= ey[i] && (double)sy <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(hit, i);
		}
	}

	DrawFormatString(50, 620, GetColor(255, 255, 255), "%d,%d,%d,%d", sx, sy, sw, sh);
	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d,%d,%d", px, py, pw, ph);
}