#pragma once
#ifndef _P_H
#define _P_H
#include<easyx.h>
#include<string>
using namespace std;
class Person
{
private:
	unsigned long long code, id;
public:
	void setid(unsigned long long a);
	unsigned long long Getid() { return id; }
	void setcode(unsigned long long b);
	virtual void lookschedule(){};
};

#endif