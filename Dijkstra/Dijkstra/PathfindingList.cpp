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
	if (nodes.size() > 0) {
		length--;
		
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i].node == nodeP.node)
			{
				nodes.erase(nodes.begin() + i);
			}
		}
	}
}

NodeRecord PathfindingList::getSmallestElement()
{
	// Use the first node.costSoFar as reference
	int min = nodes[0].costSoFar;
	int storedNode = 0;

	// Iterate through list of nodes, skipping the first one because it already is the reference
	if (nodes.size() > 0)
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i].costSoFar < min) {
				min = nodes[i].costSoFar;
				storedNode = i;
			}
		}
	}

	return nodes[storedNode];
}

const bool PathfindingList::contains(int nodeP) const
{
	bool isContained = false;

	// Iterate through list of nodes
	if (nodes.size() > 0)
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			// Is the current node of the list the same as the one we are looking for
			if (nodes[i].node == nodeP) {
				isContained = true;
				break;
			}
}
	}

	return isContained;
}

const NodeRecord PathfindingList::find(int nodeP) const
{
	int storedNode = 0;

	// Iterate through list of nodes
	if (nodes.size() > 0)
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i].node == nodeP) {
				storedNode = i;
				break;
			}
		}
	}

	return nodes[storedNode];
}
