#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include <graphics.h>
#include <conio.h>
#include<string.h>
#include<fstream>
#include<map>

#include"Background.h"
#include"BackStu.h"
#include"BackTea.h"
#include"Lesson.h"
#include"LessonStu.h"
#include"LessonTea.h"
#include"Person.h"
#include"PersonStu.h"
#include"PersonTea.h"

#define h(c) c>=0&&c<=9?c:(c-'a'+11)

using namespace std;

map < unsigned long long, unsigned long long> Ms,Mt;
vector <PersonStu> student;
vector<PersonTea> teacher;
const int Seed = 67;
bool change = 1;
int account_type = 12;
unsigned long long ha(string a);

void start();
void getid();
void getcode();
bool check();
bool addaccount();
void GetPerson();
int main()
{
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, ("杨晔嘉的cpp大作业 选课系统"));
	initgraph(1200, 800);
	//GetPerson();
	//start();

	if (account_type == 12) {
		BackStu b;
		//b.setX();
		//Sleep(2000);
		//b.setS();
		//Sleep(2000);
		b.setb();
		
		/*
		while (change) {
			LOGFONT f;
			gettextstyle(&f);
			MOUSEMSG mb;
			mb = GetMouseMsg();
			FlushMouseMsgBuffer();
			switch (mb.uMsg) {
			case WM_LBUTTONUP:
				if (mb.x >= 450 && mb.x <= 750 && mb.y >= 300 && mb.y <= 330) {
					//输入学工号 2021 0013 0164 长度为12位的是学生，教师号码为10位
					getid();
				}
				if (mb.x >= 450 && mb.x <= 750 && mb.y >= 370 && mb.y <= 400) {
					getcode();
				}
				if (mb.x >= 540 && mb.x <= 615 && mb.y >= 490 && mb.y <= 540) {
					fillroundrect(400, 350, 800, 450, 10, 10);
					f.lfHeight = 20;
					settextcolor(RGB(0, 47, 167));
					if (check()) {
						outtextxy(500, 370, "登录中");
						change = 0;
						Sleep(500);
					}
					else {
						outtextxy(420, 370, "用户不存在或密码错误");
						Sleep(500);
						b.setb();
					}
				}
				if (mb.x > 625 && mb.x < 700 && mb.y>490 && mb.y < 540) {
					fillroundrect(400, 350, 800, 450, 10, 10);
					f.lfHeight = 20;
					setfillcolor(WHITE);
					settextcolor(RGB(0, 47, 167));
					if (addaccount()) {
						outtextxy(460, 390, "注册成功,将自动登录");
						change = 0;
						Sleep(2000);
					}
					else {
						outtextxy(460, 370, "用户已存在");
						Sleep(500);
						b.setb();
					}
				}
				break;

			case WM_MOUSEMOVE:
				if (mb.x >= 540 && mb.x <= 615 && mb.y >= 490 && mb.y <= 540) {
					setfillcolor(RGB(211, 211, 211));
					fillrectangle(540, 490, 615, 540);
					outtextxy(550, 500, "登录");
					FlushMouseMsgBuffer();
				}
				else if (mb.x > 625 && mb.x < 700 && mb.y>490 && mb.y < 540) {
					setfillcolor(RGB(211, 211, 211));
					fillrectangle(625, 490, 700, 540);
					outtextxy(635, 500, "注册");
					FlushMouseMsgBuffer();
				}
				else {
					setfillcolor(WHITE);
					fillrectangle(540, 490, 615, 540);
					fillrectangle(625, 490, 700, 540);
					outtextxy(635, 500, "注册");
					outtextxy(550, 500, "登录");
				}
				break;
			}

		}*/
	}
	else if (account_type == 10) {
		BackTea b;
		b.setb();
		Sleep(2000);
		b.setC();
		//Sleep(2000);
		//b.setK();

	}
	while (1);
    return 0;
}

void GetPerson() {
	cin.clear();
	unsigned long long id;
	freopen("Students.txt", "r", stdin);
	while (cin >> id ) {
		cin >> Ms[id];
	}
	cin.clear();
	freopen("Teachers.txt", "r", stdin);
	while (cin >> id ) {
		cin >> Mt[id];
	}
	cin.clear();
}
void start() {
	Background b;
	b.setb();
	while (change) {
		LOGFONT f;
		gettextstyle(&f);
		MOUSEMSG mb;
		mb = GetMouseMsg();
		FlushMouseMsgBuffer();
		switch (mb.uMsg) {
		case WM_LBUTTONUP:
			if (mb.x >= 450 && mb.x <= 750 && mb.y >= 300 && mb.y <= 330) {
				//输入学工号 2021 0013 0164 长度为12位的是学生，教师号码为10位
				getid();
			}
			if (mb.x >= 450 && mb.x <= 750 && mb.y >= 370 && mb.y <= 400) {
				getcode();
			}
			if (mb.x >= 540 && mb.x <= 615 && mb.y >= 490 && mb.y <= 540) {
				fillroundrect(400, 350, 800, 450, 10, 10);
				f.lfHeight = 20;
				settextcolor(RGB(0, 47, 167));
				if (check()) {
					outtextxy(500, 370, "登录中");
					change = 0;
					Sleep(500);
				}
				else {
					outtextxy(420, 370, "用户不存在或密码错误");
					Sleep(500);
					b.setb();
				}
			}
			if (mb.x > 625 && mb.x < 700 && mb.y>490 && mb.y < 540) {
				fillroundrect(400, 350, 800, 450, 10, 10);
				f.lfHeight = 20;
				setfillcolor(WHITE);
				settextcolor(RGB(0, 47, 167));
				if (addaccount()) {
					outtextxy(460, 390, "注册成功,将自动登录");
					change = 0;
					Sleep(2000);
				}
				else {
					outtextxy(460, 370, "用户已存在");
					Sleep(500);
					b.setb();
				}
			}
			break;

		case WM_MOUSEMOVE:
			if (mb.x >= 540 && mb.x <= 615 && mb.y >= 490 && mb.y <= 540) {
				setfillcolor(RGB(211,211,211));
				fillrectangle(540, 490, 615, 540);
				outtextxy(550, 500, "登录");
				FlushMouseMsgBuffer();
			}
			else if (mb.x > 625 && mb.x < 700 && mb.y>490 && mb.y < 540) {
				setfillcolor(RGB(211, 211, 211));
				fillrectangle(625, 490, 700, 540);
				outtextxy(635, 500, "注册");
				FlushMouseMsgBuffer();
			}
			else {
				setfillcolor(WHITE);
				fillrectangle(540, 490, 615, 540);
				fillrectangle(625, 490, 700, 540);
				outtextxy(635, 500, "注册");
				outtextxy(550, 500, "登录");
			}
			break;
		}
		
	}
}
bool addaccount() {
	unsigned long long code, id;
	if(freopen("tempcode.txt", "r", stdin))
		cin >> code;
	cin.clear();
	if(freopen("tempid.txt", "r", stdin))
		cin >> id;
	cin.clear();
	fclose(stdin);
	int len = account_type;
	unsigned long long precode = Ms[id];
	if (len == 12) {
		if (Ms[id])return 0;
		else Ms[id] = code;
		freopen("Students.txt", "a+", stdout);
	}
	else if (len == 10) {
		if (Mt[id])return 0;
		else Mt[id] = code;
		freopen("Teachers.txt", "a+", stdout);
	}
	cout << id << " " << code << endl;
	fclose(stdout);
	return 1;
}
bool check() {	
	unsigned long long code,id;
	cin.clear();
	if(freopen("tempcode.txt", "r", stdin))
		cin >> code;
	cin.clear();
	if(freopen("tempid.txt", "r", stdin))
		cin >> id;
	cin.clear();
	int len = account_type;
	if (len == 10) {
		if (Mt[id] != code)return 0;
		return 1;
	}
	else if (len == 12) {
		if (Ms[id] != code)return 0;
		return 1;
	}
}
void getid() {
	fillrectangle(450, 300, 750, 330);
	setlinecolor(RGB(191, 219, 255));
	setfillcolor(RGB(191, 219, 255));
	fillrectangle(750, 290, 900, 340);
	setfillcolor(WHITE);
	char id[20]; 
	for (int i = 0; i < 20; i++)
		id[i] = '\0';
	int len = 0;
	bool in = 1;
	ExMessage msg;
	LOGFONT out;
	gettextstyle(&out);
	settextstyle(30, 0, "华文宋体");
	outtextxy(450 + len * 15, 298, '|');
	Sleep(100);
	while (in) {
		while (in && peekmessage(&msg, EM_MOUSE | EM_CHAR, 1)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (!(msg.x >= 450 && msg.x <= 750 && msg.y >= 300 && msg.y <= 330)) {//点外面就停止输入
					in = 0;
					break;
				}
			}
			else if (msg.message == WM_CHAR) {
				switch (msg.ch) {
				case '\b':				// 退格删除
					if (len > 0)
					{
						id[--len] = '\0';
						fillrectangle(450, 300, 750, 330);
						settextcolor(BLACK);
						outtextxy(452, 300, id);
					}
					break;
				case '\r':				// 回车结束
				case '\n':
					in = 0;
					break;
				default:
					if (len < 15) {
						id[len++] = msg.ch;
						fillrectangle(450, 300, 750, 330);
						LOGFONT f;
						gettextstyle(&f);
						settextcolor(BLACK);
						outtextxy(452, 300, id);
					}
				}
				Sleep(100);
				outtextxy(450 + len * 13, 298, '|');//光标
			}
		}
	}
	settextcolor(BLACK);
	gettextstyle(&out);
	settextstyle(25, 0, "黑体");
	setlinecolor(WHITE);
	if (len == 12) {
		rectangle(795, 295, 860, 330);
		outtextxy(800, 300, "学生");
		account_type = len;
	}
	else if (len == 10) {
		rectangle(795, 295, 860, 330);
		outtextxy(800, 300, "教师");
		account_type = len;
	}
	else {
		outtextxy(760, 300, "用户不存在");
		return;
	}
	freopen("tempid.txt", "w", stdout);
	cout << ha(id);
	Sleep(500);//做出一个通知的延时效果
	fclose(stdout);
	return;
}
void getcode() {
	char code[20]; 
	for (int i = 0; i < 20; i++)
		code[i] = '\0';
	char oucd[20]; 
	for (int i = 0; i < 20; i++)
		oucd[i] = '\0';
	fillrectangle(450, 370, 750, 400);
	setlinecolor(RGB(191, 219, 255));
	setfillcolor(RGB(191, 219, 255));
	fillrectangle(750, 290, 900, 340);
	setfillcolor(WHITE);
	int len = 0;
	bool in = 1;
	bool look = 1;
	ExMessage msg;
	LOGFONT out;
	gettextstyle(&out);
	settextstyle(30, 0, "华文宋体");
	outtextxy(450 + len * 15, 368, '|');
	Sleep(100);
	while (in) {
		while (in && peekmessage(&msg, EM_MOUSE | EM_CHAR, 1)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if ((msg.x - 770) * (msg.x - 770) + (msg.y - 385) * (msg.y - 385) < 100) {
					LOGFONT f;
					gettextstyle(&f);
					settextcolor(BLACK);
					if (look == 1) {//look=1时意味着看不到
						setfillcolor(BLACK);
						fillcircle(770, 385, 5);
						setfillcolor(WHITE);
						fillrectangle(450, 370, 750, 400);
						look = 0;
						outtextxy(452, 370, code);
					}
					else {
						fillcircle(770, 385, 5);
						fillrectangle(450, 370, 750, 400);
						look = 1;
						outtextxy(452, 370, oucd);
					}
				}
				else if (!(msg.x >= 450 && msg.x <= 750 && msg.y >= 370 && msg.y <= 400)) {//点外面就停止输入
					in = 0;
					break;
				}
			}
			else if (msg.message == WM_CHAR) {
				switch (msg.ch) {
				case '\b':				// 退格删除
					if (len > 0)
					{
						code[--len] = '\0';
						oucd[len] = '\0';
						fillrectangle(450, 370, 750, 400);
						settextcolor(BLACK);
						if (look == 0)outtextxy(452, 370, code);
						else if (look == 1)outtextxy(452, 370, oucd);
					}
					break;
				case '\r':				// 回车结束
				case '\n':
					in = 0;
					break;
				default:
					if (len < 15) {
						code[len++] = msg.ch;
						oucd[len - 1] = '*';
						fillrectangle(450, 370, 750, 400);
						LOGFONT f;
						gettextstyle(&f);
						settextcolor(BLACK);
						if(look==1)outtextxy(452, 370, oucd);
						else if (look == 0) {
							outtextxy(452, 370, code);
						}
					}
				}
				Sleep(100);
				outtextxy(450 + len * 13, 368, '|');
			}
		}
	}
	settextcolor(BLACK);
	gettextstyle(&out);
	settextstyle(25, 0, "黑体");
	setlinecolor(WHITE);
	fclose(stdout);
	freopen("tempcode.txt", "w", stdout);
	int l = strlen(code);
	cout <<ha(code);
	return;
}
unsigned long long ha(string a) {
	unsigned long long re = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		re += h(a[i]);
		re *= Seed;
	}
	re /= Seed;
	return re;
}
