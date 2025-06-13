#include "ScavTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
//#include <string>

ScavTrap::ScavTrap() : ClapTrap("Unnamed Default ScavTrap")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap class " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	
	std::cout << "ScavTrap class " << _name << " named constructer called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap class " << _name << " copy-constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	ClapTrap::operator=(rhs);

	std::cout << "ScavTrap class " << _name << " copy-assignment called" << std::endl;

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap class " << _name << " destructor called" << std::endl;
}

// action go here:

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack (no hit points left)" << std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack (no energy points left)" << std::endl;
		return;
	}

	--_energyPoints;

	std::cout << "ScavTrap " << _name << " attacks " << target << " in a scavvy way, causing "
				<< _attackDamage << " points of damage!" << std::endl;
}

// needs it;s own attack function, plus the new gatekeeping on, but how will it work for prints
// regarding healthpoints etc?

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap class " << _name << " is now in Gate keeper mode" << std::endl;

}