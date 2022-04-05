#pragma once
#include "Condition.h"
class FloatCondition :
    public Condition
{
public:
    bool test() { return minValue <= *testValue <= maxValue; }

private:
    float minValue{ 0 };
    float maxValue{ 0 };
    float* testValue{ nullptr };
};

