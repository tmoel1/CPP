#include <iostream>
#include <string>
#include "Array.hpp"

static void printNumbers(Array<int> const& a)
{
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

static void printStrings(Array<std::string> const& a)
{
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

int main()
{
	// empty array construction
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl << std::endl;

	// sized array construction
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = (i + 1) * 10;
	std::cout << "numbers = ";
	printNumbers(numbers);
	std::cout << std::endl;

	// copy-construction
	Array<int> copy(numbers);
	numbers[0] = 99;
	std::cout << "copy after numbers[0]=99 -> ";
	printNumbers(copy);
	std::cout << std::endl;

	// copy-assignment
	Array<std::string> words(3);
	words[0] = "lorum";
	words[1] = "ipsum";
	words[2] = "dolor";

	Array<std::string> other;
	other = words;
	words[1] = "CHANGED";

	std::cout << "words = ";
	printStrings(words);
	std::cout << "other = ";
	printStrings(other);
	std::cout << std::endl;

	// range-checking
	try
	{
		std::cout << "numbers[10] = ";
		std::cout << numbers[10] << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "*proving program continuation before returning 0*" << std::endl;
	return 0;
}
