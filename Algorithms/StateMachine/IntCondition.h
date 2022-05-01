#pragma once
#include "ICondition.h"

class IntCondition :
    public ICondition
{
public: 
    IntCondition(int minValueP, int maxValueP, int testValueP) :
        ICondition(), minValue(minValueP), maxValue(maxValueP), testValue(testValueP)
    {}

    bool test() override;

private:

    int minValue{ 0 };
    int maxValue{ 0 };
    int testValue{ 0 };
};

