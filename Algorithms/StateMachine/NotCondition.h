#pragma once
#include "Condition.h"

class NotCondition :
    public Condition
{
public:
    bool test() { return !condition->test(); }

private:
    Condition* condition;

};
