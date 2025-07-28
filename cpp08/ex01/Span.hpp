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
		unsigned int	size() const;
		unsigned int 	capacity() const;
		
		void			addNumber(int value);
/*
		template <typename T> // T is an iterator
		void			addNumber(T first, T last)
		{
			if (static_cast<unsigned int>(_data.size()) + std::distance(first, last) > _max)
				throw std::overflow_error("Exception: container full");

			_data.insert(_data.end(), first, last);
		}
*/
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