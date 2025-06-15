#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() ////////////////////////////// delete comments 
{
	
	{
		std::cout << "=== Proper polymorphism ===" << std::endl;
		const Animal* aa = new Animal();
		const Animal* ad = new Dog();
		const Animal* ac = new Cat();

		std::cout << "aa is a " << aa->getType() << std::endl;
		std::cout << "ad is a " << ad->getType() << std::endl;
		std::cout << "ac is a " << ac->getType() << std::endl;

		aa->makeSound(); // Animal sound
		ad->makeSound();    // Dog sound
		ac->makeSound();    // Cat sound

		delete aa;       // virtual dtor ensures correct order
		delete ad;
		delete ac;
	}


	{
		std::cout << "\n=== Wrong-polymorphism (on the stack) ===" << std::endl;
		WrongAnimal waa;          // base object
		WrongCat    wac;           // derived object

		WrongAnimal& refwaa = wac;    // bind base-reference to derived

		std::cout << "refwa is a " << refwaa.getType() << std::endl;

		refwaa.makeSound();   // → WrongAnimal::makeSound()   (static binding)
		waa.makeSound();  // → WrongAnimal::makeSound()
		wac.makeSound();
	}

	/*
	{
	/////////// If you uncomment this you'll have leaks
	std::cout << "\n=== Wrong-polymorphism (on the heap) ===" << std::endl; // COMMENT OUT TO AVOID CRASHES?
	const WrongAnimal* wa = new WrongCat();

	wa->makeSound();    // OOPS: prints WrongAnimal sound!
	//delete w;   // <-- uncommenting can (potentially) crash execution
	}
	*/
	
	{
	std::cout << std::endl;
	std::cout << "=== Wrong-polymorphism (on the heap) ===" << std::endl;
	const WrongAnimal* waa = new WrongAnimal();
	const WrongAnimal* wac = new WrongCat();

	std::cout << "waa is a " << waa->getType() << std::endl;
	std::cout << "wac is a " << wac->getType() << std::endl;

	waa->makeSound(); // Animal sound
	wac->makeSound();    // Cat sound

	delete waa;       // virtual dtor ensures correct order
	delete wac;
	}
	
	return 0;
	// RUN IT THROUGH VALGRIND TO BE SURE!!!!!!!!!!!!!!!!!!!!!!!!!!
}
