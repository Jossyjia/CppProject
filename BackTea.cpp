#include "BackTea.h"

void BackTea::setb()
{
	IMAGE Background, Photo;
	loadimage(&Background, _T("Long.jpg"), 1200, 800, 0);
	putimage(0, 0, &Background);
	loadimage(&Photo, _T("��è.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("��������"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	outtextxy(20, 175, "����:��è");
	outtextxy(20, 255, "�ҵĿα�");
	outtextxy(50, 335, "����");
	outtextxy(20, 415, "ѧ���ɼ�");
	outtextxy(20, 495, "������Ϣ");
	
	setfillcolor(BLACK);
	fillroundrect(40, 715, 110, 755, 5, 5);
	outtextxy(50, 720, "�˳�");
	setlinecolor(WHITE);
	rectangle(0, 0, 150, 800);
	rectangle(180, 25, 1175, 775);

	outtextxy(190 + 80 + 135 * 0, 25, "��һ");//tchar�����漰������ת��������
	outtextxy(190 + 80 + 135 * 1, 25, "�ܶ�");
	outtextxy(190 + 80 + 135 * 2, 25, "����");
	outtextxy(190 + 80 + 135 * 3, 25, "����");
	outtextxy(190 + 80 + 135 * 4, 25, "����");
	outtextxy(190 + 80 + 135 * 5, 25, "����");
	outtextxy(190 + 80 + 135 * 6, 25, "����");
	gettextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("Bodoni MT Black"));
	settextstyle(&f);
	outtextxy(200, 100 + 140 * 0, "1");
	outtextxy(200, 100 + 140 * 1, "2");
	outtextxy(200, 400 + 140 * 0, "3");
	outtextxy(200, 400 + 140 * 1, "4");
	outtextxy(200, 680, "5");
	for (int i = 0; i <= 6; i++) {
		rectangle(160 + 70 + 135 * i, 25, 160 + 70 + 135 * (i + 1), 55);
		for (int j = 0; j <= 1; j++) {
			rectangle(160 + 70 + 135 * i, 55 + 140 * j, 160 + 70 + 135 * (i + 1), 55 + 140 * (j + 1));
			rectangle(180, 55 + 140 * j, 230, 55 + 140 * (j + 1));
			rectangle(160 + 70 + 135 * i, 345 + 140 * j, 160 + 70 + 135 * (i + 1), 345 + 140 * (j + 1));
			rectangle(180, 345 + 140 * j, 230, 345 + 140 * (j + 1));
		}
		rectangle(160 + 70 + 135 * i, 635, 160 + 70 + 135 * (i + 1), 635 + 140);
	}
	
	rectangle(180, 635, 230, 635 + 140);
	rectangle(25, 25, 125, 125);
	for (int i = 0; i < 4; i++) {
		rectangle(0, 150 + 80 * i, 150, 230 + 80 * (i + 1));
	}

}


