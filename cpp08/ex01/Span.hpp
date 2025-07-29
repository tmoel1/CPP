#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>

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

		template <typename T>
		void			addManyNumbers(T first, T last)
		{
			unsigned int count = std::distance(first, last);

			if (_data.size() + count > _max)
				throw std::overflow_error("Exception: container full");

			_data.insert(_data.end(), first, last);
		}

	private:
		unsigned int		_max;
		std::vector<int>	_data;


};

#endif