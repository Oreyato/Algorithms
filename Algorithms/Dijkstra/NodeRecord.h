#pragma once
#include "Connection.h"

struct NodeRecord
{
	int node;
	Connection connection;
	float costSoFar;

	bool operator == (NodeRecord const& obj) {
		if (this->node == obj.node) {
			return true;
		}
		else {
			return false;
		}
	}
};