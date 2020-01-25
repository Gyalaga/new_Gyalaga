#ifndef _ENEMYBULLET_H_
#define _ENEMYBULLET_H_

#include "Bullet.h"

//エネミーの弾クラスの宣言
class ENEMYBULLET :public ENEMY_BULLET {
private:
	int shot[4];		//弾の画像格納
	double ex, ey;
	bool bflg;
public:
	ENEMYBULLET();		//コンストラクタ
	void Init();		//初期化処理
	void Final();		//終了処理
	void Update();		//更新処理
	void Draw();		//描画処理
};

#endif // !_ENEMYBULLET_H_