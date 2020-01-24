#ifndef _PLAYERBULLET_H_
#define _PLAYERBULLET_H_

#include "Bullet.h"

//プレイヤーの弾クラスの宣言
class PLAYERBULLET :public BULLET {
public:
	PLAYERBULLET();		//コンストラクタ
	void Init();		//初期化処理
	void Final();		//終了処理
	void Update();		//更新処理
	void Draw();		//描画処理
};

#endif // !_PLAYERBULLET_H_