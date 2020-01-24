#include "EnemyBullet.h"
#include "DxLib.h"

//コンストラクタ
ENEMYBULLET::ENEMYBULLET() {
	Init();
}

//初期化処理
void ENEMYBULLET::Init() {
	LoadDivGraph("./res/img/Galaga_OBJ_bullet.png", 4, 4, 1, 10, 12, shot);

	x = 100;
	y = 100;
	width = 10;
	height = 12;
	onActive = true;

}

//終了処理
void ENEMYBULLET::Final() {

}

//更新処理
void ENEMYBULLET::Update() {

}

//描画処理
void ENEMYBULLET::Draw() {
	DrawGraph(x, y, shot[0], TRUE);
}