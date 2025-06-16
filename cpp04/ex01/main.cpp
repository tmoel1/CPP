#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "=== Deep-copy check ===" << std::endl;

		Dog basicDog;
		basicDog.setIdea(0, "Chase the cat");
		std::cout << "basicDog idea[0] = " << basicDog.getIdea(0) << std::endl;

		Dog copyDog(basicDog);					// calls deep-copy ctor
		std::cout << "copyDog idea[0] = " << copyDog.getIdea(0) << std::endl;

		Dog assignedDog; // cannot declare animal as getIdea isn't virtual
		assignedDog = basicDog;
		std::cout << "assignedDog idea[0] = " << assignedDog.getIdea(0) << std::endl;

		basicDog.setIdea(0, "Sleep on the couch");	// change *only* original
		std::cout << std::endl << "After change:" << std::endl;
		std::cout << "basicDog idea[0] = " << basicDog.getIdea(0) << std::endl;
		std::cout << "copyDog idea[0] = " << copyDog.getIdea(0) << std::endl;
		std::cout << "assignedDog idea[0] = " << assignedDog.getIdea(0) << std::endl;
	}

	{
		std::cout << "\n=== Mixed array ===" << std::endl;

		const int	N = 4;
		Animal*		zoo[N];

		for (int i = 0; i < N; ++i)
		{
			if (i < N / 2)
				zoo[i] = new Dog();
			else
				zoo[i] = new Cat();
		}

		std::cout << std::endl << "--- makeSound() loop ---" << std::endl;
		for (int i = 0; i < N; ++i)
			zoo[i]->makeSound();

		std::cout <<std::endl << "--- delete loop ---" << std::endl;
		for (int i = 0; i < N; ++i)
			delete zoo[i];			// virtual destructor → good order
	}

	return 0;
}
