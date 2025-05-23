#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie stack(name);
	stack.announce();
} //auto deleted as soon as function ends ordinarily