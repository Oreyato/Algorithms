#pragma once

class Connection
{
public:
	Connection();
	Connection(int fromNodeP, int toNodeP, float costP);
	~Connection();

	const int getFromNode() const { return fromNode; }
	const int getToNode() const { return toNode; }
	const float getCost() const { return cost; }

private:
	int fromNode;
	int toNode;
	float cost;
};

