#ifndef _TASK_H_
#define _TASK_H_

//タスククラスの宣言
class TASK {
public:
	virtual ~TASK() {}
	virtual void Init() {}			//初期化処理
	virtual void Final() {}			//終了処理
	virtual void Update() = 0;		//更新処理
	virtual void Draw() = 0;		//描画処理
};

#endif // !_TASK_H