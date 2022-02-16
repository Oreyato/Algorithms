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
	bool isContained();

	std::vector<NodeRecord> getList() { return nodes; }
	int getLength() { return length; }

private:
	std::vector<NodeRecord> nodes;
	int length;
};