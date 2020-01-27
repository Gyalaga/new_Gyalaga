#ifndef _ZAKO_H_
#define _ZAKO_H_

#include "Enemy.h"
#include "EnemyBullet.h"

//ザコクラスの宣言
class ZAKO :public ENEMY {
private:
	int gh[5];							//画像格納変数
	ENEMYBULLET* bullet;				//弾
	int sincount;                       //sinのカウント
	double Rota_zome, Rota_angle;       //拡大率と描画角度
	int angle;                          //なんかの角度
	int R;                              //ラジアン
	int i;                              //ザコの画像を切り替えるよう
	int zako_change;                    //ザコの画像を切り替えるよう
	int zakoflg;                        //ザコ敵の挙動を変えるフラグ
	int FLAG_X,FLAG_Y;				    //zakoflgで使う値
public:
	ZAKO(int getX, int getY);				//コンストラクタ
	void Init(int ix, int iy);				//初期化処理
	void Final();							//終了処理
	void Update();							//更新処理
	void Atacck(bool atk);					//敵の攻撃
	void Draw();							//描画処理
	void Draw_angle();						//描画の角度を変える
	void Zako_change(int interVal);			//ザコの画像を切り替える
	void Load_Image(int* sGh);				//画像読み込み処理
	void Overall_Move();					//全体共通の動き
	void Load_AddMove(int addMove);			//エネミー管理クラスからの読み込み
	void Load_OnActive(bool setOnActive);	//エネミー管理クラスからの読み込み
	int Send_Width();						//横幅を送る処理
	int Send_Height();						//高さを送る処理
	double Send_X();						//x座標を送る処理
	double Send_Y();						//y座標を送る処理
};

#endif // !_ZAKO_H_