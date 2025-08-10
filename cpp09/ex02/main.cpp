#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Not enough arguments." << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmergeme;
		pmergeme.runSortComparison(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}