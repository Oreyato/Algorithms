#include "BossMovement.h"
#include <iostream>

using std::cout;
using std::endl;

BossMovement::BossMovement(std::string nameP, float stepP, bool forwardP, float* gapP) :
	Action{ nameP },
	step{ stepP },
	forward{ forwardP },
	gap{ gapP }
{
}

BossMovement::~BossMovement()
{
}

void BossMovement::execute()
{
	if (forward) {
		cout << "Rydnir takes " << step << " steps towards the player" << endl;

		*gap -= step;
	}
	else {
		cout << "Rydnir takes " << step << " steps away from the player" << endl; 

		*gap += step;
	}
}
