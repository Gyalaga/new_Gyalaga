#ifndef _BASESCENE_H_
#define _BASESCENE_H_

#include "Task.h"
#include "ISceneChanger.h"

class BASESCENE :public TASK {
protected:
	int mImageHandle;				//背景画像を格納する
	ISCENECHANGER* mSceneChanger;	//クラス所有元にシーン切り替えを伝えるインターフェイス
public:
	BASESCENE(ISCENECHANGER* changer);
	virtual ~BASESCENE(){}
	virtual void Init(){}
	virtual void Final(){}
	virtual void Update(){}
	virtual void Draw(){}
};

#endif // !_BASESCENE_H_
