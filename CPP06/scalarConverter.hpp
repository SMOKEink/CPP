#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class scalarConverter
{
private:
	scalarConverter();
	scalarConverter(const scalarConverter& other);
	scalarConverter& operator=(const scalarConverter& other);
	~scalarConverter();
public:
	static void convert(const std::string& literal);
};

#endif