#include "Boss.h"
#include "DxLib.h"

//�R���X�g���N�^
BOSS::BOSS(int getX, int getY) {
	Init(getX, getY);
}

//�G�l�~�[�Ǘ��N���X����摜��ǂݍ���
void BOSS::Load_Image(int* sGh) {

	for (int i = 0; i < 10; i++) {
		gh[i] = *(sGh + i);
	}
}

//�G�l�~�[�Ǘ��N���X����S�̂̈ړ��ʂ��擾����
void BOSS::Load_AddMove(int addMove) {

	allMoveAmount = addMove;

	//�U�����ł͂Ȃ��ꍇ
	if (atkActive == false) {
		Overall_Move();
	}
}

//�_���[�W���󂯂鏈��
void BOSS::Load_Damage(int damage) {
	durability -= damage;

	if (durability == 1) {
		changeMode = true;
	}
}

//�A�j���[�V��������
void BOSS::Load_Interval(int interval) {

	if (atkActive == false) {

		if (durability == 2) {
			if (interval == 120) {
				moveAni = 1;
			}
			else if (interval == 240) {
				moveAni = 0;
			}
		}
		else if (durability == 1) {
			if (interval == 120) {
				moveAni = 6;
			}
			else if (interval == 240) {
				moveAni = 5;
			}
		}
		aniOrder = moveAni;
	}
}

//atkActive��true�ɂ���
void BOSS::Load_AtkActive(bool setAtkActive) {

	if (onAcitve == true) {
		atkActive = setAtkActive;
	}
}

//����������
void BOSS::Init(int ix, int iy) {

	int initAni[29] = { 0,1,2,3,4,5,6,7,8,9,10,11,10,11,10,11,10,11,10,9,8,7,6,5,4,3,2,1,0 };

	LoadDivGraph("./res/img/Galaga_OBJ_effect.png", 12, 5, 3, 51, 83, tGh);    // �摜�̕����ǂݍ���

	for (int i = 0; i < 29; i++) {
		tractorAni[i] = initAni[i];
	}

	x = ix;					//x���W�̏�����
	y = iy;					//y���W�̏�����
	width = 30;				//����
	height = 30;			//����
	aniOrder = 0;			//�`�悷��摜�ԍ�
	moveAni = 0;			//�S�̂̓����̃A�j���[�V����
	durability = 2;			//�ϋv��
	atkActive = false;		//�U������
	onAcitve = true;		//��������
	beamCnt = 0;			//�g���N�^�[�r�[���J�E���g
	beamOrder = 0;			//�\������ꏊ�w��
	bcnt = 0;				//�A�j���[�V�����p�t���O
	tractorFlg = false;		//�g���N�^�[�r�[�������˂��Ă邩����
	changeMode = false;		//���`�ԗp
	biimflg = false;        //�����蔻��p
}

//�I������
void BOSS::Final() {

}

//�g���N�^�[�r�[�����ˏ���
void BOSS::Tractor_Beam() {

	beamCnt++;

	if (beamCnt > 100)beamCnt = 100;

	if (beamCnt == 100) {

		bcnt++;

		if (bcnt >= 10)beamOrder++, bcnt = 0;
		if (tractorAni[beamOrder] >= 8)
		{
			biimflg = true;
		}
		else
		{
			biimflg = false;
		}
		if (beamOrder >= 27)beamOrder = 0, beamCnt = 0;

	}
}

void BOSS::Tractor_Move() {
	if (y < (double)600 + height)y++;
}

//�X�V����
void BOSS::Update() {

	if (durability == 1 && changeMode == true) {

		if (aniOrder == 0) {
			aniOrder = 5;
		}
		else if (aniOrder == 1) {
			aniOrder = 6;
		}

		changeMode = false;
	}

	//onActive��false�ɂ���
	if (durability == 0 && onAcitve == true) {
		onAcitve = false;
		atkActive = false;
		tractorFlg = false;
		PlaySoundFile("./res/wav/gal_se_boss_striken_2.wav", DX_PLAYTYPE_BACK);
	}

	if (atkActive == true) {
		tractorFlg = true;
	}

	if (tractorFlg == true) {
		Tractor_Beam();
		Tractor_Move();
	}
}

//�`�揈��
void BOSS::Draw() {

	if (onAcitve == true) {
		DrawRotaGraph(x, y, 2.0, 0, gh[aniOrder], TRUE);
	}
	if (tractorFlg == true) {
		DrawGraph(x - (double)13 * 2, y - 5, tGh[tractorAni[beamOrder]], TRUE); // �摜��\��
	}
}

//�S�̂̓���
void BOSS::Overall_Move() {
	x += allMoveAmount;
}

//x���W�𑗂鏈��
double BOSS::Send_X() {
	return x;
}

//y���W�𑗂鏈��
double BOSS::Send_Y() {
	return y;
}

//�����𑗂鏈��
int BOSS::Send_Width() {
	return width;
}

//�����𑗂鏈��
int BOSS::Send_Height() {
	return height;
}

//onActive�𑗂鏈��
bool BOSS::Send_OnActive() {
	return onAcitve;
}
//biimflg�𑗂鏈��
bool BOSS::Yes_OnActive() {
	return biimflg;
}