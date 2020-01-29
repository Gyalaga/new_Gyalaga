#include "Control.h"
#include "DxLib.h"

//コントロールクラスのコンストラクタ
CONTROL::CONTROL() {

	Init();		//初期化処理
}

//コントロールクラスのデストラクタ
CONTROL::~CONTROL() {

	Final();	//終了処理
}

//初期化処理
void CONTROL::Init() {

	enemyMgr = new ENEMYMGR;	//エネミー管理クラスの動的確保をする

	//エネミー関連で使用する変数の初期化
	for (int i = 0; i < 40; i++) {
		ex[i]		= 0;
		ey[i]		= 0;
		eWidth[i]	= 0;
		eHeight[i]	= 0;
		hitCheck[i] = false;
	}
	damage = 1;

	//プレイヤー関連で使用する変数の初期化
	px	= 0;
	py	= 0;
	pw	= 0;
	ph	= 0;
	sx	= 0;
	sy	= 0;
	sx2 = 0;
	sy2 = 0;
	sw	= 0;
	sh	= 0;
	hf	= 0;

	//SE関連で使用する変数の初期化
	wavcnt = 0;
	wavflg = 0;

	//ゲーム終了関連で使用する変数の初期化
	gameEnd		= false;
	gameEndCnt	= 0;
}

//終了処理
void CONTROL::Final() {

	delete enemyMgr;
}

//ゲームの全体制御
void CONTROL::GameControl() {

	for (int i = 0; i < 40; i++) {
		if (hitCheck[i] == true)gameEndCnt++;
	}

	if (gameEndCnt == 40)gameEnd = true;
	else gameEndCnt = 0;

	if (gameEnd == false) {

		Score_Save();		//ハイスコアを記録する
		Score_Draw();		//スコアの描画

		if (wavcnt < 800)wavcnt++;	//SE用カウントを増やす

		//スタート時
		if (wavcnt >= 10) {

			if (wavcnt < 800)DrawFormatString(380, 380, GetColor(255, 255, 255), "START");
			if (wavflg == 0)PlaySoundFile("./res/wav/gal_music_gamestart.wav", DX_PLAYTYPE_BACK);
			wavflg = 1;
		}

		//SEが鳴り終わったら
		if (wavcnt == 800) {

			Player_All();		//プレイヤー全体管理
			enemyMgr->All();	//エネミー管理クラスの全体管理

			//当たり判定関連の座標取得処理
			Player_judgment(&px, &py, &pw, &ph, &sx, &sy, &sw, &sh, &sx2, &sy2, &hf);
			enemyMgr->Send_Coordinate(ex, ey, eWidth, eHeight);

			Hit_Judgment();		//当たり判定処理
		}
	}
}

//当たり判定処理
void CONTROL::Hit_Judgment() {

	enemyMgr->Judgment_OnActive(hitCheck);		//hitCheckに当たり判定が必要かの情報を格納する

	for (int i = 0; i < 40; i++) {

		if (hitCheck[i] == true)continue;	//当たり判定が必要ではない場合次のループへ

		//プレイヤーと敵の当たり判定
		if (hf == 0 && (double)px + pw >= ex[i] && (double)px <= ex[i] + eWidth[i] && (double)py + ph >= ey[i] && (double)py <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(damage, i);
			c.c = 1;
			Player_hit(c.c);
			hf = 1;
			Player_hitflg(hf);
		}

		//プレイヤーの1発目の弾と敵の当たり判定
		if (bullet.sf[0] == 1 && (double)sx + sw >= ex[i] && (double)sx <= ex[i] + eWidth[i] && (double)sy+sh  >= ey[i] && (double)sy+sh <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(damage, i);
			bullet.sf[0] = 0;
			score += 100;
		    Score_up(score);
		}

		//プレイヤーの2発目の弾と敵の当たり判定
		if (bullet.sf[1] == 1 && (double)sx2 + sw >= ex[i] && (double)sx2 <= ex[i] + eWidth[i] && (double)sy2+sh >= ey[i] && (double)sy2+sh <= ey[i] + eHeight[i]) {
			enemyMgr->Hit_ChangeOnActive(damage, i);
			bullet.sf[1] = 0;
			score += 100;
			Score_up(score);
		}
		DrawFormatString(50, 640, GetColor(255, 255, 255), "%d", hf);
	}
}

//ゲーム終了かどうかをゲームクラスへ送る
bool CONTROL::GameEnd_Judgment() {
	return gameEnd;
}