#pragma once
#ifndef _L_T_H
#define _L_T_H

#include "Lesson.h"
class LessonTea :
    public Lesson
{
    friend class PersonTea;
public:
    void open();
    void del();
    void addscore();
    void lookstu();
};

#endif // !_L_T_H