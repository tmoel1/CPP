#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (!_weapon)
		std::cout << _name << " has no weapon currently" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}