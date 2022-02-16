#include "Connection.h"

Connection::Connection() :
	fromNode(0),
	toNode(0),
	cost(0.0f)
{
}

Connection::Connection(int fromNodeP, int toNodeP, float costP) :
	fromNode(fromNodeP),
	toNode(toNodeP),
	cost(costP)
{
}

Connection::~Connection()
{
}