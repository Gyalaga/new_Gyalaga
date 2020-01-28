#include "EnemyMgr.h"
#include "DxLib.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define PI 3.1415926f
#define GOEI_NUM         15   // �S�G�C�̐�
#define GOEI_P            0   // �S�G�C�̍U���p�^�[��

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
	x            = 310;
	y            = 120;
	x2           = 328;
	y2           = 68;
	x3           = 380;
	y3           = 15;
	sincount     = 0;
	goei_no      = 0;
	atkActive    = false;
	goei_pataan  = 1;
	enemyAll     = -10;
	enemyAllMove = ENEMY_MOVERIGHT;
	enemy_GO     = 0;                   //�����́�    0;�� 1;��
	Move_cnt     = 0;
	intervalCnt  = 0;

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
		x += 30;
		if (i == 9) {
			y -= 25;
			x = 310;
		}
	}

	//�S�G�C�̎��̂𐶐�����
	for (int i = 0; i < 16; i++) {
		goei[i] = new GOEI(x2, y2);
		goei[i]->Load_Image(goeiGh);
		goei_bazin_x[i] = x2;
		goei_bazin_y[i] = y2;
		goei[i]->Atacck(atkActive, goei_no,goei_pataan,goei_bazin_x[i],goei_bazin_y[i]);
		x2 += 35;
		if (i == 7) {
			y2 -= 20;
			x2 = 328;
		}
	}

	//�{�X�M�����K�̎��̂�ǉ�����
	for (int i = 0; i < 4; i++) {
		boss[i] = new BOSS(x3, y3);
		boss[i]->Load_Image(bossGh);
		x3 += 35;
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

	//�U�R�̌��݂̍��W���擾����
	for (int i = 0; i < 20; i++) {
		enemyX[i] = zako[i]->Send_X();
		enemyY[i] = zako[i]->Send_Y();
	}


	//�S�G�C�̌��݂̍��W���擾����
	for (int i = 0; i < 16; i++) {
		enemyX[i + GOEI_ORDER] = goei[i]->Send_X();
		enemyY[i + GOEI_ORDER] = goei[i]->Send_Y();
	}

	//�{�X�M�����K�̌��݂̍��W���擾����
	for (int i = 0; i < 4; i++) {
		enemyX[i + BOSS_ORDER] = boss[i]->Send_X();
		enemyY[i + BOSS_ORDER] = boss[i]->Send_Y();
	}

	/***�Ԋu�J�E���g��250�𒴂���Ƃ�����������***/
	if (intervalCnt > 250)intervalCnt = 0;

	/***�����̏�����***/
	srand((unsigned)time(NULL));
	/***sin�J�E���g��100�𒴂���Ɠ�����***/
	if (sincount >= 100) {
	
		/***�S�G�C�t���O��false�̎��ɍU���t���O��true�ɂ���***/
		/***�����Ō��߂��S�G�C�𓮂���**************************/
		if (atkActive == false) {	
			bool atkActive = true;
			goei[goei_no]->Atacck(atkActive,goei_no,goei_pataan,goei_bazin_x[goei_no],goei_bazin_y[goei_no]);
		}
		
		/***�S�G�C����ɖ߂��Ă����^�C�~���O�ŁA�U���t���O��false�ɂ���***/
		if (sincount >= 863) {
		
            /***�S�G�C�c�������Ȃ��Ă����񂾁I�I�I***/
			goei[goei_no]->Atacck(atkActive,goei_no,goei_pataan,goei_bazin_x[goei_no],goei_bazin_y[goei_no]);

			/***���̃h���C�������_���ɂ���***/
			goei_no = (rand() % GOEI_NUM);
			/***���̍U���p�^�[���������_���ɂ���***
			goei_pataan = (rand() % GOEI_P);

			/***���Ȃ���c�����c��Ȃ�!!!***/
			goei[goei_no]->Atacck(atkActive,goei_no,goei_pataan,goei_bazin_x[goei_no],goei_bazin_y[goei_no]);

			sincount = 0;
		}

		zako[0]->Atacck(atkActive);
	}

	//�J�E���g��120�̎��S�̂𓮂���
	if (intervalCnt % 125 == 0) {
		enemyAll += enemyAllMove;

		//�U�R�ɑS�̂̈ړ��ʂ𑗂�
		for (int i = 0; i < 20; i++) {
			zako[i]->Load_AddMove(enemyAllMove);
	
		}
		//�S�G�C�ɑS�̂̈ړ��ʂ𑗂�
		int h_flg = 0;

		for (int i = 0; i < 16; i++) {
			goei[i]->Load_AddMove(enemyAllMove);
			goei[goei_no]->Atacck(atkActive, goei_no,goei_pataan,goei_bazin_x[goei_no],goei_bazin_y[goei_no]);
			goei[i]->Goei_change(intervalCnt);
		}

		//�{�X�M�����K�̈ړ��ʂ𑗂�
		for (int i = 0; i < 4; i++) {
			boss[i]->Load_AddMove(enemyAllMove);
		}

	}
	/***�S�̂œ��������̔���***/
	if (enemyAll <= -50) {
		enemyAllMove = ENEMY_MOVERIGHT;
		enemy_GO = 0;   //���ɐi��
	}
	if (enemyAll >= 50) {
		enemyAllMove = ENEMY_MOVELEFT;
		Move_cnt -= 1;
		enemy_GO = 1;   //���ɐi��
	}
	sincount++;         //sin�ړ��J�E���g�𑝂₷
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
	int Red = GetColor(255, 0, 0);            //�Ԃ̐F
	DrawFormatString(900, 500, Red, "%d", sincount);
}

//�R���g���[���N���X�Œ�`�����ϐ��̃|�C���^�ɍ��W��������
void ENEMYMGR::Send_Coordinate(double* setX, double* setY) {
	for (int i = 0; i < 40; i++) {
		*(setX + i) = enemyX[i];
		*(setY + i) = enemyY[i];
	}
}