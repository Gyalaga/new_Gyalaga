#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"

//ゲーム管理クラスの宣言
class CONTROL {
private:
	ENEMYMGR* enemyMgr;
public:
	int X;
    int Y;
	CONTROL();									//コンストラクタ
	~CONTROL();									//デストラクタ
	void GameControl();
	void PlayerGet(int,int);	//ゲームの全体管理
};
static int A ;//　void PlayerGet(int,int)で受け取ったPlayer.x代入
static int S; //　void PlayerGet(int,int)で受け取ったPlayer.y代入
#endif // !_CONTROL_H_