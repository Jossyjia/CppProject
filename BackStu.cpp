#include "BackStu.h"

void BackStu::resetP()
{
	loadimage(&Photo, _T("Photos\\����.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
}

void BackStu::setb()
{
	
	loadimage(&Background, _T("Photos\\Qian.jpg"), 1200, 800, 0);
	putimage(0, 0, &Background);
	loadimage(&Photo, _T("Photos\\ǧѰ.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	if (gender == 0)
		resetP();
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("��������"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	if(gender)
		outtextxy(20,175,"����:ǧѰ");
	else 
		outtextxy(20, 175, "����:����");
	outtextxy(20, 255, "�ҵĿα�");
	outtextxy(50, 335, "ѡ��");
	//outtextxy(50, 415, "�ɼ�");
	outtextxy(50, 720, "�˳�");
	roundrect(40, 715, 110, 755,5,5);
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
		rectangle(160+70 + 135 * i, 25, 160+70 + 135 * (i+1), 55);//��һ������
		for (int j = 0; j <= 1; j++) {
			rectangle(160+70 + 135 * i, 55 + 140 * j, 160+70 + 135 * (i + 1), 55 + 140 * (j + 1));//��һ����
			rectangle(180, 55 + 140 * j, 230, 55 + 140 * (j + 1));
			rectangle(160+70 + 135 * i, 345 + 140 * j, 160+70 + 135 * (i + 1), 345 + 140 * (j + 1));//�ڶ�����
			rectangle(180, 345 + 140 * j, 230, 345 + 140 * (j + 1));
		}
		rectangle(160+70 + 135 * i, 635 , 160+70 + 135 * (i + 1), 635 + 140 );//�����
	}
	rectangle(180, 635, 230, 635 + 140);
	rectangle(25, 25, 125, 125);
	for (int i = 0; i <2; i++) {
		rectangle(0, 150+80*i, 150, 230+80*(i+1));
	}
	
}

void BackStu::setX()
{
	loadimage(&Background, _T("Photos\\Qian.jpg"), 1200, 800, 0);
	putimage(0, 0, &Background);
	loadimage(&Photo, _T("Photos\\ǧѰ.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	if (gender == 0)
		resetP();
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("��������"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	if (gender)
		outtextxy(20, 175, "����:ǧѰ");
	else
		outtextxy(20, 175, "����:����");
	for (int i = 0; i < 2; i++) {
		rectangle(0, 150 + 80 * i, 150, 230 + 80 * (i + 1));
	}
	outtextxy(20, 255, "�ҵĿα�");
	outtextxy(50, 335, "ѡ��");
	//outtextxy(50, 415, "�ɼ�");
	outtextxy(50, 720, "�˳�");
	roundrect(40, 715, 110, 755, 5, 5);
	setlinecolor(WHITE);
	rectangle(0, 0, 150, 800);

	for (int i = 0; i <= 6; i++) 
		rectangle(160 + 170 + 100 * i, 25, 160 + 170 + 100 * (i + 1), 55);
	for(int i=0;i<=4;i++)
		rectangle(160 + 170 + 100 * i, 60, 160 + 170 + 100 * (i + 1), 90);
	for (int i = 0; i <= 1; i++) {
		rectangle(160 + 170 + 100 * i, 100, 160 + 170 + 100 * (i + 1), 130);
		rectangle(160 + 670 + 100 * i, 100, 160 + 670 + 100 * (i + 1), 130);
	}
		

	outtextxy(220, 25, "�ܴ�");
	outtextxy(220, 60, "�ڴ�");
	outtextxy(220, 100, "ѧ��");
	outtextxy(650, 100, "�Ƿ�ѡ��");	outtextxy(1080, 195, "ѡ��");
	outtextxy(170 + 180 + 100 * 0, 25, "��һ");//tchar�����漰������ת��������
	outtextxy(170 + 180 + 100 * 1, 25, "�ܶ�");
	outtextxy(170 + 180 + 100 * 2, 25, "����");
	outtextxy(170 + 180 + 100 * 3, 25, "����");
	outtextxy(170 + 180 + 100 * 4, 25, "����");
	outtextxy(170 + 180 + 100 * 5, 25, "����");
	outtextxy(170 + 180 + 100 * 6, 25, "����");
	gettextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("Bodoni MT Black"));
	settextstyle(&f);
	outtextxy(375, 60, "1"); outtextxy(375, 100, "1"); outtextxy(870, 100, "��");
	outtextxy(475, 60, "2"); outtextxy(475, 100, "2"); outtextxy(970, 100, "��");
	outtextxy(575, 60, "3");
	outtextxy(675, 60, "4");
	outtextxy(775, 60, "5");
	outtextxy(225, 195, "��"); outtextxy(295, 195, "��"); outtextxy(350, 195, "ѧ��"); outtextxy(420, 195, "ѡ��");
	outtextxy(490, 195, "���"); outtextxy(560, 195, "��ǰ"); outtextxy(660, 195, "��ʦ"); outtextxy(840, 195, "�γ�����");
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 5; j++) {
			rectangle(200+j*70, 180 + 60 * i, 270+j*70, 240 + 60 * i);
		}
		rectangle(620, 180 + 60 * i, 750, 240 + 60 * i);
		rectangle(750, 180 + 60 * i, 1050, 240 + 60 * i);
		rectangle(1050, 180 + 60 * i, 1150, 240 + 60 * i);
	}

}

void BackStu::setS()
{
	loadimage(&Background, _T("Photos\\Qian.jpg"), 1200, 800, 0);
	putimage(0, 0, &Background);
	loadimage(&Photo, _T("Photos\\ǧѰ.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	if (gender == 0)
		resetP();
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("��������"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	if (gender)
		outtextxy(20, 175, "����:ǧѰ");
	else
		outtextxy(20, 175, "����:����");
	outtextxy(20, 255, "�ҵĿα�");
	outtextxy(50, 335, "ѡ��");
	outtextxy(50, 415, "�ɼ�");
	outtextxy(50, 720, "�˳�");
	roundrect(40, 715, 110, 755, 5, 5);
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
			rectangle(160 + 70 + 135 * i, 55 + 70 * j, 160 + 70 + 135 * (i + 1), 55 + 70 * (j + 1));
			rectangle(160 + 70 + 135 * i, 55 + 70 * (j+2), 160 + 70 + 135 * (i + 1), 55 + 70 * (j + 3));
			rectangle(180, 55 + 140 * j, 230, 55 + 140 * (j + 1));
			rectangle(160 + 70 + 135 * i, 345 + 140 * j, 160 + 70 + 135 * (i + 1), 345 + 140 * (j + 1));
			rectangle(160 + 70 + 135 * i, 345 +70+ 140 * j, 160 + 70 + 135 * (i + 1), 345 + 70+140 * (j + 1));
			rectangle(180, 345 + 140 * j, 230, 345 + 140 * (j + 1));
		}
		rectangle(160 + 70 + 135 * i, 635, 160 + 70 + 135 * (i + 1), 635 + 140);
		rectangle(160 + 70 + 135 * i, 635+70, 160 + 70 + 135 * (i + 1), 635 + 140);
	}
	rectangle(180, 635, 230, 635 + 140);
	rectangle(25, 25, 125, 125);
	for (int i = 0; i < 3; i++) {
		rectangle(0, 150 + 80 * i, 150, 230 + 80 * (i + 1));
	}
}

