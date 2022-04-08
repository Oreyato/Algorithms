#pragma once
#include <vector>

#include "FloatCondition.h"
#include "AndCondition.h"
#include "NotCondition.h"
#include "OrCondition.h"

class State;
class Action;

class Transition
{
public:
	Transition(State* targetStateP, Action* actionP, ICondition* conditionP);
	Transition(State* targetStateP, std::vector<Action*> actionsP, ICondition* conditionP);
	~Transition();

	bool isTriggered() { return condition->test(); }
	State* getTargetState() { return targetState; }
	std::vector<Action*> getActions() { return actions; }

private:
	ICondition* condition;

	State* targetState{ nullptr };
	Action* action;
	std::vector<Action*> actions;
};