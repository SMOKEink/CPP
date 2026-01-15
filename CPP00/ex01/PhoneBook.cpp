#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	N_index = 0;
};

Phonebook::~Phonebook()
{
	std::cout << "PhoneBook Destructor is Called" << std::endl;
};

std::string	Phonebook::CheckInput(std::string prompt)
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

	contact.SetFirstName(CheckInput("Enter First Name: "));
	contact.SetLastName(CheckInput("Enster Last Name: "));
	contact.SetNickname(CheckInput("Enter Nickname: "));
	contact.SetPhoneNumber(CheckInput("Enter Phone Number: "));
	contact.SetSecret(CheckInput("Enter Darkest Secret: "));

	Contacts[N_index] = contact;
	if (N_index == 7)
		N_index = -1;
	std::cout << "Contact Added With Success" << std::endl;
	N_index++;
}

void Phonebook::ControlledPrint(std::string field)
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
		std::cout << "|"  << "         " << i << "|";
			ControlledPrint(Contacts[i].GetFirstName());
		std::cout << "|";
			ControlledPrint(Contacts[i].GetLastName());
		std::cout << "|";
			ControlledPrint(Contacts[i].GetNickname());
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
	if (Contacts[index].GetFirstName().empty())
	{
		std::cout << "--> No Contact Was Found For Index " << index << " !" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------\n"
			  << "First Name: " << Contacts[index].GetFirstName() << '\n'
			  << "Last Name: " << Contacts[index].GetLastName() << '\n'
			  << "Nick_Name: " << Contacts[index].GetNickname() << '\n'
			  << "Phone Number: " << Contacts[index].GetPhoneNumber() << '\n'
			  << "Darkest Secret: " << Contacts[index].GetSecret() << '\n'
			  << "---------------------------------------------" << std::endl;
}
