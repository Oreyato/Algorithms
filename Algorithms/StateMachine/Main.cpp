#include <iostream>
#include "StateMachine.h"

int main() {
	State startState;

	StateMachine stm{ startState };

	stm.update();

	return 0;
}