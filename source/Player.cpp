#include "DxLib.h"
#include "Player.h"
#include "Keyborad.h"

int i = 0;

void Player_All() //�S��
{
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Player_All������");
	Player_Init();//������
	Player_Draw();//�`��
	Player_Move();//����

}

void Player_Init()
{
	LoadDivGraph("./res/img/���@.png", 2, 1, 2, 16, 16, Player.image);  // ���@�摜�̕����ǂݍ���
}

void Player_Draw()//�`��
{
	if (Player.flg == true)DrawRotaGraph(Player.x[i], Player.y[i], 2, PI / 180 * Player.rote, Player.image[0], TRUE);
}
void Player_Move()//����
{
	DrawFormatString(250, 100, GetColor(255, 255, 255), "%d", Player.x[i]);  // ������`�悷��

	if (Player.mode == 0 || Player.mode == 1)//�ʏ펞,�f���A�����[�h��
	{
		// �E�������Ă�����E�ɐi��
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.x[i] + Player.center <= 798) Player.x[i] += 3;

		// ���������Ă����獶�ɐi��
		if (CheckHitKey(KEY_INPUT_LEFT) && Player.x[i] - Player.center >= 2)   Player.x[i] -= 3;

		//�X�y�[�X�����Ă�����e����
		if (CheckHitKey(KEY_INPUT_SPACE));

	}
	if (Player.mode == 2)//�ߔ����ꂻ���Ȏ�
	{
		if (CheckHitKey(KEY_INPUT_SPACE));
	}
	if (Player.mode == 3 || Player.mode == 4)//�ߔ���,�j��(��\��)��
	{

	}
}//Player_Move()�I��