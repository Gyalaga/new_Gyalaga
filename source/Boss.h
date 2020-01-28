#ifndef _BOSS_H_
#define _BOSS_H_

#include "Enemy.h"

//ボスギャラガクラスの宣言
class BOSS :public ENEMY {
private:
	int gh[10];		//画像格納変数
public:
	BOSS(int getX, int getY);				//コンストラクタ
	void Init(int ix, int iy);				//初期化処理
	void Final();							//終了処理
	void Update();							//更新処理
	void Draw();							//描画処理
	void Load_Image(int* sGh);				//画像読み込み処理
	void Overall_Move();					//全体共通の動き
	void Load_AddMove(int addMove);			//エネミー管理クラスからの読み込み
	void Load_OnActive(bool setOnActive);	//エネミー管理クラスからの読み込み
	int Send_Width();						//横幅を送る処理
	int Send_Height();						//高さを送る処理
	double Send_X();						//x座標を送る処理
	double Send_Y();						//y座標を送る処理
};

#endif // !_BOSS_H_