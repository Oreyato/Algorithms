#include "PlayableCharacter.h"
#include <iostream>

using namespace std;

PlayableCharacter::PlayableCharacter(std::string nameP, float maxHealthP, Weapon* currentWeaponP) : 
	Character{ nameP, maxHealthP },
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
	bool isChoosing = true;

	cout << "\nWhat would " << name << " do? (enter a number)" << endl;
	cout << "\t1 - ATTACK [" << currentWeapon->getTokenCost() << " t.]" << endl;
	cout << "\t2 - CHANGE WEAPON [0 t.]" << endl;
	cout << "\t3 - GO FORWARD [0,5 t.]" << endl;
	cout << "\t4 - GO BACKWARD [0,5 t.]" << endl;
	cout << "\tTOKEN: " << tokens << endl;

	while (isChoosing) {

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
				isChoosing = false;
				// faire des dégats au dragon


				break;

			case 2:
				isChoosing = false;
				switchWeapon();
				break;

			case 3:
				isChoosing = false;
				// avancer

				break;

			case 4:
				isChoosing = false;
				// reculer

				break;

			default:
				cout << "Please enter a proper number" << endl;
				break;
			}
		}
	}
}
