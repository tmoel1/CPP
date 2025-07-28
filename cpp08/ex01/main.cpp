#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Helper to generate random numbers for the large test
int generateRandom() {
	return std::rand();
}

int main() {
	std::srand(std::time(0)); // Seed random numbers once

	// --- Subject's Main Test ---
	std::cout << "--- Subject's Test ---" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest:  " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	// --- Large Scale & Iterator Range Test ---
	std::cout << "--- Large Scale Test (10,000 numbers) ---" << std::endl;
	try
	{
		std::vector<int> source(10000);
		std::generate(source.begin(), source.end(), generateRandom);

		Span largeSpan(10000);
		largeSpan.addManyNumbers(source.begin(), source.end()); // Test iterator range method

		std::cout << "Shortest: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest:  " << largeSpan.longestSpan() << std::endl;
	} catch (const std::exception& e)
	{
		std::cerr << "Error during large test: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Exception & Copy Tests ---
	std::cout << "--- Exception & Copy Tests ---" << std::endl;
	Span s_orig(5); // Give original enough capacity to be modified
	s_orig.addNumber(10);
	s_orig.addNumber(20);

	Span s_copy = s_orig; // Test copy
	s_orig.addNumber(30); // Modify original to prove deep copy later

	try
	{
		std::cout << "Adding to full Span:          ";
		Span s(1);
		s.addNumber(1);
		s.addNumber(2); // This should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught OK" << std::endl;
	}

	try
	{
		std::cout << "Span with 1 element:          ";
		Span s(1);
		s.addNumber(1);
		s.shortestSpan(); // This should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught OK" << std::endl;
	}

	try
	{
		std::cout << "Span with 0 elements:         ";
		Span s(0);
		s.longestSpan(); // This should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught OK" << std::endl;
	}

	std::cout << "Original size: " << s_orig.size() << " | Copy size: " << s_copy.size() << " (Copy is independent)" << std::endl;

	return 0;
}