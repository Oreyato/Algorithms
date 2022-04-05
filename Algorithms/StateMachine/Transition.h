#pragma once
#include <vector>

#include "Condition.h"

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
	Condition condition;

	State* targetState;
	std::vector<Action*> actions;
};