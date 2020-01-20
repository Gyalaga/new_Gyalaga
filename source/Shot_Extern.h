#ifndef _SHOT_EXTERN_H_
#define _SHOT_EXTERN_H_
#define SHOT 2
extern int Shot_init();
extern int Shot_draw();
extern int Shot_Check();

extern int shot;

typedef struct {
	int sx[SHOT], sy[SHOT],
		sx2[SHOT], sy2[SHOT],
		sw = 9, sh = 12;
	int sf[SHOT];
	int sf2;
} BULLET;
extern BULLET bullet;

typedef struct
{
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:����, height:�c��, center:���S
	int width = 32, height = 32, center = width / 2;
	//  rote:�p�x,image:�摜,hp:�̗�
	int rote = 0, image[2], hp = 3;
	//  mode:  0_�ʏ�  ,2_�ߔ����ꂻ�� ,3_�ߔ� ,4_�j��(��\��)
	int mode = 0;
	//�f���A�����[�h�t���O
	bool dualmode = false;
	//�\���t���O
	bool flg = true;
}PLAYER;

extern PLAYER Player;

#endif 
