#ifndef _BULLET_H_
#define _BULLET_H_

#include "Task.h"

//�e�N���X�̐錾
class BULLET :public TASK {
private:
	double x, y;			//���W
	int width, height;		//�����E����
	bool onActive;			//�`�悵�Ă邩���ĂȂ����̔���
public:
	virtual void Init(){}		//����������
	virtual void Final(){}		//�I������
	virtual void Update(){}		//�X�V����
	virtual void Draw(){}		//�`�揈��
};

#endif // !_BULLET_H_