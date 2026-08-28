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
	std::cout << "===== Shrubbery =====" << std::endl;

	ShrubberyCreationForm shrubbery("home");
	Bureaucrat gardener("Gardener", 137);

	gardener.signForm(shrubbery);
	gardener.executeForm(shrubbery);


	std::cout << "\n===== Robotomy =====" << std::endl;

	RobotomyRequestForm robotomy("Bender");
	Bureaucrat robotomist("Robotomist", 45);

	robotomist.signForm(robotomy);
	robotomist.executeForm(robotomy);


	std::cout << "\n===== Presidential Pardon =====" << std::endl;

	PresidentialPardonForm pardon("Arthur Dent");
	Bureaucrat president("President", 5);

	president.signForm(pardon);
	president.executeForm(pardon);


	std::cout << "\n===== Execution errors =====" << std::endl;

	ShrubberyCreationForm unsignedForm("garden");
	Bureaucrat bureaucrat("Bob", 100);

	bureaucrat.executeForm(unsignedForm);

	ShrubberyCreationForm difficultForm("garden");
	Bureaucrat weak("Weak", 150);

	weak.signForm(difficultForm);
	weak.executeForm(difficultForm);
}