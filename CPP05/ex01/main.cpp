#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	try
	{
		Form Med_Form("Med_Form", 50, 25);
		std::cout << Med_Form << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		Bureaucrat Brcrat_1("Brcrat_1", 40);
		Brcrat_1.signForm(Med_Form);
		std::cout << Med_Form << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;

		Form High_Form("High_Form", 20, 10);
		Bureaucrat Brcrat_2("Brcrat_2", 50);
		Brcrat_2.signForm(High_Form);
		std::cout << High_Form << std::endl;
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