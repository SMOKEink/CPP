#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	try
	{
		Form form("Tax Form", 50, 25);
		std::cout << form << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		Bureaucrat bob("Bob", 40);
		bob.signForm(form);
		std::cout << form << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		Form difficult("Difficult Form", 20, 10);
		Bureaucrat Med("Med", 50);

		Med.signForm(difficult);
		std::cout << difficult << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	try
	{
		Form tooHigh("Too High", 0, 50);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tooLow("Too Low", 50, 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}