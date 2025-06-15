#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() 
{
	
	{
		std::cout << "=== Proper polymorphism ===" << std::endl;
		const Animal* aa = new Animal();
		const Animal* ad = new Dog();
		const Animal* ac = new Cat();

		std::cout << "aa is a " << aa->getType() << std::endl;
		std::cout << "ad is a " << ad->getType() << std::endl;
		std::cout << "ac is a " << ac->getType() << std::endl;

		aa->makeSound();
		ad->makeSound();
		ac->makeSound();

		delete aa;
		delete ad;
		delete ac;
	}


	{
		std::cout << "\n=== Wrong-polymorphism (on the stack) ===" << std::endl;
		WrongAnimal waa;
		WrongCat    wac;

		WrongAnimal& refwaa = wac;

		std::cout << "refwa is a " << refwaa.getType() << std::endl;

		refwaa.makeSound();
		waa.makeSound();
		wac.makeSound();
	}

	/*
	{
	// if you uncomment this you'll probably have leaks
	std::cout << "\n=== Wrong-polymorphism (on the heap) ===" << std::endl; // COMMENT OUT TO AVOID CRASHES?
	const WrongAnimal* wa = new WrongCat();

	wa->makeSound();    // OOPS: prints WrongAnimal sound!
	//delete w;   // <-- uncommenting this here can (potentially) crash execution
	}
	*/
	
	{
	// this can also result in leaks or crashes
	std::cout << std::endl;
	std::cout << "=== Wrong-polymorphism (on the heap) ===" << std::endl;
	const WrongAnimal* waa = new WrongAnimal();
	const WrongAnimal* wac = new WrongCat();

	std::cout << "waa is a " << waa->getType() << std::endl;
	std::cout << "wac is a " << wac->getType() << std::endl;

	waa->makeSound();
	wac->makeSound();

	delete waa;
	delete wac;
	}
	
	return 0;
}
