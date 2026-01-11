#include "Contact.hpp"

void	Contact::set_first_name(const std::string& firstN) {first_name = firstN;}
void	Contact::set_last_name(const std::string& lastN) {last_name = lastN;}
void	Contact::set_nickname(const std::string& nickN) {nickname = nickN;}
void	Contact::set_phone_nb(const std::string& PhoneN) {phone_number = PhoneN;}
void	Contact::set_secret(const std::string& DarkestS) {darkest_secret = DarkestS;}

std::string	Contact::get_fisrt_name() const {return first_name;}
std::string	Contact::get_last_name() const {return last_name;}
std::string	Contact::get_nickname() const {return nickname;}
std::string	Contact::get_phone_number() const {return phone_number;}
std::string	Contact::get_secret() const {return darkest_secret;}