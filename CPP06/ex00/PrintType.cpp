#include "PrintType.hpp"
#include <iostream>
#include <cctype>
#include <climits>
#include <cmath>
#include <iomanip>

static bool charOverflow(double val)
{
	if (val < static_cast<double>(CHAR_MIN) || val > static_cast<double>(CHAR_MAX))
		return (true);
	return (false);
}

bool intOverflow(double val)
{
	if (val < static_cast<double>(INT_MIN) || val > static_cast<double>(INT_MAX))
		return (true);
	return (false);
}

void printChar(char c)
{
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void printChar(int nb)
{
	if (charOverflow(nb))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(nb);
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}
void printChar(float f)
{
	if (charOverflow(f) || std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(f);
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}
void printChar(double d)
{
	if (charOverflow(d) || std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(d);
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void printInt(char c)
{
	std::cout << "int: " << static_cast<int>(c) << std::endl;
}
void printInt(int nb)
{
	std::cout << "int: " << nb << std::endl;
}
void printInt(float f)
{
	if (intOverflow(f) || std::isnan(f) || std::isinf(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
}
void printInt(double d)
{
	if (intOverflow(d) || std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void printFloat(char c)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
}
void printFloat(int nb)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
}
void printFloat(float f)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << ((f > 0) ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}
void printFloat(double d)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(d))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << "float: " << ((d > 0) ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
}

void printDouble(char c)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}
void printDouble(int nb)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
}
void printDouble(float f)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(f))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(f))
		std::cout << "double: " << ((f > 0) ? "+inf" : "-inf") << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}
void printDouble(double d)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
		std::cout << "double: " << ((d > 0) ? "+inf" : "-inf") << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}
