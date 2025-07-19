#include "Base.hpp"
#include <iostream>

int main()
{
	std::srand(std::time(0));

	Base* obj = generate();

	std::cout << "identify(pointer):   ";
	identify(obj);
	std::cout << std::endl;

	std::cout << "identify(reference): ";
	identify(*obj);

	delete obj;
	return 0;
}
