#ifndef _BOSS_H_
#define _BOSS_H_

#include "Enemy.h"

//�{�X�M�����K�N���X�̐錾
class BOSS :public ENEMY {
private:
	int gh[10];		//�摜�i�[�ϐ�
public:
	BOSS(int getX, int getY);			//�R���X�g���N�^
	void Init(int ix, int iy);			//����������
	void Final();						//�I������
	void Update();						//�X�V����
	void Draw();						//�`�揈��
	void Load_Image(int* sGh);			//�摜�ǂݍ��ݏ���
	void Overall_Move();				//�S�̋��ʂ̓���
	void Load_AddMove(int addMove);		//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	double Send_X();					//x���W�𑗂鏈��
	double Send_Y();					//y���W�𑗂鏈��
};

#endif // !_BOSS_H_