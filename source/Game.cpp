#include "Game.h"
#include "DxLib.h"

GAME::GAME() {
	control = new CONTROL;
}

GAME::~GAME() {
	delete control;
}

void GAME::Update() {
	control->GameControl();
}
