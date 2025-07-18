#ifndef SCLARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string> 
#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdlib> 
#include <cerrno>
#include <cctype>
#include <limits>
#include <cmath>


class ScalarConverter
{
	public:
		static void convert(std::string const& literal);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const&);
		ScalarConverter& operator=(ScalarConverter const&);
		~ScalarConverter();

		enum eType 
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			FLOAT_PSEUDO,
			DOUBLE_PSEUDO,
			UNKNOWN
		};

		static eType	_findType(std::string const& s);

		static bool		_isChar(std::string const& s);
		static bool		_isInt(std::string const& s);
		static bool		_isFloat(std::string const& s);
		static bool		_isDouble(std::string const& s);

		static void		_printChar(long double n, bool impossible);
		static void		_printInt(long double n, bool impossible);
		static void		_printFloat(long double n, bool isPseudo, bool impossible);
		static void		_printDouble(long double n, bool isPseudo, bool impossible);
};

#endif