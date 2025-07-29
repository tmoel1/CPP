#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// helper to generate random numbers for the large test
int generateRandom() {
	return std::rand();
}

int main() {
	std::srand(std::time(0)); // seed random numbers once

	// subject's main Test
	std::cout << "Subject's Test:" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest:  " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	// large Scale & Iterator Range Test
	std::cout << "Large Scale Test (10,000 numbers):" << std::endl;
	try
	{
		std::vector<int> source(10000);
		std::generate(source.begin(), source.end(), generateRandom);

		Span largeSpan(10000);
		largeSpan.addManyNumbers(source.begin(), source.end()); // test iterator range method

		std::cout << "Shortest: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest:  " << largeSpan.longestSpan() << std::endl;
	} catch (const std::exception& e)
	{
		std::cerr << "Error during large test: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// exception & Copy Tests
	std::cout << "Exception & Copy Tests:" << std::endl;
	Span s_orig(5); // give original enough capacity to be modified
	s_orig.addNumber(10);
	s_orig.addNumber(20);

	Span s_copy = s_orig; // test copy
	s_orig.addNumber(30); // modify original to prove deep copy later

	try
	{
		std::cout << "Adding to full Span: ";
		Span s(1);
		s.addNumber(1);
		s.addNumber(2); // this should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught OK - " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Span with 1 element: ";
		Span s(1);
		s.addNumber(1);
		s.shortestSpan(); // this should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught OK - " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Span with 0 elements: ";
		Span s(0);
		s.longestSpan(); // this should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught OK - " << e.what() << std::endl;
	}

	std::cout << "Original size: " << s_orig.getSize() << " | Copy size: " << s_copy.getSize() << " (Copy is independent)" << std::endl;

	return 0;
}