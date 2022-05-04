#pragma once
#include <iostream>
#include <string>

class Character
{
public: 
	Character(std::string nameP, float maxHealthP, float* gapP);

	void setName(std::string nameP) { name = nameP; }
	void setMaxHealth(float& maxHealthP) { maxHealth = maxHealthP; }
	void setHealth(float& healthP) { health = healthP; }
	void setTarget(Character* targetP) { target = targetP; }

	const std::string getName() { return name; }
	const float getHealth() { return health; }
	const Character* getTarget() { return target; }
	const bool getDeathStatus() { return isDead; }

	void hurt(float damageP);
	void kill() { isDead = true; }

protected:
	std::string name{ "" };

	float maxHealth{ 0 };
	float health{ 0 };

	Character* target{ nullptr };
	float* gap{ nullptr };

	bool isDead{ false };
};