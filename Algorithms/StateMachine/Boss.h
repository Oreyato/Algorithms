#pragma once
#include "Character.h"
class Boss :
    public Character
{
public:
    Boss(std::string nameP, float maxHealthP, float* gapP) : Character{ nameP, maxHealthP, gapP } {};

private:
    int currentPhase{ 0 };

};

