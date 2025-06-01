#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
// includes

class Weapon
{
	public:
		Weapon();
		~Weapon();
	
	private:
		std::string& getType() const;
		void setType(std::string);
	
		std::string _type;
};

#endif