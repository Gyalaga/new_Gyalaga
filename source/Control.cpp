#include "Control.h"
#include "DxLib.h"

//�R���g���[���N���X�̃R���X�g���N�^
CONTROL::CONTROL() {

	Init();		//����������
}

//�R���g���[���N���X�̃f�X�g���N�^
CONTROL::~CONTROL() {

	Final();	//�I������
}

//����������
void CONTROL::Init() {

	enemyMgr = new ENEMYMGR;	//�G�l�~�[�Ǘ��N���X�̓��I�m�ۂ�����

	//�G�l�~�[�֘A�Ŏg�p����ϐ��̏�����
	for (int i = 0; i < 40; i++) {
		ex[i]		= 0;
		ey[i]		= 0;
		eWidth[i]	= 0;
		eHeight[i]	= 0;
		hitCheck[i] = false;
	}
	damage = 1;

	//�v���C���[�֘A�Ŏg�p����ϐ��̏�����
	Player_Init();
	Shot_init();
	px	= 0;
	py	= 0;
	pw	= 0;
	ph	= 0;
	sx	= 0;
	sy	= 0;
	sx2 = 0;
	sy2 = 0;
	sw	= 0;
	sh	= 0;
	hf	= 0;
	hp  = 3;
	score = 0;
	//�X�R�A�֘A�̏�����
	Score_Init();
	//SE�֘A�Ŏg�p����ϐ��̏�����
	wavcnt = 0;
	wavflg = 0;

	//�Q�[���I���֘A�Ŏg�p����ϐ��̏�����
	gameEnd		= false;
	gameEndCnt	= 0;
}

//�I������
void CONTROL::Final() {

	delete enemyMgr;
}

//�Q�[���̑S�̐���
void CONTROL::GameControl() {

	for (int i = 0; i < 40; i++) {
		if (hitCheck[i] == true)gameEndCnt++;
	}
	if (hp == 0)gameEnd = true;
	if (gameEndCnt == 40)gameEnd = true;
	else gameEndCnt = 0;

	if (gameEnd == false) {

		Score_Save();		//�n�C�X�R�A���L�^����
		Score_Draw();		//�X�R�A�̕`��
		SetFontSize(48);
		DrawString(850, 570, "������@", GetColor(255, 255, 255));
		SetFontSize(32);
		DrawString(850, 650, "�e���ˁFSPACE", GetColor(255, 255, 255));
		DrawString(850, 750, "�E�ړ��F�@��", GetColor(255, 255, 255));
		DrawString(850, 700, "���ړ��F�@��", GetColor(255, 255, 255));
		SetFontSize(16);
		if (wavcnt < 800)wavcnt++;	//SE�p�J�E���g�𑝂₷

		//�X�^�[�g��
		if (wavcnt >= 10) {

			if (wavcnt < 800)DrawFormatString(380, 380, GetColor(255, 255, 255), "START");
			if (wavflg == 0)PlaySoundFile("./res/wav/gal_music_gamestart.wav", DX_PLAYTYPE_BACK);
			wavflg = 1;
		}

		//SE����I�������
	if (wavcnt == 800) {

			Player_All();		//�v���C���[�S�̊Ǘ�
			enemyMgr->All();	//�G�l�~�[�Ǘ��N���X�̑S�̊Ǘ�

			//�����蔻��֘A�̍��W�擾����
			Player_judgment(&px, &py, &pw, &ph, &sx, &sy, &sw, &sh, &sx2, &sy2, &hf,&hp);
			enemyMgr->Send_Coordinate(ex, ey, eWidth, eHeight);

			Hit_Judgment();		//�����蔻�菈��
		}
	}
}

//�����蔻�菈��
void CONTROL::Hit_Judgment() {

	enemyMgr->Judgment_OnActive(hitCheck);		//hitCheck�ɓ����蔻�肪�K�v���̏����i�[����
	enemyMgr->Yes_Judgment(No);
	for (int i = 0; i < 40; i++) {

		if (hitCheck[i] == true)continue;	//�����蔻�肪�K�v�ł͂Ȃ��ꍇ���̃��[�v��

		//�v���C���[�ƓG�̓����蔻��
		if (hf == 0 && (double)px + pw >= ex[i] && (double)px <= ex[i] + eWidth[i] && (double)py + ph >= ey[i] && (double)py <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(damage, i);
			c.c = 1;
			Player_hit(c.c);
			hf = 1;
			Player_hitflg(hf);
		}

		//�v���C���[��1���ڂ̒e�ƓG�̓����蔻��
		if (bullet.sf[0] == 1 && (double)sx + sw >= ex[i] && (double)sx <= ex[i] + eWidth[i] && (double)sy+sh  >= ey[i] && (double)sy+sh <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(damage, i);
			bullet.sf[0] = 0;
			score += 100;
		    Score_up(score);
		}

		//�v���C���[��2���ڂ̒e�ƓG�̓����蔻��
		if (bullet.sf[1] == 1 && (double)sx2 + sw >= ex[i] && (double)sx2 <= ex[i] + eWidth[i] && (double)sy2+sh >= ey[i] && (double)sy2+sh <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(damage, i);
			bullet.sf[1] = 0;
			score += 100;
			Score_up(score);
		}
		for (int j = 0; j <= 4; j++)
		{
			if (No[j] == true)
			{
				//�v���C���[�ƓG�̓����蔻��
				if (hf == 0 && (double)px + pw >= ex[j+ BOSS_ORDER] - 10 && (double)px <= ex[j+ BOSS_ORDER] + eWidth[j+ BOSS_ORDER] + 10 && (double)py + ph >= ey[j+ BOSS_ORDER] && (double)py <= ey[j+ BOSS_ORDER] + eHeight[j+ BOSS_ORDER] + 60) {
					c.c = 5;
					Player_hit(c.c);
					hf = 1;
					Player_hitflg(hf);
					Player_Enemy(ex[j + BOSS_ORDER], ey[j + BOSS_ORDER]);
				}
			}
		}
	}
}

//�Q�[���I�����ǂ������Q�[���N���X�֑���
bool CONTROL::GameEnd_Judgment() {
	return gameEnd;
}