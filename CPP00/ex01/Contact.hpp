#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:

	Contact();
	~Contact();
	
	void set_first_name(std::string firstN);
	void set_last_name(std::string lastN);
	void set_nickname(std::string nickN);
	void set_phone_nb(std::string PhoneN);
	void set_secret(std::string DarkestS);

	std::string	get_first_name() const;
	std::string	get_last_name() const;
	std::string	get_nickname() const;
	std::string	get_phone_number() const;
	std::string	get_secret() const;
};

#endif