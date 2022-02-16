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
}

void PathfindingList::remove(NodeRecord nodeP)
{
	length--;
}

NodeRecord PathfindingList::getSmallestElement()
{
	// Use the first node.costSoFar as reference
	int min = nodes[0].costSoFar;
	int storedNode = 0;

	// Iterate through list of nodes, skipping the first one ^
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
	for (size_t i = 0; i < length; i++)
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