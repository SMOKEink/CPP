#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Intern intern;

	std::cout << "===== Valid form =====" << std::endl;
	AForm *form = intern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << "\n===== Invalid form =====" << std::endl;
	form = intern.makeForm("coffee request", "Bender");
	delete form;
}