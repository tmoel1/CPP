#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& rhs);
		~WrongAnimal(); // without the virtual!!
	
		std::string		getType() const;
		void			makeSound() const; //also without!

	protected:
		std::string		type;
};

#endif