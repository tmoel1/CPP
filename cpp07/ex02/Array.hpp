#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // for out of range
// not necessary -> #include <cstddef> // for size_t
#include <string>
#include <iostream>

template <typename T>
class Array
{
	public:

		Array() : _data(NULL), _size(0) {}

		explicit Array(unsigned int n) : _data(NULL), _size(n) // need to be explicit?
		{
			if (n)
				_data = new T[n]();  // can this part be in the topline instead?
		}

		Array(Array const& other) : _data(NULL), _size(0) //initialising at zero as copy assignment does the rest
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
				for (unsigned int i = 0; i < _size; ++i) //check to be sure it's correct to have the loop also for it size is 0 and therefore data is null
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
		unsigned int	_size; // better size_t?
};



#endif