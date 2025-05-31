#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
		
	return horde;
}


// subject spsecifies function, not method or membern so i guess it's outside of the class
// and also gives the prototype without a "Zombie::" scope qualifier which indicates it's outside the class - but outside of the hpp??

// can choose to name then all identically or add some sort of index??