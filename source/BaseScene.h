#ifndef _BASESCENE_H_
#define _BASESCENE_H_

#include "Task.h"
#include "ISceneChanger.h"

class BASESCENE :public TASK {
protected:
	int mImageHandle;				//�w�i�摜���i�[����
	ISCENECHANGER* mSceneChanger;	//�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
public:
	BASESCENE(ISCENECHANGER* changer);
	virtual ~BASESCENE(){}
	virtual void Init(){}
	virtual void Final(){}
	virtual void Update(){}
	virtual void Draw(){}
};

#endif // !_BASESCENE_H_
