#ifndef _GOEI_H_
#define _GOEI_H_

#include "Enemy.h"

//�S�G�C�N���X�̐錾
class GOEI :public ENEMY {
private:
	int gh[5];		//�摜�i�[�ϐ�
public:
	GOEI(int getX, int getY);			//�R���X�g���N�^
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

#endif // !_GOEI_H_