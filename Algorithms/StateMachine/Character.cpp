#include "Character.h"

Character::Character(std::string nameP, float maxHealthP, float* gapP) :
	name{ nameP }, 
	maxHealth{ maxHealthP }, 
	health{ maxHealth },
	gap{gapP}
{}

void Character::hurt(float damageP) {
	health -= damageP;

	std::cout << name << " received " << damageP << " damage";
	std::cout << "\nThey now have " << health << " hp" << std::endl;
}