#pragma once
#include "ICondition.h"

class AndCondition :
    public ICondition
{
public:
    bool test() { return conditionA->test() && conditionB->test(); }

private:
    ICondition* conditionA{ nullptr };
    ICondition* conditionB{ nullptr };

};