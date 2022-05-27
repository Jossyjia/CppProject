#pragma once
#ifndef _B_S_H
#define _B_S_H


#include "Background.h"
class BackStu :
    public Background
{
private:
    IMAGE Background, Photo;
    bool gender=0;
    void resetP();
public:
    void setb();//基本界面（我的课表
    void setX();//选课界面
    void setS();//分数界面
};

#endif // !_B_S_H