#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
public:
	static void convert(const std::string& literal);
};

#endif

//	The behavior of isdigit (and the other <cctype> functions) is undefined
//	if the value of the argument is neither representable as unsigned char nor equal to EOF.