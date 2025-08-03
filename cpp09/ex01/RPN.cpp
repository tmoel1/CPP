#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
	return *this;
}



int RPN::evaluate(const std::string& expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && isdigit(token[0]))
		{
			this->_stack.push(std::atoi(token.c_str()));
		}
		else if (token.length() == 1 && (token[0] == '+' || token[0] == '-'
				|| token[0] == '*' || token[0] == '/'))
		{
			_executeOperation(token[0]);
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (this->_stack.size() != 1)
		throw std::runtime_error("Error");

	return this->_stack.top();
}

void RPN::_executeOperation(char symbol)
{
	if (this->_stack.size() < 2)
		throw std::runtime_error("Error");

	int rhs = this->_stack.top();
	this->_stack.pop();
	int lhs = this->_stack.top();
	this->_stack.pop();

	if (symbol == '+')
		this->_stack.push(lhs + rhs);
	else if (symbol == '-')
		this->_stack.push(lhs - rhs);
	else if (symbol == '*')
		this->_stack.push(lhs * rhs);
	else if (symbol == '/')
	{
		if (rhs == 0)
			throw std::runtime_error("Error");
		this->_stack.push(lhs / rhs);
	}
}