#ifndef _SCENE_MGR_H_
#define _SCENE_MGR_H_

typedef enum {
	eScene_MENU,  //���j���[���
	eScene_GAME,  //�Q�[�����
	eScene_RESULT,//�ݒ���
}eScene;

//�X�V
void Scenemgr_update();

//�`��
void Scenemgr_draw();

void Changescene(eScene nextScene);
#endif // !_SCENE_MGR_H_

