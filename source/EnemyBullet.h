#ifndef _ENEMYBULLET_H_
#define _ENEMYBULLET_H_

#include "Bullet.h"

//�G�l�~�[�̒e�N���X�̐錾
class ENEMYBULLET :public ENEMY_BULLET {
private:
	int shot[4];		//�e�̉摜�i�[
	double ex, ey;
	bool bflg;
public:
	ENEMYBULLET();		//�R���X�g���N�^
	void Init();		//����������
	void Final();		//�I������
	void Update();		//�X�V����
	void Draw();		//�`�揈��
};

#endif // !_ENEMYBULLET_H_