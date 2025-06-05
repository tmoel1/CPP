#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();

		void announce() const;
		void setName(std::string name);

	private:
		std::string _name; 
};

Zombie* zombieHorde(int N, std::string name);

#endif