#include <iostream>
#include "PathfindingList.h"
#include "Connection.h"

int main()
{
	//v Graph initialization =========================================
	// Create a big number to simulate an impossible path
	float bNum = 10000.0f;
	int graph[7][7] = {
		// A,		B,		C,		D,		E,		F,		G
		{  0.f,		15.f,	22,		bNum,	bNum,	bNum,	bNum},		// A
		{  15.f,	0.f,	bNum,	20.f,	18.f,	bNum,	bNum},		// B
		{  22.f,	bNum,	0.f,	16.f,	bNum,	42.f,	bNum},		// C
		{  bNum,	20.f,	16.f,	0.f,	bNum,	bNum,	bNum},		// D
		{  bNum,	18.f,	5.f,	bNum,	0.f,	15.f,	25.f},		// E
		{  bNum,	bNum,	42.f,	bNum,	15.f,	0.f,	10.f},		// F
		{  bNum,	bNum,	bNum,	bNum,	25.f,	10.f,	0.f}		// G
	};
	//^ ==============================================================
}

// The parameters will change to this, later on:
// [array] pathfindDijkstra(int graph[7][7], int startNode, int endNode)
void pathfindDijkstra(int graph[7][7], int startNode, int endNode) {
	// Initialise the record for the start node
	NodeRecord startRecord = NodeRecord();
	startRecord.node = startNode;
	// startRecord.connection = ;
	startRecord.costSoFar = 0;

	// Initialise the open and closed lists
	PathfindingList open;
	open.add(startRecord);
	PathfindingList closed;

	// Iterate through processing each node
	while (open.getLength() > 0)
	{
		// Find the smallest element in the open list
	}
}