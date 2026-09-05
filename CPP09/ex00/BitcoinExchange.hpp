#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, float> dataBase;

	bool isValidDate(const std::string& date) const;
	bool parseValue(const std::string& str, float& value) const;
	std::string trim(const std::string& str) const;
	void loadDatabase(const std::string& filename);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	float getRate(const std::string& date) const;
	void processInput(const std::string& filename) const;
};

#endif