#ifndef _GOEI_H_
#define _GOEI_H_

#include "Enemy.h"

//ゴエイクラスの宣言
class GOEI :public ENEMY {
private:
	int gh[5];		//画像格納変数
public:
	GOEI(int getX, int getY);			//コンストラクタ
	void Init(int ix, int iy);			//初期化処理
	void Final();						//終了処理
	void Update();						//更新処理
	void Draw();						//描画処理
	void Load_Image(int* sGh);			//画像読み込み処理
	void Overall_Move();				//全体共通の動き
	void Load_AddMove(int addMove);		//エネミー管理クラスからの読み込み
	double Send_X();					//x座標を送る処理
	double Send_Y();					//y座標を送る処理
};

#endif // !_GOEI_H_