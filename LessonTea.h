#pragma once
#ifndef _L_T_H
#define _L_T_H

#include "Lesson.h"
class LessonTea :
    public Lesson
{
    friend class PersonTea;
public:
    bool done = 0;
    void open();
    void del();
    void lookstu();
    void print(int x, int y);
};

#endif // !_L_T_H