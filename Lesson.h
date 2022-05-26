#pragma once
#ifndef _L_H
#define _L_H
using namespace std;
enum week { Mon, Tue, Wed, Thu, Fri, Sat ,Sun };
struct Time {  
	int weekday,order;
	Time(int w=Sun,int o=1):weekday(w),order(o){}
};
class Lesson
{
public:
	const int credit, maxstu;
	Time time;
	bool type;//1是必修 0是选修
	Lesson  (int c=2,int m=16,int w=Sun,int o=1);
};

#endif // !_L_H