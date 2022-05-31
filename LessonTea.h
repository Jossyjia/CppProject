#pragma once
#ifndef _L_T_H
#define _L_T_H

#include "Lesson.h"
class LessonStu;
class LessonTea :
    public Lesson
{
    friend class PersonTea;
public:
    LessonTea() {};
    LessonTea(int c, int m, int w, int o, string T, string N, bool t) {
        Lesson(c, m, w, o, T, N, t);
    }
    LessonTea& operator=(LessonTea& s);
    LessonTea& operator=(LessonStu& s);
    bool done = 0;
    void open();
    void print(int x, int y);
};

#endif // !_L_T_H