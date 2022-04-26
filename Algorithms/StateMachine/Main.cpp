#include <iostream>
#include "StateMachine.h"

using namespace std;

int main() {	
	Action actionA{ "Action 1" };
	Action actionB{ "Action 2" };
	Action actionC{ "Action 3" };

	vector<Action*> entryActions;
	vector<Action*> actions;
	vector<Action*> exitActions;

	entryActions.push_back(&actionA);
	actions.push_back(&actionB);
	exitActions.push_back(&actionC);

	float testValue = 5;

	FloatCondition floatCdt{ 0, 10, testValue };

	Transition testTransition{ &actionC, &floatCdt };

	vector<Transition*> testTransitions;
	testTransitions.push_back(&testTransition);

	State testState{ entryActions, actions, exitActions, testTransitions };

	testTransitions[0]->setTargetState(&testState);

	StateMachine stateMachineTest{ testState };
	
	actions = stateMachineTest.update();
	stateMachineTest.executeActions(actions);
	actions = stateMachineTest.update();
	stateMachineTest.executeActions(actions);

	return 0;
}