#ifndef _Player_h_
#define _Player_h_

#define PI 3.14    // �p�x���߂�̂Ɏg�p
/*{ ���̏��ł��K�v�ȕϐ� }**********************************************************/
typedef struct
{
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:����, height:�c��, center:���S
	int width = 32, height = 32, center = width / 2;
	//  rote:�p�x,image:�摜,hp:�̗�
	int rote = 0, image[2],  hp = 3;
	//  mode:  0_�ʏ�  ,2_�ߔ����ꂻ�� ,3_�ߔ� ,4_�j��(��\��)
	int mode = 0;
	//�f���A�����[�h�t���O
	bool dualmode = false;
	//�\���t���O
	bool flg = true;
}PLAYER;

static PLAYER Player;            // Player�̍\����
/***********************************************************************************/

/*{ Player.cpp�������Ŏg���\���� }****************************************************/
typedef struct
{
	int i = 0, j = 0;                          // i:���j�G�t�F�N�g�̑���, j:�\��
	int check = 0;
	int image[13];

	int check_left_x;                               // x���W���L�^
	int check_right_x;                              // x���W���L�^
	bool left_flg = false;
	bool right_flg = false;
}EXPLOSION; // �����p�̍\����

static EXPLOSION explosion;            // �����p�̍\����

void Player_All();       //Player�̑S�̊Ǘ�
void Player_Init();      //Player�̏������Ǘ�
void Player_Draw();      //Player�̕`��̊Ǘ�
void Player_Move();      //Player�̓����̊Ǘ�
void Player_Animation(); //Player�̃A�j���[�V�����̊Ǘ�
void Player_Shot();      //Player�̒e�̑S�̊Ǘ�
void Player_judgment();  //Player�̓����蔻��̊Ǘ�

#endif