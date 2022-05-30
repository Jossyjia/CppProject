#include "LessonTea.h"

void LessonTea::open()
{

}

void LessonTea::print(int x, int y)
{
	int xx = 230 + 135 * x;
	int yy = 640;
	if (y == 1 || y == 0)yy = 60 + 140 * y;
	else if (y == 2 || y == 3) yy = 350 + 140 * y;
	string tmp = Name + " " + Tea;
	char* n = new char[sizeof(tmp)];
	strcpy(n, tmp.c_str());
	outtextxy(xx, yy, n);
	if (type)outtextxy(xx, yy + 40, "±ØÐÞ");
	else outtextxy(xx, yy + 40, "Ñ¡ÐÞ");
	if (credit == 1)outtextxy(xx + 90, yy + 40, "1");
	else outtextxy(xx + 90, yy + 40, "1");
}
