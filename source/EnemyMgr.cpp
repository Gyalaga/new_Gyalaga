#include "EnemyMgr.h"
#include "DxLib.h"

//コンストラクタ
ENEMYMGR::ENEMYMGR() {
	Init();
}

//デストラクタ
ENEMYMGR::~ENEMYMGR() {
	Final();
}

//初期化処理
void ENEMYMGR::Init() {

	int x, y, x2, y2, x3, y3;	//※ファイルからデータを読み込む機能実装後削除します
	x = 310;
	y = 72;
	x2 = 328;
	y2 = 36;
	x3 = 364;
	y3 = 0;

	enemyAll		= 0;
	enemyAllMove	= ENEMY_MOVERIGHT;
	direction_flg	= 0;
	intervalCnt		= 0;

	//敵の画像を一時的にbaseGhに格納する
	LoadDivGraph("./res/img/Galaga_OBJ_enemy.png", 50, 5, 10, 18, 18, baseGh);

	//各敵のクラスへ送る画像の準備
	for (int i = 0; i < MAX_TYPE; i++) {
		if (i < GENERAL_TYPE) {
			zakoGh[i] = baseGh[i];
			goeiGh[i] = baseGh[i + GOEI_START];
		}
		bossGh[i] = baseGh[i + BOSS_START];
	}

	//ザコの実体を生成する
	for (int i = 0; i < 20; i++) {
		zako[i] = new ZAKO(x, y);
		zako[i]->Load_Image(zakoGh);
		x += 18;
		if (i == 9) {
			y -= 18;
			x =	310;
		}

		//ゴエイの実体を生成する
		if (i < 16) {
			goei[i] = new GOEI(x2, y2);
			goei[i]->Load_Image(goeiGh);
			x2 += 18;

			if (i == 7) {
				y2 -= 18;
				x2 = 328;
			}
		}

		if (i < 4) {
			boss[i] = new BOSS(x3, y3);
			boss[i]->Load_Image(bossGh);
			x3 += 18;
		}
	}
}

//終了処理
void ENEMYMGR::Final() {

	//確保していたメモリを解放する
	for (int i = 0; i < 20; i++) {
		delete zako[i];
		if (i < 16)delete goei[i];
		if (i < 4)delete boss[i];
	}
}

//更新処理
void ENEMYMGR::Update() {

	for (int i = 0; i < 20; i++) {
		zako[i]->Update();
		if (i < 16)goei[i]->Update();
		if (i < 4)boss[i]->Update();
	}

	//間隔カウントが60を超えるとき初期化する
	if (intervalCnt > 120)intervalCnt = 0;

	//カウントが60の時全体を動かす
	if (intervalCnt == 120) {
		enemyAll += enemyAllMove;

		//ザコに全体の移動量を送る
		for (int i = 0; i < 20; i++) {
			zako[i]->Load_AddMove(enemyAllMove);
		}

	}

	//全体で動く方向の判定
	if (enemyAll <= 0) {
		enemyAllMove = ENEMY_MOVERIGHT;
		direction_flg = 0;
	}
	if (enemyAll >= 50) {
		enemyAllMove = ENEMY_MOVELEFT;
		direction_flg = 1;
	}

	intervalCnt++;		//間隔カウントを増やす
}

//描画処理
void ENEMYMGR::Draw() {
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%d",enemyAll);

	for (int i = 0; i < 20; i++) {
		zako[i]->Draw();
		if (i < 16)goei[i]->Draw();
		if (i < 4)boss[i]->Draw();
	}
}