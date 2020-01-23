#ifndef _ZAKO_H_
#define _ZAKO_H_

#include "Enemy.h"

//�U�R�N���X�̐錾
class ZAKO :public ENEMY {
private:
	int gh[5];		//�摜�i�[�ϐ�
public:
	ZAKO(int getX, int getY);			//�R���X�g���N�^
	void Init(int ix, int iy);			//����������
	void Final();						//�I������
	void Update();						//�X�V����
	void Draw();						//�`�揈��
	void Load_Image(int* sGh);			//�摜�ǂݍ��ݏ���
	void Overall_Move();				//�S�̋��ʂ̓���
	void Load_AddMove(int addMove);		//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
};

#endif // !_ZAKO_H_