#pragma once
#include "ICondition.h"

class OrCondition :
    public ICondition
{
public:
    bool test() override { return conditionA->test() || conditionB->test(); }

private:
    ICondition* conditionA{ nullptr };
    ICondition* conditionB{ nullptr };

};
