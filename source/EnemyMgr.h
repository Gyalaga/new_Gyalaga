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
#define INTERVAL_MIDDLE	125		//�Ԋu�̒���
#define INTERVAL_RESET	250		//�Ԋu�̏I�_
#define GOEI_NUM        15;     //�S�G�C�̐�
#define GOEI_P           1;     //�S�G�C�̎��

//�G�l�~�[�Ǘ��N���X�̐錾
class ENEMYMGR :public TASK {
private:
	int baseGh[50];		    //�摜�����p�ϐ�
	int zakoGh[5];		    //�U�R�N���X�։摜�𑗂�p�ϐ�
	int goeiGh[5];		    //�S�G�C�N���X�։摜�𑗂�p�ϐ�
	int bossGh[10];		    //�{�X�M�����K�N���X�։摜�𑗂�p�ϐ�
	int enemyAllMove;	    //�G�l�~�[�S�̂̈ړ��p�ϐ�
	int enemyAll;		    //�e�G�ɑ���p�ϐ�
	int intervalCnt;	    //�S�̂œ����Ԋu�J�E���g
	int width[40];		    //�G�̉������擾
	int height[40];		    //�G�̍������擾
	int sincount;           //sin�����̃J�E���g
	int goei_no;            //�S�G�C�̔ԍ����i�[
	int boss_rand;			//�{�X�M�����K�̍U������p
	int tmpBoss_rand;		//boss_rand���ꎞ�I�Ɋi�[�p
	double enemyX[40];	    //�G��X���W���擾
	double enemyY[40];	    //�G��Y���W���擾
	double goei_bazin_x[16];//�S�G�C�̏���x���W���i�[
	double goei_bazin_y[16];//�S�G�C�̏���y���W���i�[
	bool atkActive;         //�G�l�~�[���U�����Ă邩�ǂ��� true:�U�� false:���ĂȂ�
	bool Yes[4];            //biimflg
	Enemy enemy_type;	    //�G�l�~�[�\���̂̎���
	ZAKO* zako[20];		    //�U�R�̎��̂̔z��
	GOEI* goei[16];		    //�S�G�C�̎��̂̔z��
	BOSS* boss[4];		    //�{�X�M�����K�̎��̂̔z��
public:
	ENEMYMGR();																			//�R���X�g���N�^
	~ENEMYMGR();																		//�f�X�g���N�^
	void Init();																		//����������
	void Final();																		//�I������
	void Update();																		//�X�V����
	void Draw();																		//�`�揈��
	void Send_Coordinate(double* setX, double* setY, int* setWidth, int* setHeight);	//�擾�����|�C���^�Ƀ|�C���^��������
	void Hit_ChangeOnActive(int getDamage, int n);										//Hit�����G��onActive��false�ɂ���
	void Judgment_OnActive(bool* setHitCheck);
	void Yes_Judgment(bool* flg);
	void All();																			//�G�l�~�[�Ǘ��N���X�S�̂��Ǘ�
};

#endif // !_ENEMYMGR_H_