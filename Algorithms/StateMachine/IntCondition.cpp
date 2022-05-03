#include "IntCondition.h"

bool IntCondition::test() {
    bool test = false;

    if (minValue <= testValue && testValue <= maxValue) {
        test = true;
    }
    else {
        test = false;
    }

    return test;
}
