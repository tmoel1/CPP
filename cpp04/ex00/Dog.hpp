#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& rhs);
		virtual ~Dog(); //virtual keyword here
	
		virtual void	makeSound() const; //virtual also
};

#endif