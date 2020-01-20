#ifndef _ENEMYMGR_H_
#define _ENEMYMGR_H_

#include "Task.h"
#include "Goei.h"
#include "Zako.h"

#define GOEI_START		5		//ゴエイの先頭の場所
#define BOSS_START		10		//ボスギャラガの先頭の場所
#define MAX_TYPE		10		//画像の最大数
#define MIN_TYPE		4		//画像の最小数	※拡張用で今回は使用できない可能性が...
#define GENERAL_TYPE	5		//最大数と最小数の間の数

//エネミー管理クラスの宣言
class ENEMYMGR :public TASK {
private:
	int baseGh[50];		//画像分割用変数
	int zakoGh[5];		//ザコクラスへ画像を送る用変数
	int goeiGh[5];		//ゴエイクラスへ画像を送る用変数
	int bossGh[10];		//ボスギャラガクラスへ画像を送る用変数
	ZAKO* zako[20];		//ザコの実体の配列
	GOEI* goei[16];		//ゴエイの実体の配列
public:
	ENEMYMGR();			//コンストラクタ
	~ENEMYMGR();		//デストラクタ
	void Init();		//初期化処理
	void Final();		//終了処理
	void Update();		//更新処理
	void Draw();		//描画処理
};

#endif // !_ENEMYMGR_H_