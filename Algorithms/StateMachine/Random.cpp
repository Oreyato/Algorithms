#include "Random.h"

Random::Random()
{
}

Random::~Random()
{
}

const BossAttack* Random::pickBetween(std::vector<BossAttack*> attacksP)
{
	int randNum = rand() % 100 + 1;
	int out = 0;

	float totalPickProb{ 0.0f };

	for (int i = 0; i < attacksP.size(); i++)
	{
		totalPickProb += attacksP[i]->getPickProbability()*10.0f;

		if (randNum <= totalPickProb)
		{
			out = i;

			break;
		}
	}

	return attacksP[out];
}
