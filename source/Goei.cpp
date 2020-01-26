#include "Goei.h"
#include "DxLib.h"

//�R���X�g���N�^
GOEI::GOEI(int getX, int getY) {
	Init(getX, getY);
}

//�G�l�~�[�Ǘ��N���X����摜��ǂݍ���
void GOEI::Load_Image(int* sGh) {
	
	for (int i = 0; i < 5; i++) {
		gh[i] = *(sGh + i);
	}
}

//�G�l�~�[�Ǘ��N���X����S�̂̈ړ��ʂ��擾����
void GOEI::Load_AddMove(int addMove) {

	allMoveAmount = addMove;		//�S�̂̈ړ��ʂ��S�G�C�N���X�ɓK�p������

	//�U�����ł͂Ȃ��Ƃ�
	if (atkActive == false) {
		Overall_Move();
	}
}

//����������
void GOEI::Init(int ix, int iy) {
	x			= ix;		//x���W
	y			= iy;		//y���W
	width		= 18;		//����
	height		= 18;		//����
	durability	= 1;		//�ϋv��
	atkActive	= false;	//�U������
	onAcitve	= true;		//��������
}

//�I������
void GOEI::Final() {

}

//�X�V����
void GOEI::Update() {

}

//�`�揈��
void GOEI::Draw() {
	DrawRotaGraph(x, y, 2.0, 0, gh[0], TRUE);
}

//�S�̂̓���
void GOEI::Overall_Move() {
	x += allMoveAmount;
}

//x���W�𑗂鏈��
double GOEI::Send_X() {
	return x;
}

//y���W�𑗂鏈��
double GOEI::Send_Y() {
	return y;
}