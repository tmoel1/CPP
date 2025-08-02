#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		this->_db = rhs._db;
	}
	return *this;
}



void BitcoinExchange::loadDatabase(const std::string& dbPath)
{
	std::ifstream dbFile(dbPath.c_str());

	if (!dbFile.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(dbFile, line);

	while (std::getline(dbFile, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos != std::string::npos) 
		{
			std::string date = line.substr(0, commaPos);
			float rate = std::atof(line.substr(commaPos + 1).c_str());
			_db[date] = rate;
		}
	}
}

void BitcoinExchange::processInputFile(const std::string& inputPath)
{
	std::ifstream inputFile(inputPath.c_str());

	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string line;
	std::getline(inputFile, line);

	while (std::getline(inputFile, line))
		_processLine(line);
}

void BitcoinExchange::_processLine(const std::string& line)
{
	size_t separatorPos = line.find('|');

	if (separatorPos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string date = line.substr(0, separatorPos);
	std::string valueStr = line.substr(separatorPos + 1);
	
	_trimString(date);
	_trimString(valueStr);

	float value;

	if (!_isValidDate(date))
		return;

	if (!_isValidValue(valueStr, value))
		return;

	std::map<std::string, float>::iterator it = _db.lower_bound(date);

	if (it == _db.end() || (it->first != date && it != _db.begin()))
		--it;
	else if (it->first != date && it == _db.begin())
	{
		std::cout << "Error: no data available for or before date " << date << std::endl;
		return;
	}

	std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
}

bool BitcoinExchange::_isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	else
		return true;
}

bool BitcoinExchange::_isValidValue(const std::string& valueStr, float& value)
{
	if (valueStr.empty())
	{
		std::cout << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	
	char* end;
	value = std::strtof(valueStr.c_str(), &end);

	if (*end != '\0')
	{
		std::cout << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	else
		return true;
}

void	BitcoinExchange::_trimString(std::string& s)
{
	s.erase(0, s.find_first_not_of(" \t\n\r"));
	s.erase(s.find_last_not_of(" \t\n\r") + 1);
}
