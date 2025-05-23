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

	private:
		std::string _name; //better private?? 
};

#endif