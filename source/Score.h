#ifndef _SCORE_H_
#define _SCORE_H_
#include "Player.h"
static int score = 0;                            //スコア
static int h_score = 0;                          //ハイスコア
static char String[256];                         //保存変数
static int scorex = 950, scorey = 200;           //スコア計算の座標
static int h_scorex = 950, h_scorey = 90;        //ハイスコア計算座標        
static int count = 0;                             //点滅
static int FileHandle;                            //ファイル

void Score_Init();

//描画
void Score_Draw();
	
//保存
void Score_Save();

//タイトル画面スコア
void Score_Title();

void Score_up(int p);
#endif