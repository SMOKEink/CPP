#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
	std::cout << "Contact Destructor is Called" << std::endl;
}

void	Contact::SetFirstName(std::string firstN) {FirstName = firstN;}
void	Contact::SetLastName(std::string lastN) {LastName = lastN;}
void	Contact::SetNickname(std::string nickN) {Nickname = nickN;}
void	Contact::SetPhoneNumber(std::string PhoneN) {PhoneNumber = PhoneN;}
void	Contact::SetSecret(std::string DarkestS) {DarkestSecret = DarkestS;}

std::string	Contact::GetFirstName() const {return FirstName;}
std::string	Contact::GetLastName() const {return LastName;}
std::string	Contact::GetNickname() const {return Nickname;}
std::string	Contact::GetPhoneNumber() const {return PhoneNumber;}
std::string	Contact::GetSecret() const {return DarkestSecret;}