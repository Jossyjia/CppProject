#pragma once
#ifndef _P_S_H
#define _P_S_H

#include "Person.h"
#include "LessonStu.h"
class PersonStu :
    public Person
{
public:
    PersonStu& operator=(PersonStu& s);
    void xuan(LessonStu a);
    void tui(int week,int order);
    int lookscore(int w,int o);
    void lookschedule();
    LessonStu schedule[10][10];
};

#endif // !_P_S_H