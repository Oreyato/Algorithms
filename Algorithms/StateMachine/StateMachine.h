#pragma once

#include "State.h"
#include "Action.h"

class StateMachine
{
public:
	StateMachine(State initialStateP);
	std::vector<Action*> update();
	void executeActions(std::vector<Action*> actionsP);

private:
	std::vector<State> states;

	State initialState;
	State currentState;
};

