#include "Span.hpp"

Span::Span() : _max(0) {}

Span::Span(unsigned int n) : _max(n) {}

Span::Span(Span const& other) : _max(other._max), _data(other._data) {}

Span& Span::operator=(Span const& rhs)
{
	if (this != &rhs)
	{
		_max = rhs._max;
		_data = rhs._data;
	}
	return *this;
}

Span::~Span() {}



int		Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw std::logic_error("Exception: not enough elements");

	std::vector<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());

	int shortest = tmp[1] - tmp[0];

	for (unsigned int i = 2; i < tmp.size(); ++i)
	{
		int diff = tmp[i] - tmp[i - 1];
		
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}

int		Span::longestSpan() const
{
	if (_data.size() < 2)
		throw std::logic_error("Exception: not enough elements");

	std::vector<int>::const_iterator min_it = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator max_it = std::max_element(_data.begin(), _data.end());

	return *max_it - *min_it;
}

unsigned int	Span::getSize() const
{
	return _data.size();
}

unsigned int	Span::getCapacity() const
{
	return _max;
}

void	Span::addNumber(int value)
{
	if (_data.size() >= _max)
		throw std::overflow_error("Exception: container full");

	_data.push_back(value);
}