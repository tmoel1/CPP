#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>



template <typename T>
void	iter(T* array, std::size_t len, void (*func)(T&))
{
	if (!array)
		return;
	for (std::size_t i = 0; i < len; ++i)
		func(array[i]);
}

template <typename T>
void	iter(T const* array, std::size_t len, void (*func)(T const&))
{
	if (!array)
		return;
	std::cout << "*using const overload* ";
	for (std::size_t i = 0; i < len; ++i)
		func(array[i]);
}

#endif