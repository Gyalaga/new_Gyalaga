#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Task.h"

//敵の基底クラスの宣言
class ENEMY :public TASK {
protected:
	double x, y;			//敵の座標
	int width, height;		//敵の横幅と高さ
public:
	virtual void Init(){}		//初期化処理
	virtual void Final(){}		//終了処理
	virtual void Update(){}		//更新処理
	virtual void Draw(){}		//描画処理
	virtual void Load_Image(){}	//画像読み込み処理
};

#endif // !_ENEMY_H_