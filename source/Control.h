#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "EnemyMgr.h"
#include "Player.h"
#include"Shot_Extern.h"
#include "Score.h"
#include "Task.h"

//ゲーム管理クラスの宣言
class CONTROL :public TASK {
private:
	double	ex[40];			//敵のx座標
	double	ey[40];			//敵のy座標
	int		eWidth[40];		//敵の横幅
	int		eHeight[40];	//敵の高さ
	int		damage;			//ダメージ量
	int		gameEndCnt;		//クリア判定処理
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
	int wavflg;
	int wavcnt;
	bool No[4];
	bool hitCheck[40];		//当たり判定の処理をするかどうかの判定用
	bool gameEnd;			//ゲームを終了するか判定
	ENEMYMGR* enemyMgr;		//エネミー管理クラスの実体
public:
	CONTROL();									//コンストラクタ
	~CONTROL();									//デストラクタ
	void Init();								//初期化処理
	void Final();								//終了処理
	void Update(){}								//更新処理
	void Draw(){}								//描画処理
	void GameControl();							//ゲームの全体管理
	void Hit_Judgment();						//当たり判定
	bool GameEnd_Judgment();					//ゲーム終了かをゲームクラスに送る
};

#endif // !_CONTROL_H_