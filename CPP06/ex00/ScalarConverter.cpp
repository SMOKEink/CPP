#include "ScalarConverter.hpp"
#include "PrintType.hpp"
#include <cstdlib>
#include <limits>
#include <iostream>
#include <cctype>
#include <climits>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}
ScalarConverter::~ScalarConverter()
{}

enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

static Type extractType(const std::string& str)
{
	if (str.empty())
		return (INVALID);
	if ((str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		|| (str.size() == 3 && str[0] == '\'' && str[2] == '\''))
		return (CHAR);
	if (str == "nan" || str == "+inf" || str == "-inf")
		return (DOUBLE);
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (FLOAT);

	bool isFloat = false;
	std::string s = str;
	size_t strSize = s.size();
	if (s[strSize - 1] == 'f')
	{
		isFloat = true;
		s = s.substr(0, strSize - 1);
		strSize = s.size();
	}
	if (strSize == 0)
		return (INVALID);
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	bool hasDigit = false;
	bool hasDot = false;
	while (i < strSize)
	{
		if (std::isdigit(static_cast<unsigned char>(s[i])))
			hasDigit = true;
		else if (s[i] == '.' && !hasDot)
			hasDot = true;
		else
			return (INVALID);
		i++;
	}
	if (!hasDigit)
		return (INVALID);
	if (isFloat)
	{
		if (hasDot)
			return (FLOAT);
		return (INVALID);
	}
	return (hasDot ? DOUBLE : INT);
}
#include <cstdio>
void ScalarConverter::convert(const std::string& str)
{
	Type type = extractType(str);

	if (type == INVALID)
	{
		std::cout << "Invalid Literal" << std::endl;
		return;
	}
	else if (type == CHAR)
	{
		char c;
		if (str.size() == 3)
			c = str[1];
		else
			c = str[0];
		printChar(c);
		printInt(c);
		printFloat(c);
		printDouble(c);
	}
	else if (type == INT)
	{
		double d = std::atof(str.c_str());
		if (intOverflow(d))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		}
		else
		{
			int nb = std::atoi(str.c_str());
			printChar(nb);
			printInt(nb);
			printFloat(nb);
			printDouble(nb);
		}
	}
	else if (type == FLOAT)
	{
		float f;
		if (str == "nanf")
			f = std::numeric_limits<float>::quiet_NaN();
		else if (str == "+inff")
			f = std::numeric_limits<float>::infinity();
		else if (str == "-inff")
			f = -std::numeric_limits<float>::infinity();
		else
			f = static_cast<float>(std::atof(str.c_str()));
		printChar(f);
		printInt(f);
		printFloat(f);
		printDouble(f);
	}
	else if (type == DOUBLE)
	{
		double d;
		if (str == "nan")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (str == "+inf")
			d = std::numeric_limits<double>::infinity();
		else if (str == "-inf")
			d = -std::numeric_limits<double>::infinity();
		else
			d = std::atof(str.c_str());
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
	}
}
