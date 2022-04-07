#include "State.h"

using std::vector;


State::State(vector<Action*> entryActionsP, vector<Action*> actionsP, vector<Action*> exitActionsP, vector<Transition*> transitionsP) :
	entryActions{ entryActionsP },
	actions{ actionsP },
	exitActions{ exitActionsP },
	transitions{ transitionsP }
{
}

void State::execute()
{
}
