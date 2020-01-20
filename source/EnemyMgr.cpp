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

	int x, y, x2, y2;	//※ファイルからデータを読み込む機能実装後削除します
	x = 310;
	y = 72;
	x2 = 328;
	y2 = 36;

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

		if (i < 16) {
			goei[i] = new GOEI(x2, y2);
			goei[i]->Load_Image(goeiGh);
			x2 += 18;

			if (i == 8) {
				y -= 18;
				x = 328;
			}
		}
	}
}

//終了処理
void ENEMYMGR::Final() {

	//確保していたメモリを解放する
	for (int i = 0; i < 20; i++) {
		delete zako[i];
		if (i < 16)delete goei[i];
	}
}

//更新処理
void ENEMYMGR::Update() {

	for (int i = 0; i < 20; i++) {
		zako[i]->Update();
		if (i < 16)goei[i]->Update();
	}
}

//描画処理
void ENEMYMGR::Draw() {

	for (int i = 0; i < 20; i++) {
		zako[i]->Draw();
		if (i < 16)goei[i]->Draw();
	}
}