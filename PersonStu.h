#pragma once
#ifndef _P_S_H
#define _P_S_H

#include "Person.h"
#include "LessonStu.h"
class PersonStu :
    public Person
{

    
public:
    void xuan(LessonStu a);
    void tui();
    void lookcredit();
    void lookschedule();
    LessonStu schedule[10][10];
};

#endif // !_P_S_H