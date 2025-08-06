#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
//#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>



class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void sortAndMeasure(int argc, char **argv);

	private:


		// Helper Methods
		void _parseInput(int argc, char **argv);
		std::vector<size_t> generateJacobsthalIndices(size_t n);
		// Vector Implementation
		void _fordJohnsonSortVector(std::vector<int>& arr);
		void _mergeSortPairsVector(std::vector< std::pair<int, int> >& pairs);
		// Deque Implementation
		void _fordJohnsonSortDeque(std::deque<int>& arr);
		void _mergeSortPairsDeque(std::deque< std::pair<int, int> >& pairs);

				std::vector<int> _vec;
		std::deque<int>  _deq;
};


/*
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void sortAndMeasure(int argc, char **argv);

	private:
		std::vector<int> _vec;
		std::deque<int>  _deq;

		void _parseInput(int argc, char **argv);
		void _printResults(const std::string& containerName, double time);

		void _sortVector();
		void _mergeInsertVector(std::vector<int>& arr);

		void _sortDeque();
		void _mergeInsertDeque(std::deque<int>& arr);
};
*/
#endif