#pragma once
#include "Condition.h"

class AndCondition :
    public Condition
{
public:
    bool test() { return conditionA->test() && conditionB->test(); }

private:
    Condition* conditionA{ nullptr };
    Condition* conditionB{ nullptr };

};