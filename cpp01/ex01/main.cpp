#include "Zombie.hpp"
#include <iostream>

int main()
{
	int N = 3;
	Zombie* horde = zombieHorde(N, "Horde Zombie");
	if (!horde)
		return 1;

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;
	return 0;
}