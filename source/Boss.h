#ifndef _BOSS_H_
#define _BOSS_H_

#include "Enemy.h"

//�{�X�M�����K�N���X�̐錾
class BOSS :public ENEMY {
private:
	int tractorAni[29];	//�A�j���[�V����
	int gh[10];			//�摜�i�[�ϐ�
	int tGh[12];		//�g���N�^�[�r�[���̉摜�i�[
	int beamCnt;		//�g���N�^�[�r�[���p�J�E���g�ϐ�
	int beamOrder;		//�`�悷��摜�̎w��
	int bcnt;			//�g���N�^�[�r�[���A�j���[�V�����p
	bool tractorFlg;	//�g���N�^�[�r�[���p�t���O
	bool changeMode;	//���`�Ԃ��Ǘ��������
public:
	BOSS(int getX, int getY);				//�R���X�g���N�^
	void Init(int ix, int iy);				//����������
	void Final();							//�I������
	void Update();							//�X�V����
	void Draw();							//�`�揈��
	void Load_Image(int* sGh);				//�摜�ǂݍ��ݏ���
	void Overall_Move();					//�S�̋��ʂ̓���
	void Load_AddMove(int addMove);			//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	void Load_Damage(int damage);			//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	void Load_AtkActive(bool setAtkActive);	//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	void Load_Interval(int interval);		//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	void Tractor_Beam();					//�g���N�^�[�r�[���̔���
	void Tractor_Move();					//�g���N�^�[�r�[���̓���
	int Send_Width();						//�����𑗂鏈��
	int Send_Height();						//�����𑗂鏈��
	double Send_X();						//x���W�𑗂鏈��
	double Send_Y();						//y���W�𑗂鏈��
	bool Send_OnActive();					//onActive�𑗂鏈��
};

#endif // !_BOSS_H_