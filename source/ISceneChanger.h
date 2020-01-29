#ifndef _ISCENECHANGER_H_
#define _ISCENECHANGER_H_

typedef enum {
	eScene_Title,		//タイトル画面
	eScene_Game,		//ゲーム画面
	eScene_End,		//設定画面

	eScene_None			//無し
}eScene;

//シーンを変更するためのインターフェイスクラス
class ISCENECHANGER {
public:
	virtual ~ISCENECHANGER() = 0;
	virtual void ChangeScene(eScene nextScene) = 0;		//指定シーンに変更する
};

#endif // !_ISCENECHANGER_H_
