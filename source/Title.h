#ifndef _TITLE_H_
#define _TITLE_H_

#include "BaseScene.h"

typedef enum {
	eMenu_1PLAYER,       //1PLAYERモード
	eMenu_2PLAYER,       //2PLAYERモード
	eMenu_Num,           //項目の数
} eMenu;

class TITLE :public BASESCENE {
private:
	int PLAYER1_Y = 1170;    //「1PLAYER」文字のy座標
	int PLAYER2_Y = 1210;   //「2PLAYER」文字のy座標
	int TITLE_Y = 900;   //「タイトルロゴ」のy座標
	int SCORE_Y = 800;   //「HI-SCORE」のｙ座標
	int ONEUP_Y = 800;   //「1UP」のｙ座標
	int TWOUP_Y = 800;   //「2UP」のｙ座標
	int NAMCO_Y = 1350;  //「namco」のｙ座標

	int Select = eMenu_1PLAYER;
public:
	TITLE(ISCENECHANGER* changer);
	void Update();
	void Draw();
};

#endif // !_TITLE_H_
