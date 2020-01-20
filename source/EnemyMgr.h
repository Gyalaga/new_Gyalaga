#ifndef _ENEMYMGR_H_
#define _ENEMYMGR_H_

#include "Task.h"
#include "Goei.h"
#include "Zako.h"

#define GOEI_START		5		//�S�G�C�̐擪�̏ꏊ
#define BOSS_START		10		//�{�X�M�����K�̐擪�̏ꏊ
#define MAX_TYPE		10		//�摜�̍ő吔
#define MIN_TYPE		4		//�摜�̍ŏ���	���g���p�ō���͎g�p�ł��Ȃ��\����...
#define GENERAL_TYPE	5		//�ő吔�ƍŏ����̊Ԃ̐�

//�G�l�~�[�Ǘ��N���X�̐錾
class ENEMYMGR :public TASK {
private:
	int baseGh[50];		//�摜�����p�ϐ�
	int zakoGh[5];		//�U�R�N���X�։摜�𑗂�p�ϐ�
	int goeiGh[5];		//�S�G�C�N���X�։摜�𑗂�p�ϐ�
	int bossGh[10];		//�{�X�M�����K�N���X�։摜�𑗂�p�ϐ�
	ZAKO* zako[20];		//�U�R�̎��̂̔z��
	GOEI* goei[16];		//�S�G�C�̎��̂̔z��
public:
	ENEMYMGR();			//�R���X�g���N�^
	~ENEMYMGR();		//�f�X�g���N�^
	void Init();		//����������
	void Final();		//�I������
	void Update();		//�X�V����
	void Draw();		//�`�揈��
};

#endif // !_ENEMYMGR_H_