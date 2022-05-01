#include "State.h"

using std::vector;

State::State(vector<Action*>& actionsP, vector<Transition*>* transitionsP) :
	actions{ actionsP },
	transitions{ transitionsP }
{
}

void State::execute()
{
}
