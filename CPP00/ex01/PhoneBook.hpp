#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

class Phonebook
{
private:
	Contact Contacts[8];
	int		N_index;
	void	ControlledPrint(std::string field);
	std::string CheckInput(std::string prompt);
public:
	Phonebook();
	~Phonebook();
	void	add();
	void	search();
};

#endif