#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::out_of_range("exception caught: value not found");

	return it;
}

 // const-correct version
template <typename T>
typename T::const_iterator easyfind(T const& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::out_of_range("exception caught: value not found");

	return it;
}

#endif