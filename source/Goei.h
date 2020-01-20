#ifndef _GOEI_H_
#define _GOEI_H_

#include "Enemy.h"

class GOEI :public ENEMY {
private:
	int gh[5];		//画像格納変数
public:
	GOEI(int getX, int getY);	//コンストラクタ
	void Init(int ix, int iy);	//初期化処理
	void Final();
	void Update();
	void Draw();
	void Load_Image(int* sGh);
};

#endif // !_GOEI_H_