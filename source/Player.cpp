#include "DxLib.h"
#include "Player.h"
#include "Keyborad.h"
int cnt = 0, i = 0;
int n, j = 1;
bool init = false;
bool teki = true;
int teki_x = 200, teki_y = 550, c = 0;

void Player_All()//全体
{
	DrawFormatString(0, 20, GetColor(255, 255, 255), "Player_All動き卍");
	if (init == false)
	{
		Player_Init();   //初期化
		init = true;
	}
	Player_int();        //数値の確認用
	Player_Draw();       //描画
	Player_Move();       //動き
	Player_Animation();  //アニメーション
	Player_judgment();   //当たり判定
}

void Player_int()//数値の確認用
{
	DrawFormatString(50, 40, GetColor(255, 255, 255), "c=%d", c); 
	DrawFormatString(50, 60, GetColor(255, 255, 255), "n=%d", n); 
	DrawFormatString(50, 80, GetColor(255, 255, 255), "i=%d", i); 
	DrawFormatString(50, 100, GetColor(255, 255, 255), "Player.mode=%d", Player.mode);
	DrawFormatString(50, 120, GetColor(255, 255, 255), "hp=%d", Player.hp); 
	DrawFormatString(50, 140, GetColor(255, 255, 255), "L_x=%d", Player.x[i]); 
	DrawFormatString(50, 160, GetColor(255, 255, 255), "R_x=%d", Player.x[n]); 
	DrawFormatString(50, 180, GetColor(255, 255, 255), "explosion.check_left_x=%d", explosion.check_left_x); 
	DrawFormatString(50, 200, GetColor(255, 255, 255), "explosion.check_right_x=%d", explosion.check_right_x); 

	if (Player.left_flg[i]  == true)DrawFormatString(100, 220, GetColor(255, 255, 255), "Player.left_flg[%d] true", i);  
	if (Player.right_flg[n] == true)DrawFormatString(100, 240, GetColor(255, 255, 255), "Player.right_flg[%d] true", n); 
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
	if (Player.left_flg[i] == false)DrawRotaGraph(Player.x[i], Player.y[i], 2, PI / 180 * Player.L_rote, Player.image[0], TRUE);
	//右の自機表示
	if (Player.right_flg[n] == true)DrawRotaGraph(Player.x[n], Player.y[n], 2, PI / 180 * Player.R_rote, Player.image[j], TRUE);
	//敵(後で削除予定)
	if(teki==true)DrawRotaGraph(teki_x, teki_y, 2, 0, Player.image[0], TRUE);
}
void Player_Move()//動き
{

	if (Player.mode == 0 || Player.dualmode == true)//通常時,デュアルモード時
	{
		//右を押していたら右に進む

		//通常時
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.dualmode == false && Player.x[i] + Player.center <= 798) Player.x[i] += 3;
		//デュアルモード時
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.dualmode == true  && Player.x[n] + Player.center <= 798) Player.x[i] += 3;
		//デュアルモードから通常になった時
		if (CheckHitKey(KEY_INPUT_RIGHT) && Player.dualmode == false && Player.right_flg[n] == true && Player.x[n] + Player.center <= 798) Player.x[n] += 3;
		
		//左を押していたら左に進む
		//通常時
		if (CheckHitKey(KEY_INPUT_LEFT) && Player.x[i] - Player.center >= 2)   Player.x[i] -= 3;
		//デュアルモードから通常になった時
		if (CheckHitKey(KEY_INPUT_LEFT) && Player.dualmode == false && Player.right_flg[n] == true && Player.left_flg[i] == true && Player.x[n] - Player.center >= 2)   Player.x[n] -= 3;
		
		//スペース押していたら弾発射
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			if (CheckHitKey(KEY_INPUT_LEFT) && Player.x[i] - Player.center >= 2)  teki_y -= 3;              //確認用
			if (CheckHitKey(KEY_INPUT_A) && Player.x[i] - Player.center >= 2)teki = false, dual.flg = true; //確認用
		}

		if (CheckHitKey(KEY_INPUT_Q))c = 1;       //確認用
		if (CheckHitKey(KEY_INPUT_W))c = 3;       //確認用
		if (CheckHitKey(KEY_INPUT_E))teki = true; //確認用

		//捕縛された自機の動き
		if (Player.dualmode == false&&dual.flg_L== false && dual.flg_R== false &&Player.right_flg[n] == true&& dual.c == false)
		{
			if (Player.x[n] <= teki_x) Player.x[n] += 3;      //移動スピードは敵のスピードと同じにする
			if (Player.x[n] >= teki_x) Player.x[n] -= 3;      //移動スピードは敵のスピードと同じにする
			if (Player.y[n] >= teki_y - 32) Player.y[n]-= 3;  //移動スピードは敵のスピードと同じにする
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

			if (Player.x[n] <= teki_x) Player.x[n] += 3;     //移動スピードは敵のスピードと同じにする
			if (Player.x[n] >= teki_x) Player.x[n] -= 3;     //移動スピードは敵のスピードと同じにする
			if (Player.y[n] >= teki_y - 32) Player.y[n] -= 3;//移動スピードは敵のスピードと同じにする
	}
	if (teki == true && Player.x[i] <= 300)c = 5; //確認用
	if (teki == true && Player.x[n] >= 600)c = 6; //確認用
}//Player_Move()終了

void Player_Animation()//アニメーション
{
	//デュアルモード時
	if (Player.dualmode == true)
	{
		//座標合わせ
		if (Player.x[i]+30 >= Player.x[n]) Player.x[n]= Player.x[i] + 30;
		if (Player.x[i]+30 <= Player.x[n]) Player.x[n]= Player.x[i] + 30;
	}

	//奪還時
	if (dual.flg == true)
	{
		Player.mode = 4;     //操作拒否
		Player.R_rote += 18; //回転
		j = 0;               //自機の色を元に
		if (dual.ani_flg[0] == false)
		{
			//座標合わせ
			if (Player.x[i] <= Player.x[n] - 30) Player.x[i]++;
			if (Player.x[i] >= Player.x[n] - 30) Player.x[i]--;
		}

		if (dual.ani_flg[1] == false&&Player.x[i] == Player.x[n] - 30)
		{
			dual.ani_flg[0] == true;
			Player.y[n]++;    //座標合わせ
			Player.R_rote = 0;//回転止める
		}
		//アニメーションので使った変数をリセットとプレイヤーの処理をする
		if (Player.y[i] == Player.y[n])
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
			Player.left_flg[i] = true;
			dual.flg_L = true;
			if (explosion.L==false)
			{
				explosion.L = true;
				explosion.check_left_x = Player.x[i];
			}
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
			i += 1;
			Player.mode = 0; Player.hp -= 1;  c = 0;
			explosion.i = 0; explosion.j = 0; explosion.left_flg = false;
			Player.left_flg[i] = false;
			dual.ani_flg[0] = false;
			dual.ani_flg[1] = false;
			dual.flg_L = false;
			j = 1;
			Player.dualmode = false;
			explosion.L = false;
			dual.c = false;
		}
		//右側
		if (explosion.right_flg == true)
		{
			dual.flg_R = true;
			Player.right_flg[n] = false;
			if (explosion.R == false)
			{
				explosion.R = true;
				explosion.check_right_x = Player.x[n];;
			}
			explosion.n++;              //爆破アニメーション開始
			if (explosion.n == 10)
			{
				explosion.c += 1;
				explosion.n = 0;     //自機の爆破エフェクトスピードをいじるならifの条件を変える
			}
			DrawRotaGraph(explosion.check_right_x, Player.y[n], 2, PI / 180 * 0, explosion.image[explosion.c], TRUE);    //爆破画像表示
		}
		if (explosion.c == 8)          //爆破アニメーションが終わったらリセットする
		{
			i += 1;
			Player.mode = 0; Player.hp -= 1;  c = 0;
			explosion.n = 0; explosion.c = 0; explosion.right_flg = false;
			dual.ani_flg[0] = false;
			dual.ani_flg[1] = false;
			dual.flg_R = false;
			j = 1;
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
			Player.left_flg[i] = true;
			dual.flg_L = true;
			if (explosion.L == false)
			{
				explosion.L = true;
				explosion.check_left_x = Player.x[i];
			}
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
			c = 0;
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
			Player.right_flg[n] = false;
			if ( explosion.R == false)
			{
				explosion.R = true;
				explosion.check_right_x = Player.x[n];
			}
			explosion.n++;              //爆破アニメーション開始
			if (explosion.n == 10)
			{
				explosion.c += 1;
				explosion.n = 0;     //自機の爆破エフェクトスピードをいじるならifの条件を変える
			}
			DrawRotaGraph(explosion.check_right_x, Player.y[n], 2, PI / 180 * 0, explosion.image[explosion.c], TRUE);    //爆破画像表示
		}
		if (explosion.c == 8)          //爆破アニメーションが終わったらリセットする
		{
			c = 0;
			explosion.n = 0; explosion.c = 0; explosion.right_flg = false;
			dual.ani_flg[0] = false;
			dual.ani_flg[1] = false;
			dual.flg_R = false;
			j = 1;
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
			if (Player.x[i] <= teki_x) Player.x[i]++;
			if (Player.x[i] >= teki_x) Player.x[i]--;
			if (Player.y[i] >= teki_y+32) Player.y[i]--;

			if (Player.y[i] < teki_y+32)tractor.check_flg[0] = true;

			if (tractor.check_flg[0] == true)
			{
				Player.L_rote = 0;
				tractor.check_flg[0] = false;
				tractor.check_flg[1] = true;
			}

			if (tractor.check_flg[1] == true)
			{
				cnt++;
				if (cnt == 2)
				{
					if (Player.y[i] >= teki_y - 32)	Player.y[i]--;
					cnt = 0;
				}
			}

			if (Player.y[i] <= teki_y - 32)
			{
				tractor.check_flg[2] = true;
				tractor.check_flg[3] = true;
				tractor.check_flg[4] = true;
			}
			
			if (tractor.check_flg[2] == true)
			{
				n = i;
				i += 1;
				tractor.check_flg[2] = false;
			}

			if (tractor.check_flg[3] == true)
			{
				Player.hp -= 1;
				Player.mode = 0;    
				dual.flg_L = false;
				tractor.left_flg = false;
				c = 0;
				for (int i = 0; i < 4; i++)
				{
					tractor.check_flg[i] = false;
				}
			}
			if (tractor.check_flg[4] == true) Player.right_flg[n] = true;
		}

		if (tractor.right_flg == true)
		{
			Player.mode = 2;      //吸い込まれそう
			Player.R_rote += 18;    //回転させる
			if (Player.x[n] <= teki_x) Player.x[n]++;
			if (Player.x[n] >= teki_x) Player.x[n]--;
			if (Player.y[n] >= teki_y + 32) Player.y[n]--;

			if (Player.y[n] < teki_y + 32)tractor.check_flg[0] = true;

			if (tractor.check_flg[0] == true)
			{
				Player.R_rote = 0;
				tractor.check_flg[0] = false;
				tractor.check_flg[1] = true;
			}

			if (tractor.check_flg[1] == true)
			{
				cnt++;
				if (cnt == 2)
				{
					if (Player.y[n] >= teki_y - 32)	Player.y[n]--;
					cnt = 0;
				}
			}

			if (Player.y[n] <= teki_y - 32)
			{
				tractor.check_flg[2] = true;
				tractor.check_flg[3] = true;
				tractor.check_flg[4] = true;
			}

			if (tractor.check_flg[2] == true)
			{
				i += 1;
				tractor.check_flg[2] = false;
			}

			if (tractor.check_flg[3] == true)
			{
				Player.mode = 0;
				j = 1; 
				Player.hp -= 1;
				Player.dualmode = false;
				dual.flg_R = true;
				tractor.right_flg = false;
				c = 0;
				for (int i = 0; i < 4; i++)
				{
					tractor.check_flg[i] = false;
				}
			}
			if (tractor.check_flg[4] == true) Player.right_flg[n] = true;
		}

}//Player_Animation()終了

void Player_judgment()//当たり判定
{
	//Control.cppから値持ってくる
	//1:左が敵に普通にあたる, 2:左が敵の弾に当たる
	//3:右が敵に普通にあたる, 4:右が敵の弾に当たる
	//5:トラクタービーム
	if (c == 1 || c == 2)
	{
	   explosion.left_flg = true;
	}
	if (c == 3 || c == 4)
	{
		explosion.right_flg = true;
	}

	if (c == 5)
	{
		tractor.left_flg = true;
	}
	if (c == 6)
	{
		tractor.right_flg = true;
	}
}//Player_judgment()終了