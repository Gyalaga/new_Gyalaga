#ifndef _SCORE_H_
#define _SCORE_H_

static int score = 0;                            //�X�R�A
static int h_score = 0;                          //�n�C�X�R�A
static char String[256];                         //�ۑ��ϐ�
static int scorex = 950, scorey = 200;           //�X�R�A�v�Z�̍��W
static int h_scorex = 950, h_scorey = 90;        //�n�C�X�R�A�v�Z���W        
static int count = 0;                             //�_��
static int FileHandle;                           //�t�@�C��

//�X�V
void Score_Update();

//�`��
void Score_Draw();
	
//�ۑ�
void Score_Save();

//�^�C�g����ʃX�R�A
void Score_Title();

#endif