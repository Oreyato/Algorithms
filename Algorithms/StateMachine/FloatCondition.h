#pragma once
#include "ICondition.h"

class FloatCondition :
    public ICondition
{
public:
    FloatCondition(float minValueP, float maxValueP, float testValueP) : 
        ICondition(), minValue(minValueP), maxValue(maxValueP), testValue(testValueP)
    {}

    bool test() override;

    float minValue{ 0 };
    float maxValue{ 0 };
    float testValue{ 0 };
};

