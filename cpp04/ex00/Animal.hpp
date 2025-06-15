#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal(); //virtual keyword here
	
		std::string		getType() const;
		virtual void	makeSound() const; //virtual also

	protected:
		std::string		type;
};

#endif