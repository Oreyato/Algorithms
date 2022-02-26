#include <iostream>
#include "PathfindingList.h"
#include "Graph.h"

std::vector<std::string> pathfindDijkstra(Graph graph, int startNode, int goalNode) {
	// Initialise the record for the start node
	NodeRecord startRecord = NodeRecord();
	startRecord.node = startNode;
	startRecord.connection = {};
	startRecord.costSoFar = 0;

	// Initialize the current node
	NodeRecord current = startRecord;

	// Initialise the record for the end node
	NodeRecord endRecord = NodeRecord();
	float endNodeCost = 0;

	// Initialise the open and closed lists
	PathfindingList open;
	open.add(startRecord);
	PathfindingList closed;

	// Algo outputs header
	std::cout << std::endl;
	std::cout << "[========] Processing Algo [========]" << std::endl;

	// Iterate through processing each node
	while (open.getLength() > 0)
	{
		// Find the smallest element in the open list
		current = open.getSmallestElement();
		std::cout << "Current node: " << current.node << std::endl;

		// If it is the goal node, then terminate
		if (current.node == goalNode) break;

		// Otherwise, get its outgoing connections
		std::vector<Connection> connections = graph.getConnections(current);

		// Loop through each connection in turn
		for (Connection connection : connections)
		{
			std::cout << "Current connection: " << connection.getFromNode() << " -> " << connection.getToNode() << " | " << connection.getCost() << std::endl;

			//Get the cost estimate for the end node
			endRecord.node = connection.getToNode();
			endNodeCost = current.costSoFar + connection.getCost();
			
			// Skip if the node is closed
			if (closed.contains(endRecord.node)) {
				continue;
			}
			// ... or if it is open and we have found a worse route
			// MUCH PROBABLY AN ISSUE HERE ============
			else if (open.contains(endRecord.node)) {
				// Here we find the record in the open list corresponding to the endNode
				endRecord = open.find(endRecord.node);
				if (endRecord.costSoFar <= endNodeCost) continue;
			}
			// =========================================
			// Otherwise we know we've got an unvisited node, so make a record for it
			else {
				NodeRecord endRecord = NodeRecord();
				endRecord.node = current.node;
				//endRecord.connection = connection;
				//endRecord.costSoFar = endNodeCost;
			}

			// At this point we need to update the node
			// Update the cost and connection
			endRecord.costSoFar = endNodeCost;
			endRecord.connection = connection;

			// And add it to the open list
			if (!open.contains(endRecord.node)) {
				open.add(endRecord);
			}
		}

		// We have finished looking at the connections for the current node,
		// so add it to the closed list and remove it from the open one
		open.remove(current);
		closed.add(current);
	}

	// At this point we either found the goal or, 
	// if we've no more nodes to search, find which
	if (current.node != goalNode) {
		// We have run out of nodes without finding the goal, so there's no solution
		std::vector<std::string> noPath;
		return noPath;
	}
	else {
		// Compile the list of connections in the path
		std::vector<int> nodesPath;

		// Work back along the path, accumulating connections
		while (current.node != startNode) {
			nodesPath.push_back(current.node);
			current = closed.find(current.connection.getFromNode());
		}
		// Adding the startNode
		nodesPath.push_back(current.node);

		// Reverse the path
		std::reverse(nodesPath.begin(), nodesPath.end());

		// Translate it into a corresponding string of names
		const std::string* names = graph.getNodesNames();
		std::vector<std::string> pathWithNames;
		for (int i = 0; i < nodesPath.size(); i++)
		{
			pathWithNames.push_back(names[nodesPath[i]]);
		}
		std::cout << "[===================================]" << std::endl;

		// Return it
		return pathWithNames;
	}
}

void coutPath(std::vector<std::string> pathP) {
	std::cout << std::endl;
	std::cout << "[=============] Path [==============]" << std::endl;
	if (pathP.size() > 0)
	{
		for (auto i = 0; i < pathP.size() - 1; i++)
		{
			std::cout << pathP[i] << " -> ";
		}
		std::cout << pathP[pathP.size() - 1] << std::endl;
	}
	else {
		std::cout << "There is no path" << std::endl;
	}
	std::cout << "[===================================]" << std::endl;
}

int main()
{
	Graph graph = Graph();
	graph.displayConnections();

	std::vector<std::string> path = pathfindDijkstra(graph, 0, 5);
	coutPath(path);
}