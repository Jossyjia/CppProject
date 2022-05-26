#pragma once
#ifndef _P_H
#define _P_H
#include<easyx.h>
#include<string>
using namespace std;
class Person
{
private:
	string id;
	string code;
	//char id[20];ÕËºÅ
	//char code[20];ÃÜÂë
public:
	virtual void lookschedule();
};

#endif