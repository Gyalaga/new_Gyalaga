#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Task.h"

#define ENEMY_MOVERIGHT	10		//�E���ւ̈ړ�
#define ENEMY_MOVELEFT	-10		//�����ւ̈ړ�

//�G�̊��N���X�̐錾
class ENEMY :public TASK {
protected:
	double x, y;			//�G�̍��W
	int width, height;		//�G�̉����ƍ���
	int durability;			//�G�̑ϋv��
	int allMoveAmount;		//�ړ���
	bool atkActive;			//�G�̍U���t���O�@true:�U���� false:��A�N�e�B�u
	bool onAcitve;			//�G�������Ă邩�t���O	true:������ false:��A�N�e�B�u
public:
	virtual void Init(){}						//����������
	virtual void Final(){}						//�I������
	virtual void Update(){}						//�X�V����
	virtual void Draw(){}						//�`�揈��
	virtual void Load_Image(){}					//�摜�ǂݍ��ݏ���
	virtual void Overall_Move(){}				//�S�̋��ʂ̓���
	virtual void Load_AddMove(int addMove){}	//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
};

#endif // !_ENEMY_H_