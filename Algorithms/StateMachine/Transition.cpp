#pragma once
#include "Transition.h"
#include "Action.h"
#include "State.h"

#include "AndCondition.h"
#include "FloatCondition.h"
#include "NotCondition.h"
#include "OrCondition.h"

Transition::Transition(State* targetStateP, std::vector<Action*> actionsP, ICondition* conditionP) :
	targetState{targetStateP},
	actions{actionsP},
	condition{conditionP}
{
}

Transition::~Transition()
{
}
