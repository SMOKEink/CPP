#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory Address Of String str	 : " << &str << std::endl; 
	std::cout << "Memory Address Held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory Address Held by stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable  : " << str << std::endl; 
	std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;
}
