#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() : _name("Unnamed Default ClapTrap"), _hitPoints(_kDefaultHealth),
						_energyPoints(_kDefaultEnergy), _attackDamage(_kDefaultAttack)
{
	std::cout << "ClapTrap class " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(_kDefaultHealth),
						_energyPoints(_kDefaultEnergy), _attackDamage(_kDefaultAttack)
{
	std::cout << "ClapTrap class " << _name << " named constructer called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints),
						_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap class " << _name << " copy-constructor called" << std::endl;
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

	std::cout << "ClapTrap class " << _name << " copy-assignment called" << std::endl;

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap class " << _name << " destructor called" << std::endl;
}


void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack (no hit points left)" << std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack (no energy points left)" << std::endl;
		return;
	}

	--_energyPoints;

	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage
				<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already down (no hit points left)" << std::endl;
		return;
	}

	_hitPoints -= static_cast<int>(amount);

	if (_hitPoints < 0)
		_hitPoints = 0;

	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair (no hit points left)" << std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair (no energy points left)" << std::endl;
		return;
	}

	--_energyPoints;

	_hitPoints += static_cast<int>(amount);

	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hitpoints!"
				<< std::endl;
}