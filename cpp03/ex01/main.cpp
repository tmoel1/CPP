#include "ClapTrap.hpp"

int main()
{
	ClapTrap alice("Alice");
	ClapTrap bob("Bob");

	alice.attack("Bob");
	bob.takeDamage(4);
	bob.beRepaired(2);

	// energy test
	for (int i = 0; i < 12; ++i)
		alice.attack("nothing");

	// copy
	ClapTrap copyTrap = alice;
	copyTrap.beRepaired(1);

	return 0;
}
