#include "BossMovement.h"
#include <iostream>

using std::cout;
using std::endl;

BossMovement::BossMovement(std::string nameP, float stepP, bool forwardP, float* gapP, float tokenCostP, float* tokenP) :
	Action{ nameP },
	step{ stepP },
	forward{ forwardP },
	gap{ gapP },
	tokenCost{ tokenCostP },
	token{tokenP}
{
}

BossMovement::~BossMovement()
{
}

void BossMovement::execute()
{
	if (forward) {
		cout << "Rydnir takes " << step << " steps towards the player";

		*gap -= step;
	}
	else {
		cout << "Rydnir takes " << step << " steps away from the player";

		*gap += step;
	}

	cout << " for " << tokenCost << " token";
	if (tokenCost > 1.0f) cout << "s";
	cout << endl;

	*token += tokenCost;
}
