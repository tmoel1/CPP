#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &rhs)
		_value = rhs._value;
	
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(static_cast<int>(roundf(f * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

// Number manips:

int		Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

float	Fixed::toFloat() const
{
	return _value / static_cast<float>(1 << _fractionalBits);
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return _value;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	_value = raw;
}

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs)
{
	o << rhs.toFloat();
	return o;
}