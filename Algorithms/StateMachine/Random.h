#pragma once
#include <ctime>
#include <stdlib.h>
#include <vector>

#include "BossAttack.h"

class Random
{
public:
	Random();
	~Random();

	const BossAttack* pickBetween(std::vector<BossAttack*> attacksP);

private:

};