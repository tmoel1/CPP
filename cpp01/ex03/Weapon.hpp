#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
// includes

class Weapon
{
	public:
		Weapon(const std::string& type); //a reference to avoid passing by value and const to promise not to modify it
		~Weapon();
		// do these two below need to be public?
		const std::string&	getType() const;
		void 				setType(const std::string& type); //does type need to be const and ref??
	
	private:
		std::string _type;
};

#endif