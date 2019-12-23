#include "DxLib.h"
#include "Score.h"

int Black = GetColor(0, 0, 0);            //���̐F
int Red = GetColor(255, 0, 0);            //�Ԃ̐F
int White = GetColor(255, 255, 255);      //�h��Ԃ��p�i���j

//�X�V
void Score_Update() {
	score = 0;
}

//�`��
void Score_Save() {

	//�n�C�X�R�A�̃t�@�C�����J��
	FileHandle = FileRead_open("h_score.dat");

	// ��s�ǂ�
	FileRead_gets(String, 256, FileHandle);

	// ��ʂɕ`��
	DrawString(h_scorex, h_scorey, String, White);

	// �t�@�C�������
	FileRead_close(FileHandle);
}


void Score_Draw() {

	FILE* fp;

	/*//�n�C�X�R�A�̋L�^
	fp = fopen("h_score.dat", "wb");
	fprintf(fp, "%d", h_score);

	fclose(fp);*/



	// �n�C�X�R�A�̕����`��
	DrawFormatString(900, 30, Red, "HIGH ");
	DrawFormatString(950, 50, Red, " SCORE");

	//�X�R�A�����̕`��
	DrawFormatString(900, 160, Red, "1UP");

	//�X�R�A�����̕`��
	DrawFormatString(scorex, scorey, White, "%d", score);

	// �n�C�X�R�A�̐����`��char�^
	DrawFormatString(h_scorex, h_scorey, White, "%s", String);

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

}

void Score_Title() {

	//�n�C�X�R�A�̃t�@�C�����J��
	FileHandle = FileRead_open("h_score.dat");

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