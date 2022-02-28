#include "PathfindingList.h"

PathfindingList::PathfindingList() :
	length(0)
{
}

PathfindingList::~PathfindingList()
{
}

void PathfindingList::add(NodeRecord nodeP)
{
	length++;
	nodes.push_back(nodeP);
}

void PathfindingList::remove(NodeRecord nodeP)
{
	length--;
	std::vector<NodeRecord>::iterator it = std::find(nodes.begin(), nodes.end(), nodeP);
	nodes.erase(it);
}

NodeRecord PathfindingList::getSmallestElement()
{
	// Use the first node.costSoFar as reference
	int min = nodes[0].costSoFar;
	int storedNode = 0;

	// Iterate through list of nodes, skipping the first one because it already is the reference
	for (int i = 1; i < length; i++)
	{
		if (nodes[i].costSoFar < min) {
			min = nodes[i].costSoFar;
			storedNode = i;
		}
	}

	return nodes[storedNode];
}
// This one use the estimatedTotalCost, for the A* algorithm
NodeRecord PathfindingList::getSmallestElement(int aStar)
{
	// Use the first node.costSoFar as reference
	int min = nodes[0].costSoFar;
	int storedNode = 0;

	// Iterate through list of nodes, skipping the first one because it already is the reference
	for (int i = 1; i < length; i++)
	{
		if (nodes[i].costSoFar < min) {
			min = nodes[i].costSoFar;
			storedNode = i;
		}
	}

	return nodes[storedNode];
}

const bool PathfindingList::contains(int nodeP) const
{
	bool isContained = false;

	// Iterate through list of nodes
	for (int i = 0; i < length; i++)
	{
		// Is the current node of the list the same as the one we are looking for
		if (nodes[i].node == nodeP) {
			isContained = true;
			break;
		}
	}

	return isContained;
}

const NodeRecord PathfindingList::find(int nodeP) const
{
	int storedNode = 0;

	// Iterate through list of nodes
	for (int i = 0; i < length; i++)
	{
		if (nodes[i].node == nodeP) {
			storedNode = i;
			break;
		}
	}

	return nodes[storedNode];
}
