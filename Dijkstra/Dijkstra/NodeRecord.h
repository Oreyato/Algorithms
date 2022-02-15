#pragma once
#include "Connection.h"

struct NodeRecord
{
	int node;
	Connection connection;
	float costSoFar;
};