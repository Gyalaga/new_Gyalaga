#ifndef _END_H_
#define _END_H_

#include "BaseScene.h"

class END :public BASESCENE {
private:
	int image;
public:
	END(ISCENECHANGER* changer);
	void Init();
	void Final();
	void Update();
	void Draw();
};

#endif // !_END_H_