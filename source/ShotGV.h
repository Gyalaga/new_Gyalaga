//�O���[�o���ϐ��Ƃ��Ă̐錾
#ifndef _SHOTGV_H_
#define _SHOTGV_H_

#define SHOT 2 //�e�̍ő吔
int Shot_init(); //�e�̏���������
int Shot_draw(); //�e�̕`�揈��
int Shot_Check(int,int); //�X�y�[�X�������ꂽ���̏���

int shot; //�e�̉摜�p�ϐ�

//�e�̍\����
typedef struct {
	int sx[SHOT], sy[SHOT],
		sx2[SHOT], sy2[SHOT],
		sw = 6, sh = 16;
	int sf[SHOT];
	int sf2;
	int bi = 0;
} BULLET;

 BULLET bullet;



#endif 

