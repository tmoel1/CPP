#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Unnamed Default ClapTrap"), _hitPoints(_kDefaultHealth),
						_energyPoints(_kDefaultEnergy), _attackDamage(_kDefaultAttack)
{
	std::cout << "ClapTrap Class " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(_kDefaultHealth),
						_energyPoints(_kDefaultEnergy), _attackDamage(_kDefaultAttack)
{
	std::cout << "ClapTrap Class " << _name << " named constructer called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints),
						_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Class " << _name << " copy-constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}

	std::cout << "ClapTrap Class " << _name << " copy-assignment called" << std::endl;

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Class " << _name << " destructor called" << std::endl;
}

// action go here: