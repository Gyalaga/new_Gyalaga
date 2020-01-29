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
		if (allMoveAmount == ENEMY_MOVERIGHT) {
			Move_flg = 0;  //�E
			Move_cnt += 1;
			Overall_Move();
		}
		else {
			Move_flg = 1;
			Move_cnt -= 1; //��
			Overall_Move();
		}
	}
}

//�_���[�W���󂯂鏈��
void GOEI::Load_Damage(int damage) {
	durability -= damage;
}

//�A�j���[�V��������
void GOEI::Load_Interval(int interval) {

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
void GOEI::Init(int ix, int iy) {
	x = ix;		//x���W
	y = iy;		//y���W
	Rota_zome = 2.0;        //�g�嗦
	Rota_angle = 0;         //�`��p�x
	angle = 75;             //angle�̏����l
	R = 150;                //���W�A���̏����l
	width = 30;		//����
	height = 30;		//����
	FLAG_X = 800;           //goeiflg�Ŏg���l
	FLAG_Y = 200;           //goeiflg�Ŏg���l
	durability = 1;		//�ϋv��
	aniOrder = 0;			//�`�悷��摜�ԍ�
	moveAni = 0;			//�S�̂̓����̃A�j���[�V����
	atkActive = false;	//�U������
	onAcitve = true;		//��������
	goeiflg = 0;            //�U�R�G�̋�����ς���t���O
							//0:��]�ړ� 1:�Ȑ��ړ� 2:�Ȃ� 3:�Ȃ�
	zigzagcnt = 0;          //�W�O�U�O�J�E���g
	zigzagflg = 0;          //�W�O�U�O�t���O
	Move_flg = 0;          //�ŏ��́�  0:�E 1:��
	Move_cnt = 0;

}

//�I������
void GOEI::Final() {

}

//�X�V����
void GOEI::Update() {

	//onActive��false�ɂ���
	if (durability == 0 && onAcitve == true) {
		onAcitve = false;
		PlaySoundFile("./res/wav/gal_se_goei_striken.wav", DX_PLAYTYPE_BACK);
	}
}

void GOEI::Atacck(bool atk, int dorei_no, double bazin_x, double bazin_y) {

	/***�G�l�~�[�}�l�W���[����󂯎�����f�[�^���i�[***/
	atkActive = atk;           //�S�G�C�̍U���t���O
	int goei_no = dorei_no;  //�����S�G�C�̔ԍ�
	double x_bazin = bazin_x;  //�����S�G�C��,�����O�̍��W
	double y_bazin = bazin_y;  //�����S�G�C��,�����O�̍��W

	if (atkActive == true) {

		/***�ŏ��̉�]***/
		if (goeiflg == 0) {
			x -= -R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			//sin(PI * sincount / 80.0f) * 2.0f;
			y -= -R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			//1.5f;
			angle += 1;
			Rota_angle -= 0.04;
		}
		/***��]��������A���̍s�����ڂ��ׂɃt���O��؂�ւ���***/
		if (FLAG_Y <= y && goeiflg == 0) {
			goeiflg = 1;
			FLAG_Y = 550;
		}
		/***��苗���܂Œ��i������A���̍s���Ɉڂ����邽�߃t���O��؂�ւ���***/
		if (FLAG_Y <= y && goeiflg == 1) {
			goeiflg = 2;
			angle = -90;
			R = 150;
		}
		/***�΂߂�***/
		if (goeiflg == 1) {
			x += 2.5;//sin(PI * sincount / 80.0f) * 2.0f;
			y += 1.5f;
		}
		/***���i��̉�]***/
		if (goeiflg == 2) {

			x += R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y += R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 2;
			Rota_angle -= 0.04;
			if (angle >= 162 && goeiflg == 2) {
				goeiflg = 3;
			}
		}
		/***�Ō�̒��i***/
		if (goeiflg == 3) {
			x -= 1.5f;
			y += 2.5f;
			//Rota_angle += 0.01;
		}
		/***��ʊO�ɏo���S�G�C����Ƀ��[�v������***/
		if (y >= 1100) {
			if (Move_flg == 0) { //�G�l�~�[�S�̂��E�ɐi��ł��ꍇ
				x_bazin = x_bazin + (10 * Move_cnt);
				x = x_bazin;
				if (goei_no == 0) {
					x = x_bazin - 10;
				}
			}
			else {              //�G�l�~�[�S�̂����ɐi��ł����ꍇ
				x_bazin = x_bazin - (10 * Move_cnt);
				x = x_bazin;
			}
			y = -15;
			Rota_angle = 0;
			goeiflg = 4;
		}
		/***���Ɉړ����I�����S�G�C����ɖ߂��Ă�����A������ɖ߂�܂ŉ��Ɉړ�������***/
		if (y <= y_bazin && goeiflg == 4) {
			y += 2;
			atkActive = false;

		}

		/******�W�O�U�O�̓���******/
		if (zigzagflg == 1) {
			x -= 1.5;
			y += 1.5f;
			zigzagcnt += 1;
		}
		if (zigzagcnt > 50) {
			zigzagflg = 2;
		}
		if (zigzagflg == 2) {
			x += 3;
			y += 1.5f;
		}
		if (zigzagcnt > 100) {
			zigzagflg = 3;
		}
		if (zigzagflg == 3) {
			x -= 1.5;
			y += 1.5f;
		}
		/**************************/
	}
}

//�`�揈��
void GOEI::Draw() {

	if (onAcitve == true) {
		int Red = GetColor(255, 0, 0);            //�Ԃ̐F
		DrawFormatString(600, 500, Red, "%d", sincount);
		DrawRotaGraph(x, y, Rota_zome, Rota_angle, gh[aniOrder], TRUE);
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

//�����𑗂鏈��
int GOEI::Send_Width() {
	return width;
}

//�����𑗂鏈��
int GOEI::Send_Height() {
	return height;
}

//onActive�𑗂鏈��
bool GOEI::Send_OnActive() {
	return onAcitve;
}