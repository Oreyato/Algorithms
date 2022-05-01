#pragma once
#include <string>

class Character
{
public: 
	Character(std::string nameP, float maxHealthP) : name{ nameP }, maxHealth{ maxHealthP }, health{ maxHealth } {};

	void setName(std::string nameP) { name = nameP; }
	void setMaxHealth(float& maxHealthP) { maxHealth = maxHealthP; }
	void setHealth(float& healthP) { health = healthP; }

	const std::string getName() { return name; }
	const float getHealth() { return health; }

	void hurt(float damageP) { health -= damageP; }

protected:
	std::string name{ "" };

	float maxHealth{ 0 };
	float health{ 0 };
};

