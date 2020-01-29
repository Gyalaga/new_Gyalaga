#ifndef _END_H_
#define _END_H_

#include "BaseScene.h"

class END :public BASESCENE {
private:
public:
	END(ISCENECHANGER* changer);
	void Update();
	void Draw();
};

#endif // !_END_H_