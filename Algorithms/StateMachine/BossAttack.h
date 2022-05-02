#pragma once
#include "Action.h"

class BossAttack :
    public Action
{
public:
    BossAttack();
    ~BossAttack();

    const float getDamage() { return damage; }
    const float getTokenCost() { return tokenCost; }
    const float getPickProbability() { return pickProbability; }
    const float getMissProbability() { return missProbability; }

    void setPickProbability(float pickProbabilityP) { pickProbability = pickProbabilityP; }

private:
    float damage{ 0.0f };
    // float range{ 0.0f }; // <--- à priori pas besoin, géré par la StateMachine
    float tokenCost{ 0.0f };
    float pickProbability{ 0.0f };
    float missProbability{ 0.0f };

};

