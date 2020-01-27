#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"
#include"Shot_Extern.h"
#include "Score.h"

//ゲーム管理クラスの宣言
class CONTROL {
private:
	double	ex[40];			//敵のx座標
	double	ey[40];			//敵のy座標
	int		eWidth[40];		//敵の横幅
	int		eHeight[40];	//敵の高さ
	int px;
	int py;
	int pw;
	int ph;
	int sx;
	int sy;
	int sx2;
	int sy2;
	int sw;
	int sh;
	int hf;
	bool hit;
	bool hitCheck[40];
	ENEMYMGR* enemyMgr;
public:
	CONTROL();									//コンストラクタ
	~CONTROL();									//デストラクタ
	void GameControl();
	void Hit_Judgment();						//当たり判定
};

#endif // !_CONTROL_H_