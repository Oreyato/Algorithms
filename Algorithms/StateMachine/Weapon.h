#pragma once

#include <string>

class Weapon
{
public:
	Weapon(std::string nameP, float damageP, float tokenCostP, float missProbabilityP = 0.0f) :
		name{ nameP },
		damage{damageP},
		tokenCost{tokenCostP},
		missProbability{missProbabilityP}
	{};

	const std::string getName() { return name; }
	const float getDamage() { return damage; }
	const float getTokenCost() { return tokenCost; }
	const float getMissProbability() { return missProbability; }

private:
	std::string name{ "" };

	float damage{ 0 };
	float tokenCost{ 0 };
	float missProbability{ 0 };
};

