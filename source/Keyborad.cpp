#include "DxLib.h"
#include "Keyborad.h"

//�L�[����
int Key[256];  //0:���͂���ĂȂ�
			   //1:���͂��ꂽ�u��
			   //2:���͂���Ă���
char Keyset[256];

//�L�[�̓��͏�Ԃ��X�V
void Keyborad() {

	GetHitKeyStateAll(Keyset);  // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++) {

		if (Keyset[i] != 0) { //i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[i]++;         //���Z
		}
		else {                //������Ă��Ȃ����
			Key[i] = 0;       //0�ɂ���
		}
	}
}

// KeyCode�̃L�[�̓��͏�Ԃ��擾����

int Key_get(int KeyCode) {

	return Key[KeyCode];
}
