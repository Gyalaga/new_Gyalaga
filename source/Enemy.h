#ifndef _ENEMY_H_
#define _ENEMY_H_

//エネミーの全体管理
void Enemy_All();

//敵クラスの宣言
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
