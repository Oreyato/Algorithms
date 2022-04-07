#pragma once
#include "ICondition.h"

class NotCondition :
    public ICondition
{
public:
    bool test() override { return !condition->test(); }

private:
    ICondition* condition;

};
