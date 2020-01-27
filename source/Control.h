#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"

//�Q�[���Ǘ��N���X�̐錾
class CONTROL {
private:
	double	ex[40];			//�G��x���W
	double	ey[40];			//�G��y���W
	int		eWidth[40];		//�G�̉���
	int		eHeight[40];	//�G�̍���
	int px;
	int py;
	ENEMYMGR* enemyMgr;
	int flg;
public:
	CONTROL();									//�R���X�g���N�^
	~CONTROL();									//�f�X�g���N�^
	void GameControl();
	void Hit_Judgment();						//�����蔻��
};

#endif // !_CONTROL_H_