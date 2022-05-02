#pragma once

#include <string>

class Weapon
{
public:
	Weapon(std::string nameP, float damageP, float rangeP, float tokenCostP, float missProbabilityP = 0.0f) :
		name{ nameP },
		damage{damageP},
		range{rangeP},
		tokenCost{tokenCostP},
		missProbability{missProbabilityP}
	{
	};

	const std::string getName() { return name; }
	const float getDamage() { return damage; }
	const float getRange() { return range; }
	const float getTokenCost() { return tokenCost; }
	const float getMissProbability() { return missProbability; }

private:
	std::string name{ "" };

	float damage{ 0.0f };
	float range{ 0.0f };
	float tokenCost{ 0.0f };
	float missProbability{ 0.0f };
};

