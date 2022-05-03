#pragma once
#include <string>

class Action
{
public:
	Action(std::string nameP);

	virtual const float getPickProbability() { return 0.0f; }

	virtual void execute();
	virtual bool choosable();

protected:
	std::string name;
};