#include "scalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 2)
		scalarConverter::convert(argv[1]);
	else
	{
		std::cout << "Error: Use: ./convert <literal>" << std::endl;
		return (1);
	}
}