#include "iter.hpp"

static void addTen(int &n)
{
	n += 10;
}

static void toUpper(std::string &s)
{
	for (std::size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - ('a' - 'A');
	}
}

static void printInt(int const &n)
{
	std::cout << n << " ";
}

int main()
{
	int nums[] = { 1, 2, 3, 4, 5 };
	std::string texts[] = { "lorum", "ipsum", "dolor", "sit", "amet" };
	int const const_nums[] = { 100, 200, 300, 400, 500 };

	std::cout << "Initial arrays" << std::endl;
	std::cout << "  nums:         ";
	for (std::size_t i = 0; i < 5; ++i)
		std::cout << nums[i] << ' ';
	std::cout << std::endl;

	std::cout << "  texts:        ";
	for (std::size_t i = 0; i < 5; ++i)
		std::cout << texts[i] << ' ';
	std::cout << std::endl;

	std::cout << "  const_nums:   ";
	for (std::size_t i = 0; i < 5; ++i)
		std::cout << const_nums[i] << ' ';
	std::cout << std::endl << std::endl;

	iter(nums, 5, addTen);
	iter(texts, 5, toUpper);

	std::cout << "Final arrays" << std::endl;
	std::cout << "  nums (modified):  ";
	for (std::size_t i = 0; i < 5; ++i)
		std::cout << nums[i] << ' ';
	std::cout << std::endl;

	std::cout << "  texts (modified): ";
	for (std::size_t i = 0; i < 5; ++i)
		std::cout << texts[i] << ' ';
	std::cout << std::endl;

	std::cout << "  const_nums ";
	iter(const_nums, 5, printInt);
	std::cout << std::endl;

	return 0;
}