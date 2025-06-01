#infdef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA();
		~HumanA();
	
	private:
		Weapon Weapon;
		std::string _name;
};


#endif