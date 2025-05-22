#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& n) : _name(n) {}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}