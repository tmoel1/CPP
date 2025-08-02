#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void	loadDatabase(const std::string& dbPath);
		void	processInputFile(const std::string& inputPath);

	private:
		void	processLine(const std::string& line);
		bool	isValidDate(const std::string& date);
		bool	isValidValue(const std::string& valueStr, float& value);
		void	trimString(std::string& s);

		std::map<std::string, float> _db;
};

#endif