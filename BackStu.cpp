#include "BackStu.h"

void BackStu::setb()
{
	IMAGE Background;
	loadimage(NULL, _T("Scene.PNG"), 1200, 800, 0);
	putimage(0, 0, &Background);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 60;
	_tcscpy_s(f.lfFaceName, _T("����"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	outtextxy(480, 20, "ѡ��ϵͳ");
	setfillcolor(RGB(191, 219, 255));
	fillroundrect(300, 200, 900, 600, 10, 10);
	setfillcolor(WHITE);
	fillrectangle(450, 300, 750, 330);//ѧ����
	fillrectangle(450, 370, 750, 400);//����
	fillrectangle(540, 490, 615, 540);//��¼
	fillrectangle(625, 490, 700, 540);//ע��
	setlinecolor(BLACK);
	fillcircle(770, 385, 10);
	setlinecolor(WHITE);
	gettextstyle(&f);
	f.lfHeight = 30;
	settextcolor(BLACK);
	_tcscpy_s(f.lfFaceName, _T("��������"));
	settextstyle(&f);
	for (int i = 1; i <= 5; i++) {
		outtextxy(350, 300, "ѧ����:");
		outtextxy(350, 370, "����:");
		outtextxy(550, 500, "��¼");
		outtextxy(635, 500, "ע��");
	}
}

void BackStu::Exit()
{
	//���Ϊ�˳���ǰ�ʺŶ������˳���������
}
