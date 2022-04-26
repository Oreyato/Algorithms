#include <vector>
#include "Transition.h"
#include "Action.h"

class State
{
public:
	State(std::vector<Action*>& entryActionsP, std::vector<Action*>& actionsP, std::vector<Action*>& exitActionsP, std::vector<Transition*>& transitionsP);

	void execute();

	const std::vector<Action*> getEntryActions() { return entryActions; }
	const std::vector<Action*> getActions() { return actions; }
	const std::vector<Action*> getExitActions() { return exitActions; }

	const std::vector<Transition*> getTransitions() { return transitions; }

private:
	std::vector<Action*> entryActions{ nullptr };
	std::vector<Action*> actions{ nullptr };
	std::vector<Action*> exitActions{ nullptr };

	std::vector<Transition*> transitions{ nullptr };
};