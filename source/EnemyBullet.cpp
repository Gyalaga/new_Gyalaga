#include "EnemyBullet.h"
#include "DxLib.h"

//�R���X�g���N�^
ENEMYBULLET::ENEMYBULLET() {
	Init();
}

//����������
void ENEMYBULLET::Init() {
	LoadDivGraph("./res/img/Galaga_OBJ_bullet.png", 4, 4, 1, 10, 12, shot);

	x = 100;
	y = 100;
	width = 10;
	height = 12;
	onActive = true;

}

//�I������
void ENEMYBULLET::Final() {

}

//�X�V����
void ENEMYBULLET::Update() {

}

//�`�揈��
void ENEMYBULLET::Draw() {
	DrawGraph(x, y, shot[0], TRUE);
}