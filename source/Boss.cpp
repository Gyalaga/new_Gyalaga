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
	DrawGraph(x, y, gh[0], TRUE);
}