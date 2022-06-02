#include "BackStu.h"

void BackStu::resetP()
{
	loadimage(&Photo, _T("Photos\\白龙.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
}

void BackStu::setb()
{
	
	loadimage(&Background, _T("Photos\\Qian.jpg"), 1200, 800, 0);
	putimage(0, 0, &Background);
	loadimage(&Photo, _T("Photos\\千寻.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	if (gender == 0)
		resetP();
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("华文宋体"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	if(gender)
		outtextxy(20,175,"姓名:千寻");
	else 
		outtextxy(20, 175, "姓名:白龙");
	outtextxy(20, 255, "我的课表");
	outtextxy(50, 335, "选课");
	//outtextxy(50, 415, "成绩");
	outtextxy(50, 720, "退出");
	roundrect(40, 715, 110, 755,5,5);
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
		rectangle(160+70 + 135 * i, 25, 160+70 + 135 * (i+1), 55);//周一到周日
		for (int j = 0; j <= 1; j++) {
			rectangle(160+70 + 135 * i, 55 + 140 * j, 160+70 + 135 * (i + 1), 55 + 140 * (j + 1));//第一二节
			rectangle(180, 55 + 140 * j, 230, 55 + 140 * (j + 1));
			rectangle(160+70 + 135 * i, 345 + 140 * j, 160+70 + 135 * (i + 1), 345 + 140 * (j + 1));//第二三节
			rectangle(180, 345 + 140 * j, 230, 345 + 140 * (j + 1));
		}
		rectangle(160+70 + 135 * i, 635 , 160+70 + 135 * (i + 1), 635 + 140 );//第五节
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
	loadimage(&Photo, _T("Photos\\千寻.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	if (gender == 0)
		resetP();
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("华文宋体"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	if (gender)
		outtextxy(20, 175, "姓名:千寻");
	else
		outtextxy(20, 175, "姓名:白龙");
	for (int i = 0; i < 2; i++) {
		rectangle(0, 150 + 80 * i, 150, 230 + 80 * (i + 1));
	}
	outtextxy(20, 255, "我的课表");
	outtextxy(50, 335, "选课");
	//outtextxy(50, 415, "成绩");
	outtextxy(50, 720, "退出");
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
		

	outtextxy(220, 25, "周次");
	outtextxy(220, 60, "节次");
	outtextxy(220, 100, "学分");
	outtextxy(650, 100, "是否选修");	outtextxy(1080, 195, "选择");
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
	outtextxy(225, 195, "周"); outtextxy(295, 195, "节"); outtextxy(350, 195, "学分"); outtextxy(420, 195, "选修");
	outtextxy(490, 195, "最多"); outtextxy(560, 195, "当前"); outtextxy(660, 195, "教师"); outtextxy(840, 195, "课程名称");
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
	loadimage(&Photo, _T("Photos\\千寻.jpg"), 100, 100, 0);
	putimage(25, 25, &Photo);
	if (gender == 0)
		resetP();
	setbkmode(TRANSPARENT);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("华文宋体"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	settextcolor(WHITE);
	if (gender)
		outtextxy(20, 175, "姓名:千寻");
	else
		outtextxy(20, 175, "姓名:白龙");
	outtextxy(20, 255, "我的课表");
	outtextxy(50, 335, "选课");
	outtextxy(50, 415, "成绩");
	outtextxy(50, 720, "退出");
	roundrect(40, 715, 110, 755, 5, 5);
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

