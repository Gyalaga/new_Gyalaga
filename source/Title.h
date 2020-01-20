#ifndef _TITLE_H_
#define _TITLE_H_

#include "BaseScene.h"

typedef enum {
	eMenu_1PLAYER,       //1PLAYER���[�h
	eMenu_2PLAYER,       //2PLAYER���[�h
	eMenu_Num,           //���ڂ̐�
} eMenu;

class TITLE :public BASESCENE {
private:
	int PLAYER1_Y = 1170;    //�u1PLAYER�v������y���W
	int PLAYER2_Y = 1210;   //�u2PLAYER�v������y���W
	int TITLE_Y = 900;   //�u�^�C�g�����S�v��y���W
	int SCORE_Y = 800;   //�uHI-SCORE�v�̂����W
	int ONEUP_Y = 800;   //�u1UP�v�̂����W
	int TWOUP_Y = 800;   //�u2UP�v�̂����W
	int NAMCO_Y = 1350;  //�unamco�v�̂����W

	int Select = eMenu_1PLAYER;
public:
	TITLE(ISCENECHANGER* changer);
	void Update();
	void Draw();
};

#endif // !_TITLE_H_
