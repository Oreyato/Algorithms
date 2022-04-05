#include <vector>
#include "Transition.h"

class State
{
public:
	State();

	std::vector<Transition*> getTransitions() { return transitions; }

private:

	std::vector<Transition*> transitions;
};