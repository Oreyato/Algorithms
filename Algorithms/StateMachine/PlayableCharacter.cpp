#include "PlayableCharacter.h"

using namespace std;

PlayableCharacter::PlayableCharacter(std::string nameP, float maxHealthP, Weapon* currentWeaponP, float* gapP) : 
	Character{ nameP, maxHealthP, gapP },
	currentWeapon{currentWeaponP}
{
}

void PlayableCharacter::switchWeapon()
{
}

void PlayableCharacter::setWeapons(std::vector<Weapon*> weaponsP)
{
}

void PlayableCharacter::chooseAction()
{
	tokens = 2.0f; // <--- TEMP

	bool isChoosing = true;
	bool canAttack = false;

	while (tokens > 0.0f) {
		float weaponDamage = currentWeapon->getDamage();

		cout << "\nWhat would " << name << " do? (enter a number)" << endl;

		if (*gap <= currentWeapon->getRange()) {
			canAttack = true;

			cout << "\t1 - ATTACK (" << weaponDamage << " dmg) [" << currentWeapon->getTokenCost() << " t.]" << endl;
		}
		else {
			cout << "\tx - YOU ARE TOO FAR AWAY TO USE THIS WEAPON" << endl;
		}
		cout << "\t2 - CHANGE WEAPON [0 t.]" << endl;
		cout << "\t3 - GO FORWARD [0,5 t.]" << endl;
		cout << "\t4 - GO BACKWARD [0,5 t.]" << endl;

		cout << "\tTOKEN: " << tokens << flush << endl;

		int decision = -1;
		cin >> decision;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a number" << endl;
		}
		else {
			switch (decision)
			{
			case 1:
				if (canAttack)
				{
					isChoosing = false;
					// Attack the dragon
					target->hurt(weaponDamage);
				}
				cout << "You can't use this weapon\nPlease enter a proper number" << endl;

				break;

			case 2:
				isChoosing = false;
				switchWeapon();
				break;

			case 3:
				isChoosing = false;
				// Going forward
				*gap -= 1;

				cout << "You take a step forward" << endl;
				cout << "Current distance: " << *gap << endl;

				tokens -= 0.5f;

				break;

			case 4:
				isChoosing = false;
				// Going backward
				*gap += 1;

				cout << "You take a step back" << endl;
				cout << "Current distance: " << *gap << endl;

				tokens -= 0.5f;

				break;

			default:
				cout << "Please enter a proper number" << endl;
				break;
			}
		}
	}
}
