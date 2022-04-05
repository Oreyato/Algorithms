#pragma once
#include <vector>

#include "FloatCondition.h"

class State;
class Action;

class Transition
{
public:
	Transition();
	~Transition();

	bool isTriggered() { return condition.test(); }
	State* getTargetState() { return targetState; }
	std::vector<Action*> getActions() { return actions; }

private:
	ICondition condition;

	State* targetState{ nullptr };
	std::vector<Action*> actions;
};