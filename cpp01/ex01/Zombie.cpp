#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}
//Zombie::Zombie(std::string name) : _name(name) {} no need now?

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// definition here for setName?
