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

//onActive��false�ɂ���
void BOSS::Load_OnActive(bool setOnActive) {
	onAcitve = setOnActive;
}

//atkActive��true�ɂ���
void BOSS::Load_AtkActive(bool setAtkActive) {
	atkActive = setAtkActive;
}

//����������
void BOSS::Init(int ix, int iy) {

	int initAni[29] = { 0,1,2,3,4,5,6,7,8,9,10,11,10,11,10,11,10,11,10,9,8,7,6,5,4,3,2,1,0 };

	LoadDivGraph("./res/img/Galaga_OBJ_effect.png", 12, 5, 3, 51, 83, tGh);    // �摜�̕����ǂݍ���

	for (int i = 0; i < 29; i++) {
		ani[i] = initAni[i];
	}

	x = ix;					//x���W�̏�����
	y = iy;					//y���W�̏�����
	width = 30;				//����
	height = 30;			//����
	durability = 2;			//�ϋv��
	atkActive = false;		//�U������
	onAcitve = true;		//��������
	beamCnt = 0;			//�g���N�^�[�r�[���J�E���g
	beamOrder = 0;			//�\������ꏊ�w��
	bcnt = 0;				//�A�j���[�V�����p�t���O
	tractorFlg = false;		//�g���N�^�[�r�[�������˂��Ă邩����
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

		if (beamOrder >= 27)beamOrder = 0, beamCnt = 0;

	}
}

void BOSS::Tractor_Move() {
	if (y < (double)600 + height)y++;
}

//�X�V����
void BOSS::Update() {

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
		DrawRotaGraph(x, y, 2.0, 0, gh[0], TRUE);
		DrawGraph(x - (double)13 * 2, y - 5, tGh[ani[beamOrder]], TRUE); // �摜��\��
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

int BOSS::Send_Width() {
	return width;
}

int BOSS::Send_Height() {
	return height;
}