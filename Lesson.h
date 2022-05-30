#pragma once
#ifndef _L_H
#define _L_H
#include<string>
#include<graphics.h>
#include<easyx.h>
using namespace std;

enum week { Mon, Tue, Wed, Thu, Fri, Sat ,Sun };
struct Time {  
	int weekday,order;
	Time(int w=Sun,int o=1):weekday(w),order(o){}
};
class Lesson
{
public:
	/*const int credit, maxstu;
	static int nowstu;*/
	int credit, maxstu, nowstu;
	Time time;
	bool type;//1�Ǳ��� 0��ѡ��
	string Tea, Name;
	Lesson (int c=2,int m=16,int w=Sun,int o=1,string T="������",string N="��Ҫ��ͷ"):credit(c),maxstu(m),time(w,o),Tea(T),Name(N){};
};

#endif // !_L_H   