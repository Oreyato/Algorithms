#include <vector>
#include "Transition.h"
#include "Action.h"

class State
{
public:
	State();

	std::vector<Action*> getEntryAction() { return entryAction; }
	std::vector<Action*> getAction() { return action; }
	std::vector<Action*> getExitAction() { return exitAction; }

	std::vector<Transition*> getTransitions() { return transitions; }

private:
	std::vector<Action*> entryAction{ nullptr };
	std::vector<Action*> action{ nullptr };
	std::vector<Action*> exitAction{ nullptr };

	std::vector<Transition*> transitions{ nullptr };
};