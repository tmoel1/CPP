// for tests

#include "Zombie.hpp"

// how comprehensive do the test here need to be in fact?
// also need to look into method call through a pointer...

// movbed the declarations to the .hpp

int main()
{
	Zombie *heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("StackZombie"); // so the announce happens in the function called ,as it exists only in that instance and not here, correct??
	return 0;
}