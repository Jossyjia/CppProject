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
    void setb();
};

#endif // !_B_S_H