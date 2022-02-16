#pragma once
#include "Connection.h"
#include <vector>
#include <string>

class Graph
{
public:
	Graph();
	~Graph();

	const std::vector<Connection> getConnections() const { return connections; }
	const void displayConnections() const;

private:
	std::vector<Connection> connections;
	//std::vector<std::string> nodesNames;
	std::string nodesNames[7];
};

