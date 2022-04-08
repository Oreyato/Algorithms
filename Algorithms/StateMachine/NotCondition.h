#pragma once
#include "ICondition.h"

class NotCondition :
    public ICondition
{
public:
    NotCondition(ICondition* conditionP) :
        ICondition(), condition(conditionP)
    {}

    bool test() override { return !condition->test(); }

private:
    ICondition* condition;

};
