#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

// SUPPRIME EXCESS .csv FILES BEFORE PUSHING!!!!!!!

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
		void	_processLine(const std::string& line);
		bool	_isValidDate(const std::string& date);
		bool	_isValidValue(const std::string& valueStr, float& value);
		void	_trimString(std::string& s);

		std::map<std::string, float> _db;
};

#endif