#ifndef _ENEMY_H_
#define _ENEMY_H_

//�G�l�~�[�̑S�̊Ǘ�
void Enemy_All();

//�G�N���X�̐錾
class ENEMY {
private:
	int x;
	int y;
	int width;
	int height;
	int cx;
	int cy;
	bool onActive;
public:
	ENEMY();
	void Init();
};


#endif // !_ENEMY_H_
