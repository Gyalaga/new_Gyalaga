#ifndef _GOEI_H_
#define _GOEI_H_

#include "Enemy.h"

class GOEI :public ENEMY {
private:
	int gh[5];		//�摜�i�[�ϐ�
public:
	GOEI(int getX, int getY);	//�R���X�g���N�^
	void Init(int ix, int iy);	//����������
	void Final();
	void Update();
	void Draw();
	void Load_Image(int* sGh);
};

#endif // !_GOEI_H_