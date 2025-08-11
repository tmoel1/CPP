#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>
#include <string>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(MutantStack const& other) : std::stack<T>(other) {}
		MutantStack&	operator=(MutantStack const& rhs)
		{
			std::stack<T>::operator=(rhs);
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T>::container_type		base_container;

		typedef typename base_container::iterator			iterator;
		typedef typename base_container::const_iterator		const_iterator;

		iterator	begin()
		{
			return this->c.begin();
		}
		iterator	end()
		{
			return this->c.end();
		}
		const_iterator	begin() const
		{
			return this->c.begin();
		}
		const_iterator	end() const
		{
			return this->c.end();
		}
};

#endif