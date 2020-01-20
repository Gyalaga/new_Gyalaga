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

	int x, y, x2, y2;	//���t�@�C������f�[�^��ǂݍ��ދ@�\������폜���܂�
	x = 310;
	y = 72;
	x2 = 328;
	y2 = 36;

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

		if (i < 16) {
			goei[i] = new GOEI(x2, y2);
			goei[i]->Load_Image(goeiGh);
			x2 += 18;

			if (i == 8) {
				y -= 18;
				x = 328;
			}
		}
	}
}

//�I������
void ENEMYMGR::Final() {

	//�m�ۂ��Ă������������������
	for (int i = 0; i < 20; i++) {
		delete zako[i];
		if (i < 16)delete goei[i];
	}
}

//�X�V����
void ENEMYMGR::Update() {

	for (int i = 0; i < 20; i++) {
		zako[i]->Update();
		if (i < 16)goei[i]->Update();
	}
}

//�`�揈��
void ENEMYMGR::Draw() {

	for (int i = 0; i < 20; i++) {
		zako[i]->Draw();
		if (i < 16)goei[i]->Draw();
	}
}