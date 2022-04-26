#pragma once
#include "Transition.h"
#include "Action.h"
#include "State.h"

Transition::Transition(Action* actionP, ICondition* conditionP) :
	targetState{ nullptr },
	action{ actionP },
	condition{ conditionP }
{
}

Transition::Transition(State* targetStateP, Action* actionP, ICondition* conditionP) :
	targetState{ targetStateP },
	action{ actionP },
	condition{ conditionP }
{
}

Transition::Transition(State* targetStateP, std::vector<Action*>& actionsP, ICondition* conditionP) :
	targetState{targetStateP},
	actions{actionsP},
	condition{conditionP}
{
}

Transition::~Transition()
{
}
