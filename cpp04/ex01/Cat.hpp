#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat();
	
		virtual void	makeSound() const;

		void			setIdea(int idx, const std::string& idea);
		std::string		getIdea(int idx) const; //why are we redeclaring these in Cat/cat?
	
	private:
		Brain*	brain;
};

#endif