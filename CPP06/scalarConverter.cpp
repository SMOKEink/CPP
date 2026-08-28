#include "scalarConverter.hpp"
#include <iostream>
// #include <cstdlib>
#include <climits>
#include <limits>
#include <cmath>
// #include <cctype>


enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

static Type extractType(const std::string&str)
{
	if (str.empty())
		return (INVALID);
	if ((str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		|| (str.size() == 3 && str[0] == '\'' && str[2] == '\''))
		return (CHAR);
	if (str == "nan" || str == "+inf" || str == "-inf")
		return (DOUBLE);
	else if (str == "nanf" || str == "+inff" || str == "-inff")
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
	else
	{
		if (hasDot)
			return (DOUBLE);
		return (INT);
	}
}

static bool intOverFlow(double d)
{
	if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d))
		return (true);
	return (false);
}
static bool charOverFlow(double d)
{
	if (d < CHAR_MIN || d > CHAR_MAX || std::isnan(d) || std::isinf(d))
		return (true);
	return (false);
}

static void printChar(double d)
{
	if (charOverFlow(d))
		std::cout << "char: Impossible" << std::endl;
	else
	{
		char c = static_cast<char>(d);
		if (!std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
}
static void printInt(double d)
{
	if (intOverFlow(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}
static void printFloat(double d)
{
	
}
static void printDouble(double d)
{

}

void scalarConverter::convert(const std::string& str)
{
	Type type= extractType(str);
	double value = 0.0;

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
		printChar(static_cast<double>(c));
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		printFloat(static_cast<double>(c));
		printDouble(static_cast<double>(c));
	}
	else if (type == INT)
	{
		int nb = atoi(str.c_str());
		printChar(static_cast<double>(nb));
		std::cout << "int: " << nb << std::endl;
		printFloat(static_cast<double>(nb));
		printDouble(static_cast<double>(nb));
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
		printChar(static_cast<double>(f));
		printInt(static_cast<double>(f));
		std::cout << "float: " << f << "f" << std::endl;
		printDouble(static_cast<double>(f));

	}
	else if (type == DOUBLE)
	{
		double d;
		if (str == "nan")
			d = std::numeric_limits<float>::quiet_NaN();
		else if (str == "+inf")
			d = std::numeric_limits<float>::infinity();
		else if (str == "-inf")
			d = -std::numeric_limits<float>::infinity();
		else
			d = static_cast<float>(std::atof(str.c_str()));
		printChar(d);
		printInt(d);
		printFloat(d);
		std::cout << "double: " << d << std::endl;
	}

}