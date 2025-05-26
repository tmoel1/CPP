// for tests

#include "Zombie.hpp"

// how comprehensive do the test here need to be in fact?
// also need to look into method call through a pointer...

Zombie *newZombie(std::string); // these 2 are declared here but should they be in the .hpp? as static??
void randomChump(std::string);

int main()
{
	Zombie *heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("StackZombie"); // so the announce happens in the function called ,as it exists only in that instance and not here, correct??
	return 0;
}