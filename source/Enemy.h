#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Task.h"

//�G�̊��N���X�̐錾
class ENEMY :public TASK {
protected:
	double x, y;			//�G�̍��W
	int width, height;		//�G�̉����ƍ���
public:
	virtual void Init(){}		//����������
	virtual void Final(){}		//�I������
	virtual void Update(){}		//�X�V����
	virtual void Draw(){}		//�`�揈��
	virtual void Load_Image(){}	//�摜�ǂݍ��ݏ���
};

#endif // !_ENEMY_H_