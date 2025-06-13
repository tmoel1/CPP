#include "ClapTrap.hpp"

int main()
{
	ClapTrap alice("Alice");
	ClapTrap bob("Bob");

	alice.attack("Bob");
	bob.takeDamage(4);
	bob.beRepaired(2);

	// energy point test
	for (int i = 0; i < 12; ++i)
		alice.attack("an enemy");

	// copy tests
	ClapTrap cop1(bob); // copy ctor
	ClapTrap copy2; // default
	copy2 = alice; // assign
	copy2.beRepaired(1);

	return 0;
}
