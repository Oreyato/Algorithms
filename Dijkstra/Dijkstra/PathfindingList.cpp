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
	return NodeRecord();
}

bool PathfindingList::isContained()
{
	return false;
}
