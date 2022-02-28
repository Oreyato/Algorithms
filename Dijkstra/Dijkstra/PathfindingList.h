#pragma once
#include "NodeRecord.h"
#include <vector>

class PathfindingList
{
public:
	PathfindingList();
	~PathfindingList();

	void add(NodeRecord nodeP);
	void remove(NodeRecord nodeP);

	NodeRecord getSmallestElement();
	NodeRecord getSmallestElement(int aStar);
	const bool contains(int nodeP) const;
	const NodeRecord find(int nodeP) const;

	std::vector<NodeRecord> getList() { return nodes; }
	int getLength() { return length; }

private:
	std::vector<NodeRecord> nodes;
	int length;
};