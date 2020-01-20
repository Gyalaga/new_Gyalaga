#ifndef _Player_h_
#define _Player_h_

#define PI 3.14    // �p�x���߂�̂Ɏg�p
/*{ ���̏��ł��K�v�ȕϐ� }**********************************************************/
typedef struct
{
	//x,y���W�z��
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:����, height:�c��, center:���S
	int width = 32, height = 32, center = width / 2;
	//  rote:�p�x,image:�摜,hp:�̗�
	int L_rote = 0,R_rote=0, image[2],  hp = 3;
	//  mode:  0_�ʏ�  ,2_�ߔ����ꂻ�� ,3_�ߔ� ,4_�j��(��\��)
	int mode = 0;
	//�f���A�����[�h�t���O
	bool dualmode = false;

	//�\���t���O
	bool  left_flg[16] = { false,false,false,false,false,false,false,false,
						   false,false,false,false,false,false,false,false };
	bool right_flg[16] = { false,false,false,false,false,false,false,false,
						   false,false,false,false,false,false,false,false };

}PLAYER;

 PLAYER Player;    // Player�̍\����
/*************************************************************************************/

/*{ Player.cpp�������Ŏg���\���� }****************************************************/
typedef struct
{
	int i = 0, j = 0;          //���̎��@�� i:�A�j���[�V�����̑���, j:�\��
	int n = 0, c = 0;          //�E�̎��@�� n:�A�j���[�V�����̑���, c:�\��

	int image[13];             //�摜�̔z��

	int check_left_x;          //����x���W���L�^
	int check_right_x;         //�E��x���W���L�^
	bool L = false;            //����x���W���L�^����̂Ɏg���t���O
	bool R = false;            //�E��x���W���L�^����̂Ɏg���t���O
	bool left_flg = false;     //���̃A�j���[�V�������s�p�̃t���O
	bool right_flg = false;    //�E�̃A�j���[�V�������s�p�̃t���O
}EXPLOSION; //�����p�̍\����

typedef struct
{
	int i = 0, j = 0;          // i:�A�j���[�V�����̑���, j:�\��

	int check_left_x;          // x���W���L�^
	int check_right_x;         // x���W���L�^

	bool left_flg = false;     //���̃A�j���[�V�������s�p�̃t���O
	bool right_flg = false;    //�E�̃A�j���[�V�������s�p�̃t���O
	bool check_flg[5] = { false,false,false,false,false}; //�G�̍��W�ɍ��킹��t���O�z��
}TRACTOR;   //�߂܂�Ƃ��̃A�j���[�V�����p�̍\����

typedef struct
{
	bool c = false;            //�����p�Ɏg���p�̕ϐ�
	bool flg_L = false;        //���̏����p�Ɏg���p�̕ϐ�
	bool flg_R = false;        //�E�̏����p�Ɏg���p�̕ϐ�
	bool flg = false;          //�A�j���[�V�������s�p�̃t���O
	bool ani_flg[2] = { false,false};  //�G�̍��W�ɍ��킹��t���O�z��
}DUAL;      //�f���A���A�j���[�V�����p�̍\����

static DUAL dual;              // �����p�̍\����
static EXPLOSION explosion;    // �����p�̍\����
static TRACTOR tractor;        //�f���A���A�j���[�V�����p�̍\����

void Player_All();             //Player�̑S�̊Ǘ�
void Player_Init();            //Player�̏������Ǘ�
void Player_Draw();            //Player�̕`��̊Ǘ�
void Player_Move();            //Player�̓����̊Ǘ�
void Player_Animation();       //Player�̃A�j���[�V�����̊Ǘ�
void Player_Shot();            //Player�̒e�̑S�̊Ǘ�
void Player_judgment();        //Player�̓����蔻��̊Ǘ�

void Player_int();             //Player�̕ϐ��m�F

#endif