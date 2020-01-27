#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"

//ゲーム管理クラスの宣言
class CONTROL {
private:
	double ex[40];
	double ey[40];
	int px;
	int py;
	ENEMYMGR* enemyMgr;
public:
	int X;
    int Y;
	CONTROL();									//コンストラクタ
	~CONTROL();									//デストラクタ
	void GameControl();
};
static int A ;//　void PlayerGet(int,int)で受け取ったPlayer.x代入
static int S; //　void PlayerGet(int,int)で受け取ったPlayer.y代入
#endif // !_CONTROL_H_