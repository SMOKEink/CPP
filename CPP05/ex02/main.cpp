#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(std::time(NULL));
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	Bureaucrat Garden("Garden", 137);
	ShrubberyCreationForm shrubbery("MoSsA");
	Garden.signForm(shrubbery);
	Garden.executeForm(shrubbery);

	std::cout << "------------------------------------------------------------------------------" << std::endl;
	Bureaucrat robotomist("Robotomist", 45);
	RobotomyRequestForm robotomy("MoSsA");
	robotomist.signForm(robotomy);
	robotomist.executeForm(robotomy);

	std::cout << "------------------------------------------------------------------------------" << std::endl;
	Bureaucrat president("President", 5);
	PresidentialPardonForm pardon("MoSsA");
	president.signForm(pardon);
	president.executeForm(pardon);

	std::cout << "------------------------------------------------------------------------------" << std::endl;
	Bureaucrat bcrat("Bcrat", 100);
	ShrubberyCreationForm unsignedForm("garden");
	bcrat.executeForm(unsignedForm);
	std::cout << "----------------------------------------" << std::endl;

	Bureaucrat weakBcrat("Weak", 150);
	ShrubberyCreationForm highForm("garden");
	weakBcrat.signForm(highForm);
	weakBcrat.executeForm(highForm);
}