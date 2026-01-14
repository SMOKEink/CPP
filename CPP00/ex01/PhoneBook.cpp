#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	N_index = 0;
};

Phonebook::~Phonebook()
{
	std::cout << "PhoneBook Destructor is Called" << std::endl;
};

std::string	check_input(std::string prompt)
{
	std::string input;
	bool	not_nbr = 0;

	while (1337)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (prompt == "Enter Phone Number: ")
			for(int i = 0; input[i]; i++)
				if (input[i] > '9' || input[i] < '0')
				{
					not_nbr = 1;
					break ;
				}
		if (not_nbr)
		{
			std::cout << "--- > Warning: Phone Number Must Include Only Numbers !" << std::endl;
			not_nbr = 0;
			continue ;
		}
		if (!input.empty())
			return (input);
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
	std::cout << "Contact Added With Success" << std::endl;
	N_index++;
}

void Phonebook::controlled_print(std::string field)
{
	if (field.length() > 10)
		field = field.substr(0, 9) + '.';
	std::cout << std::setw(10) << std::right << field;
}

void Phonebook::search()
{
	std::cout << ".............................................\n";
	std::cout << "|" << "  Index   "
			  << "|" << "First Name"
			  << "|" << " LastName "
			  << "|" << " NickName "
			  << "|\n";
	std::cout << "............................................." << std::endl;
	for (int i = 0; i < 8; i++)
	{	
		std::cout << "|"  << "    " << i << "     " << "|";
			controlled_print(Contacts[i].get_first_name());
		std::cout << "|";
			controlled_print(Contacts[i].get_last_name());
		std::cout << "|";
			controlled_print(Contacts[i].get_nickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "............................................." << std::endl;
	
	std::cout << "Enter An Index To See Details Of Contact: ";
	std::string input;
	std::getline(std::cin, input);
	if (input < "0" || input > "7" || input.length() != 1)
	{
		std::cout << "---> Error: Invalid Index !" << std::endl;
		return ;
	}
	int index = std::atoi(input.c_str());
	if (Contacts[index].get_first_name().empty())
	{
		std::cout << "--> No Contact Was Found For Index " << index << " !" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------\n"
			  << "First Name: " << Contacts[index].get_first_name() << '\n'
			  << "Last Name: " << Contacts[index].get_last_name() << '\n'
			  << "Nick_Name: " << Contacts[index].get_nickname() << '\n'
			  << "Phone Number: " << Contacts[index].get_phone_number() << '\n'
			  << "Darkest Secret: " << Contacts[index].get_secret() << '\n'
			  << "---------------------------------------------" << std::endl;
}
