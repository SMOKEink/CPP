#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

AForm* Intern::createShrubberyCreation(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}
AForm* Intern::createRobotomyRequest(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}
AForm* Intern::createPresidentialPardon(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

typedef AForm* (Intern::*FormCreator)(const std::string&) const;

struct FormInfo
{
	const char* name;
	FormCreator creator;
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	const FormInfo forms[3] =
	{
		{"shrubbery creation", &Intern::createShrubberyCreation},
		{"robotomy request", &Intern::createRobotomyRequest},
		{"presidential pardon", &Intern::createPresidentialPardon}
	};
	for (int i = 0; i < 3; ++i)
	{
		if (formName == forms[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*forms[i].creator)(target);
		}
	}
	std::cerr << "ERROR: Unknown Form >> " << formName << std::endl;
	return (NULL);
}