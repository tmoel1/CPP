#include "Base.hpp"

Base::~Base() {}



Base*	generate()
{
	switch (std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void	identify(Base* bPtr)
{
	if (dynamic_cast<A*>(bPtr))
		std::cout << "A";
	else if (dynamic_cast<B*>(bPtr))
		std::cout << "B";
	else if (dynamic_cast<C*>(bPtr))
		std::cout << "C";
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& bRef)
{
	try
	{
		(void)dynamic_cast<A&>(bRef);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<B&>(bRef);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(bRef);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}

	std::cout << "Unknown" << std::endl;
}
