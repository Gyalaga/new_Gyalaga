#ifndef _TITLE_H_
#define _TITLE_H_

typedef enum {
	eMenu_1PLAYER,       //1PLAYER���[�h
	eMenu_2PLAYER,       //2PLAYER���[�h
	eMenu_Num,           //���ڂ̐�
} eMenu;

//�X�V
void Title_update();

//�`��
void Title_draw();
#endif // !_TITLE_H_
