#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Task.h"

#define ENEMY_MAXNUM	40		//�G�̍ő吔
#define ENEMY_ZAKONUM	20		//�U�R�̐�
#define ENEMY_GOEINUM	16		//�S�G�C�̐�
#define ENEMY_BOSSNUM	4		//�{�X�M�����K�̐�
#define ENEMY_MOVERIGHT	10		//�E���ւ̈ړ�
#define ENEMY_MOVELEFT	-10		//�����ւ̈ړ�

//�G���ʗp�\����
typedef enum {
	Enemy_Zako,		//�U�R
	Enemy_Goei,		//�S�G�C
	Enemy_Boss,		//�{�X�M�����K
}Enemy;

//�G�̊��N���X�̐錾
class ENEMY :public TASK {
protected:
	double x, y;			//�G�̍��W
	int width, height;		//�G�̉����ƍ���
	int durability;			//�G�̑ϋv��
	int allMoveAmount;		//�ړ���
	int moveAni;			//�S�̂̓������̃A�j���[�V����
	int aniOrder;			//�\������摜
	bool atkActive;			//�G�̍U���t���O�@true:�U���� false:��A�N�e�B�u
	bool onAcitve;			//�G�������Ă邩�t���O	true:������ false:��A�N�e�B�u
public:
	virtual void Init(){}								//����������
	virtual void Final(){}								//�I������
	virtual void Update(){}								//�X�V����
	virtual void Draw(){}								//�`�揈��
	virtual void Load_Image(){}							//�摜�ǂݍ��ݏ���
	virtual void Overall_Move(){}						//�S�̋��ʂ̓���
	virtual void Load_AddMove(int addMove){}			//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	virtual void Load_LoadDamage(int damege){}			//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	virtual void Load_AtkActive(bool setAtkActive){}	//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	virtual void Load_Interval(int interval){}			//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	virtual int Send_Width() = 0;						//�����𑗂鏈��
	virtual int Send_Height() = 0;						//�����𑗂鏈��
	virtual double Send_X() = 0;						//x���W�𑗂鏈��
	virtual double Send_Y() = 0;						//y���W�𑗂鏈��
	virtual bool Send_OnActive() = 0;					//onActive�𑗂鏈��
};

#endif // !_ENEMY_H_