#ifndef _PLAYERBULLET_H_
#define _PLAYERBULLET_H_

#include "Bullet.h"

//�v���C���[�̒e�N���X�̐錾
class PLAYERBULLET :public BULLET {
public:
	PLAYERBULLET();		//�R���X�g���N�^
	void Init();		//����������
	void Final();		//�I������
	void Update();		//�X�V����
	void Draw();		//�`�揈��
};

#endif // !_PLAYERBULLET_H_