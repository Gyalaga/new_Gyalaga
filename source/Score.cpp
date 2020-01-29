#include "DxLib.h"
#include "Score.h"
#pragma warning(disable : 6387)

int Black = GetColor(0, 0, 0);            //�h��Ԃ��p�̍��̐F
int Red = GetColor(255, 0, 0);            //�Ԃ̐F
int White = GetColor(255, 255, 255);      //���̐F

//�X�R�A�̏���������
void Score_Init() {
	score = 0;
}

//�`��
void Score_Save() {
	//�n�C�X�R�A�̃t�@�C�����J��
	FileHandle = FileRead_open("res/source/high_score.dat");

	// ��ʂɕ`��
	DrawString(h_scorex, h_scorey, String, White);

	// �t�@�C�������
	FileRead_close(FileHandle);

	FILE* fp;
	errno_t error;

	// �n�C�X�R�A�̋L�^
	if ((error = fopen_s(&fp, "res/source/high_score.dat", "w")) != 0) {
		DrawFormatString(50, 50, Red, "�t�@�C���I�[�v���G���[");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "%d", h_score);

	fclose(fp);
}

void Score_Draw() {
	// �n�C�X�R�A�̕����`��
	DrawFormatString(900, 30, Red, "HIGH");
	DrawFormatString(950, 60, Red, "SCORE");

	//�X�R�A�����̕`��
	DrawFormatString(scorex, scorey, White, "%d", score);

	//char�^����int�^�ւ̕ϊ�
	h_score = atoi(String);

	//�n�C�X�R�A�X�V�A�X�R�A�A��
	if (h_score < score) {
		SetDrawScreen(DX_SCREEN_BACK);  //�h��Ԃ�                        
		DrawBox(h_scorex, h_scorey, 1000, 150, Black, TRUE);

		//�h��Ԃ���̕`��
		h_score = score;
		DrawFormatString(h_scorex, h_scorey, White, "%d", h_score);
	}

	//�_��(60��30��\���̃y�[�X)�ŃX�R�A��`��
	count = (count + 1) % 60;
	if (count < 30) {
		DrawFormatString(950, 160, Red, "1UP");
	}
	Score_up(score);
	Player.zanki = score / 2000;
	Player_Score(Player.zanki);
}

void Score_Title() {

	//�n�C�X�R�A�̃t�@�C�����J��
	FileHandle = FileRead_open("res/source/high_score.dat");

	// ��s�ǂ�
	FileRead_gets(String, 256, FileHandle);

	// ��ʂɕ`��
	DrawString(140, 90, String, White);

	// ��ʂɕ`��
	DrawString(390, 90, String, White);

	// �t�@�C�������
	FileRead_close(FileHandle);

	//�X�R�A�����̕`��
	DrawFormatString(650, 90, White, "0");

}
void Score_up(int p)
{
	score = p;
}