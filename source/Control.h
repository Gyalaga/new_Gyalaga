#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"

//ゲーム管理クラスの宣言
class CONTROL {
private:
	ENEMYMGR* enemyMgr;
public:
	CONTROL();				//コンストラクタ
	~CONTROL();				//デストラクタ
	void GameControl();		//ゲームの全体管理
};

#endif // !_CONTROL_H_