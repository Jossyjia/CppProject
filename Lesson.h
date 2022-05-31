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
	bool type;//1是必修 0是选修
	string Tea, Name;
	void setnow(int k){ nowstu = k; }

	Lesson (int c=2,int m=16,int w=Sun,int o=1,string T="汤婆婆",string N="不要回头",bool t=1):credit(c),maxstu(m),time(w,o),Tea(T),Name(N),type(t) {};
	
};

#endif // !_L_H   