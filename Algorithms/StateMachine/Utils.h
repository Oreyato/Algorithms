#pragma once
#include <ctime>
#include <stdlib.h>
#include <vector>

#include "BossAttack.h"

namespace util {

	template <typename T>
	const T* pickBetween(std::vector<T*> a) {
		int randNum = rand() % 100 + 1;
		int out = 0;

		float totalPickProb{ 0.0f };

		for (int i = 0; i < a.size(); i++)
		{
			totalPickProb += a[i]->getPickProbability() * 10.0f;

			if (randNum <= totalPickProb)
			{
				out = i;

				break;
			}
		}

		return a[out];
	}
	template<>
	const BossAttack* pickBetween(std::vector<BossAttack*> attackP)
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
