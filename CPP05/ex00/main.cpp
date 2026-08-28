#include "Bureaucrat.hpp"

int main()
{
	std::cout << "---------------------------------------" << std::endl;
	Bureaucrat bob("Bob", 100);
	std::cout << bob << std::endl;

	bob.incrementGrade();
	std::cout << bob << std::endl;
	bob.decrementGrade();
	std::cout << bob << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	try
	{
		Bureaucrat tooHigh("High", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("Low", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------------------------" << std::endl;
	Bureaucrat high("High", 1);
	try
	{
		high.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat low("Low", 150);
	try
	{
		low.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------------------------" << std::endl;
	Bureaucrat original("Original", 42);
	Bureaucrat copy(original);
	std::cout << copy << std::endl;
	Bureaucrat assigned("Assigned", 100);
	assigned = original;
	std::cout << assigned << std::endl;
}