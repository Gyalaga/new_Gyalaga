#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"

//ゲーム管理クラスの宣言
class CONTROL {
private:
	double	ex[40];			//敵のx座標
	double	ey[40];			//敵のy座標
	int		eWidth[40];		//敵の横幅
	int		eHeight[40];	//敵の高さ
	int px;
	int py;
	ENEMYMGR* enemyMgr;
	int flg;
public:
	CONTROL();									//コンストラクタ
	~CONTROL();									//デストラクタ
	void GameControl();
	void Hit_Judgment();						//当たり判定
};

#endif // !_CONTROL_H_