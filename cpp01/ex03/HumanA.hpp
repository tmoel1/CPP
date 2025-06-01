#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	public:
		HumanA(const std::string& name, Weapon& weapon); //again, const and ref necessary??
		~HumanA();

		void	attack() const; //const as it modifies nothing, only prints
	
	private:
		std::string _name;
		Weapon& _weapon; //possible due to construction assignment right? can't be another instance otherwise we can't modify it elsewhere
};

#endif