#include "DxLib.h"
#include "Player.h"
#include "Keyborad.h"

int i = 0;
bool init = false;
void Player_All() //全体
{
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Player_All動き卍");
	if (init == false)
	{
		Player_Init();//初期化
		init = true;
	}

	Player_Draw();//描画
	Player_Move();//動き
	Player_Animation();//アニメーション
	Player_judgment();//当たり判定
}

void Player_Init()//初期化
{
	LoadDivGraph("./res/img/自機.png", 2, 1, 2, 16, 16, Player.image);  // 自機画像の分割読み込み
	LoadDivGraph("./res/img/bakuhatu.png", 9, 9, 1, 32, 32, explosion.image);              // 爆破画像の分割
}

void Player_Draw()//描画
{
	if (Player.flg == true)DrawRotaGraph(Player.x[i], Player.y[i], 2, PI / 180 * Player.rote, Player.image[0], TRUE);
}
void Player_Move()//動き
{
	DrawFormatString(250, 100, GetColor(255, 255, 255), "%d", Player.x[i]);  // 文字を描画する

	if (Player.mode == 0 || Player.dualmode == true)//通常時,デュアルモード時
	{
		// 右を押していたら右に進む
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.x[i] + Player.center <= 798) Player.x[i] += 3;

		// 左を押していたら左に進む
		if (CheckHitKey(KEY_INPUT_LEFT) && Player.x[i] - Player.center >= 2)   Player.x[i] -= 3;

		//スペース押していたら弾発射
		if (CheckHitKey(KEY_INPUT_SPACE))explosion.left_flg = true;

	}
	if (Player.mode == 2)//捕縛されそうな時
	{
		if (CheckHitKey(KEY_INPUT_SPACE));
	}
	if (Player.mode == 3 || Player.mode == 4)//捕縛時,破壊(非表示)時
	{

	}
}//Player_Move()終了

void Player_Animation()//アニメーション
{
	//撃墜された時
		if (Player.dualmode == false)
		{
			if (explosion.left_flg == true)
			{
				if (explosion.check == 0)
				{
					explosion.check_left_x = Player.x[i];
					explosion.check = 1;
				}
				Player.mode = 4;      //入力拒否 
				explosion.i++;              //爆破アニメーション開始
				if (explosion.i == 10)
				{
					explosion.j += 1;
					explosion.i = 0;     //自機の爆破エフェクトスピードをいじるならifの条件を変える
				}
				DrawRotaGraph(explosion.check_left_x, Player.y[i], 2, PI / 180 * 0, explosion.image[explosion.j], TRUE);    //爆破画像表示
			}
			if (explosion.j == 8)          //爆破アニメーションが終わったらリセットする
			{
				explosion.i += 1; Player.mode = 0; Player.hp -= 1;
				explosion.i = 0;  explosion.j = 0; explosion.left_flg=false;
				explosion.check = 0;
			}
		}
		else
		{

		}

	//吸い込まれ時
	//	Player.mode = 2;      //吸い込まれそう
	//	Player.rote += 18;    //回転させる
}//Player_Animation()終了

void Player_judgment()//当たり判定
{
	//Control.cppから値持ってくる
	//1:敵に普通にあたる, 2:敵の弾に当たる,3:トラクタービーム
	/*
	if(1||2)
	{
	   explosion.left_flg = true;
	}


	if(3)
	{

	}
	*/
}//Player_judgment()終了