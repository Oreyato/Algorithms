#pragma once
#include "Transition.h"
#include "Action.h"
#include "State.h"

Transition::Transition()
{
}

Transition::~Transition()
{
}

bool Transition::isTriggered()
{
    return false;
}
