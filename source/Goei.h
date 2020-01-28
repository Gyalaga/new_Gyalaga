#ifndef _GOEI_H_
#define _GOEI_H_

#include "Enemy.h"

//�S�G�C�N���X�̐錾
class GOEI :public ENEMY {
private:
	int gh[5];		                    //�摜�i�[�ϐ�
	int sincount;                       //sin�̃J�E���g
	double Rota_zome, Rota_angle;       //�g�嗦�ƕ`��p�x
	double angle;                       //�Ȃ񂩂̊p�x
	int R;                              //���W�A��
	int i;                              //���[�v�p
	int xx;
	int goei_gh;                        //�S�G�C�̉摜��؂�ւ���悤
	int goei_change;                    //�S�G�C�̉摜��ry
	int goeiflg;                        //�S�G�C�̋�����ς���t���O
	int FLAG_X, FLAG_Y;				    //zakoflg�Ŏg���l
	double Move;                        //�G�l�~�[�̈ړ����� 0;�� 1:��
	double Move_cnt;
	double Move_RIGHT_cnt;              //�G�l�~�[���E�Ɉړ�������
	double Move_LEFT_cnt;               //�G�l�~�[�����Ɉړ�������
	bool   Move_flg;                    //�ŏ��̈�x�����l���炵������ł���B�͂��B�����L�B�B�B


	double goei_dotei[16];              //�S�G�C�̏������W���i�[    
public:
	GOEI(int getX, int getY);			//�R���X�g���N�^
	void Init(int ix, int iy);			//����������
	void Final();						//�I������
	void Update();						//�X�V����
	void Draw();						//�`�揈��
	void Atacck(bool atk,int dorei,int pataan,double bazin_x,double bazin_y);              //�G�̍U��
	void Goei_change(int interVal);     //�U�R�̉摜��؂�ւ���
	void Load_Image(int* sGh);			//�摜�ǂݍ��ݏ���
	void Overall_Move();				//�S�̋��ʂ̓���
	void Load_AddMove(int addMove);		//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	double Send_X();					//x���W�𑗂鏈��
	double Send_Y();					//y���W�𑗂鏈��
};

#endif // !_GOEI_H_