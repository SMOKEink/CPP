#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class Phonebook
{
private:
	Contact Contacts[8];
	int		N_index;
	void	controlled_print(std::string field);
	
public:
	Phonebook();

	void	add();
	void	search();
};

#endif