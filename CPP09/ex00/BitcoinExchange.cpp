#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

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

	it = dataBase.find(date);
	if (it != dataBase.end())
		return (it->second);
	return (0.0f);
}