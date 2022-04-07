#include <iostream>
#include "StateMachine.h"

using namespace std;

int main() {
	//State startState;

	//StateMachine stm{ startState };

	//stm.update();

	Action act01{"Pierre"};
	Action* p_act01 = &act01;

	vector<Action*> actions;
	actions.push_back(p_act01);

	FloatCondition floatCdt;
	Transition trans{actions, floatCdt};

	return 0;
}