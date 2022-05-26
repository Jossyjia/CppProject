#include <iostream>
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
		case WM_LBUTTONDOWN:
			if (mb.x >= 450 && mb.x <= 750 && mb.y >= 300 && mb.y <= 330) {
				//输入学工号 2021 0013 0164 长度为12位的是学生，教师号码为10位
				getid();
			}
			if (mb.x >= 450 && mb.x <= 750 && mb.y >= 370 && mb.y <= 400) {
				getcode();
			}

			break;

		case WM_MOUSEMOVE:
			if (mb.x >= 540 && mb.x <= 615 && mb.y >= 490 && mb.y <= 540) {
				setfillcolor(RGB(211,211,211));
				fillrectangle(540, 490, 615, 540);
				outtextxy(550, 500, "登录");
				FlushMouseMsgBuffer();
				MOUSEMSG m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONUP) {
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
			}
			else if (mb.x > 625 && mb.x < 700 && mb.y>490 && mb.y < 540) {
				setfillcolor(RGB(211, 211, 211));
				fillrectangle(625, 490, 700, 540);
				outtextxy(635, 500, "注册");
				FlushMouseMsgBuffer();
				MOUSEMSG m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONUP) {
					fillroundrect(400, 350, 800, 450, 10, 10);
					f.lfHeight = 20;
					settextcolor(RGB(0, 47, 167));
					if (addaccount()) {
						outtextxy(420, 370, "注册成功,将自动登录");
						change = 0;
						Sleep(50);
					}
					else {
						outtextxy(450, 370, "用户已存在");
						Sleep(100);
						b.setb();
					}
				}
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
	freopen("tempcode.txt", "r", stdin);
	cin >> code;
	freopen("tempid.txt", "r", stdin);
	cin >> id;
	int len = id.length();
	if (len == 10)freopen("Students.txt", "a+", stdin);
	else if (len == 12)freopen("Teacher.txt", "a+", stdin);
	int n;
	cin >> n;
	string all[2];
	for (int i = 1; i <= n; i++) {
		cin >> all[0] >> all[1];
		if (all[0] == id) {
			return 0;
		}
	}
	freopen("Students.txt", "a+", stdout);
	cout << id <<" " << code;
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
	freopen("tempcode.txt", "w", stdout);
	cout << code;
	return;
}
/*
////////////////////////////////////////
// 程序：基于 EasyX 的文本框 + 按钮控件
// 作者：BestAns
// 编译环境：VS2019，EasyX_20211109
// 编写日期：2021-10-28
// 最后修改：2021-11-20
//#include <graphics.h>



// 实现文本框控件
class EasyTextBox
{
private:
	int left = 0, top = 0, right = 0, bottom = 0;	// 控件坐标
	char* text = NULL;							// 控件内容
	size_t maxlen = 0;									// 文本框最大内容长度

public:
	void Create(int x1, int y1, int x2, int y2, int max)
	{
		maxlen = max;
		text = new char[maxlen];
		text[0] = 0;
		left = x1, top = y1, right = x2, bottom = y2;

		// 绘制用户界面
		Show();
	}

	~EasyTextBox()
	{
		if (text != NULL)
			delete[] text;
	}

	char* Text()
	{
		return text;
	}

	bool Check(int x, int y)
	{
		return (left <= x && x <= right && top <= y && y <= bottom);
	}

	// 绘制界面
	void Show()
	{
		// 备份环境值
		int oldlinecolor = getlinecolor();
		int oldbkcolor = getbkcolor();
		int oldfillcolor = getfillcolor();

		setlinecolor(LIGHTGRAY);		// 设置画线颜色
		setbkcolor(0xeeeeee);			// 设置背景颜色
		setfillcolor(0xeeeeee);			// 设置填充颜色
		fillrectangle(left, top, right, bottom);
		outtextxy(left + 10, top + 5, text);

		// 恢复环境值
		setlinecolor(oldlinecolor);
		setbkcolor(oldbkcolor);
		setfillcolor(oldfillcolor);
	}

	void OnMessage()
	{
		// 备份环境值
		int oldlinecolor = getlinecolor();
		int oldbkcolor = getbkcolor();
		int oldfillcolor = getfillcolor();

		setlinecolor(BLACK);			// 设置画线颜色
		setbkcolor(WHITE);				// 设置背景颜色
		setfillcolor(WHITE);			// 设置填充颜色
		fillrectangle(left, top, right, bottom);
		outtextxy(left + 10, top + 5, text);

		int width = textwidth(text);	// 字符串总宽度
		int counter = 0;				// 光标闪烁计数器
		bool binput = true;				// 是否输入中

		ExMessage msg;
		while (binput){
			while (binput && peekmessage(&msg, EM_MOUSE | EM_CHAR, false))	// 获取消息，但不从消息队列拿出			{
				if (msg.message == WM_LBUTTONDOWN){
					// 如果鼠标点击文本框外面，结束文本输入
					if (msg.x < left || msg.x > right || msg.y < top || msg.y > bottom){
						binput = false;
						break;
					}
				}
				else if (msg.message == WM_CHAR){
					size_t len =strlen(text);
					switch (msg.ch){
					case '\b':				// 用户按退格键，删掉一个字符
						if (len > 0){
							text[len - 1] = 0;
							width = textwidth(text);
							counter = 0;
							clearrectangle(left + 10 + width, top + 1, right - 1, bottom - 1);
						}
						break;
					case '\r':				// 用户按回车键，结束文本输入
					case '\n':
						binput = false;
						break;
					default:				// 用户按其它键，接受文本输入
						if (len < maxlen - 1)
						{
							text[len++] = msg.ch;
							text[len] = 0;

							clearrectangle(left + 10 + width + 1, top + 3, left + 10 + width + 1, bottom - 3);	// 清除画的光标
							width = textwidth(text);				// 重新计算文本框宽度
							counter = 0;
							outtextxy(left + 10, top + 5, text);		// 输出新的字符串
						}
					}
				}
				peekmessage(NULL, EM_MOUSE | EM_CHAR);				// 从消息队列抛弃刚刚处理过的一个消息
			}

			// 绘制光标（光标闪烁周期为 20ms * 32）
			counter = (counter + 1) % 32;
			if (counter < 16)
				line(left + 10 + width + 1, top + 3, left + 10 + width + 1, bottom - 3);				// 画光标
			else
				clearrectangle(left + 10 + width + 1, top + 3, left + 10 + width + 1, bottom - 3);		// 擦光标

			// 延时 20ms
			Sleep(20);
		}

		clearrectangle(left + 10 + width + 1, top + 3, left + 10 + width + 1, bottom - 3);	// 擦光标

		// 恢复环境值
		setlinecolor(oldlinecolor);
		setbkcolor(oldbkcolor);
		setfillcolor(oldfillcolor);

		Show();
	}
};



// 实现按钮控件
class EasyButton
{
private:
	int left = 0, top = 0, right = 0, bottom = 0;	// 控件坐标
	char * text = NULL;							// 控件内容
	void (*userfunc)() = NULL;						// 控件消息

public:
	void Create(int x1, int y1, int x2, int y2, const char* title, void (*func)())
	{
		text = new char[strlen(title) + 1];
		for (int i = 0; i <= strlen(title) + 1; i++) {
			*(text + i) = *(title + i);
		}
		left = x1, top = y1, right = x2, bottom = y2;
		userfunc = func;

		// 绘制用户界面
		Show();
	}
	~EasyButton()
	{
		if (text != NULL)
			delete[] text;
	}

	bool Check(int x, int y)
	{
		return (left <= x && x <= right && top <= y && y <= bottom);
	}
	// 绘制界面
	void Show()
	{
		int oldlinecolor = getlinecolor();
		int oldbkcolor = getbkcolor();
		int oldfillcolor = getfillcolor();

		setlinecolor(BLACK);			// 设置画线颜色
		setbkcolor(WHITE);				// 设置背景颜色
		setfillcolor(WHITE);			// 设置填充颜色
		fillrectangle(left, top, right, bottom);
		outtextxy(left + (right - left - textwidth(text) + 1) / 2, top + (bottom - top - textheight(text) + 1) / 2, text);

		setlinecolor(oldlinecolor);
		setbkcolor(oldbkcolor);
		setfillcolor(oldfillcolor);
	}
	void OnMessage()
	{
		if (userfunc != NULL)
			userfunc();
	}
};
// 定义控件
EasyTextBox txtName;
EasyTextBox txtPwd;
EasyButton btnOK;
// 按钮 btnOK 的点击事件
void On_btnOk_Click()
{
	;
}

// 主函数
int main(){
	// 创建图形窗口
	initgraph(640, 480);
	setbkcolor(0xeeeeee);// 简单绘制界面
	cleardevice();
	settextcolor(BLACK);
	outtextxy(50, 55, "用户名：");
	txtName.Create(120, 50, 400, 75, 10);						// 创建用户名文本框控件
	outtextxy(50, 105, "密　码：");
	txtPwd.Create(120, 100, 400, 125, 10);						// 创建密码文本框控件
	btnOK.Create(320, 150, 400, 175, "OK", On_btnOk_Click);	// 创建按钮控件

	ExMessage msg;
	while (true)
	{
		msg = getmessage(EM_MOUSE);			// 获取消息输入

		if (msg.message == WM_LBUTTONDOWN)
		{
			// 判断控件
			if (txtName.Check(msg.x, msg.y))	txtName.OnMessage();

			// 判断控件
			if (txtPwd.Check(msg.x, msg.y))		txtPwd.OnMessage();

			// 判断控件
			if (btnOK.Check(msg.x, msg.y))		btnOK.OnMessage();
		}
	}

	// 关闭绘图窗口
	closegraph();
	return 0;
}*/