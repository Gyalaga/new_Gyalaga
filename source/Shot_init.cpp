#include "DxLib.h"
#include"Shot_Extern.h"

int Shot_init() {
	int i;
	shot = LoadGraph("bullet.png");

	//�e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ���
	//�u���݂��Ă��Ȃ��v���Ӗ�����0�������Ă���

	for (i = 0; i < SHOT; i++) {
		bullet.sf[i] = 0;
	}

	//�V���b�g�{�^����O�̃t���[���ŉ����ꂽ���ǂ�����ێ�����
	//�ϐ���0�i������Ă��Ȃ��j����

	bullet.sf2 = 0;
	return 0;
}