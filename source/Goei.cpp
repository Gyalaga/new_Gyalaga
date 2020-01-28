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
			Move_cnt += 1;
		}
		else {
			Move_cnt -= 1;
		}
		Overall_Move();
	}
}

	//����������
	void GOEI::Init(int ix, int iy){
		x                 = ix;		     //x���W
		y                 = iy;		     //y���W
		Rota_zome         = 2.0;         //�g�嗦
		Rota_angle        = 0;           //�`��p�x
		angle             = 75;          //angle�̏����l
		R                 = 150;         //���W�A���̏����l
		i                 = 0;           //���[�v�p
		goei_change       = 0;           //�S�G�C�̉摜��؂�ւ���
		goei_gh           = 0;           // 0;�J�r 1:�r
		width             = 18;		     //����
		height            = 18;		     //����
		FLAG_X            = 800;         //goeiflg�Ŏg���l
		FLAG_Y            = 200;         //goeiflg�Ŏg���l
		Move              = 0;           //�G�l�~�[�̈ړ����� 0:�� 1:��
		Move_cnt          = 0;
		Move_RIGHT_cnt    = -1;           //�G�l�~���\�E�ɓ�������
		Move_LEFT_cnt     = 1;           //�G�l�~���\���ɓ������� 
		Move_flg          = true;        // true:�N�� false:�Ȃ� ��x�������������������Ȃ̂ŁA1�ɂ�����߂�Ȃ�
		durability        = 1;		     //�ϋv��
		onAcitve          = true;        //��������
		atkActive         = false;       //�G�l�~�[���U�����Ă邩�ǂ����̔���
		goeiflg           = 0;           //�S�G�C�̋�����ς���t���O
								         //0:��]�ړ� 1:���i 2:��] 3:���i 4:�����Ȃ�
	}

//�I������
void GOEI::Final() {

}

//�X�V����
void GOEI::Update() {

}


void GOEI::Atacck(bool atk,int dorei,int pataan,double bazin_x,double bazin_y) {//int goei_Move,int cnt_Move

	/***�G�l�~�}�l�[�W���[����A�S�G�C�̏�Ԃ��󂯎��***/
	atkActive        = atk;         //�U���̃t���O������
	int goei_no      = dorei;       //�S�G�C�̔ԍ�
	int goei_type    = 0;           //�U���̃p�^�[��������
	
	/***�������O�Ɏ󂯎�����������W��ۑ����Ă���***/
	double x_bazin = bazin_x;    
	double y_bazin = bazin_y;

	/***�p�^�[���P�F�����ւ̓���***/
	if (atkActive == true && goei_type == 0) {

		
		/***�ŏ��̉�]***/
		if (goeiflg == 0) {
			x -= -R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y -= -R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
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
		/***�΂߂ɒ��i***/
		if (goeiflg == 1) {

			x += 2.0;//sin(PI * sincount / 80.0f) * 2.0f;
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
			x -= 1.5f; sin(PI * sincount / 100.0f) * 2.0f;
			y += 2.5f;
		}
		/***��ʊO�ɏo���S�G�C����Ƀ��[�v������***/
		if (y > 1100) {
			if (Move == 0) {
				x_bazin = x_bazin + (10 * Move_cnt);
			}
			else {
				x_bazin = x_bazin - (10 * Move_cnt);
	
			}
			x = x_bazin;
			if (goei_no == 0) {
				x = x_bazin + 10;
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

	}

     /***�p�^�[���Q�F�E���ւ̓���***/
	if (atkActive == true && goei_type == 1 ) {
		
		/***�ŏ��̉�]***/
		if (goeiflg == 0) {
			R = -150;
			x += R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y -= R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 1;
			Rota_angle += 0.04;
		}
		/***��]��������A���̍s�����ڂ��ׂɃt���O��؂�ւ���***/
		if (FLAG_Y <= y && goeiflg == 0) {
			goeiflg = 1;
			FLAG_Y = 550;
		}
		/***�΂߂ɒ��i***/
		if (goeiflg == 1) {

			x -= 2.0;
			y += 1.5f;
		}
		/***��苗���܂Œ��i������A���̍s���Ɉڂ����邽�߃t���O��؂�ւ���***/
		if (FLAG_Y <= y && goeiflg == 1) {
			goeiflg = 2;
			angle = -90;
			R = 150;
		}
		/***���i��̉�]***/
		if (goeiflg == 2) {

			x -= R * (cos((angle + 1) * (PI / -180)) - cos(angle * (PI / -180)));
			y += R * (sin((angle + 1) * (PI / -180)) - sin(angle * (PI / -180)));
			angle += 2;
			Rota_angle += 0.04;
			if (angle >= 162 && goeiflg == 2) {
				goeiflg = 3;
			}
		}
		/***�Ō�̒��i***/
		if (goeiflg == 3) {
			x += 1.5;
			y += 2.5f;	
		}
		/***��ʊO�ɏo���S�G�C����Ƀ��[�v������***/
		if (y > 1100) {
			if (Move == 0) {
				x_bazin = x_bazin + (10 * Move_cnt);
			}
			else {
				x_bazin = x_bazin - (10 * Move_cnt);

			}
			x = x_bazin;
			if (goei_no == 0) {
				x = x_bazin + 10;
			}
			y = -15;
			Rota_angle = 0;
			goeiflg = 4;
		}
		/***���Ɉړ����I�����S�G�C����ɖ߂��Ă�����A������ɖ߂�܂ŉ��Ɉړ�������***/
		if (y <= y_bazin && goeiflg == 4) {
			y += 2;

		}
		if (y == 20 && goeiflg == 3) {
			atkActive = false;

		}
	}	
}

//�`�揈��
void GOEI::Draw() {
	DrawRotaGraph(x, y, Rota_zome, Rota_angle, gh[i], TRUE);
	int Red = GetColor(255, 0, 0);            //�Ԃ̐F
	int aaa = 0;

}

void GOEI::Goei_change(int interVal) {

	goei_change = interVal;

	if (goei_change == 125) {
		i = 1;
	}
	if (goei_change == 250) {
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