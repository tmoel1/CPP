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

		// comparison
		bool	operator>(Fixed const&) const;
		bool	operator<(Fixed const&) const;
		bool	operator>=(Fixed const&) const;
		bool	operator<=(Fixed const&) const;
		bool	operator==(Fixed const&) const;
		bool	operator!=(Fixed const&) const;

		// arithmetic
		Fixed	operator+(Fixed const&) const;
		Fixed	operator-(Fixed const&) const;
		Fixed	operator*(Fixed const&) const;
		Fixed	operator/(Fixed const&) const;

		// in-de-crement
		Fixed&	operator++(); // pre-inc
		Fixed	operator++(int); // post-inc
		Fixed&	operator--();
		Fixed	operator--(int);

		// min-max
		static Fixed&		min(Fixed&, Fixed&);
		static Fixed const&	min(Fixed const&, Fixed const&);
		static Fixed&		max(Fixed&, Fixed&);
		static Fixed const&	max(Fixed const&, Fixed const&);

	private:
		int _value;
		static const int _fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs);

#endif