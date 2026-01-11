#include "PhoneBook.hpp"

int main()
{
	Phonebook	phonebook;
	std::string command;

	while (1337)
	{
		std::cout << "Please Enter A Command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (command.empty())
		{
			std::cout << "---> Warning: Empty Command, Try Again !!\n";
			continue ;
		}
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
		{
			std::cout << "Exited Successfully" << std::endl;
			break ;
		}
		else
			std::cout << "---> Warning: Invalid Command, Try Again !!" << std::endl;
	}
	return (0);
}