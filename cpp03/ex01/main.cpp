#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap bob("Bob");
	ScavTrap alice("Alice");

	alice.attack("an enemy");
	alice.takeDamage(40);
	alice.beRepaired(30);

	alice.guardGate();

	// copy tests
	ScavTrap copy1(alice); // copy ctor
	ScavTrap copy2; // default
	copy2 = alice; // assign
	copy1.guardGate();
	copy2.guardGate();

	return 0;
}
