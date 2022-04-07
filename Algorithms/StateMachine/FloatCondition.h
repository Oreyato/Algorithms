#pragma once
#include "ICondition.h"

class FloatCondition :
    public ICondition
{
public:
    bool test() override { return minValue <= *testValue <= maxValue; }

    float minValue{ 0 };
    float maxValue{ 0 };
    float* testValue{ nullptr };
};

