#ifndef _Player_h_
#define _Player_h_

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

//Player�̑S�̊Ǘ�
void Player_All();



#endif