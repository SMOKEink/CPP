#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Identify.hpp"

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 6; ++i)
	{
		Base*	p = generate();

		std::cout << "--- Round " << i << " ---" << std::endl;
		std::cout << "identify(Base*): ";
		identify(p);
		std::cout << "identify(Base&): ";
		identify(*p);
		delete p;
	}

	return (0);
}
