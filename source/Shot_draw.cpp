#include "DxLib.h"
#include"Shot_Extern.h"
int Shot_Check(int px,int py) {

	//�X�y�[�X�L�[�������ꂽ�Ƃ��ɒe���v���C���[�̒��S���W�ɃZ�b�g����
	if (CheckHitKey(KEY_INPUT_SPACE)) {

		//��ʏ�ɏo�ĂȂ��e�����邩�A�e�̐���������Ԃ����ׂ�
		for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) { 

			//�O�̃t���[���ŃX�y�[�X�L�[������������
			//�ۑ�����Ă���ϐ���0��������e�𔭎�
			if (bullet.sf2 == 0) { 

				//�e����ʏ�ɏo�ĂȂ��ꍇ�͂��̒e����ʂɏo��
				if (bullet.sf[bullet.bi] == 0) { 

					//�e�͑��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ���1��������
					bullet.sf[bullet.bi] = 1;

					//�e�̈ʒu�����@�̒��S�ɂ���
					bullet.sx[bullet.bi] = px;
					bullet.sy[bullet.bi] = py;
					PlaySoundFile("./res/wav/gal_se_fighter_shot.wav", DX_PLAYTYPE_BACK);
					break;//�e��1�o�����̂Ń��[�v���甲���o��
				}
			}
		}
		//�O�̃t���[���ŃV���b�g�{�^����������Ă�������
		//�ێ�����ϐ���1�i������Ă����j��������
		bullet.sf2 = 1;
	}

	/*�O�̃t���[���ŃX�y�[�X�L�[��������Ă��Ȃ������ꍇ��
	  �X�y�[�X�L�[��������Ă�������
	  �ێ�����ϐ���0�i������Ă��Ȃ��j��������*/
	else { bullet.sf2 = 0; }

	
	return 0;
}

int Shot_draw() {

	//�e�̐������e�𓮂�������
	for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {

		//�e�����݂���Ƃ��ɍs��
		if (bullet.sf[bullet.bi] == 1) {

			//�e[i]�̍��W��10�h�b�g��������
			bullet.sy[bullet.bi] -= 10;

			//��ʊO�ɏo�������݂�ێ����Ă���ϐ���0(���݂��Ȃ�)�ɂ���
			if (bullet.sy[bullet.bi] < -50) {
				bullet.sf[bullet.bi] = 0;
			}
		}
	}

	//�e�̐������`�悷��
	for (bullet.bi = 0; bullet.bi < SHOT; bullet.bi++) {
		if (bullet.sf[bullet.bi] == 1) {
			DrawRotaGraph(bullet.sx[bullet.bi], bullet.sy[bullet.bi],2,0, shot, TRUE);
		}
	}
	return 0;
}