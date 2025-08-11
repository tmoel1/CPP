#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Span
{
	public:
		Span();
		explicit Span(unsigned int n);
		Span(Span const& other);
		Span& operator=(Span const& rhs);
		~Span();

		int				shortestSpan() const;
		int				longestSpan() const;
		unsigned int	getSize() const;
		unsigned int 	getCapacity() const;
		void			addNumber(int value);
		void			addManyNumbers(std::vector<int>::const_iterator first,
										std::vector<int>::const_iterator last);

	private:
		unsigned int		_max;
		std::vector<int>	_data;


};

#endif