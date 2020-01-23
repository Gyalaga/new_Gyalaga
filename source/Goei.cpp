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
	DrawGraph(x, y, gh[0], TRUE);
}