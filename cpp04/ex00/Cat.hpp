#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat(); //virtual keyword here
	
		virtual void	makeSound() const; //virtual also
};

#endif