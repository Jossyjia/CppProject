#include "BackStu.h"

void BackStu::setb()
{
	IMAGE Background;
	loadimage(NULL, _T("Qian.jpg"), 1200, 800, 0);
	//loadimage(NULL, _T("Scene.PNG"), 1200, 800, 0);
	putimage(0, 0, &Background);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 60;
	_tcscpy_s(f.lfFaceName, _T("华文宋体"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);

	setlinecolor(WHITE);
	rectangle(0, 0, 100, 800);
	rectangle(160, 25, 1175, 775);
	for (int i = 0; i <= 6; i++) {
		rectangle(160+70 + 135 * i, 25, 160+70 + 135 * (i+1), 55);
		for (int j = 0; j <= 1; j++) {
			rectangle(160+70 + 135 * i, 55 + 140 * j, 160+70 + 135 * (i + 1), 55 + 140 * (j + 1));
			rectangle(160+70 + 135 * i, 345 + 140 * j, 160+70 + 135 * (i + 1), 345 + 140 * (j + 1));
		}
		rectangle(160+70 + 135 * i, 635 , 160+70 + 135 * (i + 1), 635 + 140 );
			
	}
	
}

void BackStu::Exit()
{
	//设计为退出当前帐号而不是退出整个程序
}
