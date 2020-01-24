#include "Zako.h"
#include "DxLib.h"
#include<math.h>
#define PI 3.1415926f
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
	Roto_x      = 2.0;      //Roto_x���W�̏����l
	Roto_y      = 0;      //Roto_y���W�̏����l
	angle       = 0;        //angle�̏����l
	R           = 200;      //���W�A���̏����l
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

void ZAKO::Atacck(bool atk) {

	atkActive = atk;

	if (atkActive == true) {
		x += sin(PI * sincount / 400.0f) * 3.5f;
		y += 2.5f;
	}
}

//�`�揈��
void ZAKO::Draw() {
	DrawRotaGraph(x, y, Roto_x,Roto_y,gh[0], TRUE);
	sincount += 1;
	angle += 1;
	//DrawGraph(Move_x, Move_y, gh[1], TRUE);
}

//�S�̂̓���
void ZAKO::Overall_Move() {
	
	x += allMoveAmount;
}