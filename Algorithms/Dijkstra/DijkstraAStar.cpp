#include <iostream>
#include "PathfindingList.h"
#include "Graph.h"

using std::vector;
using std::string;

vector<string> pathfindAStar(Graph graph, int startNode, int goalNode) {
	vector<string> pouet{};



	return pouet;
}

vector<std::string> pathfindDijkstra(Graph graph, int startNode, int goalNode) {
	// Initialise the record for the start node
	NodeRecord startRecord = NodeRecord();
	startRecord.node = startNode;

	// Initialize the current node
	NodeRecord current = startRecord;

	// Initialize the end node
	int endNode;
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
		vector<Connection> connections = graph.getConnections(current);

		// Loop through each connection in turn
		for (Connection connection : connections)
		{
			std::cout << "Current connection: " << connection.getFromNode() << " -> " << connection.getToNode() << " | " << connection.getCost() << std::endl;

			//Get the cost estimate for the end node
			endNode = connection.getToNode();
			endNodeCost = current.costSoFar + connection.getCost();
			
			// Skip if the node is closed
			// We skip here because Dijkstra algorithm will never find a better route to a closed node,
			// but this isn't true for the A* algorithm
			if (closed.contains(endNode)) continue;
			// ... or if it is open
			else if (open.contains(endNode)) {
				// Here we find the record in the open list corresponding to the endNode
				NodeRecord endNodeRecord = open.find(endNode);
				// Skip if we found a worse route that the previous one
				if (endNodeRecord.costSoFar <= endNodeCost) continue;
				// Update the latest best record at this node with the new one
				else {
					open.remove(endNodeRecord);
					endNodeRecord.costSoFar = endNodeCost;
					endNodeRecord.node = current.node;
					open.add(endNodeRecord);
				}
			}

			// Otherwise we know we've got an unvisited node so we'll create a new record
			NodeRecord endNodeRecord{ endNode, connection, endNodeCost };

			// And add it to the open list
			if (!open.contains(endNode)) {
				open.add(endNodeRecord);
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
		vector<std::string> noPath;
		return noPath;
	}
	else {
		// Compile the list of connections in the path
		vector<int> nodesPath;

		// Get the total cost
		float totalCost = current.costSoFar;
		// Cout the total cost
		std::cout << std::endl;
		std::cout << "Found the best path, for " << totalCost << std::endl;

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
		vector<string> pathWithNames;
		for (int i = 0; i < nodesPath.size(); i++)
		{
			pathWithNames.push_back(names[nodesPath[i]]);
		}
		std::cout << "[===================================]" << std::endl;

		// Return it
		return pathWithNames;
	}
}

void coutPath(vector<string> pathP) {
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

	vector<string> path = pathfindDijkstra(graph, 0, 5);
	coutPath(path);
}