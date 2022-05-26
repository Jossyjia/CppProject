#pragma once
#ifndef _P_T_H
#define _P_T_H

#include "Person.h"
#include"LessonTea.h"
class PersonTea :
    public Person
{
public:
    void launch();
    void addscore();
    void lookschedule();
    LessonTea schedule[10][10];
};

#endif // !_P_T_H