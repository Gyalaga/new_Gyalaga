#ifndef _GOEI_H_
#define _GOEI_H_

#include "Enemy.h"

//ゴエイクラスの宣言
class GOEI :public ENEMY {
private:
	int gh[5];		                    //画像格納変数
	int sincount;                       //sinのカウント
	double Rota_zome, Rota_angle;       //拡大率と描画角度
	double angle;                       //なんかの角度
	int R;                              //ラジアン
	int i;                              //ループ用
	int xx;
	int goei_gh;                        //ゴエイの画像を切り替えるよう
	int goei_change;                    //ゴエイの画像をry
	int goeiflg;                        //ゴエイの挙動を変えるフラグ
	int FLAG_X, FLAG_Y;				    //zakoflgで使う値
	double Move;                        //エネミーの移動方向 0;→ 1:←
	double Move_cnt;
	double Move_RIGHT_cnt;              //エネミーが右に移動した回数
	double Move_LEFT_cnt;               //エネミーが左に移動した回数
	bool   Move_flg;                    //最初の一度だけ値ずらしたいんですよ。はい。モンキィィィ


	double goei_dotei[16];              //ゴエイの初期座標を格納    
public:
	GOEI(int getX, int getY);			//コンストラクタ
	void Init(int ix, int iy);			//初期化処理
	void Final();						//終了処理
	void Update();						//更新処理
	void Draw();						//描画処理
	void Atacck(bool atk,int dorei,int pataan,double bazin_x,double bazin_y);              //敵の攻撃
	void Goei_change(int interVal);     //ザコの画像を切り替える
	void Load_Image(int* sGh);			//画像読み込み処理
	void Overall_Move();				//全体共通の動き
	void Load_AddMove(int addMove);		//エネミー管理クラスからの読み込み
	double Send_X();					//x座標を送る処理
	double Send_Y();					//y座標を送る処理
};

#endif // !_GOEI_H_