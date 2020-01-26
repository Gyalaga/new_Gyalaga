#include "EnemyMgr.h"
#include "DxLib.h"
#include<math.h>
#define PI 3.1415926f

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
	y = 120;
	x2 = 328;
	y2 = 68;
	x3 = 380;
	y3 = 15;
	sincount = 0;

	enemyAll = 0;
	enemyAllMove = ENEMY_MOVERIGHT;
	intervalCnt = 0;

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
		x += 30;
		if (i == 9) {
			y -= 25;
			x = 310;
		}
	}

	//ゴエイの実体を生成する
	for (int i = 0; i < 16; i++) {
		goei[i] = new GOEI(x2, y2);
		goei[i]->Load_Image(goeiGh);
		x2 += 35;
		if (i == 7) {
			y2 -= 20;
			x2 = 328;
		}
	}

	//ボスギャラガの実体を追加する
	for (int i = 0; i < 4; i++) {
		boss[i] = new BOSS(x3, y3);
		boss[i]->Load_Image(bossGh);
		x3 += 35;
	}
}

//終了処理
void ENEMYMGR::Final() {

	//確保していたザコクラスのメモリを解放する
	for (int i = 0; i < 20; i++) {
		delete zako[i];
	}

	//確保していたゴエイクラスのメモリを解放する
	for (int i = 0; i < 16; i++) {
		delete goei[i];
	}

	//確保していたボスギャラガクラスのメモリを解放する
	for (int i = 0; i < 4; i++) {
		delete boss[i];
	}
}

//更新処理
void ENEMYMGR::Update() {

	//ザコ
	for (int i = 0; i < 20; i++) {
		zako[i]->Update();
	}

	//ゴエイ
	for (int i = 0; i < 16; i++) {
		goei[i]->Update();
	}

	//ボスギャラガ
	for (int i = 0; i < 4; i++) {
		boss[i]->Update();
	}

	//ザコの現在の座標を取得する
	for (int i = 0; i < 20; i++) {
		enemyX[i] = zako[i]->Send_X();
		enemyY[i] = zako[i]->Send_Y();
	}

	//ゴエイの現在の座標を取得する
	for (int i = 0; i < 16; i++) {
		enemyX[i + GOEI_ORDER] = goei[i]->Send_X();
		enemyY[i + GOEI_ORDER] = goei[i]->Send_Y();
	}

	//ボスギャラガの現在の座標を取得する
	for (int i = 0; i < 4; i++) {
		enemyX[i + BOSS_ORDER] = boss[i]->Send_X();
		enemyY[i + BOSS_ORDER] = boss[i]->Send_Y();
	}

	//間隔カウントが60を超えるとき初期化する
	if (intervalCnt > 120)intervalCnt = 0;
	
	//sinカウントが100を超えると動かす
	if (sincount >= 100) {
		bool atkActive = true;
		zako[0]->Atacck(atkActive);
	}

	//カウントが60の時全体を動かす
	if (intervalCnt == 120) {
		enemyAll += enemyAllMove;
		

		//ザコに全体の移動量を送る
		for (int i = 0; i < 20; i++) {
			zako[i]->Load_AddMove(enemyAllMove);
		}

		
		//ゴエイに全体の移動量を送る
		for (int i = 0; i < 16; i++) {
			goei[i]->Load_AddMove(enemyAllMove);
		}

		//ボスギャラガの移動量を送る
		for (int i = 0; i < 4; i++) {
			boss[i]->Load_AddMove(enemyAllMove);
		}

	}

	//全体で動く方向の判定
	if (enemyAll <= -50) {
		enemyAllMove = ENEMY_MOVERIGHT;
	}
	if (enemyAll >= 50) {
		enemyAllMove = ENEMY_MOVELEFT;
	}
	sincount++;         //sin移動カウントを増やす
	intervalCnt++;		//間隔カウントを増やす


}

//描画処理
void ENEMYMGR::Draw() {

	//ザコ
	for (int i = 0; i < 20; i++) {
		zako[i]->Draw();
	}

	//ゴエイ
	for (int i = 0; i < 16; i++) {
		goei[i]->Draw();
	}

	//ボスギャラガ
	for (int i = 0; i < 4; i++) {
		boss[i]->Draw();
	}
}

//コントロールクラスで定義した変数のポインタに座標を代入する
void ENEMYMGR::Send_Coordinate(double* setX, double* setY) {
	for (int i = 0; i < 40; i++) {
		*(setX + i) = enemyX[i];
		*(setY + i) = enemyY[i];
	}
}