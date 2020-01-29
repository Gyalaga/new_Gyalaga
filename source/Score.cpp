#include "DxLib.h"
#include "Score.h"
#pragma warning(disable : 6387)

int Black = GetColor(0, 0, 0);            //塗りつぶす用の黒の色
int Red = GetColor(255, 0, 0);            //赤の色
int White = GetColor(255, 255, 255);      //白の色

//スコアの初期化処理
void Score_Init() {
	score = 0;
}

//描画
void Score_Save() {
	//ハイスコアのファイルを開く
	FileHandle = FileRead_open("res/source/high_score.dat");

	// 画面に描画
	DrawString(h_scorex, h_scorey, String, White);

	// ファイルを閉じる
	FileRead_close(FileHandle);

	FILE* fp;
	errno_t error;

	// ハイスコアの記録
	if ((error = fopen_s(&fp, "res/source/high_score.dat", "w")) != 0) {
		DrawFormatString(50, 50, Red, "ファイルオープンエラー");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "%d", h_score);

	fclose(fp);
}

void Score_Draw() {
	// ハイスコアの文字描画
	DrawFormatString(900, 30, Red, "HIGH");
	DrawFormatString(950, 60, Red, "SCORE");

	//スコア数字の描画
	DrawFormatString(scorex, scorey, White, "%d", score);

	//char型からint型への変換
	h_score = atoi(String);

	//ハイスコア更新、スコア連動
	if (h_score < score) {
		SetDrawScreen(DX_SCREEN_BACK);  //塗りつぶし                        
		DrawBox(h_scorex, h_scorey, 1000, 150, Black, TRUE);

		//塗りつぶし後の描画
		h_score = score;
		DrawFormatString(h_scorex, h_scorey, White, "%d", h_score);
	}

	//点滅(60回中30回表示のペース)でスコアを描画
	count = (count + 1) % 60;
	if (count < 30) {
		DrawFormatString(950, 160, Red, "1UP");
	}
	Score_up(score);
	Player.zanki = score / 2000;
	Player_Score(Player.zanki);
}

void Score_Title() {

	//ハイスコアのファイルを開く
	FileHandle = FileRead_open("res/source/high_score.dat");

	// 一行読む
	FileRead_gets(String, 256, FileHandle);

	// 画面に描画
	DrawString(140, 90, String, White);

	// 画面に描画
	DrawString(390, 90, String, White);

	// ファイルを閉じる
	FileRead_close(FileHandle);

	//スコア数字の描画
	DrawFormatString(650, 90, White, "0");

}
void Score_up(int p)
{
	score = p;
}