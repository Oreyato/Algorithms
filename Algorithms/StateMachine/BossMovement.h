#pragma once
#include "Action.h"

class BossMovement :
    public Action
{
public:
    BossMovement(std::string nameP, float stepP, bool forwardP, float* gapP, float tokenCostP, float* tokenP);
    ~BossMovement();

    void execute() override;

    float getStep() { return step; }
    bool getForward() { return forward; }

private:
    float step{ 0.0f };
    bool forward{ true };
    float* gap{ nullptr };
    float tokenCost{ 0.0f };
    float* token{ nullptr };
};

