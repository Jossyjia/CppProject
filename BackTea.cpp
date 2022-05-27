#include "BackTea.h"

void BackTea::setb()
{
	IMAGE Background, Photo;
	loadimage(&Background, _T("Long.jpg"), 1200, 800, 0);
	putimage(0, 0, &Background);
	loadimage(&Photo, _T("龙猫.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("华文宋体"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	outtextxy(20, 175, "姓名:龙猫");

	for (int i = 0; i < 3; i++) {
		rectangle(0, 150 + 80 * i, 150, 230 + 80 * (i + 1));
	}
	outtextxy(20, 255, "我的课表");
	outtextxy(50, 335, "开课");
	outtextxy(20, 415, "学生成绩");
	
	setfillcolor(BLACK);
	fillroundrect(40, 715, 110, 755, 5, 5);
	outtextxy(50, 720, "退出");
	setlinecolor(WHITE);
	rectangle(0, 0, 150, 800);
	rectangle(180, 25, 1175, 775);

	outtextxy(190 + 80 + 135 * 0, 25, "周一");//tchar类型涉及到互相转化的问题
	outtextxy(190 + 80 + 135 * 1, 25, "周二");
	outtextxy(190 + 80 + 135 * 2, 25, "周三");
	outtextxy(190 + 80 + 135 * 3, 25, "周四");
	outtextxy(190 + 80 + 135 * 4, 25, "周五");
	outtextxy(190 + 80 + 135 * 5, 25, "周六");
	outtextxy(190 + 80 + 135 * 6, 25, "周日");
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

}

void BackTea::setK()
{

	IMAGE Background, Photo;
	loadimage(&Background, _T("Long.jpg"), 1200, 800, 0);
	putimage(0, 0, &Background);
	loadimage(&Photo, _T("龙猫.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	rectangle(25, 25, 125, 125);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("华文宋体"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	outtextxy(20, 175, "姓名:龙猫");

	for (int i = 0; i < 3; i++) {
		rectangle(0, 150 + 80 * i, 150, 230 + 80 * (i + 1));
	}
	outtextxy(20, 255, "我的课表");
	outtextxy(50, 335, "开课");
	outtextxy(20, 415, "学生成绩");

	setfillcolor(BLACK);
	fillroundrect(40, 715, 110, 755, 5, 5);
	outtextxy(50, 720, "退出");
	setlinecolor(WHITE);
	rectangle(0, 0, 150, 800);

	for (int i = 0; i <= 6; i++)
		rectangle(160 + 170 + 100 * i, 25, 160 + 170 + 100 * (i + 1), 55);
	for (int i = 0; i <= 4; i++)
		rectangle(160 + 170 + 100 * i, 60, 160 + 170 + 100 * (i + 1), 90);
	for (int i = 0; i <= 1; i++) {
		rectangle(160 + 170 + 100 * i, 100, 160 + 170 + 100 * (i + 1), 130);
		rectangle(160 + 670 + 100 * i, 100, 160 + 670 + 100 * (i + 1), 130);
	}


	outtextxy(220, 25, "周次");
	outtextxy(220, 60, "节次");
	outtextxy(220, 100, "学分");
	outtextxy(650, 100, "是否选修");	
	outtextxy(200, 150, "课程名称"); 
	setfillcolor(DARKGRAY);
	fillrectangle(330, 150, 800, 180); 
	setfillcolor(BLACK);
	outtextxy(170 + 180 + 100 * 0, 25, "周一");//tchar类型涉及到互相转化的问题
	outtextxy(170 + 180 + 100 * 1, 25, "周二");
	outtextxy(170 + 180 + 100 * 2, 25, "周三");
	outtextxy(170 + 180 + 100 * 3, 25, "周四");
	outtextxy(170 + 180 + 100 * 4, 25, "周五");
	outtextxy(170 + 180 + 100 * 5, 25, "周六");
	outtextxy(170 + 180 + 100 * 6, 25, "周日");
	gettextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("Bodoni MT Black"));
	settextstyle(&f);
	outtextxy(375, 60, "1"); outtextxy(375, 100, "1"); outtextxy(870, 100, "是");
	outtextxy(475, 60, "2"); outtextxy(475, 100, "2"); outtextxy(970, 100, "否");
	outtextxy(575, 60, "3");
	outtextxy(675, 60, "4");
	outtextxy(775, 60, "5");
	outtextxy(225, 255, "周"); outtextxy(295, 255, "节"); outtextxy(350, 255, "学分"); outtextxy(420, 255, "选修");
	outtextxy(490, 255, "最多"); outtextxy(560, 255, "当前"); outtextxy(660, 255, "教师"); outtextxy(840, 255, "课程名称");
	for (int i = 1; i <= 8; i++) {
		for (int j = 0; j <= 5; j++) {
			rectangle(200 + j * 70, 180 + 60 * i, 270 + j * 70, 240 + 60 * i);
		}
		rectangle(620, 180 + 60 * i, 750, 240 + 60 * i);
		rectangle(750, 180 + 60 * i, 1050, 240 + 60 * i);
	}

}

void BackTea::setC()
{
	IMAGE Background, Photo;
	loadimage(&Background, _T("Long.jpg"), 1200, 800, 0);
	putimage(0, 0, &Background);
	loadimage(&Photo, _T("龙猫.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	rectangle(25, 25, 125, 125);
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("华文宋体"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	outtextxy(20, 175, "姓名:龙猫");

	for (int i = 0; i < 3; i++) {
		rectangle(0, 150 + 80 * i, 150, 230 + 80 * (i + 1));
	}
	outtextxy(20, 255, "我的课表");
	outtextxy(50, 335, "开课");
	outtextxy(20, 415, "学生成绩");

	setfillcolor(BLACK);
	fillroundrect(40, 715, 110, 755, 5, 5);
	outtextxy(50, 720, "退出");
	setlinecolor(WHITE);
	rectangle(0, 0, 150, 800);
	outtextxy(200, 80, "课程名：");
	for (int i = 0; i <= 3; i+=1) {//列
		for (int j = 0; j <= 8; j++) {//行
			rectangle(200 + i * 220, 120 + j * 60, 350 + i * 220, 180 + j * 60);
			rectangle(200 + i * 220, 120 + j * 60, 420 + i * 220, 180 + j * 60);
		}
	}
}


