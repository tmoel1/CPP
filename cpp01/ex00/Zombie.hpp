#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie(); //need to add a string as param?? does it need to be explicit??
		~Zombie();

		void	announce() const; //const as this will simply print a msg - public or private??

	private:
		std::string _name; //better private?? 
};






#endif