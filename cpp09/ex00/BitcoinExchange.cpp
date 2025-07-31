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
	std::getline(dbFile, line); // Skip header

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
	std::getline(inputFile, line); // Skip header

	while (std::getline(inputFile, line))
		processLine(line);
}

void BitcoinExchange::processLine(const std::string& line)
{
	size_t separatorPos = line.find(" | ");

	if (separatorPos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string date = line.substr(0, separatorPos);
	std::string valueStr = line.substr(separatorPos + 3);
	float value;

	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl; // move error msg to helper function
		return;
	}
	if (!isValidValue(valueStr, value))
		return;

	std::map<std::string, float>::iterator it = _db.lower_bound(date);

	if (it == _db.end() || (it->first != date && it != _db.begin())) // ->first?
		--it;
	else if (it->first != date && it == _db.begin())
	{
		std::cout << "Error: no data available for or before date " << date << std::endl;
		return;
	}

	std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
} // it->second??

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) 
		return false;
	else
		return true; // error msgs should be moved here for consistency?
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
	char* end;
	value = std::strtof(valueStr.c_str(), &end); // how does the &end work? and strtof?

	if (*end != '\0' && !std::isspace(*end)) // !std::isspace(*end) ????
	{
		std::cout << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000) // subject: valid int or float must be 0 - 1000
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	else
		return true;
}