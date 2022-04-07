#pragma once
#include <vector>

#include "FloatCondition.h"

class State;
class Action;

class Transition
{
public:
	Transition(std::vector<Action*> actionsP, ICondition& conditionP);
	~Transition();

	bool isTriggered() { return condition.test(); }
	State* getTargetState() { return targetState; }
	std::vector<Action*> getActions() { return actions; }

private:
	FloatCondition floatCdt;
	ICondition& condition = floatCdt;

	State* targetState{ nullptr };
	std::vector<Action*> actions;
};