#pragma once
#include "ICondition.h"

class AndCondition :
    public ICondition
{
public:
    AndCondition(ICondition* conditionAP, ICondition* conditionBP) :
        ICondition(), conditionA{ conditionAP }, conditionB{ conditionBP }
    {}

    bool test() override { return conditionA->test() && conditionB->test(); }

private:
    ICondition* conditionA{ nullptr };
    ICondition* conditionB{ nullptr };

};