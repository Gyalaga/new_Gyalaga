#include "DxLib.h"
#include"Shot_Extern.h"

int Shot_init() {
	shot = LoadGraph("./res/img/bullet.png");

	//�e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ���
	//�u���݂��Ă��Ȃ��v���Ӗ�����0�������Ă���

	for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {
		bullet.sf[bullet.bi] = 0;
	}

	//�V���b�g�{�^����O�̃t���[���ŉ����ꂽ���ǂ�����ێ�����
	//�ϐ���0�i������Ă��Ȃ��j����

	bullet.sf2 = 0;
	return 0;
}