#ifndef _Player_h_
#define _Player_h_

typedef struct
{
	int x[16] = { 400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400 };
	int y[16] = { 700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700 };
	//  width:‘, height:c, center:S
	int width = 32, height = 32, center = width / 2;
	//  mode:  0_Κν ,1_ί ,2_fA[h
	int mode = 0;
	//\¦tO
	bool flg = false;
}PLAYER;

//PlayerΜSΜΗ
void Player_All();



#endif