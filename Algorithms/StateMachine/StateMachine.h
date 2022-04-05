#pragma once

#include "State.h"
#include "Action.h"

class StateMachine
{
public:
	StateMachine(State initialStateP);
	std::vector<Action> update();

private:
	std::vector<State> states;

	State initialState;
	State currentState{ initialState };
};

