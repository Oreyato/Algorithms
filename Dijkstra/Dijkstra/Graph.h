#pragma once
#include "Connection.h"
#include "NodeRecord.h"
#include <vector>
#include <string>

class Graph
{
public:
	Graph();
	~Graph();

	const std::string* getNodesNames() { return nodesNames; }
	const std::vector<Connection> getConnections(NodeRecord nodeP) const;
	const void displayConnections() const;

private:
	std::vector<Connection> connections;
	std::string nodesNames[7];
};

