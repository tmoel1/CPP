#include "Zombie.hpp"

Zombie* newZombie(std::string name) // not const or passed by reference, as subject specifies
{
	return new Zombie(name); // make sure there the corresponding delete in main!!
}