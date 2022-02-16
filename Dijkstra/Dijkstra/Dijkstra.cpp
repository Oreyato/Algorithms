#include <iostream>
#include "PathfindingList.h"
#include "Connection.h"

int main()
{
	//v Graph initialization =========================================
	// Create a big number to simulate an impossible path
	float bNum = 10000.0f;
	float graph[7][7] = {
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
}

// The parameters will change to this, later on:
// [array] pathfindDijkstra(int graph[7][7], int startNode, int endNode)
void pathfindDijkstra(int graph[7][7], int startNode, int endNode) {
	// Initialise the record for the start node
	NodeRecord startRecord = NodeRecord();
	startRecord.node = startNode;
	// startRecord.connection = ;
	startRecord.costSoFar = 0;

	// Initialise the record for the end node
	NodeRecord endRecord = NodeRecord();
	endRecord.node = endNode;

	// Initialise the open and closed lists
	PathfindingList open;
	open.add(startRecord);
	PathfindingList closed;

	// Iterate through processing each node
	while (open.getLength() > 0)
	{
		// Find the smallest element in the open list
		NodeRecord current = open.getSmallestElement();

		// If it is the goal node, then terminate
		if (current.node == endNode) break;

		// Otherwise, get its outgoing connections
		//std::vector<Connection> connections = graph.getConnections(current);

		// Loop through each connection in turn
		//for each (connection in connections)
		//{
			//Get the cost estimate for the end node
			//endNode = connection.getToNode();
			//endNodeCost = current.costSoFar + connection.getCost();
			
			// Skip if the node is closed
			if (closed.contains(endNode)) {
				continue;
			}
			// ... or if it is open and we have found a worse route
			else if (open.contains(endNode)) {
				// Here we find the record in the open list corresponding to the endNode
				endRecord = open.find(endNode);
				//if (endRecord.costSoFar <= endNodeCost) continue;
			}
			// Otherwise we know we've got an unvisited node, so make a record for it
			else {
				NodeRecord* endRecord = new NodeRecord();
				endRecord->node = endNode;
			}

			// At this point we need to update the node
			// Update the cost and connection
			//endNode.cost = endNodeCost;
			//endNode.connection = connection;

			// And add it to the open list
			if (!open.contains(endNode)) {
				//open.add(endRecord);
			}
		//}

		// We have finished looking at the connections for the current node,
		// so add it to the closed list and remove it from the open one
		open.remove(current);
		closed.add(current);
	}
}