#include <iostream>
#include "PathfindingList.h"
#include "Graph.h"
#include "Heuristic.h"

std::vector<std::string> pathfindDijkstra(Graph graph, int startNode, int goalNode) {
	// Initialise the record for the start node
	NodeRecord startRecord = NodeRecord();
	startRecord.node = startNode;

	// Initialize the current node
	NodeRecord current = startRecord;

	// Initialize the end node
	int endNode;
	float endNodeCost = 0;

	// Initialise the record for the end node
	NodeRecord endNodeRecord = NodeRecord();

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
			endNode = connection.getToNode();
			endNodeCost = current.costSoFar + connection.getCost();
			
			// Skip if the node is closed
			// We skip here because Dijkstra algorithm will never find a better route to a closed node,
			// but this isn't true for the A* algorithm
			if (closed.contains(endNode)) continue;
			// ... or if it is open and we have found a worse route
			else if (open.contains(endNode)) {
				// Here we find the record in the open list corresponding to the endNode
				endNodeRecord = open.find(endNode); // <<<---------------------------------------
				if (endNodeRecord.costSoFar <= endNodeCost) continue;
				// Otherwise we know we've got an unvisited node, so make a record for it
				else {
					open.remove(endNodeRecord);
					endNodeRecord.costSoFar = endNodeCost;
					endNodeRecord.node = current.node;
					open.add(endNodeRecord);
				}
			}
			// At this point we need to update the node
			// Update the cost and connection
			endNodeRecord.node = endNode;
			endNodeRecord.costSoFar = endNodeCost;
			endNodeRecord.connection = connection;

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
		std::vector<std::string> noPath;
		return noPath;
	}
	else {
		// Compile the list of connections in the path
		std::vector<int> nodesPath;

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

std::vector<std::string> pathfindAStar(Graph graph, int startNode, int goalNode) {
	// Initialise heuristic
	Heuristic heuristic;

	// Initialise the record for the start node
	NodeRecord startRecord;
	startRecord.node = startNode;
	startRecord.connection = {};
	startRecord.costSoFar = 0.f;
	startRecord.estimatedTotalCost = heuristic.estimate(startNode);

	// Initialize the current node
	NodeRecord current = startRecord;

	// Initialize the end node
	NodeRecord endNode;
	endNode.node = 0;
	endNode.costSoFar = 0.f;
	endNode.estimatedTotalCost = 0.f;

	// Initialise the record for the end node
	NodeRecord endNodeRecord = NodeRecord();

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
		// using the estimatedTotalCost this time
		current = open.getSmallestElement(0);
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
			endNode.node = connection.getToNode();
			endNode.costSoFar = current.costSoFar + connection.getCost();

			// If the node is closed
			if (closed.contains(endNode.node)) {
				// Here we find the record in the closed list corresponding to the endNode
				endNodeRecord = closed.find(endNode.node);

				// If we didn't find a shorter route, skip
				if (endNodeRecord.costSoFar <= endNode.costSoFar) continue;
				// Otherwise, remove it from the closed list
				else {
					closed.remove(endNodeRecord);
				
					// We can use the node's old cost values to calculate its heuristic
					// without calling the possibly expensive heuristic function
					endNode.estimatedTotalCost = endNodeRecord.estimatedTotalCost - endNodeRecord.costSoFar;
				}

				//continue;
			}
			// ... or if it is open and we have found a worse route
			else if (open.contains(endNode.node)) {
				// Here we find the record in the open list corresponding to the endNode
				endNodeRecord = open.find(endNode.node); 
				if (endNodeRecord.costSoFar <= endNode.costSoFar) continue;
				// Otherwise we know we've got an unvisited node, so make a record for it
				else {
					open.remove(endNodeRecord);
					endNodeRecord.costSoFar = endNode.costSoFar;
					endNodeRecord.node = current.node;
					open.add(endNodeRecord);
				}
			}
			// At this point we need to update the node
			// Update the cost and connection
			endNodeRecord.node = endNode.node;
			endNodeRecord.costSoFar = endNode.costSoFar;
			endNodeRecord.connection = connection;

			// And add it to the open list
			if (!open.contains(endNode.node)) {
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
		std::vector<std::string> noPath;
		return noPath;
	}
	else {
		// Compile the list of connections in the path
		std::vector<int> nodesPath;

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

	//std::vector<std::string> path = pathfindDijkstra(graph, 0, 5);
	std::vector<std::string> path = pathfindAStar(graph, 0, 5);
	coutPath(path);
}