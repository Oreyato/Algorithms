#pragma once
#include "Action.h"
#include "PlayableCharacter.h"

class BossAttack :
    public Action
{
public:
    BossAttack(std::string nameP, float damageP, float tokenCostP, float pickP, float missP, PlayableCharacter* targetP);
    ~BossAttack();

    const float getDamage() { return damage; }
    const float getTokenCost() { return tokenCost; }
    const float getPickProbability() override { return pickProbability; }
    const float getMissProbability() { return missProbability; }

    void setPickProbability(float pickProbabilityP) { pickProbability = pickProbabilityP; }
    void execute() override;
    bool choosable() override { return true; }

private:
    float damage{ 0.0f };
    float tokenCost{ 0.0f };
    float pickProbability{ 0.0f };
    float missProbability{ 0.0f };

    PlayableCharacter* target;
};

