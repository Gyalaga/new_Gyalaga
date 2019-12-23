#ifndef _Player_h_
#define _Player_h_
/*{ ���̏��ł��K�v�ȕϐ� }**********************************************************/
typedef struct
{
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:����, height:�c��, center:���S
	int width = 32, height = 32, center = width / 2;
	//  mode:  0_�ʏ� ,1_�ߔ� ,2_�f���A�����[�h
	int mode = 0;
	//�\���t���O
	bool flg = false;
}PLAYER;

static PLAYER Player;            // Player�̍\����
/***********************************************************************************/

/*{ Player.cpp�������Ŏg���ϐ� }****************************************************/
typedef struct
{

}Animation;

static Animation ani;            // Player_Animation�̍\����

void Player_All();       //Player�̑S�̊Ǘ�
void Player_Init();      //Player�̏������Ǘ�
void Player_Draw();      //Player�̕`��̊Ǘ�
void Player_Move();      //Player�̓����̊Ǘ�
void Player_Animation(); //Player�̃A�j���[�V�����̊Ǘ�
void Player_Shot();      //Player�̒e�̑S�̊Ǘ�
void Player_judgment();  //Player�̓����蔻��̊Ǘ�

#endif