#include "Game.h"
#include "DxLib.h"

GAME::GAME(ISCENECHANGER* changer):BASESCENE(changer) {
	control = new CONTROL;
}

GAME::~GAME() {
	delete control;
}

void GAME::Update() {
	control->GameControl();
}
