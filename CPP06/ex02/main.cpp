#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Identify.hpp"

int	main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 6; ++i)
	{
		Base* p = generate();

		std::cout << "------- " << i << " -------" << std::endl;
		std::cout << "identify Base*: ";
		identify(p);
		std::cout << "identify Base&: ";
		identify(*p);
		delete p;
	}
}
