#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
public:

	Contact();
	~Contact();
	
	void SetFirstName(std::string firstN);
	void SetLastName(std::string lastN);
	void SetNickname(std::string nickN);
	void SetPhoneNumber(std::string PhoneN);
	void SetSecret(std::string DarkestS);

	std::string	GetFirstName() const;
	std::string	GetLastName() const;
	std::string	GetNickname() const;
	std::string	GetPhoneNumber() const;
	std::string	GetSecret() const;
};

#endif