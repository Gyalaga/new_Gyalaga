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

//����������
void BOSS::Init(int ix, int iy) {
	x			= ix;		//x���W�̏�����
	y			= iy;		//y���W�̏�����
	width		= 18;		//����
	height		= 18;		//����
	durability	= 1;		//�ϋv��
	atkActive	= false;	//�U������
	onAcitve	= true;		//��������
}

//�I������
void BOSS::Final() {

}

//�X�V����
void BOSS::Update() {

}

//�`�揈��
void BOSS::Draw() {
	DrawRotaGraph(x, y, 2.0, 0, gh[0], TRUE);
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