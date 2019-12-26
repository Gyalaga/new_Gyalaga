#include "DxLib.h"
#include "Player.h"
#include "Keyborad.h"

int i = 0;

void Player_All() //全体
{
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Player_All動き卍");
	Player_Init();//初期化
	Player_Draw();//描画
	Player_Move();//動き

}

void Player_Init()
{
	LoadDivGraph("./res/img/自機.png", 2, 1, 2, 16, 16, Player.image);  // 自機画像の分割読み込み
}

void Player_Draw()//描画
{
	if (Player.flg == true)DrawRotaGraph(Player.x[i], Player.y[i], 2, PI / 180 * Player.rote, Player.image[0], TRUE);
}
void Player_Move()//動き
{
	DrawFormatString(250, 100, GetColor(255, 255, 255), "%d", Player.x[i]);  // 文字を描画する

	if (Player.mode == 0 || Player.mode == 1)//通常時,デュアルモード時
	{
		// 右を押していたら右に進む
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.x[i] + Player.center <= 798) Player.x[i] += 3;

		// 左を押していたら左に進む
		if (CheckHitKey(KEY_INPUT_LEFT) && Player.x[i] - Player.center >= 2)   Player.x[i] -= 3;

		//スペース押していたら弾発射
		if (CheckHitKey(KEY_INPUT_SPACE));

	}
	if (Player.mode == 2)//捕縛されそうな時
	{
		if (CheckHitKey(KEY_INPUT_SPACE));
	}
	if (Player.mode == 3 || Player.mode == 4)//捕縛時,破壊(非表示)時
	{

	}
}//Player_Move()終了