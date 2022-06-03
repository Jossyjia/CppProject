#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include <graphics.h>
#include <conio.h>
#include<stdlib.h>
#include<shellapi.h>
#include<string.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<Python.h>
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

#pragma comment(lib,"Imm32.lib")

#define h(c) c>=0&&c<=9?c:(c-'a'+11)
#define inf 0x7f7f7f7f
using namespace std;

vector<LessonStu> allLesson;//必须用excel保存！excel是gbk读入也是gbk 而vsc用utf8
map < unsigned long long, unsigned long long> Ms,Mt;//存储账号密码，登陆用
map< unsigned long long, PersonStu> Stusaved;//存储账号对应的课表
map< unsigned long long, PersonTea> Teasaved;
const int Seed = 67;
bool change = 1;
int account_type = 10,all=0;
unsigned long long ha(string a);
void start();
void getid();
void getcode();
bool check();
bool addaccount();
void GetPerson();
void SetLesson(LessonStu a,int n);
void GetLesson();
void OutLessonT(unsigned long long id);
void OutLessonS(unsigned long long id);
void picklessons(PersonStu *p);
void show(int t, int num);
void py();
void beginclasses(PersonTea *p);
string getname();
string gettea();
void GetIMEString(HWND hWnd, string &str);
int main()
{
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, ("杨晔嘉的cpp大作业 选课系统"));
	initgraph(1200, 800);
	GetLesson();
	GetPerson();
	//start();
	unsigned long long ii = 0, cc = 0;
	cin.clear();
	if (freopen("tempcode.txt", "r", stdin))
		cin >>cc;
	cin.clear();
	if (freopen("tempid.txt", "r", stdin))
		cin >> ii;
	cin.clear();
	fclose(stdin);
	if (account_type == 12) {
		BackStu b;
		b.setb();
		PersonStu p = Stusaved[ii];
		p.setcode(cc);
		p.setid(ii);	
		p.lookschedule();
		while (change) {
			LOGFONT f;
			gettextstyle(&f);
			MOUSEMSG mb;
			mb = GetMouseMsg();
			FlushMouseMsgBuffer();
			switch (mb.uMsg) {
			case WM_LBUTTONUP:
				if (mb.x >=0 && mb.x <= 150 && mb.y >= 230 && mb.y < 310) {
					b.setb();
					p.lookschedule();
				}
				if (mb.x >= 0 && mb.x <= 150 && mb.y >= 310 && mb.y < 390) {
					b.setX();
					picklessons(&p);
				}
				if (mb.x >= 0 && mb.x <= 150 && mb.y >= 390 && mb.y <= 470) {
					b.setS();
					/*
					是想实现但是由于时间问题并没有实现的功能，具体设想如下：
					由于要存储的是每个学生对应课程的分数，那么会用到map<unsigned long long, <int,int> > 
					（好像用multimap也可以？我没有这样用过，具体实现的时候会查明白的
					然后就是make_pair<课程编号和成绩>
					看分数的时候通过id-》课程编号-》具体课程的名字-》时间和分数
					（需要在LessonStu里写一个专门的printf函数，上层是名字下层是score）
					当然如果能用到MySQL就更好了
					*/
				}
				if (mb.x >= 40 && mb.x <= 110 && mb.y >= 715 && mb.y <= 755) {
					OutLessonS(p.Getid());
					fillroundrect(400, 350, 800, 450, 10, 10);
					f.lfHeight = 50;
					settextstyle(&f);
					setfillcolor(WHITE);
					settextcolor(BLACK);
					outtextxy(450, 375, "安全退出选课中..");
					Sleep(2000); exit(0);
				}

				break;
				
			}//switch

		}//which
	}
	else if (account_type == 10) {
		BackTea b;
		b.setb();
		PersonTea p = Teasaved[ii];
		p.setcode(cc);
		p.setid(ii);
		p.lookschedule();
		change = 1;
		while (change) {
			LOGFONT f;
			gettextstyle(&f);
			MOUSEMSG mb;
			mb = GetMouseMsg();
			FlushMouseMsgBuffer();
			switch (mb.uMsg) {
			case WM_LBUTTONUP:
				if (mb.x >= 0 && mb.x <= 150 && mb.y >= 230 && mb.y < 310) {
					b.setb();
					p.lookschedule();
				}
				if (mb.x >= 0 && mb.x <= 150 && mb.y >= 310 && mb.y < 390) {
					b.setK();
					beginclasses(&p);
					fillcircle(300, 300, 50);
				}
				if (mb.x >= 0 && mb.x <= 150 && mb.y >= 390 && mb.y <= 470) {
					b.setC();
				}
				if (mb.x >= 40 && mb.x <= 110 && mb.y >= 715 && mb.y <= 755) {
					OutLessonS(p.Getid());
					fillroundrect(400, 350, 800, 450, 10, 10);
					f.lfHeight = 50;
					settextstyle(&f);
					setfillcolor(WHITE);
					settextcolor(BLACK);
					outtextxy(450, 375, "安全退出选课中..");
					Sleep(2000); exit(0);
				}

				break;

			}//switch
		}
	}
	while (1);
    return 0;
}

void GetIMEString(HWND hWnd, string& str)
{
	HIMC hIMC = ImmGetContext(hWnd);//获取HIMC 
	if (hIMC) {
		static bool flag = false;
		DWORD dwSize = ImmGetCompositionStringW(hIMC, GCS_COMPSTR, NULL, 0);
		if (dwSize > 0) {
			if (flag == false)
			{
				flag = true;
			}
		}
		else if (dwSize == 0 && flag) {
			int iSize;
			LPSTR pszMultiByte = NULL;
			int ChineseSimpleAcp = 936;
			WCHAR* lpWideStr = NULL;
			dwSize = ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, NULL, 0);
			if (dwSize > 0) {
				dwSize += sizeof(WCHAR);
				if (lpWideStr) {
					delete[]lpWideStr;
					lpWideStr = NULL;
				}
				lpWideStr = new WCHAR[dwSize];
				memset(lpWideStr, 0, dwSize);
				ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, lpWideStr, dwSize);
				iSize = WideCharToMultiByte(ChineseSimpleAcp, 0, lpWideStr, -1, NULL, 0, NULL, NULL);
				if (pszMultiByte) {
					delete[] pszMultiByte;
					pszMultiByte = NULL;
				}
				pszMultiByte = new char[iSize + 1];
				WideCharToMultiByte(ChineseSimpleAcp, 0, lpWideStr, -1, pszMultiByte, iSize, NULL, NULL);
				pszMultiByte[iSize] = '\0';
				str += pszMultiByte;
				if (lpWideStr) {
					delete[]lpWideStr;
					lpWideStr = NULL;
				}
				if (pszMultiByte) {
					delete[] pszMultiByte;
					pszMultiByte = NULL;
				}
			}
			flag = false;
		}
		ImmReleaseContext(hWnd, hIMC);
	}
}
string getname() {
	HWND hWnd = GetHWnd();
	BeginBatchDraw(); 
	string str;
	while (true){
		if (_kbhit()){
			char c = _getch();
			if (c == '\b'){
				if (str.length() > 0){
					if (str.at(str.length() - 1) & 0x8000)
						str.erase(str.end() - 1);
					str.erase(str.end() - 1);
				}
			}
			else if (c == 27||c=='\r'||c=='\n') {
				outtextxy(332, 148, str.c_str());
				return str;
			}
			else {
				str += c;
			}
		}
		else {
			GetIMEString(hWnd, str);
		}
		if (str.length() > 100)
			str = ""; 
		setfillcolor(DARKGRAY);
		fillrectangle(330, 148, 700, 182);
		outtextxy(332,148, str.c_str());
		FlushBatchDraw();
	}
	return str;
}
string gettea() {
	
	HWND hWnd = GetHWnd();
	BeginBatchDraw();
	string str;
	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (c == '\b') {
				if (str.length() > 0) {
					if (str.at(str.length() - 1) & 0x8000)
						str.erase(str.end() - 1);
					str.erase(str.end() - 1);
				}
			}
			else if (c == 27 || c == '\r' || c == '\n') {
				outtextxy(832, 148, str.c_str());
				return str;
			}
			else {
				str += c;
			}
		}
		else {
			GetIMEString(hWnd, str);
		}
		if (str.length() > 100)
			str = "";
		setfillcolor(DARKGRAY);
		fillrectangle(830, 148, 1030, 182);
		outtextxy(832, 148, str.c_str());
		FlushBatchDraw();
	}
	
	return str;
}
void py() {
	Py_Initialize();
	int k = Py_IsInitialized();
	if (Py_IsInitialized()) {

		FILE* fp = NULL;
		fp = fopen("picking.py", "r");
		if (fp == NULL)return;
		PyRun_SimpleFile(fp, "picking.py");
	/*	//PyObject* pMod = PyImport_ImportModule("picking");
		PyObject* pModule = NULL;
		PyObject* pFunc = NULL;
		pModule = PyImport_ImportModule("picking");
		if (pModule) {
			pFunc = PyObject_GetAttrString(pModule, "work");
			PyEval_CallObject(pFunc, NULL);
		}*/

	}
	Py_Finalize();
}
void show(int t, int num) {
	LessonStu a;
	num--;
	if (t - 1 >= 0 && t - 1 < allLesson.size())a = allLesson[t - 1];
	else return;
	//a=allLesson[t-1];
	char k = 'a';
	char* p = new char[30];
	_itoa(a.time.weekday, p, 10);
	outtextxy(230, 250 + 60 * num, p);
	*p = k;
	_itoa(a.time.order, p, 10);
	outtextxy(300, 250 + 60 * num, p);
	*p = k;
	_itoa(a.credit, p, 10);
	outtextxy(380, 250 + 60 * num, p);
	*p = k;
	if (a.type) {
		outtextxy(420, 250 + 60 * num, "否");
	}
	else {
		outtextxy(420, 250+60 * num, "是");
	}
	_itoa(a.maxstu, p, 10);
	outtextxy(500, 250 + 60 * num, p);
	*p = k;
	_itoa(a.nowstu, p, 10);
	outtextxy(565, 250 + 60 * num, p);
	*p = k;
	string box = a.Tea;
	strcpy(p, box.c_str());
	outtextxy(630, 250 + 60 * num, p);
	box = a.Name;
	strcpy(p, box.c_str());
	outtextxy(760, 250 + 60 * num, p);
}
void beginclasses(PersonTea *p) {
	int week = inf, type = inf, maxstu = 30, credit = inf, order = inf;
	string name, tea;
	while (change) {
		LOGFONT f;
		gettextstyle(&f);
		MOUSEMSG mb;
		mb = GetMouseMsg();
		FlushMouseMsgBuffer();
		switch (mb.uMsg) {
		case WM_LBUTTONUP:
			if (mb.x >= 0 && mb.x <= 150 && mb.y >= 230 && mb.y < 310) {
				return;
			}
			if (mb.x >= 0 && mb.x <= 150 && mb.y >= 310 && mb.y < 390) {
				return;
			}

			if (mb.x >= 40 && mb.x <= 110 && mb.y >= 715 && mb.y <= 755) {
				OutLessonS(p->Getid());
				fillroundrect(400, 350, 800, 450, 10, 10);
				f.lfHeight = 50;
				settextstyle(&f);
				setfillcolor(WHITE);
				settextcolor(BLACK);
				outtextxy(450, 375, "安全退出选课中..");
				Sleep(2000); exit(0);
			}

			if (mb.y >= 25 && mb.y <= 55) {
				setlinecolor(WHITE);
				for (int i = 0; i <= 6; i++)
					rectangle(160 + 170 + 100 * i, 25, 160 + 170 + 100 * (i + 1), 55);
				setlinecolor(DARKGRAY);
				if (mb.x >= 330 && mb.x <= 430) {
					rectangle(330, 25, 430, 55);
					week = Mon;
				}
				if (mb.x > 430 && mb.x < 530) {
					rectangle(430, 25, 530, 55);
					week = Tue;
				}
				if (mb.x >= 530 && mb.x < 630) {
					rectangle(530, 25, 630, 55);
					week = Wed;
				}
				if (mb.x >= 630 && mb.x < 730) {
					rectangle(630, 25, 730, 55);
					week = Thu;
				}
				if (mb.x >= 730 && mb.x < 830) {
					rectangle(730, 25, 830, 55);
					week = Fri;
				}
				if (mb.x >= 830 && mb.x < 930) {
					rectangle(830, 25, 930, 55);
					week = Sat;
				}
				if (mb.x >= 930 && mb.x <= 1030) {
					rectangle(930, 25, 1030, 55);
					week = Sun;
				}
			}

			if (mb.y >= 60 && mb.y <= 90) {
				setlinecolor(WHITE);
				for (int i = 0; i <= 4; i++)
					rectangle(160 + 170 + 100 * i, 60, 160 + 170 + 100 * (i + 1), 90);
				setlinecolor(DARKGRAY);
				if (mb.x >= 330 && mb.x <= 430) {
					rectangle(330, 60, 430, 90);
					order = 1;
				}
				if (mb.x > 430 && mb.x < 530) {
					rectangle(430, 60, 530, 90);
					order = 2;
				}
				if (mb.x >= 530 && mb.x < 630) {
					rectangle(530, 60, 630, 90);
					order = 3;
				}
				if (mb.x >= 630 && mb.x < 730) {
					rectangle(630, 60, 730, 90);
					order = 4;
				}
				if (mb.x >= 730 && mb.x < 830) {
					rectangle(730, 60, 830, 90);
					order = 5;
				}
			}

			if (mb.y >= 100 && mb.y <= 130) {
				if (mb.x >= 330 && mb.x <= 530) {
					setlinecolor(WHITE);
					rectangle(330, 100, 430, 130);
					rectangle(430, 100, 530, 130);
					setlinecolor(DARKGRAY);
					if (mb.x < 430) {
						rectangle(330, 100, 430, 130);
						credit = 1;
					}
					else {
						rectangle(430, 100, 530, 130);
						credit = 2;
					}
				}
				else if (mb.x >= 830 && mb.x <= 1030) {
					setlinecolor(WHITE);
					rectangle(930, 100, 1030, 130);
					rectangle(830, 100, 930, 130);
					setlinecolor(DARKGRAY);
					if (mb.x < 930) {
						rectangle(830, 100, 930, 130);
						type = 0;
					}
					else {
						rectangle(930, 100, 1030, 130);
						type = 1;
					}
				}
			}
			
			if (mb.y >= 148 && mb.y <= 182) {
				if (mb.x >= 330 && mb.x <= 700) {//name
					name=getname();
					outtextxy(332, 148, name.c_str());
				}
				if (mb.x >= 830 && mb.x <= 1030) {//tea
					tea=gettea();
					outtextxy(832, 148, tea.c_str());
				}
			}
			break;
		}//switch
		if (week != inf && type != inf && credit != inf && order != inf ) {
			if (name != "" && tea != "") {
				change = 0;
				setfillcolor(WHITE);
				fillcircle(100, 100, 50);
				outtextxy(620, 180, name.c_str());
				outtextxy(620, 10, tea.c_str());
			}
			
			
		}
	}//while
	change = 1;
	setfillcolor(RED);
	fillcircle(200, 200, 100);
	setfillcolor(WHITE);
	LessonStu tmp(credit, maxstu, week, order, name, tea, type);
	SetLesson(tmp, ++all);
	p->schedule[week][order].done = 1;
	p->schedule[week][order] = tmp;
	int d = 1;
	return;
}
void picklessons(PersonStu *p) {
	
	int week = inf, type = inf, credit = inf, order = inf;
	while (change) {
		LOGFONT f;
		gettextstyle(&f);
		MOUSEMSG mb;
		mb = GetMouseMsg();
		FlushMouseMsgBuffer();
		switch (mb.uMsg) {
		case WM_LBUTTONUP:
			if (mb.x >= 0 && mb.x <= 150 && mb.y >= 230 && mb.y < 310) {
				return;
			}
			if (mb.x >= 0 && mb.x <= 150 && mb.y >= 310 && mb.y < 390) {
				return;
			}

			if (mb.x >= 40 && mb.x <= 110 && mb.y >= 715 && mb.y <= 755) {
				OutLessonS(p->Getid());
				fillroundrect(400, 350, 800, 450, 10, 10);
				f.lfHeight = 50;
				settextstyle(&f);
				setfillcolor(WHITE);
				settextcolor(BLACK);
				outtextxy(450, 375, "安全退出选课中..");
				Sleep(2000); exit(0);
			}
			
			if (mb.y >= 25 && mb.y <= 55) {
				setlinecolor(WHITE);
				for (int i = 0; i <= 6; i++)
					rectangle(160 + 170 + 100 * i, 25, 160 + 170 + 100 * (i + 1), 55);
				setlinecolor(DARKGRAY);	
				if (mb.x >= 330 && mb.x <= 430 ) {
					rectangle(330, 25, 430, 55);
					week = Mon;
				}
				if (mb.x > 430 && mb.x < 530) {
					rectangle(430, 25, 530, 55);
					week = Tue;
				}
				if (mb.x >= 530 && mb.x < 630) {
					rectangle(530, 25, 630, 55);
					week = Wed;
				}
				if (mb.x >= 630 && mb.x < 730) {
					rectangle(630, 25, 730, 55);
					week = Thu;
				}
				if (mb.x >= 730 && mb.x < 830) {
					rectangle(730, 25, 830, 55);
					week = Fri;
				}
				if (mb.x >= 830 && mb.x < 930) {
					rectangle(830, 25, 930, 55);
					week = Sat;
				}
				if (mb.x >= 930 && mb.x <= 1030) {
					rectangle(930, 25, 1030, 55);
					week = Sun;
				}
			}
			
			if (mb.y >= 60 && mb.y <= 90) {
				setlinecolor(WHITE);
				for (int i = 0; i <= 4; i++)
					rectangle(160 + 170 + 100 * i, 60, 160 + 170 + 100 * (i + 1), 90);
				setlinecolor(DARKGRAY);
				if (mb.x >= 330 && mb.x <= 430) {
					rectangle(330, 60, 430, 90);
					order = 1;
				}
				if (mb.x > 430 && mb.x < 530) {
					rectangle(430, 60, 530, 90);
					order = 2;
				}
				if (mb.x >= 530 && mb.x < 630) {
					rectangle(530, 60, 630, 90);
					order = 3;
				}
				if (mb.x >= 630 && mb.x < 730) {
					rectangle(630, 60, 730, 90);
					order = 4;
				}
				if (mb.x >= 730 && mb.x < 830) {
					rectangle(730, 60, 830, 90);
					order = 5;
				}
			}

			if (mb.y >= 100 && mb.y <= 130) {
				if (mb.x >= 330 && mb.x <= 530) {
					setlinecolor(WHITE);
					rectangle(330, 100, 430, 130);
					rectangle(430, 100, 530, 130);
					setlinecolor(DARKGRAY);
					if (mb.x < 430) {
						rectangle(330, 100, 430, 130);
						credit = 1;
					}
					else {
						rectangle(430, 100, 530, 130);
						credit = 2;
					}
				}
				else if (mb.x >= 830 && mb.x <= 1030) {
					setlinecolor(WHITE);
					rectangle(930, 100, 1030, 130);
					rectangle(830, 100, 930, 130);
					setlinecolor(DARKGRAY);
					if (mb.x < 930) {
						rectangle(830, 100, 930, 130);
						type = 0;
					}
					else {
						rectangle(930, 100, 1030, 130);
						type = 1;
					}
				}
			}
			break;
		}//switch
		if (week != inf && type != inf && credit != inf && order != inf) {
			change = 0;//fillcircle(100, 100, 50);
		}
	}//which
	change = 1;
	setlinecolor(WHITE);
	freopen("selected.txt", "w", stdout);
	cout << week+1 << " " << order << " " << credit << " " << type << endl;
	system("activate & conda activate environment1 && python D:\\sdu\\cpp\\project_rebuild\\just_doit\\picking.py");
	fclose(stdout);
	cin.clear();
	FILE* re=freopen("selected.txt", "r", stdin);
	int a=-1, i = 1;
	int ooo[10];
	
	while (cin >> a) {
		show(a, i);
		ooo[i++] = a;
	}
	fclose(stdin);
	cin.clear();
	if (a==-1) {
		LOGFONT f;
		gettextstyle(&f);
		fillroundrect(400, 350, 800, 450, 10, 10);
		f.lfHeight = 50;
		settextstyle(&f);
		setfillcolor(WHITE);
		settextcolor(BLACK);
		outtextxy(450, 375, "无内容，请重试"); 
		return;
	}
	while (change) {
		LOGFONT f;
		gettextstyle(&f);
		MOUSEMSG mb;
		mb = GetMouseMsg();
		FlushMouseMsgBuffer();
		switch (mb.uMsg) {
		case WM_LBUTTONUP:
			if (mb.x >= 0 && mb.x <= 150 && mb.y >= 230 && mb.y < 310) {
				return;
			}
			if (mb.x >= 0 && mb.x <= 150 && mb.y >= 310 && mb.y < 390) {
				return;
			}
			if (mb.x >= 40 && mb.x <= 110 && mb.y >= 715 && mb.y <= 755) {
				OutLessonS(p->Getid());
				fillroundrect(400, 350, 800, 450, 10, 10);
				f.lfHeight = 50;
				settextstyle(&f);
				setfillcolor(WHITE);
				settextcolor(BLACK);
				outtextxy(450, 375, "安全退出选课中..");
				Sleep(2000); exit(0);
			}
			if (mb.x >= 950 && mb.x <= 1250) {
				//fillcircle(mb.x, mb.y, mb.x/100);
				setfillcolor(WHITE);				
				int line = (mb.y - 240) / 60+1 ;
				if (line <= 0||line>=i)continue;
				LessonStu wuwu = allLesson[ooo[line]-1];
				if (!p->schedule[wuwu.time.weekday][wuwu.time.order].done) {
					fillcircle(1100, 180 + line * 60 + 30, 10);
					p->schedule[wuwu.time.weekday][wuwu.time.order] = wuwu;
					p->schedule[wuwu.time.weekday][wuwu.time.order].done = 1;
					//change = 0;
				}
			} 
			
			break;
		}//switch
		
	}
	change = 1;
}
void OutLessonS(unsigned long long id) {
	freopen("Student.txt", "a+", stdout);
	PersonStu tmp = Stusaved[id];
	int x = 0;
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 4; j++) {
			if (tmp.schedule[i][j].done)x++;
		}
	}
	cout << x<<" ";//先存一共有几个课
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 4; j++) {
			if (tmp.schedule[i][j].done) {
				for (int k = 0; k < allLesson.size(); k++) {
					if (allLesson[k].Name == tmp.schedule[i][j].Name) {
						cout << k << " ";
						break;
					}
				}
				//查找课程序号
			}//已知
		}
	}
	cout << endl;
}
void OutLessonT(unsigned long long id) {
	freopen("Teacher.txt", "a+", stdout);
	PersonTea tmp = Teasaved[id];
	int x = 0;
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 4; j++) {
			if (tmp.schedule[i][j].done)x++;
		}
	}
	cout << x << " ";
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 4; j++) {
			if (tmp.schedule[i][j].done) {
				for (int k = 0; k < allLesson.size(); k++) {
					if (allLesson[k].Name == tmp.schedule[i][j].Name) {
						cout << k << " ";
						break;
					}
				}
				//查找
			}//已知
		}
	}
	cout << endl;
}
void GetLesson() {//用于把所有已经开设的课程放到有序号的表里
	
	ifstream csvfile("Lesson.csv", ios::in);
	string line;//"Id" "week" "order" "credit" "type"  "maxstu"  "nowstu"  "Teacher"  "Name" 
	string field;
	int n, c, m, w, o,t;
	int i = 0;
	getline(csvfile, line);
	while (getline(csvfile, line)) {
		string field;
		istringstream sin(line);
		getline(sin, field, ',');
		n = atoi(field.c_str());
		getline(sin, field, ',');
		w = atoi(field.c_str());
		getline(sin, field, ',');
		o = atoi(field.c_str());
		getline(sin, field, ',');
		c = atoi(field.c_str());
		getline(sin, field, ',');
		t = atoi(field.c_str());
		getline(sin, field, ',');
		m = atoi(field.c_str());
		getline(sin, field, ',');
		int now = atoi(field.c_str());
		getline(sin, field, ',');
		string T = field;
		getline(sin, field, ',');
		string N = field;
		LessonStu tmp (c, m, w, o, T, N, t);
		tmp.setnow(now);
		allLesson.push_back(tmp);
		i++;
	}	
	all = i;
}
void GetPerson() {//用于读取已经存在的账号和账号相对应的课表，
	cin.clear();
	unsigned long long id;
	int L,n;
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
	freopen("Student.txt", "r", stdin);
	while (cin >> id) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> L;
			LessonStu tmp = allLesson[L];
			Stusaved[id].schedule[tmp.time.weekday][tmp.time.order] = tmp;
		}
		
	}
	cin.clear();
	freopen("Teacher.txt", "r", stdin);
	while (cin >> id) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> L;
			LessonTea tmp;//直接在初始化的时候赋值就不可以
			tmp=allLesson[L];
			Teasaved[id].schedule[tmp.time.weekday][tmp.time.order] = tmp;
		}
		
	}
	cin.clear();
	
}
void SetLesson(LessonStu a,int n) {

	ofstream csvfile;
	csvfile.open("Lesson.csv", ios::out|ios::app);
	//csvfile << "Id" << ',' << "week" << ',' << "order" << ',' << "credit" << ',' << "type" << "," << "maxstu" << "," << "nowstu" << "," << "Teacher" << "," << "Name" << endl;
	csvfile << n << "," << a.time.weekday << ',' << a.time.order << ',' << a.credit << ',' << a.type << ',' << a.maxstu << ',' << a.nowstu << ',' << a.Tea << ',' << a.Name << endl;
	csvfile.close();

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
	change = 1;
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
