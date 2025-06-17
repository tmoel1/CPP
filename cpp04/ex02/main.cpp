#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Concrete animals still work ===" << std::endl;
	const Animal* ad = new Dog();
	const Animal* ac = new Cat();

	std::cout << "ad is a " << ad->getType() << std::endl;
	std::cout << "ac is a " << ac->getType() << std::endl;

	ad->makeSound();
	ac->makeSound();

	delete ad;
	delete ac;

	// uncomment the next two lines and compile to see the error
/*
	Animal test;
	test.makeSound();
*/
	
	return 0;
}
