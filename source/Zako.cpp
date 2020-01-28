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

//�_���[�W���󂯂鏈��
void ZAKO::Load_Damage(int damage) {
	durability -= damage;
}

//�A�j���[�V��������
void ZAKO::Load_Interval(int interval) {
	
	if (atkActive == false) {
		if (interval == 120) {
			moveAni = 1;
		}
		else if (interval == 240) {
			moveAni = 0;
		}
		aniOrder = moveAni;
	}
}

//����������
void ZAKO::Init(int ix,int iy) {
	x			= ix;		//x���W�̏�����
	y			= iy;		//y���W�̏�����
	Rota_zome   = 2.0;      //�g�嗦
	Rota_angle  = 0;        //�`��p�x
	angle       = 75;       //angle�̏����l
	R           = 200;      //���W�A���̏����l
	width		= 30;		//����
	height		= 30;		//����
	FLAG_X      = 800;      //zakoflg�Ŏg���l
	FLAG_Y      = 200;      //zakoflg�Ŏg���l
	durability	= 1;		//�ϋv��
	aniOrder	= 0;		//�`�悷��摜�ԍ�
	moveAni		= 0;		//�S�̂̓����̃A�j���[�V����
	atkActive	= false;	//�U������
	onAcitve	= true;		//��������
	zakoflg     = 0;        //�U�R�G�̋�����ς���t���O
	                        //0:��]�ړ� 1:�Ȑ��ړ� 2:�Ȃ� 3:�Ȃ�
}

//�I������
void ZAKO::Final() {

}

//�X�V����
void ZAKO::Update() {

	//onActive��false�ɂ���
	if (durability == 0 && onAcitve == true) {
		onAcitve = false;
		PlaySoundFile("./res/wav/gal_se_zako_striken.wav", DX_PLAYTYPE_BACK);
	}
}

/******************
void ZAKO::Atacck(bool atk) {

	atkActive = atk;

	if (atkActive == true) {
		//Draw_angle();

		if (FLAG_Y <= y && zakoflg == 0) {
			zakoflg = 1;
			FLAG_Y = 550;
		}
		if (FLAG_Y <= y && zakoflg == 1) {
			zakoflg = 2;
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

		if (zakoflg == 0) {
			x += -R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			//sin(PI * sincount / 80.0f) * 2.0f;
			y += -R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			//1.5f;
			angle += 1;
			Rota_angle -= 0.03;
		}
		if (zakoflg == 1) {

			x += 2.5;//sin(PI * sincount / 80.0f) * 2.0f;
			y += 1.5f;
		}
		if (zakoflg == 2) {

			x += R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y += R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 2;
			Rota_angle -= 0.06;
			if (angle >= 200 && zakoflg == 2) {
				zakoflg = 3;
			}
		}
		if (zakoflg == 3) {
			x -= sin(PI * sincount / 100.0f) * 2.0f;
			y += 2.5f;
			Rota_angle += 0.01;
		}
	}
}
***********/

//�`�揈��
void ZAKO::Draw() {

	if (onAcitve == true) {
		DrawRotaGraph(x, y, Rota_zome, Rota_angle, gh[aniOrder], TRUE);
	}

	int Red = GetColor(255, 0, 0);            //�Ԃ̐F
	DrawFormatString(900, 500, Red, "%d",Rota_angle);
	
	sincount += 1;
	angle += 1;
}

/*****�]�݂�����*******

//�`��̊p�x��ς��鏈��
void ZAKO::Draw_angle() {

	if (angle >= 1075) {
		angle = 0;
	}
	if (angle >= 400 && angle <= 600) {
		Rota_angle = 45;
	}
    if (angle >= 700 && angle<= 900 ) {
		Rota_angle = 60;
	}
}
***********************/
//�S�̂̓���
void ZAKO::Overall_Move() {
	
	x += allMoveAmount;
}

//x���W�𑗂鏈��
double ZAKO::Send_X() {
	return x;
}

//y���W�𑗂鏈��
double ZAKO::Send_Y() {
	return y;
}

//�����𑗂鏈��
int ZAKO::Send_Width() {
	return width;
}

//�����𑗂鏈��
int ZAKO::Send_Height() {
	return height;
}

//onActive�𑗂鏈��
bool ZAKO::Send_OnActive() {
	return onAcitve;
}