#ifndef _GAME_H_
#define _GAME_H_

#include "BaseScene.h"
#include "Control.h"

class GAME :public BASESCENE {
private:
	CONTROL* control;
public:
	GAME(ISCENECHANGER* changer);
	~GAME();
	void Update();
	void Draw(){}
};

#endif // !_GAME_H_