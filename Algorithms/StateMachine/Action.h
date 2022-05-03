#pragma once
#include <string>

class Action
{
public:
	Action(std::string nameP);
	virtual void execute();

protected:
	std::string name;
};