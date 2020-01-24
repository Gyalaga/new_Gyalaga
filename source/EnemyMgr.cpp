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

	enemyAll = 0;
	enemyAllMove = ENEMY_MOVERIGHT;
	intervalCnt = 0;

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
			x = 310;
		}
	}

	//�S�G�C�̎��̂𐶐�����
	for (int i = 0; i < 16; i++) {
		goei[i] = new GOEI(x2, y2);
		goei[i]->Load_Image(goeiGh);
		x2 += 18;
		if (i == 7) {
			y2 -= 18;
			x2 = 328;
		}
	}

	//�{�X�M�����K�̎��̂�ǉ�����
	for (int i = 0; i < 4; i++) {
		boss[i] = new BOSS(x3, y3);
		boss[i]->Load_Image(bossGh);
		x3 += 18;
	}
}

//�I������
void ENEMYMGR::Final() {

	//�m�ۂ��Ă����U�R�N���X�̃��������������
	for (int i = 0; i < 20; i++) {
		delete zako[i];
	}

	//�m�ۂ��Ă����S�G�C�N���X�̃��������������
	for (int i = 0; i < 16; i++) {
		delete goei[i];
	}

	//�m�ۂ��Ă����{�X�M�����K�N���X�̃��������������
	for (int i = 0; i < 4; i++) {
		delete boss[i];
	}
}

//�X�V����
void ENEMYMGR::Update() {

	//�U�R
	for (int i = 0; i < 20; i++) {
		zako[i]->Update();
	}

	//�S�G�C
	for (int i = 0; i < 16; i++) {
		goei[i]->Update();
	}

	//�{�X�M�����K
	for (int i = 0; i < 4; i++) {
		boss[i]->Update();
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

		//�S�G�C�ɑS�̂̈ړ��ʂ𑗂�
		for (int i = 0; i < 16; i++) {
			goei[i]->Load_AddMove(enemyAllMove);
		}

		//�{�X�M�����K�̈ړ��ʂ𑗂�
		for (int i = 0; i < 4; i++) {
			boss[i]->Load_AddMove(enemyAllMove);
		}

	}

	//�S�̂œ��������̔���
	if (enemyAll <= -50) {
		enemyAllMove = ENEMY_MOVERIGHT;
	}
	if (enemyAll >= 50) {
		enemyAllMove = ENEMY_MOVELEFT;
	}

	intervalCnt++;		//�Ԋu�J�E���g�𑝂₷


}

//�`�揈��
void ENEMYMGR::Draw() {

	//�U�R
	for (int i = 0; i < 20; i++) {
		zako[i]->Draw();
	}

	//�S�G�C
	for (int i = 0; i < 16; i++) {
		goei[i]->Draw();
	}

	//�{�X�M�����K
	for (int i = 0; i < 4; i++) {
		boss[i]->Draw();
	}
}