#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap bob("Bob");
	ScavTrap alive("Alice");
	FragTrap finn("Finn");
	FragTrap unknown;

	finn.attack("an enemy");
	finn.takeDamage(60);
	finn.beRepaired(40);
	finn.highFivesGuys();

	// copy tests
	FragTrap copy1(finn); // copy ctor
	FragTrap copy2; //default
	copy2 = finn; // assign
	copy1.highFivesGuys();
	copy2.highFivesGuys();

	return 0;
}