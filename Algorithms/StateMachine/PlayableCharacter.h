#pragma once
#include "Character.h"

#include "Weapon.h"

#include <vector>

class PlayableCharacter :
    public Character
{
public:
    PlayableCharacter(std::string nameP, float maxHealthP, Weapon* currentWeaponP, float* gapP, float* tokensP);
    ~PlayableCharacter() { delete currentWeapon; }

    void addWeapon(Weapon* weaponP) { weapons.push_back(weaponP); }
    void displayWeapons();
    bool getWeaponByIndex(float weaponIndex, Weapon* weaponP);
    void switchWeapon();
        
    void setEquippedWeapon(Weapon* targetWeapon) { currentWeapon = targetWeapon; }
    void setWeapons(std::vector<Weapon*> weaponsP);

    void addTokens(float valueP) { *tokens += valueP; }

    void chooseAction();

private:
    Weapon* currentWeapon{ nullptr };
    float* tokens{ nullptr };

    std::vector<Weapon*> weapons;
};

