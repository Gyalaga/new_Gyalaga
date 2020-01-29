#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"
#include"Shot_Extern.h"
#include "Score.h"
#include "Task.h"

//�Q�[���Ǘ��N���X�̐錾
class CONTROL :public TASK {
private:
	double	ex[40];			//�G��x���W
	double	ey[40];			//�G��y���W
	int		eWidth[40];		//�G�̉���
	int		eHeight[40];	//�G�̍���
	int		damage;			//�_���[�W��
	int		gameEndCnt;		//�N���A���菈��
	int px;
	int py;
	int pw;
	int ph;
	int sx;
	int sy;
	int sx2;
	int sy2;
	int sw;
	int sh;
	int hf;
	int wavflg;
	int wavcnt;
	bool No[4];
	bool hitCheck[40];		//�����蔻��̏��������邩�ǂ����̔���p
	bool gameEnd;			//�Q�[�����I�����邩����
	ENEMYMGR* enemyMgr;		//�G�l�~�[�Ǘ��N���X�̎���
public:
	CONTROL();									//�R���X�g���N�^
	~CONTROL();									//�f�X�g���N�^
	void Init();								//����������
	void Final();								//�I������
	void Update(){}								//�X�V����
	void Draw(){}								//�`�揈��
	void GameControl();							//�Q�[���̑S�̊Ǘ�
	void Hit_Judgment();						//�����蔻��
	bool GameEnd_Judgment();					//�Q�[���I�������Q�[���N���X�ɑ���
};

#endif // !_CONTROL_H_