#ifndef _BOSS_H_
#define _BOSS_H_

#include "Enemy.h"

class BOSS :public ENEMY {
private:
	int gh[10];		//�摜�i�[�ϐ�
public:
	BOSS(int getX, int getY);		//�R���X�g���N�^
	void Init(int ix, int iy);		//����������
	void Final();					//�I������
	void Update();					//�X�V����
	void Draw();					//�`�揈��
	void Load_Image(int* sGh);		//�摜�ǂݍ��ݏ���
};

#endif // !_BOSS_H_