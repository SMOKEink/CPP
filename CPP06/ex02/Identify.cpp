#include <cstdlib>
#include <iostream>
#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	choice = std::rand() % 3;

	if (choice == 0)
		return (new A());
	else if (choice == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

/*
** No pointer is used here: we rely solely on reference dynamic_casts.
** A failed reference dynamic_cast throws an exception, which we catch
** with a generic handler (no std::bad_cast, no <typeinfo> header needed).
*/
void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);

		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try
		{
			B&	b = dynamic_cast<B&>(p);

			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (...)
		{
			try
			{
				C&	c = dynamic_cast<C&>(p);

				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (...)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}
