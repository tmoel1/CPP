#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <string>
#include <iostream>

template <typename T>
class Array
{
	public:

		Array() : _data(NULL), _size(0) {}

		explicit Array(unsigned int n) : _data(NULL), _size(n)
		{
			if (n)
				_data = new T[n]();
		}

		Array(Array const& other) : _data(NULL), _size(0)
		{
			*this = other;
		}

		~Array()
		{
			delete [] _data;
		}

		Array& operator=(Array const& rhs)
		{
			if (this != &rhs)
			{
				delete [] _data;
				_size = rhs._size;
				if (_size)
					_data = new T[_size];
				else
					_data = NULL;
				for (unsigned int i = 0; i < _size; ++i)
					_data[i] = rhs._data[i];
			}
			return *this;
		}

		T& operator[](unsigned int index)
		{
			if (index>= _size)
				throw std::out_of_range("Array: index out of range");
			return _data[index];
		}

		T const& operator[](unsigned int index) const
		{
			if (index>= _size)
				throw std::out_of_range("Array: index out of range");
			return _data[index];
		}

		unsigned int size() const
		{
			return _size;
		}

	private:

		T*				_data;
		unsigned int	_size;
};



#endif