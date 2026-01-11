#include "PhoneBook.hpp"


Phonebook::Phonebook():N_index(0)
{
	// std::cout << "PhoneBook Constructor called" << std::endl;
};

std::string	check_input(std::string prompt)
{
	std::string tmp;

	while (1)
	{
		std::cout << prompt;
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			exit(1);
		if (!tmp.empty())
			return (tmp);
		else
		std::cout << "---> Warning: Empty Field, Try Again !!\n";
	}
}

void Phonebook::add()
{
	Contact contact;

	contact.set_first_name(check_input("Enter First Name: "));
	contact.set_last_name(check_input("Enster Last Name: "));
	contact.set_nickname(check_input("Enter Nickname: "));
	contact.set_phone_nb(check_input("Enter Phone Number: "));
	contact.set_secret(check_input("Enter Darkest Secret: "));

	Contacts[N_index] = contact;
	if (N_index == 7)
		N_index = -1;
	std::cout << "Contact Added To The Agenda With Succes" << std::endl;
	N_index++;
}

void Phonebook::controlled_print(std::string field)
{
	if (field.length() > 15)
		field = field.substr(0, 12) + "...";
	std::cout << std::setw(15) << std::left << field;
}

void Phonebook::search()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "█" << "     Index     "
			  << "█" << "  First Name   "
			  << "█" << "   Last Name   "
			  << "█" << "   NickName    "
			  << "█\n";
	std::cout << "█████████████████████████████████████████████████████████████████" << std::endl;
	for (int i = 0; i < 8; i++)
	{	
		std::cout << "█"  << "       " << i << "       " << "█";
			controlled_print(Contacts[i].get_fisrt_name());
		std::cout << "█";
			controlled_print(Contacts[i].get_last_name());
		std::cout << "█";
			controlled_print(Contacts[i].get_nickname());
		std::cout << "█" << std::endl;
	}
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << std::endl;
	
	std::cout << "Enter An Index To See Details Of Contact: ";
	std::string input;
	std::getline(std::cin, input);
	int index = std::stoi(input);
	if (index < 0 || index > 7)
	{
		std::cout << "---> Error: Invalid Index !" << std::endl;
		return ;
	}
	if (Contacts[index].get_fisrt_name().empty())
	{
		std::cout << "--> No Contact Was Found For Index " << index << " !" << std::endl;
		return ;
	}
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n"
			  << "First Name: " << Contacts[index].get_fisrt_name() << '\n'
			  << "Last Name: " << Contacts[index].get_last_name() << '\n'
			  << "Nick_Name: " << Contacts[index].get_nickname() << '\n'
			  << "Phone Number: " << Contacts[index].get_phone_number() << '\n'
			  << "Darkest Secret: " << Contacts[index].get_secret() << '\n'
			  << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << std::endl;
}
