#pragma once

class Connection
{
public:
	Connection();
	~Connection();

	const float getCost() const { return cost; }
	const int getFromNode() const { return fromNode; }
	const int getToNode() const { return toNode; }

private:
	float cost;
	int fromNode;
	int toNode;
};

