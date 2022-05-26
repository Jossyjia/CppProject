#include <iostream>
#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
#include <graphics.h>
#include <conio.h>
#include<fstream>

#include"Background.h"
#include"Lesson.h"
#include"LessonStu.h"
#include"LessonTea.h"
#include"Person.h"
#include"PersonStu.h"
#include"PersonTea.h"


using namespace std;
vector <PersonStu> student;
vector<PersonTea> teacher;
bool change = 1;
void getid();
void getcode();
bool check();
bool addaccount();
int main()
{
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
					Sleep(50);
				}
				else {
					outtextxy(420, 370, "用户不存在或密码错误");
					Sleep(100);
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
					Sleep(50);
					Sleep(2000);
				}
				else {
					outtextxy(450, 370, "用户已存在");
					Sleep(100);
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

    return 0;
}

bool addaccount() {
	string code, id;
	if(freopen("tempcode.txt", "r", stdin))
		cin >> code;
	cin.clear();
	freopen("tempid.txt", "r", stdin);
	cin >> id;
	cin.clear();
	int len = id.length();
	if (len == 12)freopen("Students.txt", "r", stdin);
	else if (len == 10)freopen("Teacher.txt", "r", stdin);
	
	string all[2];
	while (cin >> all[0] >> all[1]) {
		if (all[0] == id) {
			return 0;
		}
	}
	fclose(stdin);
	if (len == 12)freopen("Students.txt", "a+", stdout);
	else if (len == 10)freopen("Teacher.txt", "a+", stdout);
	cout << id << " " << code << endl;
	return 1;
}
bool check() {	
	string code,id;
	freopen("tempcode.txt", "r", stdin);
	cin >> code;
	freopen("tempid.txt", "r", stdin);
	cin >> id;
	int len = id.length();
	if (len == 10)freopen("Students.txt", "r", stdin);
	else if (len == 12)freopen("Teacher.txt", "r", stdin);
	int n;
	cin >> n;
	string all[2];
	for (int i = 1; i <= n; i++) {
		cin >> all[0] >> all[1];
		if (all[0] == id) {
			if (all[1] == code) {
				return 1;
			}
			else break;
		}
	}
	return 0;
}
void getid() {
	fillrectangle(450, 300, 750, 330);
	setlinecolor(RGB(191, 219, 255));
	setfillcolor(RGB(191, 219, 255));
	fillrectangle(750, 290, 900, 340);
	setfillcolor(WHITE);
	char id[20]; for (int i = 0; i < 20; i++)id[i] = '\0';
	//char* id;
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
				outtextxy(450 + len * 13, 298, '|');
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
	}
	else if (len == 10) {
		rectangle(795, 295, 860, 330);
		outtextxy(800, 300, "教师");
	}
	else {
		outtextxy(760, 300, "用户不存在");
	}
	freopen("tempid.txt", "w", stdout);
	cout << id;
	Sleep(100);
	return;
}
void getcode() {
	char code[20]; for (int i = 0; i < 20; i++)code[i] = '\0';
	char oucd[20]; for (int i = 0; i < 20; i++)oucd[i] = '\0';
	fillrectangle(450, 370, 750, 400);
	setlinecolor(RGB(191, 219, 255));
	setfillcolor(RGB(191, 219, 255));
	fillrectangle(750, 290, 900, 340);
	setfillcolor(WHITE);
	int len = 0;
	bool in = 1,look=1;
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
	cout << code;
	return;
}