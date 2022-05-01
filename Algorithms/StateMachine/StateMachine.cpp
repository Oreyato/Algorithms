#include "StateMachine.h"
using std::vector;

StateMachine::StateMachine(State& initialStateP) :
	initialState{initialStateP},
	currentState{initialState}
{

}

std::vector<Action*> StateMachine::update()
{
	// Assume no transition is triggered
	Transition* triggeredTransition{ nullptr };
	
	// Checks through each transition and store the first one that triggers
	for (Transition* transition : currentState.getTransitions()) {
		if (transition->isTriggered()) {
			triggeredTransition = transition;
		}
	}

	// Check if we have a transition to fire
	if (triggeredTransition != nullptr) {
		// Find the target state
		State* targetState = triggeredTransition->getTargetState();

		vector<Action*> transitActions {triggeredTransition->getActions()};
		vector<Action*> actions = { targetState->getActions() };
		actions.insert(std::end(actions), std::begin(transitActions), std::end(transitActions));

		// Complete the transition and return the action list
		currentState = *targetState;

		return actions;
		
	}
	
	return currentState.getActions();
}

void StateMachine::executeActions(std::vector<Action*> actionsP)
{
	for (Action* action : actionsP) {
		action->execute();
	}
}
