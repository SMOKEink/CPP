#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory Address Of String string	: " << &string << std::endl; 
	std::cout << "Memory Address Held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory Address Held by stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The Value of the string variable  : " << string << std::endl; 
	std::cout << "The Value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "The Value pointed to by stringREF : " << stringREF << std::endl;
}
