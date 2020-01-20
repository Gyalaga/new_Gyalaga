#ifndef _GAME_H_
#define _GAME_H_

#include "Control.h"
#include "Task.h"

class GAME :public TASK {
private:
	CONTROL* control;
public:
	GAME();
	~GAME();
	void Update();
	void Draw(){}
};

#endif // !_GAME_H_