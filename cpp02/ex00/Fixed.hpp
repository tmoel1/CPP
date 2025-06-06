#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int _value;
		static const int _fractionalBits = 8;
};

#endif