#pragma once
#include <string>

class Action
{
public:
	Action(std::string nameP);
	void execute();

private:
	std::string name;
};