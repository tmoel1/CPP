#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Unnamed Default FragTrap")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap class " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap class " << _name << " named constructer called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap class " << _name << " copy-constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	ClapTrap::operator=(rhs);

	std::cout << "FragTrap class " << _name << " copy-assignment called" << std::endl;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap class " << _name << " destructor called" << std::endl;
}


void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " cannot attack (no hit points left)" << std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " cannot attack (no energy points left)" << std::endl;
		return;
	}

	--_energyPoints;

	std::cout << "FragTrap " << _name << " attacks " << target << " with a fraggy attack, causing "
				<< _attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap class " << _name << " requests high fives!" << std::endl;
}
