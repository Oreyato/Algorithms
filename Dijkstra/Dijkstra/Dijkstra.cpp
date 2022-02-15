#include <iostream>
#include "NodeRecord.h"

int main()
{
	//v Graph initialization =========================================
	// Create a big number to simulate an impossible path
	float bNum = 10000;
	int graph[7][7] = {
		// A,		B,		C,		D,		E,		F,		G
		{  0,		15,		22,		bNum,	bNum,	bNum,	bNum},		// A
		{  15,		0,		bNum,	20,		18,		bNum,	bNum},		// B
		{  22,		bNum,	0,		16,		bNum,	42,		bNum},		// C
		{  bNum,	20,		16,		0,		bNum,	bNum,	bNum},		// D
		{  bNum,	18,		5,		bNum,	0,		15,		25},		// E
		{  bNum,	bNum,	42,		bNum,	15,		0,		10},		// F
		{  bNum,	bNum,	bNum,	bNum,	25,		10,		0}			// G
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
	// open = PathFindingList();
	// open += startRecord;
	// closed = PathFindingList();

	// Iterate through processing each node
	// while (open.length() > 0)
	{
		// Find the smallest element in the open list
	}
}