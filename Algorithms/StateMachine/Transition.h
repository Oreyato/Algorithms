#pragma once
#include <vector>

class State;
class Action;

class Transition
{
public:
	Transition();
	~Transition();

	bool isTriggered() { return canFire ? true : false; }
	State* getTargetState() { return targetState; }
	std::vector<Action*> getActions() { return actions; }

private:
	bool canFire;
	State* targetState;
	std::vector<Action*> actions;
};