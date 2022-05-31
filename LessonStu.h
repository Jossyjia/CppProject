#pragma once
#ifndef _L_S_H
#define _L_S_H  
#include "Lesson.h"
class LessonTea;
class LessonStu :
    public Lesson
{
    friend class PersonStu;
public:
    LessonStu() {};
    LessonStu(int c, int m, int w, int o, string T, string N, bool t) {
        Lesson(c, m, w, o, T, N, t);
    }
    LessonStu& operator=(LessonStu& s);
    LessonStu& operator=(LessonTea& s);
    bool done=0;
    int score;
    void setscore(int t) { score = t; };
    void print(int x,int y);
};
#endif // !_L_S_H
