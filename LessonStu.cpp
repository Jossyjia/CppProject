#include "LessonStu.h"
#include "LessonTea.h"
LessonStu& LessonStu::operator=(LessonStu& s)
{
	this->credit = s.credit;
	this->maxstu = s.maxstu;
	this->Name = s.Name;
	this->nowstu = s.nowstu;
	this->type = s.type;
	this->Tea = s.Tea;
	this->time = s.time;
	return *this;
	// TODO: 在此处插入 return 语句
}

void LessonStu::print(int x,int y)
{
	int xx = 230 + 135 * x;
	int yy=640;
	if (y == 1 || y == 0)yy = 60 + 140 * y;
	else if (y == 2 || y == 3) yy = 350 + 140 * y;
	string tmp = Name + " "+Tea;
	char* n=new char[sizeof(tmp)]; 
	strcpy(n, tmp.c_str());
	outtextxy(xx, yy, n);
	if (type)outtextxy(xx, yy + 40, "必修");
	else outtextxy(xx, yy + 40, "选修");
	if (credit == 1)outtextxy(xx + 90, yy + 40, "1");
	else outtextxy(xx + 90, yy + 40, "1");

}

LessonStu& LessonStu::operator=(LessonTea& s)
{
	this->credit = s.credit;
	this->maxstu = s.maxstu;
	this->Name = s.Name;
	this->nowstu = s.nowstu;
	this->type = s.type;
	this->Tea = s.Tea;
	this->time = s.time;
	return *this;
	// TODO: 在此处插入 return 语句
}
