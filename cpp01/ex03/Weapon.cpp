#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon() {}

const std::string&	Weapon::getType() const  // i wonder if it's not safer to return a pure copy here? even though theoretically it's const so it can't be diddled with
{
	return _type;
}

void				Weapon::setType(const std::string& type)
{
	_type = type;
}