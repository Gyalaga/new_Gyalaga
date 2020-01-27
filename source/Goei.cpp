#include "Goei.h"
#include "DxLib.h"
#include<math.h>
#define PI 3.1415926f
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
	Rota_zome = 2.0;        //�g�嗦
	Rota_angle = 0;         //�`��p�x
	angle = 75;             //angle�̏����l
	R = 150;                //���W�A���̏����l
	i = 0;                  //�U�R�̉摜��؂�ւ���悤
	width		= 18;		//����
	height		= 18;		//����
	FLAG_X = 800;           //goeiflg�Ŏg���l
	FLAG_Y = 200;           //goeiflg�Ŏg���l
	durability	= 1;		//�ϋv��
	atkActive	= false;	//�U������
	onAcitve	= true;		//��������
	goeiflg = 0;            //�U�R�G�̋�����ς���t���O
							//0:��]�ړ� 1:�Ȑ��ړ� 2:�Ȃ� 3:�Ȃ�
}

//�I������
void GOEI::Final() {

}

//�X�V����
void GOEI::Update() {

}

void GOEI::Atacck(bool atk) {

	atkActive = atk;

	if (atkActive == true) {
		//Draw_angle();

		if (FLAG_Y <= y && goeiflg == 0) {
			goeiflg = 1;
			FLAG_Y = 550;
		}
		if (FLAG_Y <= y && goeiflg == 1) {
			goeiflg = 2;
			angle = -90;
			R = 150;
		}
		if (y >= 1120) {
			x = 350;
			y = -50;
			if (y < 120) {
				y += 2;
				x -= 2;
			}
			else {
				atkActive = false;
			}
		}

		if (goeiflg == 0) {
			x -= -R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			//sin(PI * sincount / 80.0f) * 2.0f;
			y -= -R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			//1.5f;
			angle += 1;
			Rota_angle -= 0.04;
		}
		if (goeiflg == 1) {

			x += 2.5;//sin(PI * sincount / 80.0f) * 2.0f;
			y += 1.5f;
		}
		if (goeiflg == 2) {

			x += R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y += R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 2;
			Rota_angle -= 0.04;
			if (angle >= 200 && goeiflg == 2) {
				goeiflg = 3;
			}
		}
		if (goeiflg == 3) {
			x -= sin(PI * sincount / 100.0f) * 2.0f;
			y += 2.5f;
			//Rota_angle += 0.01;
		}
	}
}

//�`�揈��
void GOEI::Draw() {
	DrawRotaGraph(x, y, Rota_zome, Rota_angle, gh[i], TRUE);
}

void GOEI::Goei_change(int interVal) {

	goei_change = interVal;

	if (goei_change == 120) {
		i = 1;
	}
	if (goei_change == 240) {
		i = 0;
	}
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