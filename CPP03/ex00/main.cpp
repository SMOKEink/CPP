#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("One");
	ClapTrap b("Two");

	std::cout << "\n----------------------------------------------" << std::endl;
	a.attack("Two");
	b.takeDamage(0);
	b.beRepaired(5);

	std::cout << "\n----------------------------------------------" << std::endl;
	for (int i = 0; i < 11; i++)
		a.attack("Enemy");

	std::cout << "\n----------------------------------------------" << std::endl;
	b.takeDamage(5);
	b.takeDamage(5);
	b.takeDamage(5);

	std::cout << "\n----------------------------------------------" << std::endl;
	b.attack("Ghost");
	b.beRepaired(10);

	std::cout << "\n----------------------------------------------" << std::endl;
	ClapTrap c(a);
	ClapTrap d;
	d = a;
	std::cout << "\n----------------------------------------------" << std::endl;
	return (0);
}
