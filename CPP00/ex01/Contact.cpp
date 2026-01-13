#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
	std::cout << "Contact Destructor is Called" << std::endl;
}

void	Contact::set_first_name(std::string firstN) {first_name = firstN;}
void	Contact::set_last_name(std::string lastN) {last_name = lastN;}
void	Contact::set_nickname(std::string nickN) {nickname = nickN;}
void	Contact::set_phone_nb(std::string PhoneN) {phone_number = PhoneN;}
void	Contact::set_secret(std::string DarkestS) {darkest_secret = DarkestS;}

std::string	Contact::get_first_name() const {return first_name;}
std::string	Contact::get_last_name() const {return last_name;}
std::string	Contact::get_nickname() const {return nickname;}
std::string	Contact::get_phone_number() const {return phone_number;}
std::string	Contact::get_secret() const {return darkest_secret;}