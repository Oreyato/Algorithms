#include "BossAttack.h"
#include "Utils.h"

#include <iostream>

BossAttack::BossAttack(std::string nameP, float damageP, float tokenCostP, float pickP, float missP) :
	Action{nameP},
	damage{damageP},
	tokenCost{tokenCostP},
	pickProbability{pickP},
	missProbability{missP}
{
}

BossAttack::~BossAttack()
{
}

void BossAttack::execute()
{
	if (util::success(missProbability)) {
		std::cout << "Rydnir uses, \"" << name << "\" dealing " << damage << " damage" << std::endl;
	}
	else {
		std::cout << "Rydnir misses its attack" << std::endl;
	}
}
