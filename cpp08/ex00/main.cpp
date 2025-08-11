#include "easyfind.hpp"

template <typename C>
void tryFind(C& container, int value)
{
	std::cout << "Searching for " << value << ": ";
	try
	{
		typename C::iterator it = easyfind(container, value);
		std::cout << "found at index " << std::distance(container.begin(), it) << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; ++i)
		v.push_back(i * 2); // even numbers

	std::cout << "Vector test:" << std::endl;

	tryFind(v, 8);
	tryFind(v, 11);

	std::cout << std::endl;

	std::list<int> l;
	
	for (int i = 0; i < 5; ++i)
		l.push_back(i); // 1 2 3 4 5

	std::cout << "List test:" << std::endl;

	tryFind(l, 3);
	tryFind(l, 42);

	return 0;
}