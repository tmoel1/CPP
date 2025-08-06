#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
	}
	return *this;
}



// -Jacobsthal Sequence Generation
// This helper function creates the special insertion order for the algorithm.
std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n)
{
	std::vector<size_t> jacob;
	if (n == 0)
		return jacob;

	std::vector<size_t> j_nums;
	j_nums.push_back(0);
	j_nums.push_back(1);
	while (j_nums.back() < n)
		j_nums.push_back(j_nums.back() + 2 * j_nums[j_nums.size() - 2]);

	size_t last_jacob = 1;
	for (size_t i = 2; i < j_nums.size(); ++i)
	{
		size_t current_jacob = j_nums[i];
		for (size_t j = current_jacob; j > last_jacob; --j)
		{
			if (j <= n)
				jacob.push_back(j);
		}
		last_jacob = current_jacob;
	}
	return jacob;
}

// -Main Public Method
void PmergeMe::sortAndMeasure(int argc, char **argv)
{
	_parseInput(argc, argv);

	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	// --- Vector Sorting and Timing ---
	clock_t start_vec = clock();
	_fordJohnsonSortVector(_vec); // Call main algorithm function directly
	clock_t end_vec = clock();
	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;

	// --- Deque Sorting and Timing ---
	clock_t start_deq = clock();
	_fordJohnsonSortDeque(_deq); // Call main algorithm function directly
	clock_t end_deq = clock();
	double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
			<< " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			<< " elements with std::deque  : " << time_deq << " us" << std::endl;
}

// -Helper Methods
void PmergeMe::_parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		char* end;
		long val = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || val <= 0)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
}

// -Vector Implementation

// Recursive helper: Sorts pairs using a standard merge sort.
void PmergeMe::_mergeSortPairsVector(std::vector< std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return;

	std::vector< std::pair<int, int> > left, right;
	size_t middle = pairs.size() / 2;
	for (size_t i = 0; i < middle; ++i)
		left.push_back(pairs[i]);
	for (size_t i = middle; i < pairs.size(); ++i)
		right.push_back(pairs[i]);

	_mergeSortPairsVector(left);
	_mergeSortPairsVector(right);

	pairs.clear();
	size_t l = 0, r = 0;
	while (l < left.size() && r < right.size())
	{
		if (left[l].first < right[r].first)
			pairs.push_back(left[l++]);
		else
			pairs.push_back(right[r++]);
	}
	while (l < left.size())
		pairs.push_back(left[l++]);
	while (r < right.size())
		pairs.push_back(right[r++]);
}

// Main algorithm: Implements the Ford-Johnson sort for a vector.
void PmergeMe::_fordJohnsonSortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;

	int straggler = -1;

	if (arr.size() % 2 != 0)
	{
		straggler = arr.back();
		arr.pop_back();
	}

	std::vector< std::pair<int, int> > pairs;

	for (size_t i = 0; i < arr.size() / 2; ++i)
	{
		int a = arr[i * 2];
		int b = arr[i * 2 + 1];
		if (a < b) std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	// The recursive part of the algorithm is handled by this helper
	_mergeSortPairsVector(pairs);

	std::vector<int> mainChain;
	std::vector<int> pendChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	if (!pendChain.empty())
		mainChain.insert(mainChain.begin(), pendChain[0]);

	std::vector<size_t> jacob_indices = generateJacobsthalIndices(pendChain.size());
	for (size_t i = 0; i < jacob_indices.size(); ++i)
	{
		size_t k = jacob_indices[i];
		if (k > pendChain.size()) k = pendChain.size();
		if (k <= 1) continue;

		int val = pendChain[k - 1];
		std::vector<int>::iterator insertion_point = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(insertion_point, val);
	}

	if (straggler != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}
	arr = mainChain;
}

// -Deque Implementation

// Recursive helper: Sorts pairs using a standard merge sort.
void PmergeMe::_mergeSortPairsDeque(std::deque< std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return;

	std::deque< std::pair<int, int> > left, right;
	size_t middle = pairs.size() / 2;
	for (size_t i = 0; i < middle; ++i)
		left.push_back(pairs[i]);
	for (size_t i = middle; i < pairs.size(); ++i)
		right.push_back(pairs[i]);

	_mergeSortPairsDeque(left);
	_mergeSortPairsDeque(right);

	pairs.clear();
	size_t l = 0, r = 0;
	while (l < left.size() && r < right.size())
	{
		if (left[l].first < right[r].first)
			pairs.push_back(left[l++]);
		else
			pairs.push_back(right[r++]);
	}
	while (l < left.size())
		pairs.push_back(left[l++]);
	while (r < right.size())
		pairs.push_back(right[r++]);
}

// Main algorithm: Implements the Ford-Johnson sort for a deque.
void PmergeMe::_fordJohnsonSortDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return;

	int straggler = -1;
	if (arr.size() % 2 != 0)
	{
		straggler = arr.back();
		arr.pop_back();
	}

	std::deque< std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size() / 2; ++i)
	{
		int a = arr[i * 2];
		int b = arr[i * 2 + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	// The recursive part of the algorithm is handled by this helper
	_mergeSortPairsDeque(pairs);

	std::deque<int> mainChain;
	std::deque<int> pendChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	if (!pendChain.empty())
		mainChain.insert(mainChain.begin(), pendChain[0]);

	std::vector<size_t> jacob_indices = generateJacobsthalIndices(pendChain.size());
	for (size_t i = 0; i < jacob_indices.size(); ++i)
	{
		size_t k = jacob_indices[i];
		if (k > pendChain.size())
			k = pendChain.size();
		if (k <= 1)
			continue;

		int val = pendChain[k - 1];
		std::deque<int>::iterator insertion_point = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(insertion_point, val);
	}

	if (straggler != -1)
	{
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}
	arr = mainChain;
}







/*
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
	}
	return *this;
}

void PmergeMe::sortAndMeasure(int argc, char **argv)
{
	_parseInput(argc, argv);

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	_sortVector();
	_sortDeque();

	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	_printResults("std::vector", 0.0); // Placeholder times, will be filled by actual timing
	_printResults("std::deque", 0.0);
}

void PmergeMe::_parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		char* end;
		long val = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || val <= 0)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
}

void PmergeMe::_printResults(const std::string& containerName, double time)
{
	// In a real implementation, 'time' would be calculated using clock() or similar
	// For this example, we'll just show the format
	static double vecTime = (double)clock();
	static double deqTime;

	if (containerName == "std::vector")
	{
		vecTime = ((double)clock() - vecTime) / CLOCKS_PER_SEC * 1000000.0;
		std::cout << "Time to process a range of " << _vec.size()
				<< " elements with " << containerName << " : " << vecTime << " us" << std::endl;
		deqTime = (double)clock();
	}
	else
	{
		deqTime = ((double)clock() - deqTime) / CLOCKS_PER_SEC * 1000000.0;
		std::cout << "Time to process a range of " << _deq.size()
				<< " elements with " << containerName << " : " << deqTime << " us" << std::endl;
	}
}

void PmergeMe::_sortVector()
{
	_mergeInsertVector(_vec);
}

void PmergeMe::_mergeInsertVector(std::vector<int>& arr)
{
	if (arr.size() <= 1) return;

	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;

	for (size_t i = 0; i < arr.size() / 2; ++i)
	{
		int a = arr[i * 2];
		int b = arr[i * 2 + 1];
		if (a < b) std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	if (arr.size() % 2 != 0) straggler = arr.back();

	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].first);
	
	_mergeInsertVector(mainChain);

	std::vector<int> result = mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		int val = pairs[i].second;
		std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), val);
		result.insert(it, val);
	}

	if (straggler != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), straggler);
		result.insert(it, straggler);
	}
	arr = result;
}

void PmergeMe::_sortDeque()
{
	_mergeInsertDeque(_deq);
}

void PmergeMe::_mergeInsertDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1) return;

	std::deque<std::pair<int, int> > pairs;
	int straggler = -1;

	for (size_t i = 0; i < arr.size() / 2; ++i)
	{
		int a = arr[i * 2];
		int b = arr[i * 2 + 1];
		if (a < b) std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	if (arr.size() % 2 != 0) straggler = arr.back();

	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].first);

	_mergeInsertDeque(mainChain);

	std::deque<int> result = mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		int val = pairs[i].second;
		std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), val);
		result.insert(it, val);
	}

	if (straggler != -1)
	{
		std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), straggler);
		result.insert(it, straggler);
	}
	arr = result;
}
	*/