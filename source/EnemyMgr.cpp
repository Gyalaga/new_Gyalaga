#include "EnemyMgr.h"
#include "DxLib.h"

//�R���X�g���N�^
ENEMYMGR::ENEMYMGR() {
	Init();
}

//�f�X�g���N�^
ENEMYMGR::~ENEMYMGR() {
	Final();
}

//����������
void ENEMYMGR::Init() {

	int x, y, x2, y2, x3, y3;	//���t�@�C������f�[�^��ǂݍ��ދ@�\������폜���܂�
	x = 310;
	y = 72;
	x2 = 328;
	y2 = 36;
	x3 = 364;
	y3 = 0;

	enemyAll		= 0;
	enemyAllMove	= ENEMY_MOVERIGHT;
	direction_flg	= 0;
	intervalCnt		= 0;

	//�G�̉摜���ꎞ�I��baseGh�Ɋi�[����
	LoadDivGraph("./res/img/Galaga_OBJ_enemy.png", 50, 5, 10, 18, 18, baseGh);

	//�e�G�̃N���X�֑���摜�̏���
	for (int i = 0; i < MAX_TYPE; i++) {
		if (i < GENERAL_TYPE) {
			zakoGh[i] = baseGh[i];
			goeiGh[i] = baseGh[i + GOEI_START];
		}
		bossGh[i] = baseGh[i + BOSS_START];
	}

	//�U�R�̎��̂𐶐�����
	for (int i = 0; i < 20; i++) {
		zako[i] = new ZAKO(x, y);
		zako[i]->Load_Image(zakoGh);
		x += 18;
		if (i == 9) {
			y -= 18;
			x =	310;
		}

		//�S�G�C�̎��̂𐶐�����
		if (i < 16) {
			goei[i] = new GOEI(x2, y2);
			goei[i]->Load_Image(goeiGh);
			x2 += 18;

			if (i == 7) {
				y2 -= 18;
				x2 = 328;
			}
		}

		if (i < 4) {
			boss[i] = new BOSS(x3, y3);
			boss[i]->Load_Image(bossGh);
			x3 += 18;
		}
	}
}

//�I������
void ENEMYMGR::Final() {

	//�m�ۂ��Ă������������������
	for (int i = 0; i < 20; i++) {
		delete zako[i];
		if (i < 16)delete goei[i];
		if (i < 4)delete boss[i];
	}
}

//�X�V����
void ENEMYMGR::Update() {

	for (int i = 0; i < 20; i++) {
		zako[i]->Update();
		if (i < 16)goei[i]->Update();
		if (i < 4)boss[i]->Update();
	}

	//�Ԋu�J�E���g��60�𒴂���Ƃ�����������
	if (intervalCnt > 120)intervalCnt = 0;

	//�J�E���g��60�̎��S�̂𓮂���
	if (intervalCnt == 120) {
		enemyAll += enemyAllMove;

		//�U�R�ɑS�̂̈ړ��ʂ𑗂�
		for (int i = 0; i < 20; i++) {
			zako[i]->Load_AddMove(enemyAllMove);
		}

	}

	//�S�̂œ��������̔���
	if (enemyAll <= 0) {
		enemyAllMove = ENEMY_MOVERIGHT;
		direction_flg = 0;
	}
	if (enemyAll >= 50) {
		enemyAllMove = ENEMY_MOVELEFT;
		direction_flg = 1;
	}

	intervalCnt++;		//�Ԋu�J�E���g�𑝂₷
}

//�`�揈��
void ENEMYMGR::Draw() {
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%d",enemyAll);

	for (int i = 0; i < 20; i++) {
		zako[i]->Draw();
		if (i < 16)goei[i]->Draw();
		if (i < 4)boss[i]->Draw();
	}
}