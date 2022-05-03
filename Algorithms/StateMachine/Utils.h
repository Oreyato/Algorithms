#pragma once
#include <ctime>
#include <stdlib.h>
#include <vector>

namespace util {

	template <typename T>
	T* pickBetween(std::vector<T*> a) {
		return a[0];
	}

	template<>
	BossAttack* pickBetween <BossAttack> (std::vector<BossAttack*> attackP)
	{
		int randNum = rand() % 100 + 1;
		int out = 0;

		float totalPickProb{ 0.0f };

		for (int i = 0; i < attackP.size(); i++)
		{
			totalPickProb += attackP[i]->getPickProbability() * 10.0f;

			if (randNum <= totalPickProb)
			{
				out = i;

				break;
			}
		}

		return attackP[out];
	}

	bool success(float missProbP) {
		int randNum = rand() % 100 + 1;
		bool successful = true;

		if (randNum > missProbP * 100) {
			return successful;
		}
		else return !successful;
	}
}