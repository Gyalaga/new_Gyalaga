#ifndef _ENEMYMGR_H_
#define _ENEMYMGR_H_

#include "Task.h"
#include "Boss.h"
#include "Goei.h"
#include "Zako.h"

#define GOEI_START		5		//�S�G�C�̐擪�̏ꏊ
#define BOSS_START		10		//�{�X�M�����K�̐擪�̏ꏊ
#define MAX_TYPE		10		//�摜�̍ő吔
#define MIN_TYPE		4		//�摜�̍ŏ���	���g���p�ō���͎g�p�ł��Ȃ��\����...
#define GENERAL_TYPE	5		//�ő吔�ƍŏ����̊Ԃ̐�
#define GOEI_ORDER		20		//�S�G�C�̏���
#define BOSS_ORDER		36		//�{�X�M�����K�̏���

//�G�l�~�[�Ǘ��N���X�̐錾
class ENEMYMGR :public TASK {
private:
	int baseGh[50];		//�摜�����p�ϐ�
	int zakoGh[5];		//�U�R�N���X�։摜�𑗂�p�ϐ�
	int goeiGh[5];		//�S�G�C�N���X�։摜�𑗂�p�ϐ�
	int bossGh[10];		//�{�X�M�����K�N���X�։摜�𑗂�p�ϐ�
	int enemyAllMove;	//�G�l�~�[�S�̂̈ړ��p�ϐ�
	int enemy_GO;       //�G�l�~�[���i��ł�������𔻒� 0;�� 1:��
	double Move_cnt;       //�G�l�~�[�����E�ɐi�񂾉񐔂��L�^
	int enemyAll;		//�e�G�ɑ���p�ϐ�
	int intervalCnt;	//�S�̂œ����Ԋu�J�E���g
	int dbl_flg;        //�G�̃_�u���`�F�b�N�Ŏg��
	bool goei_flg;      //�����S�G�C��ς���          
	double enemyX[40];	//�G��X���W���擾
	double enemyY[40];	//�G��Y���W���擾
	double goei_bazin_x[16]; //�S�G�C�̏���x���W��ۑ�
	double goei_bazin_y[16]; //�S�G�C�̏���y���W��ۑ�
	int sincount;       //sin�����̃J�E���g
	bool atkActive;     //�G�l�~�[�̍U���t���O
	int goei_pataan;    //�S�G�C�̍U���p�^�[��
	int goei_no;        //�������S�G�C�̔ԍ�
	ZAKO* zako[20];		//�U�R�̎��̂̔z��
	GOEI* goei[16];		//�S�G�C�̎��̂̔z��
	BOSS* boss[4];		//�{�X�M�����K�̎��̂̔z��
public:
	ENEMYMGR();											//�R���X�g���N�^
	~ENEMYMGR();										//�f�X�g���N�^
	void Init();										//����������
	void Final();										//�I������
	void Update();										//�X�V����
	void Draw();										//�`�揈��
	void Send_Coordinate(double* setX, double* setY);	//�擾�����|�C���^�Ƀ|�C���^��������
};

#endif // !_ENEMYMGR_H_