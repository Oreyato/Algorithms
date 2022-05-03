#include "Utils.h"

bool util::success(float missProbP) {
	int randNum = rand() % 100 + 1;
	bool successful = true;

	if (randNum > missProbP * 100) {
		return successful;
	}
	else return !successful;
}
