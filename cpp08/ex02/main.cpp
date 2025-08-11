#include "MutantStack.hpp"

template <typename S>
void printStack(S& s)
{
	typename S::iterator it  = s.begin();
	typename S::iterator ite = s.end();
	while (it != ite)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "Subject's Main Test (MutantStack):" << std::endl;
	try
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << "Comparison Test (std::list):" << std::endl;
	try
	{
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << "Top: " << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << "Size: " << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Copy and Assignment Test:" << std::endl;
	try
	{
		MutantStack<int> original;
		original.push(1);
		original.push(2);
		original.push(3);

		MutantStack<int> copy(original);
		MutantStack<int> assigned;
		assigned = original;

		original.pop();
		
		std::cout << "Original: "; printStack(original);
		std::cout << "Copy:     "; printStack(copy);
		std::cout << "Assigned: "; printStack(assigned);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "String Test:" << std::endl;
	try
	{
		MutantStack<std::string> str_stack;
		str_stack.push("Hello");
		str_stack.push("World");
		str_stack.push("!");
		printStack(str_stack);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}