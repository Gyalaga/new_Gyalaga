#include "DxLib.h"
#include "Player.h"
#include "Keyborad.h"

int i = 0;
bool init = false;
void Player_All() //�S��
{
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Player_All������");
	if (init == false)
	{
		Player_Init();//������
		init = true;
	}

	Player_Draw();//�`��
	Player_Move();//����
	Player_Animation();//�A�j���[�V����
	Player_judgment();//�����蔻��
}

void Player_Init()//������
{
	LoadDivGraph("./res/img/���@.png", 2, 1, 2, 16, 16, Player.image);  // ���@�摜�̕����ǂݍ���
	LoadDivGraph("./res/img/bakuhatu.png", 9, 9, 1, 32, 32, explosion.image);              // ���j�摜�̕���
}

void Player_Draw()//�`��
{
	if (Player.flg == true)DrawRotaGraph(Player.x[i], Player.y[i], 2, PI / 180 * Player.rote, Player.image[0], TRUE);
}
void Player_Move()//����
{
	DrawFormatString(250, 100, GetColor(255, 255, 255), "%d", Player.x[i]);  // ������`�悷��

	if (Player.mode == 0 || Player.dualmode == true)//�ʏ펞,�f���A�����[�h��
	{
		// �E�������Ă�����E�ɐi��
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.x[i] + Player.center <= 798) Player.x[i] += 3;

		// ���������Ă����獶�ɐi��
		if (CheckHitKey(KEY_INPUT_LEFT) && Player.x[i] - Player.center >= 2)   Player.x[i] -= 3;

		//�X�y�[�X�����Ă�����e����
		if (CheckHitKey(KEY_INPUT_SPACE))explosion.left_flg = true;

	}
	if (Player.mode == 2)//�ߔ����ꂻ���Ȏ�
	{
		if (CheckHitKey(KEY_INPUT_SPACE));
	}
	if (Player.mode == 3 || Player.mode == 4)//�ߔ���,�j��(��\��)��
	{

	}
}//Player_Move()�I��

void Player_Animation()//�A�j���[�V����
{
	//���Ă��ꂽ��
		if (Player.dualmode == false)
		{
			if (explosion.left_flg == true)
			{
				if (explosion.check == 0)
				{
					explosion.check_left_x = Player.x[i];
					explosion.check = 1;
				}
				Player.mode = 4;      //���͋��� 
				explosion.i++;              //���j�A�j���[�V�����J�n
				if (explosion.i == 10)
				{
					explosion.j += 1;
					explosion.i = 0;     //���@�̔��j�G�t�F�N�g�X�s�[�h��������Ȃ�if�̏�����ς���
				}
				DrawRotaGraph(explosion.check_left_x, Player.y[i], 2, PI / 180 * 0, explosion.image[explosion.j], TRUE);    //���j�摜�\��
			}
			if (explosion.j == 8)          //���j�A�j���[�V�������I������烊�Z�b�g����
			{
				explosion.i += 1; Player.mode = 0; Player.hp -= 1;
				explosion.i = 0;  explosion.j = 0; explosion.left_flg=false;
				explosion.check = 0;
			}
		}
		else
		{

		}

	//�z�����܂ꎞ
	//	Player.mode = 2;      //�z�����܂ꂻ��
	//	Player.rote += 18;    //��]������
}//Player_Animation()�I��

void Player_judgment()//�����蔻��
{
	//Control.cpp����l�����Ă���
	//1:�G�ɕ��ʂɂ�����, 2:�G�̒e�ɓ�����,3:�g���N�^�[�r�[��
	/*
	if(1||2)
	{
	   explosion.left_flg = true;
	}


	if(3)
	{

	}
	*/
}//Player_judgment()�I��