#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie(std::string name);// should this func be explicit??
		~Zombie();

		void announce() const; //const as this will simply print a msg - public or private??
		// should newzombie and randum chump be prototyped here??
		// or maybe it should be outside of the class? this needs looking into

	private:
		std::string _name; //better private?? 
};

Zombie *newZombie(std::string); // these 2 are declared here but should they be in the .hpp? as static??
void randomChump(std::string);

#endif