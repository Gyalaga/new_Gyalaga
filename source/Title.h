#ifndef _TITLE_H_
#define _TITLE_H_

typedef enum {
	eMenu_1PLAYER,       //1PLAYERモード
	eMenu_2PLAYER,       //2PLAYERモード
	eMenu_Num,           //項目の数
} eMenu;

//更新
void Title_update();

//描画
void Title_draw();
#endif // !_TITLE_H_
