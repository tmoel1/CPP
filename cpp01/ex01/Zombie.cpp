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

void Zombie::setName(std::string name)
{
	_name = name;
}

// definition here for setName? No i think in the zombieHoard makes more sense
// except if it *needs* to be in the class to have access to _name?
