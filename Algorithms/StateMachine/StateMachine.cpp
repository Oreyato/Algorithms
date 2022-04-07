#include "StateMachine.h"
using std::vector;

StateMachine::StateMachine(State initialStateP) :
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

			break;
		}
	}

	// Check if we have a transition to fire
	if (triggeredTransition != nullptr) {
		// Find the target state
		
		State* targetState = triggeredTransition->getTargetState();

		// Add the exit action of the old state, the transition action and the entry for the new state
		vector<Action*> actions{ currentState.getExitActions() };

		vector<Action*> transitActions {triggeredTransition->getActions()};
		vector<Action*> targetStateEntryActions {targetState->getEntryActions()};
		actions.insert(std::end(actions), std::begin(transitActions), std::end(transitActions));
		actions.insert(std::end(actions), std::begin(targetStateEntryActions), std::end(targetStateEntryActions));

		// Complete the transition and return the action list
		currentState = *targetState;

		return actions;
		
	}
	else {
		return currentState.getActions();
	}
}

void StateMachine::executeActions(std::vector<Action*> actionsP)
{
	for (Action* action : actionsP) {
		action->execute();
	}
}