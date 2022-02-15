#pragma once
#include "NodeRecord.h"

class PathfindingList
{
public:
	PathfindingList();
	~PathfindingList();

	void add(NodeRecord nodeP);
	void remove(NodeRecord nodeP);

	NodeRecord getSmallestElement();
	bool isContained();

private:

};

PathfindingList::PathfindingList()
{
}

PathfindingList::~PathfindingList()
{
}

inline void PathfindingList::add(NodeRecord nodeP)
{
}

inline void PathfindingList::remove(NodeRecord nodeP)
{
}

inline NodeRecord PathfindingList::getSmallestElement()
{
	return NodeRecord();
}

inline bool PathfindingList::isContained()
{
	return false;
}
