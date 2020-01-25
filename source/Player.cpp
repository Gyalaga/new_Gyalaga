#include "DxLib.h"
#include "Player.h"
#include "Keyborad.h"
#include "Shot_Extern.h"
int qwert = 0;
void Player_All()//全体
{
	DrawFormatString(0, 20, GetColor(255, 255, 255), "Player_All動き卍");
	if (c.init == false)
	{
		Player_Init();   //初期化
		c.init = true;
	}
	//Player_int();        //数値の確認用
	Player_Draw();       //描画
	Player_Move();       //動き
	Player_Shot();            //Playerの弾の全体管理
	Player_Animation();  //アニメーション
	Player_judgment();   //当たり判定
}

void Player_int()//数値の確認用
{
	if (c.teki == true && Player.x[c.i] <= 300)c.c = 5; //確認用
	if (c.teki == true && Player.x[c.n] >= 600)c.c = 6; //確認用

	if (CheckHitKey(KEY_INPUT_Q))c.c = 1;       //確認用
	if (CheckHitKey(KEY_INPUT_W))c.c = 3;       //確認用
	if (CheckHitKey(KEY_INPUT_E))c.teki = true; //確認用

	if (CheckHitKey(KEY_INPUT_B) && Player.x[c.i] - Player.center >= 2)  c.teki_y -= 3;              //確認用
	if (CheckHitKey(KEY_INPUT_A) && Player.x[c.i] - Player.center >= 2)c.teki = false, dual.flg = true; //確認用

		//敵(後で削除予定)
	if (c.teki == true)DrawRotaGraph(c.teki_x, c.teki_y, 2, 0, Player.image[0], TRUE);

	DrawFormatString(50, 40, GetColor(255, 255, 255), "c=%d", c.c);
	DrawFormatString(50, 60, GetColor(255, 255, 255), "n=%d", c.n);
	DrawFormatString(50, 80, GetColor(255, 255, 255), "i=%d", c.i);
	DrawFormatString(50, 100, GetColor(255, 255, 255), "Player.mode=%d", Player.mode);
	DrawFormatString(50, 120, GetColor(255, 255, 255), "hp=%d", Player.hp);
	DrawFormatString(50, 140, GetColor(255, 255, 255), "L_x=%d", Player.x[c.i]);
	DrawFormatString(50, 160, GetColor(255, 255, 255), "R_x=%d", Player.x[c.n]);
	DrawFormatString(50, 180, GetColor(255, 255, 255), "explosion.check_left_x=%d", explosion.check_left_x);
	DrawFormatString(50, 200, GetColor(255, 255, 255), "explosion.check_right_x=%d", explosion.check_right_x);

	if (Player.left_flg[c.i] == true)DrawFormatString(100, 220, GetColor(255, 255, 255), "Player.left_flg[%d] true", c.i);
	if (Player.right_flg[c.n] == true)DrawFormatString(100, 240, GetColor(255, 255, 255), "Player.right_flg[%d] true", c.n);
	if (dual.flg_L == true)DrawFormatString(100, 260, GetColor(255, 255, 255), "dual.flg_L true");
	if (dual.flg_R == true)DrawFormatString(100, 280, GetColor(255, 255, 255), "dual.flg_R true");
}

void Player_Init()//初期化
{
	LoadDivGraph("./res/img/自機.png", 2, 1, 2, 16, 16, Player.image);         // 自機画像の分割読み込み
	LoadDivGraph("./res/img/bakuhatu.png", 9, 9, 1, 32, 32, explosion.image);  // 爆破画像の分割
}

void Player_Draw()//描画
{
	//左の自機表示
	if (Player.left_flg[c.i] == false)DrawRotaGraph(Player.x[c.i], Player.y[c.i], 2, PI / 180 * Player.L_rote, Player.image[0], TRUE);
	//右の自機表示
	if (Player.right_flg[c.n] == true)DrawRotaGraph(Player.x[c.n], Player.y[c.n], 2, PI / 180 * Player.R_rote, Player.image[c.j], TRUE);
}
void Player_Move()//動き
{

	if (Player.mode == 0 || Player.dualmode == true)//通常時,デュアルモード時
	{
		//右を押していたら右に進む

		//通常時
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.dualmode == false && Player.x[c.i] + Player.center <= 798) Player.x[c.i] += 3;
		//デュアルモード時
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.dualmode == true && Player.x[c.n] + Player.center <= 798) Player.x[c.i] += 3;
		//デュアルモードから通常になった時
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.dualmode == false && Player.right_flg[c.n] == true && Player.x[c.n] + Player.center <= 798) Player.x[c.n] += 3;

		//左を押していたら左に進む
		//通常時
		if (CheckHitKey(KEY_INPUT_LEFT) && Player.x[c.i] - Player.center >= 2)   Player.x[c.i] -= 3;
		//デュアルモードから通常になった時
		if (CheckHitKey(KEY_INPUT_LEFT) && Player.dualmode == false && Player.right_flg[c.n] == true && Player.left_flg[c.i] == true && Player.x[c.n] - Player.center >= 2)   Player.x[c.n] -= 3;

		//スペース押していたら弾発射
		if (CheckHitKey(KEY_INPUT_SPACE))
		{

		}

		//捕縛された自機の動き
		if (Player.dualmode == false && dual.flg_L == false && dual.flg_R == false && Player.right_flg[c.n] == true && dual.c == false)
		{
			if (Player.x[c.n] <= c.teki_x) Player.x[c.n] += 3;      //移動スピードは敵のスピードと同じにする
			if (Player.x[c.n] >= c.teki_x) Player.x[c.n] -= 3;      //移動スピードは敵のスピードと同じにする
			if (Player.y[c.n] >= c.teki_y - 32) Player.y[c.n] -= 3;  //移動スピードは敵のスピードと同じにする
		}

	}
	if (Player.mode == 2)//捕縛されそうな時
	{
		if (CheckHitKey(KEY_INPUT_SPACE));
	}
	if (Player.mode == 3 || Player.mode == 4)//捕縛時,破壊(非表示)時
	{

	}

	if (Player.hp == 0)//hpが0になったら
	{
		Player.mode = 4;//操作拒否
		DrawFormatString(340, 400, GetColor(255, 255, 255), "ゲームオーバー");  //文字を描画する

		if (Player.x[c.n] <= c.teki_x) Player.x[c.n] += 3;     //移動スピードは敵のスピードと同じにする
		if (Player.x[c.n] >= c.teki_x) Player.x[c.n] -= 3;     //移動スピードは敵のスピードと同じにする
		if (Player.y[c.n] >= c.teki_y - 32) Player.y[c.n] -= 3;//移動スピードは敵のスピードと同じにする
	}
}//Player_Move()終了

void Player_Shot()//Playerの弾の全体管理
{
	if (qwert == 0)
	{
		Shot_init();
		qwert = 1;
	}
	Shot_draw();
	Shot_Check(Player.x[c.i] - 1 , Player.y[c.i] - Player.center);
}

void Player_Animation()//アニメーション
{
	//デュアルモード時
	if (Player.dualmode == true)
	{
		//座標合わせ
		if (Player.x[c.i] + 30 >= Player.x[c.n]) Player.x[c.n] = Player.x[c.i] + 30;
		if (Player.x[c.i] + 30 <= Player.x[c.n]) Player.x[c.n] = Player.x[c.i] + 30;
	}

	//奪還時
	if (dual.flg == true)
	{
		Player.mode = 4;     //操作拒否
		Player.R_rote += 18; //回転
		c.j = 0;               //自機の色を元に
		if (dual.ani_flg[0] == false)
		{
			//座標合わせ
			if (Player.x[c.i] <= Player.x[c.n] - 30) Player.x[c.i]++;
			if (Player.x[c.i] >= Player.x[c.n] - 30) Player.x[c.i]--;
		}

		if (dual.ani_flg[1] == false && Player.x[c.i] == Player.x[c.n] - 30)
		{
			dual.ani_flg[0] = true;
			Player.y[c.n]++;    //座標合わせ
			Player.R_rote = 0;//回転止める
		}
		//アニメーションので使った変数をリセットとプレイヤーの処理をする
		if (Player.y[c.i] == Player.y[c.n])
		{
			dual.ani_flg[1] = true;
			Player.R_rote = 0;
			dual.flg = false;
			Player.hp += 1;
			Player.mode = 0;
			Player.dualmode = true;
		}
	}
	//撃墜された時
	if (Player.dualmode == false)
	{
		//左側
		if (explosion.left_flg == true)
		{
			Player.left_flg[c.i] = true;
			dual.flg_L = true;
			if (explosion.L == false)
			{
				explosion.L = true;
				explosion.check_left_x = Player.x[c.i];
			}
			explosion.i++;              //爆破アニメーション開始
			if (explosion.i == 10)
			{
				explosion.j += 1;
				explosion.i = 0;     //自機の爆破エフェクトスピードをいじるならifの条件を変える
			}
			DrawRotaGraph(explosion.check_left_x, Player.y[c.i], 2, PI / 180 * 0, explosion.image[explosion.j], TRUE);    //爆破画像表示
		}
		if (explosion.j == 8)          //爆破アニメーションが終わったらリセットする
		{
			c.i += 1;
			Player.mode = 0; Player.hp -= 1;  c.c = 0;
			explosion.i = 0; explosion.j = 0; explosion.left_flg = false;
			Player.left_flg[c.i] = false;
			dual.ani_flg[0] = false;
			dual.ani_flg[1] = false;
			dual.flg_L = false;
			c.j = 1;
			Player.dualmode = false;
			explosion.L = false;
			dual.c = false;
		}
		//右側
		if (explosion.right_flg == true)
		{
			dual.flg_R = true;
			Player.right_flg[c.n] = false;
			if (explosion.R == false)
			{
				explosion.R = true;
				explosion.check_right_x = Player.x[c.n];
			}
			explosion.n++;              //爆破アニメーション開始
			if (explosion.n == 10)
			{
				explosion.c += 1;
				explosion.n = 0;     //自機の爆破エフェクトスピードをいじるならifの条件を変える
			}
			DrawRotaGraph(explosion.check_right_x, Player.y[c.n], 2, PI / 180 * 0, explosion.image[explosion.c], TRUE);    //爆破画像表示
		}
		if (explosion.c == 8)          //爆破アニメーションが終わったらリセットする
		{
			c.i += 1;
			Player.mode = 0; Player.hp -= 1;  c.c = 0;
			explosion.n = 0; explosion.c = 0; explosion.right_flg = false;
			dual.ani_flg[0] = false;
			dual.ani_flg[1] = false;
			dual.flg_R = false;
			c.j = 1;
			Player.dualmode = false;
			explosion.R = false;
			dual.c = false;
		}
	}
	//デュアルモード時
	if (Player.dualmode == true)
	{
		//左側
		if (explosion.left_flg == true)
		{
			dual.c = true;
			Player.left_flg[c.i] = true;
			dual.flg_L = true;
			if (explosion.L == false)
			{
				explosion.L = true;
				explosion.check_left_x = Player.x[c.i];
			}
			explosion.i++;              //爆破アニメーション開始
			if (explosion.i == 10)
			{
				explosion.j += 1;
				explosion.i = 0;     //自機の爆破エフェクトスピードをいじるならifの条件を変える
			}
			DrawRotaGraph(explosion.check_left_x, Player.y[c.i], 2, PI / 180 * 0, explosion.image[explosion.j], TRUE);    //爆破画像表示
		}
		if (explosion.j == 8)          //爆破アニメーションが終わったらリセットする
		{
			c.c = 0;
			explosion.i = 0; explosion.j = 0; explosion.left_flg = false;
			dual.ani_flg[0] = false;
			dual.ani_flg[1] = false;
			dual.flg_L = false;
			Player.dualmode = false;
			explosion.L = false;
		}
		//右側
		if (explosion.right_flg == true)
		{
			dual.c = true;
			dual.flg_R = true;
			Player.right_flg[c.n] = false;
			if (explosion.R == false)
			{
				explosion.R = true;
				explosion.check_right_x = Player.x[c.n];
			}
			explosion.n++;              //爆破アニメーション開始
			if (explosion.n == 10)
			{
				explosion.c += 1;
				explosion.n = 0;     //自機の爆破エフェクトスピードをいじるならifの条件を変える
			}
			DrawRotaGraph(explosion.check_right_x, Player.y[c.n], 2, PI / 180 * 0, explosion.image[explosion.c], TRUE);    //爆破画像表示
		}
		if (explosion.c == 8)          //爆破アニメーションが終わったらリセットする
		{
			c.c = 0;
			explosion.n = 0; explosion.c = 0; explosion.right_flg = false;
			dual.ani_flg[0] = false;
			dual.ani_flg[1] = false;
			dual.flg_R = false;
			c.j = 1;
			Player.dualmode = false;
			explosion.R = false;
		}
	}
	if (dual.flg_L == true && dual.flg_R == true)
	{
		Player.dualmode = false;
		Player.mode = 4;
	}

	//吸い込まれ時
	if (tractor.left_flg == true)
	{
		tractor.check_flg[4] = false;

		Player.mode = 2;      //吸い込まれそう
		Player.L_rote += 18;    //回転させる
		if (Player.x[c.i] <= c.teki_x) Player.x[c.i]++;
		if (Player.x[c.i] >= c.teki_x) Player.x[c.i]--;
		if (Player.y[c.i] >= c.teki_y + 32) Player.y[c.i]--;

		if (Player.y[c.i] < c.teki_y + 32)tractor.check_flg[0] = true;

		if (tractor.check_flg[0] == true)
		{
			Player.L_rote = 0;
			tractor.check_flg[0] = false;
			tractor.check_flg[1] = true;
		}

		if (tractor.check_flg[1] == true)
		{
			c.cnt++;
			if (c.cnt == 2)
			{
				if (Player.y[c.i] >= c.teki_y - 32)	Player.y[c.i]--;
				c.cnt = 0;
			}
		}

		if (Player.y[c.i] <= c.teki_y - 32)
		{
			tractor.check_flg[2] = true;
			tractor.check_flg[3] = true;
			tractor.check_flg[4] = true;
		}

		if (tractor.check_flg[2] == true)
		{
			c.n = c.i;
			c.i += 1;
			tractor.check_flg[2] = false;
		}

		if (tractor.check_flg[3] == true)
		{
			Player.hp -= 1;
			Player.mode = 0;
			dual.flg_L = false;
			tractor.left_flg = false;
			c.c = 0;
			for (int i = 0; i < 4; i++)
			{
				tractor.check_flg[i] = false;
			}
		}
		if (tractor.check_flg[4] == true) Player.right_flg[c.n] = true;
	}

	if (tractor.right_flg == true)
	{
		Player.mode = 2;      //吸い込まれそう
		Player.R_rote += 18;    //回転させる
		if (Player.x[c.n] <= c.teki_x) Player.x[c.n]++;
		if (Player.x[c.n] >= c.teki_x) Player.x[c.n]--;
		if (Player.y[c.n] >= c.teki_y + 32) Player.y[c.n]--;

		if (Player.y[c.n] < c.teki_y + 32)tractor.check_flg[0] = true;

		if (tractor.check_flg[0] == true)
		{
			Player.R_rote = 0;
			tractor.check_flg[0] = false;
			tractor.check_flg[1] = true;
		}

		if (tractor.check_flg[1] == true)
		{
			c.cnt++;
			if (c.cnt == 2)
			{
				if (Player.y[c.n] >= c.teki_y - 32)	Player.y[c.n]--;
				c.cnt = 0;
			}
		}

		if (Player.y[c.n] <= c.teki_y - 32)
		{
			tractor.check_flg[2] = true;
			tractor.check_flg[3] = true;
			tractor.check_flg[4] = true;
		}

		if (tractor.check_flg[2] == true)
		{
			c.i += 1;
			tractor.check_flg[2] = false;
		}

		if (tractor.check_flg[3] == true)
		{
			Player.mode = 0;
			c.j = 1;
			Player.hp -= 1;
			Player.dualmode = false;
			dual.flg_R = true;
			tractor.right_flg = false;
			c.c = 0;
			for (int i = 0; i < 4; i++)
			{
				tractor.check_flg[i] = false;
			}
		}
		if (tractor.check_flg[4] == true) Player.right_flg[c.n] = true;
	}

}//Player_Animation()終了

void Player_judgment()//当たり判定
{
	//Control.cppに座標を渡す
	CONTROL* Y = 0;
	CONTROL* X = 0;
	X->PlayerGet(Player.x[c.i], Player.y[c.i]);
	Y->PlayerGet(Player.x[c.i], Player.y[c.i]);
	//Control.cppから値持ってくる
	//1:左が敵に普通にあたる, 2:左が敵の弾に当たる
	//3:右が敵に普通にあたる, 4:右が敵の弾に当たる
	//5:トラクタービーム
	if (c.c == 1 || c.c == 2)
	{
		explosion.left_flg = true;
	}
	if (c.c == 3 || c.c == 4)
	{
		explosion.right_flg = true;
	}

	if (c.c == 5)
	{
		tractor.left_flg = true;
	}
	if (c.c == 6)
	{
		tractor.right_flg = true;
	}
}//Player_judgment()終了