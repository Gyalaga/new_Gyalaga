#ifndef _TASK_H_
#define _TASK_H_

//�^�X�N�N���X�̐錾
class TASK {
public:
	virtual ~TASK() {}
	virtual void Init() {}			//����������
	virtual void Final() {}			//�I������
	virtual void Update() = 0;		//�X�V����
	virtual void Draw() = 0;		//�`�揈��
};

#endif // !_TASK_H