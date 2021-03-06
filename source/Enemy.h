#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Task.h"

#define ENEMY_MAXNUM	40		//敵の最大数
#define ENEMY_ZAKONUM	20		//ザコの数
#define ENEMY_GOEINUM	16		//ゴエイの数
#define ENEMY_BOSSNUM	4		//ボスギャラガの数
#define ENEMY_MOVERIGHT	10		//右側への移動
#define ENEMY_MOVELEFT	-10		//左側への移動

//敵判別用構造体
typedef enum {
	Enemy_Zako,		//ザコ
	Enemy_Goei,		//ゴエイ
	Enemy_Boss,		//ボスギャラガ
}Enemy;

//敵の基底クラスの宣言
class ENEMY :public TASK {
protected:
	double x, y;			//敵の座標
	int width, height;		//敵の横幅と高さ
	int durability;			//敵の耐久力
	int allMoveAmount;		//移動量
	int moveAni;			//全体の動き中のアニメーション
	int aniOrder;			//表示する画像
	bool atkActive;			//敵の攻撃フラグ　true:攻撃中 false:非アクティブ
	bool onAcitve;			//敵が生きてるかフラグ	true:生存中 false:非アクティブ
	bool Yes_Acitve;
public:
	virtual void Init(){}								//初期化処理
	virtual void Final(){}								//終了処理
	virtual void Update(){}								//更新処理
	virtual void Draw(){}								//描画処理
	virtual void Load_Image(){}							//画像読み込み処理
	virtual void Overall_Move(){}						//全体共通の動き
	virtual void Load_AddMove(int addMove){}			//エネミー管理クラスからの読み込み
	virtual void Load_LoadDamage(int damege){}			//エネミー管理クラスからの読み込み
	virtual void Load_AtkActive(bool setAtkActive){}	//エネミー管理クラスからの読み込み
	virtual void Load_Interval(int interval){}			//エネミー管理クラスからの読み込み
	virtual int Send_Width() = 0;						//横幅を送る処理
	virtual int Send_Height() = 0;						//高さを送る処理
	virtual double Send_X() = 0;						//x座標を送る処理
	virtual double Send_Y() = 0;						//y座標を送る処理
	virtual bool Send_OnActive() = 0;					//onActiveを送る処理
};

#endif // !_ENEMY_H_