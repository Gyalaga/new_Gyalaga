#include "Zako.h"
#include "DxLib.h"

//�R���X�g���N�^
ZAKO::ZAKO(int getX, int getY) {
	Init(getX, getY);
}

//�G�l�~�[�Ǘ��N���X����摜��ǂݍ���
void ZAKO::Load_Image(int* sGh) {

	for (int i = 0; i < 5; i++) {
		gh[i] = *(sGh + i);
	}
}

//�G�l�~�[�Ǘ��N���X����S�̂̈ړ��ʂ��擾����
void ZAKO::Load_AddMove(int addMove) {

	allMoveAmount = addMove;	//�S�̂̈ړ��ʂ��U�R�N���X�ɓK�p������

	//�U�����ł͂Ȃ��ꍇ
	if (atkActive == false) {
		Overall_Move();
	}

}

//����������
void ZAKO::Init(int ix,int iy) {
	x			= ix;		//x���W�̏�����
	y			= iy;		//y���W�̏�����
	width		= 18;		//����
	height		= 18;		//����
	durability	= 1;		//�ϋv��
	atkActive	= false;	//�U������
	onAcitve	= true;		//��������
}

//�I������
void ZAKO::Final() {

}

//�X�V����
void ZAKO::Update() {

}

//�`�揈��
void ZAKO::Draw() {
	DrawGraph(x, y, gh[0], TRUE);
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%d", allMoveAmount);
}

//�S�̂̓���
void ZAKO::Overall_Move() {
	
	x += allMoveAmount;
}