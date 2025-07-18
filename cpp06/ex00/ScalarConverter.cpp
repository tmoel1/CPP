#include "ScalarConverter.hpp"

// publically accessible convert() function

void ScalarConverter::convert(std::string const& s)
{
	eType type = _findType(s);
	long double n = 0.0L;
	bool impossible = false;
	bool pseudo = (type == FLOAT_PSEUDO || type == DOUBLE_PSEUDO);

	switch (type)
	{
		case CHAR:
		{
			n = static_cast<long double>(s[0]);
			break;
		}
		case INT:
		{
			n = static_cast<long double>(std::strtod(s.c_str(), 0));
			break;
		}		
		case FLOAT:
		{
			n = static_cast<long double>(std::strtod(s.substr(0, s.size()-1).c_str(), 0));
			break;
		}
		case DOUBLE:
		{
			n = static_cast<long double>(std::strtod(s.c_str(), 0));
			break;
		}
		case FLOAT_PSEUDO:
		{
			n = static_cast<long double>(std::strtod(s.substr(0, s.size()-1).c_str(),0));
			break;
		}
		case DOUBLE_PSEUDO:
		{
			n = static_cast<long double>(std::strtod(s.c_str(), 0));
			break;
		}
		default:
			impossible = true;
	}
	
	bool charImpossible = impossible || std::isnan(n) || std::isinf(n) ||
		n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max();

	bool intImpossible = impossible || std::isnan(n) || std::isinf(n) ||
		n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max();

	_printChar(n, charImpossible);
	_printInt(n, intImpossible);
	_printFloat(n, pseudo, (type == UNKNOWN));
	_printDouble(n, pseudo, (type == UNKNOWN));
}

// convert() primary supporting function, _findType()

ScalarConverter::eType ScalarConverter::_findType(std::string const& s)
{
	static std::string const floatPseudo[3] = {"nanf", "+inff", "-inff"};
	static std::string const doublePseudo[3] = {"nan", "+inf", "-inf"};

	for (int i = 0; i < 3; ++i)
	{
		if (s == floatPseudo[i])
			return FLOAT_PSEUDO;
	}
	for (int i = 0; i < 3; ++i)
	{
		if (s == doublePseudo[i])
			return DOUBLE_PSEUDO;
	}

	if (_isChar(s))
		return CHAR;
	if (_isInt(s))
		return INT;
	if (_isFloat(s))
		return FLOAT;
	if (_isDouble(s))
		return DOUBLE;
	return UNKNOWN;
}

// probing functions helping _findType

bool ScalarConverter::_isChar(std::string const& s)
{
	if (s.length() == 1 && !std::isdigit(s[0]))
		return true;

	return false;
}

bool ScalarConverter::_isInt(std::string const& s)
{
	if (s.find('.') != std::string::npos || s.find('f') != std::string::npos)
		return false;

	char* end_ptr = NULL;
	errno = 0;

	long value = std::strtol(s.c_str(), &end_ptr, 10);
	(void)value;

	bool parsed = (*end_ptr == '\0');
	bool overflowed = (errno != ERANGE);

	return parsed && overflowed;
}

bool ScalarConverter::_isFloat(std::string const& s)
{
	if (s.find('f') != s.size() - 1)
		return false;

	if (s.find('.') == std::string::npos)
		return false;

	std::string digits = s.substr(0, s.size() - 1);
	
	return _isDouble(digits);

}

bool ScalarConverter::_isDouble(std::string const& s)
{
	char* end_ptr = NULL;
	errno = 0;

	std::strtod(s.c_str(), &end_ptr);

	bool parsed = (*end_ptr == '\0');
	bool overflowed = (errno != ERANGE);

	return parsed && overflowed;
}

// print functions

void	ScalarConverter::_printChar(long double n, bool impossible)
{
	std::cout << "char: ";

	if (impossible)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
}

void	ScalarConverter::_printInt(long double n, bool impossible)
{
	std::cout << "int: ";

	if (impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
}

void	ScalarConverter::_printFloat(long double n, bool isPseudo, bool impossible)
{
	std::cout << "float: ";

	if (impossible && !isPseudo)
		std::cout << "impossible" << std::endl;
	else if (isPseudo)
	{
		if (std::isnan(n))
			std::cout << "nanf" << std::endl;
		else if (std::signbit(n))
			std::cout << "-inff" << std::endl;
		else
			std::cout << "+inff" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(n) << 'f' << std::endl;
}

void	ScalarConverter::_printDouble(long double n, bool isPseudo, bool impossible)
{
	std::cout << "double: ";
	
	if (impossible && !isPseudo)
		std::cout << "impossible" << std::endl;
	else if (isPseudo)
	{
		if (std::isnan(n))
			std::cout << "nan" << std::endl;
		else if (std::signbit(n))
			std::cout << "-inf" << std::endl;
		else
			std::cout << "+inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}
