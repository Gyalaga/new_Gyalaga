#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"

//�Q�[���Ǘ��N���X�̐錾
class CONTROL {
private:
	ENEMYMGR* enemyMgr;
public:
	CONTROL();				//�R���X�g���N�^
	~CONTROL();				//�f�X�g���N�^
	void GameControl();		//�Q�[���̑S�̊Ǘ�
};

#endif // !_CONTROL_H_