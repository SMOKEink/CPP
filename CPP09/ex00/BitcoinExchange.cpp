#include "BitcoinExchange.hpp"
#include <exception>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <fstream>
// #include <string>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : dataBase(other.dataBase)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		dataBase = other.dataBase;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

float BitcoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it;

	it = dataBase.lower_bound(date);

	if (it == dataBase.begin())
	{
		if (it->first == date)
			return (it->second);
		throw std::runtime_error("date is too early");
	}
	if (it == dataBase.end())
	{
		--it;
		return (it->second);
	}
	if (it->first != date)
		--it;
	return (it->second);
}
//------------------------------------------------------------------------------------

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");
	std::string line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		float rate;

		std::getline(ss, date, ',');
		ss >> rate;
		dataBase[date] = rate;
	}
}

std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t start = 0;
	size_t end = str.size();

	while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
		++start;
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		--end;
	return (str.substr(start, end - start));
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

bool BitcoinExchange::parseValue(const std::string& str, float& value) const
{
	std::stringstream ss(str);

	ss >> value;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

void BitcoinExchange::processInput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;

	while (std::getline(file, line))
	{
		 if (line == "date | value")
        	continue;
		std::size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, pipe));
		std::string valueStr = trim(line.substr(pipe + 1));
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		float value;
		if (!parseValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		float rate = getRate(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}
