#include "BossAttack.h"
#include "Utils.h"

#include <iostream>

BossAttack::BossAttack(std::string nameP, float damageP, float tokenCostP, float pickP, float missP, PlayableCharacter* targetP) :
	Action{nameP},
	damage{damageP},
	tokenCost{tokenCostP},
	pickProbability{pickP},
	missProbability{missP},
	target{targetP}
{
}

BossAttack::~BossAttack()
{
}

void BossAttack::execute()
{
	std::cout << "Rydnir uses \"" << name << "\" for " << tokenCost << " token";
	if (tokenCost > 1.0f) std::cout << "s";


	if (util::success(missProbability)) {
		std::cout << std::endl;

		target->hurt(damage);
	}
	else {
		std::cout << " but misses" << std::endl;
	}

	target->addTokens(tokenCost);
}
