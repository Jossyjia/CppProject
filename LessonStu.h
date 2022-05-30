#pragma once
#ifndef _L_S_H
#define _L_S_H  
#include "Lesson.h"
class LessonStu :
    private Lesson
{
    friend class PersonStu;
public:
    LessonStu() {};
    LessonStu& operator=(LessonStu& s);
    bool done=0;
    int score;
    void setscore(int t) { score = t; };
    void print(int x,int y);
};
#endif // !_L_S_H
