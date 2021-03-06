#ifndef _GOEI_H_
#define _GOEI_H_

#include "Enemy.h"

//ゴエイクラスの宣言
class GOEI :public ENEMY {
private:
	int gh[5];		//画像格納変数
	int sincount;                       //sinのカウント
	double Rota_zome, Rota_angle;       //拡大率と描画角度
	double angle;                          //なんかの角度
	int R;                              //ラジアン
	int goei_change;                    //ザコの画像を切り替えるよう
	int goeiflg;                        //ザコ敵の挙動を変えるフラグ
	int FLAG_X, FLAG_Y;				    //zakoflgで使う値
	int zigzagflg;                      //ジグザグのフラグ
	int zigzagcnt;                      //ジグザグのカウント
	int Move_flg;                       //エネミー全体が左右どちらに動いているかを判定
										//0:右 1:左
	int Move_cnt;                       //エネミー全体が,
										//左右にそれぞれ何回動いたかを格納

public:
	GOEI(int getX, int getY);				//コンストラクタ
	void Init(int ix, int iy);				//初期化処理
	void Final();							//終了処理
	void Update();							//更新処理
	void Draw();							//描画処理
	void Atacck(bool atk, int dorei_no, double bazin_x, double bazin_y);					//敵の攻撃
	void Load_Image(int* sGh);				//画像読み込み処理
	void Overall_Move();					//全体共通の動き
	void Load_AddMove(int addMove);			//エネミー管理クラスからの読み込み
	void Load_Damage(int damage);			//エネミー管理クラスからの読み込み
	void Load_Interval(int interval);		//エネミー管理クラスからの読み込み
	int Send_Width();						//横幅を送る処理
	int Send_Height();						//高さを送る処理
	double Send_X();						//x座標を送る処理
	double Send_Y();						//y座標を送る処理
	bool Send_OnActive();					//onActiveを送る処理
};

#endif // !_GOEI_H_