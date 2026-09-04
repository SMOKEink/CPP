#include "BitcoinExchange.hpp"
#include <exception>
#include <stdexcept>

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

    it = dataBase.lower_bound(date);

    if (it == dataBase.begin())
    {
        if (it->first == date)
            return it->second;

        throw std::runtime_error("date is too early");
    }

    if (it == dataBase.end())
    {
        --it;
        return it->second;
    }

    if (it->first != date)
        --it;

    return it->second;
}