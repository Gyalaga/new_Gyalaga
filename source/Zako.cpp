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

//����������
void ZAKO::Init(int ix,int iy) {
	x		= ix;	//x���W�̏�����
	y		= iy;	//y���W�̏�����
	width	= 18;	//����
	height	= 18;	//����
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
}