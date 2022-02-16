#include "Graph.h"
#include <iostream>

Graph::Graph()
{
	//v Graph initialization =========================================
	// Create a big number to simulate an impossible path
	float bNum = 10000.0f;
	
	// Initialize graph size
	const int row = 7;
	const int column = 7;
	
	// Initialize nodes names
	std::string tmpNames[7]{ "A", "B", "C", "D", "E", "F", "G"};
	nodesNames->resize(7);
	const int nodesNamesSize = nodesNames->size();

	for (size_t i = 0; i < nodesNamesSize; i++)
	{
		nodesNames[i] = tmpNames[i];
	}

	float graph[row][column] = {
		// A,		B,		C,		D,		E,		F,		G
		{  0.f,		15.f,	22.f,	bNum,	bNum,	bNum,	bNum},	// A
		{  15.f,	0.f,	bNum,	20.f,	18.f,	bNum,	bNum},	// B
		{  22.f,	bNum,	0.f,	16.f,	bNum,	42.f,	bNum},	// C
		{  bNum,	20.f,	16.f,	0.f,	bNum,	bNum,	bNum},	// D
		{  bNum,	18.f,	5.f,	bNum,	0.f,	15.f,	25.f},	// E
		{  bNum,	bNum,	42.f,	bNum,	15.f,	0.f,	10.f},	// F
		{  bNum,	bNum,	bNum,	bNum,	25.f,	10.f,	0.f}	// G
	};
	//^ ==============================================================

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++) {
			if ((graph[i][j] != bNum) && (graph[i][j] != 0)) {
				Connection connection = Connection(i, j, graph[i][j]);
				connections.push_back(connection);
			}
		}
	}
}

Graph::~Graph()
{
}

const void Graph::displayConnections() const
{
	std::cout << "[==========] Connections [==========]" << std::endl;
	for (size_t i = 0; i < connections.size(); i++)	{
		int fromNode = connections[i].getFromNode();
		int toNode = connections[i].getToNode();
		std::cout << nodesNames[fromNode] << "\t->\t" << nodesNames[toNode] << "\t:\t" << connections[i].getCost() << std::endl;
	}
	std::cout << "[===================================]" << std::endl;
}
