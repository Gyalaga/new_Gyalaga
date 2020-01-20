#ifndef _BOSS_H_
#define _BOSS_H_

#include "Enemy.h"

class BOSS :public ENEMY {
private:
	int gh[10];		//画像格納変数
public:
	BOSS(int getX, int getY);		//コンストラクタ
	void Init(int ix, int iy);		//初期化処理
	void Final();					//終了処理
	void Update();					//更新処理
	void Draw();					//描画処理
	void Load_Image(int* sGh);		//画像読み込み処理
};

#endif // !_BOSS_H_