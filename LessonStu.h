#pragma once
#ifndef _L_S_H
#define _L_S_H  
#include "Lesson.h"
class LessonStu :
    private Lesson
{
    friend class PersonStu;
    LessonStu(const LessonStu& a);
    void xuan();
    void tui();
    void lookscore();
    void print();
};
#endif // !_L_S_H
