#ifndef _ZAKO_H_
#define _ZAKO_H_

#include "Enemy.h"
#include "EnemyBullet.h"

//�U�R�N���X�̐錾
class ZAKO :public ENEMY {
private:
	int gh[5];							//�摜�i�[�ϐ�
	ENEMYBULLET* bullet;				//�e
	int sincount;                       //sin�̃J�E���g
	double Rota_zome, Rota_angle;       //�g�嗦�ƕ`��p�x
	int angle;                          //�Ȃ񂩂̊p�x
	int R;                              //���W�A��
	int i;                              //�U�R�̉摜��؂�ւ���悤
	int zako_change;                    //�U�R�̉摜��؂�ւ���悤
	int zakoflg;                        //�U�R�G�̋�����ς���t���O
	int FLAG_X,FLAG_Y;				    //zakoflg�Ŏg���l
public:
	ZAKO(int getX, int getY);				//�R���X�g���N�^
	void Init(int ix, int iy);				//����������
	void Final();							//�I������
	void Update();							//�X�V����
	void Atacck(bool atk);					//�G�̍U��
	void Draw();							//�`�揈��
	void Draw_angle();						//�`��̊p�x��ς���
	void Zako_change(int interVal);			//�U�R�̉摜��؂�ւ���
	void Load_Image(int* sGh);				//�摜�ǂݍ��ݏ���
	void Overall_Move();					//�S�̋��ʂ̓���
	void Load_AddMove(int addMove);			//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	void Load_OnActive(bool setOnActive);	//�G�l�~�[�Ǘ��N���X����̓ǂݍ���
	int Send_Width();						//�����𑗂鏈��
	int Send_Height();						//�����𑗂鏈��
	double Send_X();						//x���W�𑗂鏈��
	double Send_Y();						//y���W�𑗂鏈��
};

#endif // !_ZAKO_H_