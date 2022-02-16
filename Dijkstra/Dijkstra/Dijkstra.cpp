#include "PathfindingList.h"
#include "Graph.h"

std::string pathfindDijkstra(Graph graph, int startNode, int endNode) {
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
		//for (Connection connection : connections)
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

	// At this point we either found the goal or, 
	// if we've no more nodes to search, find which
	//if (current.node != endNode) {
		// We have run out of nodes without finding the goal, so there's no solution
		//return "There's no path";
	//}
	/*
	else {
		// Compile the list of connections in the path
		int path = [];

		// Work back along the path, accumulating connections
		while (current.node != startNode) {
			path += current.connection;
			current = current.connection.getFromNode();
		}

		// Reverse the path and return it
		return reverse(path);
	}
	*/

	return "Temp";
}

int main()
{
	Graph graph = Graph();
	graph.displayConnections();

	pathfindDijkstra(graph, 0, 5);
}