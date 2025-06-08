#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <stdint.h>

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

// number manips:

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

// ex02 additions

bool	Fixed::operator>(const Fixed& rhs)  const
{
	return _value > rhs._value;
}

bool	Fixed::operator<(const Fixed& rhs)  const
{
	return _value < rhs._value;
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return _value >= rhs._value;
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return _value <= rhs._value;
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return _value == rhs._value;
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return _value != rhs._value;
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed out;
	out._value = _value + rhs._value;
	return out;
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed out;
	out._value = _value - rhs._value;
	return out;
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed out;
	int64_t product = static_cast<int64_t>(_value) * rhs._value;
	out._value = static_cast<int>(product >> _fractionalBits);
	return out;
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed out;
	int64_t shifted = (static_cast<int64_t>(_value) << _fractionalBits);
	out._value = static_cast<int>(shifted / rhs._value);
	return out;
}

Fixed& Fixed::operator++() // pre
{
	++_value;
	return *this;
}

Fixed  Fixed::operator++(int) // post
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--() // pre
{
	--_value;
	return *this;
}

Fixed  Fixed::operator--(int) // post
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}


Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}