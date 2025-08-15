#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <iostream>

class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& rhs);
		~RPN();

		int		evaluate(const std::string& expression);

	private:
		void	_executeOperation(char op);

		std::stack<int, std::list<int> > _stack;
};

#endif