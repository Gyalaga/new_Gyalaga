#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"

//�Q�[���Ǘ��N���X�̐錾
class CONTROL {
private:
	double ex[40];
	double ey[40];
	int px;
	int py;
	ENEMYMGR* enemyMgr;
public:
	int X;
    int Y;
	CONTROL();									//�R���X�g���N�^
	~CONTROL();									//�f�X�g���N�^
	void GameControl();
};
static int A ;//�@void PlayerGet(int,int)�Ŏ󂯎����Player.x���
static int S; //�@void PlayerGet(int,int)�Ŏ󂯎����Player.y���
#endif // !_CONTROL_H_