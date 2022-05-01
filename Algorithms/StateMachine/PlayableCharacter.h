#pragma once
#include "Character.h"

#include "Weapon.h"

#include <vector>

class PlayableCharacter :
    public Character
{
public:
    PlayableCharacter(std::string nameP, float maxHealthP, Weapon* currentWeaponP);
    ~PlayableCharacter() { delete currentWeapon; }

    void switchWeapon();
    void setEquippedWeapon(Weapon* targetWeapon) { currentWeapon = targetWeapon; }
    void setWeapons(std::vector<Weapon*> weaponsP);

    void chooseAction();

private:
    Weapon* currentWeapon{ nullptr };
    float tokens{ 0.0f };

    std::vector<Weapon*> weapons;
};

