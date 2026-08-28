#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
private:
	AForm* createShrubberyCreation(const std::string& target) const;
	AForm* createRobotomyRequest(const std::string& target) const;
	AForm* createPresidentialPardon(const std::string& target) const;
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	AForm* makeForm(const std::string& name, const std::string& target) const;
};

#endif