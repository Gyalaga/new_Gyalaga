#ifndef _GOEI_H_
#define _GOEI_H_

#include "Enemy.h"

//�S�G�C�N���X�̐錾
class GOEI :public ENEMY {
private:
	int gh[5];		//�摜�i�[�ϐ�
	int sincount;                       //sin�̃J�E���g
	double Rota_zome, Rota_angle;       //�g�嗦�ƕ`��p�x
	double angle;                          //�Ȃ񂩂̊p�x
	int R;                              //���W�A��
	int i;                              //�U�R�̉摜��؂�ւ���悤
	int goei_change;                    //�U�R�̉摜��؂�ւ���悤
	int goeiflg;                        //�U�R�G�̋�����ς���t���O
	int FLAG_X, FLAG_Y;				    //zakoflg�Ŏg���l
	int zigzagflg;                      //�W�O�U�O�̃t���O
	int zigzagcnt;                      //�W�O�U�O�̃J�E���g

public:
	GOEI(int getX, int getY);				//�R���X�g���N�^
	void Init(int ix, int iy);				//����������
	void Final();							//�I������
	void Update();							//�X�V����
	void Draw();							//�`�揈��
	void Atacck(bool atk);					//�G�̍U��
	void Goei_change(int interVal);			//�U�R�̉摜��؂�ւ���
	void Load_Image(int* sGh);				//�摜�ǂݍ��ݏ���
	void Overall_Move();					//�S�̋��ʂ̓���
	void Load_AddMove(int addMove);			//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	void Load_Damage(int damage);			//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	int Send_Width();						//�����𑗂鏈��
	int Send_Height();						//�����𑗂鏈��
	double Send_X();						//x���W�𑗂鏈��
	double Send_Y();						//y���W�𑗂鏈��
	bool Send_OnActive();					//onActive�𑗂鏈��
};

#endif // !_GOEI_H_