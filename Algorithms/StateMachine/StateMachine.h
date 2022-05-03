#pragma once

#include "State.h"

class StateMachine
{
public:
	StateMachine(State& initialStateP);
	std::vector<Action*> update();
	void executeActions(std::vector<Action*> actionsP);

	void setCurrentState(State& currentStateP) { currentState = currentStateP; }

private:
	std::vector<State> states;

	State initialState;
	State currentState;
};

