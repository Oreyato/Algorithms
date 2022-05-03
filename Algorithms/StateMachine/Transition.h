#pragma once
#include <vector>

#include "IntCondition.h"
#include "FloatCondition.h"
#include "AndCondition.h"
#include "NotCondition.h"
#include "OrCondition.h"

class State;
class Action;

class Transition
{
public:
	Transition(Action* actionP, ICondition* conditionP);
	Transition(State* targetStateP, Action* actionP, ICondition* conditionP);
	Transition(State* targetStateP, std::vector<Action*>& actionsP, ICondition* conditionP);
	~Transition();

	bool isTriggered() { return condition->test(); }
	State* getTargetState() { return targetState; }
	std::vector<Action*> getActions() { return actions; }

	void setTargetState(State* targetStateP) { targetState = targetStateP; }

private:
	ICondition* condition;

	State* targetState{ nullptr };
	Action* action;
	std::vector<Action*> actions;
};