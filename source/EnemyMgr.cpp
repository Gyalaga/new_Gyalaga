#include "EnemyMgr.h"
#include "DxLib.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
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
	y = 132;
	x2 = 328;
	y2 = 82;
	x3 = 380;
	y3 = 32;
	sincount = 0;
	enemyAll = 0;
	goei_no = 0;
	atkActive = false;
	enemyAllMove = ENEMY_MOVERIGHT;
	intervalCnt = 0;
	boss_rand = 0;
	tmpBoss_rand = 0;

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
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {
		zako[i] = new ZAKO(x, y);
		zako[i]->Load_Image(zakoGh);
		x += 30;
		if (i == 9) {
			y -= 25;
			x = 310;
		}
	}

	//ゴエイの実体を生成する
	for (int i = 0; i < ENEMY_GOEINUM; i++) {
		goei[i] = new GOEI(x2, y2);
		goei[i]->Load_Image(goeiGh);
		goei_bazin_x[i] = x2;
		goei_bazin_y[i] = y2;
		goei[i]->Atacck(atkActive, i, goei_bazin_x[i], goei_bazin_y[i]);
		x2 += 35;
		if (i == 7) {
			y2 -= 25;
			x2 = 328;
		}
	}

	//ボスギャラガの実体を追加する
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		boss[i] = new BOSS(x3, y3);
		boss[i]->Load_Image(bossGh);
		x3 += 35;
	}
}

//終了処理
void ENEMYMGR::Final() {

	//確保していたザコクラスのメモリを解放する
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {
		delete zako[i];
	}

	//確保していたゴエイクラスのメモリを解放する
	for (int i = 0; i < ENEMY_GOEINUM; i++) {
		delete goei[i];
	}

	//確保していたボスギャラガクラスのメモリを解放する
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		delete boss[i];
	}
}

//更新処理
void ENEMYMGR::Update() {

	/***乱数の初期化***/
	srand((unsigned)time(NULL));

	//ザコ
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {
		zako[i]->Update();
	}

	//ゴエイ
	for (int i = 0; i < ENEMY_GOEINUM; i++) {
		goei[i]->Update();
	}

	//ボスギャラガ
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		boss[i]->Update();
	}

	//ザコの現在の座標を取得する
	for (int i = 0; i < 20; i++) {
		enemyX[i] = zako[i]->Send_X();
		enemyY[i] = zako[i]->Send_Y();
		width[i] = zako[i]->Send_Width();
		height[i] = zako[i]->Send_Height();
	}

	//ゴエイの現在の座標を取得する
	for (int i = 0; i < 16; i++) {
		enemyX[i + GOEI_ORDER] = goei[i]->Send_X();
		enemyY[i + GOEI_ORDER] = goei[i]->Send_Y();
		width[i + GOEI_ORDER] = goei[i]->Send_Width();
		height[i + GOEI_ORDER] = goei[i]->Send_Height();
	}

	//ボスギャラガの現在の座標を取得する
	for (int i = 0; i < 4; i++) {
		enemyX[i + BOSS_ORDER] = boss[i]->Send_X();
		enemyY[i + BOSS_ORDER] = boss[i]->Send_Y();
		width[i + BOSS_ORDER] = boss[i]->Send_Width();
		height[i + BOSS_ORDER] = boss[i]->Send_Height();
		Yes[i] = boss[i]->Yes_OnActive();
	}

	//間隔カウントが240を超えるとき初期化する
	if (intervalCnt > INTERVAL_RESET)intervalCnt = 0;

	//sinカウントが100を超えると動かす
	if (sincount >= 100) {
		bool atkActive = true;
		goei[goei_no]->Atacck(atkActive, goei_no,
			goei_bazin_x[goei_no], goei_bazin_y[goei_no]);

		/***ゴエイが上に戻ってきたタイミングで、攻撃フラグをfalseにする***/
		if (sincount >= 863) {
			/***ゴエイ…もう戦わなくていいんだ！！！***/
			bool atkActive = false;
			goei[goei_no]->Atacck(atkActive, goei_no,
				goei_bazin_x[goei_no], goei_bazin_y[goei_no]);
			/***次のドレイをランダムにする***/
			goei_no = (rand() % 15);
			/***戦わなきゃ…生き残れない!!!***/
			goei[goei_no]->Atacck(atkActive, goei_no,
				goei_bazin_x[goei_no], goei_bazin_y[goei_no]);
			sincount = 0;

		}
	}

	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		if (boss[i]->Send_AtkActive() == true)break;
		if (i == 3) {
			boss_rand = rand() % 4;
			boss[boss_rand]->TractorInit();
		}
	}

	boss[boss_rand]->Load_AtkActive(true);

	//カウントが125の時全体を動かす
	if (intervalCnt % INTERVAL_MIDDLE == 0) {
		enemyAll += enemyAllMove;

		//ザコに全体の移動量・間隔を送る
		for (int i = 0; i < ENEMY_ZAKONUM; i++) {
			zako[i]->Load_AddMove(enemyAllMove);
			zako[i]->Load_Interval(intervalCnt);
		}

		//ゴエイに全体の移動量・間隔を送る
		for (int i = 0; i < ENEMY_GOEINUM; i++) {
			goei[i]->Load_AddMove(enemyAllMove);
			goei[i]->Load_Interval(intervalCnt);
		}

		//ボスギャラガの移動量・間隔を送る
		for (int i = 0; i < ENEMY_BOSSNUM; i++) {
			boss[i]->Load_AddMove(enemyAllMove);
			boss[i]->Load_Interval(intervalCnt);
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
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {
		zako[i]->Draw();
	}

	//ゴエイ
	for (int i = 0; i < ENEMY_GOEINUM; i++) {
		goei[i]->Draw();
	}

	//ボスギャラガ
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		boss[i]->Draw();
	}
}

//コントロールクラスで定義した変数のポインタに座標を代入する
void ENEMYMGR::Send_Coordinate(double* setX, double* setY, int* setWidth, int* setHeight) {
	for (int i = 0; i < ENEMY_MAXNUM; i++) {
		setX[i] = enemyX[i];
		setY[i] = enemyY[i];
		setWidth[i] = width[i];
		setHeight[i] = height[i];
	}
}
void ENEMYMGR::Yes_Judgment(bool* flg) {
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {
		flg[i] = Yes[i];
	}
}

//コントロールクラスから取得したHitした敵のonActiveをfalseにする
void ENEMYMGR::Hit_ChangeOnActive(int getDamage, int n) {

	//ダメージを各敵クラスへ送る
	if (n < GOEI_ORDER) {

		zako[n]->Load_Damage(getDamage);
	}
	else if (n >= GOEI_ORDER && n < BOSS_ORDER) {

		goei[n - GOEI_ORDER]->Load_Damage(getDamage);
	}
	else if (n >= BOSS_ORDER && n < ENEMY_MAXNUM) {

		boss[n - BOSS_ORDER]->Load_Damage(getDamage);
	}
}

//コントロールクラスに当たり判定が必要か返す処理
void ENEMYMGR::Judgment_OnActive(bool* setHitCheck) {

	//各ザコが当たり判定を必要か判定
	for (int i = 0; i < ENEMY_ZAKONUM; i++) {

		if (zako[i]->Send_OnActive() == true) {
			setHitCheck[i] = false;
		}
		else {
			setHitCheck[i] = true;
		}
	}

	//各ゴエイが当たり判定を必要か判定
	for (int i = 0; i < ENEMY_GOEINUM; i++) {

		if (goei[i]->Send_OnActive() == true) {
			setHitCheck[i + GOEI_ORDER] = false;
		}
		else {
			setHitCheck[i + GOEI_ORDER] = true;
		}
	}

	//各ボスギャラガが当たり判定を必要か判定
	for (int i = 0; i < ENEMY_BOSSNUM; i++) {

		if (boss[i]->Send_OnActive() == true) {
			setHitCheck[i + BOSS_ORDER] = false;
		}
		else {
			setHitCheck[i + BOSS_ORDER] = true;
		}
	}
}

void ENEMYMGR::All() {
	Update();
	Draw();
}