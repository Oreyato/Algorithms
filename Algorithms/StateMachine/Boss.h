#pragma once
#include "Character.h"
class Boss :
    public Character
{
public:
    Boss(std::string nameP, float maxHealthP) : Character{ nameP, maxHealthP } {};

private:
    int currentPhase{ 0 };

};

