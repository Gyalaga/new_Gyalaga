#ifndef _ZAKO_H_
#define _ZAKO_H_

#include "Enemy.h"
#include "EnemyBullet.h"

//ザコクラスの宣言
class ZAKO :public ENEMY {
private:
	int gh[5];				//画像格納変数
	ENEMYBULLET* bullet;	//弾
	int sincount;
	double Roto_x, Roto_y;
	int angle;
	int R;
public:
	ZAKO(int getX, int getY);			//コンストラクタ
	void Init(int ix, int iy);			//初期化処理
	void Final();						//終了処理
	void Update();						//更新処理
	void Atacck(bool atk);              //敵の攻撃
	void Draw();						//描画処理
	void Load_Image(int* sGh);			//画像読み込み処理
	void Overall_Move();				//全体共通の動き
	void Load_AddMove(int addMove);		//エネミー管理クラスからの読み込み
	double Send_X();					//x座標を送る処理
	double Send_Y();					//y座標を送る処理
};

#endif // !_ZAKO_H_