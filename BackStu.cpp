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
	_tcscpy_s(f.lfFaceName, _T("等线"));
	f.lfQuality = PROOF_QUALITY;
	settextstyle(&f);
	outtextxy(480, 20, "选课系统");
	setfillcolor(RGB(191, 219, 255));
	fillroundrect(300, 200, 900, 600, 10, 10);
	setfillcolor(WHITE);
	fillrectangle(450, 300, 750, 330);//学工号
	fillrectangle(450, 370, 750, 400);//密码
	fillrectangle(540, 490, 615, 540);//登录
	fillrectangle(625, 490, 700, 540);//注册
	setlinecolor(BLACK);
	fillcircle(770, 385, 10);
	setlinecolor(WHITE);
	gettextstyle(&f);
	f.lfHeight = 30;
	settextcolor(BLACK);
	_tcscpy_s(f.lfFaceName, _T("华文宋体"));
	settextstyle(&f);
	for (int i = 1; i <= 5; i++) {
		outtextxy(350, 300, "学工号:");
		outtextxy(350, 370, "密码:");
		outtextxy(550, 500, "登录");
		outtextxy(635, 500, "注册");
	}
}

void BackStu::Exit()
{
	//设计为退出当前帐号而不是退出整个程序
}
