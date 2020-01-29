#ifndef _ISCENECHANGER_H_
#define _ISCENECHANGER_H_

typedef enum {
	eScene_Title,		//�^�C�g�����
	eScene_Game,		//�Q�[�����
	eScene_End,		//�ݒ���

	eScene_None			//����
}eScene;

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISCENECHANGER {
public:
	virtual ~ISCENECHANGER() = 0;
	virtual void ChangeScene(eScene nextScene) = 0;		//�w��V�[���ɕύX����
};

#endif // !_ISCENECHANGER_H_
