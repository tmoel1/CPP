#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		Fixed(const int n);
		Fixed(const float f);

		int		toInt() const;
		float	toFloat() const;
		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int _value;
		static const int _fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs);

#endif