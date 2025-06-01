#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	public:
		HumanB(const std::string& name); // const and ref necessary?
		~HumanB();

		void	setWeapon(Weapon& weapon);
		void	attack() const;
	private:
		std::string _name;
		Weapon* _weapon;
};

#endif