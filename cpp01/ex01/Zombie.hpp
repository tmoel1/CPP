#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		//Zombie(std::string name);// this can be removed right?
		Zombie();
		~Zombie();

		void announce() const; //const as this will simply print a msg - public or private??
		void setName(std::string name); // new for hoard, in zombie .cpp

	private:
		std::string _name; //better private?? 
};

Zombie* zombieHorde(int N, std::string name);

#endif