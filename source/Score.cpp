#include "DxLib.h"
#include "Score.h"

int Black = GetColor(0, 0, 0);            //黒の色
int Red = GetColor(255, 0, 0);            //赤の色
int White = GetColor(255, 255, 255);      //塗りつぶす用（白）

//更新
void Score_Update() {
	score = 0;
}

//描画
void Score_Save() {

	//ハイスコアのファイルを開く
	FileHandle = FileRead_open("h_score.dat");

	// 一行読む
	FileRead_gets(String, 256, FileHandle);

	// 画面に描画
	DrawString(h_scorex, h_scorey, String, White);

	// ファイルを閉じる
	FileRead_close(FileHandle);
}


void Score_Draw() {

	FILE* fp;

	/*//ハイスコアの記録
	fp = fopen("h_score.dat", "wb");
	fprintf(fp, "%d", h_score);

	fclose(fp);*/



	// ハイスコアの文字描画
	DrawFormatString(900, 30, Red, "HIGH ");
	DrawFormatString(950, 50, Red, " SCORE");

	//スコア文字の描画
	DrawFormatString(900, 160, Red, "1UP");

	//スコア数字の描画
	DrawFormatString(scorex, scorey, White, "%d", score);

	// ハイスコアの数字描画char型
	DrawFormatString(h_scorex, h_scorey, White, "%s", String);

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

}

void Score_Title() {

	//ハイスコアのファイルを開く
	FileHandle = FileRead_open("h_score.dat");

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