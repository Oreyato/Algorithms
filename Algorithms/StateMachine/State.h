#include <vector>
#include "Transition.h"
#include "BossAttack.h"
#include "BossMovement.h"

class State
{
public:
	State(std::vector<Action*>* actionsP, std::vector<Transition*>* transitionsP);

	void execute();

	const std::vector<Action*> getActions() { return *actions; }

	const std::vector<Transition*> getTransitions() { return *transitions; }

private:
	std::vector<Action*>* actions{ nullptr };

	std::vector<Transition*>* transitions{ nullptr };
};