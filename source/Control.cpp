#include "Control.h"
#include "Score.h"
#include "DxLib.h"
//�R���g���[���N���X�̃R���X�g���N�^
CONTROL::CONTROL() {
	enemyMgr = new ENEMYMGR;
	flg = 0;
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

	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d",px,py);
	DrawFormatString(50, 540, GetColor(255, 255, 255), "%f,%f", ex[20], ey[20]);
	DrawFormatString(50, 450, GetColor(255, 255, 255), "%d", flg);

	if (flg == 1) {
		DrawString(0, 0, "�����܂���", GetColor(255, 255, 255));
	}

}

void CONTROL::Hit_Judgment() {

	for (int i = 0; i < 40; i++) {
		if ((double)px + pw >= ex[20] && (double)px <= ex[20] + eWidth[20] && (double)py + ph >= ex[20] && (double)py <= ey[20] + eHeight[20]) {
			flg = 1;
		}
	}

	DrawFormatString(50, 620, GetColor(255, 255, 255), "%d,%d,%d,%d", sx, sy, sw, sh);
	DrawFormatString(50, 520, GetColor(255, 255, 255), "%d,%d,%d,%d", px, py, pw, ph);
}