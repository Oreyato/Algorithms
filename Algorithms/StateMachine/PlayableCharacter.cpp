#include "PlayableCharacter.h"

using namespace std;

PlayableCharacter::PlayableCharacter(std::string nameP, float maxHealthP, Weapon* currentWeaponP, float* gapP, float* tokensP) :
	Character{ nameP, maxHealthP, gapP },
	currentWeapon{currentWeaponP},
	tokens{tokensP}
{
	weapons.push_back(currentWeapon);
}

void PlayableCharacter::displayWeapons()
{
	cout << name << "'s weapons: (enter a number)\n";
	string weaponName;
	float length = 25.0f;
	float nameLength;
	float damage, range, tokenCost;

	for (int i = 0; i < weapons.size(); i++) {
		// Get infos
		weaponName = weapons[i]->getName();
		nameLength = weaponName.length();
		damage = weapons[i]->getDamage();
		range = weapons[i]->getRange();
		tokenCost = weapons[i]->getTokenCost();

		// Display infos
		cout << "\t" << i << "- " << weaponName;;
		if (currentWeapon == weapons[i]) {
			cout << " (eq.)";

			// Make sure that the "damage part" starts a the same xPos everytime
			for (int i = 0; i < length - (nameLength + 6.0f); i++)
			{
				cout << " ";
			}

		} 
		else {
			// Make sure that the "damage part" starts a the same xPos everytime
			for (int i = 0; i < length - nameLength; i++)
			{
				cout << " ";
			}
		}

		// Managing range
		cout << "   | damage: " << damage << "    | range: " << range << "(";
		
		if (range >= *gap) {
			cout << "ok";
		}
		else {
			cout << range - *gap;
		}

		cout << ")  | token cost: " << tokenCost << endl;
	}
}

bool PlayableCharacter::getWeaponByIndex(float weaponIndex, Weapon* weaponP) {
	int itemsNumber = weapons.size();

	if (0 <= weaponIndex && weaponIndex < itemsNumber) {
		weaponP = weapons[weaponIndex];
	}
	else {
		weaponIndex = -1;
	}

	return (weaponIndex != -1);
}

void PlayableCharacter::switchWeapon()
{
	displayWeapons();

	bool isChoosing = true;
	int itemIndex;

	while (isChoosing) {
		//	SELECTING BY NUMBER
		itemIndex = 0;
		cin >> itemIndex;

		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a number" << endl;
			continue;
		}
		else {
			Weapon* i = nullptr;
			if (getWeaponByIndex(itemIndex, i)) {
				if (currentWeapon != weapons[itemIndex])
				{
					currentWeapon = weapons[itemIndex];

					cout << name << " equipped \"" << currentWeapon->getName() << "\"" << endl;
				}
				else {
					cout << "\"" << currentWeapon->getName() << "\" is already equipped\nReturn to previous screen" << endl;
				}
				isChoosing = false;
			}
			else {
				cout << "Please enter a proper number" << endl;
			}
		}
	}
}

void PlayableCharacter::setWeapons(std::vector<Weapon*> weaponsP)
{
}

void PlayableCharacter::chooseAction()
{
	bool canAttack = false;

	cout << "==x==x= PLAYER'S TURN =x==x==" << endl;
	
	while (*tokens > 0.0f) {
		float weaponDamage = currentWeapon->getDamage();
		float weaponCost = currentWeapon->getTokenCost();
		canAttack = false;

		cout << "\nWhat would " << name << " do? (enter a number)" << endl;

		if (*gap <= currentWeapon->getRange() && weaponCost <= *tokens) {
			canAttack = true;

			cout << "\t1 - ATTACK (" << weaponDamage << " dmg) [" << weaponCost << " t.]" << endl;
		}
		else if (weaponCost > *tokens) {
			cout << "\tx - NOT ENOUGH TOKEN TO USE THIS WEAPON" << endl;
		}
		else {
			float distance = *gap - currentWeapon->getRange();

			cout << "\tx - TOO FAR (" << distance << " steps) AWAY TO USE THIS WEAPON" << endl;
		}

		cout << "\t2 - CHANGE WEAPON [0 t.]" << endl;
		cout << "\t3 - GO FORWARD [0,5 t.]" << endl;
		cout << "\t4 - GO BACKWARD [0,5 t.]" << endl;
		cout << "\t5 - END TURN (loose remaining tokens)" << endl;

		cout << "\tTOKEN: " << *tokens << flush << endl;

		int decision = -1;
		cin >> decision;
		cout << "==x==x==x==x==x==x==x==x==x==" << endl;

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
					// Attack the dragon
					target->hurt(weaponDamage);

					*tokens -= currentWeapon->getTokenCost();
				}
				else cout << "You can't use this weapon\nPlease enter a proper number" << endl;
				cout << "==x==x==x==x==x==x==x==x==x==" << endl;

				break;

			case 2:
				switchWeapon();
				cout << "==x==x==x==x==x==x==x==x==x==" << endl;
				break;

			case 3:
				// Going forward
				*gap -= 1;

				cout << "You take a step forward" << endl;
				cout << "Current distance: " << *gap << endl;
				cout << "==x==x==x==x==x==x==x==x==x==" << endl;

				*tokens -= 0.5f;

				break;

			case 4:
				// Going backward
				*gap += 1;

				cout << "You take a step back" << endl;
				cout << "Current distance: " << *gap << endl;
				cout << "==x==x==x==x==x==x==x==x==x==" << endl;

				*tokens -= 0.5f;

				break;
			
			case 5:
				*tokens = 0.0f;
				break;

			default:
				cout << "Please enter a proper number" << endl;
				cout << "==x==x==x==x==x==x==x==x==x==" << endl;
				break;
			}
		}
	}
}
