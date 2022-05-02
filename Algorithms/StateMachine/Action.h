#pragma once
#include <string>

class Action
{
public:
	Action(std::string nameP);
	void execute();

protected:
	std::string name;
};