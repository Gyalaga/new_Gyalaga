#include "EnemyMgr.h"
#include "DxLib.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define PI 3.1415926f

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
	y = 132;
	x2 = 328;
	y2 = 82;
	x3 = 380;
	y3 = 32;
	sincount = 0;
	enemyAll = 0;
	goei_no = 0;
	atkActive = false;
	enemyAllMove = ENEMY_MOVERIGHT;
	intervalCnt = 0;
	boss_rand = 0;
	tmpBoss_rand = 0;

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
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {
		zako[i] = new ZAKO(x, y);
		zako[i]->Load_Image(zakoGh);
		x += 30;
		if (i == 9) {
			y -= 25;
			x = 310;
		}
	}

	//�S�G�C�̎��̂𐶐�����
	for (int i = 0; i < ENEMY_GOEINUM; i++) {
		goei[i] = new GOEI(x2, y2);
		goei[i]->Load_Image(goeiGh);
		goei_bazin_x[i] = x2;
		goei_bazin_y[i] = y2;
		goei[i]->Atacck(atkActive, i, goei_bazin_x[i], goei_bazin_y[i]);
		x2 += 35;
		if (i == 7) {
			y2 -= 25;
			x2 = 328;
		}
	}

	//�{�X�M�����K�̎��̂�ǉ�����
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		boss[i] = new BOSS(x3, y3);
		boss[i]->Load_Image(bossGh);
		x3 += 35;
	}
}

//�I������
void ENEMYMGR::Final() {

	//�m�ۂ��Ă����U�R�N���X�̃��������������
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {
		delete zako[i];
	}

	//�m�ۂ��Ă����S�G�C�N���X�̃��������������
	for (int i = 0; i < ENEMY_GOEINUM; i++) {
		delete goei[i];
	}

	//�m�ۂ��Ă����{�X�M�����K�N���X�̃��������������
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		delete boss[i];
	}
}

//�X�V����
void ENEMYMGR::Update() {

	/***�����̏�����***/
	srand((unsigned)time(NULL));

	//�U�R
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {
		zako[i]->Update();
	}

	//�S�G�C
	for (int i = 0; i < ENEMY_GOEINUM; i++) {
		goei[i]->Update();
	}

	//�{�X�M�����K
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		boss[i]->Update();
	}

	//�U�R�̌��݂̍��W���擾����
	for (int i = 0; i < 20; i++) {
		enemyX[i] = zako[i]->Send_X();
		enemyY[i] = zako[i]->Send_Y();
		width[i] = zako[i]->Send_Width();
		height[i] = zako[i]->Send_Height();
	}

	//�S�G�C�̌��݂̍��W���擾����
	for (int i = 0; i < 16; i++) {
		enemyX[i + GOEI_ORDER] = goei[i]->Send_X();
		enemyY[i + GOEI_ORDER] = goei[i]->Send_Y();
		width[i + GOEI_ORDER] = goei[i]->Send_Width();
		height[i + GOEI_ORDER] = goei[i]->Send_Height();
	}

	//�{�X�M�����K�̌��݂̍��W���擾����
	for (int i = 0; i < 4; i++) {
		enemyX[i + BOSS_ORDER] = boss[i]->Send_X();
		enemyY[i + BOSS_ORDER] = boss[i]->Send_Y();
		width[i + BOSS_ORDER] = boss[i]->Send_Width();
		height[i + BOSS_ORDER] = boss[i]->Send_Height();
		Yes[i] = boss[i]->Yes_OnActive();
	}

	//�Ԋu�J�E���g��240�𒴂���Ƃ�����������
	if (intervalCnt > INTERVAL_RESET)intervalCnt = 0;

	//sin�J�E���g��100�𒴂���Ɠ�����
	if (sincount >= 100) {
		bool atkActive = true;
		goei[goei_no]->Atacck(atkActive, goei_no,
			goei_bazin_x[goei_no], goei_bazin_y[goei_no]);

		/***�S�G�C����ɖ߂��Ă����^�C�~���O�ŁA�U���t���O��false�ɂ���***/
		if (sincount >= 863) {
			/***�S�G�C�c�������Ȃ��Ă����񂾁I�I�I***/
			bool atkActive = false;
			goei[goei_no]->Atacck(atkActive, goei_no,
				goei_bazin_x[goei_no], goei_bazin_y[goei_no]);
			/***���̃h���C�������_���ɂ���***/
			goei_no = (rand() % 15);
			/***���Ȃ���c�����c��Ȃ�!!!***/
			goei[goei_no]->Atacck(atkActive, goei_no,
				goei_bazin_x[goei_no], goei_bazin_y[goei_no]);
			sincount = 0;

		}
	}

	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		if (boss[i]->Send_AtkActive() == true)break;
		if (i == 3) {
			boss_rand = rand() % 4;
			boss[boss_rand]->TractorInit();
		}
	}

	boss[boss_rand]->Load_AtkActive(true);

	//�J�E���g��125�̎��S�̂𓮂���
	if (intervalCnt % INTERVAL_MIDDLE == 0) {
		enemyAll += enemyAllMove;

		//�U�R�ɑS�̂̈ړ��ʁE�Ԋu�𑗂�
		for (int i = 0; i < ENEMY_ZAKONUM; i++) {
			zako[i]->Load_AddMove(enemyAllMove);
			zako[i]->Load_Interval(intervalCnt);
		}

		//�S�G�C�ɑS�̂̈ړ��ʁE�Ԋu�𑗂�
		for (int i = 0; i < ENEMY_GOEINUM; i++) {
			goei[i]->Load_AddMove(enemyAllMove);
			goei[i]->Load_Interval(intervalCnt);
		}

		//�{�X�M�����K�̈ړ��ʁE�Ԋu�𑗂�
		for (int i = 0; i < ENEMY_BOSSNUM; i++) {
			boss[i]->Load_AddMove(enemyAllMove);
			boss[i]->Load_Interval(intervalCnt);
		}
	}

	//�S�̂œ��������̔���
	if (enemyAll <= -50) {
		enemyAllMove = ENEMY_MOVERIGHT;
	}
	if (enemyAll >= 50) {
		enemyAllMove = ENEMY_MOVELEFT;
	}
	sincount++;         //sin�ړ��J�E���g�𑝂₷
	intervalCnt++;		//�Ԋu�J�E���g�𑝂₷

}

//�`�揈��
void ENEMYMGR::Draw() {

	//�U�R
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {
		zako[i]->Draw();
	}

	//�S�G�C
	for (int i = 0; i < ENEMY_GOEINUM; i++) {
		goei[i]->Draw();
	}

	//�{�X�M�����K
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		boss[i]->Draw();
	}
}

//�R���g���[���N���X�Œ�`�����ϐ��̃|�C���^�ɍ��W��������
void ENEMYMGR::Send_Coordinate(double* setX, double* setY, int* setWidth, int* setHeight) {
	for (int i = 0; i < ENEMY_MAXNUM; i++) {
		setX[i] = enemyX[i];
		setY[i] = enemyY[i];
		setWidth[i] = width[i];
		setHeight[i] = height[i];
	}
}
void ENEMYMGR::Yes_Judgment(bool* flg) {
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		flg[i] = Yes[i];
	}
}

//�R���g���[���N���X����擾����Hit�����G��onActive��false�ɂ���
void ENEMYMGR::Hit_ChangeOnActive(int getDamage, int n) {

	//�_���[�W���e�G�N���X�֑���
	if (n < GOEI_ORDER) {

		zako[n]->Load_Damage(getDamage);
	}
	else if (n >= GOEI_ORDER && n < BOSS_ORDER) {

		goei[n - GOEI_ORDER]->Load_Damage(getDamage);
	}
	else if (n >= BOSS_ORDER && n < ENEMY_MAXNUM) {

		boss[n - BOSS_ORDER]->Load_Damage(getDamage);
	}
}

//�R���g���[���N���X�ɓ����蔻�肪�K�v���Ԃ�����
void ENEMYMGR::Judgment_OnActive(bool* setHitCheck) {

	//�e�U�R�������蔻���K�v������
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {

		if (zako[i]->Send_OnActive() == true) {
			setHitCheck[i] = false;
		}
		else {
			setHitCheck[i] = true;
		}
	}

	//�e�S�G�C�������蔻���K�v������
	for (int i = 0; i < ENEMY_GOEINUM; i++) {

		if (goei[i]->Send_OnActive() == true) {
			setHitCheck[i + GOEI_ORDER] = false;
		}
		else {
			setHitCheck[i + GOEI_ORDER] = true;
		}
	}

	//�e�{�X�M�����K�������蔻���K�v������
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {

		if (boss[i]->Send_OnActive() == true) {
			setHitCheck[i + BOSS_ORDER] = false;
		}
		else {
			setHitCheck[i + BOSS_ORDER] = true;
		}
	}
}

void ENEMYMGR::All() {
	Update();
	Draw();
}