#ifndef _BULLET_H_
#define _BULLET_H_

#include "Task.h"

//弾クラスの宣言
class BULLET :public TASK {
private:
	double x, y;			//座標
	int width, height;		//横幅・高さ
	bool onActive;			//描画してるかしてないかの判定
public:
	virtual void Init(){}		//初期化処理
	virtual void Final(){}		//終了処理
	virtual void Update(){}		//更新処理
	virtual void Draw(){}		//描画処理
};

#endif // !_BULLET_H_