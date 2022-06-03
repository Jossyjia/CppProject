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
	x--;
	int xx = 232 + 135 * x;
	int yy = 0;
	switch (y){
	case 1:
		yy = 60;
		break;
	case 2:
		yy = 200;
		break;
	case 3:
		yy = 210+140;
		break;
	case 4:
		yy = 350+140;
		break;
	case 5:
		yy = 500+140;
		break;
	}
	string tmp = Name ;
	char* n=new char[sizeof(tmp)]; 
	strcpy(n, tmp.c_str());
	outtextxy(xx, yy, n);
	tmp = Tea;
	strcpy(n, tmp.c_str());
	outtextxy(xx, yy + 40, n);
	if (type)outtextxy(xx, yy + 80, "必修");
	else outtextxy(xx, yy + 80, "选修");
	if (credit == 1)outtextxy(xx + 90, yy + 80, "1");
	else outtextxy(xx + 90, yy + 80, "2");

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
