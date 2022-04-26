#include "Action.h"
#include <iostream>

Action::Action(std::string nameP) :
	name(nameP)
{
}

void Action::execute()
{
	std::cout << name << std::endl;
}
